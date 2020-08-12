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


#ifndef __ADV_MOT_PROP_ID_H__
#define __ADV_MOT_PROP_ID_H__

/*
+-----------------------------------------------------------------------------+
| ************ Advantech Motion Property ID Definition ********************** |
+-----------------------------------------------------------------------------+
*/
/////////////////////////////////////////////////////////////////////////////// 
//
// Property ID Define
//  
///////////////////////////////////////////////////////////////////////////////
#define FT_Dev_ID                    0
#define PAR_Dev_ID                   101
#define CFG_Dev_ID                   201

#define FT_Ax_ID                     301
#define PAR_Ax_ID                    401
#define CFG_Ax_ID                    501

#define FT_Gp_ID                     601
#define PAR_Gp_ID                    701
#define CFG_Gp_ID                    801

//  [9/24/2013 dan.yang]
#define PAR_RB_ID                    1000
#define CFG_RB_ID                    1200

#define CFG_CH_ID					 1500 //  [11/18/2014 dan]

///////////////////////////////////////////////////////////////////////////////
// Device Feature
///////////////////////////////////////////////////////////////////////////////
#define FT_DevIpoTypeMap             (FT_Dev_ID + 0)    
#define FT_DevAxesCount              (FT_Dev_ID + 1)    
#define FT_DevFunctionMap            (FT_Dev_ID + 2)    
#define FT_DevOverflowCntr           (FT_Dev_ID + 3)    
//Master device config
#define FT_MasCyclicCnt_R0     		 (FT_Dev_ID + 4)  
#define FT_MasCyclicCnt_R1     		 (FT_Dev_ID + 5)  
#define FT_DevMDAQTypeMap            (FT_Dev_ID + 6)//  [6/13/2012 dan.yang]
#define FT_DevMDAQTrigMap            (FT_Dev_ID + 7)//  [6/13/2012 dan.yang]
#define FT_DevMDAQMaxChan            (FT_Dev_ID + 8)//  [6/13/2012 dan.yang]
#define FT_DevMDAQMaxBufCount        (FT_Dev_ID + 9)//  [6/13/2012 dan.yang]
#define FT_DevLTCBufMaxCount         (FT_Dev_ID + 10) 
#define FT_DevVersion                (FT_Dev_ID + 11) //  [6/4/2013 dan.yang]
#define FT_DevEmgMap                 (FT_Dev_ID + 12) //  [1/8/2014 deng]
#define FT_DevSupportAxesCount       (FT_Dev_ID + 13) // [9/30/2015 Andy]
#define FT_AresVariableCount		 (FT_Dev_ID + 14) // [1/14/2016 Andy]
#define FT_AresSupportProcessCount	 (FT_Dev_ID + 15) // [3/10/2016 Tehsin]	
#define FT_ECAT_Version				 (FT_Dev_ID + 16) // [6/16/2017 Andy]

//DAQ function  [1/24/2008 Dean]
#define FT_DaqDiMaxChan				 (FT_Dev_ID + 50)    
#define FT_DaqDoMaxChan				 (FT_Dev_ID + 51)    
#define FT_DaqAiRangeMap			 (FT_Dev_ID + 52)    
#define FT_DaqAoRangeMap			 (FT_Dev_ID + 53)    
#define FT_DaqAiMaxSingleChan		 (FT_Dev_ID + 54)    
#define FT_DaqAiMaxDiffChan			 (FT_Dev_ID + 55)    
#define FT_DaqAiResolution			 (FT_Dev_ID + 56)    
#define FT_DaqAoMaxChan				 (FT_Dev_ID + 57)    
#define FT_DaqAoResolution			 (FT_Dev_ID + 58)  
#define FT_DaqCntMaxChan			 (FT_Dev_ID + 59)  
///////////////////////////////////////////////////////////////////////////////
// Device Config
///////////////////////////////////////////////////////////////////////////////
#define CFG_DevBoardID               (CFG_Dev_ID + 0)    
#define CFG_DevRingID                (CFG_Dev_ID + 1)    
#define CFG_DevBaseAddress           (CFG_Dev_ID + 2)    
#define CFG_DevInterrupt             (CFG_Dev_ID + 3)    
#define CFG_DevBusNumber             (CFG_Dev_ID + 4)    
#define CFG_DevSlotNumber            (CFG_Dev_ID + 5)    
#define CFG_DevDriverVersion         (CFG_Dev_ID + 6)    
#define CFG_DevDllVersion            (CFG_Dev_ID + 7)    
#define CFG_DevComQualityContiErr    (CFG_Dev_ID + 8)  
#define CFG_DevComQualityErrRate     (CFG_Dev_ID + 9)  
#define CFG_DevComWdgMode 			 (CFG_Dev_ID + 10)  
#define CFG_DevFwMemory	 			 (CFG_Dev_ID + 11)  
#define CFG_DevEmgReact	 			 (CFG_Dev_ID + 12)  
#define CFG_DevFwVersion			 (CFG_Dev_ID + 13)  
#define CFG_DevBelongsTo			 (CFG_Dev_ID + 14)
#define CFG_DevMasterDev			 (CFG_Dev_ID + 15)
#define CFG_DevSlaveDevs			 (CFG_Dev_ID + 16)
#define CFG_DevCPLDVersion           (CFG_Dev_ID + 17) 
#define CFG_DevCPLD_1Version         (CFG_Dev_ID + 18)    
#define CFG_DevEmgLogic              (CFG_Dev_ID + 19) 
#define CFG_DevLatestFwVersion       (CFG_Dev_ID + 20) //  [5/30/2013 dan.yang]
#define CFG_DevEmgFilterTime         (CFG_Dev_ID + 21)  //20140107 zhaocui add
#define CFG_DevMultiCmpAxisEnable    (CFG_Dev_ID + 22)  //  [1/14/2014 deng] 
#define CFG_DevMultiCmpOutChannel    (CFG_Dev_ID + 23)  //  [1/14/2014 deng]
#define CFG_DevMultiCmpPulseLogic    (CFG_Dev_ID + 24)  //  [1/14/2014 deng]
#define CFG_DevMultiCmpPulseWidth    (CFG_Dev_ID + 25)  //  [1/14/2014 deng]
#define CFG_DevKillDec               (CFG_Dev_ID + 26)//  [2/28/2014 deng]
#define CFG_DevFuncDiFltSmpRate      (CFG_Dev_ID + 27) //  [10/18/2013 dan.yang]
#define CFG_DevLogMsg                (CFG_Dev_ID + 28) //  [06/26/2015 andy.wang]
#define CFG_DevErrorReact			 (CFG_Dev_ID + 29) //  [03/31/2016 andy.wang]
#define CFG_DevCompensateTableEnable		(CFG_Dev_ID + 30)//only for 技鼎(PCI-1285)

