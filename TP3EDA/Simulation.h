#pragma once
#include "Robot.h"
#include "Floor.h"

class Simulation
{
public:
	Simulation(int ammountRobots_, int row_, int col_, const char * pathDirtyBitmap, const char * pathCleanBitmap, const char * pathRobotBitmap);
	~Simulation();
	int run();
	bool cycle();
	void draw();
	bool checkCrash(int robotNumber);
	

private:
	Robot * bots;
	int ticks;
	Floor * ground;
	int ammountBots;
	float unit;
};

