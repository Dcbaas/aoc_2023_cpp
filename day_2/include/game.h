#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <span>
#include <string>

struct Game
{
    uint32_t game_id;
    uint32_t revealed_red;
    uint32_t revealed_green;
    uint32_t revealed_blue;
};

Game parse_game_line(std::string_view line);

#endif