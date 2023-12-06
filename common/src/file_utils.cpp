#include "file_utils.h"

#include <fstream>

namespace baas::common
{
    void read_file_line_by_line(const fs::path &file_path, std::function<void(const std::string_view)> line_function)
    {
        std::ifstream file(file_path);
        //std::string line_buffer;

        for(std::string line; std::getline(file, line);)
        {
            line_function(line);
        }
    }

    fs::path get_example_data_path()
    {
        return fs::current_path() / "input" / "example.txt";
    }

    fs::path get_data_path()
    {
        return fs::current_path() / "input" / "data.txt";
    }
}