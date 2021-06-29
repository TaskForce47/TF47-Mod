class CfgWeapons
{
    class rhs_weap_maaws;
    
    class tf47_rhs_weap_maaws: rhs_weap_maaws
    {
        displayName = "M3 MAAWS";
        magazines[] = { 
                        "tf47_mag_maaws_ffv401_adm",
                        "tf47_mag_maaws_ffv441d_he",
                        "tf47_mag_maaws_ffv469c_smoke",
                        "tf47_mag_maaws_ffv502_hedp",
                        "tf47_mag_maaws_ffv509_asm",
                        "tf47_mag_maaws_ffv545c_illum",
                        "tf47_mag_maaws_ffv551_heat",
                        "tf47_mag_maaws_ffv551c_heat",
                        "tf47_mag_maaws_ffv655_heat_cs",
                        "tf47_mag_maaws_ffv751_heat",
                        "tf47_mag_maaws_ffv756_mt",
                        "tf47_mag_maaws_gmm"
                      };
        magazineWell[] = {CBA_Carl_Gustaf};
    }
    
    class tf47_rhs_weap_raws: rhs_weap_maaws
    {
        displayName = "M3E1 RAWS";
        magazines[] = { 
                        "tf47_mag_raws_ffv401_adm",
                        "tf47_mag_raws_ffv441d_he",
                        "tf47_mag_raws_ffv469c_smoke",
                        "tf47_mag_raws_ffv502_hedp",
                        "tf47_mag_raws_ffv509_asm",
                        "tf47_mag_raws_ffv545c_illum",
                        "tf47_mag_raws_ffv551_heat",
                        "tf47_mag_raws_ffv551c_heat",
                        "tf47_mag_raws_ffv655_heat_cs",
                        "tf47_mag_raws_ffv751_heat",
                        "tf47_mag_raws_ffv756_mt",
                        "tf47_mag_raws_gmm"
                      };
        magazineWell[] = {CBA_Carl_Gustaf};
    }
};