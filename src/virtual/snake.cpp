#include "enum.hpp"
#include "snake.hpp"

c_Snake::c_Snake(uint16_t color, uint16_t start_x, uint16_t start_y, uint16_t startowy_kierunek, c_Map *mapa, uint16_t start_dlugosc = 3)
{
    obecny_kierunek = startowy_kierunek;
    playground = mapa; 
    player_color = color;

    switch (startowy_kierunek)
    {
    case LEFT:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x + i, start_y});
        }
        break;
    
    case RIGHT:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x - i, start_y});
        }
        break;
        
    case UP:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x,start_y-i});
        }
        break;

    case DOWN:
        for (uint16_t i = 0; i < start_dlugosc; i++)
        {
            tail.push_back({start_x,start_y+i});
        }
        break;
    
    }

    std::deque<position>::iterator x = tail.begin();
    while (x!=tail.end())
    {
        playground->SetCell(x[0].X,x[0].Y,new c_SnakeTail);
        *x++; 
    } 

    MakeHead();

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

void c_Snake::Move(){

    position next_Cell = tail[0];

    switch (obecny_kierunek)
    {
    case LEFT:
        next_Cell.X--;
        break;
    case RIGHT:
        next_Cell.X++;
        break;
    case UP:
        next_Cell.Y++;
        break;
    case DOWN:
        next_Cell.Y--;
        break;
    }

    switch ((playground->GetCell(next_Cell.X,next_Cell.Y))->GetID())
    {
    case CELL_EMPTY:
        playground->SetCell(next_Cell.X,next_Cell.Y,new c_SnakeTail);
        tail.push_front(next_Cell);
        playground->SetCell(tail.back().X,tail.back().Y,new c_Empty());
        tail.pop_back();
        break;
    
    case CELL_FRUIT:
        playground->SetCell(next_Cell.X,next_Cell.Y,new c_SnakeTail);
        tail.push_front(next_Cell);

    case CELL_WALL:
        alive = false;
    }

    MakeHead();

}

void c_Snake::Move(uint16_t kierunek){

    position next_Cell = tail[0];

    switch (kierunek)
    {
    case LEFT:
        next_Cell.X--;
        break;
    case RIGHT:
        next_Cell.X++;
        break;
    case UP:
        next_Cell.Y++;
        break;
    case DOWN:
        next_Cell.Y--;
        break;
    }

    switch ((playground->GetCell(next_Cell.X,next_Cell.Y))->GetID())
    {
    case CELL_EMPTY:
        playground->SetCell(next_Cell.X,next_Cell.Y,new c_SnakeTail);
        tail.push_front(next_Cell);
        playground->SetCell(tail.back().X,tail.back().Y,new c_Empty());
        tail.pop_back();
        break;
    
    case CELL_FRUIT:
        playground->SetCell(next_Cell.X,next_Cell.Y,new c_SnakeTail);
        tail.push_front(next_Cell);

    case CELL_WALL:
        alive = false;
    }

    MakeHead();

}

void c_Snake::MakeHead()
{
    playground->SetCell(tail[0].X,tail[0].Y,new c_SnakeHead);
}