class CfgMagazineWells
{
/////Handgun/////
/////9x19mm//////

	class CBA_9x19_Glock_Full
	{
		RHS_Magazines[] =
		{
			"rhsusf_mag_17Rnd_9x19_JHP",
			"rhsusf_mag_17Rnd_9x19_FMJ"
		};
	};
	class CBA_9x19_M9
	{
		RHS_Magazines[] =
		{
			"rhsusf_mag_15Rnd_9x19_JHP",
			"rhsusf_mag_15Rnd_9x19_FMJ"
		};
	};

/////.45ACP//////

	class CBA_45ACP_1911
	{
		RHS_Magazines[] =
		{
			"rhsusf_mag_7x45acp_MHP"
		};
	};

///////SMG///////
////4.60x30mm////

	class CBA_46x30_MP7			// H&K MP7
	{
		RHS_Magazines[] =
		{
			"rhsusf_mag_40Rnd_46x30_FMJ",
			"rhsusf_mag_40Rnd_46x30_JHP",
			"rhsusf_mag_40Rnd_46x30_AP"
		};
	};

///Rifle & MGs///
////5.56x45mm////

	#define MACRO_20Rnd_556x45_STANAG \
			rhs_mag_20Rnd_556x45_M193_Stanag,\
			rhs_mag_20Rnd_556x45_M196_Stanag_Tracer_Red,\
			rhs_mag_20Rnd_556x45_M200_Stanag,\
			rhs_mag_20Rnd_556x45_M855_Stanag,\
			rhs_mag_20Rnd_556x45_M855A1_Stanag,\
			rhs_mag_20Rnd_556x45_Mk262_Stanag,\
			rhs_mag_20Rnd_556x45_M193_2MAG_Stanag,\
			rhs_mag_20Rnd_556x45_M196_2MAG_Stanag_Tracer_Red

	#define MACRO_30Rnd_556x45_STANAG \
			rhs_mag_30Rnd_556x45_M855_Stanag,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Pull,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Ranger,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Pull_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Ranger_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Green,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Yellow,\
			rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Orange,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_ranger,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow,\
			rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Orange,\
			rhs_mag_30Rnd_556x45_Mk318_Stanag,\
			rhs_mag_30Rnd_556x45_Mk318_Stanag_Pull,\
			rhs_mag_30Rnd_556x45_Mk318_Stanag_Ranger,\
			rhs_mag_30Rnd_556x45_Mk262_Stanag,\
			rhs_mag_30Rnd_556x45_Mk262_Stanag_Pull,\
			rhs_mag_30Rnd_556x45_Mk262_Stanag_Ranger,\
			rhs_mag_30Rnd_556x45_M193_Stanag,\
			rhs_mag_30Rnd_556x45_M196_Stanag_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M200_Stanag,\
			rhs_mag_30Rnd_556x45_M855A1_EPM,\
			rhs_mag_30Rnd_556x45_M855A1_EPM_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855A1_EPM_Pull,\
			rhs_mag_30Rnd_556x45_M855A1_EPM_Pull_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger,\
			rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger_Tracer_Red,\
			rhs_mag_30Rnd_556x45_Mk318_SCAR,\
			rhs_mag_30Rnd_556x45_Mk318_SCAR_Pull,\
			rhs_mag_30Rnd_556x45_Mk318_SCAR_Ranger,\
			rhs_mag_30Rnd_556x45_M855A1_PMAG,\
			rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855_PMAG,\
			rhs_mag_30Rnd_556x45_M855_PMAG_Tracer_Red,\
			rhs_mag_30Rnd_556x45_Mk318_PMAG,\
			rhs_mag_30Rnd_556x45_Mk262_PMAG,\
			rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan,\
			rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Tracer_Red,\
			rhs_mag_30Rnd_556x45_M855_PMAG_Tan,\
			rhs_mag_30Rnd_556x45_M855_PMAG_Tan_Tracer_Red,\
			rhs_mag_30Rnd_556x45_Mk318_PMAG_Tan,\
			rhs_mag_30Rnd_556x45_Mk262_PMAG_Tan

	#define MACRO_556x45_CMAG \
			rhs_mag_100Rnd_556x45_M855A1_cmag,\
			rhs_mag_100Rnd_556x45_M855A1_cmag_mixed,\
			rhs_mag_100Rnd_556x45_M855_cmag,\
			rhs_mag_100Rnd_556x45_M855_cmag_mixed,\
			rhs_mag_100Rnd_556x45_Mk318_cmag,\
			rhs_mag_100Rnd_556x45_Mk262_cmag

