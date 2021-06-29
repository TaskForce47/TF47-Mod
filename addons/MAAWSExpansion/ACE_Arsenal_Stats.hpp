class ace_arsenal_stats {
    class statBase;

    class maaws_adm: statBase {
        scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
        displayName = "Launcher Ammo Description"; // Title of the stat.
        priority = 0; // A higher value means the stat will be displayed higher on the page.
        showText = 1; // 0 disabled; 1 enabled;
        textStatement = "ADM 401 combats enemy troops in the open and soft‑skinned vehicles by launching a cluster of flechettes"; // statement evaluated to set the text entry, can return anything.
        condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv401_adm' || (configName (_this select 1)) == 'tf47_mag_raws_ffv401_adm')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
        tabs[] = {{}, {7}};
    };