#pragma once
#include <allegro5\allegro.h>
#include <math.h>
#include <stdlib.h>

#define M_PI (3.14159265358979323846264338327950288)
#define UNIT 10

class Robot
{
public:
	Robot();
	~Robot();
	float getXPos();
	float getYPos();
	void updateAngle();
	void update();
	void draw();
private:
	float x;
	float y;
	float angle;
	ALLEGRO_BITMAP * bitmap;
};

