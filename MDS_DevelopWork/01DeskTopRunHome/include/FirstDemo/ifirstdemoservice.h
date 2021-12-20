#ifndef IFIRSTDEMOSERVICE_H 
#define IFIRSTDEMOSERVICE_H 

#include <QObject>

class iFirstDemoService : public QObject 
{ 
public: 
   virtual ~iFirstDemoService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iFirstDemoService_iid "org.casic.service.demo.iFirstDemoService" 
Q_DECLARE_INTERFACE(iFirstDemoService, iFirstDemoService_iid) 
#endif  // IFIRSTDEMOSERVICE_H 

