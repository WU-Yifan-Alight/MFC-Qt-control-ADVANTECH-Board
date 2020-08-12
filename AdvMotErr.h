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


#ifndef __ADV_MOT_ERR_H__
#define __ADV_MOT_ERR_H__

#ifndef SUCCESS
#define SUCCESS						0x00000000
#endif
#define Warning						0x10000000
#define FuncError					0x80000000
#define CommError					0x80001000
#define MotionError					0x80002000
#define DaqError					0x80003000
#define DevEvtError					0x80004000
#define DspError                    0x80005000 //  [9/26/2011 dan.yang]
#define DspAxError                  0x80005100 //  [9/26/2011 dan.yang]
#define DspGpError                  0x80005200 //  [9/26/2011 dan.yang]
#define DspRbError                  0x80005500
#define GmError						0x81000000	//by dujunling on 2012.11.22 for GM code error

#define ECTError                    0x83000000  //  [9/22/2014 dan]: Add for EtherCAT
#define ECTDevError					0x83010000  //  [3/24/2015 Andy] : EtherCAT master & slave error 
#define ECTDevSDOError				0x83020000	//Error from SDO communication 0x8301 XXXX
#define ECTMotionError				0x83030000	//Error from Motion port communication
#define ECTIOError					0x83040000	//Error from IO port communication
#define ECTAxError					0x83050000  //Error from CiA402 ecat driver
#define ECAT_DriveError		        0x83100000  //  [3/24/2015 Andy] : EtherCAT Drive error 

#define InvalidDevNumber			(FuncError + 0)
#define DevRegDataLost			    (FuncError + 1)
#define LoadDllFailed				(FuncError + 2)
#define GetProcAddrFailed           (FuncError + 3)
#define MemAllocateFailed           (FuncError + 4)
#define InvalidHandle				(FuncError + 5)
#define CreateFileFailed            (FuncError + 6)
#define OpenEventFailed             (FuncError + 7)
#define EventTimeOut                (FuncError + 8)
#define InvalidInputParam			(FuncError + 9)
#define PropertyIDNotSupport		(FuncError + 10)
#define PropertyIDReadOnly			(FuncError + 11)
#define ConnectWinIrqFailed		    (FuncError + 12)

#define InvalidAxCfgVel				(FuncError + 13)
#define InvalidAxCfgAcc				(FuncError + 14)
#define InvalidAxCfgDec				(FuncError + 15)
#define InvalidAxCfgJerk			(FuncError + 16)
#define InvalidAxParVelLow			(FuncError + 17)
#define InvalidAxParVelHigh			(FuncError + 18)
#define InvalidAxParAcc				(FuncError + 19)
#define InvalidAxParDec				(FuncError + 20)
#define InvalidAxParJerk			(FuncError + 21)
#define InvalidAxPulseInMode		(FuncError + 22)
#define InvalidAxPulseOutMode		(FuncError + 23)
#define InvalidAxAlarmEn			(FuncError + 24)
#define InvalidAxAlarmLogic			(FuncError + 25)
#define InvalidAxInPEn				(FuncError + 26)
#define InvalidAxInPLogic			(FuncError + 27)
#define InvalidAxHLmtEn				(FuncError + 28)
#define InvalidAxHLmtLogic			(FuncError + 29)
#define InvalidAxHLmtReact			(FuncError + 30)
#define InvalidAxSLmtPEn			(FuncError + 31)
#define InvalidAxSLmtPReact			(FuncError + 32)
#define InvalidAxSLmtPValue			(FuncError + 33)
#define InvalidAxSLmtMEn			(FuncError + 34)
#define InvalidAxSLmtMReact			(FuncError + 35)
#define InvalidAxSLmtMValue			(FuncError + 36)
#define InvalidAxOrgLogic			(FuncError + 37)
#define InvalidAxOrgEnable			(FuncError + 38)
#define InvalidAxEzLogic			(FuncError + 39)
#define InvalidAxEzEnable			(FuncError + 40)
#define InvalidAxEzCount			(FuncError + 41)
#define InvalidAxState  			(FuncError + 42)
#define InvalidAxInEnable			(FuncError + 43)


#define InvalidAxSvOnOff			(FuncError + 44)
#define InvalidAxDistance			(FuncError + 45)
#define InvalidAxPosition			(FuncError + 46)
#define InvalidAxHomeModeKw			(FuncError + 47)

#define InvalidAxCntInGp			(FuncError + 48)
#define AxInGpNotFound				(FuncError + 49)
#define AxIsInOtherGp				(FuncError + 50)
#define AxCannotIntoGp				(FuncError + 51)
#define GpInDevNotFound				(FuncError + 52)
#define InvalidGpCfgVel				(FuncError + 53)
#define InvalidGpCfgAcc				(FuncError + 54)
#define InvalidGpCfgDec				(FuncError + 55)
#define InvalidGpCfgJerk			(FuncError + 56)
#define InvalidGpParVelLow			(FuncError + 57)
#define InvalidGpParVelHigh	        (FuncError + 58)
#define InvalidGpParAcc				(FuncError + 59)
#define InvalidGpParDec				(FuncError + 60)
#define InvalidGpParJerk			(FuncError + 61)
#define JerkNotSupport		        (FuncError + 62)
#define ThreeAxNotSupport           (FuncError + 63)
#define DevIpoNotFinished		    (FuncError + 64)
#define InvalidGpState				(FuncError + 65)
#define OpenFileFailed		        (FuncError + 66)
#define InvalidPathCnt		        (FuncError + 67)
#define InvalidPathHandle		    (FuncError + 68)
#define InvalidPath                 (FuncError + 69)

