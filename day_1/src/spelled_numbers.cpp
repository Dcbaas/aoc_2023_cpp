#include "spelled_numbers.h"

#include <string>


using CString = std::string_view;

constexpr CString ONE = "one";
constexpr CString TWO = "two";
constexpr CString THREE = "three";
constexpr CString FOUR = "four";
constexpr CString FIVE = "five";
constexpr CString SIX = "six";
constexpr CString SEVEN = "seven";
constexpr CString EIGHT = "eight";
constexpr CString NINE = "nine";



u_int32_t find_spelled_number(char *characters)
{
    std::string char_str(characters);

    switch (char_str.length())
    {
    case 5:
        if (char_str.find(THREE))
        {
            return 3;
        }
        else if (char_str.find(SEVEN))
        {
            return 7;
        }
        else if (char_str.find(EIGHT))
        {
            return 8;
        }
    case 4:
        if (char_str.find(FOUR))
        {
            return 4;
        }
        else if(char_str.find(FIVE))
        {
            return 5;
        }
        else if (char_str.find(NINE))
        {
            return 9;
        }
    case 3:
        if (char_str.find(ONE))
        {
            return 1;
        }
        else if (char_str.find(TWO))
        {
            return 2;
        }
        else if (char_str.find(SIX))
        {
            return 6;
        }
    
    default:
        // No number found. Return 0 to indicate this status
        return 0;
    }
}