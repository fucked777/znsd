//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.5
//
// <auto-generated>
//
// Generated from file `ProcessF.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_ProcessF_h__
#define __Ice_ProcessF_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 5
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef ICE_API
#   if defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   elif defined(ICE_API_EXPORTS)
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Ice
{

class Process;
class ProcessPrx;

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace Ice
{

using ProcessPtr = ::std::shared_ptr<Process>;
using ProcessPrxPtr = ::std::shared_ptr<ProcessPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace Ice
{

class Process;
/// \cond INTERNAL
ICE_API void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< Process>&);
ICE_API ::IceProxy::Ice::Object* upCast(Process*);
/// \endcond

}

}

namespace Ice
{

class Process;
/// \cond INTERNAL
ICE_API Object* upCast(Process*);
/// \endcond
typedef ::IceInternal::Handle< Process> ProcessPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Ice::Process> ProcessPrx;
typedef ProcessPrx ProcessPrxPtr;
/// \cond INTERNAL
ICE_API void _icePatchObjectPtr(ProcessPtr&, const ObjectPtr&);
/// \endcond

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