//Master device config
#define CFG_MasBaudRate_R0     		 (CFG_Dev_ID + 31)  
#define CFG_MasBaudRate_R1     		 (CFG_Dev_ID + 32)  
#define CFG_MasComErrRate_R0		 (CFG_Dev_ID + 33)  
#define CFG_MasComErrRate_R1		 (CFG_Dev_ID + 34)  
#define CFG_MasComContiErr_R0		 (CFG_Dev_ID + 35)  
#define CFG_MasComContiErr_R1		 (CFG_Dev_ID + 36)  
#define CFG_MasIoComContiErr_R0		 (CFG_Dev_ID + 37)  
#define CFG_MasIoComContiErr_R1		 (CFG_Dev_ID + 38)  
#define CFG_MasDataComContiErr_R0	 (CFG_Dev_ID + 39)  
#define CFG_MasDataComContiErr_R1	 (CFG_Dev_ID + 40)  

//DAQ function  [1/24/2008 Dean]
#define CFG_DaqAiChanType			 (CFG_Dev_ID + 50)  
#define CFG_DaqAiRanges				 (CFG_Dev_ID + 51)  
#define CFG_DaqMaiRanges			 (CFG_Dev_ID + 52)  
#define CFG_DaqAoRanges_C0			 (CFG_Dev_ID + 53)  
#define CFG_DaqAoRanges_C1			 (CFG_Dev_ID + 54)  
#define CFG_DaqAoRanges_C2			 (CFG_Dev_ID + 55)  
#define CFG_DaqAoRanges_C3			 (CFG_Dev_ID + 56)  
#define CFG_DaqAiGain                (CFG_Dev_ID + 57) //  [4/19/2012 dan.yang]

#define CFG_MasCycleTime			 (CFG_Dev_ID + 60) //  [11/10/2014 dan]
#define CFG_IoCycleTime			     (CFG_Dev_ID + 61)
#define CFG_DevMotionMasterShiftTime (CFG_Dev_ID + 62)
#define CFG_DevIoMasterShiftTime	 (CFG_Dev_ID + 63)

//Add for 凱格:PWM+multicompare. YDD. 2015.3.26
#define CFG_DevMultiTrigFifoWriteEnable  (CFG_Dev_ID + 64)
#define CFG_DevMultiTrigPulseMode		 (CFG_Dev_ID + 65)
#define CFG_DevMultiTrigPWMFreq			 (CFG_Dev_ID + 66)
#define CFG_DevMultiTrigPWMDuty			 (CFG_Dev_ID + 67)
#define CFG_DevMultiTrigAutoEmptyEn		 (CFG_Dev_ID + 68)
#define CFG_DevMultiTrigForcePWMCount	 (CFG_Dev_ID + 69)
//Add End

#define CFG_DevMotionLostFrameThreshold	(CFG_Dev_ID + 70)
#define CFG_DevIOLostFrameThreshold		(CFG_Dev_ID + 71)
#define CFG_DevMotionDisconnectEventTime (CFG_Dev_ID + 72)
#define CFG_DevIoDisconnectEventTime	(CFG_Dev_ID + 73)
#define CFG_DevConfigurePDOs			(CFG_Dev_ID + 74)
#define CFG_DevMultiCmpAxisEnableEx		(CFG_Dev_ID + 75)  // for 64 axes 
#define CFG_DevMultiCmpOutChannelEx		(CFG_Dev_ID + 76)  // for 64 axes 
#define CFG_DevMotionDisconnectSlave	(CFG_Dev_ID + 77)
#define CFG_DevIoDisconnectSlave		(CFG_Dev_ID + 78)
//Add End
//ydd. Add for movelink for 1245S.18.1.25
#define CFG_DevExtEncoderEn				(CFG_Dev_ID + 80)
#define CFG_DevExtEncoderPPUNum			(CFG_Dev_ID + 81)
#define CFG_DevExtEncoderPPUDemo		(CFG_Dev_ID + 82)
#define CFG_DevExtEncoderLogic			(CFG_Dev_ID + 83)
#define CFG_DevExtEncoderChannel		(CFG_Dev_ID + 84)

