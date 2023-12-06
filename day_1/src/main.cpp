#include <iostream>
#include <sstream>
#include <file_utils.h>
#include <cctype>

enum class DATATYPE
{
    example,
    example2,
    main
};

uint32_t determine_calibration_sum(DATATYPE data_type);

int main()
{

    // Determine the Calibration sum for the example
    auto example_sum = determine_calibration_sum(DATATYPE::example);
    std::cout << "The example calibration sum is " << example_sum << '.' << '\n';

    auto main_sum = determine_calibration_sum(DATATYPE::main);
    std::cout << "The main calibration sum is " << main_sum << '.' << '\n';
    return 0; 
}

uint32_t determine_calibration_sum(DATATYPE data_type)
{
    uint32_t calibration_sum{0};
    
    fs::path data_path;
    if (data_type == DATATYPE::example)
    {
        data_path = baas::common::get_example_data_path();
    } 
    else
    {
        data_path = baas::common::get_data_path();
    }

    auto process_line = [&calibration_sum](std::string_view line)
    {
        char first_digit;
        char second_digit;
        std::stringstream ss;
        uint32_t cal_number;
        for(auto l_it{std::begin(line)}; l_it != std::end(line); ++l_it)
        {
            // Docs say cast char as unsigned char for this C function
            if (std::isdigit(static_cast<unsigned char>(*l_it)))
            {
                first_digit = *l_it;
                break;
            }           
        }

        for(auto l_it{std::rbegin(line)}; l_it != std::rend(line); ++l_it)
        {
            if (std::isdigit(static_cast<unsigned char>(*l_it)))
            {
                second_digit = *l_it;
                break;
            }
        }

        ss << first_digit << second_digit;
        ss >> cal_number;
        calibration_sum += cal_number;
    };


    baas::common::read_file_line_by_line(data_path, process_line);
    
    return calibration_sum;
}
