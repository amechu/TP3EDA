#pragma once
#include <stdlib.h>
#include <allegro5\allegro.h>

#define UNIT (10)
class Floor
{
public:
	Floor( int row_,  int col_);
	~Floor();
	void cleanAll();
	void litterAll();
	void cleanTile(float x, float y);
	void litterTile(float x, float y);
	bool isItClean();
	void draw();
	int getColNumbre();
	int getRowNumber();

private:
	int row;
	int col;
	bool * tiles;
	ALLEGRO_BITMAP * cleanBitmap;
	ALLEGRO_BITMAP * dirtyBitmap;
};

