#include <cstdint>
#include "../enum.hpp"

class c_Cell
{
protected:
	uint16_t ID;
public:
	virtual void Spawn(uint8_t *args, uint8_t len) = 0;
	uint16_t GetID() { return ID; }
	c_Cell(){}
};

class c_Fruit : public c_Cell
{
	uint8_t Cal;
public:
	c_Fruit(uint8_t Cal);
	void Spawn(uint8_t* args, uint8_t len);
	uint8_t GetCalorie() { return Cal; }
};

class c_Wall : public c_Cell
{
	uint8_t Color;
public:
	c_Wall(uint8_t Color);
	void Spawn(uint8_t* args, uint8_t len);
	uint8_t GetColor() { return Color; }
};

class c_Empty : public c_Cell
{
public:
	c_Empty() { ID = CELL_EMPTY; }
	void Spawn(uint8_t* args, uint8_t len);
};

