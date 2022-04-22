#include "World.h"
#include "Life.h"

#include <iostream>
#include "time.h"

//#include <stdlib.h>
//#include <Windows.h>

#include "GLScene.h"

using std::malloc;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	GLScene(argc, argv);
	glutMainLoop();
}