#define CFG_DevMotionWarnThreshold		(CFG_Dev_ID + 90)
#define CFG_DevMotionDisconnectFlag		(CFG_Dev_ID + 91)
#define CFG_DevIoWarnThreshold			(CFG_Dev_ID + 92)
#define CFG_DevIoDisconnectFlag			(CFG_Dev_ID + 93)
#define CFG_DevMotionRescanTime			(CFG_Dev_ID + 94)
#define CFG_DevIoRescanTime				(CFG_Dev_ID + 95)
///////////////////////////////////////////////////////////////////////////////
// Axis Feature
///////////////////////////////////////////////////////////////////////////////
#define FT_AxFunctionMap             (FT_Ax_ID + 0)    
#define FT_AxMaxVel                  (FT_Ax_ID + 1)    
#define FT_AxMaxAcc                  (FT_Ax_ID + 2) 
#define FT_AxMaxDec                  (FT_Ax_ID + 3)     
#define FT_AxMaxJerk                 (FT_Ax_ID + 4)  
#define FT_AxPulseInMap              (FT_Ax_ID + 5)    
#define FT_AxPulseInModeMap          (FT_Ax_ID + 6)
#define FT_AxPulseOutMap             (FT_Ax_ID + 7)    
#define FT_AxPulseOutModeMap         (FT_Ax_ID + 8)    
#define FT_AxAlmMap                  (FT_Ax_ID + 9)    
#define FT_AxInpMap                  (FT_Ax_ID + 10)    
#define FT_AxErcMap                  (FT_Ax_ID + 11) 
#define FT_AxErcEnableModeMap        (FT_Ax_ID + 12)   
#define FT_AxErcOnTimeMap            (FT_Ax_ID + 13)  
#define FT_AxErcOffTimeMap           (FT_Ax_ID + 14)  
#define FT_AxSdMap                   (FT_Ax_ID + 15)    
#define FT_AxElMap                   (FT_Ax_ID + 16)    
#define FT_AxSwMelMap                (FT_Ax_ID + 17)    
#define FT_AxSwPelMap                (FT_Ax_ID + 18)    
#define FT_AxHomeMap                 (FT_Ax_ID + 19)        
#define FT_AxBackLashMap             (FT_Ax_ID + 20)    
#define FT_AxVibrationMap            (FT_Ax_ID + 21)    
#define FT_AxAlarmMap				 (FT_Ax_ID + 22)
#define FT_AxCompareMap              (FT_Ax_ID + 23) //  [9/14/2011 dan.yang]
#define FT_AxLatchMap                (FT_Ax_ID + 24) //  [9/14/2011 dan.yang]
#define FT_AxCamDOMap                (FT_Ax_ID + 25) //  [9/14/2011 dan.yang]
#define FT_AxExtDriveMap             (FT_Ax_ID + 26) //  [9/14/2011 dan.yang]
#define FT_AxExtMasterSrcMap         (FT_Ax_ID + 27) //  [9/14/2011 dan.yang]
#define FT_AxGenDOMap                (FT_Ax_ID + 28) //  [9/14/2011 dan.yang]
#define FT_AxGenDIMap                (FT_Ax_ID + 29) //  [9/14/2011 dan.yang]
#define FT_AxSimStartSourceMap       (FT_Ax_ID + 30) //  [9/19/2011 dan.yang]
#define FT_AxHomeModeMap             (FT_Ax_ID + 31) //  [6/14/2012 dan.yang]
#define FT_AxIN1Map                  (FT_Ax_ID + 32) //  [12/15/2012 dan.yang]
#define FT_AxIN2Map                  (FT_Ax_ID + 33) //  [12/15/2012 dan.yang]
#define FT_AxIN3Map                  (FT_Ax_ID + 34) //  [12/15/2012 dan.yang]
#define FT_AxIN4Map                  (FT_Ax_ID + 35) //  [12/15/2012 dan.yang]
#define FT_AxIN5Map                  (FT_Ax_ID + 36) //  [12/15/2012 dan.yang]
#define FT_AxDIFilterMap             (FT_Ax_ID + 37) //  [1/8/2014 deng]
#define FT_AxJogMap                  (FT_Ax_ID + 38) //  [5/8/2014 dan.yang]
#define FT_AxSimStartSourceMapEx     (FT_Ax_ID + 39) //for 64 axes
///////////////////////////////////////////////////////////////////////////////
// Axis Parameter
///////////////////////////////////////////////////////////////////////////////
#define PAR_AxVelLow                 (PAR_Ax_ID + 0)    
#define PAR_AxVelHigh                (PAR_Ax_ID + 1)    
#define PAR_AxAcc                    (PAR_Ax_ID + 2)    
#define PAR_AxDec                    (PAR_Ax_ID + 3)    
#define PAR_AxJerk                   (PAR_Ax_ID + 4) 
#define PAR_AxHomeExMode             (PAR_Ax_ID + 5)   
#define PAR_AxHomeExSwitchMode       (PAR_Ax_ID + 6)  
//#define PAR_AxHomeExCrossDistance    (PAR_Ax_ID + 7)
#define PAR_AxHomeCrossDistance		 (PAR_Ax_ID + 7)
#define PAR_AxJerkL                  (PAR_Ax_ID + 8)

//For fucai. 2014.4.11
#define PAR_AxJogVelLow              (PAR_Ax_ID + 9) 
#define PAR_AxJogVelHigh             (PAR_Ax_ID + 10)
#define PAR_AxJogAcc                 (PAR_Ax_ID + 11) 
#define PAR_AxJogDec                 (PAR_Ax_ID + 12)
#define PAR_AxJogJerk                (PAR_Ax_ID + 13)  

