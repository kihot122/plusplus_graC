#include "enum.hpp"
#include "snake.hpp"

c_Snake::c_Snake(uint16_t color, uint16_t start_x, uint16_t start_y, uint16_t startowy_kierunek, c_Map *mapa, uint16_t start_dlugosc = 3)
{
    obecny_kierunek = startowy_kierunek;
    playground = mapa; 
    player_color = color;

    switch (startowy_kierunek)
    {
    case lewo:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x + i, start_y});
        }
        break;
    
    case prawo:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x - i, start_y});
        }
        break;
        
    case gora:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x,start_y-i});
        }
        break;

    case dol:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x,start_y+i});
        }
        break;
    
    }

    std::deque<position>::iterator x = tail.begin();
    while (x!=tail.end())
    {
        playground->SetCell(x[0].X,x[0].Y,new c_Wall(player_color));
        *x++; 
    } 
}

c_Snake::~c_Snake()
{
    std::deque<position>::iterator x = tail.begin();
    
    while (x!=tail.end())
    {
        playground->SetCell(x[0].X,x[0].Y,new c_Empty());
        *x++; 
    }
    
    
}

void c_Snake::Move(uint16_t kierunek = NULL){

    if(!kierunek) kierunek=obecny_kierunek;

    position next_Cell = tail[0];

    switch (kierunek)
    {
    case lewo:
        next_Cell.X--;
        break;
    case prawo:
        next_Cell.X++;
        break;
    case gora:
        next_Cell.Y++;
        break;
    case dol:
        next_Cell.Y--;
        break;
    }

    switch ((playground->GetCell(next_Cell.X,next_Cell.Y))->GetID())
    {
    case CELL_EMPTY:
        playground->SetCell(next_Cell.X,next_Cell.Y,new c_Wall(player_color));
        tail.push_front(next_Cell);
        tail.pop_back();
        break;
    
    case CELL_FRUIT:
        playground->SetCell(next_Cell.X,next_Cell.Y,new c_Wall(player_color));
        tail.push_front(next_Cell);

    case CELL_WALL:
        alive = false;
    }

}