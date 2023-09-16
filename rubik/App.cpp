#include <iostream>
#include <list>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include "Cube.h"
#include "Node.h"

//how many moves does it take to get to the right side if you could just jump from side to side (up to 2 per tile)
float h(Cube c);

Node childWithSmallestF(Node children[18], unsigned int numOfChildren, unsigned int min);

bool IsInOpen(std::list<Node> openList, Cube cube);
bool IsInClosed(std::list<Node> closedList, Cube cube);


int main()
{
	Cube c;

	// Α' τρόπος Δημιουργίας κύβου
	
	c.move(0, 1, 2);
	c.move(1, 2, 0);
	c.move(1, 2, 1);


	int s, i, j, pos, row;

	/*
	// B' τρόπος Δημιουργίας κύβου

	srand(time(NULL));
	for (i = 0; i < 4; i++)
	{
		s = rand() % 2;
		pos = rand() % 6;
		while (pos == s || !ACCEPTABLE_MOVES)
		{
			pos = rand() % 6;
		}
		row = rand() % 3;
		c.move(s, pos, row);
		//std::cout << "move " << s;
		//std::cout << " to " << pos;
		//std::cout << " row " << row << std::endl;
	}
	*/
	

	Node current;
	current.cube = c;
	current.f = 0.f;
	current.g = 0;
	current.id = 0;
	current.fathersID = current.id;
	
	std::list<Node> openList;
	std::list<Node> closedList;
	std::list<Node> path;

	//put the startNode on the openList
	openList.push_back(current);
	path.push_back(current);

	Node children[18];

	unsigned int g;
	float f;
	unsigned int id = 1;
	unsigned int count = 0;
	i = 0;

	Cube temp;
	

	while (!openList.empty())
	{
		std::cout << "Waiting..";
		if (h(current.cube) == 0)
		{
			for (auto p : path)
			{
				if (count == 0)
					std::cout << std::endl << "This was the Starting Position:" << std::endl;
				else if (count == 1)
					std::cout << std::endl << "This was the 1st move:" << std::endl;
				else if (count == 2)
					std::cout << std::endl << "This was the 2nd move:" << std::endl;
				else if (count == 3)
					std::cout << std::endl << "This was the 3rd move:" << std::endl;
				else
					std::cout << std::endl << "This was your " << count << "th move:" << std::endl;
				p.cube.ToString();
				count++;
			}
			break;
		}
		else
		{
			temp = current.cube;

			g = current.g + 1;
			i = 0;

			//find all the children of the current Node and add them to the openList exept if the are already in the openList or the closedList
			for (s = 1; s <= 4; s++)
			{
				for (j = 0; j <= 2; j++)
				{
					temp.move(0, s, j);
					if (!IsInOpen(openList, temp) && !IsInClosed(closedList, temp))
					{
						f = h(temp) + g;
						children[i].cube = temp;
						children[i].fathersID = current.id;
						children[i].f = f;
						children[i].g = g;
						children[i].id = id;
						openList.push_back(children[i]);
						i++;
						id++;
					}	
					temp = current.cube;
				}
			}
			for (j = 0; j <= 2; j++)
			{
				temp.move(1, 4, j);
				if (!IsInOpen(openList, temp) && !IsInClosed(closedList, temp))
				{
					f = h(temp) + g;
					children[i].cube = temp;
					children[i].fathersID = current.id;
					children[i].f = f;
					children[i].g = g;
					children[i].id = id;
					openList.push_back(children[i]);
					i++;
					id++;
				}
				temp = current.cube;
			}
			for (j = 0; j <= 2; j++)
			{
				temp.move(1, 2, j);
				if (!IsInOpen(openList, temp) && !IsInClosed(closedList, temp))
				{
					f = h(temp) + g;
					children[i].cube = temp;
					children[i].fathersID = current.id;
					children[i].f = f;
					children[i].g = g;
					children[i].id = id;
					openList.push_back(children[i]);
					i++;
					id++;
				}
				temp = current.cube;
			}
			openList.remove(current);
			closedList.push_back(current);
			bool found = false;
			for (auto& o : openList)
			{
				if (o.f < childWithSmallestF(children, i, 100).f)
				{
					found = true;
					current = o;
					while (o.fathersID != path.back().id && path.back().id!=0)
					{
						path.pop_back();
					}
					
					break;
				}
			}
			if (!found)
			{
				current = childWithSmallestF(children, i, 100);
			}
			path.push_back(current);
		}
	}
	if (openList.empty())
	{
		std::cout << "Cube is unsolvable";
	}


	return 0;
}