#define PAR_AxHomeVelLow             (PAR_Ax_ID + 14)    
#define PAR_AxHomeVelHigh            (PAR_Ax_ID + 15)    
#define PAR_AxHomeAcc                (PAR_Ax_ID + 16)    
#define PAR_AxHomeDec                (PAR_Ax_ID + 17)    
#define PAR_AxHomeJerk               (PAR_Ax_ID + 18) 

#define PAR_AxDriverSWVersion            (PAR_Ax_ID + 35)
#define PAR_AxDriverStatus             	 (PAR_Ax_ID + 36)
#define PAR_AxDriverModelNumber          (PAR_Ax_ID + 37)
#define PAR_AxDriverSerialNumber         (PAR_Ax_ID + 38)
#define PAR_AxDriverActualTor         	 (PAR_Ax_ID + 39)
//#define PAR_AxDriverVendorID         	 (PAR_Ax_ID + 40)
//#define PAR_AxDriverReserved2          	 (PAR_Ax_ID + 41)
#define PAR_AxJerkFactor				 (PAR_Ax_ID + 42)
#define PAR_AxHomeJerkFactor			 (PAR_Ax_ID + 43)

#define PAR_AxTargetPosition			 (PAR_Ax_ID + 44) //I32	
#define PAR_AxTargetVelocity			 (PAR_Ax_ID + 45) //I32
#define PAR_AxTargetTorque				 (PAR_Ax_ID + 46) //I16
#define PAR_AxControlWord      			 (PAR_Ax_ID + 47) //U16
#define PAR_AxStatusWord      			 (PAR_Ax_ID + 48) //U16
#define PAR_AxOperationMode      		 (PAR_Ax_ID + 49) //U8

#define PAR_AxMinAcc					 (PAR_Ax_ID + 50)//dan.yang 2015.8.12
#define PAR_AxJerkValue                  (PAR_Ax_ID + 51) //ydd 17.3.23. Add for PCI-1240
#define PAR_AxDLValue					(PAR_Ax_ID + 52) //ydd 17.3.23. Add for PCI-1240
///////////////////////////////////////////////////////////////////////////////
// Axis Config
///////////////////////////////////////////////////////////////////////////////
#define CFG_AxPPU                    (CFG_Ax_ID + 50)    
#define CFG_AxPhyID                  (CFG_Ax_ID + 51)    
#define CFG_AxMaxVel                 (CFG_Ax_ID + 52)    
#define CFG_AxMaxAcc                 (CFG_Ax_ID + 53)    
#define CFG_AxMaxDec                 (CFG_Ax_ID + 54)    
#define CFG_AxMaxJerk                (CFG_Ax_ID + 55)    
#define CFG_AxPulseInMode            (CFG_Ax_ID + 56)    
#define CFG_AxPulseInLogic           (CFG_Ax_ID + 57)    
#define CFG_AxPulseInSource          (CFG_Ax_ID + 58)    
#define CFG_AxPulseOutMode           (CFG_Ax_ID + 59)    
#define CFG_AxAlmEnable              (CFG_Ax_ID + 60)    
#define CFG_AxAlmLogic               (CFG_Ax_ID + 61)    
#define CFG_AxAlmReact               (CFG_Ax_ID + 62)    
#define CFG_AxInpEnable              (CFG_Ax_ID + 63) 
#define CFG_AxInpLogic               (CFG_Ax_ID + 64)    
#define CFG_AxErcLogic               (CFG_Ax_ID + 65)    
#define CFG_AxErcOnTime              (CFG_Ax_ID + 66)    
#define CFG_AxErcOffTime             (CFG_Ax_ID + 67)    
#define CFG_AxErcEnableMode          (CFG_Ax_ID + 68)    
#define CFG_AxSdEnable               (CFG_Ax_ID + 69)    
#define CFG_AxSdLogic                (CFG_Ax_ID + 70)    
#define CFG_AxSdReact                (CFG_Ax_ID + 71)    
#define CFG_AxSdLatch                (CFG_Ax_ID + 72)    
#define CFG_AxElEnable               (CFG_Ax_ID + 73)    
#define CFG_AxElLogic                (CFG_Ax_ID + 74)    
#define CFG_AxElReact                (CFG_Ax_ID + 75)    
#define CFG_AxSwMelEnable            (CFG_Ax_ID + 76)    
#define CFG_AxSwPelEnable            (CFG_Ax_ID + 77)    
#define CFG_AxSwMelReact             (CFG_Ax_ID + 78)    
#define CFG_AxSwPelReact             (CFG_Ax_ID + 79)    
#define CFG_AxSwMelValue             (CFG_Ax_ID + 80)    
#define CFG_AxSwPelValue             (CFG_Ax_ID + 81)    
#define CFG_AxHomeMode               (CFG_Ax_ID + 82)  
#define CFG_AxHomeDir                (PAR_Ax_ID + 83)  
#define CFG_AxHomeSwitchMode         (PAR_Ax_ID + 84)  
#define CFG_AxHomePosition           (PAR_Ax_ID + 85)  
#define CFG_AxHomeCrossDistance      (PAR_Ax_ID + 86) 
#define CFG_AxOrgEnable              (CFG_Ax_ID + 87)  
#define CFG_AxOrgLogic               (CFG_Ax_ID + 88)  
#define CFG_AxEzEnable               (CFG_Ax_ID + 89)  
#define CFG_AxEzLogic                (CFG_Ax_ID + 90)  
#define CFG_AxEzCount                (CFG_Ax_ID + 91)  
#define CFG_AxBacklashEnable         (CFG_Ax_ID + 92)  
#define CFG_AxBacklashPulses         (CFG_Ax_ID + 93)  
#define CFG_AxVibrationEnable        (CFG_Ax_ID + 94)  
#define CFG_AxVibrationReverseTime   (CFG_Ax_ID + 95)  
#define CFG_AxVibrationForwardTime   (CFG_Ax_ID + 96)
#define CFG_AxPositionLagEn          (CFG_Ax_ID + 97)  
#define CFG_AxMaxPositionLag         (CFG_Ax_ID + 98)  
#define CFG_AxEmgReaction	         (CFG_Ax_ID + 99)  
#define CFG_AxLatchLogic	         (CFG_Ax_ID + 100)  
#define CFG_AxHomeResetEnable        (CFG_Ax_ID + 101) 
#define CFG_AxCmpSrc		         (CFG_Ax_ID + 102)
#define CFG_AxCmpMethod		         (CFG_Ax_ID + 103)
#define CFG_AxCmpPulseMode		     (CFG_Ax_ID + 104)
#define CFG_AxCmpPulseLogic		     (CFG_Ax_ID + 105)
#define CFG_AxCmpPulseWidth		     (CFG_Ax_ID + 106)
#define CFG_AxCmpEnable		         (CFG_Ax_ID + 107)
#define CFG_AxRange                  (CFG_Ax_ID + 108)
#define CFG_AxGenDoEnable            (CFG_Ax_ID + 109)
#define CFG_AxExtMasterSrc           (CFG_Ax_ID + 110)
#define CFG_AxExtSelEnable           (CFG_Ax_ID + 111)
#define CFG_AxExtPulseNum            (CFG_Ax_ID + 112)
#define CFG_AxOrgLatch               (CFG_Ax_ID + 113) 
#define CFG_AxOutLogic 				 (CFG_Ax_ID + 114)
#define CFG_AxDirLogic 				 (CFG_Ax_ID + 115)
#define CFG_AxExtPulseInMode         (CFG_Ax_ID + 116)
#define CFG_AxExtPresetNum			 (CFG_Ax_ID + 117)
#define CFG_AxErcOffTmEnable         (CFG_Ax_ID + 118) 
#define CFG_AxAuxOutEnable           (CFG_Ax_ID + 119) 
#define CFG_AxAuxOutTime             (CFG_Ax_ID + 120)

