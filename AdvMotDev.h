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


#ifndef __ADV_MOT_DEV_H__
#define __ADV_MOT_DEV_H__

/*
+-----------------------------------------------------------------------------+
| ************ Advantech Motion Master Device Type ID************************ |
+-----------------------------------------------------------------------------+
*/

#define Adv_UNKNOWN				0xff

// ADAM Motion Series
#define Adv_ADAM_MOTION          0x0
#define Adv_ADAM5202             (Adv_ADAM_MOTION + 0)
#define Adv_ADAM5240             (Adv_ADAM_MOTION + 1)
#define Adv_APAX5202             (Adv_ADAM_MOTION + 2)

// IO Motion Series
#define Adv_IO_MOTION           0x20
#define Adv_PCI1240             (Adv_IO_MOTION + 0)
#define Adv_PCM3240             (Adv_IO_MOTION + 1)
#define Adv_PCI1202             (Adv_IO_MOTION + 2)
#define Adv_AMAX2050            (Adv_IO_MOTION + 3)
#define Adv_PCM3202             (Adv_IO_MOTION + 4)
#define Adv_PCI1220             (Adv_IO_MOTION + 5)
#define Adv_PCI1244             (Adv_IO_MOTION + 6)
#define Adv_PCI1245             (Adv_IO_MOTION + 7)
#define Adv_PCI1265             (Adv_IO_MOTION + 8)
#define Adv_PCI1245E            (Adv_IO_MOTION + 9)
#define Adv_PCI1285             (Adv_IO_MOTION + 0xa)
#define Adv_PCI1285E            (Adv_IO_MOTION + 0xb)
#define Adv_PCI1245V            (Adv_IO_MOTION + 0xc)
#define Adv_PCI1245L            (Adv_IO_MOTION + 0xd)
#define Adv_PCI1245S            (Adv_IO_MOTION + 0xe)
#define Adv_PCI1285V            (Adv_IO_MOTION + 0xf)
#define Adv_MIC3285             (Adv_IO_MOTION + 0x10) 
#define Adv_MIC3245             (Adv_IO_MOTION + 0x11)
#define Adv_PCI1245HP			(Adv_IO_MOTION + 0x12) //YDD 2015.6.1
#define Adv_PCI1245LIO			(Adv_IO_MOTION + 0x13) //YDD 2015.6.1
#define Adv_MAS324X				(Adv_IO_MOTION + 0x14)
#define Adv_MAS328X				(Adv_IO_MOTION + 0x15)
#define Adv_PCI1245_MAS         (Adv_IO_MOTION + 0x16)
#define Adv_PCI1285_MAS         (Adv_IO_MOTION + 0x17)
#define Adv_PCI1245L_MAS		(Adv_IO_MOTION + 0x18)
#define Adv_PCI1245LIO_MAS		(Adv_IO_MOTION + 0x19)
#define Adv_PCI1245S_MAS		(Adv_IO_MOTION + 0x1A)
#define Adv_MAS324XS			(Adv_IO_MOTION + 0x1B)

#define Adv_PCIE1245            (Adv_IO_MOTION + 0x20)
#define Adv_PCIE1245E           (Adv_IO_MOTION + 0x21)
#define Adv_PCIE1245V           (Adv_IO_MOTION + 0x22)

//YDD 2015.9.29
#define Adv_MOTION_MVP	        0xD0
#define Adv_MVP3245 			(Adv_MOTION_MVP + 0x01) 
#define Adv_MVP3245P			(Adv_MOTION_MVP + 0x02)
#define Adv_MVP3245_MAS		    (Adv_MOTION_MVP + 0x03)
#define Adv_MVP3285_MAS		    (Adv_MOTION_MVP + 0x04) //ydd 2016.12.27
#define Adv_MVP3265_MAS			(Adv_MOTION_MVP + 0x05)
#define Adv_MVP3245S_MAS		(Adv_MOTION_MVP + 0x06)

#define Adv_IO_MOTION_EX        0x80       //Custom 
#define Adv_PCI1285HT           (Adv_IO_MOTION_EX + 0x0)
#define Adv_PCI1274_12AE		(Adv_IO_MOTION_EX + 0x1) //16.7.25
#define Adv_PCI1274_16AE		(Adv_IO_MOTION_EX + 0x2) //16.7.25

#define AdV_VIRTUAL_DIO_CARD        0x90       //VIRTUAL DIO CARD
#define AdV_V_PCI1750				(AdV_VIRTUAL_DIO_CARD + 0)


