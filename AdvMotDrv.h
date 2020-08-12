//
// Copyright (c) Advantech Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Advantech end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//

#ifndef __ADV_MOT_DRV_H__
#define __ADV_MOT_DRV_H__

/*
+-----------------------------------------------------------------------------+
| ************ Advantech Motion Date Type Definition ************************ |
+-----------------------------------------------------------------------------+
*/
#define  U8         UCHAR
#define  U16        USHORT
#define  U32        ULONG
#define  U64        ULONGLONG 

#define  I8         CHAR
#define  I16        SHORT
#define  I32        LONG
#define  I64        LONGLONG

#define  F32        float
#define  F64        DOUBLE

#define  PU8        UCHAR*
#define  PU16       USHORT*
#define  PU32       ULONG*
#define  PU64       ULONGLONG* 

#define  PI8        CHAR*
#define  PI16       SHORT*
#define  PI32       LONG*
#define  PI64       LONGLONG*

#define  PF32       FLOAT*
#define  PF64       DOUBLE*

typedef U32 (*ADV_USER_CALLBACK_FUNC)(U32 EvtValue, PVOID UserParameter);

#ifdef _WIN64
#define LONG_PTR LONG_PTR
#define ULONG_PTR ULONG_PTR
#else
#define LONG_PTR LONG
#define ULONG_PTR ULONG
#endif

// #if defined (_AMD64_)  
// #define  HAND       U64
// #define  PHAND      U64*
// #else
// #define  HAND       U32
// #define  PHAND      U32*
// #endif

#define	 HAND			UINT_PTR
#define	 PHAND			UINT_PTR*
#ifndef  ULONG_PTR
#define  ULONG_PTR  unsigned   long*
#endif


/*
+-----------------------------------------------------------------------------+
| ********************** Physical Axis Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define 		X_AXIS  						0
#define 		Y_AXIS  						1
#define 		Z_AXIS  						2
#define 		U_AXIS  						3
#define         A_AXIS                          4  //[Dan.Yang 2011.03.10]
#define         B_AXIS                          5  //[Dan.Yang 2011.03.10]
/*+-----------------------------------------------------------------------------+
| ******************** Settings' Limit  *************************** |
+-----------------------------------------------------------------------------+
*/

/*
+-----------------------------------------------------------------------------+
| ********************** GMCode Axis Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define 		GM_AXIS_X  						1
#define 		GM_AXIS_Y  						2
#define 		GM_AXIS_Z  						4
#define 		GM_AXIS_A  						8
#define         GM_AXIS_B                       16
#define         GM_AXIS_C                       32
#define 		GM_AXIS_X1  					64
#define 		GM_AXIS_Y1  					128
/*+-----------------------------------------------------------------------------+
| ******************** Settings' Limit  *************************** |
+-----------------------------------------------------------------------------+
*/

#ifdef PCI1244
#define MAX_RATE       150
#define MIN_RATE       0
#define MAX_R          4096
#define MIN_R          0
#define MAX_V          32767
#define MIN_V          1
#define MAX_D          65535
#define MIN_D          1
#define MAX_A          65535
#define MIN_A          1
#define MAX_K          65535
#define MIN_K          1
#define MAX_PULSE      268435455
#define MIN_PULSE      0
#define MAX_POSITION   268435455
//#define MIN_POSITION   -2147483648
#define MIN_POSITION  MAX_POSITION*(-1)-1
#else
#define MAX_RATE       500
#define MIN_RATE       1
#define MAX_R          8000000
#define MIN_R          16000
#define MAX_V          8000
#define MIN_V          1
#define MAX_D          8000
#define MIN_D          1
#define MAX_A          8000
#define MIN_A          1
#define MAX_K          65535
#define MIN_K          1
#define MAX_PULSE      268435455
#define MIN_PULSE      0
#define MAX_POSITION   2147483647
//#define MIN_POSITION   -2147483648
#define MIN_POSITION  MAX_POSITION*(-1)-1
#endif

#define		NOT_DEFINE		0xffffffff

#define	  MAX_CMPPULSEWIDTH  85899345
/*
+-----------------------------------------------------------------------------+
| ******************** Device Function Map Define *************************** |
+-----------------------------------------------------------------------------+
*/
#define     DEV_FUNC_MOT                0x001
#define     DEV_FUNC_DI                 0x002
#define     DEV_FUNC_DO                 0x004
#define     DEV_FUNC_AI                 0x008
#define     DEV_FUNC_AO                 0x010
#define     DEV_FUNC_TMR                0x020
#define     DEV_FUNC_CNT                0x040
#define     DEV_FUNC_DAQDI              0x080
#define     DEV_FUNC_DAQDO              0x100
#define     DEV_FUNC_DAQAI              0x200
#define     DEV_FUNC_DAQAO              0x400
#define     DEV_FUNC_EMG                0x800
#define     DEV_FUNC_MDAQ				0x1000	
     
/*
+-----------------------------------------------------------------------------+
| **************** Device Interpolation Type Map Define ********************* |
+-----------------------------------------------------------------------------+
*/
#define     DEV_IPO_LINE_2AX  			0x01
#define     DEV_IPO_LINE_3AX  			0x02
//////////////////////////////////////////////////////////////////////////
//ydd:add for pci1265.20110309
#define     DEV_IPO_LINE_4AX			0x04
#define     DEV_IPO_LINE_5AX			0x08
#define     DEV_IPO_LINE_6AX			0x10
#define     DEV_IPO_LINE_7AX			0x20
#define     DEV_IPO_LINE_8AX			0x40
//////////////////////////////////////////////////////////////////////////
#define     DEV_IPO_ARC_2AX   			0x0100
#define     DEV_IPO_ARC_3AX   			0x0200
#define     DEV_IPO_SPIRAL				0x0400 //  [6/20/2011 dan.yang]
#define     DEV_IPO_BLENDING   			0x0800
#define     DEV_IPO_SPEED_FORWARD		0x1000
#define     DEV_IPO_DO_CONTROL   		0x2000
#define     DEV_IPO_GEAR				0x00010000 //  [9/14/2011 dan.yang]
#define     DEV_IPO_CAM					0x00020000 //  [9/14/2011 dan.yang]
#define     DEV_IPO_GANTRY				0x00040000 //  [9/14/2011 dan.yang]
#define     DEV_IPO_TANGENT				0x00080000 //  [9/14/2011 dan.yang]
#define     DEV_IPO_SELPTH				0x01000000 //  [9/14/2011 dan.yang]
/*
+-----------------------------------------------------------------------------+
| ********************* Axis Feature Map Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_FUNC_INP         		0x01
#define     AX_FUNC_ALM					0x02
#define     AX_FUNC_ERC					0x04
#define     AX_FUNC_SD					0x08
#define     AX_FUNC_EL					0x10
#define     AX_FUNC_SW_EL				0x20
#define     AX_FUNC_ORG					0x40
#define     AX_FUNC_EZ					0x80
#define     AX_FUNC_BACKLASH_CORRECT	0x0100
#define     AX_FUNC_SUPPRESS_VIBRATION	0x0200
#define     AX_FUNC_HOME				0x0400
#define     Ax_FUNC_IMPOSE				0x0800  //  [9/14/2011 dan.yang]
#define     Ax_FUNC_CMP					0x1000  //  [9/14/2011 dan.yang]
#define     Ax_FUNC_LATCH				0x2000  //  [9/14/2011 dan.yang]
#define     Ax_FUNC_CAMDO				0x4000  //  [9/14/2011 dan.yang]
#define     Ax_FUNC_EXTDRV				0x8000  //  [9/14/2011 dan.yang]
#define     Ax_FUNC_SIMSTART			0x010000  //  [9/14/2011 dan.yang]
#define     AX_FUNC_IN1_STOP			0x020000  //  [12/15/2012 dan.yang]
#define     AX_FUNC_IN2_STOP			0x040000  //  [12/15/2012 dan.yang]
#define     AX_FUNC_IN3_STOP			0x080000  //  [12/15/2012 dan.yang]
#define     AX_FUNC_IN4_STOP			0x100000  //  [12/15/2012 dan.yang]
#define     AX_FUNC_IN5_STOP			0x200000  //  [12/15/2012 dan.yang]
#define 	AX_FUNC_MAXTOR_LMT			0x400000

#define     LtcStopEnable				0x100
#define     LtcStopReact				0x200
/*
+-----------------------------------------------------------------------------+
| ******************** Axis Pulse In Map Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_PI_MODE					1
#define     AX_PI_LOGIC 				2
#define     AX_PI_SOURCE 				4	
/*
+-----------------------------------------------------------------------------+
| ******************* Axis Pulse In Mode Map Define ************************* |
+-----------------------------------------------------------------------------+
*/
#define     AX_PIM_1XAB 				1
#define     AX_PIM_2XAB 				2
#define     AX_PIM_4XAB 				4
#define     AX_PIM_CWCCW 				8
/*
+-----------------------------------------------------------------------------+
| ******************* Axis Pulse Out Map Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_PO_MODE 					1
#define     AX_PO_PIN_REVERSE			2
/*
+-----------------------------------------------------------------------------+
| ******************* Axis Pulse Out Mode Map Define ************************ |
+-----------------------------------------------------------------------------+
*/
#define     AX_POM_OUT_DIR 				1
#define     AX_POM_OUT_DIR_OUTNEG		2
#define     AX_POM_OUT_DIR_DIRNEG		4
#define     AX_POM_OUT_DIR_ALLNEG		8
#define     AX_POM_CW_CCW 				16
#define     AX_POM_CW_CCW_ALLNEG		32
#define     AX_POM_AB					64
#define     AX_POM_BA					128
#define     AX_POM_CW_CCW_OUTNEG		256
#define     AX_POM_CW_CCW_DIRNEG		512
/*
+-----------------------------------------------------------------------------+
| *********************** Axis Alarm Map Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_ALM_EN					1
#define     AX_ALM_LOGIC				2
#define     AX_ALM_REACT				4
/*
+-----------------------------------------------------------------------------+
| ********************** Axis InPosition Map Define ************************* |
+-----------------------------------------------------------------------------+
*/
#define     AX_INP_EN					1
#define     AX_INP_LOGIC				2	
/*
+-----------------------------------------------------------------------------+
| *********************** Axis ERC Map Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define     AX_ERC_EN_MODE				1
#define     AX_ERC_LOGIC				2
#define     AX_ERC_ON_TIME				4
#define     AX_ERC_OFF_TIME				8
/*
+-----------------------------------------------------------------------------+
| *********************** Axis SD Map Define ******************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_SD_EN					1
#define     AX_SD_LOGIC					2
#define     AX_SD_REACT					4
#define     AX_SD_LATCH					8
/*
+-----------------------------------------------------------------------------+
| ***************** Axis Hardware Limit Map Define ************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_EL_EN					0x1
#define     AX_EL_LOGIC					0x2
#define     AX_EL_REACT					0x4	
#define  	AX_ELTolerance				0x08
#define     AX_EL_PELLOGIC	    		0x10
#define     AX_EL_MELLOGIC	    		0x20
/*
+-----------------------------------------------------------------------------+
| ************** Axis Software Minus Limit Map Define *********************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_SW_MEL_EN				1
#define     AX_SW_MEL_REACT				2
#define     AX_SW_MEL_VALUE				4	
#define     AX_SW_MELTolerance			8
/*
+-----------------------------------------------------------------------------+
| ************** Axis Software Plus Limit Map Define ************************ |
+-----------------------------------------------------------------------------+
*/
#define     AX_SW_PEL_EN				1
#define     AX_SW_PEL_REACT				2
#define     AX_SW_PEL_VALUE				4
#define     AX_SW_PELTolerance			8