/*ydd add for pci1245 and pci1265 2011-03-08 */
#define CFG_AxCamDOEnable            (CFG_Ax_ID + 121) 
#define CFG_AxCamDOLoLimit           (CFG_Ax_ID + 122)
#define CFG_AxCamDOHiLimit           (CFG_Ax_ID + 123)
#define CFG_AxCamDOMode              (CFG_Ax_ID + 124)
#define CFG_AxCamDODir               (CFG_Ax_ID + 125)
#define CFG_AxCamDOCmpSrc            (CFG_Ax_ID + 126)
#define CFG_AxCamDOLogic             (CFG_Ax_ID + 127)
#define CFG_AxModuleRange            (CFG_Ax_ID + 128)
#define CFG_AxBacklashVel            (CFG_Ax_ID + 129)
#define CFG_AxLatchEnable            (CFG_Ax_ID + 130)
#define CFG_AxPulseInMaxFreq         (CFG_Ax_ID + 131) //  [6/20/2011 dan.yang]
#define CFG_AxSimStartSource         (CFG_Ax_ID + 132) //  [9/19/2011 dan.yang]
#define CFG_AxOrgReact               (CFG_Ax_ID + 133) //  [12/26/2011 dan.yang]
#define CFG_AxIN1StopEnable         (CFG_Ax_ID + 134) //  [12/14/2012 dan.yang]
#define CFG_AxIN1StopReact          (CFG_Ax_ID + 135) //  [12/14/2012 dan.yang]
#define CFG_AxIN1StopLogic          (CFG_Ax_ID + 136) //  [12/14/2012 dan.yang]
#define CFG_AxIN2StopEnable         (CFG_Ax_ID + 137) //  [12/14/2012 dan.yang]
#define CFG_AxIN2StopReact          (CFG_Ax_ID + 138) //  [12/14/2012 dan.yang]
#define CFG_AxIN2StopLogic          (CFG_Ax_ID + 139) //  [12/14/2012 dan.yang]
#define CFG_AxIN4StopEnable         (CFG_Ax_ID + 140) //  [12/14/2012 dan.yang]
#define CFG_AxIN4StopReact          (CFG_Ax_ID + 141) //  [12/14/2012 dan.yang]
#define CFG_AxIN4StopLogic          (CFG_Ax_ID + 142) //  [12/14/2012 dan.yang]
#define CFG_AxIN5StopEnable         (CFG_Ax_ID + 143) //  [12/14/2012 dan.yang]
#define CFG_AxIN5StopReact          (CFG_Ax_ID + 144) //  [12/14/2012 dan.yang]
#define CFG_AxIN5StopLogic          (CFG_Ax_ID + 145) //  [12/14/2012 dan.yang]
//latch buffer://  [3/6/2013 dan.yang]
#define CFG_AxLatchBufEnable         (CFG_Ax_ID + 146)
#define CFG_AxLatchBufMinDist        (CFG_Ax_ID + 147)
#define CFG_AxLatchBufEventNum       (CFG_Ax_ID + 148)
#define CFG_AxLatchBufSource         (CFG_Ax_ID + 149) 
#define CFG_AxLatchBufAxisID         (CFG_Ax_ID + 150)
#define CFG_AxLatchBufEdge           (CFG_Ax_ID + 151)
#define CFG_AxHomeOffsetDistance     (CFG_Ax_ID + 152)
#define CFG_AxHomeOffsetVel          (CFG_Ax_ID + 153)
//pwm //[7/15/2013]zhaocui add
#define CFG_AxPWMFreq				 (CFG_Ax_ID + 154) 
#define CFG_AxPWMDuty				 (CFG_Ax_ID + 155)
#define CFG_AxPPUDenominator         (CFG_Ax_ID + 156)  //  [8/31/2013 dan.yang]
#define CFG_AxGantryMaxDiffValue     (CFG_Ax_ID + 157) //  [9/3/2013 dan.yang]
//  [10/29/2013 dan.yang]:Add channel
#define CFG_AxCh1CmpEnable		         (CFG_Ax_ID + 159)
#define CFG_AxCh1CmpPulseLogic		     (CFG_Ax_ID + 160)

