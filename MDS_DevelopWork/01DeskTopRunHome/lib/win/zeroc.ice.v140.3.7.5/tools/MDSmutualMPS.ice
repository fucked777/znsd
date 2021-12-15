// --------------------------------------------------------------------//
// 前端界面框架与其私服的Slice文件，提供互相调用的接口方法；
// 用法：通过 slice2cpp.exe
//          生成.h .cpp文件，MDS、MPS两端都包含即可通信。
//          谁作为被调者，谁实现虚函数
//
//
// MDS 前端界面框架
// MPS 前端界面框架 私服
//
// --------------------------------------------------------------------//
#pragma once


//MPS：私服实现
module MDScallMPSService {

	sequence<byte> ImageData;	

    //登陆服务验证代理
    interface LoginServiceProxy {
        bool LoginAuthentication(string user,string password);
    };

    //注册客户端函数：mds作为客户端链接mps，并将自己的service传递出去，供mps链接
	interface RegisterService{
		bool registerModule(string modulename,string host);

		/*
		* branchcode:载荷代码
		* type:通道
		* left,right,top,bottom,width,height
		* image:图像数据，rgb二进制
		*/
		ImageData requestImage(string branchcode,string type,int left, int right, int top, int bottom, int width, int height);
	};
    
};



//MDS：前端界面框架实现
module MPScallMDSService {

	struct SysOperPara
	{
		int ParamType;/*参数类型*/
		string SatID;/*卫星ID*/
		int GIIRSTeleCmdTime;/*探测仪测控指令生成的时间长度*/
		int GIIRSTeleCmdPushCycle;/*探测仪测控指令上注周期(小时)*/
		int AGRITeleCmdPushCycle;/*成像仪测控指令上注周期(小时)*/
		int AGRITeleCmdTime;/*成像仪测控指令生成的时间长度*/
		int RSITeleCmdPushCycle;/*快扫仪测控指令上注周期(小时)*/
		int RSITeleCmdTime;/*快扫仪测控指令生成的时间长度*/
		byte GIIRSAMC;/*探测仪AMC状态*/
		byte GIIRSOMC;/*探测仪OMC状态*/
		byte AGRITMC;/*成像仪TMC状态*/
		byte RSIINRFLOW;/*快扫仪INR流程总开关*/
		byte GRIISINRFLOW;/*探测仪INR流程总开关*/
		byte AGRIAMC;/*成像仪AMC状态*/
		byte AGRIOMC;/*成像仪OMC状态*/
		byte AGRIXINRFLOW;/*成像仪INR流程总开关*/
		byte GIIRSTMC;/*探测仪TMC状态*/
		byte RSIAMC;/*快扫仪AMC状态*/
		byte RSIOMC;/*快扫仪OMC状态*/
		byte RSITMC;/*快扫仪TMC状态*/
		byte GIIRSNRS;/*探测仪INR导航配准状态*/
		byte AGRINRS;/*成像仪INR导航配准状态*/
		byte RSINRS;/*快扫仪INR导航配准状态*/
	};

	struct SatPlatPara
	{
		int ParamType;/**/
		string SatID;/*卫星代号*/
		string GIIRSTmcTranCh;/*探测仪2s遥测包下传通道*/
        string AGRITmcTranCh;/*辐射计2s遥测包下传通道*/
        string FlutterTranCh;/*颤振监测下传通道*/
        string INRDataTranCh;/*INR数传遥测包下传通道*/
        string SatSenserTranCh;/*星敏感仪器下传通道*/
        string FixedPosRegTranCh;/*定位配准数据下传通道*/
        string SEPDataTranCh;/*空间环境监测仪下传通道*/
        string RSIDataTranCh;/*快速成像仪下传通道*/
        string AGRIDataTranCh;/*多通道扫描成像辐射计下传通*/
        string GIIRSProDataTranCh;/*大气垂直探测仪处理后数据下传通道*/
        string GIIRSRawDataTranCh;/*大气垂直探测仪原始数据下传通道*/
        string DataTranRightCh;/*数传通道状态右旋圆极化通道*/
        string DataTranLeftCh;/*数传通道状态左旋圆极化通道*/
        string OrbitConWorkSta;/*姿轨控工作状态*/
        string ImagePositionSta;/*图像定位配准工作状态*/
        string SatColScreenFace;/*卫星辐冷屏朝向状态*/
        int NorOrbAngleRange;/*正常工作轨道倾角范围*/
        string FGMWorkStatus;/*空间环境监测仪磁强计工作状态*/
        string RADDWorkStatus;/*空间环境监测仪辐射剂量工作状态*/
        string HEPDWorkStatus;/*空间环境监测仪高能粒子探测器工作状态*/
        string CPDWorkStatus;/*空间环境监测仪充电电位检测工作状态*/
        string RSIWorkStatus;/*快扫仪工作状态*/
        string GIIRSWorkStatus;/*探测仪工作状态*/
        string AGRIWorkStatus;/*成像仪工作状态*/
        string SatWorkStatus;/*卫星状态*/
        double OrbitLocation;/*定点位置*/
        string RSITmcTranCh;/*快扫仪2s遥测包下传通道*/
	};
	

	struct Task
	{
		string TaskEN;/*任务名称-英文*/
		string TaskCN;/*任务名称中文*/
		string TaskCode;/*任务编号*/
		string Exdate;/*任务退出时间*/
		string StartTime;/*任务开始事件*/
		string EndTime;/*任务结束事件*/
		string ExStatus;/*任务推出状态*/
		string RealStartTime;/*任务实际开始时间*/
		string RealEndTime;/*任务实际结束时间*/
	};

	sequence<Task> TasksData;

	sequence<byte> ImageData;	


	struct ErrorLog
	{
		string branchcode;/*载荷编码*/
		string errorlevel;/*告警级别*/
		string status;/*告警状态*/
		string time;/*告警时间*/
		string taskcode;/*任务编码*/
		string message;/*告警内容*/
		string errorcode;/*错误码*/
	};

	interface MDSService
	{
		/* time : "20210420120000" 2021年04月20日12点00分00秒*/
		void pushUtcTime(string time);

		//卫星状态
		void pushSysOperPara(SysOperPara para);

		//平台参数
		void pushSatPlatPara(SatPlatPara para);

		//任务参数
		void pushTaskInfo(string branchCode, TasksData tasks);

		//载荷图像数据变化
		void imageReady(string type);

		//错误日志
		void pushErrorLog(ErrorLog log);
	};

};