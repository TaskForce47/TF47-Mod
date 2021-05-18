#define _ARMA_

class CfgPatches
{
   class modules_f_vietnam
   {
      author = "SGD";
      appId = 1227700;
      name = "modules_f_vietnam";
      url = "https://www.arma3.com";
      units[] = {};
      weapons[] = {};
      requiredVersion = 0.1;
      requiredAddons[] = {"A3_data_F","A3_Modules_F_Curator"};
   };
};
class CfgFunctions
{
   class modules_f_vietnam
   {
      tag = "VN";
      class master_functions
      {
         file = "\vn\modules_f_vietnam\functions";
         class module_artillery{};
      };
      class artillery_functions
      {
         file = "\vn\modules_f_vietnam\functions\artillery";
         class artillery_bombard{};
         class artillery_init{};
         class artillery_menu{};
         class artillery_message{};
         class artillery_server_check{};
         class artillery_radio{};
         class artillery_resupply{};
         class artillery_transport{};
         class artillery_score_set{};
         class artillery_plane{};
         class artillery_heli{};
         class artillery_actions{};
         class artillery_bomb_guide{};
      };
      class artillery_ammo_functions
      {
         file = "\vn\modules_f_vietnam\functions\artillery\functions";
         class artillery_commando_vault{};
         class artillery_arc_light{};
         class artillery_dawn_1{};
      };
   };
};
class vn_modulesettings
{
   vn_unsung_maps[] = {"cam_lao_nam"};
   class vn_drm_settings
   {
      class objects
      {
         class vn_b_prop_prc77_01
         {
            channels[] = {1};
            autostart = 1;
         };
         class vn_b_item_radio_urc10_gh: vn_b_prop_prc77_01{};
         class vn_b_prop_vrc12: vn_b_prop_prc77_01{};
         class Land_vn_radio
         {
            channels[] = {3};
            autostart = 1;
         };
         class vn_b_prop_fmradio_01: Land_vn_radio{};
      };
      class backpacks
      {
         class vn_b_pack_prc77_01
         {
            channels[] = {1};
         };
         class vn_b_pack_lw_06: vn_b_pack_prc77_01{};
         class vn_b_pack_trp_04_02: vn_b_pack_prc77_01{};
         class vn_b_pack_03_02: vn_b_pack_prc77_01{};
         class vn_b_pack_03: vn_b_pack_prc77_01{};
         class vn_b_pack_trp_04: vn_b_pack_prc77_01{};
      };
   };
};
class vn_artillery_settings
{
   cost_variable = "";
   availability[] = {1,0,0,0,0};
   danger_distance = 150;
   unit_trait_required = 0;
   radio_backpacks[] = {"vn_o_pack_t884_01","vn_o_pack_t884_ish54_01_pl","vn_o_pack_t884_m1_01_pl","vn_o_pack_t884_m38_01_pl","vn_o_pack_t884_ppsh_01_pl","vn_b_pack_prc77_01_m16_pl","vn_b_pack_03_m3a1_pl","vn_b_pack_03_xm177_pl","vn_b_pack_03_type56_pl","vn_b_pack_03","vn_b_pack_prc77_01","vn_b_pack_trp_04","vn_b_pack_trp_04_02","vn_b_pack_03","vn_b_pack_03_02","vn_b_pack_lw_06"};
   radio_vehicles[] = {"vn_b_boat_05_01","vn_b_wheeled_m54_03","vn_b_wheeled_m151_01","vn_b_wheeled_m54_02","vn_b_wheeled_m54_01","vn_b_wheeled_m54_mg_02","vn_i_air_ch34_02_01","vn_i_air_ch34_01_02","vn_i_air_ch34_02_02"};
   player_types[] = {"vn_b_men_sog_05","vn_b_men_sog_17","vn_b_men_army_08","vn_o_men_nva_dc_13","vn_o_men_nva_65_27","vn_o_men_nva_65_13","vn_o_men_nva_27","vn_o_men_nva_13","vn_o_men_nva_marine_13","vn_o_men_nva_navy_13","vn_o_men_vc_local_27","vn_o_men_vc_local_13","vn_o_men_vc_regional_13"};
   class aircraft
   {
      class he
      {
         displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_HE_NAME";
         class commando_vault
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_COMMANDO_VAULT_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_29tas_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_COMMANDO_VAULT_DESCRIPTION";
            function = "vn_fnc_artillery_commando_vault";
            divergence = -45;
            cooldown = "(60*5)";
            cost = 50;
         };
         class arc_light
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_ARC_LIGHT_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_69bs_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_ARC_LIGHT_DESCRIPTION";
            function = "vn_fnc_artillery_arc_light";
            divergence = 200;
            cooldown = "(60*5)";
            cost = 50;
         };
         class rambler
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_CLUSTER_RAMBLER_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_433tfs_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_VESPA_DESCRIPTION";
            magazines[] = {"vn_bomb_500_mk82_he_mag_x1","vn_bomb_500_mk82_he_mag_x1"};
            vehicleclass = "vn_b_air_f4c_cas";
            cooldown = "(60*5)";
            cost = 10;
         };
         class sundowner
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_SUNDOWNER_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_vf111_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_SUNDOWNER_DESCRIPTION";
            magazines[] = {"vn_bomb_500_blu1b_fb_mag_x1","vn_bomb_500_blu1b_fb_mag_x1"};
            vehicleclass = "vn_b_air_f4c_cas";
            allow_double = 1;
            cooldown = "(60*5)";
            cost = 15;
         };
         class snake
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_SNAKE_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_vmfa323_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_SNAKE_DESCRIPTION";
            magazines[] = {"vn_rocket_s5_he_x16"};
            vehicleclass = "vn_b_air_f4c_cas";
            cooldown = "(60*5)";
            cost = 10;
         };
         class showtime
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_SHOWTIME_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_vf96_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_SHOWTIME_DESCRIPTION";
            magazines[] = {"vn_m61a1"};
            vehicleclass = "vn_b_air_f4c_cas";
            cooldown = "(60*5)";
            cost = 6;
         };
         class hobo
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_HOBO_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_1sos_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_HOBO_DESCRIPTION";
            magazines[] = {"vn_m61a1"};
            vehicleclass = "vn_b_air_f4c_cas";
            cooldown = "(60*5)";
            cost = 6;
         };
         class condor
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_CONDOR_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_b101_ca";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_CONDOR_DESCRIPTION";
            magazines[] = {"vn_rocket_ffar_m229_he_x7","vn_rocket_ffar_m229_he_x7"};
            vehicleclass = "vn_b_air_ah1g_01";
            cooldown = "(5*60)";
            cost = 6;
         };
         class dragon
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_DRAGON_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_a477_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_DRAGON_DESCRIPTION";
            magazines[] = {"vn_rocket_ffar_m229_he_x19","vn_rocket_ffar_m229_he_x19"};
            vehicleclass = "vn_b_air_uh1c_01_02";
            cooldown = "(5*60)";
            cost = 16;
         };
      };
      class cluster
      {
         displayname = "$STR_VN_ARTILLERY_AIRCRAFT_CLUSTER_CLUSTER_NAME";
         class rambler
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_CLUSTER_RAMBLER_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_433tfs_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_CLUSTER_RAMBLER_DESCRIPTION";
            magazines[] = {"vn_bomb_f4_out_500_mk20_cb_mag_x1","vn_bomb_f4_out_500_mk20_cb_mag_x1"};
            vehicleclass = "vn_b_air_f4c_cas";
            allow_double = 1;
            cost = 20;
         };
      };
      class flechette
      {
         displayname = "$STR_VN_ARTILLERY_AIRCRAFT_FLECHETTE_FLECHETTE_NAME";
         class combat
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_FLECHETTE_COMBAT_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_vmfa314_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_FLECHETTE_COMBAT_DESCRIPTION";
            magazines[] = {"","","vn_rocket_ffar_f4_lau3_wdu4_flechette_x19","vn_rocket_ffar_f4_lau3_wdu4_flechette_x19"};
            vehicleclass = "vn_b_air_f4c_cas";
            allow_double = 1;
            cooldown = "(5*60)";
            cost = 8;
         };
         class banshee
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_FLECHETTE_BANSHEE_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_29tas_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_FLECHETTE_BANSHEE_DESCRIPTION";
            magazines[] = {"vn_rocket_ffar_wdu4_flechette_x7","vn_rocket_ffar_wdu4_flechette_x7"};
            vehicleclass = "vn_b_air_ah1g_04";
            allow_double = 1;
            cooldown = "(5*60)";
            cost = 6;
         };
         class scarface
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_FLECHETTE_SCARFACE_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_vmo3_co.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_FLECHETTE_SCARFACE_DESCRIPTION";
            magazines[] = {"vn_rocket_ffar_wdu4_flechette_x19","vn_rocket_ffar_wdu4_flechette_x19"};
            vehicleclass = "vn_b_air_uh1c_01_07";
            allow_double = 1;
            cooldown = "(5*60)";
            cost = 12;
         };
      };
      class heat
      {
         displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_HEAT_NAME";
         class eagle_claw
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_HE_EAGLE_CLAW_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_hml367_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_HE_EAGLE_CLAW_DESCRIPTION";
            magazines[] = {"vn_rocket_ffar_m229_he_x19","vn_rocket_ffar_m229_he_x19"};
            vehicleclass = "vn_b_air_ah1g_01";
            allow_double = 1;
            cooldown = "(5*60)";
            cost = 6;
         };
      };
      class illumination
      {
         displayname = "$STR_VN_ARTILLERY_AIRCRAFT_ILLUMINATION_ILLUMINATION_NAME";
         class gnat
         {
            displayname = "$STR_VN_ARTILLERY_AIRCRAFT_ILLUMINATION_GNAT_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_a101_ca.paa";
            description = "$STR_VN_ARTILLERY_AIRCRAFT_ILLUMINATION_GNAT_DESCRIPTION";
            magazines[] = {};
            vehicleclass = "vn_b_air_uh1d_02_03";
            allow_double = 1;
            cooldown = "(5*60)";
            illumination = 1;
            cost = 0;
         };
         class dawn_1
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_DAWN_1_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_usarmy_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_DAWN_1_DESCRIPTION";
            condition = "daytime >= 18 || daytime <= 6";
            function = "vn_fnc_artillery_dawn_1";
            allow_double = 0;
            cooldown = "(60*5)";
            illumination = 1;
            cost = 0;
         };
      };
   };
   class artillery
   {
      class illumination
      {
         displayname = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_ILLUMINATION_NAME";
         class baker_1
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_BAKER_1_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l176_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_BAKER_1_DESCRIPTION";
            ammo[] = {"vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 150;
            count = 1;
            illumination = 1;
            cost = 0;
         };
         class mike_1
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_MIKE_1_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l119_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_MIKE_1_DESCRIPTION";
            ammo[] = {"vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 150;
            count = 1;
            illumination = 1;
            cost = 0;
         };
         class easy_1
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_EASY_1_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_hmm362_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_ILLUMINATION_EASY_1_DESCRIPTION";
            ammo[] = {"vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo","vn_flare_plane_med_w_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 150;
            count = 1;
            illumination = 1;
            cost = 0;
         };
      };
      class wp
      {
         displayname = "$STR_VN_ARTILLERY_ARTILLERY_WP_WP_NAME";
         class baker_2
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_WP_BAKER_2_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l176_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_WP_BAKER_2_DESCRIPTION";
            ammo[] = {"vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 10;
         };
         class mike_2
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_WP_MIKE_2_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l119_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_WP_MIKE_2_DESCRIPTION";
            ammo[] = {"vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo","vn_shell_105mm_m60_wp_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 8;
         };
         class easy_2
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_WP_EASY_2_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_hmm362_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_WP_EASY_2_DESCRIPTION";
            ammo[] = {"vn_shell_60mm_m302_wp_ammo","vn_shell_60mm_m302_wp_ammo","vn_shell_60mm_m302_wp_ammo","vn_shell_60mm_m302_wp_ammo","vn_shell_60mm_m302_wp_ammo","vn_shell_60mm_m302_wp_ammo","vn_shell_60mm_m302_wp_ammo","vn_shell_60mm_m302_wp_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 4;
         };
      };
      class he
      {
         displayname = "$STR_VN_ARTILLERY_ARTILLERY_HE_HE_NAME";
         class baker_3
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_HE_BAKER_3_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l176_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_HE_BAKER_3_DESCRIPTION";
            ammo[] = {"vn_shell_105mm_m1_he_ammo","vn_shell_105mm_m1_he_ammo","vn_shell_105mm_m1_he_ammo","vn_shell_105mm_m1_he_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 16;
         };
         class mike_3: baker_3
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_HE_MIKE_3_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l119_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_HE_MIKE_3_DESCRIPTION";
            ammo[] = {"vn_shell_81mm_m43_he_ammo","vn_shell_81mm_m43_he_ammo","vn_shell_81mm_m43_he_ammo","vn_shell_81mm_m43_he_ammo","vn_shell_81mm_m43_he_ammo","vn_shell_81mm_m43_he_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 12;
         };
         class easy_3: baker_3
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_HE_EASY_3_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_hmm362_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_HE_EASY_3_DESCRIPTION";
            ammo[] = {"vn_shell_60mm_m49a2_he_ammo","vn_shell_60mm_m49a2_he_ammo","vn_shell_60mm_m49a2_he_ammo","vn_shell_60mm_m49a2_he_ammo","vn_shell_60mm_m49a2_he_ammo","vn_shell_60mm_m49a2_he_ammo","vn_shell_60mm_m49a2_he_ammo","vn_shell_60mm_m49a2_he_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 8;
         };
      };
      class chemical
      {
         displayname = "$STR_VN_ARTILLERY_ARTILLERY_CHEMICAL_CHEMICAL_NAME";
         class baker_4
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_CHEMICAL_BAKER_4_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l176_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_CHEMICAL_BAKER_4_DESCRIPTION";
            ammo[] = {"vn_shell_105mm_m60_chem_ammo","vn_shell_105mm_m60_chem_ammo","vn_shell_105mm_m60_chem_ammo","vn_shell_105mm_m60_chem_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 8;
         };
         class mike_4: baker_4
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_CHEMICAL_MIKE_4_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l119_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_CHEMICAL_MIKE_4_DESCRIPTION";
            ammo[] = {"vn_shell_81mm_m57_fs_ammo","vn_shell_81mm_m57_fs_ammo","vn_shell_81mm_m57_fs_ammo","vn_shell_81mm_m57_fs_ammo","vn_shell_81mm_m57_fs_ammo","vn_shell_81mm_m57_fs_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 6;
         };
      };
      class frag
      {
         displayname = "$STR_VN_ARTILLERY_ARTILLERY_FRAG_FRAG_NAME";
         class baker_5
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_FRAG_BAKER_5_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l176_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_FRAG_BAKER_5_DESCRIPTION";
            ammo[] = {"vn_shell_105mm_m546_frag_ammo","vn_shell_105mm_m546_frag_ammo","vn_shell_105mm_m546_frag_ammo","vn_shell_105mm_m546_frag_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 8;
         };
      };
      class airburst
      {
         displayname = "$STR_VN_ARTILLERY_ARTILLERY_AIRBURST_AIRBURST_NAME";
         class baker_6
         {
            displayname = "$STR_VN_ARTILLERY_ARTILLERY_AIRBURST_BAKER_6_NAME";
            icon = "vn\ui_f_vietnam\data\decals\vn_callsign_src_l176_ca.paa";
            description = "$STR_VN_ARTILLERY_ARTILLERY_AIRBURST_BAKER_6_DESCRIPTION";
            ammo[] = {"vn_shell_105mm_m1_ab_ammo","vn_shell_105mm_m1_ab_ammo","vn_shell_105mm_m1_ab_ammo","vn_shell_105mm_m1_ab_ammo"};
            allow_double = 1;
            cooldown = "(60*5)";
            divergence = 50;
            count = 1;
            cost = 16;
         };
      };
   };
};
class ctrlDefault;
class ctrlDefaultText;
class ctrlDefaultButton;
class ctrlStatic;
class ctrlStaticPicture;
class ctrlStaticPictureKeepAspect;
class ctrlStaticPictureTile;
class ctrlStaticFrame;
class ctrlStaticLine;
class ctrlStaticMulti;
class ctrlStaticBackground;
class ctrlStaticOverlay;
class ctrlStaticTitle;
class ctrlStaticFooter;
class ctrlStaticBackgroundDisable;
class ctrlStaticBackgroundDisableTiles;
class ctrlButton;
class ctrlButtonPicture;
class ctrlButtonPictureKeepAspect;
class ctrlButtonOK;
class ctrlButtonCancel;
class ctrlButtonClose;
class ctrlButtonToolbar;
class ctrlButtonSearch;
class ctrlButtonExpandAll;
class ctrlButtonCollapseAll;
class ctrlButtonFilter;
class ctrlEdit;
class ctrlEditMulti;
class ctrlSliderV;
class ctrlSliderH;
class ctrlCombo;
class ctrlComboToolbar;
class ctrlListbox;
class ctrlToolbox;
class ctrlToolboxPicture;
class ctrlToolboxPictureKeepAspect;
class ctrlCheckboxes;
class ctrlCheckboxesCheckbox;
class ctrlProgress;
class ctrlHTML;
class ctrlActiveText;
class ctrlActivePicture;
class ctrlActivePictureKeepAspect;
class ctrlTree;
class ctrlStructuredText;
class ctrlControlsGroup;
class ctrlControlsGroupNoScrollbars;
class ctrlControlsGroupNoHScrollbars;
class ctrlControlsGroupNoVScrollbars;
class ctrlShortcutButton;
class ctrlShortcutButtonOK;
class ctrlShortcutButtonCancel;
class ctrlShortcutButtonSteam;
class ctrlXListbox;
class ctrlXSliderV;
class ctrlXSliderH;
class ctrlMenu;
class ctrlMenuStrip;
class ctrlObject;
class ctrlObjectContainer;
class ctrlObjectZoom;
class ctrlMap: ctrlDefault
{
   class LineMarker;
   class Legend;
   class Task;
   class ActiveMarker;
   class Waypoint;
   class WaypointCompleted;
   class CustomMark;
   class Command;
   class Bush;
   class SmallTree;
   class Tree;
   class Rock;
   class BusStop;
   class FuelStation;
   class Hospital;
   class Church;
   class Lighthouse;
   class Power;
   class PowerSolar;
   class PowerWave;
   class PowerWind;
   class Quay;
   class Transmitter;
   class Watertower;
   class Cross;
   class Chapel;
   class Shipwreck;
   class Bunker;
   class Fortress;
   class Fountain;
   class Ruin;
   class Stack;
   class Tourism;
   class ViewTower;
};
class ctrlMapMain;
class ctrlListNBox;
class ctrlCheckbox;
class ctrlCheckboxToolbar;
class ctrlCheckboxBaseline;
class ctrlControlsGroupHighlight;
class ctrlControlsGroupTutorial;
class RscProgress;
class RscText;
class RscButtonArsenal;
class RscListBox;
class RscButtonMenu;
class RscControlsGroup;
class RscActivePicture;
class RscActiveText;
class RscControlsGroupNoScrollbars;
class RscStructuredText;
class RscFrame;
class RscPictureKeepAspect;
class vn_displayartillery
{
   idd = 19557;
   enablesimulation = 1;
   enabledisplay = 1;
   onLoad = "['onload',_this] call vn_fnc_artillery_menu;";
   onUnload = "['onunload',_this] call vn_fnc_artillery_menu;";
   class controlsBackground
   {
      class Radio_CA: ctrlStaticPicture
      {
         text = "\vn\modules_f_vietnam\data\Radio\radio_ca.paa";
         x = "((getResolution select 2) * 0.5 * pixelW) - 70 * (pixelW * pixelGrid * 0.50)";
         y = "((getResolution select 3) * 0.5 * pixelH) - 75 * (pixelH * pixelGrid * 0.50)";
         w = "200 * (pixelW * pixelGrid * 0.50)";
         h = "100 * (pixelH * pixelGrid * 0.50)";
      };
   };
   class controls
   {
      class RadioGroup: ctrlControlsGroupNoScrollbars
      {
         idc = -1;
         x = "((getResolution select 2) * 0.5 * pixelW) - 70 * (pixelW * pixelGrid * 0.50)";
         y = "((getResolution select 3) * 0.5 * pixelH) - 75 * (pixelH * pixelGrid * 0.50)";
         w = "200 * (pixelW * pixelGrid * 0.50)";
         h = "60 * (pixelH * pixelGrid * 0.50)";
         class controls
         {
            class BandDial: ctrlStaticPicture
            {
               text = "\vn\modules_f_vietnam\data\Radio\dial_3_ca.paa";
               angle = 90;
               color[] = {0.8,0.8,0.8,1};
               colorActive[] = {1,1,1,1};
               colorDisabled[] = {1,1,1,1};
               x = "33 * (pixelW * pixelGrid * 0.50)";
               y = "40 * (pixelH * pixelGrid * 0.50)";
               w = "16 * (pixelW * pixelGrid * 0.50)";
               h = "16 * (pixelH * pixelGrid * 0.50)";
            };
            class BandDialButton: ctrlButton
            {
               idc = -1;
               x = "33 * (pixelW * pixelGrid * 0.50)";
               y = "40 * (pixelH * pixelGrid * 0.50)";
               w = "16 * (pixelW * pixelGrid * 0.50)";
               h = "16 * (pixelH * pixelGrid * 0.50)";
               colorBackground[] = {0,0,0,0};
               colorBackgroundDisabled[] = {0,0,0,0};
               colorBackgroundActive[] = {0,0,0,0};
               colorFocused[] = {0,0,0,0};
               colorDisabled[] = {0,0,0,0};
               colorText[] = {0,0,0,0};
            };
            class PresetLDial: BandDial
            {
               text = "\vn\modules_f_vietnam\data\Radio\dial_1_ca.paa";
               onload = "uiNamespace setVariable ['vn_artillery_display_preser_button',(_this#0)]";
               x = "53.5 * (pixelW * pixelGrid * 0.50)";
               y = "31 * (pixelH * pixelGrid * 0.50)";
               w = "14 * (pixelW * pixelGrid * 0.50)";
               h = "14 * (pixelH * pixelGrid * 0.50)";
            };
            class PresetLDialButton: BandDialButton
            {
               idc = -1;
               x = "53.5 * (pixelW * pixelGrid * 0.50)";
               y = "31 * (pixelH * pixelGrid * 0.50)";
               w = "14 * (pixelW * pixelGrid * 0.50)";
               h = "14 * (pixelH * pixelGrid * 0.50)";
               onButtonClick = "['radio:type'] call vn_fnc_artillery_menu;";
            };
            class PresetRDial: PresetLDial
            {
               onload = "";
               x = "90 * (pixelW * pixelGrid * 0.50)";
            };
            class PresetRDialButton: PresetLDialButton
            {
               x = "90 * (pixelW * pixelGrid * 0.50)";
               onButtonClick = "";
            };
            class VolumeDial: BandDial
            {
               text = "\vn\modules_f_vietnam\data\Radio\dial_2_ca.paa";
               x = "120 * (pixelW * pixelGrid * 0.50)";
               y = "26.5 * (pixelH * pixelGrid * 0.50)";
               w = "13 * (pixelW * pixelGrid * 0.50)";
               h = "13 * (pixelH * pixelGrid * 0.50)";
            };
            class VolumeDialButton: BandDialButton
            {
               x = "120 * (pixelW * pixelGrid * 0.50)";
               y = "26.5 * (pixelH * pixelGrid * 0.50)";
               w = "13 * (pixelW * pixelGrid * 0.50)";
               h = "13 * (pixelH * pixelGrid * 0.50)";
            };
            class SettingDial: BandDial
            {
               x = "118 * (pixelW * pixelGrid * 0.50)";
               y = "43.5 * (pixelH * pixelGrid * 0.50)";
               w = "16 * (pixelW * pixelGrid * 0.50)";
               h = "16 * (pixelH * pixelGrid * 0.50)";
            };
            class SettingDialButton: BandDialButton
            {
               x = "118 * (pixelW * pixelGrid * 0.50)";
               y = "43.5 * (pixelH * pixelGrid * 0.50)";
               w = "16 * (pixelW * pixelGrid * 0.50)";
               h = "16 * (pixelH * pixelGrid * 0.50)";
            };
         };
      };
      class MapFolder: ctrlStaticPictureKeepAspect
      {
         text = "\vn\modules_f_vietnam\data\vn_displayartillery\mapfolder.paa";
         x = "((getResolution select 2) * 0.5 * pixelW) - 0.5 * 200 * (pixelW * pixelGrid * 0.50)";
         y = "((getResolution select 3) * 0.5 * pixelH) - 10 * (pixelH * pixelGrid * 0.50)";
         w = "200 * (pixelW * pixelGrid * 0.50)";
         h = "0.5 * 200 * (pixelH * pixelGrid * 0.50)";
      };
      class map_selection: ctrlMap
      {
         idc = 7001;
         x = "((getResolution select 2) * 0.5 * pixelW) + 13 * (pixelW * pixelGrid * 0.50)";
         y = "((getResolution select 3) * 0.5 * pixelH) + 1 * (pixelH * pixelGrid * 0.50)";
         w = "73 * (pixelW * pixelGrid * 0.50)";
         h = "75 * (pixelH * pixelGrid * 0.50)";
         showCountourInterval = 0;
         class task
         {
            icon = "#(argb,8,8,3)color(0,0,0,0)";
            iconCreated = "#(argb,8,8,3)color(0,0,0,0)";
            iconCanceled = "#(argb,8,8,3)color(0,0,0,0)";
            iconDone = "#(argb,8,8,3)color(0,0,0,0)";
            iconFailed = "#(argb,8,8,3)color(0,0,0,0)";
            color[] = {0,0,0,0};
            colorCreated[] = {0,0,0,0};
            colorCanceled[] = {0,0,0,0};
            colorDone[] = {0,0,0,0};
            colorFailed[] = {0,0,0,0};
            size = 0;
         };
         class custommark
         {
            icon = "#(argb,8,8,3)color(0,0,0,0)";
            color[] = {0,0,0,0};
            size = 0;
            coefMax = 4;
            coefMin = 0.25;
            importance = 0;
         };
         class hospital: custommark{};
         class church: custommark{};
         class lighthouse: custommark{};
         class power: custommark{};
         class powersolar: custommark{};
         class powerwave: custommark{};
         class powerwind: custommark{};
         class transmitter: custommark{};
         class watertower: custommark{};
         class Cross: custommark{};
         class Chapel: custommark{};
         class tourism: custommark{};
         class biewtower: custommark{};
         class busstop: custommark{};
         class fuelstation: custommark{};
         class rock: custommark{};
         class smalltree: custommark{};
         class bush: custommark{};
         class fortress: custommark{};
         class fountain: custommark{};
         class quay: custommark{};
         class ruin: custommark{};
         class shipwreck: custommark{};
         class bunker: custommark{};
         class stack: custommark{};
      };
      class NotepadContent: ctrlControlsGroupNoScrollbars
      {
         x = "((getResolution select 2) * 0.5 * pixelW) - 84 * (pixelW * pixelGrid * 0.50)";
         y = "((getResolution select 3) * 0.5 * pixelH) + 2.5 * (pixelH * pixelGrid * 0.50)";
         w = "74 * (pixelW * pixelGrid * 0.50)";
         h = "75 * (pixelH * pixelGrid * 0.50)";
         class controls
         {
            class Title: ctrlStructuredText
            {
               idc = 350;
               text = "$STR_ARTILLERY_SUPPORT_AIR";
               x = 0;
               y = 0;
               w = "75 * (pixelW * pixelGrid * 0.50)";
               h = "5 * (pixelH * pixelGrid * 0.50)";
               size = "5 * (pixelH * pixelGrid * 0.50)";
               shadow = 0;
               class Attributes
               {
                  align = "center";
                  color = "#000000";
                  colorLink = "#D09B43";
                  size = 1;
                  font = "tt2020base_vn";
               };
            };
            class AmmoType: ctrlListbox
            {
               idc = 103;
               x = "0 * (pixelW * pixelGrid * 0.50)";
               y = "7.5 * (pixelH * pixelGrid * 0.50)";
               w = "36.5 * (pixelW * pixelGrid * 0.50)";
               h = "38.5 * (pixelH * pixelGrid * 0.50)";
               sizeEx = "3 * (pixelH * pixelGrid * 0.50)";
               font = "tt2020base_vn";
               colorBackground[] = {0,0,0,0};
               colorText[] = {0,0,0,1};
               shadow = 0;
            };
            class Teams: AmmoType
            {
               idc = 102;
               x = "36 * (pixelW * pixelGrid * 0.50)";
               w = "38 * (pixelW * pixelGrid * 0.50)";
               h = "34.5 * (pixelH * pixelGrid * 0.50)";
               rowHeight = "10 * (pixelH * pixelGrid * 0.50)";
               sizeEx = "3 * (pixelH * pixelGrid * 0.50)";
            };
            class Amount: ctrlCombo
            {
               idc = 104;
               x = "0.5 * (pixelW * pixelGrid * 0.50)";
               y = "50.25 * (pixelH * pixelGrid * 0.50)";
               w = "35 * (pixelW * pixelGrid * 0.50)";
               h = "5 * (pixelH * pixelGrid * 0.50)";
               font = "tt2020base_vn";
               sizeEx = "3 * (pixelH * pixelGrid * 0.50)";
               colorText[] = {0,0,0,1};
               colorSelect[] = {0,0,0,1};
               colorBackground[] = {0.9,0.9,0.86,1};
               class Items
               {
                  class Normal
                  {
                     text = "$STR_ARTILLERY_AMOUNT_NORMAL";
                  };
                  class Heavy
                  {
                     text = "$STR_ARTILLERY_AMOUNT_HEAVY";
                  };
               };
            };
            class Request: ctrlButton
            {
               idc = 105;
               text = "$STR_ARTILLERY_CONFIRM";
               font = "tt2020base_vn";
               sizeEx = "5 * (pixelH * pixelGrid * 0.50)";
               x = "36.5 * (pixelW * pixelGrid * 0.50)";
               y = "49 * (pixelH * pixelGrid * 0.50)";
               w = "37 * (pixelW * pixelGrid * 0.50)";
               h = "5 * (pixelH * pixelGrid * 0.50)";
            };
            class Info: ctrlStructuredText
            {
               text = "";
               idc = 203;
               x = 0;
               y = "59.5 * (pixelH * pixelGrid * 0.50)";
               w = "75 * (pixelW * pixelGrid * 0.50)";
               h = "15 * (pixelH * pixelGrid * 0.50)";
               size = "3 * (pixelH * pixelGrid * 0.50)";
               shadow = 0;
               class Attributes
               {
                  align = "left";
                  color = "#000000";
                  colorLink = "#D09B43";
                  size = 1;
                  font = "tt2020base_vn";
               };
            };
         };
      };
   };
};
class CfgVehicles
{
   class Logic;
   class Module_F: Logic
   {
      class AttributesBase
      {
         class Default;
         class Edit;
         class Combo;
         class Checkbox;
         class CheckboxNumber;
         class ModuleDescription;
         class Units;
      };
      class ModuleDescription
      {
         class AnyBrain;
      };
   };
   class vn_module_artillery: Module_F
   {
      scope = 2;
      scopeCurator = 1;
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      displayName = "$STR_RADIO_SUPPORT_NAME";
      _generalMacro = "vn_module_artillery";
      category = "vn_vietnammodules";
      function = "VN_fnc_module_artillery";
      functionPriority = 15;
      isGlobal = 2;
      isTriggerActivated = 1;
      isDisposable = 1;
      is3DEN = 0;
      class Attributes: AttributesBase
      {
         class ModuleDescription: ModuleDescription{};
      };
      class ModuleDescription: ModuleDescription
      {
         description = "$STR_RADIO_SUPPORT_DESCRIPTION";
      };
   };
   class moduleflare_f;
   class moduleordnancehowitzer_f;
   class vn_moduleordnancehowitzer_f: moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      _generalMacro = "vn_moduleordnancehowitzer_f";
      scope = 1;
      scopeCurator = 0;
      class Arguments{};
   };
   class vn_moduleflarewhite_f: moduleflare_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      _generalMacro = "ModuleFlareWhite_F";
      scope = 1;
      scopeCurator = 2;
      category = "Flares";
      displayName = "$STR_VN_40MM_M583_GRENADE_MAG_DN";
      portrait = "\a3\Modules_F_Curator\Data\portraitFlareWhite_ca.paa";
      ammo = "vn_40mm_m583_flare_w_ammo";
      class Arguments{};
   };
   class vn_moduleflareyellow_f: vn_moduleflarewhite_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      _generalMacro = "ModuleFlareYellow_F";
      displayName = "$STR_VN_40MM_M695_GRENADE_MAG_DN";
      portrait = "\a3\Modules_F_Curator\Data\portraitFlareYellow_ca.paa";
      ammo = "vn_40mm_m695_flare_y_ammo";
   };
   class vn_moduleflaregreen_f: vn_moduleflarewhite_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      _generalMacro = "ModuleFlareGreen_F";
      displayName = "$STR_VN_40MM_M661_GRENADE_MAG_DN";
      portrait = "\a3\Modules_F_Curator\Data\portraitFlareGreen_ca.paa";
      ammo = "vn_40mm_m661_flare_g_ammo";
   };
   class vn_moduleflarered_f: vn_moduleflarewhite_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      _generalMacro = "ModuleFlareRed_F";
      displayName = "$STR_VN_40MM_M662_GRENADE_MAG_DN";
      portrait = "\a3\Modules_F_Curator\Data\portraitFlareRed_ca.paa";
      ammo = "vn_40mm_m662_flare_r_ammo";
   };
   class vn_module_ordnance_AIR_bomb_500_mk82_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_500_mk82_he";
      displayName = "$STR_VN_MK82_LAUNCHER_DN";
      ammo = "vn_bomb_500_mk82_he_ammo";
   };
   class vn_module_ordnance_AIR_bomb_500_mk82_se: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_500_mk82_se";
      displayName = "$STR_VN_MK82_SE_LAUNCHER_DN";
      ammo = "vn_bomb_500_mk82_se_ammo";
   };
   class vn_module_ordnance_AIR_bomb_500_fab250_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_500_fab250_he";
      displayName = "$STR_VN_FAB_250_LAUNCHER_DN";
      ammo = "vn_bomb_500_fab250_he_ammo";
   };
   class vn_module_ordnance_AIR_bomb_500_mk82_dc: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_500_mk82_dc";
      displayName = "$STR_VN_MK82_DC_LAUNCHER_DN";
      ammo = "vn_bomb_500_mk82_dc_ammo";
   };
   class vn_module_ordnance_AIR_bomb_750_m117_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_750_m117_he";
      displayName = "$STR_VN_M117_LAUNCHER_DN";
      ammo = "vn_bomb_750_m117_he_ammo";
   };
   class vn_module_ordnance_AIR_bomb_1000_mk83_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_1000_mk83_he";
      displayName = "$STR_VN_MK83_LAUNCHER_DN";
      ammo = "vn_bomb_1000_mk83_he_ammo";
   };
   class vn_module_ordnance_AIR_bomb_1000_fab500_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_1000_fab500_he";
      displayName = "$STR_VN_FAB_500_LAUNCHER_DN";
      ammo = "vn_bomb_1000_fab500_he_ammo";
   };
   class vn_module_ordnance_AIR_bomb_2000_mk84_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_2000_mk84_he";
      displayName = "$STR_VN_MK84_LAUNCHER_DN";
      ammo = "vn_bomb_2000_mk84_he_ammo";
   };
   class vn_module_ordnance_AIR_bomb_2000_gbu8_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_2000_gbu8_he";
      displayName = "$STR_VN_GBU8_LAUNCHER_DN";
      ammo = "vn_bomb_2000_gbu8_he_ammo";
   };
   class vn_module_ordnance_AIR_bomb_15000_blu82_dc: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_15000_blu82_dc";
      displayName = "$STR_VN_BLU82_LAUNCHER_DN";
      ammo = "vn_bomb_15000_blu82_dc_ammo";
   };
   class vn_module_ordnance_AIR_bomb_500_mk20_cb: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_500_mk20_cb";
      displayName = "$STR_VN_MK20_LAUNCHER_DN";
      ammo = "vn_bomb_500_mk20_cb_ammo";
   };
   class vn_module_ordnance_AIR_bomb_500_blu1b_fb: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_500_blu1b_fb";
      displayName = "$STR_VN_BLU1_500_LAUNCHER_DN";
      ammo = "vn_bomb_500_blu1b_fb_ammo";
   };
   class vn_module_ordnance_AIR_bomb_100_m47_wp: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_bomb_100_m47_wp";
      displayName = "$STR_VN_M47_WP_LAUNCHER_DN";
      ammo = "vn_bomb_100_m47_wp_ammo";
   };
   class vn_module_ordnance_AIR_missile_aa2: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_missile_aa2";
      displayName = "$STR_VN_AA2_MAG_X1_DN";
      ammo = "vn_missile_aa2_ammo";
   };
   class vn_module_ordnance_AIR_missile_aim7e2: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_missile_aim7e2";
      displayName = "$STR_VN_AIM7E_MAG_X1_DN";
      ammo = "vn_missile_aim7e2_ammo";
   };
   class vn_module_ordnance_AIR_missile_aim9e: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_missile_aim9e";
      displayName = "$STR_VN_AIM9E_MAG_X1_DN";
      ammo = "vn_missile_aim9e_ammo";
   };
   class vn_module_ordnance_AIR_missile_agm45: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_missile_agm45";
      displayName = "$STR_VN_AGM45_MAG_X1_DN";
      ammo = "vn_missile_agm45_ammo";
   };
   class vn_module_ordnance_AIR_missile_at3: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_missile_at3";
      displayName = "$STR_VN_AT3_MAG_X1_DN";
      ammo = "vn_missile_at3_ammo";
   };
   class vn_module_ordnance_AIR_missile_sa7: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_missile_sa7";
      displayName = "$STR_VN_SA7_MAG_DN";
      ammo = "vn_missile_sa7_ammo";
   };
   class vn_module_ordnance_AIR_rocket_ffar_m156_wp: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_rocket_ffar_m156_wp";
      displayName = "$STR_VN_FFAR_WP_MAG_X4_DNS";
      ammo = "vn_rocket_ffar_m156_wp_ammo";
   };
   class vn_module_ordnance_AIR_rocket_ffar_m151_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_rocket_ffar_m151_he";
      displayName = "$STR_VN_FFAR_HE_10_MAG_X4_DNS";
      ammo = "vn_rocket_ffar_m151_he_ammo";
   };
   class vn_module_ordnance_AIR_rocket_ffar_m229_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_rocket_ffar_m229_he";
      displayName = "$STR_VN_FFAR_HE_17_MAG_X4_DNS";
      ammo = "vn_rocket_ffar_m229_he_ammo";
   };
   class vn_module_ordnance_AIR_rocket_ffar_wdu4_flechette: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_rocket_ffar_wdu4_flechette";
      displayName = "$STR_VN_FFAR_FL_MAG_X4_DNS";
      ammo = "vn_rocket_ffar_wdu4_flechette_ammo";
   };
   class vn_module_ordnance_AIR_rocket_s5_heat: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_rocket_s5_heat";
      displayName = "$STR_VN_S5_HE_LAUNCHER_DN";
      ammo = "vn_rocket_s5_heat_ammo";
   };
   class vn_module_ordnance_AIR_rocket_ffar_mk32_atap: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_AIR_rocket_ffar_mk32_atap";
      displayName = "$STR_VN_FFAR_ATAP_MAG_X4_DNS";
      ammo = "vn_rocket_ffar_mk32_atap_ammo";
   };
   class vn_module_ordnance_ARTY_shell_105mm_m546_frag: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_105mm_m546_frag";
      displayName = "$STR_VN_CANNON_M101_MAG_FG_X8_DNS";
      ammo = "vn_shell_105mm_m546_frag_ammo";
   };
   class vn_module_ordnance_ARTY_shell_105mm_m1_ab: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_105mm_m1_ab";
      displayName = "$STR_VN_CANNON_M101_MAG_AB_X8_DNS";
      ammo = "vn_shell_105mm_m1_ab_ammo";
   };
   class vn_module_ordnance_ARTY_shell_81mm_m374_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_81mm_m374_he";
      displayName = "$STR_VN_MORTAR_M29_MAG_HE_X8_DNS";
      ammo = "vn_shell_81mm_m374_he_ammo";
   };
   class vn_module_ordnance_ARTY_shell_60mm_m49a2_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_60mm_m49a2_he";
      displayName = "$STR_VN_MORTAR_M2_MAG_HE_X8_DNS";
      ammo = "vn_shell_60mm_m49a2_he_ammo";
   };
   class vn_module_ordnance_ARTY_shell_105mm_m1_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_105mm_m1_he";
      displayName = "$STR_VN_CANNON_M101_MAG_HE_X8_DNS";
      ammo = "vn_shell_105mm_m1_he_ammo";
   };
   class vn_module_ordnance_ARTY_shell_105mm_m67_heat: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_105mm_m67_heat";
      displayName = "$STR_VN_CANNON_M101_MAG_HEAT_X8_DNS";
      ammo = "vn_shell_105mm_m67_heat_ammo";
   };
   class vn_module_ordnance_ARTY_shell_85mm_d44_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_85mm_d44_he";
      displayName = "$STR_VN_CANNON_D44_MAG_HE_X12_DNS";
      ammo = "vn_shell_85mm_d44_he_ammo";
   };
   class vn_module_ordnance_ARTY_shell_85mm_d44_heat: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_85mm_d44_heat";
      displayName = "$STR_VN_CANNON_D44_MAG_HEAT_X12_DNS";
      ammo = "vn_shell_85mm_d44_heat_ammo";
   };
   class vn_module_ordnance_ARTY_shell_85mm_d44_hvap: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_85mm_d44_hvap";
      displayName = "$STR_VN_CANNON_D44_MAG_HVAP_X12_DNS";
      ammo = "vn_shell_85mm_d44_hvap_ammo";
   };
   class vn_module_ordnance_ARTY_shell_81mm_m375_wp: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_81mm_m375_wp";
      displayName = "$STR_VN_MORTAR_M29_MAG_WP_X8_DNS";
      ammo = "vn_shell_81mm_m375_wp_ammo";
   };
   class vn_module_ordnance_ARTY_shell_60mm_m302_wp: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_60mm_m302_wp";
      displayName = "$STR_VN_MORTAR_M2_MAG_WP_X8_DNS";
      ammo = "vn_shell_60mm_m302_wp_ammo";
   };
   class vn_module_ordnance_ARTY_shell_105mm_m60_wp: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_105mm_m60_wp";
      displayName = "$STR_VN_CANNON_M101_MAG_WP_X8_DNS";
      ammo = "vn_shell_105mm_m60_wp_ammo";
   };
   class vn_module_ordnance_ARTY_shell_105mm_m60_chem: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      _generalMacro = "vn_module_ordnance_ARTY_shell_105mm_m60_chem";
      displayName = "$STR_VN_MORTAR_M29_MAG_CHEM_X8_DNS";
      ammo = "vn_shell_105mm_m60_chem_ammo";
   };
   class vn_module_ordnance_FLARE_flare_plane_lg_w: vn_moduleflarewhite_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      category = "Flares";
      _generalMacro = "vn_module_ordnance_FLARE_flare_plane_lg_w";
      displayName = "$STR_ORDANCE_FLARE_LARGE";
      ammo = "vn_flare_plane_lg_w_ammo";
   };
   class vn_module_ordnance_FLARE_flare_plane_med_w: vn_moduleflarewhite_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      category = "Flares";
      _generalMacro = "vn_module_ordnance_FLARE_flare_plane_med_w";
      displayName = "$STR_ORDANCE_FLARE_MEDIUM";
      ammo = "vn_flare_plane_med_w_ammo";
   };
   class vn_module_ordnance_FLARE_flare_plane_small_w: vn_moduleflarewhite_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      category = "Flares";
      _generalMacro = "vn_module_ordnance_FLARE_flare_plane_small_w";
      displayName = "$STR_ORDANCE_FLARE_SMALL";
      ammo = "vn_flare_plane_small_w_ammo";
   };
   class vn_module_ordnance_salvo_SMOKE_40mm_m680_smoke_w: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 8;
      vn_salvo_timeout = 3.75;
      vn_salvo_radius = 50;
      vn_shake_toggle = -1;
      _generalMacro = "vn_module_ordnance_SMOKE_40mm_m680_smoke_w";
      displayName = "$STR_VN_ORDNACE_SMOKE_W";
      ammo = "vn_40mm_m680_smoke_w_ammo";
   };
   class vn_module_ordnance_salvo_SMOKE_40mm_m682_smoke_r: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 8;
      vn_salvo_timeout = 3.75;
      vn_salvo_radius = 50;
      vn_shake_toggle = -1;
      _generalMacro = "vn_module_ordnance_SMOKE_40mm_m682_smoke_r";
      displayName = "$STR_VN_ORDNACE_SMOKE_R";
      ammo = "vn_40mm_m682_smoke_r_ammo";
   };
   class vn_module_ordnance_salvo_SMOKE_40mm_m715_smoke_g: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 8;
      vn_salvo_timeout = 3.75;
      vn_salvo_radius = 50;
      vn_shake_toggle = -1;
      _generalMacro = "vn_module_ordnance_SMOKE_40mm_m715_smoke_g";
      displayName = "$STR_VN_ORDNACE_SMOKE_G";
      ammo = "vn_40mm_m715_smoke_g_ammo";
   };
   class vn_module_ordnance_salvo_SMOKE_40mm_m716_smoke_y: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 8;
      vn_salvo_timeout = 3.75;
      vn_salvo_radius = 50;
      vn_shake_toggle = -1;
      _generalMacro = "vn_module_ordnance_SMOKE_40mm_m716_smoke_y";
      displayName = "$STR_VN_ORDNACE_SMOKE_Y";
      ammo = "vn_40mm_m716_smoke_y_ammo";
   };
   class vn_module_ordnance_salvo_SMOKE_40mm_m717_smoke_p: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 8;
      vn_salvo_timeout = 3.75;
      vn_salvo_radius = 50;
      vn_shake_toggle = -1;
      _generalMacro = "vn_module_ordnance_SMOKE_40mm_m717_smoke_p";
      displayName = "$STR_VN_ORDNACE_SMOKE_P";
      ammo = "vn_40mm_m717_smoke_p_ammo";
   };
   class vn_module_ordnance_salvo_LUME_TEST_01_flare_plane_lg_w: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 8;
      vn_salvo_timeout = 5;
      vn_salvo_radius = 60;
      vn_shake_toggle = -1;
      _generalMacro = "vn_module_ordnance_LUME_TEST_01_flare_plane_lg_w";
      displayName = "$STR_ORDANCE_FLARE_SALVO_LARGE";
      category = "Flares";
      ammo = "vn_flare_plane_lg_w_ammo";
      portrait = "\a3\Modules_F_Curator\Data\portraitFlareWhite_ca.paa";
   };
   class vn_module_ordnance_salvo_LUME_TEST_02_flare_plane_lg_w: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 999;
      vn_salvo_timeout = 5;
      vn_salvo_radius = 60;
      vn_shake_toggle = -1;
      _generalMacro = "vn_module_ordnance_LUME_TEST_02_flare_plane_lg_w";
      displayName = "$STR_ORDANCE_FLARE_INFINITE_LARGE";
      category = "Flares";
      ammo = "vn_flare_plane_lg_w_ammo";
      portrait = "\a3\Modules_F_Curator\Data\portraitFlareWhite_ca.paa";
   };
   class vn_module_ordnance_salvo_HE_shell_81mm_m374_he: vn_moduleordnancehowitzer_f
   {
      author = "$STR_VN_AUTHORSAVAGE";
      appId = 1227700;
      scope = 1;
      scopeCurator = 2;
      function = "VN_fnc_zeus_ordnance";
      vn_salvo_shells = 8;
      vn_salvo_timeout = 7.5;
      vn_salvo_radius = 50;
      vn_shake_toggle = 0;
      _generalMacro = "vn_module_ordnance_HE_shell_81mm_m374_he";
      displayName = "$STR_VN_MORTAR_M29_MAG_HE_X8_DN";
      ammo = "vn_shell_81mm_m374_he_ammo";
   };
};
