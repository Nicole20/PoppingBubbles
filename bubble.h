#pragma once
#include<iostream>
#include<vector>
#include<glut.h>
#include<freeglut.h>
#include<ctime>

using namespace std;

class bubble
{
public:
	bubble();

	struct coords
	{
		int x;
		int y;
		int count;
	}coord;

	vector <coords> bubbles;
	int num;

	void add();

	~bubble();
};
