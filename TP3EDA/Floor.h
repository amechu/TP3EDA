#pragma once
#include <stdlib.h>
#include <allegro5\allegro.h>

class Floor
{
public:
	// Constructor de la clase
	Floor( int row_,  int col_, const char * pathCleanBitmap, const char * pathDirtyBitmap, float unit_);
	// Destructor de la clase
	~Floor();
	// Limpia todo el piso ( lo setea en 'true' )
	void cleanAll();
	// Ensucia todo el piso ( lo setea en 'false' )
	void litterAll();
	// Limpia una baldosa individua segun la coordenada que le ingresa por parametro
	void cleanTile(float x, float y);
	// Ensucia una baldosa individua segun la coordenada que le ingresa por parametro
	void litterTile(float x, float y);
	// Verifica si todo el piso esta limpio, de ser verdadero devuelve 'true'
	bool isItClean();
	// Dibuja en pantalla el piso
	void draw();
	// Devuelve el numero de columnas que tiene el piso
	int getColNumber();
	// Devuelve el numero de filas que tiene el piso
	int getRowNumber();

private:
	int row;
	int col;
	bool * tiles;
	float unit;
	ALLEGRO_BITMAP * cleanBitmap;
	ALLEGRO_BITMAP * dirtyBitmap;
};

