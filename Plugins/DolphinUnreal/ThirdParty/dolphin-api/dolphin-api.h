// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DOLPHINAPI_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DOLPHINAPI_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DOLPHINAPI_EXPORTS
#define DOLPHINAPI_API __declspec(dllexport)
#else
#define DOLPHINAPI_API __declspec(dllimport)
#endif

// This class is exported from the dll
class DOLPHINAPI_API Cdolphinapi {
public:
	Cdolphinapi(void);
	// TODO: add your methods here.
};

extern DOLPHINAPI_API int ndolphinapi;

DOLPHINAPI_API int fndolphinapi(void);
