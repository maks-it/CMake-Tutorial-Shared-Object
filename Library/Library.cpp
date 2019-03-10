#include "Library.h"
#include "add.h"

// Error LNK2019 : unresolved external symbol "__declspec(dllimport)
// Add Extern "C"
extern "C"
{
	namespace library {
		int DECLSPEC Add(int a, int b)
		{

			#ifdef USE_MYMATH

			#else

			#endif
			
			return detail::myadd(a, b);
		}
	}
}
