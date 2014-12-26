#include "stdafx.h"
#include "bubble.h"

bubble::bubble()
{
	num = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			coord.count = 0;
			coord.x = i;
			coord.y = j;
			bubbles.push_back(coord);
		}
	}
}

void bubble::add()
{
	srand(time(NULL));

	int obj = rand() % num + 1;
	int x, y;

	for (int i = 0; i < obj; i++)
	{
		x = rand() % 10;
		y = rand() % 10;

		if (bubbles[(x * 10) + y].count < 6)
		{
			bubbles[(x * 10) + y].count++;
		}
	}
}

bubble::~bubble()
{
	bubbles.clear();
}
