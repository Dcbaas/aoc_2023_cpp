#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <ostream>
#include <span>
#include <string>

struct Game
{
    uint32_t game_id;
    uint32_t revealed_red {0};
    uint32_t revealed_green {0};
    uint32_t revealed_blue {0};
};

std::ostream& operator<<(std::ostream& os, const Game& game);

Game parse_game_line(std::string_view line);

bool is_valid_game(const Game game);

#endif