#include "World3d.h"

using namespace world3;

#ifndef LIFE3D_H
#define LIFE3D_H
namespace life3
{
	class Life3d : public World3d
	{
	public:
		Life3d(int x, int y, int z) : World3d(x, y, z){}

		virtual void update();
	};
}
#endif