/*
+-----------------------------------------------------------------------------+
| ******************** Axis Home Map Define ********************************* |
+-----------------------------------------------------------------------------+
*/
#define     AX_HM_MODE					0x01
#define     AX_HM_ORG_LOGIC				0x02
#define     AX_HM_EZ_LOGIC				0x04
#define     AX_HM_RESET_EN				0x08  //  [9/14/2011 dan.yang]
#define     AX_HM_ORG_REACT				0x10  //  [12/27/2011 dan.yang]
#define     AX_HM_OFFSET         		0x20
#define     AX_HM_SPEED         		0x40
/*
+-----------------------------------------------------------------------------+
| ******************** Axis Compare Map Define ****************************** |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define     AX_CMP_EN					0x01
#define     AX_CMP_LOGIC				0x02
#define     AX_CMP_SRC					0x04
#define     AX_CMP_METHOD				0x08
#define     AX_CMP_PULSE_MODE			0x10
#define     AX_CMP_PULSE_WIDTH			0x20
/*
+-----------------------------------------------------------------------------+
| ******************** Axis Latch Map Define ******************************** |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define     AX_LATCH_EN					0x01
#define     AX_LATCH_LOGIC				0x02
#define     AX_LATCH_BUF_EN				0x04
//  [3/6/2013 dan.yang]:Add for latch buffer
#define     AX_LATCH_BUF_MINDST			0x08
#define     AX_LATCH_BUF_EVTNUM			0x10
#define     AX_LATCH_BUF_SRC			0x20
#define     AX_LATCH_BUF_AXID			0x40
#define     AX_LATCH_BUF_EDGE			0x80
/*
+-----------------------------------------------------------------------------+
| ******************** Axis Cam DO Map Define ******************************* |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define     AX_CAMDO_EN					0x01
#define     AX_CAMDO_LOGIC				0x02
#define     AX_CAMDO_CMP_SRC			0x04
#define     AX_CAMDO_LOW_LIMIT			0x08
#define     AX_CAMDO_HIGH_LIMIT			0x10
#define     AX_CAMDO_MODE				0x20
#define     AX_CAMDO_DIR				0x40
#define     AX_CAMDO_ASSIGN				0x80
/*
+-----------------------------------------------------------------------------+
| ******************* Axis External Drive Map Define ************************ |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define     AX_EXT_MASTER_SRC           0x01
#define     AX_EXT_SEL_EN               0x02
#define     AX_EXT_PULSE_Num            0x04
#define     AX_EXT_PULSE_IN_MODE        0x08
#define     AX_EXT_PRESET_NUM           0x10
/*
+-----------------------------------------------------------------------------+
| **************** Axis External Master Source Map Define ******************* |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define     ExtSrcAxis0					0x01
#define     ExtSrcAxis1					0x02
#define     ExtSrcAxis2					0x04
#define     ExtSrcAxis3					0x08
/*
+-----------------------------------------------------------------------------+
| ************* Axis Simultaneous Start/Stop source Map Define ************** |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define		SimSrc_Disable				0x000000
#define		SimSrc_STA					0x000001
#define		SimSrc_TRIGP_AX0			0x000100
#define		SimSrc_TRIGP_AX1			0x000200
#define		SimSrc_TRIGP_AX2			0x000400
#define		SimSrc_TRIGP_AX3			0x000800
#define		SimSrc_TRIGP_AX4			0x001000
#define		SimSrc_TRIGP_AX5			0x002000
#define		SimSrc_TRIGP_AX6			0x004000
#define		SimSrc_TRIGP_AX7			0x008000
#define		SimSrc_STOP_AX0				0x010000
#define		SimSrc_STOP_AX1				0x020000
#define		SimSrc_STOP_AX2				0x040000
#define		SimSrc_STOP_AX3				0x080000
#define		SimSrc_STOP_AX4				0x100000
#define		SimSrc_STOP_AX5				0x200000
#define		SimSrc_STOP_AX6				0x400000
#define		SimSrc_STOP_AX7				0x800000
/*
+-----------------------------------------------------------------------------+
| ******************** Axis Gen_DO Map Define ********************************* |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define		OUT4oCAM_DO					0x01
#define		OUT5oTRIG_P					0x02
#define		OUT6oSVON					0x04
#define		OUT7oERC					0x08	
/*
+-----------------------------------------------------------------------------+
| ******************** Axis Gen_DI Start/Stop Mode Map Define ********************************* |  //  [9/14/2011 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define		IN1oLTC						0x01
#define		IN2oRDY						0x02
#define		IN3oJOG_P					0x04
#define		IN4oJOG_M					0x08	

/*
+-----------------------------------------------------------------------------+
| ******************** Axis IN1~IN5 Stop Map Define ********************************* | //  [12/15/2012 dan.yang]
+-----------------------------------------------------------------------------+
*/
#define		IN_STOP_ENABLE				0x01
#define		IN_STOP_LOGIC				0x02
#define		IN_STOP_REACT				0x04
/*
+-----------------------------------------------------------------------------+
+-----------------------------------------------------------------------------+
*/
/*
+-----------------------------------------------------------------------------+
| ******************** Pulse In Mode Define ********************************* |
+-----------------------------------------------------------------------------+
*/
#define		AB_1X 						0
#define		AB_2X 						1
#define		AB_4X 						2
#define		I_CW_CCW 					3
#define		I_PULSE_DIR 				4
/*
+-----------------------------------------------------------------------------+
| ******************** Pulse In Logic Define ******************************** |
+-----------------------------------------------------------------------------+
*/
#define		NO_INV_DIR 					0
#define		INV_DIR 					1
/*
+-----------------------------------------------------------------------------+
| ******************** Pulse In Source Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define		EXTERNAL_FEEBACK			0
#define		COMMAND_PULSE 				1
/*
+-----------------------------------------------------------------------------+
| ******************** Pulse Out Mode Define ******************************** |
+-----------------------------------------------------------------------------+
*/
#define     OUT_DIR  					0x01
#define     OUT_DIR_OUT_NEG 			0x02
#define		OUT_DIR_DIR_NEG 			0x04
#define     OUT_DIR_ALL_NEG 			0x08
#define		O_CW_CCW 					0x10
#define     CW_CCW_ALL_NEG 				0x20
#define		AB_PHASE 					0x40
#define		BA_PHASE 					0x80
#define		CW_CCW_OUT_NEG				0x100
#define		CW_CCW_DIR_NEG				0x200

/*
+-----------------------------------------------------------------------------+
| ******************** Pulse Out Pin Reverse Define ************************* |
+-----------------------------------------------------------------------------+
*/
#define     PULSE_OUT_PIN_NORMAL  		0x00
#define     PULSE_OUT_PIN_REVERSE 		0x01

