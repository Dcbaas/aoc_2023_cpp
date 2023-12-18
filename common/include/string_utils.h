#ifndef STRING_UTILS
#define STRING_UTILS

#include <vector>
#include <string>
namespace baas::common
{
    std::vector<std::string> str_split(std::string_view chars, const std::string& delimiter);
}
#endif // !STRING_UTILS