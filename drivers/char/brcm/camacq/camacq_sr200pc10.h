  /*
 *
 * sensor set table for camera
 *
. COPYRIGHT (C)  SAMSUNG Electronics CO., LTD (Suwon, Korea). 2010   
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#if !defined(_CAMACQ_SR200PC10_H_)
#define _CAMACQ_SR200PC10_H_

/* Include */
#include "camacq_api.h"

/* Global */
#undef GLOBAL

#if !defined(_CAMACQ_API_C_)
#define GLOBAL extern
#else
#define GLOBAL
#endif /* _CAMACQ_API_C_ */

/* Include */
#if defined(WIN32)
#include "cmmfile.h"
#endif /* WIN32 */

/* Definition */
#define _SR200PC10_EVT0_    //sensor option

#define CAMACQ_MAIN_NAME         "cami2c_main"               // wingi
#define CAMACQ_MAIN_I2C_ID       0x2D	                // don't use now.
#define CAMACQ_MAIN_RES_TYPE   	 CAMACQ_SENSOR_MAIN   // main sensor

#define CAMACQ_MAIN_ISPROBED     0
#define CAMACQ_MAIN_CLOCK        0               
#define CAMACQ_MAIN_YUVORDER     0
#define CAMACQ_MAIN_V_SYNCPOL    0
#define CAMACQ_MAIN_H_SYNCPOL    0
#define CAMACQ_MAIN_SAMPLE_EDGE  0
#define CAMACQ_MAIN_FULL_RANGE   0

#define CAMACQ_MAIN_RST 
#define CAMACQ_MAIN_RST_MUX 
#define CAMACQ_MAIN_EN 
#define CAMACQ_MAIN_EN_MUX 

#define CAMACQ_MAIN_RST_ON          1
#define CAMACQ_MAIN_RST_OFF         0
#define CAMACQ_MAIN_EN_ON           1
#define CAMACQ_MAIN_EN_OFF          0
#define CAMACQ_MAIN_STANDBY_ON      1
#define CAMACQ_MAIN_STANDBY_OFF	    0

#define CAMACQ_MAIN_POWER_CTRL(onoff)
 
#define CAMACQ_MAIN_2BYTE_SENSOR    1
#define CAMACQ_MAIN_AF              0
#define CAMACQ_MAIN_INT_MODE        0   // 0xAABBCCDD is INT_MODE, 0xAA, 0xBB, 0xCC, 0xDD is ARRAY MODE
#define CAMACQ_MAIN_FS_MODE         0
#define CAMACQ_MAIN_PATH_SET_FILE   "/mnt/sdcard/sensor/%s.dat"

#if (CAMACQ_MAIN_2BYTE_SENSOR)	
#define CAMACQ_MAIN_BURST_MODE 0
#define CAMACQ_MAIN_I2C_NUM_OF_BYTE 2//add for burst
#else
#define CAMACQ_MAIN_BURST_MODE 0
#define CAMACQ_MAIN_I2C_NUM_OF_BYTE 4//add for burst
#endif /* CAMACQ_MAIN2BYTE_SENSOR */

#define CAMACQ_MAIN_BURST_I2C_TRACE 0
#define CAMACQ_MAIN_BURST_MAX 100
#define CAMACQ_MAIN_REG_FLAG_BURST 	0x0E//add for burst

#define CAMACQ_MAIN_REG_FLAG_CNTS 	0x0F12
#define CAMACQ_MAIN_REG_DELAY 		0xFE                
#define CAMACQ_MAIN_BTM_OF_DATA 	{0xFF, 0xFF},       
#define CAMACQ_MAIN_END_MARKER 		0xFF                
#define CAMACQ_MAIN_REG_SET_SZ 		2 	// {0xFFFFFFFF} is 1, {0xFFFF,0xFFFF} is 2, {0xFF,0XFF} is 2, {0xFF,0xFF,0xFF,0xFF} is 4, {0xFFFF} is 1 
#define CAMACQ_MAIN_REG_DAT_SZ 		1   // {0xFFFFFFFF} is 4, {0xFFFF,0xFFFF} is 2, {0xFF,0XFF} is 1, {0xFF,0xFF,0xFF,0xFF} is 1, {0xFFFF} is 2 
#define CAMACQ_MAIN_FRATE_MIN  5
#define CAMACQ_MAIN_FRATE_MAX  30

// MACRO FUNCTIONS BEGIN //////////////////////////////////////////////////////////// 
#if (CAMACQ_MAIN_2BYTE_SENSOR)
#define CAMACQ_MAIN_EXT_RD_SZ 1
#else
#define CAMACQ_MAIN_EXT_RD_SZ 2
#endif /* CAMACQ_MAIN_2BYTE_SENSOR */

#if CAMACQ_MAIN_2BYTE_SENSOR
#define CAMACQ_MAIN_EXT_REG_IS_BTM_OF_DATA(A)		(((A[0]==CAMACQ_MAIN_END_MARKER) && (A[1]==CAMACQ_MAIN_END_MARKER))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_DELAY(A)				((A[0]==CAMACQ_MAIN_REG_DELAY)? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_BURST(A)				(((A[0]==CAMACQ_MAIN_REG_FLAG_BURST) && (A[1]==0x01))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_BURST_END(A)				(((A[0]==CAMACQ_MAIN_REG_FLAG_BURST) && (A[1]==0x00))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_CNTS(A)				(((A[0]==CAMACQ_MAIN_REG_FLAG_BURST) && (A[1]==0x01))? 1:0)
//add for burst

#if (CAMACQ_MAIN_FS_MODE==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)\
memcpy(dest, &(srce[idx*CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ]), CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ);
#elif (CAMACQ_MAIN_REG_DAT_SZ==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = (srce[idx][0] & 0xFF); dest[1] = (srce[idx][1] & 0xFF);
#elif (CAMACQ_MAIN_REG_DAT_SZ==2)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = ((U8)(srce[idx] >> 8) & 0xFF); dest[1] = ((U8)(srce[idx]) & 0xFF);
#endif

#else // CAMACQ_MAIN_2BYTE_SENSOR

