#include "Life3d.h"

namespace life3
{
	void Life3d::update()
	{

		for (unsigned int i = 1; i <= height; i++)
		{
			for (unsigned int j = 1; j <= width; j++)
			{
				for (unsigned int k = 1; k <= depth; k++)
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
					else if ((m == 4) | (m == 5))
					{
						setNewLife(i, j, k, getLifeform(i, j, k));
					}
				}
			}
		}
		swapGrids();
	}
}
