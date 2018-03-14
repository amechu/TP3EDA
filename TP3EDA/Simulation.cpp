#include "Simulation.h"



Simulation::Simulation(int ammountRobots_, int row_, int col_)
{
	this->ground = new Floor(row_, col_);
	this->bots = new Robot[ammountRobots_]();
	this->ticks = 0;
	this->ammountBots = ammountRobots_;
	this->ground->litterAll();
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
}

void Simulation::cycle()
{
	for (int i = 0; i < this->ammountBots; ++i)
	{
		this->ground->cleanTile(this->bots[i].getXPos, this->bots[i].getYPos);
		this->bots[i].update();
	}
}

void Simulation::draw()
{
	this->ground->draw();
	for (int i = 0; i < this->ammountBots; ++i)
		this->bots[i].draw();
	
}