	#define MACRO_556x45_M249 \
			rhsusf_200Rnd_556x45_box,\
			rhsusf_200rnd_556x45_mixed_box,\
			rhsusf_200rnd_556x45_M855_box,\
			rhsusf_200rnd_556x45_M855_mixed_box,\
			rhsusf_200Rnd_556x45_soft_pouch,\
			rhsusf_200Rnd_556x45_mixed_soft_pouch,\
			rhsusf_200Rnd_556x45_soft_pouch_ucp,\
			rhsusf_200Rnd_556x45_mixed_soft_pouch_ucp,\
			rhsusf_200Rnd_556x45_soft_pouch_coyote,\
			rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote,\
			rhsusf_200Rnd_556x45_M855_soft_pouch,\
			rhsusf_200Rnd_556x45_M855_mixed_soft_pouch,\
			rhsusf_200Rnd_556x45_M855_soft_pouch_ucp,\
			rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_ucp,\
			rhsusf_200Rnd_556x45_M855_soft_pouch_coyote,\
			rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_coyote,\
			rhsusf_100Rnd_556x45_soft_pouch,\
			rhsusf_100Rnd_556x45_mixed_soft_pouch,\
			rhsusf_100Rnd_556x45_soft_pouch_ucp,\
			rhsusf_100Rnd_556x45_mixed_soft_pouch_ucp,\
			rhsusf_100Rnd_556x45_soft_pouch_coyote,\
			rhsusf_100Rnd_556x45_mixed_soft_pouch_coyote,\
			rhsusf_100Rnd_556x45_M855_soft_pouch,\
			rhsusf_100Rnd_556x45_M855_mixed_soft_pouch,\
			rhsusf_100Rnd_556x45_M855_soft_pouch_ucp,\
			rhsusf_100Rnd_556x45_M855_mixed_soft_pouch_ucp,\
			rhsusf_100Rnd_556x45_M855_soft_pouch_coyote,\
			rhsusf_100Rnd_556x45_M855_mixed_soft_pouch_coyote,\
			rhsusf_100Rnd_556x45_M995_soft_pouch,\
			rhsusf_100Rnd_556x45_M995_soft_pouch_ucp,\
			rhsusf_100Rnd_556x45_M995_soft_pouch_coyote,\
			rhsusf_100Rnd_556x45_M200_soft_pouch,\
			rhsusf_100Rnd_556x45_M200_soft_pouch_ucp,\
			rhsusf_100Rnd_556x45_M200_soft_pouch_coyote

	class STANAG_556x45
	{
		RHS_Magazines[] =
		{
			MACRO_20Rnd_556x45_STANAG,
			MACRO_30Rnd_556x45_STANAG
		};
	};
	class STANAG_556x45_Large			// STANAG mags, C-Mags etc.
	{
		RHS_Magazines[] =
		{
			MACRO_556x45_CMAG
		};
	};
	class CBA_556x45_STANAG				// STANAG mags, standard length, including small drums
	{
		RHS_Magazines[] =
		{
			MACRO_20Rnd_556x45_STANAG,
			MACRO_30Rnd_556x45_STANAG
		};
	};
	class CBA_556x45_STANAG_L {};		// STANAG mags, long stick or coffin (40/60 rounds, Magpul PMAG 40, Surefire MAG5-60)
	class CBA_556x45_STANAG_XL {};		// STANAG mags, extra long stick or coffin (80/100 rounds, Surefire MAG5-100)
	class CBA_556x45_STANAG_2D			// STANAG mags, twin drums (100rnd Beta C-MAG)
	{
		RHS_Magazines[] =
		{
			MACRO_556x45_CMAG
		};
	};
	class CBA_556x45_STANAG_2D_XL {};	// STANAG mags, extra large twin-drums (150rnd Armatac SAW-MAG)
	class M249_556x45
	{
		RHS_Magazines[] =
		{
			MACRO_556x45_M249
		};
	};
	class CBA_556x45_MINIMI
	{
		RHS_Magazines[] =
		{
			MACRO_556x45_M249
		};
	};
	class CBA_556x45_SCAR_EGLM		// Mk13 EGLM trigger-housing prevents some magazines from fitting in SCAR
	{
		RHS_Magazines[] =
		{
			MACRO_30Rnd_556x45_STANAG
		};
	};

////7.62x51mm////

