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

#if !defined(ADVDXFREADER__INCLUDED_)
#define ADVDXFREADER__INCLUDED_

#ifdef __cplusplus
extern "C"
{
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
#define ADVDXFREADERAPI      __stdcall
#endif
/////////////////////////////////////////////////////////////////////////////


#define CLOSE         1
#define NOT_CLOSE     0

#ifndef SUCCESS
#define SUCCESS     0
#endif
//#define PI 3.1415926535897931 
// DXF  错误码
#define AtEmptyPathErr		0x01         //路径为空错误
#define AtFileTypeErr		0x02         //文件类型错误
#define AtEmptyFileErr   	0x03         //文件为空错误
//#define AtSerialNumErr  	0x04         //图样序列号超出范围错误
#define AtSampleTypeErr  	0x05         //图样类型错误
#define AtDataLoseErr    	0x06         //数据丢失错误
#define AtCreatSpaceErr    	0x07         //开辟数据空间失败（malloc失败）
#define AtInputLocusNumErr  0x08         //输入轨迹数目错误
#define AtLocusPtrErr       0x09         //轨迹链表错误
#define AtInputSampleNumErr 0x0a         //输入图元数目错误
#define AtSamplePtrErr      0x0b         //图元链表错误
#define AtInputPataErr      0x0c         //输入参数错误（OpenDxf函数的精度参数）



#define CW             0
#define CCW            1


LRESULT ADVDXFREADERAPI AtOpenDXF(char *dxfFilePath,             //文件路径
			               double Proportion,             //CAD现实的图和绘制中的图的比例
							DWORD  Ellipse_Cut_Min_Angel,  //分割查补椭圆的最小角度
							DWORD  Spline_Cut_Step         //一段曲线要分为多少直线段
							);   //比例关系
LRESULT ADVDXFREADERAPI AtGetType(DWORD * Type,
		                   DWORD   Direction,
			               DWORD   Locus_Num,
			               DWORD   Sample_Num);

LRESULT ADVDXFREADERAPI AtGetArc(double * Center_x,    //圆弧圆心坐标的x值
			        double * Center_y,    //圆弧圆心坐标的y值
			        double * Center_z,    //圆弧圆心坐标的z值
		            double * r,           //圆弧的半径
			        double * Start_X,     //圆弧的起始点的X坐标
                    double * Start_Y,     //圆弧的起始点的Y坐标角度
                    double * Start_Z,     //圆弧的起始点的z坐标角度
			        double * End_X,       //圆弧的终止点的X坐标
                    double * End_Y,       //圆弧的终止点的Y坐标
                    double * End_Z,       //圆弧的终止点的Y坐标
                    DWORD  * MoveDirection, //运动方向
					double * Start_Angle, //圆弧的起始角度
		            double * End_Angle,   //圆弧的终止角度
		            DWORD 	* Plane,   //圆弧所在平面
					DWORD    Direction,  //轨迹的方向
			        DWORD    Locus_Num,   //轨迹的序列号
				    DWORD    Sample_Num); //图元的序列号

LRESULT ADVDXFREADERAPI AtGetLine(double *Start_x,    //直线起始点坐标的x值
			                                 	  double *Start_y,    //直线起始点坐标的y值
			                                 	  double *Start_z,    //直线起始点坐标的z值
			                                	  double *End_x,      //直线终止点坐标的x值
			                                	  double *End_y,      //直线终止点坐标的y值
			                                	  double *End_z,      //直线终止点坐标的z值
												  double *k,          //直线的斜率
												  DWORD   Direction,  //轨迹的方向
												  DWORD   Locus_Num,  //轨迹的序列号
				                                  DWORD   Sample_Num);//图元的序列号

LRESULT ADVDXFREADERAPI AtGetPoint(double *Point_x,//Point's x value
								   double *Point_y,//Point's y value
								   double *Point_z,//Point's z value
								   DWORD   Direction,  //轨迹的方向
								   DWORD   Locus_Num,  //轨迹的序列号
								   DWORD   Sample_Num);//图元的序列号


LRESULT ADVDXFREADERAPI AtGetMostValue( double * Min_x,    //整个文件的最小点的X坐标
				                                        double * Min_y,    //整个文件的最小点的y坐标
				                                        double * Min_z,    //整个文件的最小点的z坐标
			                                      	    double * Max_x,    //整个文件的最大点的X坐标
				                                        double * Max_y,    //整个文件的最大点的y坐标
				                                        double * Max_z     //整个文件的最大点的z坐标
				                                        );
	
LRESULT ADVDXFREADERAPI AtGetLocusCount( DWORD * Count);   //获取轨迹的数目
LRESULT ADVDXFREADERAPI AtGetSampleCount(DWORD * Count,    //第Locus_Num个轨迹中图元的个数
			                                             DWORD Locus_Num);  //第几个轨迹
LRESULT ADVDXFREADERAPI AtCloseDXF();


#ifdef __cplusplus
}
#endif

#endif
