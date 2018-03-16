#include "Simulation.h"




Simulation::Simulation(int ammountRobots_, int row_, int col_, const char * pathDirtyBitmap, const char * pathCleanBitmap, const char * pathRobotBitmap)
{
	
	this->bots = new Robot[ammountRobots_];
	this->ticks = 0;
	this->ammountBots = ammountRobots_;
	

	float unitW = al_get_display_width(al_get_current_display())/(float)col_;
	float unitH = al_get_display_height(al_get_current_display()) / (float)row_;

	this->unit = (unitH > unitW ? unitW : unitH);

	this->ground = new Floor(row_, col_, pathCleanBitmap, pathDirtyBitmap,this->unit);
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

	if ((this->bots[robotNumber].getXPos() <= 0) || this->bots[robotNumber].getXPos() >= (this->ground->getRowNumber() * this->unit))
		crash = true;
	if ((this->bots[robotNumber].getYPos() <= 0) || this->bots[robotNumber].getXPos() >= (this->ground->getColNumber() * this->unit))
		crash = true;

	return crash;
}
