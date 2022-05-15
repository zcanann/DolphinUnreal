#ifdef DOLPHINAPI_EXPORTS
#define DOLPHINAPI_API __declspec(dllexport)
#else
#define DOLPHINAPI_API __declspec(dllimport)
#endif

class DOLPHINAPI_API CDolphinAPI
{
public:
	CDolphinAPI(void);
};

DOLPHINAPI_API int GlobalFunc(void);
