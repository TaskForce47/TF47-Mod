class CfgWeapons
{
        class CBA_MiscItem;
        class CBA_MiscItem_ItemInfo;
        class TF47_AUR_Grappling_Hook: CBA_MiscItem {
                scope = 2;
                author = "TF47 Rampage";
                displayName = "$STR_AUR_Grappling_Hook";
                descriptionShort = "$STR_AUR_Grappling_Hook_Descr";
                //model = "\z\ace\addons\apl\ace_entrchtool.p3d";
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\grappling_hook.paa";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 10;
                };
        };
        class AUR_Rappel_Gear: CBA_MiscItem
        {
                scope = 2;
                displayName = "$STR_AUR_RAPPELING_GEAR";
                descriptionShort = "$STR_AUR_RAPPELING_GEAR_DESCR";
                author = "TF47 Rampage";
                model = "A3\Weapons_F\Items\ToolKit";
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\m_harness_ca";
                class ItemInfo: CBA_MiscItem_ItemInfo
                {
                        mass = 8;
                };
        };
        class AUR_Rappel_Rope_10: CBA_MiscItem
        {
                scope = 2;
                displayName = "$STR_AUR_RAPPELING_ROPE_10";
                descriptionShort = "$STR_AUR_RAPPELING_ROPE_DESCR_10";
                author = "TF47 Rampage";
                model = "\A3\Structures_F_Heli\Items\Tools\Rope_01_F.p3d";
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\m_rope_ca";
                class ItemInfo: CBA_MiscItem_ItemInfo
                {
                        mass = 5;
                };
        };
        class AUR_Rappel_Rope_20: AUR_Rappel_Rope_10
        {
                scope = 2;
                displayName = "$STR_AUR_RAPPELING_ROPE_20";
                descriptionShort = "$STR_AUR_RAPPELING_ROPE_DESCR_20";
                author = "TF47 Rampage";
                class ItemInfo: CBA_MiscItem_ItemInfo
                {
                        mass = 10;
                };
        };
        class AUR_Rappel_Rope_30: AUR_Rappel_Rope_20
        {
                scope = 2;
                displayName = "$STR_AUR_RAPPELING_ROPE_30";
                descriptionShort = "$STR_AUR_RAPPELING_ROPE_DESCR_30";
                class ItemInfo: CBA_MiscItem_ItemInfo
                {
                        mass = 15;
                };
        };
        class AUR_Rappel_Rope_50: AUR_Rappel_Rope_20
        {
                scope = 2;
                displayName = "$STR_AUR_RAPPELING_ROPE_50";
                descriptionShort = "$STR_AUR_RAPPELING_ROPE_DESCR_50";
                class ItemInfo: CBA_MiscItem_ItemInfo
                {
                        mass = 25;
                };
        };
        class AUR_Rappel_Rope_70: AUR_Rappel_Rope_20
        {
                scope = 2;
                displayName = "$STR_AUR_RAPPELING_ROPE_70";
                descriptionShort = "$STR_AUR_RAPPELING_ROPE_DESCR_70";
                class ItemInfo: CBA_MiscItem_ItemInfo
                {
                        mass = 35;
                };
        };
        class AUR_rope30: CBA_MiscItem {
                scope = 2;
                GVAR(ropeLength) = 30;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\rope_Icon.paa";
                model = "\A3\Structures_F_Heli\Items\Tools\Rope_01_F.p3d";
                displayName = "30m Climbing Rope";
                descriptionShort = "9.8mm Rope suitable for climbing or rappelling";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 42;
                };

        };
        class AUR_rope40: CBA_MiscItem {
                scope = 2;
                GVAR(ropeLength) = 40;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\rope_Icon.paa";
                model = "\A3\Structures_F_Heli\Items\Tools\Rope_01_F.p3d";
                displayName = "40m Climbing Rope";
                descriptionShort = "9.8mm Rope suitable for climbing or rappelling";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 56;
                };
        };
        class AUR_rope50: CBA_MiscItem {
                scope = 2;
                GVAR(ropeLength) = 50;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\rope_Icon.paa";
                model = "\A3\Structures_F_Heli\Items\Tools\Rope_01_F.p3d";
                displayName = "50m Climbing Rope";
                descriptionShort = "9.8mm Rope suitable for climbing or rappelling";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 70;
                };
        };
        class AUR_rope60: CBA_MiscItem {
                scope = 2;
                GVAR(ropeLength) = 60;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\rope_Icon.paa";
                model = "\A3\Structures_F_Heli\Items\Tools\Rope_01_F.p3d";
                displayName = "60m Climbing Rope";
                descriptionShort = "9.8mm Rope suitable for climbing or rappelling";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 84;
                };
        };
        class AUR_rope80: CBA_MiscItem {
                scope = 2;
                GVAR(ropeLength) = 80;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\rope_Icon.paa";
                model = "\A3\Structures_F_Heli\Items\Tools\Rope_01_F.p3d";
                displayName = "80m Climbing Rope";
                descriptionShort = "9.8mm Rope suitable for climbing or rappelling";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 112;
                };
        };
        class AUR_rope100: CBA_MiscItem {
                scope = 2;
                GVAR(ropeLength) = 100;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\rope_Icon.paa";
                model = "\A3\Structures_F_Heli\Items\Tools\Rope_01_F.p3d";
                displayName = "100m Climbing Rope";
                descriptionShort = "9.8mm Rope suitable for climbing or rappelling";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 140;
                };
        };
        class AUR_AnchorKit: CBA_MiscItem {
                scope = 2;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\anchor.paa";
                model = "\A3\Structures_F_EPA\Items\Tools\MetalWire_F.p3d";
                displayName = "Rappelling Anchor Kit";
                descriptionShort = "An unassembled rappelling anchor";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 1;
                };
        };
        class AUR_BelayDevice: CBA_MiscItem {
                scope = 2;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\belay.paa";
                model = "\A3\Structures_F_EPA\Items\Tools\CanOpener_F.p3d";
                displayName = "Belay device/descender";
                descriptionShort = "Multifunction belay and rappelling device";
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 2;
                };
        };
            class AUR_AscenderDevice: CBA_MiscItem {
                scope = 2;
                picture = "\z\TF47\addons\AdvancedUrbanRappelling\assets\tcx.paa";
                model = "\A3\Weapons_F\Items\Toolkit";
                displayName = "TCX Force";
                descriptionShort = "The TCX Force is specifically developed to be used for any land based or urban operations, for fast heavy lifting operations."; //http://www.actsafe.se/product/tcx-assault has two version, a 250kg/24m/min and a 150kg/60m/min this is the best of both worlds.
                class ItemInfo: CBA_MiscItem_ItemInfo {
                        mass = 60;
                };
        };

};