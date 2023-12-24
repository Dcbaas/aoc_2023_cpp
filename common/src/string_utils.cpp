#include "string_utils.h"

namespace baas::common
{
    std::vector<std::string> str_split(std::string_view chars, std::string_view delimiter)
    {
        std::string chars_copy(chars);

        std::vector<std::string> split;

        std::size_t found;
        while(found = chars_copy.find(delimiter), found != std::string::npos)
        {
            std::string token = chars_copy.substr(0, found);
            split.push_back(token);
            chars_copy.erase(0, found + delimiter.length());
        }

        // Need to append the end of the string to the split.
        split.push_back(chars_copy);
        
        return split;
    }
}