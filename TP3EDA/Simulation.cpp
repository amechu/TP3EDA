#include "Simulation.h"




Simulation::Simulation(int ammountRobots_, int row_, int col_, const char * pathDirtyBitmap, const char * pathCleanBitmap, const char * pathRobotBitmap, double displayW, double displayH)
{
	float unitW = displayW / (float)col_;
	float unitH = displayH / (float)row_;

	this->unit = (unitH > unitW ? unitW : unitH);

	this->ground = new Floor(row_, col_, pathCleanBitmap, pathDirtyBitmap,unitW, unitH);
	this->ground->litterAll();

	this->bots = new Robot[ammountRobots_];

	this->ticks = 0;
	this->ammountBots = ammountRobots_;
	 

	bool load = true;

	for (int i = 0; (i < ammountRobots_) && (load); ++i)	// Hay que ver como salgo de aca. El constructor no puede devolver datos creo
		if (!this->bots[i].loadExternalInfo(pathRobotBitmap, this->unit /2.0,displayH, displayW ))
			load = false;
}


Simulation::~Simulation()
{
	delete[] this->bots;
	delete this->ground;
}

int Simulation::run()
{
	
	while (!this->cycle())
	{
		this->ticks++;
	}
	return this->ticks;
}

bool Simulation::cycle()
{
	for (int i = 0; i < this->ammountBots; ++i)
	{
		this->ground->cleanTile(this->bots[i].getXPos(), this->bots[i].getYPos());
		this->bots[i].update(this->unit);

		if (this->checkCrash(i))
			this->bots[i].correctPosition(this->unit);

	}
	return this->ground->isItClean();
}

void Simulation::draw()
{
	this->ground->draw();
	for (int i = 0; i < this->ammountBots; ++i)
		this->bots[i].draw();
	al_flip_display();
}

bool Simulation::checkCrash(int robotNumber)
{
	bool crash = false;

	float minX = this->bots[robotNumber].getRadius();
	float minY = this->bots[robotNumber].getRadius();
	float maxX = this->ground->getWidth() - this->bots[robotNumber].getRadius();
	float maxY = this->ground->getHeight()- this->bots[robotNumber].getRadius();

	float actualX = this->bots[robotNumber].getXPos();
	float actualY = this->bots[robotNumber].getYPos();

	if (!((actualX >= minX) && (actualX <= maxX)))
		crash = true;
	if (!((actualY >= minY) && actualY <= maxY))
		crash = true;


	return crash;
}