#define IoctlError					(FuncError + 70)
#define AmnetRingUsed				(FuncError + 71)
#define DeviceNotOpened				(FuncError + 72)
#define InvalidRing					(FuncError + 73)
#define InvalidSlaveIP				(FuncError + 74)
#define InvalidParameter			(FuncError + 75)
#define InvalidGpCenterPosition		(FuncError + 76)
#define InvalidGpEndPosition		(FuncError + 77)
#define InvalidAddress				(FuncError + 78)
#define DeviceDisconnect			(FuncError + 79)
#define DataOutBufExceeded			(FuncError + 80)
#define SlaveDeviceNotMatch			(FuncError + 81)
#define SlaveDeviceError			(FuncError + 82)
#define SlaveDeviceUnknow			(FuncError + 83)
#define FunctionNotSupport			(FuncError + 84)
#define InvalidPhysicalAxis			(FuncError + 85)			//[Dean 2008.1.31]
#define InvalidVelocity				(FuncError + 86)			//[Dean 2008.2.5]
#define InvalidAxPulseInLogic		(FuncError + 87)			//[Dean 2008.2.13]
#define InvalidAxPulseInSource		(FuncError + 88)			//[Dean 2008.2.13]
#define InvalidAxErcLogic			(FuncError + 89)			//[Dean 2008.2.13]
#define InvalidAxErcOnTime			(FuncError + 90)			//[Dean 2008.2.13]
#define InvalidAxErcOffTime			(FuncError + 91)			//[Dean 2008.2.13]
#define InvalidAxErcEnableMode		(FuncError + 92)			//[Dean 2008.2.13]
#define InvalidAxSdEnable			(FuncError + 93)			//[Dean 2008.2.13]
#define InvalidAxSdLogic			(FuncError + 94)			//[Dean 2008.2.13]
#define InvalidAxSdReact			(FuncError + 95)			//[Dean 2008.2.13]
#define InvalidAxSdLatch			(FuncError + 96)			//[Dean 2008.2.13]
#define InvalidAxHomeResetEnable	(FuncError + 97)			//[Dean 2008.2.13]
#define InvalidAxBacklashEnable		(FuncError + 98)			//[Dean 2008.2.13]
#define InvalidAxBacklashPulses		(FuncError + 99)			//[Dean 2008.2.13]
#define InvalidAxVibrationEnable	(FuncError + 100)			//[Dean 2008.2.13]
#define InvalidAxVibrationRevTime	(FuncError + 101)			//[Dean 2008.2.13]
#define InvalidAxVibrationFwdTime	(FuncError + 102)			//[Dean 2008.2.13]
#define InvalidAxAlarmReact			(FuncError + 103)			//[Dean 2008.2.13]
#define InvalidAxLatchLogic			(FuncError + 104)			//[Dean 2008.2.13]
#define InvalidFwMemoryMode			(FuncError + 105)
#define InvalidConfigFile           (FuncError + 106)
#define InvalidAxEnEvtArraySize     (FuncError + 107)
#define InvalidAxEnEvtArray         (FuncError + 108)
#define InvalidGpEnEvtArraySize     (FuncError + 109)
#define InvalidGpEnEvtArray         (FuncError + 110)
#define InvalidIntervalData         (FuncError + 111)
#define InvalidEndPosition          (FuncError + 112)
#define InvalidAxisSelect			(FuncError + 113)
#define InvalidTableSize			(FuncError + 114)
#define InvalidGpHandle				(FuncError + 115)
#define InvalidCmpSource			(FuncError + 116)
#define InvalidCmpMethod			(FuncError + 117)
#define InvalidCmpPulseMode			(FuncError + 118)
#define InvalidCmpPulseLogic		(FuncError + 119)
#define InvalidCmpPulseWidth		(FuncError + 120)
#define InvalidPathFunctionID		(FuncError + 121)
#define SysBufAllocateFailed        (FuncError + 122)
#define SpeedFordFunNotSpported     (FuncError + 123)
#define InvalidNormVector			(FuncError + 124)//zhaocui add
#define InvalidCmpTimeTableCount    (FuncError + 125)
#define InvalidCmpTime              (FuncError + 126)
#define FWDownLoading               (FuncError + 127)//zhaocui add 20131209
#define FWVersionNotMatch           (FuncError + 128)//zhaocui add 20131209
#define InvalidAxParHomeVelLow      (FuncError + 129)//yangkai add 20140707
#define InvalidAxParHomeVelHigh     (FuncError + 130)//yangkai add 20140707
#define InvalidAxParHomeAcc         (FuncError + 131)//yangkai add 20140707
#define InvalidAxParHomeDec         (FuncError + 132)//yangkai add 20140707
#define InvalidAxParHomeJerk        (FuncError + 133)//yangkai add 20140707
#define InvalidAxCfgJogVelLow		(FuncError + 134)//yangkai add 20140707
#define InvalidAxCfgJogVelHigh		(FuncError + 135)//yangkai add 20140707
#define InvalidAxCfgJogAcc			(FuncError + 136)//yangkai add 20140707
#define InvalidAxCfgJogDec			(FuncError + 137)//yangkai add 20140707
#define InvalidAxCfgJogJerk			(FuncError + 138)//yangkai add 20140707
#define InvalidAxCfgKillDec			(FuncError + 139)//yangkai add 20140707
#define NotOpenAllAxes				(FuncError + 140)//yangkai add 20140707
#define NotSetServoComPort			(FuncError + 141)//yangkai add 20140707
#define OpenComPortFailed			(FuncError + 142)//yangkai add 20140707
#define ReadComPortTimeOut			(FuncError + 143)//yangkai add 20140707
#define SetComPortStateFailed		(FuncError + 144)//yangkai add 20140707
#define SevroTypeNotSupport			(FuncError + 145)//yangkai add 20140707
#define ReadComBufFailed			(FuncError + 146)//yangkai add 20140707
#define InvalidAxMaxErrorCnt		(FuncError + 147)//yangkai add 20141015
#define MoveModeNosupportBlend		(FuncError + 148)
#define CmpModeCannotGenDO			(FuncError + 149)

//AMONet Communication error
#define SlaveIOUpdateError			(FuncError + 150)
#define NoSlaveDevFound				(FuncError + 151)
#define MasterDevNotOpen            (FuncError + 152)
#define MasterRingNotOpen           (FuncError + 153)
#define CannotFindCenterby3P		(FuncError + 154)
#define InvalidAxCfgJogPAssign		(FuncError + 155)//andy.wang add 20150508
#define InvalidAxCfgJogNAssign		(FuncError + 156)//andy.wang add 20150508
#define InvalidAxCfgCamDOAssign	    (FuncError + 157)//andy.wang add 20150508
#define InvalidAxCfgDIStopAssign    (FuncError + 158)//andy.wang add 20150512  


//DAQ function  [1/24/2008 Dean] -----------------------------------
#define InvalidDIPort				(FuncError + 200)
#define InvalidDOPort				(FuncError + 201)
#define InvalidDOValue				(FuncError + 202)

//EVT function
#define CreateEventFailed           (FuncError + 203)
#define CreateThreadFailed          (FuncError + 204)