/*
+-----------------------------------------------------------------------------+
| ******************** Alarm Enable Define ********************************** |
+-----------------------------------------------------------------------------+
*/
#define     ALM_DIS 					0
#define     ALM_EN 						1
/*
+-----------------------------------------------------------------------------+
| ******************** Alarm Logic Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     ALM_ACT_LOW 				0
#define     ALM_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ******************** Alarm React Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     ALM_IMMED_STOP				0
#define     ALM_DEC_TO_STOP 			1
/*
+-----------------------------------------------------------------------------+
| ************************ Device Error Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define		ERR_ACT_DISABLE				0
#define		ERR_IMMED_STOP				1
#define		ERR_DEC_TO_STOP				2
/*
+-----------------------------------------------------------------------------+
| ******************** Inposition Enable Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define    INP_DIS 						0
#define	   INP_EN 						1
/*
+-----------------------------------------------------------------------------+
| ******************** Inposition Logic Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define    INP_ACT_LOW 					0
#define	   INP_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ************************** SD Enable Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define     SD_ENABLE 					0
#define	    SD_DISABLE 					1
/*
+-----------------------------------------------------------------------------+
| ************************* SD Latch Define ********************************* |
+-----------------------------------------------------------------------------+
*/
#define     SD_LEVEL 					0
#define	    SD_LATCH 					1
/*
+-----------------------------------------------------------------------------+
| ************************* SD Logic Define ********************************* |
+-----------------------------------------------------------------------------+
*/
#define     SD_ACT_LOW 					0
#define	    SD_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| *********************** SD React Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     SD_IMMED_STOP				1
#define     SD_DEC_AND_STOP 			0
/*
+-----------------------------------------------------------------------------+
| ****************** Hardware Limit Enable Define *************************** |
+-----------------------------------------------------------------------------+
*/
#define     HLMT_DIS 					0
#define	    HLMT_EN 					1
/*
+-----------------------------------------------------------------------------+
| ************************** Out Logic Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define     OUT_ACT_LOW 				0
#define		OUT_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ************************ Dir Logic Define ********************************* |
+-----------------------------------------------------------------------------+
*/
#define     DIR_ACT_LOW 				0
#define		DIR_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ************************* Erc Logic Define ******************************** |
+-----------------------------------------------------------------------------+
*/
#define	    ERC_DIS 					0
#define     ERC_EN 						1
/*
+-----------------------------------------------------------------------------+
| ************************* Erc Timer Define ******************************** |
+-----------------------------------------------------------------------------+
*/
#define	    ERC_OFF_TIME_DIS 			0
#define     ERC_OFF_TIME_EN 			1
/*
+-----------------------------------------------------------------------------+
| ****************** Hardware Limit Enable Define *************************** |
+-----------------------------------------------------------------------------+
*/
#define		HLMT_DIS 					0
#define		HLMT_EN 					1
/*
+-----------------------------------------------------------------------------+
| ****************** Hardware Limit Logic Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     HLMT_ACT_LOW 				0
#define		HLMT_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ****************** Hardware Limit React Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     HLMT_IMMED_STOP 			0
#define		HLMT_DEC_TO_STOP 			1

/*
+-----------------------------------------------------------------------------+
| ****************** IN Disable or Enable Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define		IN_DISABLE					0
#define		IN_ENABLE					1
/*
+-----------------------------------------------------------------------------+
| ****************** Software Limit Enable Define *************************** |
+-----------------------------------------------------------------------------+
*/
#define     SLMT_DIS 					0
#define		SLMT_EN 					1
/*
+-----------------------------------------------------------------------------+
| ****************** Software Limit React Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     SLMT_IMMED_STOP 			0
#define		SLMT_DEC_TO_STOP 			1
/*
+-----------------------------------------------------------------------------+
| ************************** ORG React Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define     ORG_IMMED_STOP 				0
#define		ORG_DEC_TO_STOP 			1

/*
+-----------------------------------------------------------------------------+
| ****************** Ax General DO¡¡Enable Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     GEN_DO_DISABLE 				0
#define		GEN_DO_ENABLE 				1
/*
+-----------------------------------------------------------------------------+
| ****************** Ax External Master Source Define ************************ |
+-----------------------------------------------------------------------------+
*/
#define		EXT_MASTER_SRC_AX_0			0
#define		EXT_MASTER_SRC_AX_1 		1
#define		EXT_MASTER_SRC_AX_2			2
#define		EXT_MASTER_SRC_AX_3 		3
#define		EXT_MASTER_SRC_SELF 		4
/*
+-----------------------------------------------------------------------------+
| ****************** Ax External Drive Mode ************************ |
+-----------------------------------------------------------------------------+
*/
#define		EXT_DRIVE_DISABLE			0
#define		EXT_DRIVE_JOG 	     		1
#define		EXT_DRIVE_MPG				2
#define		EXT_DRIVE_MPG_CONT			3
#define		EXT_DRIVE_MPG_PRESETP		4
#define		EXT_DRIVE_MPG_PRESETN		5
/*
+-----------------------------------------------------------------------------+
| ********************* ORG Enable Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     ORG_DISABLE 				0
#define		ORG_ENABLE 					1
/*
+-----------------------------------------------------------------------------+
| ********************* ORG Logic Define ************************************ |
+-----------------------------------------------------------------------------+
*/
#define     ORG_ACT_LOW 				0
#define		ORG_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ********************* ORG Latch Define ************************************ |
+-----------------------------------------------------------------------------+
*/
#define     ORG_LEVEL 					1
#define		ORG_LATCH 					0
/*
+-----------------------------------------------------------------------------+
| ********************** EZ Enable Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     EZ_DISABLE 					0
#define		EZ_ENABLE 					1
/*
+-----------------------------------------------------------------------------+
| ********************** EZ Logic Define ************************************ |
+-----------------------------------------------------------------------------+
*/
#define     EZ_ACT_LOW 					0
#define		EZ_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ********************** In1 Enable Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     IN1_DISABLE 				0
#define		IN1_ENABLE 					1
/*
+-----------------------------------------------------------------------------+
| ********************** IN1 Logic Define ************************************ |
+-----------------------------------------------------------------------------+
*/
#define     IN1_ACT_LOW 				0
#define		IN1_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ********************** In2 Enable Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     IN2_DISABLE 				0
#define		IN2_ENABLE 					1
/*
+-----------------------------------------------------------------------------+
| ********************** IN2 Logic Define ************************************ |
+-----------------------------------------------------------------------------+
*/
#define     IN2_ACT_LOW 				0
#define		IN2_ACT_HIGH 				1
/*
+-----------------------------------------------------------------------------+
| ********************** Servo State Define ********************************* |
+-----------------------------------------------------------------------------+
*/
#define     SV_OFF						0
#define     SV_ON 						1
/*
+-----------------------------------------------------------------------------+
| ********************** Motion Axis State Define *************************** |
+-----------------------------------------------------------------------------+
*/
#define     STA_AX_DISABLE				0
#define     STA_AX_READY 				1
#define     STA_AX_STOPPING 			2
#define     STA_AX_ERROR_STOP 			3
#define     STA_AX_HOMING 				4
#define     STA_AX_PTP_MOT 				5
#define     STA_AX_CONTI_MOT 			6
#define     STA_AX_SYNC_MOT 			7
#define     STA_AX_EXT_JOG 				8
#define     STA_AX_EXT_MPG				9
#define     STA_AX_PAUSE				10 //  [5/16/2013 dan.yang]
#define     STA_AX_BUSY					11 //  [5/16/2013 dan.yang]
#define     STA_AX_WAIT_DI				12
#define		STA_AX_WAIT_PTP				13 
#define		STA_AX_WAIT_VEL				14
/*
+-----------------------------------------------------------------------------+
| ********************** Motion Group State Define ************************** |
+-----------------------------------------------------------------------------+
*/
#define     STA_GP_DISABLE				0
#define		STA_GP_READY				1
#define		STA_GP_STOPPING				2
#define		STA_GP_ERROR_STOP			3
#define		STA_GP_MOTION				4
#define		STA_GP_AX_MOTION			5
#define		STA_GP_MOTION_PATH			6
#define     STA_GP_PAUSE				7              //  [5/7/2013 dan.yang]
#define     STA_GP_BUSY					8              //  [5/15/2013 dan.yang]
#define     WIN_STA_GP_EXT_JOG          9      //JOG mode  [7/11/2014 kai.yang]
#define     WIN_STA_GP_EXT_MPG          10     //mpg mode  [7/11/2014 kai.yang]
#define     WIN_STA_GP_EXT_JOG_MOVING   11     //JOG moving[7/11/2014 kai.yang]

