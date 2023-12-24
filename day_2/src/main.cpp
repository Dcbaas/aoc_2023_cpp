#include "game.h"
#include <file_utils.h>
#include <iostream>


int main()
{
    fs::path data_path = baas::common::get_data_path();
    uint32_t pt1_game_sum{0};
    uint32_t pt2_cube_power_sum{0};

    auto process_each_line = [&pt1_game_sum, &pt2_cube_power_sum](std::string_view line)
    {
        // Part 1
        auto game = parse_game_line(line);
        if (is_valid_game(game))
        {
            //std::cout << "Valid: " << game << '\n';
            pt1_game_sum += game.game_id;
        }
        else
        {
            //std::cout <<"Invalid: " << game << '\n';
        }

        // Part 2
        uint32_t cube_power = find_cube_power(game);
        std::cout << "Power: " << cube_power << " " << game << '\n';
        pt2_cube_power_sum += cube_power;
    };

    baas::common::read_file_line_by_line(data_path, process_each_line);

    std::cout << pt1_game_sum << '\n';
    std::cout << pt2_cube_power_sum << '\n';

    return 0; 
}