#define CFG_AxCh2CmpEnable		         (CFG_Ax_ID + 161)
#define CFG_AxCh2CmpPulseLogic		     (CFG_Ax_ID + 162)

#define CFG_AxCh3CmpEnable		         (CFG_Ax_ID + 163)
#define CFG_AxCh3CmpPulseLogic		     (CFG_Ax_ID + 164)

//20131120 zhaocui add
#define CFG_AxPelToleranceEnable     (CFG_Ax_ID + 165)
#define CFG_AxPelToleranceValue      (CFG_Ax_ID + 166)
#define CFG_AxSwPelToleranceEnable   (CFG_Ax_ID + 167)
#define CFG_AxSwPelToleranceValue    (CFG_Ax_ID + 168)

#define CFG_AxCmpPulseWidthEx        (CFG_Ax_ID + 169)

#define CFG_AxMelToleranceEnable     (CFG_Ax_ID + 170)
#define CFG_AxMelToleranceValue      (CFG_Ax_ID + 171)
#define CFG_AxSwMelToleranceEnable   (CFG_Ax_ID + 172)
#define CFG_AxSwMelToleranceValue    (CFG_Ax_ID + 173) 

//20140107 zhaocui add
#define CFG_AxALMFilterTime           (CFG_Ax_ID + 174)
#define CFG_AxLMTPFilterTime          (CFG_Ax_ID + 175)
#define CFG_AxLMTNFilterTime          (CFG_Ax_ID + 176)
#define CFG_AxIN1FilterTime           (CFG_Ax_ID + 177)
#define CFG_AxIN2FilterTime           (CFG_Ax_ID + 178)
#define CFG_AxORGFilterTime           (CFG_Ax_ID + 179)
#define CFG_AxIN4FilterTime           (CFG_Ax_ID + 180)
#define CFG_AxIN5FilterTime           (CFG_Ax_ID + 181)

#define CFG_AxEncoderRatio           (CFG_Ax_ID + 182)//20131203 zhaocui add 
#define CFG_AxMaxErrCount            (CFG_Ax_ID + 183)//20131203 zhaocui add    
#define CFG_AxResponseTime			 (CFG_Ax_ID + 184)//20131203 zhaocui add
#define	CFG_AxMaxCorrectTimes		 (CFG_Ax_ID + 185)//20131203 zhaocui add 
//  [1/16/2014 deng]
#define CFG_AxisMultiCmpDeviation     (CFG_Ax_ID + 186)
#define CFG_AxForcePWMOutTime         (CFG_Ax_ID + 187)
//  [4/29/2014 deng]
#define CFG_AxLatchStopEnable         (CFG_Ax_ID + 188)
#define CFG_AxLatchStopReact          (CFG_Ax_ID + 189)
#define CFG_AxPulseStopSrc            (CFG_Ax_ID + 190) 
#define CFG_AxJogVLTime               (CFG_Ax_ID + 191)

#define CFG_AxPulseOutReverse         (CFG_Ax_ID + 192) //  [3/31/2014 dan.yang]: Reverse Pulse/Dir and CW/CCW pulse out mode for fucai
#define CFG_AxKillDec                 (CFG_Ax_ID + 193) //  [5/9/2014 kai.yang] added for DIStop dec

#define CFG_AxJogVelLow              (CFG_Ax_ID + 194)    //[7/10/2014 kai.yang]
#define CFG_AxJogVelHigh             (CFG_Ax_ID + 195)    //[7/10/2014 kai.yang]
#define CFG_AxJogAcc                 (CFG_Ax_ID + 196)    //[7/10/2014 kai.yang]
#define CFG_AxJogDec                 (CFG_Ax_ID + 197)    //[7/10/2014 kai.yang]
#define CFG_AxJogJerk                (CFG_Ax_ID + 198)    //[7/10/2014 kai.yang]
#define CFG_AxMaxErrorCnt            (CFG_Ax_ID + 199)    //[10/13/2014 kai.yang]
#define CFG_AxCounterMax             (CFG_Ax_ID + 200)    //[10/15/2014 kai.yang]
#define CFG_AxOverflowMode           (CFG_Ax_ID + 201)    //[10/15/2014 kai.yang]
#define CFG_AxGantryActDiffValue     (CFG_Ax_ID + 202)    //[11/11/2014 kai.yang]
#define CFG_AxPelLogic               (CFG_Ax_ID + 203)//  [11/21/2014 deng]
#define CFG_AxMelLogic               (CFG_Ax_ID + 204)//  [11/21/2014 deng]
#define CFG_AxSetCmpDO               (CFG_Ax_ID + 205)//  [12/2/2014 deng]