/*
+-----------------------------------------------------------------------------+
| ********************** Motion Group State Define ************************** |//zhaocui add 201308
+-----------------------------------------------------------------------------+
*/
#define     STA_RB_DISABLE				0
#define		STA_RB_READY				1
#define		STA_RB_STOPPING				2
#define		STA_RB_ERROR_STOP			3
#define		STA_RB_MOTION				4
#define		STA_RB_AX_MOTION			5
#define		STA_RB_MOTION_PATH			6
#define     STA_RB_PAUSE				7 
#define     STA_RB_BUSY					8 
#define     WIN_STA_RB_EXT_JOG			9
#define     WIN_STA_RB_EXT_MPG			10
#define     WIN_STA_RB_EXT_JOG_MOVING   11     
/*
+-----------------------------------------------------------------------------+
| ****************** Velocity Move Direction Define ************************* |
+-----------------------------------------------------------------------------+
*/
#define     DIR_POSITIVE				0
#define     DIR_NEGATIVE 				1
/*
+-----------------------------------------------------------------------------+
| ********************* Motion Home Mode Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define     AbsSwitch					0
#define		LmtSwitch					1
#define		RefPulse					2
#define		Direct						3

#define		MODE1_Abs					0 
#define		MODE2_Lmt					1
#define		MODE3_Ref					2
#define		MODE4_Abs_Ref				3
#define		MODE5_Abs_NegRef			4
#define		MODE6_Lmt_Ref				5
#define		MODE7_AbsSearch				6
#define		MODE8_LmtSearch				7
#define		MODE9_AbsSearch_Ref			8
#define	    MODE10_AbsSearch_NegRef		9
#define	    MODE11_LmtSearch_Ref		10
#define	    MODE12_AbsSearchReFind			11 //  [6/13/2012 dan.yang]
#define	    MODE13_LmtSearchReFind			12 //  [6/13/2012 dan.yang]
#define	    MODE14_AbsSearchReFind_Ref		13 //  [6/13/2012 dan.yang]
#define	    MODE15_AbsSearchReFind_NegRef	14 //  [6/13/2012 dan.yang]
#define	    MODE16_LmtSearchReFind_Ref		15 //  [6/13/2012 dan.yang]
#define     MODE17_AbsSearchReFindFixORG    16  //2016.5.6. Add for jinghui.

#define     CiA402_MODE1				101
#define     CiA402_MODE2				102
#define     CiA402_MODE3				103
#define     CiA402_MODE4				104
#define     CiA402_MODE5				105
#define     CiA402_MODE6				106
#define     CiA402_MODE7				107
#define     CiA402_MODE8				108
#define     CiA402_MODE9				109
#define     CiA402_MODE10				110
#define     CiA402_MODE11				111
#define     CiA402_MODE12				112
#define     CiA402_MODE13				113
#define     CiA402_MODE14				114
#define     CiA402_MODE15				115
#define     CiA402_MODE16				116
#define     CiA402_MODE17				117
#define     CiA402_MODE18				118
#define     CiA402_MODE19				119
#define     CiA402_MODE20				120
#define     CiA402_MODE21				121
#define     CiA402_MODE22				122
#define     CiA402_MODE23				123
#define     CiA402_MODE24				124
#define     CiA402_MODE25				125
#define     CiA402_MODE26				126
#define     CiA402_MODE27				127
#define     CiA402_MODE28				128
#define     CiA402_MODE29				129
#define     CiA402_MODE30				130
#define     CiA402_MODE31				131
#define     CiA402_MODE32				132
#define     CiA402_MODE33				133
#define     CiA402_MODE34				134
#define     CiA402_MODE35				135
#define     CiA402_MODE36				136
#define     CiA402_MODE37				137

/*
+-----------------------------------------------------------------------------+
| *************************** DI Filter Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define 	MP_ALM_FILTER 				0x0001
#define 	MP_LMTP_FILTER 				0x0002
#define 	MP_LMTN_FILTER 				0x0004
#define 	MP_IN1_LTC_FILTER 			0x0008
#define 	MP_IN2_RDY_FILTER			0x0010
#define 	MP_IN3_ORG_FILTER			0x0020
#define 	MP_IN4_JOGP_FILTER			0x0040
#define 	MP_IN5_JOGN_FILTER			0x0080

/*
+-----------------------------------------------------------------------------+
| ****************** Motion Home Direction Mode Define ********************** |
+-----------------------------------------------------------------------------+
*/
#define		PosiDir						0
#define		NegDir						1
#define		SwitchPosi					2
#define		SwitchNeg					3
/*
+-----------------------------------------------------------------------------+
| ********************* Motion Home Switch Mode Define ********************** |
+-----------------------------------------------------------------------------+
*/
#define     LevelOn						0
#define		LevelOff					1
#define		EdgeOn						2
#define		EdgeOff						3
/*
+-----------------------------------------------------------------------------+
| ********************* Motion HomeEx Steps Define ********************** |
+-----------------------------------------------------------------------------+
*/
#define		HomeStep0					0
#define		HomeStep1					1
#define		HomeStep2					2
#define		HomeStep3					3
#define		HomeStep4					4
#define		HomeStep5					5
#define		HomeStep6					6
/*
+-----------------------------------------------------------------------------+
| ***************** Arc Interpolation Direction Define ********************** |
+-----------------------------------------------------------------------------+
*/
#define     DIR_CW						0
#define     DIR_CCW 					1
/*
+-----------------------------------------------------------------------------+
| ***************** Compare Source Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     SRC_COMMAND_POSITION        0
#define     SRC_ACTUAL_POSITION 		1
#define     SRC_ORG_POSITION          	2
#define     SRC_LMTP_POSITION 			3
#define     SRC_LMTN_POSITION           4
#define     SRC_EZ_POSITION 			5

/*
+-----------------------------------------------------------------------------+
| ***************** Compare Pulse mode Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define     CMP_PULSE                   0
#define     CMP_TOGGLE 			        1
#define     CMP_PWM                     2
#define     CMP_PWM_TOGGLE			    3
/*
+-----------------------------------------------------------------------------+
| ***************** Compare Enable Define *********************************** |
+-----------------------------------------------------------------------------+
*/
#define     CMP_ENABLE                  1
#define     CMP_DISABLE		            0
/*
+-----------------------------------------------------------------------------+
| ***************** Compare Pulse Logic Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define     CP_ACT_LOW                  0
#define     CP_ACT_HIGH 			    1
/*
+-----------------------------------------------------------------------------+
| ***************** Compare Pulse Width Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define     CP_5US						0
#define     CP_10US						1
#define     CP_20US						2
#define     CP_50US						3
#define     CP_100US					4
#define     CP_200US					5
#define     CP_500US					6
#define     CP_1000US					7
/*
+-----------------------------------------------------------------------------+
| ************************* Compare Method Define ****************************|
+-----------------------------------------------------------------------------+
*/
#define     MTD_GREATER_POSITION        0
#define     MTD_SMALLER_POSITION 		1
#define     MTD_DIRECTIONLESS 			2
#define     MTD_UNDEFINED               3 //  [4/13/2012 dan.yang]
/*

+-----------------------------------------------------------------------------+
| ************************* Event Type Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define     EVT_DEV_DISCONNET			0x01 //  [11/25/2014 dan]
#define     EVT_DEV_IO_DISCONNET		0x02 //  [07/03/2015 andy.wang]
#define		EVT_DEV_MODE_CHANGE			0x04
#define		EVT_DEV_IO_MODE_CHANGE 		0x08
#define		EVT_DEV_LOST_FRAME			0x10
#define		EVT_DEV_IO_LOST_FRAME		0x20
#define		EVT_DEV_LOST_FRAME_WARN		0x40
#define		EVT_DEV_IO_LOST_FRAME_WARN	0x80
#define		EVT_DEV_COMM_RECOVERY		0x100
#define		EVT_DEV_IO_COMM_RECOVERY	0x200

#define     AX_MOTION_DONE				0x80
#define     AX_COMPARE					0x1E
#define     EVT_NO_EVENT				0x00
#define     EVT_AX_MOTION_DONE			0x01
#define     EVT_AX_COMPARED				0x02
#define     EVT_AX_LATCHED				0x04     //  [Dan.Yang 2011.07.26]
#define     EVT_AX_ERROR				0x08     //  [12/14/2012 dan.yang]
#define     EVT_AX_VH_START				0x10	 //  [6/13/2012 dan.yang]
#define     EVT_AX_VH_END				0x20	 //  [6/13/2012 dan.yang]
#define     EVT_AX_LATCHBUF_DONE		0x40     //  [3/6/2013 dan.yang]
#define		EVT_AX_GEAR_IN				0x80	 //  [2016.05.11 andy.wang]
#define		EVT_AX_COMMUNICATION_ERROR	0x100	 //  [2017.03.24 andy.wang]
//Axis 0 event info.
#define EVT_DEV_LTCCH0               (0x1<<8)
#define EVT_DEV_LTCCH1               (0x1<<9)
#define EVT_DEV_LTCCH2               (0x1<<10)
#define EVT_DEV_LTCCH3               (0x1<<11)
#define EVT_DEV_LTCCH4               (0x1<<12)
#define EVT_DEV_LTCCH5               (0x1<<13)
#define EVT_DEV_LTCCH6               (0x1<<14)
#define EVT_DEV_LTCCH7               (0x1<<15)
#define EVT_DEV_LTCCH8               (0x1<<16)
#define EVT_DEV_LTCCH9               (0x1<<17)
#define EVT_DEV_LTCCH10             (0x1<<18)
#define EVT_DEV_LTCCH11             (0x1<<19)
 
#define EVT_DEV_CMPCH0             (0x1<<20)
#define EVT_DEV_CMPCH1             (0x1<<21)
#define EVT_DEV_CMPCH2             (0x1<<22)
#define EVT_DEV_CMPCH3             (0x1<<23)
#define EVT_DEV_CMPCH4             (0x1<<24)
#define EVT_DEV_CMPCH5             (0x1<<25)
#define EVT_DEV_CMPCH6             (0x1<<26)
#define EVT_DEV_CMPCH7             (0x1<<27)
#define EVT_DEV_CMPCH8             (0x1<<28)
#define EVT_DEV_CMPCH9             (0x1<<29)
#define EVT_DEV_CMPCH10           (0x1<<30)
#define EVT_DEV_CMPCH11           (0x1<<31)
//axis end.

//axis 1 event info
#define EVT_DEV_LTCCH12				(0x1<<8)
#define EVT_DEV_LTCCH13				(0x1<<9)
#define EVT_DEV_LTCCH14				(0x1<<10)
#define EVT_DEV_LTCCH15				(0x1<<11)

#define EVT_DEV_CMPCH12				(0x1<<20)
#define EVT_DEV_CMPCH13				(0x1<<21)
#define EVT_DEV_CMPCH14				(0x1<<22)
#define EVT_DEV_CMPCH15				(0x1<<23)
//axis 1 end.

#define     EVT_GP_MOTION_DONE			0x02
#define     EVT_GP1_MOTION_DONE			0x01     // done event of GroupID 1
#define     EVT_GP2_MOTION_DONE			0x02     // done event of GroupID 2
#define     EVT_GP3_MOTION_DONE			0x04     // done event of GroupID 3
#define     EVT_GP4_MOTION_DONE			0x08
#define     EVT_GP5_MOTION_DONE			0x10
#define     EVT_GP6_MOTION_DONE			0x20

//Start High Speed
#define     EVT_GP1_VH_START			0x01  
#define     EVT_GP2_VH_START			0x02  
#define     EVT_GP3_VH_START			0x04
#define     EVT_GP4_VH_START			0x08 
#define     EVT_GP5_VH_START			0x10
#define     EVT_GP6_VH_START			0x20 

//Start deceleration
#define     EVT_GP1_VH_END				0x01  
#define     EVT_GP2_VH_END				0x02
#define     EVT_GP3_VH_END				0x04
#define     EVT_GP4_VH_END				0x08
#define     EVT_GP5_VH_END				0x10
#define     EVT_GP6_VH_END				0x20

#define     EVT_CANCELED				0x10
#define     EVT_TIMEOUT					0xFFFF

enum  EVENT_TYPE
          {     
              TYPE_DISABLED,
				  
              TYPE_X_PULSE,
			  TYPE_X_GREATER_COMP_NEG, 
			  TYPE_X_LESS_COMP_NEG, 
			  TYPE_X_LESS_COMP_POS, 
			  TYPE_X_GREATER_COMP_POS, 
			  TYPE_X_C_END,
			  TYPE_X_C_STA,
			  TYPE_X_D_END,

			  TYPE_Y_PULSE,
			  TYPE_Y_GREATER_COMP_NEG, 
			  TYPE_Y_LESS_COMP_NEG, 
			  TYPE_Y_LESS_COMP_POS, 
			  TYPE_Y_GREATER_COMP_POS, 
			  TYPE_Y_C_END,
			  TYPE_Y_C_STA,
			  TYPE_Y_D_END,

			  TYPE_Z_PULSE,
			  TYPE_Z_GREATER_COMP_NEG, 
			  TYPE_Z_LESS_COMP_NEG, 
			  TYPE_Z_LESS_COMP_POS, 
			  TYPE_Z_GREATER_COMP_POS, 
			  TYPE_Z_C_END,
			  TYPE_Z_C_STA,
			  TYPE_Z_D_END,

			  TYPE_U_PULSE,
			  TYPE_U_GREATER_COMP_NEG, 
			  TYPE_U_LESS_COMP_NEG, 
			  TYPE_U_LESS_COMP_POS, 
			  TYPE_U_GREATER_COMP_POS, 
			  TYPE_U_C_END,
			  TYPE_U_C_STA,
			  TYPE_U_D_END,

			  TYPE_INTERPOLATION
    
          }; 
#define  MAX_EVENT_TYPE_NUM  64  //TYPE_IPO+1

#define		NodeHd_Type                 0xFO
#define		HdType_Dev     				0xF1
#define		HdType_Axis    				0xF2
#define		HdType_Group   				0xF3
#define		HdType_AxInGp 				0xF4
#define		HdType_MasDev  				0xF5
#define		HdType_SlvDev               0xF6 //  [9/29/2014 dan]
#define 	HdType_Cyl							0xF7 // ydd 16.11.9


//WR3 setting can be one of these types
#define WR3_Mask             0X0f9f//use '&'
//#define Ax_Sync_TMove        0x0f98//use '&'{bit0:MANLD(0) bit1:DSNDE(0) bit2:SACC(0)}
//#define Ax_Async_TMove       0x0f9E//bit0:MANLD(1) bit1:DSNDE(1) bit2:SACC(0)
//#define Ax_Sync_SMove        0x0f99//use bit0:MANLD(0) bit1:DSNDE(0) bit2:SACC(1)
//#define Ax_Async_SMove       0x0f9f//bit0:MANLD(1) bit1:DSNDE(1) bit2:SACC(1)


//********************************Motion type of Axis OR Group*****************
//Ptp types:
#define		Unknown         			0
#define		SynTPtP         			1
#define		AsynTPtP        			2
#define		SynSPtP         			3
#define		AsynSPtP        			4
//Conti types:
#define		SynTConti       			5
#define		AsynTConti      			6
#define		SynSConti       			7
#define		AsynSConti      			8
//Home types:
#define		HomeEX                      9

//Stop types:
#define		SynTDecStop                 22
#define		AsynTDecStop                23
#define		SynSDecStop                 24
#define		AsynSDecStop                25

 #define	EmgStop                     26
//IPO types:
#define		SynTLineIpo                 27
#define		AsynTLineIpo                28
#define		SynSLineIpo                 29
#define		AsynSLineIpo                30
#define		SynTContiIpo                31
#define		AsynTContiIpo               32
#define		SynTArcIpo                  33
#define		AsynTArcIpo                 34
#define		SynTDirectIpo               35
#define		AsynTDirectIpo              36
#define		SynSDirectIpo               37
#define		AsynSDirectIpo              38
#define		SynTDecStopGp               39
#define		AsynTDecStopGp              40
#define		SynSDecStopGp               41
#define		AsynSDecStopGp              42
#define		EmgStopGp                   43

//  [2/26/2008 kiya.chen] add
#define		SynSArcIpo                  44
#define		AsynSArcIpo                 45
#define		SynSContiIpo                46
#define		AsynSContiIpo               47

//******************Home Sub Types***************************//

