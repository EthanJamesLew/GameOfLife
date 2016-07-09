#include <iostream>
using std::cout;
using std::malloc;
using std::endl;

#ifndef WORLD3D_H
#define WORLD3D_H

namespace world3
{
	class World3d
	{
	protected:
		short* grid;
		short* new_grid;
		unsigned int width;
		unsigned int height;
		unsigned int depth;

		int getNewLife(int x, int y, int z);
		void setNewLife(int x, int y, int z, int val);
		void swapGrids();

	public:
		World3d(int, int, int);
		~World3d();

		int getNeighbors(int, int, int, int);

		int getLifeform(int x, int y, int z);
		void setLife(int x, int y, int z, int val);
		virtual void update(){ }

		void print();
	};

}

#endif