//YDD 2015.4.11 Add for salehi copr.
#define CFG_AxMPGOffsetEnable		 (CFG_Ax_ID + 206)     
#define CFG_AxMPGOffsetSum			 (CFG_Ax_ID + 207)   
//YDD end

//YDD 2015.5.12 Add for Drlaser
#define CFG_AxIN1StopEdge			 (CFG_Ax_ID + 208)        //邊緣
#define CFG_AxIN2StopEdge			 (CFG_Ax_ID + 209)
#define CFG_AxIN4StopEdge			 (CFG_Ax_ID + 210)
#define CFG_AxIN5StopEdge			 (CFG_Ax_ID + 211)

#define CFG_AxIN1OffsetValue		 (CFG_Ax_ID + 212)    //DI offset value
#define CFG_AxIN2OffsetValue		 (CFG_Ax_ID + 213)
#define CFG_AxIN4OffsetValue		 (CFG_Ax_ID + 214)
#define CFG_AxIN5OffsetValue		 (CFG_Ax_ID + 215)
//YDD Add End

//[dan.yang]Add for MPG
#define CFG_AxMPGMaxVel				 (CFG_Ax_ID + 216)			//MPR vel
#define CFG_AxMPGAcc				 (CFG_Ax_ID + 217)
#define CFG_AxMPGDec				 (CFG_Ax_ID + 218)
#define CFG_AxMPGStopReact			 (CFG_Ax_ID + 219)
#define CFG_AxJogPAssign			 (CFG_Ax_ID + 220)    //[5/8/2015 Andy.Wang]
#define CFG_AxJogNAssign			 (CFG_Ax_ID + 221)	  //[5/8/2015 Andy.Wang]
#define CFG_AxCamDOAssign			 (CFG_Ax_ID + 222)	  //[5/8/2015 Andy.Wang]
#define CFG_AxIN1StopAssign			 (CFG_Ax_ID + 223)	  //[5/12/2015 Andy.Wang]
#define CFG_AxTorqueConstData	     (CFG_Ax_ID + 224)	  //[7/29/2015 Andy.Wang]
#define CFG_AxTorqueEnable           (CFG_Ax_ID + 225)	  //[8/6/2015 Andy.Wang]
#define CFG_AxJogJerkFactor			 (CFG_Ax_ID + 226)	  //[2/22/2016 Andy.Wang]

#define CFG_AxDIStartTime			 (CFG_Ax_ID + 227)
#define CFG_AxDIStartEdge			 (CFG_Ax_ID + 228)
#define CFG_AxHomeORGSide			 (CFG_Ax_ID + 229) //YDD Add for jinghui. 2016.5.6
#define CFG_AxCompensateEnable		 (CFG_Ax_ID + 230) //only for 技鼎(PCI-1285)
#define CFG_AxCmpTrigPathEnable		 (CFG_Ax_ID + 231) //only for Salahi(PCI-1285)
#define CFG_AxCounterMin             (CFG_Ax_ID + 232)

#define CFG_AxMaxTorque				 (CFG_Ax_ID + 233)
#define CFG_AxMaxMotorSpeed			 (CFG_Ax_ID + 234)
#define CFG_AxSvOnLogic				 (CFG_Ax_ID + 235)
#define CFG_AxGantryCompFactor		 (CFG_Ax_ID + 237)	  //[3/4/2016 Jayce]
#define CFG_AxRstLogic               (CFG_Ax_ID + 238)  
#define CFG_AxRstOn			         (CFG_Ax_ID + 239)
#define CFG_AxErcOn			         (CFG_Ax_ID + 240) 

/************************************************************************/
/* dan.yang 2014.11.22 Add for EtherCAT                                 */
/************************************************************************/
#define CFG_CH_DaqDiInvertEnable		CFG_CH_ID + 0
#define CFG_CH_DaqDiLowFilter			CFG_CH_ID + 1
#define CFG_CH_DaqDiHighFilter			CFG_CH_ID + 2
#define CFG_CH_DaqDoFsvEnable			CFG_CH_ID + 3
#define CFG_CH_DaqAoRange				CFG_CH_ID + 4
#define CFG_CH_DaqAiRange				CFG_CH_ID + 5
#define CFG_CH_DaqAiEnable				CFG_CH_ID + 6
#define CFG_CH_DaqAiIntegrationTime		CFG_CH_ID + 7
#define CFG_CH_DaqAoFsv				    CFG_CH_ID + 8
#define CFG_CH_DaqAoStartup 		    CFG_CH_ID + 9
#define CFG_CH_DaqAoEnable				CFG_CH_ID + 23

