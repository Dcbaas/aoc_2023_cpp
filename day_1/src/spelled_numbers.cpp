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



char find_spelled_number(char* characters)
{
    std::string char_str(characters);

    if (char_str.find(THREE) != std::string::npos)
    {
        return '3';
    }
    else if (char_str.find(SEVEN) != std::string::npos)
    {
        return '7';
    }
    else if (char_str.find(EIGHT) != std::string::npos) 
    {
        return '8';
    }
    if (char_str.find(FOUR) != std::string::npos)
    {
        return '4';
    }
    else if(char_str.find(FIVE) != std::string::npos)
    {
        return '5';
    }
    else if (char_str.find(NINE) != std::string::npos)
    {
        return '9';
    }
    if (char_str.find(ONE) != std::string::npos)
    {
        return '1';
    }
    else if (char_str.find(TWO) != std::string::npos)
    {
        return '2';
    }
    else if (char_str.find(SIX) != std::string::npos)
    {
        return '6';
    }
    
    return -1;
}