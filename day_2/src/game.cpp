#include "game.h"

#include <string_utils.h>
#include <iostream>
#include <sstream>
#include <vector>

enum class Color 
{
    red,
    green,
    blue
};

Color identify_color(std::string_view color_str);
void update_counts(Game& game, const Color color, const uint32_t cube_count);


Game parse_game_line(std::string_view line)
{
    Game game;
    std::stringstream ss;

    // Split Game ID and game info
    std::vector<std::string> game_data_split = baas::common::str_split(line, ": ");
    std::string game_id_str = game_data_split[0];
    std::string game_data_str = game_data_split[1];

    // Get Game Id
    std::vector<std::string> game_id_split = baas::common::str_split(game_id_str, " ");
    ss << game_data_split[1];
    ss >> game.game_id;
    ss.clear();

    // Split grab events
    std::vector<std::string> grab_events = baas::common::str_split(game_data_str, "; ");

    // Parse each grab event to populate the Game struct
    for (auto& grab : grab_events)
    {
        std::vector<std::string> cubes_split = baas::common::str_split(grab, ", ");
        for (auto& cubes: cubes_split)
        {
            std::vector<std::string> cube_data_split = baas::common::str_split(cubes, " ");
            Color color = identify_color(cube_data_split[0]);

            uint32_t cube_count;
            
            ss << cube_data_split[1];
            ss >> cube_count;
            ss.clear();
            update_counts(game, color, cube_count);
        }
    }
    return game;
}

// In the end this conversion might be a waste of time. Oh well.
Color identify_color(std::string_view color_str)
{
    char first_letter = color_str[0];
    switch (first_letter)
    {
    case 'r':
        return Color::red;
    case 'g':
        return Color::green;
    case 'b':
        return Color::blue;
    default:
        std::cerr << "No correct color provided: " << color_str << '\n';
        return Color::blue;
    }
    
    return Color();
}

void update_counts(Game &game, const Color color, const uint32_t cube_count)
{
    switch (color)
    {
    case Color::red:
        if (game.revealed_red < cube_count)
        {
            game.revealed_red = cube_count;
        }
        break;
    case Color::green:
        if (game.revealed_green < cube_count)
        {
            game.revealed_green = cube_count;
        }
        break;
    case Color::blue:
    default:
        if (game.revealed_blue < cube_count)
        {
            game.revealed_blue = cube_count;
        }
    }
}

bool is_valid_game(const Game game)
{
    constexpr uint32_t MAX_RED{12};
    constexpr uint32_t MAX_GREEN{13};
    constexpr uint32_t MAX_BLUE{14};

    return game.revealed_red <= MAX_RED && game.revealed_green <= MAX_GREEN && game.revealed_blue <= MAX_BLUE;
}