/************************************************************************/
/* andy.wang 2015.04.21 Add for EtherCAT Counter                        */
/************************************************************************/
#define CFG_CH_DaqCntEnable				CFG_CH_ID + 10
#define CFG_CH_DaqCntPulseInMode		CFG_CH_ID + 11
#define CFG_CH_DaqCntInitValue			CFG_CH_ID + 12
#define CFG_CH_DaqCntMaxValue			CFG_CH_ID + 13
#define CFG_CH_DaqCntOverflowMode		CFG_CH_ID + 14
#define CFG_CH_DaqCntLatchEnable		CFG_CH_ID + 15
#define CFG_CH_DaqCntLatchEdge			CFG_CH_ID + 16
#define CFG_CH_DaqCntCmpEnable			CFG_CH_ID + 17
#define CFG_CH_DaqCntCmpMethod			CFG_CH_ID + 18
#define CFG_CH_DaqCntCmpPulseEnable		CFG_CH_ID + 19
#define CFG_CH_DaqCntCmpPulseMode		CFG_CH_ID + 20
#define CFG_CH_DaqCntCmpPulseLogic		CFG_CH_ID + 21
#define CFG_CH_DaqCntCmpPulseWidth		CFG_CH_ID + 22
//////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Group Parameter
///////////////////////////////////////////////////////////////////////////////
#define PAR_GpVelLow                 (PAR_Gp_ID + 0)    
#define PAR_GpVelHigh                (PAR_Gp_ID + 1)    
#define PAR_GpAcc                    (PAR_Gp_ID + 2)    
#define PAR_GpDec                    (PAR_Gp_ID + 3)   
#define PAR_GpJerk                   (PAR_Gp_ID + 4) 
#define PAR_GpGroupID                (PAR_Gp_ID + 5)
#define PAR_GpJerkL                  (PAR_Gp_ID + 6) 
#define PAR_GpIsPathDec              (PAR_Gp_ID + 7) 
#define PAR_GpRefPlane               (PAR_Gp_ID + 8)  //  [6/20/2011 dan.yang]
#define PAR_GpJerkFactor	         (PAR_Gp_ID + 9) 
#define PAR_GpJerkValue				 (PAR_Gp_ID + 10) //ydd 17.3.23. Add for PCI-1240
#define PAR_GpDLValue				 (PAR_Gp_ID + 11) //ydd 17.3.23. Add for PCI-1240
///////////////////////////////////////////////////////////////////////////////
// Group Config
///////////////////////////////////////////////////////////////////////////////
#define CFG_GpMaxVel                 (CFG_Gp_ID + 0)    
#define CFG_GpMaxAcc                 (CFG_Gp_ID + 1) 
#define CFG_GpMaxDec                 (CFG_Gp_ID + 2)    
#define CFG_GpMaxJerk                (CFG_Gp_ID + 3) 
#define CFG_GpPPU                    (CFG_Gp_ID + 4)     
#define CFG_GpAxesInGroup            (CFG_Gp_ID + 5)  
#define CFG_GpGroupID                (CFG_Gp_ID + 6)  
#define CFG_GpBldTime                (CFG_Gp_ID + 7) //  [6/2/2011 dan.yang]
#define CFG_GpSFEnable               (CFG_Gp_ID + 8) //  [6/2/2011 dan.yang]
#define CFG_GpVectorEnable           (CFG_Gp_ID + 13) //  [6/5/2013 dan.yang]
#define CFG_GpSpdFwdVelEn            (CFG_Gp_ID + 14) //  [6/22/2013 dan.yang]

//Add for fuqiang.2016.4.14
#define CFG_GpSFMinAngle			 (CFG_Gp_ID + 15) 
#define CFG_GpSFMaxAngle			 (CFG_Gp_ID + 16) 
#define CFG_GpSFSpeedRatio			 (CFG_Gp_ID + 17) 
#define CFG_GpSFMinCornerTime		 (CFG_Gp_ID + 18) 
//end.

#define CFG_GpAxesInGroupEx			 (CFG_Gp_ID + 19) //for 64 axes
//Add 17.7.4
#define CFG_GpPWMLinkVel			(CFG_Gp_ID + 20) 
#define CFG_GpPWMMonitorMode		(CFG_Gp_ID + 21) 
#define CFG_GpPWMRefVel				(CFG_Gp_ID + 22) 

//by dujunling 2012.11.23
typedef enum
{
	GM_PATTERN_ID_RefPlane=1,
	GM_PATTERN_ID_UNIT,
	GM_PATTERN_ID_Coordinate,
	GM_PATTERN_ID_PathControl,
	GM_PATTERN_ID_DistanceMode
}GM_PATTERN_ID;
//Robot zhaocui add 201307
#define CFG_RbLengthArm1           (CFG_RB_ID + 0)
#define CFG_RbLengthArm2           (CFG_RB_ID + 1)
#define CFG_RbLengthArm3           (CFG_RB_ID + 2)
#define CFG_RbHandMode             (CFG_RB_ID + 3)
#define CFG_RbSFEnable             (CFG_RB_ID + 4)
#define CFG_RbLengthArm4           (CFG_RB_ID + 5)
#define CFG_RbLengthArm5           (CFG_RB_ID + 6)
#define CFG_RbCsys                 (CFG_RB_ID + 7)
#define CFG_RbJogAxis              (CFG_RB_ID + 8)
#define CFG_RbRZCOUPLING           (CFG_RB_ID + 9)
#define CFG_RbRZCFNumerator        (CFG_RB_ID + 10)
#define CFG_RbRZCFDenominator      (CFG_RB_ID + 11)
#define CFG_RbScaraAxisMode	       (CFG_RB_ID + 12)
#define CFG_RbJ1J2CouplingEn       (CFG_RB_ID + 13)

//ydd. 18.1.25. Add for movelink
#define CFG_RbMoveLinkCSAngle       (CFG_RB_ID + 14)
#define CFG_RbMoveLinkAutoEn		(CFG_RB_ID + 15)

#define  PAR_RbVelLow				(PAR_RB_ID + 0)
#define  PAR_RbVelHigh				(PAR_RB_ID + 1)
#define  PAR_RbAcc					(PAR_RB_ID + 2)
#define  PAR_RbDec					(PAR_RB_ID + 3)
#define  PAR_RbJerk					(PAR_RB_ID + 4)
#define  PAR_RbRefPlane				(PAR_RB_ID + 5)
#endif // __ADV_MOT_PROP_ID_H__
