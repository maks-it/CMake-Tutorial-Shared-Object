
#if defined _WIN32
	#ifdef DLL_EXPORT
		#define DECLSPEC __declspec(dllexport) //DLL_EXPORT ON
	#else
		#define DECLSPEC __declspec(dllimport) //DLL_EXPORT OFF
	#endif
	#define NOT_DECLSPEC
#elif defined __CYGWIN__
	#ifdef DLL_EXPORT
		#define DECLSPEC __attribute__ ((dllexport))
	#else
		#define DECLSPEC __attribute__ ((dllimport))
	#endif
	#define NOT_DECLSPEC
#elif defined __GNUC__ >= 4
	#define DECLDIR __attribute__ ((visibility ("default")))
	#define NOT_DECLSPEC __attribute__ ((visibility ("hidden")))
#else
	#define DECLSPEC
	#define NOT_DECLSPEC
#endif

extern "C"
{
	namespace library {
		int DECLSPEC Add(int a, int b);
	}
}
