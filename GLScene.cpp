#include "GLScene.h"

int size = 500;

Life * life = new Life(size, size);

int window_width;
int window_height;
int g_GLUTWindowHandle;
int g_ErrorCode;
float y_offset;
float x_offset;
float scal = 0.0f;

void GLScene(int argc, char*argv[])
{
	GLScene(900, 900, argc, argv);
}

void GLScene(int x, int y, int argc, char*argv[])
{
	for (int i = 0; i < 100000; i++)
	{
		int x = rand() % size + 1;
		int y = rand() % size + 1;
		life->setLife(x, y, 1);
	}

	window_height = y;
	window_width = x;

	glutInit(&argc, argv);
	
	glutInitWindowPosition(30, 30);
	glutInitWindowSize(window_width, window_height);

	window_width = glutGet(GLUT_SCREEN_WIDTH);
	window_height = glutGet(GLUT_SCREEN_HEIGHT);

	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);


	g_GLUTWindowHandle = glutCreateWindow("Conway's Game of Life");
	glutInitWindowSize(window_width, window_height);

	glutDisplayFunc(DisplayGL);
	glutKeyboardFunc(KeyboardGL);
	glutReshapeFunc(ReshapeGL);

	glClearColor(0.156f, 0.172f, 0.203f, 1.00f);
	glClearDepth(1.0f);
	glShadeModel(GL_SMOOTH);

}

void Cleanup()
{
	if (g_GLUTWindowHandle != 0)
	{
		glutDestroyWindow(g_GLUTWindowHandle);
		g_GLUTWindowHandle = 0;
	}
	if (false)
	{
		exit(g_ErrorCode);
	}

}

void DisplayGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	render();
	glutSwapBuffers();
	glutPostRedisplay();
}

void newLife()
{
	life = new Life(size, size);
	for (int i = 0; i < .6*size*size; i++)
	{
		int x = rand() % size + 1;
		int y = rand() % size + 1;
		life->setLife(x, y, 1);
	}
}



void KeyboardGL(unsigned char c, int x, int y)
{
	if (c == 'w')
	{
		y_offset = y_offset - ((float)size/500) *0.1;
	}

	if (c == 's')
	{
		y_offset += ((float)size / 500) *0.1;
	}

	if (c == 'd')
	{
		x_offset -= ((float)size / 500) *0.1;
	}
	
	if (c == 'a')
	{
		x_offset += ((float)size / 500) *0.1;
	}
	if (c == ',')
	{
		scal -= ((float)size / 500) *0.1f;
	}

	if (c == '.')
	{
		scal += ((float)size / 500) *0.1f;
	}
	if (c == '1')
	{
		size = 200;
		newLife();
	}

	if (c == '2')
	{
		size = 200;
		newLife();
	}
	if (c == '3')
	{
		size = 300;
		newLife();
	}
	if (c == '4')
	{
		size = 400;
		newLife();
	}
	if (c == '5')
	{
		size = 500;
		newLife();
	}
	if (c == '6')
	{
		size = 600;
		newLife();
	}
	if (c == '7')
	{
		size = 700;
		newLife();
	}
	if (c == '8')
	{
		size = 800;
		newLife();
	}
	if (c == '9')
	{
		size = 900;
		newLife();
	}
	if (c == '!')
	{
		size = 1000;
		newLife();
	}
	if (c == '@')
	{
		size = 2000;
		newLife();
	}
	if (c == '#')
	{
		size = 3000;
		newLife();
	}
	if (c == '$')
	{
		size = 4000;
		newLife();
	}
	if (c == '%')
	{
		size = 5000;
		newLife();
	}

	switch (c)
	{
		case'r':
		{
				   newLife();
		}
	}
}



void render()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	float y_t = 0.0f;
	float x_t = 0.0f;
	float off = 500 / (float)size *0.01f;

	//glScalef(1.0f+scal, 1.0f+scal, 1.0f+scal);
	glTranslatef(-5.0f + x_offset, -5.0f + y_offset, -9.0f+scal);
	//glTranslatef(-0.5f, -0.5f, 0.0f);
	//glColor3f(0.827f, 0.733f, 0.482f);
	glColor3f((169.0f/255.0f), (234.0f/255.0f), (123.0f/255.0f));
	glBegin(GL_QUADS);
	for (int i = 0; i < size; i++)
	{
		x_t = 0.0f;
		for (int j = 0; j < size; j++)
		{
			if (life->getLifeform(j + 1, i + 1) == 1)
			{
				glVertex2f(x_t - off, y_t + off);
				glVertex2f(x_t + off, y_t + off);
				glVertex2d(x_t + off, y_t - off);
				glVertex2d(x_t - off, y_t - off);
			}

			x_t += (500/(float)size) * 0.02f;
		}
		y_t += (500 / (float)size) *0.02f;
	}
	glEnd();
	glPopMatrix();
	life->update();
	
}

void DrawRectangle(float width, float height)
{
	const float w = width / 2.0f;
	const float h = height / 2.0f;

	glBegin(GL_QUADS);
	glVertex2f(-w, h);   // Top-Left
	glVertex2f(w, h);   // Top-Right
	glVertex2f(w, -h);   // Bottom-Right
	glVertex2f(-w, -h);   // Bottom-Left
	glEnd();

}

void ReshapeGL(int w, int h)
{
	//std::cout << "ReshapGL( " << w << ", " << h << " );" << std::endl;

	if (h == 0)										// Prevent A Divide By Zero error
	{
		h = 1;										// Making Height Equal One
	}

	window_width = w;
	window_height = h;

	glViewport(0, 0, window_width, window_height);

	// Setup the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLdouble)window_width / (GLdouble)window_height, 0.1, 100.0);

	//render();
	glutPostRedisplay();
}
