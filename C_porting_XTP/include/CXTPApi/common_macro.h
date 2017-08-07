#ifndef _H_COMMON_MACRO_H_
#define _H_COMMON_MACRO_H_

#ifdef WIN32
#ifdef DLL_EXPORT
#define LC_XTP_API __declspec(dllexport)
#else
#define LC_XTP_API __declspec(dllimport)
#endif
#else
#define LC_XTP_API
#endif


#include<stdlib.h>

#ifndef __cplusplus
typedef enum {false = 0, true = 1} bool;
#endif

#endif
