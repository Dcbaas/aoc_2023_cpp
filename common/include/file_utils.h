#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <filesystem>
#include <functional>
#include <string>

namespace fs = std::filesystem;

namespace baas::common
{
void read_file_line_by_line(const fs::path& file_path,std::function<void(const std::string_view)> line_function);
fs::path get_example_data_path();
fs::path get_example_data2_path();
fs::path get_data_path();
}

#endif // !FILE_UTILS_H
