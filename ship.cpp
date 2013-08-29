#include "ship.h"
#include "surface.h"

namespace invader
{

int	ship::init_ship()
{
	this->surf = new (std::nothrow) surface;
	if (this->surf == nullptr)
		return -1;

	if (this->surf->loadImage("graphics/invader.png") == -1)
		return -1;
	this->surf->setPos();
	this->surf->setClip();

	return 0;
}

ship::ship()
{
}

ship::~ship()
{
}

};
