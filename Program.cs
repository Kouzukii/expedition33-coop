using System.Diagnostics;
using System.Reflection;
using UAssetAPI;
using UAssetAPI.ExportTypes;
using UAssetAPI.FieldTypes;
using UAssetAPI.Kismet.Bytecode;
using UAssetAPI.Kismet.Bytecode.Expressions;
using UAssetAPI.UnrealTypes;
using UAssetAPI.Unversioned;

var usmap = new Usmap("Mappings.usmap");
// patch broken struct reference in PlayerIndicator & ModLibrary
{
    var playerIndicator = new UAsset(@".\Sandfall\Windows\Sandfall\Content\Coop\PlayerIndicator.uasset", EngineVersion.VER_UE5_4, usmap);
    var originalStruct = new UAsset(@".\Export\Sandfall/Content/jRPGTemplate/Structures/S_jRPG_PartySlot.uasset", EngineVersion.VER_UE5_4, usmap);
    var accessedStructProp = playerIndicator.GetNameMapIndexList().First(i => i.Value.StartsWith("CharacterHardcodedName"));
    accessedStructProp.Value = originalStruct.GetNameMapIndexList().First(i => i.Value.StartsWith("CharacterHardcodedName")).Value;
    playerIndicator.Write(@".\Sandfall\Windows\Sandfall\Content\Coop\PlayerIndicator.uasset");
    Console.WriteLine("Patched PlayerIndicator");
    var modLibrary = new UAsset(@".\Sandfall\Windows\Sandfall\Content\Coop\ModLibrary.uasset", EngineVersion.VER_UE5_4, usmap);
    accessedStructProp = modLibrary.GetNameMapIndexList().First(i => i.Value.StartsWith("CharacterHardcodedName"));
    accessedStructProp.Value = originalStruct.GetNameMapIndexList().First(i => i.Value.StartsWith("CharacterHardcodedName")).Value;
    modLibrary.Write(@".\Sandfall\Windows\Sandfall\Content\Coop\ModLibrary.uasset");
    Console.WriteLine("Patched ModLibrary");
}

{
    var modActor = new UAsset(@".\Sandfall\Windows\Sandfall\Content\Coop\ModActor.uasset", EngineVersion.VER_UE5_4, usmap);
    var setterFunc = (FunctionExport)modActor["set_PlayerControllerClass"];

    var name = new FName(modActor, modActor.AddNameReference(new FString(setterFunc.ObjectName.ToString()[4..])));
    var funcIndex = FPackageIndex.FromExport(modActor.Exports.IndexOf(setterFunc));
    var targetObj = (FObjectProperty)setterFunc.LoadedProperties[0];
    var newVal = setterFunc.LoadedProperties[1];

    // unreal engine doesn't check at runtime whether a property is BlueprintReadOnly, so we can just create a function that sets the GameMode->PlayerControllerClass
    var setterExpression =
        new EX_LetObj {
            AssignmentExpression =
                new EX_LocalVariable { Variable = new KismetPropertyPointer { New = new FFieldPath { Path = [newVal.Name], ResolvedOwner = funcIndex } } },
            VariableExpression = new EX_Context {
                ContextExpression =
                    new EX_InstanceVariable {
                        Variable = new KismetPropertyPointer { New = new FFieldPath { Path = [name], ResolvedOwner = targetObj.PropertyClass } }
                    },
                ObjectExpression =
                    new EX_LocalVariable {
                        Variable = new KismetPropertyPointer { New = new FFieldPath { Path = [targetObj.Name], ResolvedOwner = funcIndex } }
                    },
                Offset = 9,
                RValuePointer = new KismetPropertyPointer { New = new FFieldPath { Path = [targetObj.Name], ResolvedOwner = funcIndex } }
            }
        };
    var @return = new EX_Return { ReturnExpression = new EX_Nothing() };
    var endOfScript = new EX_EndOfScript();
    setterFunc.ScriptBytecode = [setterExpression, @return, endOfScript];

    typeof(UAsset).GetField("NamesReferencedFromExportDataCount", BindingFlags.NonPublic | BindingFlags.Instance)!.SetValue(modActor,
        modActor.GetNameMapIndexList().Count);

    modActor.Write(@".\Sandfall\Windows\Sandfall\Content/Coop/ModActor.uasset");
    Console.WriteLine("Patched ModActor");
}

string[] filesToHook = [
    "jRPGTemplate/Blueprints/Basics/BP_jRPG_Character_Battle_Base",
    "jRPGTemplate/Blueprints/Basics/BP_jRPG_Controller_World",
    "jRPGTemplate/Blueprints/Basics/BP_jRPG_GM_World",
    "UI/Widgets/MainMenu/WBP_MM_MainMenu",
    "UI/Widgets/InGame_Menu/Team/WBP_TeamCard_CharacterStatus"
];

foreach (var file in filesToHook) {
    var proc = Process.Start(Path.Join(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), "ue-hook-blueprints.exe"),
    [
        $@".\Sandfall\Windows\Sandfall\Content\{file}.uasset",
        $@".\Export\Sandfall\Content\{file}.uasset",
        "--ueversion", "VER_UE5_4",
        "--mappings", "Mappings.usmap"
    ]);
    proc.WaitForExit();
    if (proc.ExitCode != 0)
        throw new Exception($"ue-hook-blueprints.exe failed with {proc.ExitCode}");
}

var retocProc = Process.Start("retoc.exe",
[
    "to-zen", @".\Sandfall\Windows", "expedition33_coop_P.utoc",
    "--version", "UE5_4",
    "--filter", "Content/Coop",
    ..filesToHook.SelectMany<string, string>(f => ["--filter", f])
]);
retocProc.WaitForExit();
if (retocProc.ExitCode != 0)
    throw new Exception($"retoc.exe failed with {retocProc.ExitCode}");