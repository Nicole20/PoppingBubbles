// PoppingBubbles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<glut.h>
#include<freeglut.h>
#include<ctime>
#include "bubble.h"

using namespace std;

void initialize();
void draw();
void Timer(int value);
void TimerLevel(int value);
void mouse(int button, int state, int x, int y);

bubble bubbles;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Popping Bubbles");

	initialize();

	glutDisplayFunc(draw);
	glutMouseFunc(mouse);
	glutTimerFunc(0, TimerLevel, 0);
	glutTimerFunc(0, Timer, 0);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 10, 0, 10);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < bubbles.bubbles.size(); i++)
	{
		switch (bubbles.bubbles[i].count)
		{
		case(0) :
		{
			glColor3f(1, 1, 1);
			break;
		}
		case(1) :
		{
			glColor3f(1, 0, 1);
			break;
		}
		case(2) :
		{
			glColor3f(0, 0, 1);
			break;
		}
		case(3) :
		{
			glColor3f(0, 1, 0);
			break;
		}
		case(4) :
		{
			glColor3f(1, 1, 0);
			break;
		}
		case(5) :
		{
			glColor3f(1, 0.5, 0);
			break;
		}
		case(6) :
		{
			glColor3f(1, 0, 0);
			break;
		}
		default:
			break;
		}
		glBegin(GL_QUADS);
		glVertex2i(bubbles.bubbles[i].x, bubbles.bubbles[i].y);
		glVertex2i(bubbles.bubbles[i].x + 1, bubbles.bubbles[i].y);
		glVertex2i(bubbles.bubbles[i].x + 1, bubbles.bubbles[i].y + 1);
		glVertex2i(bubbles.bubbles[i].x, bubbles.bubbles[i].y + 1);
		glEnd();
	}

	glutPostRedisplay();
	glFlush();
}

void Timer(int value)
{
	bubbles.add();
	glutPostRedisplay();
	glutTimerFunc(1000 - (bubbles.num*100), Timer, 0);
}

void TimerLevel(int value)
{
	if (bubbles.num != 8)
	{
		bubbles.num++;
		glutTimerFunc(10000, TimerLevel, 0);
	}
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			int xx, yy;
			xx = x / 50;
			yy = 9 - y / 50;
			if (bubbles.bubbles[(xx*10) + yy].count != 0)
			{
				bubbles.bubbles[(xx * 10) + yy].count--;
				glutPostRedisplay();
			}
		}
	}
}