#define CAMACQ_MAIN_EXT_REG_IS_BTM_OF_DATA(A)		(((A[0]==CAMACQ_MAIN_END_MARKER) && (A[1]==CAMACQ_MAIN_END_MARKER) && \
(A[2]==CAMACQ_MAIN_END_MARKER) && (A[3]==CAMACQ_MAIN_END_MARKER))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_DELAY(A)				(((A[0]==((CAMACQ_MAIN_REG_DELAY>>8) & 0xFF)) && (A[1]==(CAMACQ_MAIN_REG_DELAY & 0xFF)))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_CNTS(A)				(((A[0]==((CAMACQ_MAIN_REG_FLAG_CNTS>>8) & 0xFF)) && (A[1]==(CAMACQ_MAIN_REG_FLAG_CNTS & 0xFF)))? 1:0)

#if (CAMACQ_MAIN_FS_MODE==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)\
memcpy(dest, &(srce[idx*CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ]), CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ);
#elif (CAMACQ_MAIN_REG_DAT_SZ==2)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0]=((srce[idx][0] >> 8) & 0xFF); dest[1]=(srce[idx][0] & 0xFF); \
dest[2]=((srce[idx][1] >> 8) & 0xFF); dest[3]=(srce[idx][1] & 0xFF);
#elif (CAMACQ_MAIN_REG_DAT_SZ==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0]=srce[idx][0]; dest[1]=srce[idx][1]; \
dest[2]=srce[idx][2]; dest[3]=srce[idx][3];
#elif (CAMACQ_MAIN_REG_DAT_SZ==4)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = ((U8)(srce[idx] >> 24) & 0xFF); dest[1] = ((U8)(srce[idx] >> 16) & 0xFF); \
dest[2] = ((U8)(srce[idx] >> 8) & 0xFF); dest[3] = ((U8)(srce[idx]) & 0xFF);			
#endif
#endif /* CAMACQ_2BYTE_SENSOR */
// MACRO FUNCTIONS END /////////////////////////////////////////////////////////// 


/* DEFINE for sensor regs*/
#if( CAMACQ_MAIN_FS_MODE )
#define CAMACQ_MAIN_REG_INIT            "INIT"
#define CAMACQ_MAIN_REG_PREVIEW         "PREVIEW"
#define CAMACQ_MAIN_REG_SNAPSHOT        "SNAPSHOT"
#define CAMACQ_MAIN_REG_CAMCORDER        "CAMCORDER"

#define CAMACQ_MAIN_REG_WB_AUTO                 "WB_AUTO"
#define CAMACQ_MAIN_REG_WB_DAYLIGHT             "WB_DAYLIGHT"
#define CAMACQ_MAIN_REG_WB_CLOUDY               "WB_CLOUDY"
#define CAMACQ_MAIN_REG_WB_INCANDESCENT         "WB_INCANDESCENT"
#define CAMACQ_MAIN_REG_WB_FLUORESCENT         "WB_FLUORESCENT"

#define CAMACQ_MAIN_REG_SCENE_AUTO              "SCENE_AUTO" 
#define CAMACQ_MAIN_REG_SCENE_NIGHT             "SCENE_NIGHT"
#define CAMACQ_MAIN_REG_SCENE_NIGHT_DARK        "SCENE_NIGHT_DARK"
#define CAMACQ_MAIN_REG_SCENE_LANDSCAPE         "SCENE_LANDSCAPE"
#define CAMACQ_MAIN_REG_SCENE_PORTRAIT          "SCENE_PORTRAIT"
#define CAMACQ_MAIN_REG_SCENE_SPORTS            "SCENE_SPORTS"
#define CAMACQ_MAIN_REG_SCENE_INDOOR            "SCENE_INDOOR"
#define CAMACQ_MAIN_REG_SCENE_SUNSET            "SCENE_SUNSET"
#define CAMACQ_MAIN_REG_SCENE_SUNRISE           "SCENE_SUNRISE"    // dawn
#define CAMACQ_MAIN_REG_SCENE_BEACH             "SCENE_BEACH"
#define CAMACQ_MAIN_REG_SCENE_FALLCOLOR         "SCENE_FALLCOLOR"
#define CAMACQ_MAIN_REG_SCENE_FIREWORKS         "SCENE_FIREWORKS"
#define CAMACQ_MAIN_REG_SCENE_CANDLELIGHT       "SCENE_CANDLELIGHT"
#define CAMACQ_MAIN_REG_SCENE_AGAINSTLIGHT      "SCENE_AGAINSTLIGHT"  // backlight

#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_0      "BRIGHTNESS_LEVEL_0"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_1      "BRIGHTNESS_LEVEL_1"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_2      "BRIGHTNESS_LEVEL_2"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_3      "BRIGHTNESS_LEVEL_3"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_4      "BRIGHTNESS_LEVEL_4"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_5      "BRIGHTNESS_LEVEL_5"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_6      "BRIGHTNESS_LEVEL_6"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_7      "BRIGHTNESS_LEVEL_7"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_8      "BRIGHTNESS_LEVEL_8"

#define CAMACQ_MAIN_REG_METER_MATRIX            "METER_MATRIX"
#define CAMACQ_MAIN_REG_METER_CW                "METER_CW"
#define CAMACQ_MAIN_REG_METER_SPOT              "METER_SPOT"

#define CAMACQ_MAIN_REG_EFFECT_NONE             "EFFECT_NONE"
#define CAMACQ_MAIN_REG_EFFECT_GRAY             "EFFECT_GRAY" // mono, blackwhite
#define CAMACQ_MAIN_REG_EFFECT_NEGATIVE         "EFFECT_NEGATIVE"
#define CAMACQ_MAIN_REG_EFFECT_SEPIA            "EFFECT_SEPIA"

#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M2              "CONTRAST_M2"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M1              "CONTRAST_M1"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_DEFAULT         "CONTRAST_DEFAULT"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P1              "CONTRAST_P1"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P2              "CONTRAST_P2"

#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M2             "SHARPNESS_M2"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M1             "SHARPNESS_M1"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_DEFAULT        "SHARPNESS_DEFAULT"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P1             "SHARPNESS_P1"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P2             "SHARPNESS_P2"

#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M2            "SATURATION_M2"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M1            "SATURATION_M1"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_DEFAULT       "SATURATION_DEFAULT"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P1            "SATURATION_P1"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P2            "SATURATION_P2"

#else
#define CAMACQ_MAIN_REG_INIT            reg_main_init
#define CAMACQ_MAIN_REG_PREVIEW         reg_main_preview
#define CAMACQ_MAIN_REG_SNAPSHOT        reg_main_snapshot
#define CAMACQ_MAIN_REG_CAMCORDER      reg_main_camcorder

#define CAMACQ_MAIN_REG_WB_AUTO                 reg_main_wb_auto
#define CAMACQ_MAIN_REG_WB_DAYLIGHT             reg_main_wb_daylight
#define CAMACQ_MAIN_REG_WB_CLOUDY               reg_main_wb_cloudy
#define CAMACQ_MAIN_REG_WB_INCANDESCENT         reg_main_wb_incandescent
#define CAMACQ_MAIN_REG_WB_FLUORESCENT          reg_main_wb_fluorescent


#define CAMACQ_MAIN_REG_SCENE_AUTO              reg_main_scene_auto  // auto, off
#define CAMACQ_MAIN_REG_SCENE_NIGHT             reg_main_scene_night
#define CAMACQ_MAIN_REG_SCENE_NIGHT_DARK        reg_main_scene_night_dark
#define CAMACQ_MAIN_REG_SCENE_LANDSCAPE         reg_main_scene_landscape
#define CAMACQ_MAIN_REG_SCENE_PORTRAIT          reg_main_scene_portrait
#define CAMACQ_MAIN_REG_SCENE_SPORTS            reg_main_scene_sports
#define CAMACQ_MAIN_REG_SCENE_INDOOR            reg_main_scene_indoor
#define CAMACQ_MAIN_REG_SCENE_SUNSET            reg_main_scene_sunset
#define CAMACQ_MAIN_REG_SCENE_SUNRISE           reg_main_scene_sunrise    // dawn
#define CAMACQ_MAIN_REG_SCENE_BEACH             reg_main_scene_beach
#define CAMACQ_MAIN_REG_SCENE_FALLCOLOR         reg_main_scene_fallcolor
#define CAMACQ_MAIN_REG_SCENE_FIREWORKS         reg_main_scene_fireworks
#define CAMACQ_MAIN_REG_SCENE_CANDLELIGHT       reg_main_scene_candlelight
#define CAMACQ_MAIN_REG_SCENE_AGAINSTLIGHT      reg_main_scene_againstlight  // backlight

#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_0      reg_main_brightness_level_0
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_1      reg_main_brightness_level_1
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_2      reg_main_brightness_level_2
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_3      reg_main_brightness_level_3
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_4      reg_main_brightness_level_4
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_5      reg_main_brightness_level_5
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_6      reg_main_brightness_level_6
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_7      reg_main_brightness_level_7
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_8      reg_main_brightness_level_8

#define CAMACQ_MAIN_REG_METER_MATRIX            reg_main_meter_matrix
#define CAMACQ_MAIN_REG_METER_CW                reg_main_meter_cw
#define CAMACQ_MAIN_REG_METER_SPOT              reg_main_meter_spot

#define CAMACQ_MAIN_REG_EFFECT_NONE             reg_main_effect_none
#define CAMACQ_MAIN_REG_EFFECT_GRAY             reg_main_effect_gray // mono, blackwhite
#define CAMACQ_MAIN_REG_EFFECT_NEGATIVE         reg_main_effect_negative
#define CAMACQ_MAIN_REG_EFFECT_SEPIA            reg_main_effect_sepia

#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M2              reg_main_adjust_contrast_m2
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M1              reg_main_adjust_contrast_m1
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_DEFAULT         reg_main_adjust_contrast_default
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P1              reg_main_adjust_contrast_p1
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P2              reg_main_adjust_contrast_p2

#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M2             reg_main_adjust_sharpness_m2
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M1             reg_main_adjust_sharpness_m1
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_DEFAULT        reg_main_adjust_sharpness_default
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P1             reg_main_adjust_sharpness_p1
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P2             reg_main_adjust_sharpness_p2

#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M2            reg_main_adjust_saturation_m2
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M1            reg_main_adjust_saturation_m1
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_DEFAULT       reg_main_adjust_saturation_default
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P1            reg_main_adjust_saturation_p1
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P2            reg_main_adjust_saturation_p2
#endif


#define CAMACQ_MAIN_REG_MIDLIGHT                reg_main_midlight
#define CAMACQ_MAIN_REG_LOWLIGHT                reg_main_lowlight
#define CAMACQ_MAIN_REG_NIGHTSHOT_ON            reg_main_nightshot_on
#define CAMACQ_MAIN_REG_NIGHTSHOT_OFF           reg_main_nightshot_off
#define CAMACQ_MAIN_REG_NIGHTSHOT               reg_main_nightshot

#define CAMACQ_MAIN_REG_WB_TWILIGHT             reg_main_wb_twilight
#define CAMACQ_MAIN_REG_WB_TUNGSTEN             reg_main_wb_tungsten
#define CAMACQ_MAIN_REG_WB_OFF                  reg_main_wb_off
#define CAMACQ_MAIN_REG_WB_HORIZON              reg_main_wb_horizon
#define CAMACQ_MAIN_REG_WB_SHADE                reg_main_wb_shade

#define CAMACQ_MAIN_REG_EFFECT_SOLARIZE         reg_main_effect_solarize
#define CAMACQ_MAIN_REG_EFFECT_POSTERIZE        reg_main_effect_posterize
#define CAMACQ_MAIN_REG_EFFECT_WHITEBOARD       reg_main_effect_whiteboard
#define CAMACQ_MAIN_REG_EFFECT_BLACKBOARD       reg_main_effect_blackboard
#define CAMACQ_MAIN_REG_EFFECT_AQUA             reg_main_effect_aqua
#define CAMACQ_MAIN_REG_EFFECT_SHARPEN          reg_main_effect_sharpen
#define CAMACQ_MAIN_REG_EFFECT_VIVID            reg_main_effect_vivid
#define CAMACQ_MAIN_REG_EFFECT_GREEN            reg_main_effect_green
#define CAMACQ_MAIN_REG_EFFECT_SKETCH           reg_main_effect_sketch


#define CAMACQ_MAIN_REG_FLIP_NONE               reg_main_flip_none
#define CAMACQ_MAIN_REG_FLIP_WATER              reg_main_flip_water
#define CAMACQ_MAIN_REG_FLIP_MIRROR             reg_main_flip_mirror
#define CAMACQ_MAIN_REG_FLIP_WATER_MIRROR       reg_main_flip_water_mirror


#define CAMACQ_MAIN_REG_FPS_FIXED_5             reg_main_fps_fixed_5
#define CAMACQ_MAIN_REG_FPS_FIXED_7             reg_main_fps_fixed_7
#define CAMACQ_MAIN_REG_FPS_FIXED_10            reg_main_fps_fixed_10
#define CAMACQ_MAIN_REG_FPS_FIXED_15            reg_main_fps_fixed_15
#define CAMACQ_MAIN_REG_FPS_FIXED_20            reg_main_fps_fixed_20
#define CAMACQ_MAIN_REG_FPS_FIXED_25            reg_main_fps_fixed_25
#define CAMACQ_MAIN_REG_FPS_VAR_15              reg_main_fps_var_15
#define CAMACQ_MAIN_REG_FPS_FIXED_30            reg_main_fps_fixed_30


#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_0 reg_main_expcompensation_level_0
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_1 reg_main_expcompensation_level_1
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_2 reg_main_expcompensation_level_2
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_3 reg_main_expcompensation_level_3
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_4 reg_main_expcompensation_level_4
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_5 reg_main_expcompensation_level_5
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_6 reg_main_expcompensation_level_6
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_7 reg_main_expcompensation_level_7
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_8 reg_main_expcompensation_level_8

#define CAMACQ_MAIN_REG_SET_AF                  reg_main_set_af  // start af
#define CAMACQ_MAIN_REG_OFF_AF                  reg_main_off_af
#define CAMACQ_MAIN_REG_CHECK_AF                reg_main_check_af
#define CAMACQ_MAIN_REG_RESET_AF                reg_main_reset_af
#define CAMACQ_MAIN_REG_MANUAL_AF               reg_main_manual_af    // normal_af
#define CAMACQ_MAIN_REG_MACRO_AF                reg_main_macro_af
#define CAMACQ_MAIN_REG_RETURN_MANUAL_AF        reg_main_return_manual_af
#define CAMACQ_MAIN_REG_RETURN_MACRO_AF         reg_main_return_macro_af
#define CAMACQ_MAIN_REG_SET_AF_NLUX             reg_main_set_af_nlux
#define CAMACQ_MAIN_REG_SET_AF_LLUX             reg_main_set_af_llux
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_1    reg_main_set_af_normal_mode_1
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_2    reg_main_set_af_normal_mode_2
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_3    reg_main_set_af_normal_mode_3
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_1     reg_main_set_af_macro_mode_1
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_2     reg_main_set_af_macro_mode_2
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_3     reg_main_set_af_macro_mode_3

#define CAMACQ_MAIN_REG_ISO_AUTO                reg_main_iso_auto
#define CAMACQ_MAIN_REG_ISO_50                  reg_main_iso_50
#define CAMACQ_MAIN_REG_ISO_100                 reg_main_iso_100
#define CAMACQ_MAIN_REG_ISO_200                 reg_main_iso_200
#define CAMACQ_MAIN_REG_ISO_400                 reg_main_iso_400
#define CAMACQ_MAIN_REG_ISO_800                 reg_main_iso_800
#define CAMACQ_MAIN_REG_ISO_1600                reg_main_iso_1600
#define CAMACQ_MAIN_REG_ISO_3200                reg_main_iso_3200


#define CAMACQ_MAIN_REG_SCENE_PARTY             reg_main_scene_party
#define CAMACQ_MAIN_REG_SCENE_SNOW              reg_main_scene_snow
#define CAMACQ_MAIN_REG_SCENE_TEXT              reg_main_scene_text

#define CAMACQ_MAIN_REG_QQVGA                   reg_main_qqvga
#define CAMACQ_MAIN_REG_QCIF                    reg_main_qcif
#define CAMACQ_MAIN_REG_QVGA                    reg_main_qvga
#define CAMACQ_MAIN_REG_WQVGA                    reg_main_wqvga
#define CAMACQ_MAIN_REG_CIF                     reg_main_cif
#define CAMACQ_MAIN_REG_VGA                     reg_main_vga
#define CAMACQ_MAIN_REG_WVGA                     reg_main_wvga // 800* 480
#define CAMACQ_MAIN_REG_SVGA                    reg_main_svga
#define CAMACQ_MAIN_REG_SXGA                    reg_main_sxga
#define CAMACQ_MAIN_REG_QXGA                    reg_main_qxga
#define CAMACQ_MAIN_REG_UXGA                    reg_main_uxga
#define CAMACQ_MAIN_REG_FULL_YUV                reg_main_full_yuv
#define CAMACQ_MAIN_REG_CROP_YUV                reg_main_crop_yuv
#define CAMACQ_MAIN_REG_QVGA_V		            reg_main_qvga_v
#define CAMACQ_MAIN_REG_HALF_VGA_V	            reg_main_half_vga_v
#define CAMACQ_MAIN_REG_HALF_VGA		        reg_main_half_vga	
#define CAMACQ_MAIN_REG_VGA_V		            reg_main_vga_v			
#define CAMACQ_MAIN_REG_5M			            reg_main_5M
#define CAMACQ_MAIN_REG_1080P		            reg_main_1080P
#define CAMACQ_MAIN_REG_720P			        reg_main_720P
#define CAMACQ_MAIN_REG_NOT                     reg_main_not

#define CAMACQ_MAIN_REG_JPEG_5M                 reg_main_jpeg_5m        //2560X1920
#define CAMACQ_MAIN_REG_JPEG_5M_2               reg_main_jpeg_5m_2      // 2592X1944
#define CAMACQ_MAIN_REG_JPEG_W4M                 reg_main_jpeg_w4m      // 2560x1536
#define CAMACQ_MAIN_REG_JPEG_3M                 reg_main_jpeg_3m        // QXGA 2048X1536
#define CAMACQ_MAIN_REG_JPEG_2M                 reg_main_jpeg_2m        // UXGA 1600x1200
#define CAMACQ_MAIN_REG_JPEG_W1_5M               reg_main_jpeg_w1_5m    // 1280x960
#define CAMACQ_MAIN_REG_JPEG_1M                 reg_main_jpeg_1m
#define CAMACQ_MAIN_REG_JPEG_VGA                reg_main_jpeg_vga   //640x480
#define CAMACQ_MAIN_REG_JPEG_WQVGA              reg_main_jpeg_wqvga //420x240
#define CAMACQ_MAIN_REG_JPEG_QVGA               reg_main_jpeg_qvga  //320x240

#define CAMACQ_MAIN_REG_FLICKER_DISABLED        reg_main_flicker_disabled
#define CAMACQ_MAIN_REG_FLICKER_50HZ            reg_main_flicker_50hz
#define CAMACQ_MAIN_REG_FLICKER_60HZ            reg_main_flicker_60hz
#define CAMACQ_MAIN_REG_FLICKER_AUTO            reg_main_flicker_auto

// image quality
#define CAMACQ_MAIN_REG_JPEG_QUALITY_SUPERFINE reg_main_jpeg_quality_superfine
#define CAMACQ_MAIN_REG_JPEG_QUALITY_FINE      reg_main_jpeg_quality_fine
#define CAMACQ_MAIN_REG_JPEG_QUALITY_NORMAL    reg_main_jpeg_quality_normal

// Private Control
#define CAMACQ_MAIN_REG_PRIVCTRL_RETURNPREVIEW  reg_main_priv_ctrl_returnpreview

// Format
#define CAMACQ_MAIN_REG_FMT_YUV422 	            reg_main_fmt_yuv422
#define CAMACQ_MAIN_REG_FMT_JPG		            reg_main_fmt_jpg


// NEW
#define CAMACQ_MAIN_REG_SLEEP                   reg_main_sleep
#define CAMACQ_MAIN_REG_WAKEUP                  reg_main_wakeup

/* Enumeration */

/* Global Value */

GLOBAL const U8 reg_main_sleep[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U8 reg_main_wakeup[][2] 
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_init[][2]
#if defined(_CAMACQ_API_C_)
={
/******************************************************
*
*	Init.dat
*                                                    
*						      
*******************************************************/

{0x01, 0xf9}, //sleep on
{0x08, 0x0f}, //Hi-Z on
{0x01, 0xf8}, //sleep off

{0x03, 0x00}, //Dummy 750us
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},

{0x0e, 0x03}, //PLL On
{0x0e, 0x73}, //x2

{0x03, 0x00}, //Dummy 750us
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},

{0x0e, 0x00}, //PLL off
{0x01, 0xf9}, //sleep on
{0x08, 0x00}, //Hi-Z off

{0x01, 0xfb},
{0x01, 0xf9},

{0x03, 0x20}, //page 20
{0x10, 0x1c}, //ae off
    
{0x03, 0x22}, //page 22
{0x10, 0x69}, //awb off

//Initial Start
{0x03, 0x00}, //Initial Start
{0x10, 0x19}, //Sub 1/2 VSync Type2
{0x11, 0x90}, //Windowing On 1Frame Skip
{0x12, 0x04}, //rinsing edge 0x04 -> 00#  

{0x0b, 0xaa}, //ESD Check Register
{0x0c, 0xaa}, //ESD Check Register
{0x0d, 0xaa}, //ESD Check Register
{0xc1, 0xaa}, //ESD Check Register
{0xc2, 0xaa}, //ESD Check Register

{0x20, 0x00}, //WINROW START
    {0x21, 0x02},
    {0x22, 0x00},
    {0x23, 0x0a},

    {0x24, 0x04},
    {0x25, 0xb0},
    {0x26, 0x06},
{0x27, 0x40}, //WINROW END

{0x40, 0x01}, //Hblank 360
    {0x41, 0x68},
{0x42, 0x00}, //Vblank 88
{0x43, 0x58},

    {0x45, 0x04},
    {0x46, 0x18},
    {0x47, 0xd8},

//BLC
    {0x80, 0x2e},
    {0x81, 0x7e},
    {0x82, 0x90},
    {0x83, 0x00},
    {0x84, 0x0c},
    {0x85, 0x00},
{0x90, 0x0c}, //BLC_TIME_TH_ON
{0x91, 0x0c}, //BLC_TIME_TH_OFF 
{0x92, 0x60}, //BLC_AG_TH_ON
{0x93, 0x58}, //BLC_AG_TH_OFF
    {0x94, 0xff},
    {0x95, 0xff},
    {0x96, 0xdc},
    {0x97, 0xfe},
    {0x98, 0x38},

//Dark BLC
    {0xa0, 0x00},
    {0xa2, 0x00},
    {0xa4, 0x00},
    {0xa6, 0x00},

//Normal BLC
    {0xa8, 0x43},
    {0xaa, 0x43},
    {0xac, 0x43},
    {0xae, 0x43},

//Out BLC
    {0x99, 0x43},
    {0x9a, 0x43},
    {0x9b, 0x43},
    {0x9c, 0x43},

// 2Page
    {0x03, 0x02},
    {0x12, 0x03},
    {0x13, 0x03},
    {0x16, 0x00},
    {0x17, 0x8C},
{0x18, 0x28}, //20100209
    {0x1a, 0x36},
    {0x1c, 0x09},
    {0x1d, 0x40},
    {0x1e, 0x30},
    {0x1f, 0x10},

    {0x20, 0x77},
    {0x21, 0xdd},
    {0x22, 0xa7},
    {0x23, 0x30},
    {0x27, 0x3c},
    {0x2b, 0x80},
    {0x2e, 0x11},
    {0x2f, 0xa1},

    {0x50, 0x20},
{0x52, 0x03},
    {0x55, 0x1c},
    {0x56, 0x00},
{0x5d, 0xa2}, //20100209
    {0x5e, 0x5a},
    {0x60, 0x87},
    {0x61, 0x99},
    {0x62, 0x88},
    {0x63, 0x97},
    {0x64, 0x88},
    {0x65, 0x97},

    {0x67, 0x0c},
    {0x68, 0x0c},
    {0x69, 0x0c},

    {0x72, 0x89},
{0x73, 0x96}, //20100209
    {0x74, 0x89},
{0x75, 0x96}, //20100209
    {0x76, 0x89},
{0x77, 0x96}, //20100209

    {0x7C, 0x85},

    {0x81, 0x81},
    {0x82, 0x23},
    {0x83, 0x2b},
    {0x84, 0x7d},
    {0x85, 0x81},
    {0x86, 0x7d},
    {0x87, 0x81},

    {0x92, 0x53},
    {0x93, 0x5e},
    {0x94, 0x7d},
    {0x95, 0x81},
    {0x96, 0x7d},
    {0x97, 0x81},

{0xa1, 0x7B},
{0xa3, 0x7B},
{0xa4, 0x7B},
{0xa6, 0x7B},

    {0xa8, 0x85},
    {0xa9, 0x8c},
    {0xaa, 0x85},
    {0xab, 0x8c},
    {0xac, 0x20},
    {0xad, 0x26},
    {0xae, 0x20},
    {0xaf, 0x26},

    {0xb0, 0x99},
    {0xb1, 0xA3},
    {0xb2, 0xA4},
    {0xb3, 0xAE},
    {0xb4, 0x9B},
    {0xb5, 0xA2},
    {0xb6, 0xA6},
    {0xb7, 0xAC},
    {0xb8, 0x9B},
    {0xb9, 0x9F},
    {0xba, 0xA6},
    {0xbb, 0xAA},
    {0xbc, 0x9B},
{0xbd, 0x9e}, //20100209
    {0xbe, 0xA6},
{0xbf, 0xA9}, //20100209
    {0xc4, 0x36},
    {0xc5, 0x4E},
    {0xc6, 0x61},
    {0xc7, 0x78},
    {0xc8, 0x36},
    {0xc9, 0x4D},
    {0xca, 0x36},
    {0xcb, 0x4D},
    {0xcc, 0x62},
    {0xcd, 0x78},
    {0xce, 0x62},
    {0xcf, 0x78},
    {0xd0, 0x0a},
    {0xd1, 0x09},

{0xd4, 0x0c}, //DCDC_TIME_TH_ON
{0xd5, 0x0c}, //DCDC_TIME_TH_OFF 
{0xd6, 0x60}, //DCDC_AG_TH_ON
{0xd7, 0x58}, //DCDC_AG_TH_OFF
    {0xe0, 0xc4},
    {0xe1, 0xc4},
    {0xe2, 0xc4},
    {0xe3, 0xc4},
    {0xe4, 0x00},
    {0xe8, 0x00},

    {0xea, 0x82},

// 10 Page ISP-CTL1
    {0x03, 0x10},
    {0x10, 0x03}, //YCbYcr
    {0x12, 0x30},
    {0x20, 0x00},
    {0x40, 0x80},
    {0x41, 0x00},

    {0x30, 0x00},
    {0x31, 0x00},
    {0x32, 0x00},
    {0x33, 0x00},

    {0x34, 0x30},
    {0x35, 0x00},
    {0x36, 0x00},
    {0x38, 0x00},
    {0x3e, 0x58},
{0x3f, 0x02}, //For Preview

//Saturation
{0x60, 0x67}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30
    {0x64, 0x41},

{0x66, 0x42},
{0x67, 0x10},

    {0x6a, 0x45},
    {0x6b, 0x3a},
    {0x6c, 0x3f},
    {0x6d, 0x47},

//11 Page 
    {0x03, 0x11},
    {0x10, 0x3f},
    {0x11, 0x40},
    {0x12, 0xba},
{0x13, 0xcb},

    {0x26, 0x20},
    {0x27, 0x22},
    {0x28, 0x0f},
    {0x29, 0x10},
    {0x2b, 0x30},
    {0x2c, 0x32},

//Out2 D-LPF th
    {0x30, 0x70},
    {0x31, 0x10},
    {0x32, 0x65},
    {0x33, 0x09},
    {0x34, 0x06},
    {0x35, 0x04},

//Out1 D-LPF th
    {0x36, 0x70},
    {0x37, 0x18},
    {0x38, 0x65},
    {0x39, 0x09},
    {0x3a, 0x06},
    {0x3b, 0x04},

//Indoor D-LPF th
    {0x3c, 0x80},
    {0x3d, 0x18},
{0x3e, 0x80},
{0x3f, 0x0c},
{0x40, 0x09},
{0x41, 0x06},

    {0x42, 0x80},
    {0x43, 0x18},
    {0x44, 0x80},
    {0x45, 0x12},
    {0x46, 0x10},
    {0x47, 0x10},

    {0x48, 0x90},
    {0x49, 0x40},
    {0x4a, 0x80},
    {0x4b, 0x13},
    {0x4c, 0x10},
    {0x4d, 0x11},

    {0x4e, 0x80},
    {0x4f, 0x30},
    {0x50, 0x80},
    {0x51, 0x13},
    {0x52, 0x10},
    {0x53, 0x13},

    {0x54, 0x11},
    {0x55, 0x17},
    {0x56, 0x20},
    {0x57, 0x20},
    {0x58, 0x20},
    {0x59, 0x30},

    {0x5a, 0x18},
    {0x5b, 0x00},
    {0x5c, 0x00},

    {0x60, 0x3f},
{0x62, 0x50},
    {0x70, 0x06},

//12 Page
    {0x03, 0x12},
    {0x20, 0x0f},
    {0x21, 0x0f},

{0x25, 0x00}, //0x30

    {0x28, 0x00},
    {0x29, 0x00},
    {0x2a, 0x00},

//region th
    {0x30, 0x50},
    {0x31, 0x18},
    {0x32, 0x32},
    {0x33, 0x40},
    {0x34, 0x50},
    {0x35, 0x70},
    {0x36, 0xa0},

//Out2 th
    {0x40, 0xa0},
    {0x41, 0x40},
    {0x42, 0xa0},
{0x43, 0x90},
{0x44, 0x90},
    {0x45, 0x80},

//Out1 th
    {0x46, 0xb0},
    {0x47, 0x55},
    {0x48, 0xa0},
{0x49, 0x90},
{0x4a, 0x90},
    {0x4b, 0x80},

//Indoor th
    {0x4c, 0xb0},
    {0x4d, 0x40},
{0x4e, 0x90},
    {0x4f, 0x90},
    {0x50, 0xa0},
    {0x51, 0x80},

//Dark1 th
    {0x52, 0xb0},
    {0x53, 0x60},
    {0x54, 0xc0},
    {0x55, 0xc0},
    {0x56, 0xc0},
    {0x57, 0x80},

//Dark2 th
    {0x58, 0x90},
    {0x59, 0x40},
    {0x5a, 0xd0},
    {0x5b, 0xd0},
{0x5c, 0xe0},
    {0x5d, 0x80},

//Dark3 th
    {0x5e, 0x88},
    {0x5f, 0x40},
    {0x60, 0xe0},
    {0x61, 0xe0},
    {0x62, 0xe0},
    {0x63, 0x80},

    {0x70, 0x15},
    {0x71, 0x01},

    {0x72, 0x18},
    {0x73, 0x01},

    {0x74, 0x25},
    {0x75, 0x15},

    {0x80, 0x15},
    {0x81, 0x25},
    {0x82, 0x50},
    {0x85, 0x1a},
    {0x88, 0x00},
    {0x89, 0x00},

    {0x3b, 0x06},
    {0x3c, 0x06},

    {0xc5, 0x30},
    {0xc6, 0x2a},

//Don't Touch register
    {0xD0, 0x0c},
    {0xD1, 0x80},
    {0xD2, 0x67},
    {0xD3, 0x00},
    {0xD4, 0x00},
    {0xD5, 0x02},
    {0xD6, 0xff},
    {0xD7, 0x18},
//End

//13 Page
    {0x03, 0x13},
    {0x10, 0xcb},
    {0x11, 0x7b},
    {0x12, 0x07},
    {0x14, 0x00},

    {0x20, 0x15},
    {0x21, 0x13},
    {0x22, 0x33},
    {0x23, 0x04},
    {0x24, 0x09},

    {0x25, 0x0a},

{0x26, 0x18}, //w_gain 20->18//
    {0x27, 0x30},
    {0x29, 0x12},
    {0x2a, 0x50},

    {0x2b, 0x06},
    {0x2c, 0x06},
    {0x25, 0x08},
    {0x2d, 0x0c},
    {0x2e, 0x12},
    {0x2f, 0x12},

//Out2 Edge
    {0x50, 0x10},
    {0x51, 0x14},
{0x52, 0x10},
    {0x53, 0x0c},
    {0x54, 0x0f},
{0x55, 0x0c},

//Out1 Edge
    {0x56, 0x10},
    {0x57, 0x13},
{0x58, 0x10},
    {0x59, 0x0c},
    {0x5a, 0x0f},
{0x5b, 0x0c},

//Indoor Edge
    {0x5c, 0x0a},
    {0x5d, 0x0b},
    {0x5e, 0x0a},
    {0x5f, 0x08},
    {0x60, 0x09},
    {0x61, 0x08},

//Dark1 Edge
    {0x62, 0x08},
{0x63, 0x08},
    {0x64, 0x08},
    {0x65, 0x06},
{0x66, 0x06},
    {0x67, 0x06},

//Dark2 Edge
    {0x68, 0x07},
{0x69, 0x07},
    {0x6a, 0x07},
{0x6b, 0x05},
{0x6c, 0x05},
{0x6d, 0x05},

//Dark3 Edge
    {0x6e, 0x07},
{0x6f, 0x07},
    {0x70, 0x07},
{0x71, 0x05},
{0x72, 0x05},
{0x73, 0x05},

//2DY
    {0x80, 0xfd},
    {0x81, 0x1f},
{0x82, 0x01}, //0x05->0x01 0405 SFT Yoon
{0x83, 0x53}, //0x41->0x53 0405 SFT Yoon

    {0x90, 0x05},
    {0x91, 0x05},
    {0x92, 0x33},
    {0x93, 0x30},
    {0x94, 0x03},
    {0x95, 0x14},
{0x97, 0x27}, //0x30->0x27 0405 SFT Yoon
    {0x99, 0x2e},

    {0xa0, 0x04},
    {0xa1, 0x05},
    {0xa2, 0x04},
    {0xa3, 0x05},
    {0xa4, 0x07},
    {0xa5, 0x08},
    {0xa6, 0x07},
    {0xa7, 0x08},
    {0xa8, 0x07},
    {0xa9, 0x08},
    {0xaa, 0x07},
    {0xab, 0x08},

//Out2
    {0xb0, 0x22},
    {0xb1, 0x2a},
    {0xb2, 0x28},
    {0xb3, 0x22},
    {0xb4, 0x2a},
    {0xb5, 0x28},

//Out1
    {0xb6, 0x22},
    {0xb7, 0x2a},
    {0xb8, 0x28},
    {0xb9, 0x22},
    {0xba, 0x2a},
    {0xbb, 0x28},

//Indoor 
{0xbc, 0x25},
{0xbd, 0x2a},
{0xbe, 0x27},
{0xbf, 0x25},
{0xc0, 0x2a},
{0xc1, 0x27},

//Darxk1
    {0xc2, 0x1e},
    {0xc3, 0x24},
    {0xc4, 0x20},
    {0xc5, 0x1e},
    {0xc6, 0x24},
    {0xc7, 0x20},

//Dark2
    {0xc8, 0x18},
    {0xc9, 0x20},
    {0xca, 0x1e},
    {0xcb, 0x18},
    {0xcc, 0x20},
    {0xcd, 0x1e},

//Dark3 
    {0xce, 0x18},
    {0xcf, 0x20},
    {0xd0, 0x1e},
    {0xd1, 0x18},
    {0xd2, 0x20},
    {0xd3, 0x1e},

// 14 Page LensShading
    {0x03, 0x14},
    {0x10, 0x11},
{0x20, 0x70}, //80 60
{0x21, 0xa0}, //80
    {0x23, 0x80},
    {0x22, 0x80},
    {0x23, 0x80},
    {0x24, 0x80},

    {0x30, 0xc8},
    {0x31, 0x2b},
    {0x32, 0x00},
    {0x33, 0x00},
    {0x34, 0x90},

{0x40, 0x3d},
{0x50, 0x29}, //2d
{0x60, 0x24}, //26
{0x70, 0x29}, //2d

// 15page 
    {0x03, 0x15},
    {0x10, 0x0f},
    {0x14, 0x52},
    {0x15, 0x42},
    {0x16, 0x32},
    {0x17, 0x2f},

//CMC
    {0x30, 0x8f},
    {0x31, 0x59},
    {0x32, 0x0a},
    {0x33, 0x15},
    {0x34, 0x5b},
    {0x35, 0x06},
    {0x36, 0x07},
    {0x37, 0x40},
    {0x38, 0x86},

//CMC OFS
    {0x40, 0x95},
    {0x41, 0x1f},
    {0x42, 0x8a},
    {0x43, 0x86},
    {0x44, 0x0a},
    {0x45, 0x84},
    {0x46, 0x87},
    {0x47, 0x9b},
    {0x48, 0x23},

//CMC POFS
    {0x50, 0x8c},
    {0x51, 0x0c},
    {0x52, 0x00},
    {0x53, 0x07},
    {0x54, 0x17},
    {0x55, 0x9d},
    {0x56, 0x00},
    {0x57, 0x0b},
    {0x58, 0x89},

    {0x80, 0x03},
    {0x85, 0x40},
    {0x87, 0x02},
    {0x88, 0x00},
    {0x89, 0x00},
    {0x8a, 0x00},

// 16 Page Gamma
    {0x03, 0x16},
    {0x10, 0x31},
    {0x18, 0x37},
    {0x19, 0x36},
    {0x1a, 0x0e},
    {0x1b, 0x01},
    {0x1c, 0xdc},
    {0x1d, 0xfe},

//GMA_Default
    {0x30, 0x00},
{0x31, 0x06}, //06 -> 0c
{0x32, 0x1f}, //1f -> 1c
    {0x33, 0x2e},
    {0x34, 0x53},
    {0x35, 0x6c},
    {0x36, 0x81},
    {0x37, 0x94},
{0x38, 0xa4},
{0x39, 0xb3},
{0x3a, 0xc0},
{0x3b, 0xcb},
{0x3c, 0xd5},
{0x3d, 0xde},
{0x3e, 0xe6},
{0x3f, 0xee},
{0x40, 0xf6}, //100105 f5->f6
{0x41, 0xfd}, //100105 fc->fd
    {0x42, 0xff},

    {0x50, 0x00},
    {0x51, 0x03},
    {0x52, 0x19},
    {0x53, 0x34},
    {0x54, 0x58},
    {0x55, 0x75},
    {0x56, 0x8d},
    {0x57, 0xa1},
    {0x58, 0xb2},
    {0x59, 0xbe},
    {0x5a, 0xc9},
    {0x5b, 0xd2},
    {0x5c, 0xdb},
    {0x5d, 0xe3},
    {0x5e, 0xeb},
    {0x5f, 0xf0},
    {0x60, 0xf5},
    {0x61, 0xf7},
    {0x62, 0xf8},

    {0x70, 0x00},
    {0x71, 0x08},
    {0x72, 0x17},
    {0x73, 0x2f},
    {0x74, 0x53},
    {0x75, 0x6c},
    {0x76, 0x81},
    {0x77, 0x94},
    {0x78, 0xa4},
    {0x79, 0xb3},
    {0x7a, 0xc0},
    {0x7b, 0xcb},
    {0x7c, 0xd5},
    {0x7d, 0xde},
    {0x7e, 0xe6},
    {0x7f, 0xee},
    {0x80, 0xf4},
    {0x81, 0xfa},
    {0x82, 0xff},

// 17 Page AE
//HIST
    {0x03, 0x17},
    {0x10, 0xf7},

// 20 Page AE
//AE Start
    {0x03, 0x20},
    {0x11, 0x1c},
    {0x18, 0x30},
    {0x1a, 0x08},
    {0x20, 0x05},
    {0x21, 0x30},
    {0x22, 0x10},
    {0x23, 0x00},
    {0x24, 0x04},

    {0x28, 0xe7},
    {0x29, 0x0d},
    {0x2a, 0xff},
    {0x2b, 0xf4},

    {0x2c, 0xc2},
    {0x2d, 0x5f},
    {0x2e, 0x33},
    {0x30, 0xf8},
    {0x32, 0x03},
    {0x33, 0x2e},
    {0x34, 0x30},
    {0x35, 0xd4},
    {0x36, 0xfe},
    {0x37, 0x32},
    {0x38, 0x04},

//Y_Frame TH
    {0x50, 0x45},
    {0x51, 0x88},

{0x56, 0x10},
{0x57, 0xb7},
    {0x58, 0x14},
    {0x59, 0x88},
    {0x5a, 0x04},

    {0x60, 0x55},
    {0x61, 0x55},
{0x62, 0x6A},
{0x63, 0xA9},
{0x64, 0x6A},
{0x65, 0xA9},
    {0x66, 0x6B},
{0x67, 0xE9},
    {0x68, 0x6B},
{0x69, 0xE9},
{0x6a, 0x6A},
{0x6b, 0xA9},
{0x6c, 0x6A},
{0x6d, 0xA9},
    {0x6e, 0x55},
    {0x6f, 0x55},

//AE target
    {0x70, 0x70},
{0x71, 0x82},

    {0x78, 0x24},
    {0x79, 0x25},
    {0x7a, 0x23},
    {0x7b, 0x22},
    {0x7d, 0x23},



{0x83, 0x01}, //EXP Normal 33.33 fps 
{0x84, 0x5f},
{0x85, 0x90},


{0x86, 0x01}, //EXPMin 6000.00 fps
    {0x87, 0xf4},


{0x88, 0x05}, //EXP Max 8.33 fps 
{0x89, 0x7e},
{0x8a, 0x40},

{0x8B, 0x75}, //EXP100 
{0x8C, 0x30}, 


{0x8D, 0x61}, //EXP120 
{0x8E, 0xa8},

{0x98, 0x9d}, //Outdoor th1
{0x99, 0x45}, //Outdoor th2
    {0x9a, 0x0d},
    {0x9b, 0xde},

{0x9c, 0x17}, //EXP Limit 500.00 fps 
{0x9d, 0x70},
{0x9e, 0x01}, //EXP Unit 
    {0x9f, 0xf4},

    {0xa0, 0x03},
    {0xa1, 0xa9},
    {0xa2, 0x80},

{0xb0, 0x1d},
{0xb1, 0x0d}, //0d//0f//0d
{0xb2, 0x68}, // 78
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc0, 0x0d},
{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
    {0xc4, 0x08},

    {0xc8, 0x40},
    {0xc9, 0x40},
//AE End

// 22 Page AWB
    {0x03, 0x22},
    {0x10, 0xfd},
    {0x11, 0x2e},
    {0x19, 0x01},
    {0x20, 0x30},
{0x21, 0x00},
    {0x24, 0x01},

    {0x30, 0x80},
    {0x31, 0x80},
    {0x38, 0x11},
    {0x39, 0x34},
    {0x40, 0xf6},

{0x41, 0x33},
    {0x42, 0x22},
    {0x43, 0xf0},
{0x44, 0x43},
    {0x45, 0x33},
    {0x46, 0x00},
    {0x50, 0xb2},
    {0x51, 0x81},
    {0x52, 0x98},

{0x80, 0x38},
    {0x81, 0x20},
    {0x82, 0x3a},

{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
    {0x86, 0x24},

{0x87, 0x4c},// R Max 52 -> 50
{0x88, 0x3a},// R Min  3f-> 3d
{0x89, 0x3b},// B Max 3a->36
{0x8a, 0x2d},// B Min 2f->2d
                 
{0x8b, 0x40}, // R Max
{0x8c, 0x3b}, // R Min
{0x8d, 0x33}, // B Max 35->32
{0x8e, 0x2d}, // B Min 2e->2c

//Slope
    {0x8f, 0x63},
    {0x90, 0x61},
    {0x91, 0x5e},
    {0x92, 0x4d},
    {0x93, 0x40},
    {0x94, 0x3f},
{0x95, 0x39},
    {0x96, 0x30},
    {0x97, 0x24},
    {0x98, 0x20},
    {0x99, 0x20},
    {0x9a, 0x19},

{0x9b, 0x77},
    {0x9c, 0x55},
    {0x9d, 0x48},
    {0x9e, 0x38},
    {0x9f, 0x30},

    {0xa0, 0x74},
{0xa1, 0x85},//35
    {0xa2, 0xaf},
    {0xa3, 0xf7},

    {0xa4, 0x10},
    {0xa5, 0x26},
    {0xa6, 0xcf},

    {0xad, 0x40},
    {0xae, 0x4a},

{0xaf, 0x2f},  // low temp Rgain
{0xb0, 0x2a},  // low temp Rgain

{0xb1, 0x00},
    {0xb4, 0xea},
{0xb8, 0xa1}, //a2 B-3_R+2_091119 a2->a1
    {0xb9, 0x00},

{0x03, 0x20}, //AE on
{0x10, 0x9c}, //50Hz

    {0x03, 0x22},
    {0x10, 0xe9},

    {0x03, 0x00},
    {0x0e, 0x03},
    {0x0e, 0x73},

    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},
    {0x03, 0x00},

    {0x03, 0x00},
{0x01, 0xf8},

{0xfe, 0x0a},//NEED Delay 100ms//
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_fmt_jpg[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_fmt_yuv422[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA PREVIEW(640*480 / FULL)
//==========================================================
GLOBAL const U8 reg_main_preview[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x00},//Sleep On
{0x01, 0xf9},

{0x0e, 0x03},//Pll Off

{0x03, 0x20},//page 20
{0x18, 0x30},//for Preview
{0x10, 0x1c},//ae off_50Hz

{0x03, 0x22},//page 22
{0x10, 0x69},//awb off

	{0x03, 0x00},
{0x10, 0x19},//Sub 1/2_Preview1 Mode,VSync Type2
{0x11, 0x90},//Windowing On,1Frame Skip

{0x20, 0x00},//Windowing start point Y
	{0x21, 0x02},
{0x22, 0x00},//Windowing start point X
	{0x23, 0x0a},

{0x42, 0x00}, //Vblank 88
{0x43, 0x58},
    
//Page10
	{0x03, 0x10},
{0x3f, 0x02},//For Preview
{0x60, 0x6b},//For Preview

//Page12
{0x03, 0x12},//Function
	{0x20, 0x00},
	{0x21, 0x00},
	{0x90, 0x00},

//Page13
{0x03, 0x13},//Function
	{0x80, 0x00},

	{0x03, 0x20},
{0x10, 0x9c},//AE ON

	{0x03, 0x22},
{0x10, 0xe9},//AWB ON

	{0x03, 0x00},
{0x0e, 0x03}, //PLL ON
{0x0e, 0x73}, // x2

{0x03, 0x00},//Sleep Off  
{0x01, 0xf8},  

{0xfe, 0x28}, // delay 400ms
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// SNAPSHOT
//==========================================================

GLOBAL const U8 reg_main_snapshot[][2]
#if defined(_CAMACQ_API_C_)
={
/******************************************************
*
*	capture.dat
*                                                    
*						      
*******************************************************/


	{0x03, 0x00}, 
{0x01, 0xf9},

{0x0e, 0x03},//Pll off

	{0x03, 0x22}, 
	{0x10, 0x69},

	{0x03, 0x00},
{0x10, 0x08},  //Vsync Type 2 0x08, Type 1 0x00
	{0x11, 0x90}, 

	{0x20, 0x00},
	{0x21, 0x0a},
	{0x22, 0x00},
	{0x23, 0x0a},

//Page10
	{0x03, 0x10},
{0x3f, 0x00},//Capture DPC
	{0x60, 0x67},

//Page12
	{0x03, 0x12},
	{0x20, 0x0f},
	{0x21, 0x0f},
	{0x90, 0x5d},

//Page13
	{0x03, 0x13},
	{0x80, 0xfd},

	{0x03, 0x00},
	{0x0e, 0x73},

	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},

{0x03, 0x00},
{0x01, 0xf8}, 

{0xfe, 0x03},  //Delay 30ms
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// MIDLIGHT SNAPSHOT =======> Flash Low light snapshot
//==========================================================
GLOBAL const U8 reg_main_midlight[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// LOWLIGHT SNAPSHOT
//==========================================================
GLOBAL const U8 reg_main_lowlight[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;



/*****************************************************************/
/*********************** N I G H T  M O D E **********************/
/*****************************************************************/

//==========================================================
// CAMERA NIGHTMODE ON
//==========================================================
GLOBAL const U8 reg_main_nightshot_on[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA NIGHTMODE OFF
//==========================================================
GLOBAL const U8 reg_main_nightshot_off[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// NIGHT-MODE SNAPSHOT
//==========================================================
GLOBAL const U8 reg_main_nightshot[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_AUTO (1/10)
//==========================================================
GLOBAL const U8 reg_main_wb_auto[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x22},
{0x11, 0x2e},
{0x80, 0x38},
{0x81, 0x20},
{0x82, 0x3a},
{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
{0x86, 0x24},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_DAYLIGHT (2/10)
//==========================================================
GLOBAL const U8 reg_main_wb_daylight[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x22},
{0x11, 0x2c},
{0x80, 0x52},
{0x81, 0x20},
{0x82, 0x27},
{0x83, 0x58},
{0x84, 0x4d},
{0x85, 0x2c},
{0x86, 0x22},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_CLOUDY  (3/10)
//==========================================================
GLOBAL const U8 reg_main_wb_cloudy[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x22},
{0x11, 0x2c},
{0x80, 0x71},//71 //R
{0x81, 0x20},//G  
{0x82, 0x20},//B  
{0x83, 0x72},//72 // Rmax 6f
{0x84, 0x6e},//70 70 // Rmin 68
{0x85, 0x21},//1f    Bmax     
{0x86, 0x1f},//1e    Bmin    
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_INCANDESCENT (4/10)
//==========================================================
GLOBAL const U8 reg_main_wb_incandescent[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x22},
{0x11, 0x2c},
{0x80, 0x20},
{0x81, 0x20},
{0x82, 0x58},
{0x83, 0x23},
{0x84, 0x1f},
{0x85, 0x58},
{0x86, 0x52},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (5/10)
//==========================================================
GLOBAL const U8 reg_main_wb_fluorescent[][2]
#if defined(_CAMACQ_API_C_)
={
    {0x03, 0x22},
    {0x11, 0x2c},
    {0x80, 0x3d},
    {0x81, 0x20},
    {0x82, 0x4a},
    {0x83, 0x42},
    {0x84, 0x3c},
    {0x85, 0x51},
    {0x86, 0x47},
    {0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (6/10)
//==========================================================
GLOBAL const U8 reg_main_wb_twilight[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (7/10)
//==========================================================
GLOBAL const U8 reg_main_wb_tungsten[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (8/10)
//==========================================================
GLOBAL const U8 reg_main_wb_off[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (9/10)
//==========================================================
GLOBAL const U8 reg_main_wb_horizon[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (10/10)
//==========================================================
GLOBAL const U8 reg_main_wb_shade[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_EFFECT_OFF (1/13)
//==========================================================
GLOBAL const U8 reg_main_effect_none[][2]
#if defined(_CAMACQ_API_C_)
={
	{0x03, 0x10},
	{0x11, 0x03},
	{0x12, 0x30}, 
  	{0x44, 0x80},
        {0x45, 0x80},
	{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_MONO (2/13)
//==========================================================
GLOBAL const U8 reg_main_effect_gray[][2]
#if defined(_CAMACQ_API_C_)
={
	{0x03, 0x10},
	{0x11, 0x03},
        {0x12, 0x33},
	{0x44, 0x80},
	{0x45, 0x80},
	{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_NEGATIVE (3/13)
//==========================================================
GLOBAL const U8 reg_main_effect_negative[][2]
#if defined(_CAMACQ_API_C_)
={
	{0x03, 0x10},
	{0x11, 0x03},
  	{0x12, 0x38},
  	{0x44, 0x80},
  	{0x45, 0x80},
	{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SOLARIZE (4/13)
//==========================================================
GLOBAL const U8 reg_main_effect_solarize[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SEPIA (5/13)
//==========================================================
GLOBAL const U8 reg_main_effect_sepia[][2]
#if defined(_CAMACQ_API_C_)
={
	{0x03, 0x10},
	{0x11, 0x03},
  	{0x12, 0x33},
	{0x44, 0x70},
	{0x45, 0x98},
	{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_POSTERIZE (6/13)
//==========================================================
GLOBAL const U8 reg_main_effect_posterize[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_WHITEBOARD (7/13)
//==========================================================
GLOBAL const U8 reg_main_effect_whiteboard[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_BLACKBOARD (8/13)
//==========================================================
GLOBAL const U8 reg_main_effect_blackboard[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_AQUA (9/13)
//==========================================================
GLOBAL const U8 reg_main_effect_aqua[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SHARPEN (10/13)
//==========================================================
GLOBAL const U8 reg_main_effect_sharpen[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_AQUA (11/13)
//==========================================================
GLOBAL const U8 reg_main_effect_vivid[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_GREEN (12/13)
//==========================================================
GLOBAL const U8 reg_main_effect_green[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SKETCH (13/13)
//==========================================================
GLOBAL const U8 reg_main_effect_sketch[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_AEC_MATRIX_METERING (2/2)
//==========================================================
GLOBAL const U8 reg_main_meter_matrix[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x20},
{0x60, 0x55},
{0x61, 0x55},
{0x62, 0x55},
{0x63, 0x55},
{0x64, 0x55},
{0x65, 0x55},
{0x66, 0x55},
{0x67, 0x55},
{0x68, 0x55},
{0x69, 0x55},
{0x6a, 0x55},
{0x6b, 0x55},
{0x6c, 0x55},
{0x6d, 0x55},
{0x6e, 0x55},
{0x6f, 0x55},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_CENTERWEIGHTED_METERING (2/2)
//==========================================================
GLOBAL const U8 reg_main_meter_cw[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x20},
{0x60, 0x55},
{0x61, 0x55},
{0x62, 0x6A},
{0x63, 0xA9},
{0x64, 0x6A},
{0x65, 0xA9},
{0x66, 0x6B},
{0x67, 0xE9},
{0x68, 0x6B},
{0x69, 0xE9},
{0x6a, 0x6A},
{0x6b, 0xA9},
{0x6c, 0x6A},
{0x6d, 0xA9},
{0x6e, 0x55},
{0x6f, 0x55},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_SPOT_METERING (1/2)
//==========================================================
GLOBAL const U8 reg_main_meter_spot[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x20},
{0x60, 0x00},
{0x61, 0x00},
{0x62, 0x00},
{0x63, 0x00},
{0x64, 0x00},
{0x65, 0x00},
{0x66, 0x03},
{0x67, 0xc0},
{0x68, 0x03},
{0x69, 0xc0},
{0x6a, 0x00},
{0x6b, 0x00},
{0x6c, 0x00},
{0x6d, 0x00},
{0x6e, 0x00},
{0x6f, 0x00},
	{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_FRAME_AVERAGE (2/2)
//==========================================================
GLOBAL const U8 reg_main_meter_frame[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_NONE (1/4)
//==========================================================
GLOBAL const U8 reg_main_flip_none[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_VERTICAL (2/4)
//==========================================================
GLOBAL const U8 reg_main_flip_water[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_HORIZ (3/4)
//==========================================================
GLOBAL const U8 reg_main_flip_mirror[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FLIP_SYMMETRIC (4/4)
//==========================================================
GLOBAL const U8 reg_main_flip_water_mirror[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;



//==========================================================
// CAMERA_CAMCORDER
//==========================================================
GLOBAL const U8 reg_main_camcorder[][2]
#if defined(_CAMACQ_API_C_)
={

/*==========================================================
//	CAMERA_CAMCORDER_FPS_14.91FIX 
//==========================================================*/


{0x03,0x00},
{0x01,0xf9},
{0x0e, 0x03},
{0x03, 0x00},
{0x11,0x90},

{0x42, 0x00}, /*Vsync 20 */
{0x43,0x14},

{0x03,0x20},
{0x10,0x1C},

{0x03,0x22},
{0x10,0x69},

{0x03,0x20},
{0x2a,0x03},
{0x2b,0xf5},
{0x83, 0x01}, //EXP Normal 33.33 fps 
{0x84, 0x5f}, 
{0x85, 0x90}, 

{0x88, 0x02}, //EXP Max 20.00 fps 
{0x89, 0x49},
{0x8a, 0xf0},

{0x91, 0x02}, //EXP Fix 14.91 fps
{0x92, 0xfe},
{0x93, 0x9a},

{0x03,0x20},
{0x10,0x9C},

{0x03,0x22},
{0x10,0xe9},

{0x03,0x00},
{0x11,0x94},

{0x03,0x00},
{0x0e, 0x03},
{0x0e, 0x73},

{0x03, 0x00},
{0x03,0x00},
{0x03,0x00},
{0x03,0x00},
{0x03,0x00},
{0x03,0x00},
{0x03,0x00},
{0x03,0x00},
{0x03,0x00},
{0x03,0x00},
{0x03, 0x00},
{0x01,0xf8},

{0xfe, 0x32}, //NEED Delay 500ms //
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FRAMERATE_5FPS
//==========================================================
GLOBAL const U8 reg_main_fps_fixed_5[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FRAMERATE_7FPS
//==========================================================
GLOBAL const U8 reg_main_fps_fixed_7[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_10FPS
//==========================================================
GLOBAL const U8 reg_main_fps_fixed_10[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_15FPS
//==========================================================
GLOBAL const U8 reg_main_fps_fixed_15[][2]
#if defined(_CAMACQ_API_C_)
={
	  {0x03, 0x00},
{0x01, 0xf9},
	  {0x0e, 0x03},
	  {0x03, 0x00},
	  {0x11, 0x90},
	
	  {0x42, 0x00},
	  {0x43, 0x14},
	  {0x03, 0x20},
{0x10, 0x1C},
	  {0x03, 0x22},
	  {0x10, 0x69},
	
	  {0x03, 0x20},
	  {0x2a, 0x03},
	  {0x2b, 0xf5},
	
{0x83, 0x01}, //EXP Normal 33.33 fps 
{0x84, 0x5f}, 
{0x85, 0x90}, 
{0x88, 0x02}, //EXP Max 20.00 fps 
	  {0x89, 0x49},
	  {0x8a, 0xf0},
	
{0x91, 0x02}, //EXP Fix 14.91 fps
	  {0x92, 0xfe},
	  {0x93, 0x9a},
	
	  {0x03, 0x20},
{0x10, 0x9C},
	  {0x03, 0x22},
	  {0x10, 0xe9},
	
	  {0x03, 0x00},
	  {0x11, 0x94},
	
	  {0x03, 0x00},
	  {0x0e, 0x03},
	  {0x0e, 0x73},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
	  {0x03, 0x00},
{0x01, 0xf8},
	
{0xfe, 0x32}, //NEED Delay 500ms //
{0xff, 0xff},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_20FPS
//==========================================================
GLOBAL const U8 reg_main_fps_fixed_20[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_25FPS
//==========================================================
GLOBAL const U8 reg_main_fps_fixed_25[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_30FPS
//==========================================================
GLOBAL const U8 reg_main_fps_fixed_30[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_AUTO_MAX15(5~15fps)
//==========================================================
GLOBAL const U8 reg_main_fps_var_15[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_BRIGHTNESS_LEVEL1 (1/9) : 
//==========================================================
GLOBAL const U8 reg_main_brightness_level_0[][2]
#if defined(_CAMACQ_API_C_)
={
	{0x03, 0x10},
	{0x40, 0xd0},
	{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL2 (2/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_1[][2]
#if defined(_CAMACQ_API_C_)
={
	{0x03, 0x10},
    {0x40, 0xc0},
	{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL3 (3/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_2[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x10},
{0x40, 0xb0},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL4 (4/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_3[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x10},
{0x40, 0xa0},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL5 (5/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_4[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x10},
{0x40, 0x00},

{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL6 (6/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_5[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x10},
{0x40, 0x20},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL7 (7/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_6[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x10},
{0x40, 0x30},

{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL8 (8/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_7[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x10},
{0x40, 0x40},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL9 (9/9)
//==========================================================
GLOBAL const U8 reg_main_brightness_level_8[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x10},
{0x40, 0x50},
{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL1 (1/9) : 
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_0[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL2 (2/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_1[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL3 (3/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_2[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL4 (4/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_3[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL5 (5/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_4[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL6 (6/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_5[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL7 (7/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_6[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL8 (8/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_7[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL9 (9/9)
//==========================================================
GLOBAL const U8 reg_main_expcompensation_level_8[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AF
//==========================================================
GLOBAL const U8 reg_main_reset_af [][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_nlux [][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_llux [][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af[][2] // start_af
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_off_af[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U8 reg_main_check_af[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_manual_af[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_macro_af[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_return_manual_af[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_return_macro_af[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_normal_mode_1[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_normal_mode_2[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_normal_mode_3[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_macro_mode_1[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_macro_mode_2[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_set_af_macro_mode_3[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_AUTO
//==========================================================
GLOBAL const U8 reg_main_iso_auto[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_50
//==========================================================
GLOBAL const U8 reg_main_iso_50[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_100
//==========================================================
GLOBAL const U8 reg_main_iso_100[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_200
//==========================================================
GLOBAL const U8 reg_main_iso_200[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_400
//==========================================================
GLOBAL const U8 reg_main_iso_400[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_800
//==========================================================
GLOBAL const U8 reg_main_iso_800[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_1600
//==========================================================
GLOBAL const U8 reg_main_iso_1600[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_3200
//==========================================================
GLOBAL const U8 reg_main_iso_3200[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_AUTO (OFF)
//==========================================================
GLOBAL const U8 reg_main_scene_auto[][2]
#if defined(_CAMACQ_API_C_)
={
/* CAMERA_SCENEMODE_OFF */

{0x03, 0x00},
{0xa0, 0x00},
{0xa2, 0x00},
{0xa4, 0x00},
{0xa6, 0x00},


{0x03, 0x16}, 
{0x70, 0x00}, 
{0x71, 0x08}, 
{0x72, 0x17}, 
{0x73, 0x2f}, 
{0x74, 0x53}, 
{0x75, 0x6c}, 
{0x76, 0x81}, 
{0x77, 0x94}, 
{0x78, 0xa4}, 
{0x79, 0xb3}, 
{0x7a, 0xc0}, 
{0x7b, 0xcb}, 
{0x7c, 0xd5}, 
{0x7d, 0xde}, 
{0x7e, 0xe6}, 
{0x7f, 0xee}, 
{0x80, 0xf4}, 
{0x81, 0xfa}, 
{0x82, 0xff}, 

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

//Metering Center
{0x60, 0x55}, 
{0x61, 0x55}, 
{0x62, 0x6a}, 
{0x63, 0xa9}, 
{0x64, 0x6a}, 
{0x65, 0xa9}, 
{0x66, 0x6b}, 
{0x67, 0xe9}, 
{0x68, 0x6b}, 
{0x69, 0xe9}, 
{0x6a, 0x6a}, 
{0x6b, 0xa9}, 
{0x6c, 0x6a}, 
{0x6d, 0xa9}, 
{0x6e, 0x55}, 
{0x6f, 0x55}, 

//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
{0x89, 0x7e}, 
{0x8a, 0x40}, 

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x68},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
{0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB Auto  
{0x03, 0x22},
{0x11, 0x2e},

{0x80, 0x38},
{0x81, 0x20},
{0x82, 0x3a},

{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
{0x86, 0x24}, 

//Saturation 0, EV 0
{0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness 0
{0x03, 0x13},
{0x12, 0x07},
{0x25, 0x0a},
{0x20, 0x15},
{0x21, 0x13},

{0xfe, 0x28},

{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_NIGHT
//==========================================================
GLOBAL const U8 reg_main_scene_night[][2]
#if defined(_CAMACQ_API_C_)
={
/* CAMERA_SCENEMODE_NIGHT_Nomal */                
   
  {0x03, 0x00},
{0xa0, 0x01},
{0xa2, 0x01},
{0xa4, 0x01},
{0xa6, 0x01},

    {0x03, 0x16},
    {0x70, 0x00},
    {0x71, 0x10},
    {0x72, 0x1e},
    {0x73, 0x36},
    {0x74, 0x5a},
    {0x75, 0x74},
    {0x76, 0x89},
    {0x77, 0x9c},
    {0x78, 0xac},
    {0x79, 0xbb},
    {0x7a, 0xc8},
    {0x7b, 0xd3},
    {0x7c, 0xdd},
    {0x7d, 0xe7},
    {0x7e, 0xea},
    {0x7f, 0xf3},
    {0x80, 0xf8},
    {0x81, 0xfc},
    {0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

//Metering Center
    {0x60, 0x55},
    {0x61, 0x55},
    {0x62, 0x6a},
    {0x63, 0xa9},
    {0x64, 0x6a},
    {0x65, 0xa9},
    {0x66, 0x6b},
    {0x67, 0xe9},
    {0x68, 0x6b},
    {0x69, 0xe9},
    {0x6a, 0x6a},
    {0x6b, 0xa9},
    {0x6c, 0x6a},
    {0x6d, 0xa9},
    {0x6e, 0x55},
    {0x6f, 0x55},

{0x88, 0x0d}, //EXP Max 3.33 fps 
{0x89, 0xbb}, 
{0x8a, 0xa0}, 

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x90},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
{0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB Auto  
    {0x03, 0x22},
    {0x11, 0x2e},

    {0x80, 0x38},
    {0x81, 0x20},
    {0x82, 0x3a},

{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
    {0x86, 0x24},

//Saturation 0, EV 0
    {0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness 0
    {0x03, 0x13},
    {0x12, 0x07},
    {0x25, 0x0a},
    {0x20, 0x15},
    {0x21, 0x13},

{0xfe, 0x28},

    {0xff, 0xff},  
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U8 reg_main_scene_night_dark[][2]
#if defined(_CAMACQ_API_C_)
={
 /* CAMERA_SCENEMODE_NIGHT_Dark */                             
                                                                
  {0x03, 0x00},
{0xa0, 0x01},
{0xa2, 0x01},
{0xa4, 0x01},
{0xa6, 0x01},

    {0x03, 0x16},
    {0x70, 0x00},
    {0x71, 0x10},
    {0x72, 0x1e},
    {0x73, 0x36},
    {0x74, 0x5a},
    {0x75, 0x74},
    {0x76, 0x89},
    {0x77, 0x9c},
    {0x78, 0xac},
    {0x79, 0xbb},
    {0x7a, 0xc8},
    {0x7b, 0xd3},
    {0x7c, 0xdd},
    {0x7d, 0xe7},
    {0x7e, 0xea},
    {0x7f, 0xf3},
    {0x80, 0xf8},
    {0x81, 0xfc},
    {0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

//Metering Center
     {0x60, 0x55},                                              
     {0x61, 0x55},                                              
     {0x62, 0x6a},                                              
     {0x63, 0xa9},                                              
     {0x64, 0x6a},                                              
     {0x65, 0xa9},                                              
     {0x66, 0x6b},                                              
     {0x67, 0xe9},                                              
     {0x68, 0x6b},                                              
     {0x69, 0xe9},                                              
     {0x6a, 0x6a},                                              
     {0x6b, 0xa9},                                              
     {0x6c, 0x6a},                                              
     {0x6d, 0xa9},                                              
     {0x6e, 0x55},                                              
     {0x6f, 0x55},    
                                               
{0x83, 0x0d}, // Expnormal 3.33fps
{0x84, 0xbb},
{0x85, 0xa0},

{0x88, 0x0d}, //EXP Max 3.33 fps 
{0x89, 0xbb}, 
{0x8a, 0xa0}, 

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x90},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
     {0xc4, 0x08},                                              

{0x10, 0x9c}, // AE On
                                                                
//WB Auto  
     {0x03, 0x22},                                              
     {0x11, 0x2e},                                              
                                                                
     {0x80, 0x38},                                              
     {0x81, 0x20},                                              
     {0x82, 0x3a},                                              
                                                                
{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
     {0x86, 0x24},                                              
                                                                
//Saturation 0, EV 0
     {0x03, 0x10},                                              
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30
                                                                
//Sharpness 0
     {0x03, 0x13},                                              
     {0x12, 0x07},                                              
     {0x25, 0x0a},                                              
     {0x20, 0x15},                                              
     {0x21, 0x13},                                              

{0x10, 0x9C},
{0xfe, 0x28},

    {0xff, 0xff},  
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_LANDSCAPE
//==========================================================
GLOBAL const U8 reg_main_scene_landscape[][2]
#if defined(_CAMACQ_API_C_)
={
/* CAMERA_SCENEMODE_LANDSCAPE   :*/

	{0x03, 0x00},
        {0xa0, 0x00},
        {0xa2, 0x00},
        {0xa4, 0x00},
        {0xa6, 0x00},

        {0x03, 0x16},
        {0x70, 0x00},
        {0x71, 0x08},
        {0x72, 0x17},
        {0x73, 0x2f},
        {0x74, 0x53},
        {0x75, 0x6c},
        {0x76, 0x81},
        {0x77, 0x94},
        {0x78, 0xa4},
        {0x79, 0xb3},
        {0x7a, 0xc0},
        {0x7b, 0xcb},
        {0x7c, 0xd5},
        {0x7d, 0xde},
        {0x7e, 0xe6},
        {0x7f, 0xee},
        {0x80, 0xf4},
        {0x81, 0xfa},
        {0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

// AE Matrix(Average)
        {0x60, 0x55},
        {0x61, 0x55},
{0x62, 0x6a},
{0x63, 0xa9},
{0x64, 0x6a},
{0x65, 0xa9},
{0x66, 0x6a},
{0x67, 0xa9},
{0x68, 0x6a},
{0x69, 0xa9},
{0x6a, 0x6a},
{0x6b, 0xa9},
{0x6c, 0x6a},
{0x6d, 0xa9},
        {0x6e, 0x55},
        {0x6f, 0x55},

//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
        {0x89, 0x7e},
        {0x8a, 0x40},

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x68},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
        {0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB Auto  
        {0x03, 0x22},
        {0x11, 0x2e},

        {0x80, 0x38},
        {0x81, 0x20},
        {0x82, 0x3a},

{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
        {0x86, 0x24},

//Saturation 0, EV 0
        {0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x89}, //B str
{0x62, 0x84}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness +1
        {0x03, 0x13},
        {0x12, 0x02},
        {0x25, 0x02},
        {0x20, 0x1a},
        {0x21, 0x1a},
   
{0xfe, 0x28},
        {0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SUNSET
//==========================================================
GLOBAL const U8 reg_main_scene_sunset[][2]
#if defined(_CAMACQ_API_C_)
={

/* CAMERA_SCENEMODE_SUNSET   : ??\u017e?\u017e???  */     
                 
        {0x03, 0x00},            
        {0xa0, 0x00},            
        {0xa2, 0x00},            
        {0xa4, 0x00},            
        {0xa6, 0x00},            

        {0x03, 0x16},            
        {0x70, 0x00},            
        {0x71, 0x08},            
        {0x72, 0x17},            
        {0x73, 0x2f},            
        {0x74, 0x53},            
        {0x75, 0x6c},            
        {0x76, 0x81},            
        {0x77, 0x94},            
        {0x78, 0xa4},            
        {0x79, 0xb3},            
        {0x7a, 0xc0},            
        {0x7b, 0xcb},            
        {0x7c, 0xd5},            
        {0x7d, 0xde},            
        {0x7e, 0xe6},            
        {0x7f, 0xee},            
        {0x80, 0xf4},            
        {0x81, 0xfa},            
        {0x82, 0xff},            
          
{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

//Metering Center
        {0x60, 0x55},            
        {0x61, 0x55},            
        {0x62, 0x6a},            
        {0x63, 0xa9},            
        {0x64, 0x6a},            
        {0x65, 0xa9},            
        {0x66, 0x6b},            
        {0x67, 0xe9},            
        {0x68, 0x6b},            
        {0x69, 0xe9},            
        {0x6a, 0x6a},            
        {0x6b, 0xa9},            
        {0x6c, 0x6a},            
        {0x6d, 0xa9},            
        {0x6e, 0x55},            
        {0x6f, 0x55},            
                
//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
        {0x89, 0x7e},            
        {0x8a, 0x40},            
              
//ISO AUTO 
        {0xb1, 0x0d},            
{0xb2, 0x68},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
        {0xc4, 0x08},            
            
{0xff, 0x05},
{0x10, 0x9c}, // AE On
     
//WB Day 
        {0x03, 0x22},            
        {0x11, 0x2c},            
           
        {0x80, 0x52},            
        {0x81, 0x20},            
        {0x82, 0x27},            
             
        {0x83, 0x58},            
        {0x84, 0x4d},            
        {0x85, 0x2c},            
        {0x86, 0x22},            
                 
//Saturation 0, EV 0
{0x03, 0x10},
{0x40, 0x00},
{0x60, 0x6b}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness 0
        {0x03, 0x13},            
        {0x12, 0x07},            
        {0x25, 0x0a},            
        {0x20, 0x15},            
        {0x21, 0x13},

{0xfe, 0x28},
        {0xff, 0xff},
        
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_PORTRAIT
//==========================================================
GLOBAL const U8 reg_main_scene_portrait[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SUNRISE
//==========================================================
GLOBAL const U8 reg_main_scene_sunrise[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x00},
{0xa0, 0x00},
{0xa2, 0x00},
{0xa4, 0x00},
{0xa6, 0x00},

{0x03, 0x16},
{0x70, 0x00},
{0x71, 0x08},
{0x72, 0x17},
{0x73, 0x2f},
{0x74, 0x53},
{0x75, 0x6c},
{0x76, 0x81},
{0x77, 0x94},
{0x78, 0xa4},
{0x79, 0xb3},
{0x7a, 0xc0},
{0x7b, 0xcb},
{0x7c, 0xd5},
{0x7d, 0xde},
{0x7e, 0xe6},
{0x7f, 0xee},
{0x80, 0xf4},
{0x81, 0xfa},
{0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

//Metering Center
{0x60, 0x55},
{0x61, 0x55},
{0x62, 0x6a},
{0x63, 0xa9},
{0x64, 0x6a},
{0x65, 0xa9},
{0x66, 0x6b},
{0x67, 0xe9},
{0x68, 0x6b},
{0x69, 0xe9},
{0x6a, 0x6a},
{0x6b, 0xa9},
{0x6c, 0x6a},
{0x6d, 0xa9},
{0x6e, 0x55},
{0x6f, 0x55},

//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
{0x89, 0x7e}, 
{0x8a, 0x40}, 

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x68},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
{0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB FLUORESCENT
{0x03, 0x22},
{0x11, 0x2c},

{0x80, 0x3d},
{0x81, 0x20},
{0x82, 0x4a},

{0x83, 0x42},
{0x84, 0x3c},
{0x85, 0x51},
{0x86, 0x47},

//Saturation 0, EV 0
{0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness 0
{0x03, 0x13},
{0x12, 0x07},
{0x25, 0x0a},
{0x20, 0x15},
{0x21, 0x13},

{0xfe, 0x28},
        {0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_INDOOR // == PARTY
//==========================================================
GLOBAL const U8 reg_main_scene_indoor[][2]
#if defined(_CAMACQ_API_C_)
={
/* CAMERA_SCENEMODE_AGAINST   : ??\u017e?\u017e???*/

        {0x03, 0x00},
        {0xa0, 0x00},
        {0xa2, 0x00},
        {0xa4, 0x00},
        {0xa6, 0x00},

        {0x03, 0x16},
        {0x70, 0x00},
        {0x71, 0x08},
        {0x72, 0x17},
        {0x73, 0x2f},
        {0x74, 0x53},
        {0x75, 0x6c},
        {0x76, 0x81},
        {0x77, 0x94},
        {0x78, 0xa4},
        {0x79, 0xb3},
        {0x7a, 0xc0},
        {0x7b, 0xcb},
        {0x7c, 0xd5},
        {0x7d, 0xde},
        {0x7e, 0xe6},
        {0x7f, 0xee},
        {0x80, 0xf4},
        {0x81, 0xfa},
        {0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x13}, //Adaptive off

//Metering Center
        {0x60, 0x55},
        {0x61, 0x55},
        {0x62, 0x6a},
        {0x63, 0xa9},
        {0x64, 0x6a},
        {0x65, 0xa9},
        {0x66, 0x6b},
        {0x67, 0xe9},
        {0x68, 0x6b},
        {0x69, 0xe9},
        {0x6a, 0x6a},
        {0x6b, 0xa9},
        {0x6c, 0x6a},
        {0x6d, 0xa9},
        {0x6e, 0x55},
        {0x6f, 0x55},

//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
{0x89, 0x7e}, 
{0x8a, 0x40}, 

 //ISO_200 
        {0xb1, 0x1d},
        {0xb2, 0x37},
        {0xb3, 0x1d},
        {0xb4, 0x1d},
        {0xb5, 0x37},
        {0xb6, 0x2c},
        {0xb7, 0x27},
        {0xb8, 0x25},
        {0xb9, 0x23},
        {0xba, 0x22},
        {0xbb, 0x22},
        {0xbc, 0x21},
        {0xbd, 0x21},

        {0xc1, 0x21},
        {0xc2, 0x21},
        {0xc3, 0x21},
        {0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB Auto  
        {0x03, 0x22},
        {0x11, 0x2e},

        {0x80, 0x38},
        {0x81, 0x20},
        {0x82, 0x3a},

{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
        {0x86, 0x24},
        
//Saturation 0, EV 0
{0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x89}, //B str
{0x62, 0x84}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness 0
        {0x03, 0x13},
        {0x12, 0x07},
        {0x25, 0x0a},
        {0x20, 0x15},
        {0x21, 0x13},

{0xfe, 0x28},
        
{0xff, 0xff},}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_PARTY // == INDOOR
//==========================================================
GLOBAL const U8 reg_main_scene_party[][2] 
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SPORTS
//==========================================================
GLOBAL const U8 reg_main_scene_sports[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_BEACH
//==========================================================
GLOBAL const U8 reg_main_scene_beach[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SNOW
//==========================================================
GLOBAL const U8 reg_main_scene_snow[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_FALLCOLOR
//==========================================================
GLOBAL const U8 reg_main_scene_fallcolor[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x00},
{0xa0, 0x00},
{0xa2, 0x00},
{0xa4, 0x00},
{0xa6, 0x00},

{0x03, 0x16},
{0x70, 0x00},
{0x71, 0x08},
{0x72, 0x17},
{0x73, 0x2f},
{0x74, 0x53},
{0x75, 0x6c},
{0x76, 0x81},
{0x77, 0x94},
{0x78, 0xa4},
{0x79, 0xb3},
{0x7a, 0xc0},
{0x7b, 0xcb},
{0x7c, 0xd5},
{0x7d, 0xde},
{0x7e, 0xe6},
{0x7f, 0xee},
{0x80, 0xf4},
{0x81, 0xfa},
{0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

//Metering Center
{0x60, 0x55},
{0x61, 0x55},
{0x62, 0x6a},
{0x63, 0xa9},
{0x64, 0x6a},
{0x65, 0xa9},
{0x66, 0x6b},
{0x67, 0xe9},
{0x68, 0x6b},
{0x69, 0xe9},
{0x6a, 0x6a},
{0x6b, 0xa9},
{0x6c, 0x6a},
{0x6d, 0xa9},
{0x6e, 0x55},
{0x6f, 0x55},

//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
{0x89, 0x7e}, 
{0x8a, 0x40}, 

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x68},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
{0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB Auto  
{0x03, 0x22},
{0x11, 0x2e},

{0x80, 0x38},
{0x81, 0x20},
{0x82, 0x3a},

{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
{0x86, 0x24},

//Saturation 0, EV 0
{0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x99}, //B str
{0x62, 0x94}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30
//Sharpness 0
{0x03, 0x13},
{0x12, 0x07},
{0x25, 0x0a},
{0x20, 0x15},
{0x21, 0x13},

{0xfe, 0x28},

{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_FIREWORKS
//==========================================================
GLOBAL const U8 reg_main_scene_fireworks[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_CANDLELIGHT
//==========================================================
GLOBAL const U8 reg_main_scene_candlelight[][2]
#if defined(_CAMACQ_API_C_)
={

/* CAMERA_SCENE_CANDLELIGHT    : ??\u017e?\u017e???*/
{0x03, 0x00}, 
{0xa0, 0x00},
{0xa2, 0x00},
{0xa4, 0x00},
{0xa6, 0x00},

{0x03, 0x16},
{0x70, 0x00},
{0x71, 0x08},
{0x72, 0x17},
{0x73, 0x2f},
{0x74, 0x53},
{0x75, 0x6c},
{0x76, 0x81},
{0x77, 0x94},
{0x78, 0xa4},
{0x79, 0xb3},
{0x7a, 0xc0},
{0x7b, 0xcb},
{0x7c, 0xd5},
{0x7d, 0xde},
{0x7e, 0xe6},
{0x7f, 0xee},
{0x80, 0xf4},
{0x81, 0xfa},
{0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

//Metering Center
{0x60, 0x55},
{0x61, 0x55},
{0x62, 0x6a},
{0x63, 0xa9},
{0x64, 0x6a},
{0x65, 0xa9},
{0x66, 0x6b},
{0x67, 0xe9},
{0x68, 0x6b},
{0x69, 0xe9},
{0x6a, 0x6a},
{0x6b, 0xa9},
{0x6c, 0x6a},
{0x6d, 0xa9},
{0x6e, 0x55},
{0x6f, 0x55},

//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
{0x89, 0x7e}, 
{0x8a, 0x40}, 

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x68},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
{0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB Day  
{0x03, 0x22},
{0x11, 0x2c},

{0x80, 0x52},
{0x81, 0x20},
{0x82, 0x27},

{0x83, 0x58},
{0x84, 0x4d},
{0x85, 0x2c},
{0x86, 0x22},

//Saturation 0, EV 0
{0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness 0
{0x03, 0x13},
{0x12, 0x07},
{0x25, 0x0a},
{0x20, 0x15},
{0x21, 0x13},

{0xfe, 0x28},

{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_AGAINSTLIGHT (BACKLight??)
//==========================================================
GLOBAL const U8 reg_main_scene_againstlight[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x00},
{0xa0, 0x00},
{0xa2, 0x00},
{0xa4, 0x00},
{0xa6, 0x00},

{0x03, 0x16},
{0x70, 0x00},
{0x71, 0x08},
{0x72, 0x17},
{0x73, 0x2f},
{0x74, 0x53},
{0x75, 0x6c},
{0x76, 0x81},
{0x77, 0x94},
{0x78, 0xa4},
{0x79, 0xb3},
{0x7a, 0xc0},
{0x7b, 0xcb},
{0x7c, 0xd5},
{0x7d, 0xde},
{0x7e, 0xe6},
{0x7f, 0xee},
{0x80, 0xf4},
{0x81, 0xfa},
{0x82, 0xff},

{0x03, 0x20}, //Page 20
{0x10, 0x1c},// AE Off
{0x2e, 0x33}, //Adaptive on 13 -> 33

 //Flash OFF _Spot
{0x60, 0x00},
{0x61, 0x00},
{0x62, 0x00},
{0x63, 0x00},
{0x64, 0x00},
{0x65, 0x00},
{0x66, 0x03},
{0x67, 0xc0},
{0x68, 0x03},
{0x69, 0xc0},
{0x6a, 0x00},
{0x6b, 0x00},
{0x6c, 0x00},
{0x6d, 0x00},
{0x6e, 0x00},
{0x6f, 0x00},

//Normal condition
{0x88, 0x05}, //EXP Max 8.33 fps 
{0x89, 0x7e}, 
{0x8a, 0x40}, 

//ISO AUTO 
{0xb1, 0x0d},
{0xb2, 0x68},
{0xb3, 0x1d},
{0xb4, 0x19},
{0xb5, 0x32},
{0xb6, 0x25},
{0xb7, 0x21},
{0xb8, 0x1f},
{0xb9, 0x1e},
{0xba, 0x1d},
{0xbb, 0x1c},
{0xbc, 0x23},
{0xbd, 0x22},

{0xc1, 0x1f},
{0xc2, 0x1f},
{0xc3, 0x1f},
{0xc4, 0x08},

{0x10, 0x9c}, // AE On

//WB Auto  
{0x03, 0x22},
{0x11, 0x2e},

{0x80, 0x38},
{0x81, 0x20},
{0x82, 0x3a},

{0x83, 0x5e}, //5c
{0x84, 0x23}, //23 24
{0x85, 0x53}, //55->53
{0x86, 0x24},

//Saturation 0, EV 0
{0x03, 0x10},
{0x40, 0x00},
{0x60, 0x67}, //Saturation
{0x61, 0x79}, //B str
{0x62, 0x74}, //R str
{0x63, 0x30}, //090728 for W_gain 50->30

//Sharpness 0
{0x03, 0x13},
{0x12, 0x07},
{0x25, 0x0a},
{0x20, 0x15},
{0x21, 0x13},

{0xfe, 0x28},

{0xff, 0xff},
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_TEXT
//==========================================================
GLOBAL const U8 reg_main_scene_text[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_M2
//==========================================================
GLOBAL const U8 reg_main_adjust_contrast_m2[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_M1
//==========================================================
GLOBAL const U8 reg_main_adjust_contrast_m1[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_DEFAULT
//==========================================================
GLOBAL const U8 reg_main_adjust_contrast_default[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_P1
//==========================================================
GLOBAL const U8 reg_main_adjust_contrast_p1[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_P2
//==========================================================
GLOBAL const U8 reg_main_adjust_contrast_p2[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SHARPNESS_M2
//==========================================================
GLOBAL const U8 reg_main_adjust_sharpness_m2[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SHARPNESS_M1
//==========================================================
GLOBAL const U8 reg_main_adjust_sharpness_m1[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_DEFAULT
//==========================================================
GLOBAL const U8 reg_main_adjust_sharpness_default[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_P1
//==========================================================
GLOBAL const U8 reg_main_adjust_sharpness_p1[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_P2
//==========================================================
GLOBAL const U8 reg_main_adjust_sharpness_p2[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_M2
//==========================================================
GLOBAL const U8 reg_main_adjust_saturation_m2[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_M1
//==========================================================
GLOBAL const U8 reg_main_adjust_saturation_m1[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_DEFAULT
//==========================================================
GLOBAL const U8 reg_main_adjust_saturation_default[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_P1
//==========================================================
GLOBAL const U8 reg_main_adjust_saturation_p1[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_P2
//==========================================================
GLOBAL const U8 reg_main_adjust_saturation_p2[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_output_qqvga
//==========================================================
GLOBAL const U8 reg_main_qqvga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qcif
//==========================================================
GLOBAL const U8 reg_main_qcif[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qvga
//==========================================================
GLOBAL const U8 reg_main_qvga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_wqvga
//==========================================================
GLOBAL const U8 reg_main_wqvga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_cif
//==========================================================
GLOBAL const U8 reg_main_cif[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_vga
//==========================================================
GLOBAL const U8 reg_main_vga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_wvga 800 * 480
//==========================================================
GLOBAL const U8 reg_main_wvga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_svga
//==========================================================
GLOBAL const U8 reg_main_svga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_sxga
//==========================================================
GLOBAL const U8 reg_main_sxga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qxga
//==========================================================
GLOBAL const U8 reg_main_qxga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qxga
//==========================================================
GLOBAL const U8 reg_main_uxga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_full_yuv
//==========================================================
GLOBAL const U8 reg_main_full_yuv[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_cropped_yuv
//==========================================================
GLOBAL const U8 reg_main_crop_yuv[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

      
//==========================================================
// CAMERA_JPEG_output_5M
//==========================================================
GLOBAL const U8 reg_main_jpeg_5m[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_5M_2
//==========================================================
GLOBAL const U8 reg_main_jpeg_5m_2[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_4M
//==========================================================
GLOBAL const U8 reg_main_jpeg_w4m[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_3M
//==========================================================
GLOBAL const U8 reg_main_jpeg_3m[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_2M
//==========================================================
GLOBAL const U8 reg_main_jpeg_2m[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_w1_5M
//==========================================================
GLOBAL const U8 reg_main_jpeg_w1_5m[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_1M
//==========================================================
GLOBAL const U8 reg_main_jpeg_1m[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_VGA
//==========================================================
GLOBAL const U8 reg_main_jpeg_vga[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_WQVGA
//==========================================================
GLOBAL const U8 reg_main_jpeg_wqvga[][2]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_QVGA
//==========================================================
GLOBAL const U8 reg_main_jpeg_qvga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_qvga_v[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_half_vga_v[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_half_vga[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_vga_v[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_5M[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_1080P[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_720P[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_not[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_flicker_disabled[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_flicker_50hz[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_flicker_60hz[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_flicker_auto[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_jpeg_quality_superfine[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_jpeg_quality_fine[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_jpeg_quality_normal[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_priv_ctrl_returnpreview[][2]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//BYKIM_DTP
GLOBAL const U8 reg_main_dtp_on[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x00}, // 0 Page
{0x12, 0x05}, //  Clock Divider Pclk 1/2 Output
{0x50, 0x05}, //  DTP On
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U8 reg_main_dtp_off[][2]
#if defined(_CAMACQ_API_C_)
={
{0x03, 0x00}, // 0 Page
{0x12, 0x04}, //  Clock Divider Pclk Return Output
{0x50, 0x00}, // DTP Off
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


#undef GLOBAL

#endif /* _CAMACQ_SR200PC10_H_ */
