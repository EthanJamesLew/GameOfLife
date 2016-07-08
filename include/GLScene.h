#include <cstdlib>
#include "life.h"
#include <GL\glut.h>
#ifndef GLSCENE_H
#define GLSCENE_H


void GLScene(int argc, char*argv[]);
void GLScene(int, int, int argc, char*argv[]);
void Cleanup();

void DisplayGL();
void KeyboardGL(unsigned char c, int x, int y);

void DrawRectangle(float, float);

void render();

void ReshapeGL(int w, int h);
#endif