#define		SearchLevelOnOrgByFixDir       0
#define		SearchLevelOffOrgByFixDir      1
#define		SearchEdgeOnOrgByFixDir        2 //HomeEX_SubType1,2,3,4
#define		SearchEdgeOffOrgByFixDir       3
#define		SearchLevelOnOrgBySwitchDir    4
#define		SearchLevelOffOrgBySwitchDir   5
#define		SearchEdgeOnOrgBySwitchDir     6//HomeEX_SubType5,6,7,8
#define		SearchEdgeOffOrgBySwitchDir    7

#define		SearchLevelOnLmtBySwitchDir    8
#define		SearchLevelOffLmtBySwitchDir   9
#define		SearchEdgeOnLmtByFixDir        10 //HomeEX_SubType9,10,11,12
#define		SearchEdgeOnLmtBySwitchDir     11 //HomeEX_SubType13,14,15,16
#define		SearchEdgeOffLmtBySwitchDir    12
#define		SearchEz                       13 //HomeEX_SubType17,18,19,20

#define		HomeEX_SubType1				1 //AbsSwitch+PosiDir+EdgeOn+HighActive
#define		HomeEX_SubType2				2 //AbsSwitch+PosiDir+EdgeOn+LowActive
#define		HomeEX_SubType3				3 //AbsSwitch+NegDir+EdgeOn+HighActive
#define		HomeEX_SubType4				4 //AbsSwitch+NegDir+EdgeOn+LowActive
#define		HomeEX_SubType5				5 //AbsSwitch+SwitchPosi+EdgeOn+HighActive
#define		HomeEX_SubType6				6 //AbsSwitch+SwitchPosi+EdgeOn+LowActive
#define		HomeEX_SubType7				7 //AbsSwitch+SwitchNeg+EdgeOn+HighActive
#define		HomeEX_SubType8				8 //AbsSwitch+SwitchNeg+EdgeOn+LowActive

#define		HomeEX_SubType9				9 //LimitSwitch+PosiDir+EdgeOn+HighActive
#define		HomeEX_SubType10			10 //LimitSwitch+PosiDir+EdgeOn+LowActive
#define		HomeEX_SubType11			11 //LimitSwitch+NegDir+EdgeOn+HighActive
#define		HomeEX_SubType12			12 //LimitSwitch+NegDir+EdgeOn+LowActive
#define		HomeEX_SubType13			13 //LimitSwitch+SwitchPosi+EdgeOn+HighActive
#define		HomeEX_SubType14			14 //LimitSwitch+SwitchPosi+EdgeOn+LowActive
#define		HomeEX_SubType15			15 //LimitSwitch+SwitchNeg+EdgeOn+HighActive
#define		HomeEX_SubType16			16 //LimitSwitch+SwitchNeg+EdgeOn+LowActive

#define		HomeEX_SubType17			17 //RefPulse+PosiDir+EdgeOn+HighActive
#define		HomeEX_SubType18			18 //RefPulse+PosiDir+EdgeOn+LowActive
#define		HomeEX_SubType19			19 //RefPulse+NegDir+EdgeOn+HighActive
#define		HomeEX_SubType20			20 //RefPulse+NegDir+EdgeOn+LowActive
//******************End of Home Sub Types***************************//
//**********************************End of Motion type***************************

#define		Ptp_PosDir                  0
#define		Ptp_NegDir                  1

#define		Conti_PosDir                0
#define		Conti_NegDir                1

