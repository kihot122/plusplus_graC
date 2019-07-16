#pragma once

#include "enum.hpp"
#include "../cell/cell.hpp"
#include <deque>
#include "../cell/map.hpp"

struct position{
    int X,Y;
};

class c_Snake
{
private:
    bool alive = true;
    int obecny_kierunek;
    int player_color;
    c_Map *playground;
    std::deque<position> tail;
public:
    c_Snake(int ilosc_pustych_pol, int start_x, int start_y, int startowy_kierunek, c_Map *mapa, int start_dlugosc);
    ~c_Snake();
    void Move(int kierunek);
};