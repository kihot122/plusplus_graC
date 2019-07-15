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

struct c_Fruit : public c_Cell
{
	uint8_t Cal;
public:
	c_Fruit(uint8_t _Cal);
	void Spawn(uint8_t* args, uint8_t len);
	uint8_t GetCalorie() { return Cal; }
};

struct c_Wall : public c_Cell
{
	c_Wall() { ID = CELL_WALL; }
public:
	void Spawn(uint8_t* args, uint8_t len);
};

struct c_Empty : public c_Cell
{
	c_Empty(){ ID = CELL_EMPTY; }
public:
	void Spawn(uint8_t* args, uint8_t len);
};