#define		Home_PosDir                 0
#define		Home_NegDir                 1
/*
+-----------------------------------------------------------------------------+
| ********************* Motion Home Phase Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define		Home_Phase_Search_ORG       0
#define		Home_Phase_Search_EL        1
#define		Home_Phase_Search_EZ        2
#define		Home_Phase_CrossDistance    3
#define		Home_Phase_ORG_OUTING       4
#define		Home_Phase_EL_OUTING        5
#define		Home_Phase_EZ_OUTING        6
/*
+-----------------------------------------------------------------------------+
| ********************* Motion Home Switch Mode Define ********************** |
+-----------------------------------------------------------------------------+
*/
#define		LevelOn						0
#define		LevelOff					1
#define		EdgeOn						2
#define		EdgeOff						3
/*
+-----------------------------------------------------------------------------+
| ********************* Motion Path Cmd Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define	    EndPath						0
#define	    Abs2DLine					1
#define	    Rel2DLine					2
#define	    Abs2DArcCW					3
#define	    Abs2DArcCCW					4
#define	    Rel2DArcCW					5
#define	    Rel2DArcCCW					6
#define     Abs3DLine					7
#define     Rel3DLine					8
#define     AbsMultiLine				9
#define     RelMultiLine				10
//Add for pci1245 and pci1265[dan.yang 2011.05.04]// Reserved.
#define     Abs2DDirect					11  
#define     Rel2DDirect					12
#define     Abs3DDirect					13
#define     Rel3DDirect					14
#define     Abs4DDirect					15
#define     Rel4DDirect					16
#define     Abs5DDirect					17
#define     Rel5DDirect					18
#define     Abs6DDirect					19
#define     Rel6DDirect					20
#define     Abs3DArcCW					21
#define     Rel3DArcCW					22
#define     Abs3DArcCCW					23
#define     Rel3DArcCCW					24
#define     Abs3DSpiralCW				25  
#define     Rel3DSpiralCW				26
#define     Abs3DSpiralCCW				27
#define     Rel3DSpiralCCW				28
#define     GPDELAY						29

#define     Abs4DSpiralCW				30  //add by zhaocui.deng 20130402
#define     Rel4DSpiralCW				31
#define     Abs4DSpiralCCW				32
#define     Rel4DSpiralCCW				33
#define     Abs5DSpiralCW				34  
#define     Rel5DSpiralCW				35
#define     Abs5DSpiralCCW				36
#define     Rel5DSpiralCCW				37
#define     Abs6DSpiralCW				38  
#define     Rel6DSpiralCW				39
#define     Abs6DSpiralCCW				40
#define     Rel6DSpiralCCW				41
#define     Abs7DSpiralCW				42  
#define     Rel7DSpiralCW				43
#define     Abs7DSpiralCCW				44
#define     Rel7DSpiralCCW				45
#define     Abs8DSpiralCW				46  
#define     Rel8DSpiralCW				47
#define     Abs8DSpiralCCW				48
#define     Rel8DSpiralCCW				49

//added by zhaocui.deng 20130502
#define	    Abs2DArcCWAngle				50
#define	    Rel2DArcCWAngle				51
#define	    Abs2DArcCCWAngle			52
#define	    Rel2DArcCCWAngle			53
#define     Abs3DArcCWAngle				54
#define     Rel3DArcCWAngle				55
#define     Abs3DArcCCWAngle			56
#define     Rel3DArcCCWAngle			57
#define     Abs3DSpiralCWAngle			58  
#define     Rel3DSpiralCWAngle			59
#define     Abs3DSpiralCCWAngle			60
#define     Rel3DSpiralCCWAngle			61
#define     Abs4DSpiralCWAngle			62  
#define     Rel4DSpiralCWAngle			63
#define     Abs4DSpiralCCWAngle			64
#define     Rel4DSpiralCCWAngle			65
#define     Abs5DSpiralCWAngle			66  
#define     Rel5DSpiralCWAngle			67
#define     Abs5DSpiralCCWAngle			68
#define     Rel5DSpiralCCWAngle			69
#define     Abs6DSpiralCWAngle			70 
#define     Rel6DSpiralCWAngle			71
#define     Abs6DSpiralCCWAngle			72
#define     Rel6DSpiralCCWAngle			73
#define     Abs7DSpiralCWAngle			74  
#define     Rel7DSpiralCWAngle			75
#define     Abs7DSpiralCCWAngle			76
#define     Rel7DSpiralCCWAngle			77
#define     Abs8DSpiralCWAngle			78  
#define     Rel8DSpiralCWAngle			79
#define     Abs8DSpiralCCWAngle			80
#define     Rel8DSpiralCCWAngle			81
#define     Abs7DDirect					82
#define     Rel7DDirect					83
#define     Abs8DDirect					84
#define     Rel8DDirect					85
#define     Abs2DArcCW_3P				86  //  [9/4/2014 kai.yang]
#define 	Rel2DArcCW_3P				87 
#define 	Abs2DArcCCW_3P				88 
#define 	Rel2DArcCCW_3P				89

#define     DoControl					90  //  [2/27/2014 dan.yang]

#define     Abs1DDirect					91  
#define     Rel1DDirect					92

#define		Abs3DSpiralCW_3P            93  
#define     Rel3DSpiralCW_3P            94
#define     Abs3DSpiralCCW_3P           95
#define     Rel3DSpiralCCW_3P           96
#define     Abs4DSpiralCW_3P            97
#define     Rel4DSpiralCW_3P            98
#define     Abs4DSpiralCCW_3P           99
#define     Rel4DSpiralCCW_3P           100
#define     Abs5DSpiralCW_3P            101  
#define     Rel5DSpiralCW_3P            102
#define     Abs5DSpiralCCW_3P           103
#define     Rel5DSpiralCCW_3P           104
#define     Abs6DSpiralCW_3P            105 
#define     Rel6DSpiralCW_3P            106
#define     Abs6DSpiralCCW_3P           107
#define     Rel6DSpiralCCW_3P           108
#define     Abs7DSpiralCW_3P            109
#define     Rel7DSpiralCW_3P            110
#define     Abs7DSpiralCCW_3P           111
#define     Rel7DSpiralCCW_3P           112
#define     Abs8DSpiralCW_3P            113  
#define     Rel8DSpiralCW_3P            114
#define     Abs8DSpiralCCW_3P           115
#define     Rel8DSpiralCCW_3P           116
#define		WaitforAxis					117
#define		Abs3DArcCW_3P				118
#define     Rel3DArcCW_3P				119
#define     Abs3DArcCCW_3P				120
#define     Rel3DArcCCW_3P				121
/*
+-----------------------------------------------------------------------------+
| *********************Robot  Motion Path Cmd Define ************************ |
+-----------------------------------------------------------------------------+
*///  [9/17/2013 dan.yang]: For different with general path command.
#ifdef ADVVIRTUALMOTIONCARD 
#define     RB_MOVE_CMD_BASE                0xA0
#define 	RB_EndPath       	(RB_MOVE_CMD_BASE+0)
#define 	RB_AbsMove       	(RB_MOVE_CMD_BASE+1)
#define 	RB_RelMove       	(RB_MOVE_CMD_BASE+2)
#define 	RB_AbsMoveDirect 	(RB_MOVE_CMD_BASE+3)
#define 	RB_RelMoveDirect 	(RB_MOVE_CMD_BASE+4)
#define 	RB_AbsMoveLine   	(RB_MOVE_CMD_BASE+5)
#define 	RB_RelMoveLine   	(RB_MOVE_CMD_BASE+6)
#define 	RB_AbsMoveArcCW		(RB_MOVE_CMD_BASE+7)
#define 	RB_RelMoveArcCW		(RB_MOVE_CMD_BASE+8) 
#define 	RB_AbsMoveArcCCW	(RB_MOVE_CMD_BASE+9)
#define 	RB_RelMoveArcCCW    (RB_MOVE_CMD_BASE+10)
#define     RB_AbsMoveArcCW_3P  (RB_MOVE_CMD_BASE+11)
#define 	RB_RelMoveArcCW_3P  (RB_MOVE_CMD_BASE+12)
#define 	RB_AbsMoveArcCCW_3P (RB_MOVE_CMD_BASE+13)
#define 	RB_RelMoveArcCCW_3P (RB_MOVE_CMD_BASE+14)
#define 	RB_DELAY			(RB_MOVE_CMD_BASE+20)
#define     RB_DoControl        (RB_MOVE_CMD_BASE+21)
#else
#define 	RB_EndPath       			0
#define 	RB_AbsMove       			1
#define 	RB_RelMove       			2
#define 	RB_AbsMoveDirect 			3
#define 	RB_RelMoveDirect 			4
#define 	RB_AbsMoveLine   			5
#define 	RB_RelMoveLine   			6
#define 	RB_AbsMoveArcCW				7 
#define 	RB_RelMoveArcCW				8 
#define 	RB_AbsMoveArcCCW			9 
#define 	RB_RelMoveArcCCW			10
#define     RB_AbsMoveArcCW_3P			11
#define 	RB_RelMoveArcCW_3P			12 
#define 	RB_AbsMoveArcCCW_3P			13 
#define 	RB_RelMoveArcCCW_3P			14
#define 	RB_DELAY					20
#define     RB_DoControl				21
#endif

/*+-----------------------------------------------------------------------------+
| ********************* Motion Path Mode Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define     BlendingEn					0
#define     BlendingDis					1
#define     CUSTOMIZED_MODE				2
/*

/*
+-----------------------------------------------------------------------------+
| ********************* Motion Event Name Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     ADV_EVT_NUM					6
#define     ADV_EVT_AX_DONE				"EVT_AX_DONE"
#define     ADV_EVT_GP_DONE				"EVT_GP_DONE"
#define     ADV_EVT_CANCELED			"EVT_CANCELED"
	

/*
+-----------------------------------------------------------------------------+
| *********************** Axis ERC Map Define ******************************* |
+-----------------------------------------------------------------------------+
*/
#define     AX_ERC_EN_MODE				1
#define     AX_ERC_LOGIC				2
#define     AX_ERC_ON_TIME				4
#define     AX_ERC_OFF_TIME				8

/*
+-----------------------------------------------------------------------------+
| ******************** Axis ERC On-Time Map Define ************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_ERC_ON_12US				1
#define     AX_ERC_ON_102US				2
#define     AX_ERC_ON_409US				4
#define     AX_ERC_ON_1600US			8
#define     AX_ERC_ON_13MS				16
#define     AX_ERC_ON_52MS				32
#define     AX_ERC_ON_104MS				64
#define     AX_ERC_ON_LEVEL				128

/*
+-----------------------------------------------------------------------------+
| ******************** Axis ERC Enable mode Map Define ********************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_ERC_ON_HOME				1
#define     AX_ERC_ON_MIO				2
#define     AX_ERC_ON_HOME_MIO			4

/*
+-----------------------------------------------------------------------------+
| ******************** Axis ERC Off-Time Map Define ************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_ERC_OFF_0US				1
#define     AX_ERC_OFF_12US				2
#define     AX_ERC_OFF_1600US			4
#define     AX_ERC_OFF_104MS			8

/*
+-----------------------------------------------------------------------------+
| ******************** Axis BACKLASH Map Define ************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_BKSH_EN					1
#define     AX_BKSH_VALUE				2
#define		AX_BKSH_VEL					4

/*
+-----------------------------------------------------------------------------+
| ******************** Axis VIBRATION Map Define ************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_VIBRA_EN					1
#define     AX_VIBRA_FWD_VALUE			2
#define     AX_VIBRA_REV_VALUE			4

/*
+-----------------------------------------------------------------------------+
| ************************ Axis JOG Map Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define     AX_JOG_SPEED				0x01
#define     AX_JOG_VL_TIME				0x02
#define     AX_JOG_SOFT					0x04
#define     AX_JOG_Assign				0x08

/*
+-----------------------------------------------------------------------------+
| ******************** CounterMax OverflowMode Define *********************** |
+-----------------------------------------------------------------------------+
*/
#define     CNTMAX_OVMode_NEG			0x00
#define     CNTMAX_OVMode_ZERO			0x01
#define     CNTMAX_OVMode_MIN			0x02

/*
+-----------------------------------------------------------------------------+
| ***************** ERC Acitve Logic Define ********************************* |
+-----------------------------------------------------------------------------+
*/
#define     ERC_ACT_LOW                 0
#define     ERC_ACT_HIGH 			    1


//Added by Dean -----------------------------------------------
#define     ERC_ON_DISABLE				0
#define     ERC_ON_HOME					1
#define     ERC_ON_MIO					2
#define     ERC_ON_HOME_MIO				3

/*
+-----------------------------------------------------------------------------+
| ******************** Axis ERC On-Time Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define     ERC_ON_12US					0
#define     ERC_ON_102US				1
#define     ERC_ON_409US				2
#define     ERC_ON_1600US				3
#define     ERC_ON_13MS					4
#define     ERC_ON_52MS					5
#define     ERC_ON_104MS				6
#define     ERC_ON_LEVEL				7

/*
+-----------------------------------------------------------------------------+
| ******************** Axis ERC Off-Time Define ***************************** |
+-----------------------------------------------------------------------------+
*/
#define     ERC_OFF_0US					0
#define     ERC_OFF_12US				1
#define     ERC_OFF_1600US				2
#define     ERC_OFF_104MS				3