	class CBA_762x51_1rnd {};		// 1 loose round of 7.62x51mm NATO
	class CBA_762x51_2rnds {};		// 2 loose rounds of 7.62x51mm NATO
	class CBA_762x51_3rnds {};		// 3 loose rounds of 7.62x51mm NATO
	class CBA_762x51_4rnds {};		// 4 loose rounds of 7.62x51mm NATO
	class CBA_762x51_5rnds			// 5 loose rounds of 7.62x51mm NATO
	{
		RHS_Magazines[] =
		{
			rhsusf_5Rnd_762x51_m118_special_Mag,
			rhsusf_5Rnd_762x51_m993_Mag,
			rhsusf_5Rnd_762x51_m62_Mag
		};
	};
	class CBA_762x51_AICS			// AICS short action mag (5/10 rounds)
	{
		RHS_Magazines[] =
		{
			rhsusf_5Rnd_762x51_AICS_m118_special_Mag,
			rhsusf_5Rnd_762x51_AICS_m993_Mag,
			rhsusf_5Rnd_762x51_AICS_m62_Mag,
			rhsusf_10Rnd_762x51_m118_special_Mag,
			rhsusf_10Rnd_762x51_m993_Mag,
			rhsusf_10Rnd_762x51_m62_Mag
		};
	};

	class CBA_762x51_AR10				// AR-10 standard mag (20 rounds)
	{
		RHS_Magazines[] =
		{
			rhsusf_20Rnd_762x51_SR25_m118_special_Mag,
			rhsusf_20Rnd_762x51_SR25_mk316_special_Mag,
			rhsusf_20Rnd_762x51_SR25_m993_Mag,
			rhsusf_20Rnd_762x51_SR25_m62_Mag
		};
	};
	class CBA_762x51_AR10_L {};			// AR-10 long mag (25/30 rounds)
	class CBA_762x51_AR10_XL {};		// AR-10 drum mag (X-Products 50 round)

	#define MACRO_20Rnd_762x51_M14 \
			rhsusf_20Rnd_762x51_m118_special_Mag,\
			rhsusf_20Rnd_762x51_m993_Mag,\
			rhsusf_20Rnd_762x51_m80_Mag,\
			rhsusf_20Rnd_762x51_m62_Mag

	class M14_762x51
	{
		RHS_Magazines[] =
		{
			MACRO_20Rnd_762x51_M14
		};
	};
	class CBA_762x51_M14			// M14
	{
		RHS_Magazines[] =
		{
			MACRO_20Rnd_762x51_M14
		};
	};		// M14
	class CBA_762x51_M14_L {};		// M14 long mag (25/30 rounds)
	class CBA_762x51_M14_XL {};		// M14 drum mag (X-Products 50 round)
	class CBA_762x51_SCAR
	{
		RHS_Magazines[] =
		{
			"rhs_mag_20Rnd_SCAR_762x51_m61_ap",
			"rhs_mag_20Rnd_SCAR_762x51_m62_tracer",
			"rhs_mag_20Rnd_SCAR_762x51_m80_ball",
			"rhs_mag_20Rnd_SCAR_762x51_m80a1_epr",
			"rhs_mag_20Rnd_SCAR_762x51_m118_special",
			"rhs_mag_20Rnd_SCAR_762x51_mk316_special"
		};
	};
	class CBA_762x51_SCAR_EGLM		// Mk13 EGLM trigger-housing prevents some magazines from fitting in SCAR
	{
		RHS_Magazines[] =
		{
			"rhs_mag_20Rnd_SCAR_762x51_m61_ap",
			"rhs_mag_20Rnd_SCAR_762x51_m62_tracer",
			"rhs_mag_20Rnd_SCAR_762x51_m80_ball",
			"rhs_mag_20Rnd_SCAR_762x51_m80a1_epr",
			"rhs_mag_20Rnd_SCAR_762x51_m118_special",
			"rhs_mag_20Rnd_SCAR_762x51_mk316_special"
		};
	};

	class M240_762x51
	{
		RHS_Magazines[] =
		{
			"rhsusf_50Rnd_762x51", // M80
			"rhsusf_50Rnd_762x51_m61_ap",
			"rhsusf_50Rnd_762x51_m62_tracer",
			"rhsusf_50Rnd_762x51_m80a1epr",
			"rhsusf_50Rnd_762x51_m82_blank",

			"rhsusf_100Rnd_762x51", // M80
			"rhsusf_100Rnd_762x51_m61_ap",
			"rhsusf_100Rnd_762x51_m62_tracer",
			"rhsusf_100Rnd_762x51_m80a1epr",
			"rhsusf_100Rnd_762x51_m82_blank"
		};
	};
	class CBA_762x51_LINKS {};		// M13 Links for M60, M240, MG3 (DM6/DM60)

/////.300 WM/////

	class CBA_300WM_AICS			// AICS long action mag (5 rounds)
	{
		RHS_Magazines[] =
		{
			"rhsusf_5Rnd_300winmag_xm2010"
		};
	};

////12.7x99mm////

