#include "cell.hpp"

c_Fruit::c_Fruit(uint8_t Cal) : Cal(Cal)
{
	ID = CELL_FRUIT;
}

c_Wall::c_Wall(uint8_t Color) : Color(Color)
{
	ID = CELL_WALL;
}

void c_Fruit::Spawn(uint8_t* args, uint8_t len){}
void c_Wall::Spawn(uint8_t *argc, uint8_t len){}
void c_Empty::Spawn(uint8_t* argc, uint8_t len){}
void c_SnakeHead::Spawn(uint8_t* args, uint8_t len) {}
void c_SnakeTail::Spawn(uint8_t* args, uint8_t len) {}