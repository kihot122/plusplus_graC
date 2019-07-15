#include "map.hpp"

c_Map::c_Map(uint16_t SizeX, uint16_t SizeY) : Size{SizeX, SizeY}
{
	Grid = new c_Cell **[SizeX];
	for (int i = 0; i < SizeX; i++)
	{
		Grid[i] = new c_Cell * [SizeY];
		for (int j = 0; j < SizeY; j++)
			Grid[i][j] = new c_Empty;
	}
}

void c_Map::SetCell(uint16_t X, uint16_t Y, c_Cell* Cell)
{
	delete Grid[X][Y];
	Grid[X][Y] = Cell;
}

c_Cell* c_Map::GetCell(uint16_t X, uint16_t Y)
{
	return Grid[X][Y];
}