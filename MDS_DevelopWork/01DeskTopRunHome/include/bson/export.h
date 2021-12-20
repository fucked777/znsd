#pragma once
#ifdef _WIN32
#ifdef BSONLIB
#define BSOM_EXPORT __declspec(dllexport)
#else
#define BSOM_EXPORT __declspec(dllimport)
#endif
#else
#ifdef BSONLIB
#define BSOM_EXPORT __attribute__((visibility("default")))
#else
#define BSOM_EXPORT __attribute__((visibility("default")))
#endif
#endif

