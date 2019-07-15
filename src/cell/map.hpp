#include "cell.hpp"

class c_Map
{
	uint16_t Size[2];
	c_Cell*** Grid;
public:
	c_Map(uint16_t SizeX, uint16_t SizeY);
	void SetCell(uint16_t X, uint16_t Y, c_Cell* Cell);
	c_Cell *GetCell(uint16_t X, uint16_t Y);
	uint16_t *GetSize() { return Size; }
};