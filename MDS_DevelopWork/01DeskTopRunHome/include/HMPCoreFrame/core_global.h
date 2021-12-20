#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CORE_LIBRARY)
#  define HMP_CORE_EXPORT Q_DECL_EXPORT
#else
#  define HMP_CORE_EXPORT Q_DECL_IMPORT
#endif

#endif // CORE_GLOBAL_H
