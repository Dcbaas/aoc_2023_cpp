#include <algorithm>
#include <iostream>
#include <sstream>
#include <file_utils.h>
#include <cctype>
#include <vector>

#include "spelled_numbers.h"

enum class DATATYPE
{
    example,
    example2,
    main
};

uint32_t determine_calibration_sum(DATATYPE data_type, bool check_spelled_nums=false);

int main()
{

    std::cout << "PART 1" << '\n';
    // Determine the Calibration sum for the example
    auto example_sum = determine_calibration_sum(DATATYPE::example);
    std::cout << "The example calibration sum is " << example_sum << '.' << '\n';

    auto main_sum = determine_calibration_sum(DATATYPE::main);
    std::cout << "The main calibration sum is " << main_sum << '.' << '\n';

    std::cout << "\n\n-----------------------------------------------------------\n\n";
    std::cout << "PART 2" << '\n';
    auto example2_sum = determine_calibration_sum(DATATYPE::example2, true);
    std::cout << "The second example sum is " << example2_sum << '.' << '\n';

    auto main_sum2 = determine_calibration_sum(DATATYPE::main, true);
    std::cout << "The main calibration sum is " << main_sum2 << '.' << '\n';

    return 0; 
}

uint32_t determine_calibration_sum(DATATYPE data_type, bool check_spelled_nums)
{
    uint32_t calibration_sum{0};
    
    fs::path data_path;

    switch (data_type)
    {
    case DATATYPE::example:
        data_path = baas::common::get_example_data_path();
        break;
    case DATATYPE::example2:
        data_path = baas::common::get_example_data2_path();
        break;
    case DATATYPE::main:
    default:
        data_path = baas::common::get_data_path();
        break;
    }

    auto process_line = [&calibration_sum, &check_spelled_nums](std::string_view line)
    {
        char first_digit;
        char second_digit;
        std::stringstream ss;
        uint32_t cal_number;
        std::vector<char> characters;
        for(auto l_it{std::begin(line)}; l_it != std::end(line); ++l_it)
        {
            // Docs say cast char as unsigned char for this C function
            if (std::isdigit(static_cast<unsigned char>(*l_it)))
            {
                first_digit = *l_it;
                break;
            }
            else if (check_spelled_nums)
            {
                char value = *l_it;
                characters.push_back(value);
                char result = find_spelled_number(characters.data());
                if(result != -1)
                {
                    first_digit = result;
                    break;
                }
            }          
        }
        if (check_spelled_nums && !characters.empty())
        {
            characters.clear();
        }
        

        for(auto l_it{std::rbegin(line)}; l_it != std::rend(line); ++l_it)
        {
            if (std::isdigit(static_cast<unsigned char>(*l_it)))
            {
                second_digit = *l_it;
                break;
            }
            else if (check_spelled_nums)
            {
                char value = *l_it;
                characters.push_back(value);
                
                // This may not be optimized but it gets the job done. 
                // REMEMBER to preallocate the reverese vector's inital size before running the reverse algorithim.
                std::vector<char> reverse_chars(characters.size());
                if (characters.size() == 1)
                {
                    reverse_chars = std::vector(characters);
                }
                else
                {
                    std::reverse_copy(std::begin(characters), std::end(characters), std::begin(reverse_chars));
                }
            
                char result = find_spelled_number(reverse_chars.data());
                if (result != -1)
                {
                    second_digit = result;
                    break;
                }
            }
        }

        ss << first_digit << second_digit;
        ss >> cal_number;
        calibration_sum += cal_number;

        if (check_spelled_nums)
        {
            std::cout << cal_number << ":" << calibration_sum << ":" << line << '\n';
        }
        
    };


    baas::common::read_file_line_by_line(data_path, process_line);
    
    return calibration_sum;
}
