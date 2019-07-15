#include "cell.hpp"

c_Fruit::c_Fruit(uint8_t _Cal)
{
	ID = CELL_FRUIT;
	Cal = _Cal;
}

void c_Fruit::Spawn(uint8_t* args, uint8_t len){}
void c_Wall::Spawn(uint8_t *argc, uint8_t len){}
void c_Empty::Spawn(uint8_t* argc, uint8_t len){}