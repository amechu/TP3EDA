#include "Floor.h"



Floor::Floor(int row_, int col_, const char * pathCleanBitmap, const char * pathDirtyBitmap, float unit_)
{
	this->row = row_;
	this->col = col_;
	this->tiles =  new bool[row_ * col_];
	this->unit = unit_;
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

	float finalWidth = al_get_display_width(al_get_current_display()) / (float)this->col;
	float finalHeight = al_get_display_height(al_get_current_display()) / (float)this->row;

	for (int i = 0; i < this->col; ++i)
	{
		if ((i * finalWidth <= x) && ((i + 1)* finalWidth > x))
			xTile = i;
	}

	for (int i = 0; i < this->row; ++i)
	{
		if ((i * finalHeight <= y) && ((i + 1)* finalHeight > y))
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
		if ((i * this->unit < x) && ((i + 1)* this->unit >x))
			xTile = i;
	}

	for (int i = 0; i < this->row; ++i)
	{
		if ((i * this->unit < y) && ((i + 1)* this->unit > y))
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
	float finalWidth = al_get_display_width(al_get_current_display()) / (float)this->col;
	float finalHeight = al_get_display_height(al_get_current_display()) / (float)this->row;

	float currentWidth = al_get_bitmap_width(this->cleanBitmap);
	float currentHeight = al_get_bitmap_height(this->cleanBitmap);

	for (int i = 0; (i < this->row); ++i)
		for (int a = 0; (a < this->col); ++a)
			if (this->tiles[i * this->col + a])
				al_draw_scaled_bitmap(this->cleanBitmap, 0, 0, currentWidth, currentHeight, a * finalWidth, i * finalHeight, finalWidth, finalHeight, 0);
			else
				al_draw_scaled_bitmap(this->dirtyBitmap, 0, 0, currentWidth, currentHeight, a * finalWidth, i * finalHeight, finalWidth, finalHeight, 0);
}

int Floor::getColNumber()
{
	return this->col;
}

int Floor::getRowNumber()
{
	return this->row;
}
