#pragma once
#include "Robot.h"
#include "Floor.h"

class Simulation
{
public:
	Simulation(int ammountRobots_, int row_, int col_);
	~Simulation();
	int run();
	void cycle();
	void draw();

private:
	Robot * bots;
	int ticks;
	Floor * ground;
	int ammountBots;
};