#define InvalidHomeModeEx           (FuncError + 205)
#define InvalidDirMode              (FuncError + 206)
#define AxHomeMotionFailed          (FuncError + 207)
#define ReadFileFailed              (FuncError + 208)
#define PathBufIsFull               (FuncError + 209)
#define PathBufIsEmpty              (FuncError + 210)
#define GetAuthorityFailed          (FuncError + 211)  //  [3/17/2011 dan.yang]
#define GpIDAllocatedFailed         (FuncError + 212)  //  [04/15/2011 dan.yang]
#define FirmWareDown                (FuncError + 213) //  [4/26/2011 dan.yang] todo
#define InvalidGpRadius             (FuncError + 214) //  [4/28/2011 dan.yang]
#define InvalidAxCmd                (FuncError + 215) //  [4/28/2011 dan.yang]
#define InvalidaxExtDrv             (FuncError + 216) //  [4/29/2011 dan.yang]
#define InvalidGpMovCmd             (FuncError + 217) //  [5/4/2011 dan.yang]
#define SpeedCurveNotSupported      (FuncError + 218) //  [5/20/2011 dan.yang]
#define InvalidCounterNo            (FuncError + 219) //  [5/24/2011 dan.yang]
#define InvalidPathMoveMode         (FuncError + 220) //  [6/2/2011 dan.yang]
#define PathSelStartCantRunInSpeedForwareMode (FuncError + 221) //  [6/21/2011 dan.yang]
#define InvalidCamTableID           (FuncError + 222) //  [6/23/2011 dan.yang]
#define InvalidCamPointRange        (FuncError + 223) //  [6/23/2011 dan.yang]
#define CamTableIsEmpty             (FuncError + 224) //  [6/23/2011 dan.yang]
#define InvalidPlaneVector          (FuncError + 225) //  [6/24/2011 dan.yang]
#define MasAxIDSameSlvAxID          (FuncError + 226) //  [6/24/2011 dan.yang]
#define InvalidGpRefPlane           (FuncError + 227) //  [7/4/2011 dan.yang]
#define InvalidAxModuleRange        (FuncError + 228) //  [7/8/2011 dan.yang]
#define DownloadFileFailed          (FuncError + 229) //  [7/12/2011 dan.yang]
#define InvalidFileLength           (FuncError + 230) //  [7/12/2011 dan.yang] 
#define InvalidCmpCnt               (FuncError + 231) //  [8/10/2011 dan.yang]
#define JerkExceededMaxValue        (FuncError + 232) //  [12/9/2011 dan.yang]
#define AbsMotionNotSupport         (FuncError + 233) //  [1/17/2012 dan.yang]
#define invalidAiRange              (FuncError + 234) //  [4/18/2012 dan.yang]
#define AIScaleFailed               (FuncError + 235) //  [4/18/2012 dan.yang]
#define AxInRobot                   (FuncError + 236) //  [7/31/2013 zhaocui]  
#define Invalid3DArcFlat            (FuncError + 237) //  [7/31/2013 zhaocui]
#define InvalidIpoMap               (FuncError + 238)
#define DataSizeNotCorrect          (FuncError + 239) //  [10/28/2013 dan.yang]
#define AxisNotFound                (FuncError + 240) //  [10/30/2013 dan.yang]
#define InvalidPathVelHigh          (FuncError + 241)  //  [12/10/2013 dan.yang]

#define InvalidRbParVelLow			(FuncError + 250) //  [8/5/2014 kai.yang]
#define InvalidRbParVelHigh	        (FuncError + 251) //  [8/5/2014 kai.yang]
#define InvalidRbParAcc				(FuncError + 252) //  [8/5/2014 kai.yang]
#define InvalidRbParDec				(FuncError + 253) //  [8/5/2014 kai.yang]
#define InvalidRbParJerk			(FuncError + 254) //  [8/5/2014 kai.yang]
#define InvalidRbState				(FuncError + 255) //  [8/5/2014 kai.yang]
#define InvalidRbHandle				(FuncError + 256) //  [8/5/2014 kai.yang]
#define InvalidRbRadius             (FuncError + 257) //  [8/5/2014 kai.yang]
#define InvalidRbMovCmd             (FuncError + 258) //  [8/5/2014 kai.yang]
#define NotOpenRobot				(FuncError + 259) //  [8/5/2014 kai.yang]
#define InvalidRbPoint				(FuncError + 260)//yangkai add 20150128
#define RbAngleExceeded				(FuncError + 261)//yangkai add 20150128

#define GetDIOFalied				(FuncError + 300) //  [11/16/2014 dan]
#define InvalidRingBufferCmd		(FuncError + 301) //  [12/10/2014 dan]
#define InvalidAoRange				(FuncError + 302) //  [12/17/2014 dan]
#define RingBufferOverFlow			(FuncError + 303) //  [12/18/2014 dan]
#define RbAreaExceeded              (FuncError + 304)
#define InvalidAiValue				(FuncError + 305)
#define InvalidAoValue				(FuncError + 306)
#define NoPreScanData               (FuncError + 307) //  [2/17/2016 dandan.yang]
#define GroupNotAssigned			(FuncError + 308) //  [2/17/2016 dandan.yang]
#define AxisNotOpened				(FuncError + 309)
#define DataCntExceeded             (FuncError + 310)
#define InvalidCamTable             (FuncError + 311)

#define HLmtPExceeded				(MotionError + 0)
#define HLmtNExceeded				(MotionError + 1)
#define SLmtPExceeded				(MotionError + 2)
#define SLmtNExceeded				(MotionError + 3)
#define AlarmHappened				(MotionError + 4)
#define EmgHappened					(MotionError + 5)
#define TimeLmtExceeded				(MotionError + 6)
#define DistLmtExceeded				(MotionError + 7)
#define InvalidPositionOverride		(MotionError + 8)			//[Dean 2008.2.18]
#define OperationErrorHappened		(MotionError + 9)
#define SimultaneousStopHappened	(MotionError + 10)
#define OverflowInPAPB				(MotionError + 11)
#define OverflowInIPO				(MotionError + 12)
#define STPHappened					(MotionError + 13)
#define SDHappened					(MotionError + 14)
#define AxisNoCmpDataLeft           (MotionError + 15)


#define DevEvtTimeOut				(DevEvtError + 1)
#define DevNoEvt			        (DevEvtError + 2)
//*************************************************************
#define Warning_AxWasInGp			(Warning + 1)
//inconsistent rate of PPU setting
#define Warning_GpInconsistRate     (Warning + 2)
#define Warning_GpInconsistPPU      (Warning + 3)
#define Warning_GpMoveDistanceCanntBeZero (Warning + 4)


// Dsp Error //  [9/26/2011 dan.yang]
// ----------------------------------------------------------------------------
#define ERR_SYS_TIME_OUT					(DspError + 0x01)
#define Dsp_PropertyIDNotSupport			(DspError + 0x02)
#define Dsp_PropertyIDReadOnly				(DspError + 0x03)

#define Dsp_InvalidParameter				(DspError + 0x04)
#define Dsp_DataOutBufExceeded				(DspError + 0x05)
#define Dsp_FunctionNotSupport				(DspError + 0x06)
#define Dsp_InvalidConfigFile				(DspError + 0x07)
#define Dsp_InvalidIntervalData				(DspError + 0x08)
#define Dsp_InvalidTableSize				(DspError + 0x09)
#define Dsp_InvalidTableID					(DspError + 0x0a)
#define Dsp_DataIndexExceedBufSize			(DspError + 0x0b)
#define Dsp_InvalidCompareInterval			(DspError + 0x0c)
#define Dsp_InvalidCompareRange				(DspError + 0x0d)
#define Dsp_PropertyIDWriteOnly				(DspError + 0x0e)
#define Dsp_NcError							(DspError + 0x0f)	
#define Dsp_CamTableIsInUse					(DspError + 0x10)	
#define Dsp_EraseBlockFailed				(DspError + 0x11)	
#define Dsp_ProgramFlashFailed				(DspError + 0x12)	
#define Dsp_WatchdogError					(DspError + 0x13)	
#define Dsp_ReadPrivateOverMaxTimes			(DspError + 0x14)	//[v1.0.8.4]
#define Dsp_InvalidPrivateID				(DspError + 0x15)	//[v1.0.8.4]
#define Dsp_DataNotReady					(DspError + 0x16)	//[v1.0.8.4]
#define Dsp_LastOperationNotOver 			(DspError + 0x17)
#define Dsp_WritePrivateTimeout 			(DspError + 0x18)
#define Dsp_FwIsDownloading                 (DspError + 0x19)
#define Dsp_FwDownloadStepError             (DspError + 0x20)

