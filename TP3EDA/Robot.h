#pragma once
#include <allegro5\allegro.h>
#include <math.h>
#include <stdlib.h>

#define M_PI (3.14159265358979323846264338327950288)

class Robot
{
public:
	// Constructor de la clase, hace todo menos cargar el bitmap por la forma en que se reserva la memoria
	Robot();
	// Destructor de la clase, destruye a todos los robots creados
	~Robot();
	// Devuelve la possicion sobre el eje X
	float getXPos();
	// Devuelve la posicion sobre el eje Y
	float getYPos();
	// Cuando es llamada acutaliza la direccion del robot
	void updateDirection();
	// Esta funcion actualiza la posicion del robot cada vez que es llamada
	void update(float unit);
	// Esta funcion hace retroceder al robot a su posicion anterior en caso de que se pase del limite (esta condicion es verificada por simulacion)
	void correctPosition(float unit);
	// Esta funcion dibuja al robot
	void draw();
	// Esta funcion carga la imagen al bitmap. Es necesaria para poder dibujar!
	bool loadBitmap(const char * pathBitmap);

private:
	float x;
	float y;
	float angle;
	ALLEGRO_BITMAP * bitmap;
};

