#ifndef DATATRANSFORM_GLOBAL_H
#define DATATRANSFORM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DATATRANSFORM_LIBRARY)
#  define DATATRANSFORM_EXPORT Q_DECL_EXPORT
#else
#  define DATATRANSFORM_EXPORT Q_DECL_IMPORT
#endif

#endif // DATATRANSFORM_GLOBAL_H
