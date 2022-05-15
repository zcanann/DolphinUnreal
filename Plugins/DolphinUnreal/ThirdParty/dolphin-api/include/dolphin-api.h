#ifdef DOLPHINAPI_EXPORTS
#define DOLPHINAPI_API __declspec(dllexport)
#else
#define DOLPHINAPI_API __declspec(dllimport)
#endif

class DOLPHINAPI_API DolphinAPI
{
public:
	DolphinAPI(void);
};

extern DOLPHINAPI_API int GlobalVar;

DOLPHINAPI_API int GlobalFunction();