	class CBA_50BMG_M107			// M82, M107, G82
	{
		RHS_Magazines[] =
		{
			"rhsusf_mag_10Rnd_STD_50BMG_M33",
			"rhsusf_mag_10Rnd_STD_50BMG_mk211"
		};	
	};		

/////Shotgun/////
////12 Gauge/////

	class CBA_12g_1rnd {};		// 1 loose round
	class CBA_12g_2rnds {};		// 2 loose rounds
	class CBA_12g_3rnds {};		// 3 loose rounds
	class CBA_12g_4rnds {};		// 4 loose rounds
	class CBA_12g_5rnds		// 5 loose rounds
	{
		RHS_Magazines[] =
		{
			rhsusf_5Rnd_00Buck,
			rhsusf_5Rnd_Slug,
			rhsusf_5Rnd_HE,
			rhsusf_5Rnd_FRAG,
			rhsusf_5rnd_doomsday_buck
		};
	};
	class CBA_12g_6rnds {};		// 6 loose rounds
	class CBA_12g_7rnds {};		// 7 loose rounds
	class CBA_12g_8rnds		// 8 loose rounds
	{
		RHS_Magazines[] =
		{
			rhsusf_8Rnd_00Buck,
			rhsusf_8Rnd_Slug,
			rhsusf_8Rnd_HE,
			rhsusf_8Rnd_FRAG,
			rhsusf_8rnd_doomsday_buck
		};
	};
	class CBA_12g_9rnds {};		// 9 loose rounds

///Explosives///
///40x46mm LV///

	#define MACRO_40mm_Short \
			rhs_mag_M441_HE,\
			rhs_mag_M433_HEDP,\
			rhs_mag_M397_HET,\
			rhs_mag_m576,\
			rhs_mag_M4009,\
			rhs_mag_M583A1_white,\
			rhs_mag_M585_white,\
			rhs_mag_M661_green,\
			rhs_mag_M662_red,\
			rhs_mag_M585_white_cluster,\
			rhs_mag_M663_green_cluster,\
			rhs_mag_M664_red_cluster,\
			rhs_mag_M713_red,\
			rhs_mag_M714_white,\
			rhs_mag_M715_green,\
			rhs_mag_M716_yellow,\
			rhs_mag_M781_Practice

	class UGL_40x36
	{
		RHS_Magazines[] =
		{
			MACRO_40mm_Short
		};
	};
	class CBA_40mm_M203			// max cartridge length 5.5", limited by M203's sliding breech
	{
		RHS_Magazines[] =
		{
			MACRO_40mm_Short
		};
	};
	class CBA_40mm_EGLM {};			// grenades >5.5" that can only fit side breech-loading (M320, Mk13, M79 etc)
	class 3UGL_40x36 {};
	class CBA_40mm_3GL {};
	class CBA_40mm_M203_6rnds		// 6 loose M203 type grenades for M32 MGL
	{
		RHS_Magazines[] =
		{
		// Offensive
			"rhsusf_mag_6Rnd_M441_HE",
			"rhsusf_mag_6Rnd_M433_HEDP",
			"rhsusf_mag_6Rnd_M397_HET",
			"rhsusf_mag_6Rnd_M576_Buckshot",
			"rhsusf_mag_6Rnd_m4009", // Stun

		// Flare
			"rhsusf_mag_6Rnd_M585_white",
			"rhsusf_mag_6Rnd_M583A1_white",
			"rhsusf_mag_6Rnd_m661_green",
			"rhsusf_mag_6Rnd_m662_red",

		// Smoke
			"rhsusf_mag_6Rnd_M713_red",
			"rhsusf_mag_6Rnd_M714_white",
			"rhsusf_mag_6Rnd_M715_green",
			"rhsusf_mag_6Rnd_M716_yellow",
		// Prac
			"rhsusf_mag_6Rnd_M781_Practice"
		};
	};

////84mm RR/////

	class CBA_Carl_Gustaf			// MAAWS, RAWS
	{
		RHS_Magazines[] =
		{
			"rhs_mag_maaws_HEAT",
			"rhs_mag_maaws_HEDP",
			"rhs_mag_maaws_HE"
			//"rhs_mag_maaws_SMOKE",
			//"rhs_mag_maaws_ILLUM"
		};
	};

//////SMAW//////

	class CBA_SMAW					// Mk 153 SMAW
		{
		RHS_Magazines[] =
		{
			"rhs_mag_smaw_HEAA",
			"rhs_mag_smaw_HEDP"
		};
	};
	class CBA_SMAW_Spotting_Rifle	// Mk 153 SMAW - Spotting Rifle
	{
		RHS_Magazines[] =
		{
			"rhs_mag_smaw_SR"
		};
	};
};