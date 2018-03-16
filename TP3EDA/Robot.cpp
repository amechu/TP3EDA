#include "Robot.h"



Robot::Robot()
{
	this->x = rand() % (al_get_display_width(al_get_current_display()));
	this->y = rand() % (al_get_display_height(al_get_current_display()));
	this->updateAngle();

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
	this->angle = (rand() % 360) * M_PI / 180.0; // Dice que el angulo tiene que ser un numbero real, alguna idea?
}

void Robot::update(float unit)
{
	this->x += cos(this->angle) * unit;
	this->y += sin(this->angle) * unit;
}

void Robot::correctPosition(float unit)
{
	this->x -= cos(this->angle) * unit;
	this->y -= sin(this->angle) * unit;
	this->updateAngle();
}

void Robot::draw()
{
	al_draw_scaled_bitmap(this->bitmap,0, 0, al_get_bitmap_width(this->bitmap), al_get_bitmap_height(this->bitmap), this->x, this->y, 100.0, 100.0, 0);
}