#define Adv_VirtualMotionCard   (0xA0)
#define Adv_V_PCI1245             (Adv_VirtualMotionCard + Adv_PCI1245 -Adv_IO_MOTION)
#define Adv_V_PCI1245E            (Adv_VirtualMotionCard + Adv_PCI1245E-Adv_IO_MOTION)
#define Adv_V_PCI1245V            (Adv_VirtualMotionCard + Adv_PCI1245V-Adv_IO_MOTION)
#define Adv_V_PCI1245S            (Adv_VirtualMotionCard + Adv_PCI1245S-Adv_IO_MOTION)
#define Adv_V_PCI1245L            (Adv_VirtualMotionCard + Adv_PCI1245L-Adv_IO_MOTION)
#define Adv_V_PCI1265             (Adv_VirtualMotionCard + Adv_PCI1265 -Adv_IO_MOTION)
#define Adv_V_PCI1285             (Adv_VirtualMotionCard + Adv_PCI1285 -Adv_IO_MOTION)
#define Adv_V_PCI1285E            (Adv_VirtualMotionCard + Adv_PCI1285E-Adv_IO_MOTION)
#define Adv_V_PCI1285V            (Adv_VirtualMotionCard + Adv_PCI1285V-Adv_IO_MOTION)
#define Adv_V_PCI1203             (Adv_VirtualMotionCard + Adv_PCI1203-Adv_IO_MOTION)

#define Adv_V_MAS324X             (Adv_VirtualMotionCard + Adv_MAS324X-Adv_IO_MOTION)
#define Adv_V_MAS328X             (Adv_VirtualMotionCard + Adv_MAS328X-Adv_IO_MOTION)
#define Adv_V_MAS324XS            (Adv_VirtualMotionCard + Adv_MAS324XS-Adv_IO_MOTION)

//IO Slave Series
#define Adv_AMAX_SLAVE           0x40
#define Adv_AMAX2210             (Adv_AMAX_SLAVE + 0)
#define Adv_AMAX2240             (Adv_AMAX_SLAVE + 1)
#define Adv_AMAX2710             (Adv_AMAX_SLAVE + 2)
#define Adv_AMAX2754             (Adv_AMAX_SLAVE + 3)
#define Adv_AMAX2730             (Adv_AMAX_SLAVE + 4)
#define Adv_AMAX2756             (Adv_AMAX_SLAVE + 5)
#define Adv_AMAX2752             (Adv_AMAX_SLAVE + 6)

//EtherCAT
#define Adv_EtherCAT             0x60
#define Adv_ADAM5000             (Adv_EtherCAT + 1)
#define Adv_PCI1203              (Adv_EtherCAT + 2)
#define Adv_PCIE1203             (Adv_EtherCAT + 3)
#define Adv_PCIE1203E            (Adv_EtherCAT + 4)
#define Adv_PCIE1203V            (Adv_EtherCAT + 5)
#define Adv_PCIE1203L            (Adv_EtherCAT + 6)
#define Adv_PCI1203L             (Adv_EtherCAT + 7)
#define Adv_PCI1203S             (Adv_EtherCAT + 8)
#define Adv_PCIE1203S            (Adv_EtherCAT + 9)

#define Adv_EtherCAT_MAS           0x70 //ydd. 18.3.22. add for ethercat -mas
#define Adv_PCI1203_MAS           (Adv_EtherCAT_MAS + Adv_PCI1203 - Adv_EtherCAT)
#define Adv_PCI1203S_MAS          (Adv_EtherCAT_MAS + Adv_PCI1203S - Adv_EtherCAT)
#define Adv_PCIE1203_MAS          (Adv_EtherCAT_MAS + Adv_PCIE1203 - Adv_EtherCAT)
#define Adv_PCIE1203E_MAS         (Adv_EtherCAT_MAS + Adv_PCIE1203E - Adv_EtherCAT)
#define Adv_PCIE1203V_MAS         (Adv_EtherCAT_MAS + Adv_PCIE1203V - Adv_EtherCAT)
#define Adv_PCIE1203L_MAS         (Adv_EtherCAT_MAS + Adv_PCIE1203L - Adv_EtherCAT)
#define Adv_PCIE1203S_MAS         (Adv_EtherCAT_MAS + Adv_PCIE1203S - Adv_EtherCAT)
#endif // __ADV_MOT_DEV_H__
