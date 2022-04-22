#include "Life3d.h"
#include "Life.h"

#include <ctime>

#include <GL/glut.h>

using namespace life3;

#ifndef GLSCENE_H
#define GLSCENE_H

enum Scene
{
	scene1,
	scene2
};

void GLScene(int argc, char*argv[]);
void GLScene(int, int, int argc, char*argv[]);
void Cleanup();

void newLife();
void newlife3d();

void DisplayGL();
void KeyboardGL(unsigned char c, int x, int y);
void ReshapeGL(int w, int h);

void render();
void render3d();
#endif