#define Dsp_InvalidDiLtcChanelID			(DspError + 0x21)
#define Dsp_InvalidDoCmpChanelID			(DspError + 0x22)
#define Dsp_InvalidDevPptValue				(DspError + 0x23)
#define Dsp_CmpCannotLinkMultiLtc			(DspError + 0x24)
#define Dsp_SDIOLinkError     			    (DspError + 0x25)
#define InvalidVerScanTable					(DspError + 0x26) 
#define InvalidVerEnablePos					(DspError + 0x27) 
#define VerMovLimitExceeded					(DspError + 0x28)
#define Dsp_InvalidTableName				(DspError + 0x29)
#define Dsp_SlaveDoNotSupportSDO			(DspError + 0x2a) 

#define Dsp_MIOInvalidSer					(DspError + 0x30)
#define Dsp_SDIInvalidSer					(DspError + 0x31)
#define Plink_SynTimeTooShort				(DspError + 0x32)


// Axis Error
// ----------------------------------------------------------------------------


#define Dsp_InvalidAxCfgVel				(DspAxError + 0x01)
#define Dsp_InvalidAxCfgAcc				(DspAxError + 0x02)
#define Dsp_InvalidAxCfgDec				(DspAxError + 0x03)
#define Dsp_InvalidAxCfgJerk			(DspAxError + 0x04)
#define Dsp_InvalidAxParVelLow			(DspAxError + 0x05)
#define Dsp_InvalidAxParVelHigh			(DspAxError + 0x06)
#define Dsp_InvalidAxParAcc				(DspAxError + 0x07)
#define Dsp_InvalidAxParDec				(DspAxError + 0x08)
#define Dsp_InvalidAxParJerk			(DspAxError + 0x09)
#define Dsp_InvalidAxPptValue			(DspAxError + 0x0a)
#define Dsp_InvalidAxState				(DspAxError + 0x0b)
#define Dsp_InvalidAxSvOnOff			(DspAxError + 0x0c)
#define Dsp_InvalidAxDistance			(DspAxError + 0x0d)
#define Dsp_InvalidAxPosition			(DspAxError + 0x0e)
#define Dsp_InvalidAxHomeMode			(DspAxError + 0x0f)
#define Dsp_InvalidPhysicalAxis			(DspAxError + 0x10)			
#define Dsp_HLmtPExceeded				(DspAxError + 0x11)
#define Dsp_HLmtNExceeded				(DspAxError + 0x12)
#define Dsp_SLmtPExceeded				(DspAxError + 0x13)
#define Dsp_SLmtNExceeded				(DspAxError + 0x14)
#define Dsp_AlarmHappened				(DspAxError + 0x15)
#define Dsp_EmgHappened					(DspAxError + 0x16)
#define Dsp_CmdValidOnlyInConstSec		(DspAxError + 0x17)			// Command valid only in the constant section
#define Dsp_InvalidAxCmd				(DspAxError + 0x18)
#define Dsp_InvalidAxHomeDirMode		(DspAxError + 0x19)
#define Dsp_AxisMustBeModuloAxis		(DspAxError + 0x1a)
#define Dsp_AxIdCantSameAsMasId			(DspAxError + 0x1b)
#define Dsp_CantResetPosiOfMasAxis		(DspAxError + 0x1c)
#define Dsp_InvalidAxExtDrvOperation	(DspAxError + 0x1d)
#define Dsp_AxAccExceededMaxAcc         (DspAxError + 0x1e)
#define Dsp_AxVelExceededMaxVel         (DspAxError + 0x1f)
#define Dsp_NotEnoughPulseForChgV   	(DspAxError + 0x20)
#define Dsp_NewVelMustGreaterThanVelLow (DspAxError + 0x21)
#define Dsp_InvalidAxGearMode 			(DspAxError + 0x22)
#define Dsp_InvalidGearRatio 			(DspAxError + 0x23)
#define Dsp_InvalidPWMDataCount			(DspAxError	+ 0x24)
#define	Dsp_InvalidAxPWMFreq			(DspAxError	+ 0x25)
#define	Dsp_InvalidAxPWMDuty			(DspAxError	+ 0x26)
#define Dsp_AxGantryExceedMaxDiffValue  (DspAxError + 0x27)
#define	Dsp_ChanelIsDisable				(DspAxError + 0x28)
#define	Dsp_ChanelBufferIsFull			(DspAxError + 0x29)
#define	Dsp_ChanelBufferIsEmpty			(DspAxError + 0x30)
#define Dsp_InvalidDoChanelID			(DspAxError + 0x31)
#define Dsp_LatchHappened               (DspAxError + 0x32)
#define Dsp_InvalidAxKillDec            (DspAxError + 0x33)
#define Dsp_InvalidAxJogVelLow          (DspAxError + 0x34)
#define Dsp_InvalidAxJogVelHigh         (DspAxError + 0x35)
#define Dsp_InvalidAxJogAcc             (DspAxError + 0x36)
#define Dsp_InvalidAxJogDec             (DspAxError + 0x37)
#define Dsp_InvalidAxJogJerk            (DspAxError + 0x38)
#define Dsp_InvalidAxHomeVelLow         (DspAxError + 0x39)
#define Dsp_InvalidAxHomeVelHigh        (DspAxError + 0x40)
#define Dsp_InvalidAxHomeAcc            (DspAxError + 0x41)
#define Dsp_InvalidAxHomeDec            (DspAxError + 0x42)
#define Dsp_InvalidAxHomeJerk           (DspAxError + 0x43)
#define Dsp_PosErrorCntExceed           (DspAxError + 0x44)
#define Dsp_InvalidAxCounterMax         (DspAxError + 0x45)        //ring counter
#define Dsp_InvalidAxOverflowMode       (DspAxError + 0x46)
#define Dsp_ImposeTimeLongerPTP         (DspAxError + 0x47)
#define Dsp_AxAngExceededMaxRotationAng (DspAxError + 0x48)
#define Dsp_AxAreaExceeded              (DspAxError + 0x49)
#define Dsp_AxDiStopAct					(DspAxError + 0x50) //dan.yang 2015.5.11 For guanghaojie
#define	Dsp_SWPELIsDisable				(DspAxError + 0x51)
#define	Dsp_SWMELIsDisable				(DspAxError + 0x52)
#define	Dsp_CMPIsDisable				(DspAxError + 0x53)
#define	Dsp_MotionDisConnect			(DspAxError + 0x54)

