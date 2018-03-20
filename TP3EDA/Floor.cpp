#include "Floor.h"



Floor::Floor(int row_, int col_, const char * pathCleanBitmap, const char * pathDirtyBitmap, double unitX_, double unitY_)
{
	this->row = row_;
	this->col = col_;
	this->tiles =  new bool[row_ * col_];
	this->unitX = unitX_;
	this->unitY = unitY_;
	this->cleanBitmap = al_load_bitmap(pathCleanBitmap);  // Hay que ponerlo lindo
	this->dirtyBitmap = al_load_bitmap(pathDirtyBitmap);  // Hay que ponerlo lindo
}


Floor::~Floor()
{
	 delete[] this->tiles;
	al_destroy_bitmap(this->cleanBitmap);
	al_destroy_bitmap(this->dirtyBitmap);
}

void Floor::cleanAll()
{
	for (int i = 0; i < this->row; ++i)
		for (int a = 0; a < this->col; ++a)
			this->tiles[i* this->col + a] = true;
}

void Floor::litterAll()
{
	for (int i = 0; i < this->row; ++i)
		for (int a = 0; a < this->col; ++a)
			this->tiles[i* this->col+ a] = false;
}

void Floor::cleanTile(float x, float y)
{
	int xTile = -1,yTile = -1;

	for (int i = 0; i < this->col; ++i)
	{
		if ((i * this->unitX <= x) && ((i + 1)* this->unitX > x))
			xTile = i;
	}

	for (int i = 0; i < this->row; ++i)
	{
		if ((i * this->unitY <= y) && ((i + 1)* this->unitY > y))
			yTile = i;
	}

	if (xTile >= 0 && yTile >= 0)
		this->tiles[yTile * this->col + xTile] = true;
}

void Floor::litterTile(float x, float y)
{
	int xTile = -1, yTile = -1;
	for (int i = 0; i < this->col; ++i)
	{
		if ((i * this->unitX < x) && ((i + 1)* this->unitX >x))
			xTile = i;
	}

	for (int i = 0; i < this->row; ++i)
	{
		if ((i * this->unitY < y) && ((i + 1)* this->unitY > y))
			yTile = i;
	}

	if (xTile > 0 && yTile > 0)
		this->tiles[yTile * this->col + xTile] = false;
}

bool Floor::isItClean()
{
	bool retValue = true;

	for (int i = 0; (i < this->row) && retValue; ++i)
		for (int a = 0; (a < this->col) && retValue; ++a)
			if (!this->tiles[i * this->col + a])
				retValue = false;
	return retValue;
}



void Floor::draw()
{

	float currentWidth = al_get_bitmap_width(this->cleanBitmap);
	float currentHeight = al_get_bitmap_height(this->cleanBitmap);

	for (int i = 0; (i < this->row); ++i)
		for (int a = 0; (a < this->col); ++a)
			if (this->tiles[i * this->col + a])
				al_draw_scaled_bitmap(this->cleanBitmap, 0, 0, currentWidth, currentHeight, a * this->unitX, i * this->unitY, this->unitX, this->unitY, 0);
			else
				al_draw_scaled_bitmap(this->dirtyBitmap, 0, 0, currentWidth, currentHeight, a * this->unitX, i * this->unitY, this->unitX, this->unitY, 0);
}

double Floor::getWidth()
{
	return this->col * this->unitX;
}

double Floor::getHeight()
{
	return this->row * this->unitY;
}
