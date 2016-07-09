#include "Life3d.h"

namespace life3
{
	void Life3d::update()
	{

		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				for (int k = 1; k <= depth; k++)
				{
					int m = getNeighbors(i, j, k, 1);
					if (m == 5)
					{
						setNewLife(i, j, k, 1);
					}
					else
					if (m < 3)
					{
						setNewLife(i, j, k, 0);
					}
					else
					if (m > 5)
					{
						setNewLife(i, j, k, 0);
					}
					else if (m == 4 | m == 5)
					{
						setNewLife(i, j, k, getLifeform(i, j, k));
					}
				}
			}
		}
		swapGrids();
	}
}