// Group Error //  [9/26/2011 dan.yang]
// ----------------------------------------------------------------------------
#define Dsp_InvalidAxCntInGp			(DspGpError + 0x01)
#define Dsp_AxInGpNotFound				(DspGpError + 0x02)
#define Dsp_AxIsInOtherGp				(DspGpError + 0x03)
#define Dsp_AxCannotIntoGp				(DspGpError + 0x04)
#define Dsp_GpInDevNotFound				(DspGpError + 0x05)
#define Dsp_InvalidGpCfgVel				(DspGpError + 0x06)
#define Dsp_InvalidGpCfgAcc				(DspGpError + 0x07)
#define Dsp_InvalidGpCfgDec				(DspGpError + 0x08)
#define Dsp_InvalidGpCfgJerk			(DspGpError + 0x09)
#define Dsp_InvalidGpParVelLow			(DspGpError + 0x0a)
#define Dsp_InvalidGpParVelHigh	        (DspGpError + 0x0b)
#define Dsp_InvalidGpParAcc				(DspGpError + 0x0c)
#define Dsp_InvalidGpParDec				(DspGpError + 0x0d)
#define Dsp_InvalidGpParJerk			(DspGpError + 0x0e)
#define Dsp_JerkNotSupport		        (DspGpError + 0x0f)
#define Dsp_ThreeAxNotSupport           (DspGpError + 0x10)
#define Dsp_DevIpoNotFinished		    (DspGpError + 0x11)
#define Dsp_InvalidGpState				(DspGpError + 0x12)
#define Dsp_OpenFileFailed		        (DspGpError + 0x13)
#define Dsp_InvalidPathCnt		        (DspGpError + 0x14)
#define Dsp_InvalidPathHandle		    (DspGpError + 0x15)
#define Dsp_InvalidPath                 (DspGpError + 0x16)
#define Dsp_GpSlavePositionOverMaster  	(DspGpError + 0x17)
#define Dsp_GpPathBufferOverflow 		(DspGpError + 0x19)
#define Dsp_InvalidPathFunctionID		(DspGpError + 0x1a)
#define Dsp_SysBufAllocateFailed        (DspGpError + 0x1b)
#define Dsp_InvalidGpCenterPosition		(DspGpError + 0x1c)
#define Dsp_InvalidGpEndPosition		(DspGpError + 0x1d)
#define Dsp_InvalidGpCmd				(DspGpError + 0x1e)
#define Dsp_AxHasBeenInInGp				(DspGpError + 0x1f)
#define Dsp_InvalidPathRange			(DspGpError + 0x20)
#define Dsp_InvalidNormVector			(DspGpError + 0x21)
//  [1/22/2014 deng]

#define Dsp_NotANumber					(DspGpError + 0x22)
#define Dsp_UnknownCmdID				(DspGpError + 0x23)
#define Dsp_InvalidJumpPosi				(DspGpError + 0x24)
#define Dsp_DivideByZero				(DspGpError + 0x25)
#define Dsp_IrVersionNotSupport			(DspGpError + 0x26)
#define Dsp_InvalidIrSource				(DspGpError + 0x27)
#define Dsp_InvalidVariableAddress		(DspGpError + 0x28)
#define Dsp_IntprIsRunning				(DspGpError + 0x29)
#define Dsp_ProgramNotloaded			(DspGpError + 0x2a)
#define Dsp_BreakPointsFulled			(DspGpError + 0x2b)
#define Dsp_MotionRTError				(DspGpError + 0x2c)
#define Dsp_AresAxisConflict			(DspGpError + 0x2d)



#define Dsp_RbInvalidGpid                        (DspRbError + 0x01)
#define Dsp_RbInvalidMode                        (DspRbError + 0x01)
#define Dsp_RbInvalidArmLength                   (DspRbError + 0x02)
#define Dsp_RbInvalidAxesNum                     (DspRbError + 0x03)
#define Dsp_RbInvalidHandDir                     (DspRbError + 0x04)
#define Dsp_RbAreaExceeded                       (DspRbError + 0x05)
#define Dsp_RbAngleExceeded                      (DspRbError + 0x06)
#define Dsp_RbSwLmtNotEnabled                    (DspRbError + 0x07)
#define Dsp_RbVectorDistExceededZTargetDist      (DspRbError + 0x08)
#define Dsp_RbInvalidPoint                       (DspRbError + 0x09)         
#define Dsp_RbInvalidCurrentHandDir              (DspRbError + 0x0a)        
#define Dsp_RbInvalidCoordinateSystem            (DspRbError + 0x0b)         
#define Dsp_RbInvalidCoordinateAxis              (DspRbError + 0x0c)         
#define Dsp_RbSpeedTooHigh                       (DspRbError + 0x0d)       
#define Dsp_RbInvalidState                       (DspRbError + 0x0e) 
#define Dsp_RbEmgHappened	                     (DspRbError + 0x0f)
#define Dsp_RbAlmHappened                        (DspRbError + 0x10)
#define Dsp_RbSLmtPExceeded	                     (DspRbError + 0x11)
#define Dsp_RbSLmtNExceeded	                     (DspRbError + 0x12)




//add by dujunling 2012.11.23
#define Gm_CodeError					(GmError + 0x100)
#define Gm_SystemError					(GmError + 0x200)

/////////////Gm_CodeError
#define	Gm_InvalidCharacter				(Gm_CodeError + 1)
#define Gm_InvalidCode					(Gm_CodeError + 2)
#define Gm_InvalidGCode					(Gm_CodeError + 3)
#define Gm_InvalidMCode					(Gm_CodeError + 4)
#define Gm_GroupCodeAlreadyExist		(Gm_CodeError + 5)
#define Gm_MissingNumber				(Gm_CodeError + 6)
//
#define Gm_MissingFWord					(Gm_CodeError + 7)
#define Gm_MissingSWord					(Gm_CodeError + 8)
#define Gm_MissingOWord					(Gm_CodeError + 9)
#define Gm_MissingNWord					(Gm_CodeError + 10)
#define Gm_MissingLWord					(Gm_CodeError + 11)
#define Gm_MissingPWord					(Gm_CodeError + 12)
#define Gm_MissingQWord					(Gm_CodeError + 13)
#define Gm_MissingRWord					(Gm_CodeError + 14)
#define Gm_MissingEWord					(Gm_CodeError + 15)
#define Gm_MissingHWord					(Gm_CodeError + 16)
#define Gm_MissingDWord					(Gm_CodeError + 17)
#define Gm_MissingTWord					(Gm_CodeError + 18)
#define	Gm_MissingAxisWord				(Gm_CodeError + 19)
#define	Gm_MissingSubAxisWord			(Gm_CodeError + 20)
//
#define Gm_InvalidFValue				(Gm_CodeError + 21)
#define Gm_InvalidSValue				(Gm_CodeError + 22)
#define Gm_InvalidOValue				(Gm_CodeError + 23)
#define Gm_InvalidNValue				(Gm_CodeError + 24)
#define Gm_InvalidLValue				(Gm_CodeError + 25)
#define Gm_InvalidPValue				(Gm_CodeError + 26)
#define Gm_InvalidQValue				(Gm_CodeError + 27)
#define Gm_InvalidRValue				(Gm_CodeError + 28)
#define Gm_InvalidEValue				(Gm_CodeError + 29)
#define Gm_InvalidHValue				(Gm_CodeError + 31)
#define Gm_InvalidDValue				(Gm_CodeError + 32)
#define Gm_InvalidTValue				(Gm_CodeError + 33)
#define Gm_InvalidAxisValue				(Gm_CodeError + 34)
#define Gm_InvalidSubAxisValue			(Gm_CodeError + 35)