/*
+-----------------------------------------------------------------------------+
| ***************** ERC on home Define(only for KW Dialog) ****************** |
+-----------------------------------------------------------------------------+
*/
#define     ERC_HOME_DISABLE            0
#define     ERC_HOME_ENABLE 			1

/*
+-----------------------------------------------------------------------------+
| ***************** ERC on motion_io Define(only for KW Dialog) ************* |
+-----------------------------------------------------------------------------+
*/
#define     ERC_ERRMIO_DISABLE          0
#define     ERC_ERRMIO_ENABLE 			1

/*
+-----------------------------------------------------------------------------+
| ****************** SD  Enable Define *************************** |
+-----------------------------------------------------------------------------+
*/
#define     SD_DIS 						0
#define		SD_EN 						1
/*
+-----------------------------------------------------------------------------+
| ****************** SD React Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     SD_DEC		 				0
#define		SD_DEC_TO_STOP 				1

/*
+-----------------------------------------------------------------------------+
| ****************** SD Latch Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     SD_LATCH_DIS				0
#define		SD_LATCH_EN 				1

/*
+-----------------------------------------------------------------------------+
| ****************** Latch Logic Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     LATCH_ACT_LOW 				0
#define		LATCH_ACT_HIGH 				1

/*
+-----------------------------------------------------------------------------+
| ****************** Home Reset Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     HOME_RESET_DIS				0
#define		HOME_RESET_EN 				1
/*
+-----------------------------------------------------------------------------+
| ****************** Backlash enable Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define     BKSH_DIS					0
#define		BKSH_EN 					1
/*
+-----------------------------------------------------------------------------+
| ****************** Viabration enable Define **************************** | //ydd:modified.20110309
+-----------------------------------------------------------------------------+
*/
#define     VIBRA_DIS					0
#define		VIBRA_EN 					1

/*
+-----------------------------------------------------------------------------+
| ****************** Baudrate Define **************************** |
+-----------------------------------------------------------------------------+
*/
#define		BR_AMONET_2500K				0x00
#define		BR_AMONET_5M				0x01
#define		BR_AMONET_10M				0x02
#define		BR_AMONET_20M				0x03
#define		BR_CAN_10K					0x10
#define		BR_CAN_20K					0x11
#define		BR_CAN_50K					0x12
#define		BR_CAN_125K					0x13
#define		BR_CAN_250K					0x14
#define		BR_CAN_500K					0x15
#define		BR_CAN_800K					0x16
#define		BR_CAN_1000K				0x17

/*
+-----------------------------------------------------------------------------+
| ****************** Master Communication Status **************************** |
+-----------------------------------------------------------------------------+
*/
#define		COM_ST_DISCONNECTED			0x00
#define		COM_ST_CONNECTED			0x01
#define		COM_ST_SLAVE_ERROR			0x02
#define		COM_ST_BUSY					0x03
#define		COM_ST_ERROR				0x04

/*
+-----------------------------------------------------------------------------+
| ********************* CAM DO Mode ***************************************** |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2011.05.25]
*/
#define     CamDOByPosition			    0
#define		CamDOByTime			        1

/*
+-----------------------------------------------------------------------------+
| ********************* Encode Pulse in Max Frequency ***************************************** |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2011.06.20]
*/
#define		ENC_500KHZ 					0x00
#define		ENC_1MHZ 					0x01
#define		ENC_2MHZ 					0x02
#define		ENC_4MHZ	 				0x03
/*
+-----------------------------------------------------------------------------+
| *********************Reference plane for Arc interpolation /spiral interpolation/Gantry function * |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2011.06.20]
*/
#define		XY_PLANE                    0
#define		YZ_PLANE                    1
#define		XZ_PLANE                    2
/*
+-----------------------------------------------------------------------------+
| *********************PWM ***************************************************|
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[zhaocui  2013.07.15]
*/
#define		MaxPWMFreq					250000
#define		MinPWMFreq					1
/*
+-----------------------------------------------------------------------------+
| ********** Motion DAQ channel type MAP* |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2012.06.13]
*/
#define		MP_MQ_TYPE_CMDPOSI          0x01                         // cmd position information
#define		MP_MQ_TYPE_ACTPOSI          0x02                         // act position information
#define		MP_MQ_TYPE_LAGPOSI          0x04                         // cmd - act position information
#define		MP_MQ_TYPE_CMDVEL           0x08                         // cmd velocity information (reserved)
/*
+-----------------------------------------------------------------------------+
| *********************Motion DAQ Channel Type * |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2012.06.13]
*/
#define		MQ_TYPE_CMDPOSI             0                        // cmd position information
#define		MQ_TYPE_ACTPOSI             1                        // act position information
#define		MQ_TYPE_LAGPOSI             2                        // cmd - act position information
#define		MQ_TYPE_CMDVEL              3                        // cmd velocity information (reserved)
/*
+-----------------------------------------------------------------------------+
| *********************Motion DAQ trigger type * |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2012.06.13]
*/
// Motion DAQ trigger type (each channel can be set to trigger in what state )
#define		MQ_TRIG_DISABLE				0				// Disable
#define		MQ_TRIG_SW					1				// Trigger by Software 
#define		MQ_TRIG_DI					2				// Trigger by DI (reserved)
#define		MQ_TRIG_AX0_START			3				// Trigger by Axis0 start move
#define		MQ_TRIG_AX1_START			4				// Trigger by Axis1 start move
#define		MQ_TRIG_AX2_START			5				// Trigger by Axis2 start move
#define		MQ_TRIG_AX3_START			6				// Trigger by Axis3 start move
#define		MQ_TRIG_AX4_START			7				// Trigger by Axis4 start move
#define		MQ_TRIG_AX5_START			8				// Trigger by Axis5 start move
#define		MQ_TRIG_AX6_START			9				// Trigger by Axis6 start move
#define		MQ_TRIG_AX7_START			10				// Trigger by Axis7 start move
#define		MQ_TRIG_AX8_START			11				// Trigger by Axis8 start move
#define		MQ_TRIG_AX9_START			12				// Trigger by Axis9 start move
#define		MQ_TRIG_AX10_START			13				// Trigger by Axis10 start move
#define		MQ_TRIG_AX11_START			14				// Trigger by Axis11 start move
#define		MQ_TRIG_AX12_START			15				// Trigger by Axis12 start move
#define		MQ_TRIG_AX13_START			16				// Trigger by Axis13 start move
#define		MQ_TRIG_AX14_START			17				// Trigger by Axis14 start move
#define		MQ_TRIG_AX15_START			18				// Trigger by Axis15 start move
#define		MQ_TRIG_AX16_START			19				// Trigger by Axis16 start move
#define		MQ_TRIG_AX17_START			20				// Trigger by Axis17 start move
#define		MQ_TRIG_AX18_START			21				// Trigger by Axis18 start move
#define		MQ_TRIG_AX19_START			22				// Trigger by Axis19 start move
#define		MQ_TRIG_AX20_START			23				// Trigger by Axis20 start move
#define		MQ_TRIG_AX21_START			24				// Trigger by Axis21 start move
#define		MQ_TRIG_AX22_START			25				// Trigger by Axis22 start move
#define		MQ_TRIG_AX23_START			26				// Trigger by Axis23 start move
#define		MQ_TRIG_AX24_START			27				// Trigger by Axis24 start move
#define		MQ_TRIG_AX25_START			28				// Trigger by Axis25 start move
#define		MQ_TRIG_AX26_START			29				// Trigger by Axis26 start move
#define		MQ_TRIG_AX27_START			30				// Trigger by Axis27 start move
#define		MQ_TRIG_AX28_START			31				// Trigger by Axis28 start move
#define		MQ_TRIG_AX29_START			32				// Trigger by Axis29 start move
#define		MQ_TRIG_AX30_START			33				// Trigger by Axis30 start move
#define		MQ_TRIG_AX31_START			34				// Trigger by Axis31 start move
#define		MQ_TRIG_AX32_START			35				// Trigger by Axis32 start move
#define		MQ_TRIG_AX33_START			36				// Trigger by Axis33 start move
#define		MQ_TRIG_AX34_START			37				// Trigger by Axis34 start move
#define		MQ_TRIG_AX35_START			38				// Trigger by Axis35 start move
#define		MQ_TRIG_AX36_START			39				// Trigger by Axis36 start move
#define		MQ_TRIG_AX37_START			40				// Trigger by Axis37 start move
#define		MQ_TRIG_AX38_START			41				// Trigger by Axis38 start move
#define		MQ_TRIG_AX39_START			42				// Trigger by Axis39 start move
#define		MQ_TRIG_AX40_START			43				// Trigger by Axis40 start move
#define		MQ_TRIG_AX41_START			44				// Trigger by Axis41 start move
#define		MQ_TRIG_AX42_START			45				// Trigger by Axis42 start move
#define		MQ_TRIG_AX43_START			46				// Trigger by Axis43 start move
#define		MQ_TRIG_AX44_START			47				// Trigger by Axis44 start move
#define		MQ_TRIG_AX45_START			48				// Trigger by Axis45 start move
#define		MQ_TRIG_AX46_START			49				// Trigger by Axis46 start move
#define		MQ_TRIG_AX47_START			50				// Trigger by Axis47 start move
#define		MQ_TRIG_AX48_START			51				// Trigger by Axis48 start move
#define		MQ_TRIG_AX49_START			52				// Trigger by Axis49 start move
#define		MQ_TRIG_AX50_START			53				// Trigger by Axis50 start move
#define		MQ_TRIG_AX51_START			54				// Trigger by Axis51 start move
#define		MQ_TRIG_AX52_START			55				// Trigger by Axis52 start move
#define		MQ_TRIG_AX53_START			56				// Trigger by Axis53 start move
#define		MQ_TRIG_AX54_START			57				// Trigger by Axis54 start move
#define		MQ_TRIG_AX55_START			58				// Trigger by Axis55 start move
#define		MQ_TRIG_AX56_START			59				// Trigger by Axis56 start move
#define		MQ_TRIG_AX57_START			60				// Trigger by Axis57 start move
#define		MQ_TRIG_AX58_START			61				// Trigger by Axis58 start move
#define		MQ_TRIG_AX59_START			62				// Trigger by Axis59 start move
#define		MQ_TRIG_AX60_START			63				// Trigger by Axis60 start move
#define		MQ_TRIG_AX61_START			64				// Trigger by Axis61 start move
#define		MQ_TRIG_AX62_START			65				// Trigger by Axis62 start move
#define		MQ_TRIG_AX63_START			66				// Trigger by Axis63 start move

