#pragma once

class c_Snake
{
private:
    int obecny_kierunek;
    int obecna_dlugosc;
    //c_Cell = *ogon;
public:
    c_Snake(int ilosc_pustych_pol, int start_x, int start_y, int startowy_kierunek, int start_dlugosc = 3);
    ~c_Snake();
    move(int kierunek, int pole = puste);
};

c_Snake::c_Snake(int ilosc_pustych_pol, int start_x, int start_y, int startowy_kierunek, int start_dlugosc = 3)
{
}

c_Snake::~c_Snake()
{
}

c_Snake::move(int kierunek, int pole = puste)
{
}