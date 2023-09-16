#include "Cube.h"


void Cube::move(unsigned int side, unsigned int pos, unsigned int row)
{
	unsigned int i, j, s;

	//set temp
	std::string temp[6][3][3];
	for (s = 0; s < 6; s++)
	{
		for (i = 0; i <= 2; i++)
		{
			for (j = 0; j <= 2; j++)
			{
				temp[s][i][j] = cube[s][i][j];
			}
		}
	}
	
	//move(0, 1)
	if (ACCEPTABLE_MOVES_1)
	{ 
		for (i = 0; i <= 2; i++)
		{
			cube[1][i][row] = temp[0][row][2 - i];
			cube[0][row][i] = temp[3][i][2 - row];
			cube[3][i][2 - row] = temp[5][2 - row][2 - i];
			cube[5][2 - row][i] = temp[1][i][row];
		}
		if (row == 0)
		{
			cube[4][0][0] = temp[4][2][0];
			cube[4][0][1] = temp[4][1][0];
			cube[4][0][2] = temp[4][0][0];
			cube[4][1][2] = temp[4][0][1];
			cube[4][2][2] = temp[4][0][2];
			cube[4][2][1] = temp[4][1][2];
			cube[4][2][0] = temp[4][2][2];
			cube[4][1][0] = temp[4][2][1];
		}
		if (row == 2)
		{
			cube[2][0][0] = temp[2][0][2];
			cube[2][0][1] = temp[2][1][2];
			cube[2][0][2] = temp[2][2][2];
			cube[2][1][2] = temp[2][2][1];
			cube[2][2][2] = temp[2][2][0];
			cube[2][2][1] = temp[2][1][0];
			cube[2][2][0] = temp[2][0][0];
			cube[2][1][0] = temp[2][0][1];
		}
	}
	// move(0, 2)
	else if (ACCEPTABLE_MOVES_2)
	{
		for (i = 0; i <= 2; i++)
		{
			cube[5][i][row] = temp[2][i][row];
			cube[2][i][row] = temp[0][i][row];
			cube[0][i][row] = temp[4][2 - i][2 - row];
			cube[4][2 - i][2 - row] = temp[5][i][row];
		}
		if (row == 0)
		{
			cube[1][0][0] = temp[1][2][0];
			cube[1][0][1] = temp[1][1][0];
			cube[1][0][2] = temp[1][0][0];
			cube[1][1][2] = temp[1][0][1];
			cube[1][2][2] = temp[1][0][2];
			cube[1][2][1] = temp[1][1][2];
			cube[1][2][0] = temp[1][2][2];
			cube[1][1][0] = temp[1][2][1];
		}
		if (row == 2)
		{
			cube[3][0][0] = temp[3][0][2];
			cube[3][0][1] = temp[3][1][2];
			cube[3][0][2] = temp[3][2][2];
			cube[3][1][2] = temp[3][2][1];
			cube[3][2][2] = temp[3][2][0];
			cube[3][2][1] = temp[3][1][0];
			cube[3][2][0] = temp[3][0][0];
			cube[3][1][0] = temp[3][0][1];
		}

	}
	//move(0, 3) 
	else if (ACCEPTABLE_MOVES_3)
	{
		for (i = 0; i <= 2; i++)
		{
			cube[0][row][i] = temp[1][2 - i][row];
			cube[1][i][row] = temp[5][2 - row][i];
			cube[5][2 - row][i] = temp[3][2 - i][2 - row];
			cube[3][i][2 - row] = temp[0][row][i];	
		}
		if (row == 0)
		{
			cube[4][0][0] = temp[4][0][2];
			cube[4][0][1] = temp[4][1][2];
			cube[4][0][2] = temp[4][2][2];
			cube[4][1][2] = temp[4][2][1];
			cube[4][2][2] = temp[4][2][0];
			cube[4][2][1] = temp[4][1][0];
			cube[4][2][0] = temp[4][0][0];
			cube[4][1][0] = temp[4][0][1];

		}
		if (row == 2)
		{
			cube[2][0][0] = temp[2][2][0];
			cube[2][0][1] = temp[2][1][0];
			cube[2][0][2] = temp[2][0][0];
			cube[2][1][2] = temp[2][0][1];
			cube[2][2][2] = temp[2][0][2];
			cube[2][2][1] = temp[2][1][2];
			cube[2][2][0] = temp[2][2][2];
			cube[2][1][0] = temp[2][2][1];
		}
	}

	// move(0, 4)
	else if (ACCEPTABLE_MOVES_4)
	{
		for (i = 0; i <= 2; i++)
		{
			cube[0][i][row] = temp[2][i][row];
			cube[2][i][row] = temp[5][i][row];
			cube[5][i][row] = temp[4][2-i][2-row];
			cube[4][2 - i][2 - row] = temp[0][i][row];
		}
		if (row == 0)
		{
			cube[1][0][0] = temp[1][0][2];
			cube[1][0][1] = temp[1][1][2];
			cube[1][0][2] = temp[1][2][2];
			cube[1][1][2] = temp[1][2][1];
			cube[1][2][2] = temp[1][2][0];
			cube[1][2][1] = temp[1][1][0];
			cube[1][2][0] = temp[1][0][0];
			cube[1][1][0] = temp[1][0][1];
		}
		if (row == 2)
		{
			cube[3][0][0] = temp[3][2][0];
			cube[3][0][1] = temp[3][1][0];
			cube[3][0][2] = temp[3][0][0];
			cube[3][1][2] = temp[3][0][1];
			cube[3][2][2] = temp[3][0][2];
			cube[3][2][1] = temp[3][1][2];
			cube[3][2][0] = temp[3][2][2];
			cube[3][1][0] = temp[3][2][1];
		}
	}
	
	// move(1, 2)
	else if (ACCEPTABLE_MOVES_5)
	{
		for (i = 0; i <= 2; i++)
		{
			cube[2][row][i] = temp[1][row][i];
			cube[3][row][i] = temp[2][row][i];
			cube[4][row][i] = temp[3][row][i];
			cube[1][row][i] = temp[4][row][i];

		}
		if (row == 0)
		{
			cube[0][0][0] = temp[0][0][2];
			cube[0][0][1] = temp[0][1][2];
			cube[0][0][2] = temp[0][2][2];
			cube[0][1][2] = temp[0][2][1];
			cube[0][2][2] = temp[0][2][0];
			cube[0][2][1] = temp[0][1][0];
			cube[0][2][0] = temp[0][0][0];
			cube[0][1][0] = temp[0][0][1];
		}
		if (row == 2)
		{
			cube[5][0][0] = temp[5][2][0];
			cube[5][0][1] = temp[5][1][0];
			cube[5][0][2] = temp[5][0][0];
			cube[5][1][2] = temp[5][0][1];
			cube[5][2][2] = temp[5][0][2];
			cube[5][2][1] = temp[5][1][2];
			cube[5][2][0] = temp[5][2][2];
			cube[5][1][0] = temp[5][2][1];
		}
	}
	// move(1, 4)
	else if (ACCEPTABLE_MOVES_6)
	{
		for (i = 0; i <= 2; i++)
		{
			cube[2][row][i] = temp[3][row][i];
			cube[3][row][i] = temp[4][row][i];
			cube[4][row][i] = temp[1][row][i];
			cube[1][row][i] = temp[2][row][i];
		}
		if (row == 0)
		{
			cube[0][0][0] = temp[0][2][0];
			cube[0][0][1] = temp[0][1][0];
			cube[0][0][2] = temp[0][0][0];
			cube[0][1][2] = temp[0][0][1];
			cube[0][2][2] = temp[0][0][2];
			cube[0][2][1] = temp[0][1][2];
			cube[0][2][0] = temp[0][2][2];
			cube[0][1][0] = temp[0][2][1];
		}
		if (row == 2)
		{
			cube[5][0][0] = temp[5][0][2];
			cube[5][0][1] = temp[5][1][2];
			cube[5][0][2] = temp[5][2][2];
			cube[5][1][2] = temp[5][2][1];
			cube[5][2][2] = temp[5][2][0];
			cube[5][2][1] = temp[5][1][0];
			cube[5][2][0] = temp[5][0][0];
			cube[5][1][0] = temp[5][0][1];
		}

	}
}

Cube::Cube()
{
	unsigned int i, j;

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			cube[0][i][j] = "WHITE";
			cube[1][i][j] = "GREEN";
			cube[2][i][j] = "RED";
			cube[3][i][j] = "BLUE";
			cube[4][i][j] = "ORANGE";
			cube[5][i][j] = "YELLOW";
		}
	}
}
void Cube::ToString()
{
	unsigned int s, i, j;
	for (s = 0; s <= 5; s++)
	{
		std::cout << s << " side" << std::endl;
		for (i = 0; i <= 2; i++)
		{
			std::cout << std::endl;
			for (j = 0; j <= 2; j++)
			{
				std::cout << cube[s][i][j] << '\t';
			}
			std::cout << std::endl;
		}
	}
}

bool Cube::equals(Cube a)
{
	bool result = true;
	unsigned int s, i, j;
	for (s = 0; s <= 5; s++)
	{
		for (i = 0; i <= 2; i++)
		{
			for (j = 0; j <= 2; j++)
			{
				if (cube[s][i][j] != a.cube[s][i][j])
				{
					result = false;
					break;
				}
			}
			if (result == false)
				break;
		}
		if (result == false)
			break;
	}
	return result;
}
	

	

