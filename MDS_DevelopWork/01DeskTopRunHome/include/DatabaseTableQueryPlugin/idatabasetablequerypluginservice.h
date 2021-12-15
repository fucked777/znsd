#ifndef IDATABASETABLEQUERYPLUGINSERVICE_H 
#define IDATABASETABLEQUERYPLUGINSERVICE_H 

#include <QObject>

class iDatabaseTableQueryPluginService : public QObject 
{ 
public: 
   virtual ~iDatabaseTableQueryPluginService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iDatabaseTableQueryPluginService_iid "org.casic.service.demo.iDatabaseTableQueryPluginService" 
Q_DECLARE_INTERFACE(iDatabaseTableQueryPluginService, iDatabaseTableQueryPluginService_iid) 
#endif  // IDATABASETABLEQUERYPLUGINSERVICE_H 

