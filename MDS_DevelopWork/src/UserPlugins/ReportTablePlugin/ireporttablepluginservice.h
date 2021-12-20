#ifndef IREPORTTABLEPLUGINSERVICE_H 
#define IREPORTTABLEPLUGINSERVICE_H 

#include <QObject>

class iReportTablePluginService : public QObject 
{ 
public: 
   virtual ~iReportTablePluginService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iReportTablePluginService_iid "org.casic.service.demo.iReportTablePluginService" 
Q_DECLARE_INTERFACE(iReportTablePluginService, iReportTablePluginService_iid) 
#endif  // IREPORTTABLEPLUGINSERVICE_H 