#define Gm_OverloadAxisNum				(Gm_CodeError + 36)
#define Gm_InvalidAxisNumber			(Gm_CodeError + 37)
#define Gm_MacroNotFound				(Gm_CodeError + 38)

//////////////Gm_SystemError
#define Gm_InvalidGMSHandle				(Gm_SystemError + 1)
#define Gm_InvalidThreadHandle			(Gm_SystemError + 2)  
#define Gm_SystemNotReady				(Gm_SystemError + 3)

#define Gm_NotEnoughMemory              (Gm_SystemError + 4)
#define Gm_InvalidPatternId				(Gm_SystemError + 5)
#define Gm_InvalidBreakPoint			(Gm_SystemError + 6)
#define Gm_InvalidMacroNumber			(Gm_SystemError + 7)

#define Gm_CodeOverload					(Gm_SystemError + 8)
#define Gm_MacroOverload				(Gm_SystemError + 9)
#define Gm_InvalidFeedRate				(Gm_SystemError + 10)
#define Gm_InvalidModuleRange			(Gm_SystemError + 11)


#define Gm_RadiusCompensationAlreadyOn	(Gm_SystemError + 12)
#define Gm_OverCut						(Gm_SystemError + 13)
#define Gm_WrongRefPlane				(Gm_SystemError + 14)



#define Gm_DllNotFound					(Gm_SystemError + 15)
#define Gm_Ax_ErrorStop					(Gm_SystemError + 16)

#define Gm_OverrunDwell					(Gm_SystemError + 17)
#define Gm_InvalidSetCoordinate			(Gm_SystemError + 18)




#define Gm_OverrunAxisNum				(Gm_SystemError + 19)
#define Gm_InvalidG29					(Gm_SystemError + 20)//Updated by W.Y.Z 10-->20
#define	Gm_BothOfGCodeUseAxisWords		(Gm_SystemError + 21)
#define	Gm_NotFoundNext					(Gm_SystemError + 22)
#define	Gm_ArcAxisNumError				(Gm_SystemError + 23)
#define	Gm_OverrunContiAxis				(Gm_SystemError + 24)
#define	Gm_ContiArcAxisError			(Gm_SystemError + 25)
#define	Gm_G272829CanNotBeConti			(Gm_SystemError + 26)
#define	Gm_CheckHomeFailed				(Gm_SystemError + 27)

#define	Gm_StackOverflow				(Gm_SystemError + 28)
#define	Gm_StackUnderflow				(Gm_SystemError + 29)
#define	Gm_InvalidAxHomeMode			(Gm_SystemError + 30)
#define Gm_OverrunFilePath				(Gm_SystemError + 31)
#define Gm_OverrunLineText				(Gm_SystemError + 32)
#define Gm_InvalidSSTA                  (Gm_SystemError + 33)       //Added by W.Y.Z on 2012.08.22 modify by dujunling on 2012.10.26

#define Gm_InfineLoop        			(Gm_SystemError + 34)       //Added bydujunling on 2012.9.27 for loadjob,uploadjob,

////do error			added by dujunling 2012.10.26
#define Gm_InvalidDoDevice				(Gm_SystemError + 35)
#define Gm_InvalidDoChannel				(Gm_SystemError + 36)
#define Gm_InvalidDoLevel				(Gm_SystemError + 37)
//di
#define Gm_InvalidDiDevice				(Gm_SystemError + 38)
#define Gm_InvalidDiChannel				(Gm_SystemError + 39)
#define Gm_InvalidDiLevel				(Gm_SystemError + 40)
//custom m code
#define Gm_RunCustomMcodeError			(Gm_SystemError + 41)

#define Gm_ZeroVector					(Gm_SystemError + 42)
#define Gm_LineParallel					(Gm_SystemError + 43)
//
#define Gm_InvalidBufferLength			(Gm_SystemError + 44)
#define GmInvalidOptionPauseParam       (Gm_SystemError + 45)
#define GmInvalidOptionSkip             (Gm_SystemError + 46)
#define GmWaitDiTimeOut             	(Gm_SystemError + 47)
#define GmCannotInvokeMacroInMacro      (Gm_SystemError + 48)
#define GmThreadTimeOut				    (Gm_SystemError + 49)
#define Gm_InvalidDiValue				(Gm_SystemError + 50)//Added by W.Y.Z on 2014.04.09
#define Gm_BeOverCutted                 (Gm_SystemError + 51)//Added by W.Y.Z on 2014.06.12
//for P point function by W.Y.Z on 2014.08.28
#define Gm_RadiusCompensationCannotWithG2G3   (Gm_SystemError + 52)  
#define Gm_InvalidPpointID              (Gm_SystemError + 53)  
#define Gm_InvalidFilePath              (Gm_SystemError + 54)
#define Gm_InvalidFileFormat            (Gm_SystemError + 55)
#define Gm_PpointHasNotSet              (Gm_SystemError + 56) 
#define Gm_PpointLenNotEqualWithAxesNum              (Gm_SystemError + 57)  
#define Gm_PpointAndNonPCannotBeMixed        (Gm_SystemError + 58) 
#define Gm_StartPosCannotEqualWithEndPos     (Gm_SystemError + 59) 
//  [3/24/2015 yang.kai]
#define Gm_InvalidBoolID              (Gm_SystemError + 60) 
#define Gm_BoolHasNotSet              (Gm_SystemError + 61) 
#define Gm_IfBlockNotCorrect              (Gm_SystemError + 62) 
#define Gm_IfBlockFlowError              (Gm_SystemError + 63) 
#define Gm_InvalidParameter            (Gm_SystemError + 64) 
//Error Code


