#include "Robot.h"



Robot::Robot(char * pathBitmap)
{
	this->x = rand() % (al_get_display_width(al_get_current_display()));
	this->y = rand() % (al_get_display_height(al_get_current_display()));
	this->updateAngle();

	this->bitmap = al_load_bitmap(pathBitmap);  // Hay que ponerlo lindo
}


Robot::~Robot()
{
	al_destroy_bitmap(this->bitmap);
}

float Robot::getXPos()
{
	return this->x;
}

float Robot::getYPos()
{
	return this->y;
}

void Robot::updateAngle()
{
	this->angle = (rand() % 361) * M_PI / 180;
}

void Robot::update()
{
	this->x += cos(this->angle) * UNIT;
	this->y += sin(this->angle) * UNIT;
}

void Robot::correctPosition()
{
	this->x -= cos(this->angle) * UNIT;
	this->y -= sin(this->angle) * UNIT;
	this->updateAngle();
}

void Robot::draw()
{
	al_draw_bitmap(this->bitmap, this->x, this->y, 0);
}
