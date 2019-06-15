//---------------------------------------------------------------------------

#ifndef StringUtilsH
#define StringUtilsH
#include <vector>
#include <string>
#include <vcl.h>

class StringUtils
{
	public:
		static const std::vector<std::string> explode(const std::string& s, const char& c);
		static std::string convertStr(UnicodeString str);
};

//---------------------------------------------------------------------------
#endif