#define EC_GetNICNumberFailed           (ECTError + 0x0)
#define EC_GetNICInfoFailed             (ECTError + 0x1)
#define EC_OpenMasterDevFailed          (ECTError + 0x2)
#define EC_GetSlaveFailed               (ECTError + 0x3)
#define EC_StartOpModeFailed            (ECTError + 0x4)
#define EC_CloseDeviceFailed            (ECTError + 0x5)
#define EC_MemAllocateFailed			(ECTError + 0x6)
#define EC_InvalidNicIndex				(ECTError + 0x7)
#define EC_OpenDevFailed				(ECTError + 0x8)
#define EC_ReadFileFailed				(ECTError + 0x9)
#define EC_GetNicInfoFailed				(ECTError + 0xa)
#define EC_GetSDOFailed					(ECTError + 0xb)
#define EC_InvalidParameter				(ECTError + 0xc)
#define EC_GetPDOOffsetFailed			(ECTError + 0xd)
#define EC_InitialMappingInfoFalied		(ECTError + 0xe)
#define EC_InitResourceFailed			(ECTError + 0xf)
#define EC_SetSDOFailed					(ECTError + 0x10)
#define EC_InvalidPortType				(ECTError + 0x11)
#define EC_SetCycleTimeFailed			(ECTError + 0x12)
#define EC_InvalidAoRange				(ECTError + 0x13)
#define EC_InvalidAiRange				(ECTError + 0x14)
#define EC_GetSlaveInfoFaied			(ECTError + 0x15)
#define EC_GetNetWorkStateFaied			(ECTError + 0x16)
#define EC_RegisterEventFailed			(ECTError + 0x17)
#define EC_InvalidIntegrationTime		(ECTError + 0x18)
#define EC_InvalidAIEnable				(ECTError + 0x19)
#define EC_InvalidDIFilter				(ECTError + 0x1a)
#define EC_SetSlaveStateFailed			(ECTError + 0x1b)
#define EC_ZeroCalibrationFailed		(ECTError + 0x1c)
#define EC_InvalidMasterHandle			(ECTError + 0x1d)
#define EC_InvalidENIFile				(ECTError + 0x1e)
#define EC_InvalidCaliType				(ECTError + 0x1f)
#define EC_SetCaliValueFailed			(ECTError + 0x20)
#define EC_AOCalibrationFailed			(ECTError + 0x21)
#define EC_InvalidIOMapping				(ECTError + 0x22)
#define EC_PortIndexGreaterThanPortNum	(ECTError + 0x23)
#define EC_ChannelIDGreaterThanChannelNum (ECTError + 0x24)
#define EC_InputIndexGreaterThanInputNum (ECTError + 0x25)
#define EC_OutputIndexGreaterThanOutputNum (ECTError + 0x26)
#define EC_SetEnableFailed				(ECTError + 0x27)
#define EC_SetAIRangeFailed				(ECTError + 0x28)
#define EC_SetIntegrationTimeFailed		(ECTError + 0x29)
#define EC_PropertyNotSupported			(ECTError + 0x2a)
#define EC_SlaveIDConflicted			(ECTError + 0x2b)
#define EC_SpanCalibrationFailed		(ECTError + 0x2c)
#define EC_InvalidAiValue				(ECTError + 0x2d)
#define EC_InvalidAoValue				(ECTError + 0x2e)
#define EC_GetModuleFailed				(ECTError + 0x2f)
#define EC_InvalidCntEnable				(ECTError + 0x30)
#define EC_InvalidCntPulseInMode		(ECTError + 0x31)
#define EC_InvalidCntInitValue			(ECTError + 0x32)
#define EC_InvalidCntMaxValue			(ECTError + 0x33)
#define EC_InvalidCntOverflowMode		(ECTError + 0x34)
#define EC_InvalidCntLatchEnable		(ECTError + 0x35)
#define EC_InvalidCntLatchEdge			(ECTError + 0x36)
#define EC_InvalidCntCmpEnable			(ECTError + 0x37)
#define EC_InvalidCntCmpMethod			(ECTError + 0x38)
#define EC_InvalidCntCmpPulseEnable		(ECTError + 0x39)
#define EC_InvalidCntCmpPulseMode		(ECTError + 0x3a)
#define EC_InvalidCntCmpPulseLogic		(ECTError + 0x3b)
#define EC_InvalidCntCmpPulseWidth		(ECTError + 0x3c)
#define EC_AxCntExceeded                (ECTError + 0x3d)
#define EC_FWUpgraded                   (ECTError + 0x3e)


#define ECAT_MasterEcatError			(ECTDevError + 0x01)
#define ECAT_SlaveDisconnect_R0			(ECTDevError + 0x02)
#define ECAT_SlaveDisconnect_R1			(ECTDevError + 0x03)
#define ECAT_R0_CHECK_OP_TIMEOUT		(ECTDevError + 0x04)
#define ECAT_R0_PH_INIT_TIMEOUT			(ECTDevError + 0x05)
#define ECAT_R0_START_TIMEOUT			(ECTDevError + 0x06)
#define ECAT_R0_GET_SLAVE_ID_TIMEOUT	(ECTDevError + 0x07)
#define ECAT_SlaveLostPDOArriveWarnThreshold_R0	(ECTDevError + 0x08)
#define ECAT_SlaveLostPDOArriveWarnThreshold_R1	(ECTDevError + 0x09)
#define ECAT_SlaveModeChange_R0			(ECTDevError + 0x0A)
#define ECAT_SlaveModeChange_R1			(ECTDevError + 0x0B)
#define ECAT_SlaveLostFrame_R0			(ECTDevError + 0x0C)
#define ECAT_SlaveLostFrame_R1			(ECTDevError + 0x0D)

#define ECAT_AxRetryError				(ECTAxError + 0x01)
#define ECAT_AxResetCounterError		(ECTAxError + 0x02)
#define ECAT_AxCmdErrorProtection		(ECTAxError + 0x03)
#define ECAT_AxSlaveALM					(ECTAxError + 0x04)
#define ECAT_AxFollowError				(ECTAxError + 0x05)
#define ECAT_AxHomeError				(ECTAxError + 0x06)

#define ECAT_MOTION_MASTER_NULL			(ECTMotionError + 0x01)
#define ECAT_MOTION_SCAN_BUSY			(ECTMotionError + 0x02)
#define ECAT_MOTION_DOMAIN_FAILED		(ECTMotionError + 0x03)
#define ECAT_MOTION_SLAVE_NOT_SUPPORT	(ECTMotionError + 0x04)
#define ECAT_MOTION_SLAVE_CONFIG_FAILED	(ECTMotionError + 0x05)
#define ECAT_MOTION_ACTIVE_FAILED		(ECTMotionError + 0x06)
#define ECAT_MOTION_DOMAN_DATA_FAILED	(ECTMotionError + 0x07)
#define ECAT_MOTION_NEED_RESCAN			(ECTMotionError + 0x08)

#define ECAT_IO_MASTER_NULL				(ECTIOError + 0x01)
#define ECAT_IO_SCAN_BUSY				(ECTIOError + 0x02)
#define ECAT_IO_DOMAIN_FAILED			(ECTIOError + 0x03)
#define ECAT_IO_SLAVE_NOT_SUPPORT		(ECTIOError + 0x04)
#define ECAT_IO_SLAVE_CONFIG_FAILED		(ECTIOError + 0x05)
#define ECAT_IO_ACTIVE_FAILED			(ECTIOError + 0x06)
#define ECAT_IO_DOMAN_DATA_FAILED 		(ECTIOError + 0x07)
#define ECAT_IO_NEED_RESCAN	 			(ECTIOError + 0x08)


