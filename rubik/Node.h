#pragma once
#include "Cube.h"

class Node
{
public:

	Cube cube;
	
	float f;
	unsigned int g;
	unsigned int id;

	unsigned int fathersID;


	bool operator == (const  Node& n) const { return id == n.id; }
	bool operator != (const  Node& n) const { return !operator==(n);}
	
};