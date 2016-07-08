#include "Life.h"


void Life::update()
{

	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			int m = getNeighbors(j, i, 1);
			if (m == 3)
			{
				setNewLife(j, i, 1);
			}
			if (m == 2)
			{
				setNewLife(j, i, getLifeform(j, i));
			}
			if (m != 3 && m != 2)
			{
				setNewLife(j, i, 0);
			}
		}
	}
	swapGrids();
}
