
class Extended_PostInit_EventHandlers
{
    class unflipping
    {
        serverInit = "call compile preprocessFileLineNumbers 'z\TF47\addons\unflipping\XEH_postInitServer.sqf'";
        clientInit = "call compile preprocessFileLineNumbers 'z\TF47\addons\unflipping\XEH_postInitClient.sqf'";
    };
};
class Extended_PreInit_EventHandlers
{
    class unflipping
    {
        init = "call compile preprocessFileLineNumbers 'z\TF47\addons\unflipping\XEH_preInit.sqf'";
    };
};