#define ECTAxOPERATIONMODE				(ECTAxError + 0x10) //Error from CiA402 ecat driver
#define ECTAxHOMEOFFSET					(ECTAxError + 0x20) //Error from CiA402 ecat driver
#define ECTAxHOMEMODE					(ECTAxError + 0x30) //Error from CiA402 ecat driver

#define ECAT_HM_OPMODE_ProtocolTimeout				(ECTAxOPERATIONMODE + 0x01)
#define ECAT_HM_OPMODE_ObjectNotExist				(ECTAxOPERATIONMODE + 0x02)
#define ECAT_HM_OPMODE_SubindexNotExist				(ECTAxOPERATIONMODE + 0x03)
#define ECAT_HM_OPMODE_ValueRangeExceeded			(ECTAxOPERATIONMODE + 0x04)
#define ECAT_HM_OPMODE_WrittenTooHigh				(ECTAxOPERATIONMODE + 0x05)
#define ECAT_HM_OPMODE_WrittenTooLow				(ECTAxOPERATIONMODE + 0x06)
#define ECAT_HM_OPMODE_MaximumLessMinimum			(ECTAxOPERATIONMODE + 0x07)
#define ECAT_HM_OPMODE_OTHER						(ECTAxOPERATIONMODE + 0x08)		

#define ECAT_HM_OFFSET_ProtocolTimeout				(ECTAxHOMEOFFSET + 0x01)
#define ECAT_HM_OFFSET_ObjectNotExist				(ECTAxHOMEOFFSET + 0x02)
#define ECAT_HM_OFFSET_SubindexNotExist				(ECTAxHOMEOFFSET + 0x03)
#define ECAT_HM_OFFSET_ValueRangeExceeded			(ECTAxHOMEOFFSET + 0x04)
#define ECAT_HM_OFFSET_WrittenTooHigh				(ECTAxHOMEOFFSET + 0x05)
#define ECAT_HM_OFFSET_WrittenTooLow				(ECTAxHOMEOFFSET + 0x06)
#define ECAT_HM_OFFSET_MaximumLessMinimum			(ECTAxHOMEOFFSET + 0x07)
#define ECAT_HM_OFFSET_OTHER						(ECTAxHOMEOFFSET + 0x08)	

#define ECAT_HM_MODE_ProtocolTimeout				(ECTAxHOMEMODE + 0x01)
#define ECAT_HM_MODE_ObjectNotExist					(ECTAxHOMEMODE + 0x02)
#define ECAT_HM_MODE_SubindexNotExist				(ECTAxHOMEMODE + 0x03)
#define ECAT_HM_MODE_ValueRangeExceeded				(ECTAxHOMEMODE + 0x04)
#define ECAT_HM_MODE_WrittenTooHigh					(ECTAxHOMEMODE + 0x05)
#define ECAT_HM_MODE_WrittenTooLow					(ECTAxHOMEMODE + 0x06)
#define ECAT_HM_MODE_MaximumLessMinimum				(ECTAxHOMEMODE + 0x07)
#define ECAT_HM_MODE_OTHER							(ECTAxHOMEMODE + 0x08)	


#define ECAT_SDO_ToggleBitNotChanged		(ECTDevSDOError + 0x5300) //0x05030000,Toggle bit not changed
#define ECAT_SDO_ProtocolTimeout			(ECTDevSDOError + 0x5400) //0x05040000,SDO protocol timeout
#define ECAT_SDO_CommandNotValidOrUnknown	(ECTDevSDOError + 0x5401) //0x05040001,Client/Server command specifier not valid or unknown
#define ECAT_SDO_OutOfMemory				(ECTDevSDOError + 0x5405) //0x05040005,Out of memory
#define ECAT_SDO_UnsupportedAccess			(ECTDevSDOError + 0x6100) //0x06010000,Unsupported access to an object
#define ECAT_SDO_WriteOnlyObject			(ECTDevSDOError + 0x6101) //0x06010001,Attempt to read a write-only object
#define ECAT_SDO_ReadOnlyObject				(ECTDevSDOError + 0x6102) //0x06010002,Attempt to write a read-only object
#define ECAT_SDO_ObjectNotExist				(ECTDevSDOError + 0x6200) //0x06020000, This object does not exist in the object directory
#define ECAT_SDO_MappedToPDOFailed			(ECTDevSDOError + 0x6441) //0x06040041,The object cannot be mapped into the PDO
#define ECAT_SDO_ExceedPdoLength			(ECTDevSDOError + 0x6442) //0x06040042,The number and length of the objects to be mapped would exceed the PDO length
#define ECAT_SDO_ParameterIncompatibility	(ECTDevSDOError + 0x6443) //0x06040043,General parameter incompatibility reason
#define ECAT_SDO_InternalIncompatibility	(ECTDevSDOError + 0x6447) //0x06040047,"General internal incompatibility in device
#define ECAT_SDO_HardwareError				(ECTDevSDOError + 0x6600) //0x06060000,Access failure due to a hardware error
#define ECAT_SDO_LengthNotMatch				(ECTDevSDOError + 0x6710) //0x06070010,Data type does not match, length of service parameter does not match
#define ECAT_SDO_LengthTooHigh				(ECTDevSDOError + 0x6712) //0x06070012,Data type does not match, length of service parameter too high
#define ECAT_SDO_LengthTooLow				(ECTDevSDOError + 0x6713) //0x06070013,Data type does not match, length of service parameter too low
#define ECAT_SDO_SubindexNotExist			(ECTDevSDOError + 0x6911) //0x06090011,Subindex does not exist
#define ECAT_SDO_ValueRangeExceeded			(ECTDevSDOError + 0x6930) //0x06090030,Value range of parameter exceeded
#define ECAT_SDO_WrittenTooHigh				(ECTDevSDOError + 0x6931) //0x06090031,Value of parameter written too high
#define ECAT_SDO_WrittenTooLow				(ECTDevSDOError + 0x6932) //0x06090032,Value of parameter written too low
#define ECAT_SDO_MaximumLessMinimum			(ECTDevSDOError + 0x6936) //0x06090036,Maximum value is less than minimum value
#define ECAT_SDO_GeneralError				(ECTDevSDOError + 0x8000) //0x08000000,General error
#define ECAT_SDO_ErrorStoredToApplication	(ECTDevSDOError + 0x8020) //0x08000020,Data cannot be transferred or stored to the application
#define ECAT_SDO_ErrorStoredOfLocalControl	(ECTDevSDOError + 0x8021) //0x08000021,Data cannot be transferred or stored to the application because of local control
#define ECAT_SDO_ErrorStoredOfPresentDeviceState (ECTDevSDOError + 0x8022) //0x08000022,Data cannot be transferred or stored to the application because of the present device state
#define ECAT_SDO_DynamicGenerationFails		(ECTDevSDOError + 0x8023) //0x08000023,Object dictionary dynamic generation fails or no object

#endif // __ADV_MOT_ERR_H__
