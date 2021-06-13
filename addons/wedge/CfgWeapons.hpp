class CfgWeapons {
        class ACE_ItemCore;
        class CBA_MiscItem_ItemInfo;

        class AMP_Door_Wedge: ACE_ItemCore {
                author = "Ampersand";
                displayName = "Door Wedge";
                descriptionShort = "A door wedge is used to quickly block a door from moving.";
                model = "\A3\Structures_F_Heli\Items\Tools\WheelChock_01_F.p3d";
                picture = "\z\TF47\addons\wedge\assets\doorstop_white.paa";
                scope = 2;
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 0.5;
                };
        };
};
