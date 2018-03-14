#include "Floor.h"



Floor::Floor(int row_, int col_)
{
	this->row = row_;
	this->col = col_;
	this->tiles = new bool[row_ * col_];
}


Floor::~Floor()
{
	delete[] this->tiles;
}

void Floor::cleanAll()
{
	for (int i = 0; i < this->row; ++i)
		for (int a = 0; a < this->col; ++a)
			this->tiles[i + a] = true;
}

void Floor::litterAll()
{
	for (int i = 0; i < this->row; ++i)
		for (int a = 0; a < this->col; ++a)
			this->tiles[i + a] = false;
}

void Floor::cleanTile(float x, float y)
{
	int xTile = -1,yTile = -1;
	for (int i = 0; i < this->col; ++i)
	{
		if ((i * UNIT < x) && ((i + 1)* UNIT > x))
			xTile = i;
	}

	for (int i = 0; i < this->row; ++i)
	{
		if ((i * UNIT < y) && ((i + 1)* UNIT > y))
			yTile = i;
	}

	if (xTile > 0 && yTile > 0)
		this->tiles[yTile * this->col + xTile] = true;
}

void Floor::litterTile(float x, float y)
{
	int xTile = -1, yTile = -1;
	for (int i = 0; i < this->col; ++i)
	{
		if ((i * UNIT < x) && ((i + 1)* UNIT > x))
			xTile = i;
	}

	for (int i = 0; i < this->row; ++i)
	{
		if ((i * UNIT < y) && ((i + 1)* UNIT > y))
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
			if (!this->tiles[i + a])
				retValue = false;
	return retValue;
}

void Floor::draw()
{
	for (int i = 0; (i < this->row); ++i)
		for (int a = 0; (a < this->col); ++a)
			if (this->tiles[i + a])
				al_draw_bitmap(this->cleanBitmap, a * UNIT, i * UNIT, 0);
			else
				al_draw_bitmap(this->dirtyBitmap, a * UNIT, i * UNIT, 0);
}

int Floor::getColNumbre()
{
	return this->col;
}

int Floor::getRowNumber()
{
	return this->row;
}
