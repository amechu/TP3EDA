#pragma once
#include "Robot.h"
#include "Floor.h"
#include <allegro5\allegro_color.h>

class Simulation
{
public:
	// Es el constructor de la sumulacion, le pasamos la cantidad de robots, de filas y de columnas, ademas de las imagenes para el piso sucio, limpio y de los robots.
	Simulation(int ammountRobots_, int row_, int col_, const char * pathDirtyBitmap, const char * pathCleanBitmap, const char * pathRobotBitmap, double displayW, double displayH);
	// Es el destructor, cuando termina de usarse la clase mata a todos los bitmaps y la memoria reservada dinamicamente
	~Simulation();
	// Este seria el modo 2. ejecuta la simulacion y devuelve la cantidad de ticks sin imprimir nada en pantalla.
	int run();
	// Esto ejecuta un unico ciclo de la simulacion y nos sirve para el modo 1, donde no esta bueno mezclar lo que se dibuja y lo que corre en el backend.
	// En el main voy a explicar como funciona
	bool cycle();
	// Esta funcion dibuja el piso y los robots
	void draw();
	// Esta funcion verifica si choca un robot contra la pared
	bool checkCrash(int robotNumber);

private:
	Robot * bots;
	int ticks;
	Floor * ground;
	int ammountBots;
	float unit;
};

