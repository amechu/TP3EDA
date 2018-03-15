#include "Simulation.h"




Simulation::Simulation(int ammountRobots_, int row_, int col_, char * pathDirtyBitmap, char * pathCleanBitmap, char * pathRobotBitmap)
{
	this->ground = new Floor(row_, col_, pathCleanBitmap, pathDirtyBitmap);
	this->bots = new Robot[ammountRobots_];
	this->ticks = 0;
	this->ammountBots = ammountRobots_;
	this->ground->litterAll();

	bool load = true;

	for (int i = 0; (i < ammountRobots_) && (load); ++i)	// Hay que ver como salgo de aca. El constructor no puede devolver datos creo
		if (!this->bots[i].loadBitmap(pathRobotBitmap))
			load = false;
}


Simulation::~Simulation()
{
	delete[] this->bots;
	delete this->ground;
}

int Simulation::run()
{
	
	while (!this->ground->isItClean())
	{
		this->cycle();
		this->ticks++;
	}
	return this->ticks;
}

void Simulation::cycle()
{
	for (int i = 0; i < this->ammountBots; ++i)
	{
		this->ground->cleanTile(this->bots[i].getXPos(), this->bots[i].getYPos());
		this->bots[i].update();

		if (this->checkCrash(i))
			this->bots[i].correctPosition();
	}
}

void Simulation::draw()
{
	this->ground->draw();
	for (int i = 0; i < this->ammountBots; ++i)
		this->bots[i].draw();
	
}

bool Simulation::checkCrash(int robotNumber)
{
	bool crash = false;

	if ((this->bots[robotNumber].getXPos() <= 0) || this->bots[robotNumber].getXPos() >= (this->ground->getRowNumber() * UNIT))
		crash = true;
	if ((this->bots[robotNumber].getYPos() <= 0) || this->bots[robotNumber].getXPos() >= (this->ground->getColNumber() * UNIT))
		crash = true;

	return crash;
}
