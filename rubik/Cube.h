#pragma once
#include "Define.h"
#include <iostream>
#include <string>
#include <cstdlib>


class Cube
{
public:
	std::string cube[6][3][3];
	Cube();
	void ToString();
	void move(unsigned int side, unsigned int pos, unsigned int row);
	bool equals(Cube a);
};