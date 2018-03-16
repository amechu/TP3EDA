#pragma once
#include <stdlib.h>
#include <allegro5\allegro.h>

class Floor
{
public:
	Floor( int row_,  int col_, const char * pathCleanBitmap, const char * pathDirtyBitmap, float unit_);
	~Floor();
	void cleanAll();
	void litterAll();
	void cleanTile(float x, float y);
	void litterTile(float x, float y);
	bool isItClean();
	void draw();
	int getColNumber();
	int getRowNumber();

private:
	int row;
	int col;
	bool * tiles;
	float unit;
	ALLEGRO_BITMAP * cleanBitmap;
	ALLEGRO_BITMAP * dirtyBitmap;
};

