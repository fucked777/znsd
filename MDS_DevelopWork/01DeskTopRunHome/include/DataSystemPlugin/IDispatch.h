#pragma once

#include <QEvent>
class QObject;
class IDataDispatch
{
public:
	enum DisPatchEvent
	{
		UtcTime_Event = QEvent::User + 1,
		SysOper_Event,
		SatPlat_Event,
		task_Event,
		image_Event_b,
		image_Event_d,
		errLog_Event,
		orbit_Event,
		taskStatus_Event,
		fftData_Event,
		PQAData_Event,
		SysLog_Event,
		Instruction_Event,
		Yaoce_Event,
		PA_Event,
		PAA_Event,
		Time_Event,
		File_Event,
		BandReg_Event,
		TaskTime_Event,
		ErrorCount_Event,
		MyUser,
	};

        enum RquestEvent
        {
            P_Image_Event = DisPatchEvent::MyUser +1,
            P_Task_Event,
            P_SysOper_Event,
            P_SatPlat_Event,
            P_YaoCe_Event,
			P_TaskTime_Event,
			P_ErrorCount_Event,
        };

	virtual bool registSlot(DisPatchEvent type,QObject* receriver, const char* slot) = 0;

        virtual bool registSender(RquestEvent type,QObject* sender, const char* signal) = 0;

        virtual bool unregistSlot(DisPatchEvent type,QObject* receriver, const char* slot) = 0;

        virtual bool unregistSender(QObject* sender, const char* signal) = 0;

};