float h(Cube c)
{
	unsigned int s, i, j;
	int moves = 0;
	unsigned int whiteSide, greenSide, redSide, blueSide, orangeSide, yellowSide;
	for (s = 0; s < 6; s++)
	{
		if (c.cube[s][1][1] == "WHITE")
			whiteSide = s;
		else if (c.cube[s][1][1] == "GREEN")
			greenSide = s;
		else if (c.cube[s][1][1] == "RED")
			redSide = s;
		else if (c.cube[s][1][1] == "BLUE")
			blueSide = s;
		else if (c.cube[s][1][1] == "ORANGE")
			orangeSide = s;
		else if (c.cube[s][1][1] == "YELLOW")
			yellowSide = s;

	}
	for (s = 0; s < 6; s++)
	{
		for (i = 0; i <= 2; i++)
		{
			for (j = 0; j <= 2; j++)
			{
				//Then it has to go at whiteSide
				if (c.cube[s][i][j] == "WHITE")
				{
					if (s == greenSide || s == redSide || s == blueSide || s == orangeSide)
						moves += 1;
					else if (s == yellowSide)
						moves += 2;
				}
				//Then it has to go at greenside
				else if (c.cube[s][i][j] == "GREEN")
				{
					if (s == whiteSide || s == redSide || s == orangeSide || s == yellowSide)
						moves += 1;
					else if (s == blueSide)
						moves += 2;
				}
				//Then it has to go at side 2
				else if (c.cube[s][i][j] == "RED")
				{
					if (s == whiteSide || s == greenSide || s == blueSide || s == yellowSide)
						moves += 1;
					else if (s == orangeSide)
						moves += 2;
				}
				//Then it has to go at side 3
				else if (c.cube[s][i][j] == "BLUE")
				{
					if (s == whiteSide || s == redSide || s == orangeSide || s == yellowSide)
						moves += 1;
					else if (s == greenSide)
						moves += 2;
				}
				//Then it has to go at side 4
				else if (c.cube[s][i][j] == "ORANGE")
				{
					if (s == whiteSide || s == greenSide || s == blueSide || s == yellowSide)
						moves += 1;
					else if (s == redSide)
						moves += 2;
				}
				//Then it has to go at side 5 (YELLOW)
				else
				{
					if (s == greenSide || s == redSide || s == blueSide || s == orangeSide)
						moves += 1;
					else if (s == whiteSide)
						moves += 2;
				}
			}
		}
	}
	return (float)moves/8.f;
}

Node childWithSmallestF(Node children[18], unsigned int num, unsigned int min)
{
	unsigned int i;
	Node result;

	for (i = 0; i < num; i++)
	{
		if (children[i].f < min)
		{
			min = children[i].f;
			result = children[i];
		}	
	}
	return result;
}

bool IsInOpen(std::list<Node> openList, Cube cube)
{
	bool flag = false;
	for (auto o : openList)
	{
		if (o.cube.equals(cube))
		{
			flag = true;
			break;
		}

	}
	return flag;
}

bool IsInClosed(std::list<Node> closedList, Cube cube)
{
	bool flag = false;
	for (auto c : closedList)
	{
		if (c.cube.equals(cube))
		{
			flag = true;
			break;
		}
	}
	return flag;
}