/*
+-----------------------------------------------------------------------------+
| *********************Motion DAQ trigger Map * |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2012.06.18]
*/
#define		MP_MQ_TRIG_DISABLE			0x0000				// Disable
#define		MP_MQ_TRIG_SW				0x0001				// Trigger by Software 
#define		MP_MQ_TRIG_DI				0x0002				// Trigger by DI (reserved)
#define		MP_MQ_TRIG_AX_START			0x0004				// Trigger by AXIS

/*
+-----------------------------------------------------------------------------+
| *********************Home Mode Map * |
+-----------------------------------------------------------------------------+
//Add for pci1245 and pci1265.[dan.yang 2012.06.13]
*/
#define		MP_MODE1_Abs							0x0001 
#define		MP_MODE2_Lmt							0x0002
#define		MP_MODE3_Ref							0x0004
#define		MP_MODE4_Abs_Ref						0x0008
#define		MP_MODE5_Abs_NegRef						0x0010
#define		MP_MODE6_Lmt_Ref						0x0020
#define		MP_MODE7_AbsSearch						0x0040
#define		MP_MODE8_LmtSearch						0x0080
#define		MP_MODE9_AbsSearch_Ref					0x0100
#define	    MP_MODE10_AbsSearch_NegRef				0x0200
#define	    MP_MODE11_LmtSearch_Ref					0x0400
#define	    MP_MODE12_AbsSearchReFind				0x0800
#define	    MP_MODE13_LmtSearchReFind				0x1000
#define	    MP_MODE14_AbsSearchReFind_Ref			0x2000
#define	    MP_MODE15_AbsSearchReFind_NegRef		0x4000
#define	    MP_MODE16_LmtSearchReFind_Ref			0x8000

/*
+-----------------------------------------------------------------------------+
| *********************Ax Motion IO * |
+-----------------------------------------------------------------------------+
//.[kai.yang 2014.05.29]
*/
#define		AX_MOTION_IO_RDY			0x00000001
#define		AX_MOTION_IO_ALM			0x00000002
#define		AX_MOTION_IO_LMTP			0x00000004
#define		AX_MOTION_IO_LMTN			0x00000008
#define		AX_MOTION_IO_ORG			0x00000010
#define		AX_MOTION_IO_DIR			0x00000020
#define		AX_MOTION_IO_EMG			0x00000040
#define		AX_MOTION_IO_PCS			0x00000080
#define		AX_MOTION_IO_ERC			0x00000100
#define		AX_MOTION_IO_EZ				0x00000200
#define		AX_MOTION_IO_CLR			0x00000400
#define		AX_MOTION_IO_LTC			0x00000800
#define		AX_MOTION_IO_SD				0x00001000
#define		AX_MOTION_IO_INP			0x00002000
#define		AX_MOTION_IO_SVON			0x00004000
#define		AX_MOTION_IO_ALRM			0x00008000
#define		AX_MOTION_IO_SLMTP			0x00010000
#define		AX_MOTION_IO_SLMTN			0x00020000
#define		AX_MOTION_IO_CMP			0x00040000
#define		AX_MOTION_IO_CAMDO			0x00080000
#define		AX_MOTION_IO_MAXTORLMT		0x00100000 //Andy.Wang 2015.08.10

/*
+-----------------------------------------------------------------------------+
| *********************AI Range Map * |
+-----------------------------------------------------------------------------+
//Add for AI[dan.yang 2014.11.22]
*/
#define		DAQ_AI_NEG_10V_TO_10V				0x00000001
#define		DAQ_AI_NEG_5V_TO_5V					0x00000002
#define		DAQ_AI_NEG_2500MV_TO_2500MV			0x00000004
#define		DAQ_AI_NEG_1250MV_TO_1250MV			0x00000008
#define		DAQ_AI_NEG_625MV_TO_625MV			0x00000010
#define		DAQ_AI_NEG_1V_TO_1V					0x00000020
#define		DAQ_AI_NEG_500MV_TO_500MV			0x00000040
#define		DAQ_AI_NEG_150MV_TO_150MV			0x00000080
#define		DAQ_AI_NEG_0_TO_10V	    			0x00000100
#define		DAQ_AI_NEG_0_TO_500MV				0x00000200			
#define		DAQ_AI_0MA_TO_20MA					0x00010000
#define		DAQ_AI_4MA_TO_20MA					0x00020000
#define		DAQ_AI_NEG_20MA_TO_20MA				0x00040000

/*

/*
+-----------------------------------------------------------------------------+
| *********************AI Range configuration * |
+-----------------------------------------------------------------------------+
//Add for AI[dan.yang 2014.11.22]
*/
#define		CFG_DAQ_AI_NEG_10V_TO_10V			0x00000000
#define		CFG_DAQ_AI_NEG_5V_TO_5V				0x00000001
#define		CFG_DAQ_AI_NEG_2500MV_TO_2500MV		0x00000002
#define		CFG_DAQ_AI_NEG_1250MV_TO_1250MV		0x00000003
#define		CFG_DAQ_AI_NEG_625MV_TO_625MV		0x00000004
#define		CFG_DAQ_AI_NEG_1V_TO_1V				0x00000005
#define		CFG_DAQ_AI_NEG_500MV_TO_500MV		0x00000006
#define		CFG_DAQ_AI_NEG_150MV_TO_150MV		0x00000007
#define		CFG_DAQ_AI_NEG_0_TO_10V				0x00000008
#define		CFG_DAQ_AI_NEG_0_TO_500MV			0x00000009
#define		CFG_DAQ_AI_0MA_TO_20MA				0x00000010
#define		CFG_DAQ_AI_4MA_TO_20MA				0x00000011
#define		CFG_DAQ_AI_NEG_20MA_TO_20MA			0x00000012

/*
+-----------------------------------------------------------------------------+
| *********************AO Range Map * |
+-----------------------------------------------------------------------------+
//Add for AO[dan.yang 2014.11.22]
*/
#define		DAQ_AO_NEG_10V_TO_10V				0x00000001
#define		DAQ_AO_NEG_5V_TO_5V					0x00000002
#define		DAQ_AO_NEG_2500MV_TO_2500MV			0x00000004
#define		DAQ_AO_NEG_1250MV_TO_1250MV			0x00000008
#define		DAQ_AO_NEG_625MV_TO_625MV			0x00000010
#define		DAQ_AO_NEG_0V_TO_10V				0x00000020
#define		DAQ_AO_NEG_0V_TO_5V					0x00000040
#define		DAQ_AO_0MA_TO_20MA					0x00010000
#define		DAQ_AO_4MA_TO_20MA					0x00020000

/*
+-----------------------------------------------------------------------------+
| *********************AO Range Configuration * |
+-----------------------------------------------------------------------------+
//Add for AO[dan.yang 2014.11.22]
*/
#define		CFG_DAQ_AO_NEG_10V_TO_10V			0x00000000
#define		CFG_DAQ_AO_NEG_5V_TO_5V				0x00000001
#define		CFG_DAQ_AO_NEG_2500MV_TO_2500MV		0x00000002
#define		CFG_DAQ_AO_NEG_1250MV_TO_1250MV		0x00000003
#define		CFG_DAQ_AO_NEG_625MV_TO_625MV		0x00000004
#define		CFG_DAQ_AO_NEG_0V_TO_10V			0x00000005
#define		CFG_DAQ_AO_NEG_0V_TO_5V			    0x00000006
#define		CFG_DAQ_AO_0MA_TO_20MA				0x00000010
#define		CFG_DAQ_AO_4MA_TO_20MA				0x00000011


#define		ECAT_TYPE_I8				1
#define		ECAT_TYPE_U8				2
#define		ECAT_TYPE_I16				3
#define		ECAT_TYPE_U16				4
#define		ECAT_TYPE_I32				5
#define		ECAT_TYPE_U32				6
#define		ECAT_TYPE_I64				7
#define		ECAT_TYPE_U64				8
#define		ECAT_TYPE_STRING			9
#define		ECAT_TYPE_BOOL				10
#define		ECAT_TYPE_F32				11
#define		ECAT_TYPE_F64				12

typedef enum _SLV_DEV_STATE
{
	EC_SLAVE_STATE_UNKNOWN = 0x00,  /**< unknown state */
	EC_SLAVE_STATE_INIT = 0x01,   /**< INIT state (no mailbox communication, no IO) */
	EC_SLAVE_STATE_PREOP = 0x02,    /**< PREOP state (mailbox communication, no IO) */
	EC_SLAVE_STATE_BOOT = 0x03,   /**< Bootstrap state (mailbox communication, firmware update) */
	EC_SLAVE_STATE_SAFEOP = 0x04,   /**< SAFEOP (mailbox communication and input update) */
	EC_SLAVE_STATE_OP = 0x08,   /**< OP (mailbox communication and input/output update) */
	EC_SLAVE_STATE_OFFLINE = 0x0F,
	EC_SLAVE_STATE_ACK_ERR = 0x10  /**< Acknowledge/Error bit (no actual state) */
}SLV_DEV_STATE;

/*
+-----------------------------------------------------------------------------+
| ***************** Torque Limit Source Define ****************************** |
+-----------------------------------------------------------------------------+
*/
#define		TorLmtSrc_DISABLE			0
#define     TorLmtSrc_TABLE_ABS			1
#define     TorLmtSrc_TABLE_REL 		2
#define     TorLmtSrc_CONST        		3
#endif // __ADV_MOT_DRV_H__

