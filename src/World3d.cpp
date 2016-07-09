#include "World3d.h"

namespace world3
{
	World3d::World3d(int w, int h, int d)
	{
		width = w;
		height = h;
		depth = d;
		grid = (short *)malloc((width + 2)*(height + 2)*(depth + 2)*sizeof(short));
		new_grid = (short *)malloc((width + 2)*(height + 2)*(depth + 2)*sizeof(short));

		for (int i = 0; i < (width + 2)*(height + 2)*(depth + 2); i++)
		{
			grid[i] = 0;
			new_grid[i] = 0;
		}
	}

	World3d::~World3d(){
		free(grid); free(new_grid);
	}

	int World3d::getNewLife(int x, int y, int z)
	{
		return grid[y + x*(width + 2) + z*(width + 2)*(height + 2)];
	}

	void World3d::setNewLife(int x, int y, int z, int val)
	{
		new_grid[y + x*(width + 2) + z*(width + 2)*(height + 2)] = val;
	}

	void World3d::swapGrids()
	{
		std::swap(grid, new_grid);
	}

	int World3d::getNeighbors(int x, int y, int z, int val)
	{
		int count = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (getLifeform(x - 1 + j, y - 1 + i, z - 1 + k) == val)
					{
						//int m[3] = { x - 1 + j, y - 1 + i, z - 1 +k };
						count++;
					}
				}
			}
		}
		if (getLifeform(x, y, z) == val)
		{
			count--;
		}
		return count;
	}

	int World3d::getLifeform(int x, int y, int z)
	{
		return grid[y + x*(width + 2) + z*(width + 2)*(height + 2)];
	}

	void World3d::setLife(int x, int y, int z, int val)
	{
		grid[y + x*(width + 2) + z*(width + 2)*(height + 2)] = val;
	}

	void World3d::print()
	{
		for (int i = 1; i <= height; i++)
		{
			cout << endl;
			for (int j = 1; j <= width; j++)
			{
				for (int k = 1; k <= depth; k++)
				{
					cout << getLifeform(j, i, k) << " ";
				}
			}
		}
		cout << endl;
		cout << endl;

	}
}