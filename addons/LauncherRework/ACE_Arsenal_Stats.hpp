class ace_arsenal_stats {
    class statBase;

    class maaws_adm: statBase {
        scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
        displayName = "Launcher Ammo Description"; // Title of the stat.
        priority = 0; // A higher value means the stat will be displayed higher on the page.
        showText = 1; // 0 disabled; 1 enabled;
        textStatement = ""; // statement evaluated to set the text entry, can return anything.
        condition = ""; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
        tabs[] = {{}, {7}};
    };
};