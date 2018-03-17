#include "Robot.h"



Robot::Robot()
{
	radius = 50;

	this->x = radius + rand() % (int)(al_get_display_width(al_get_current_display()) - radius);
	this->y = radius + rand() % (int)(al_get_display_height(al_get_current_display()) - radius);
	this->updateDirection();

	radius = 50;

}


Robot::~Robot()
{
	al_destroy_bitmap(this->bitmap);
}

bool Robot::loadBitmap(const char * pathBitmap)
{
	bool retValue;

	if (this->bitmap = al_load_bitmap(pathBitmap))
		retValue = true;
	else
		retValue = false;

		return retValue;
}

float Robot::getRadius()
{
	return this->radius;
}

float Robot::getXPos()
{
	return this->x;
}

float Robot::getYPos()
{
	return this->y;
}

void Robot::updateDirection()
{
	this->angle = (rand() % 360) * M_PI / 180.0; // Dice que el angulo tiene que ser un numbero real, alguna idea?
}

void Robot::update(float unit)
{
	this->oldX = this->x;
	this->oldY = this->y;
	this->x += cos(this->angle) * unit;
	this->y += sin(this->angle) * unit;
}

void Robot::correctPosition(float unit)
{
	//this->x -= cos(this->angle) * unit;
	//this->y -= sin(this->angle) * unit;
	this->x = this->oldX;
	this->y = this->oldY;
	this->updateDirection();
}

void Robot::draw()
{
	al_draw_scaled_bitmap(this->bitmap,0, 0, al_get_bitmap_width(this->bitmap), al_get_bitmap_height(this->bitmap), this->x - this->radius, this->y - this->radius, 100.0, 100.0, 0);
}
