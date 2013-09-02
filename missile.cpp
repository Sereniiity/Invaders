#include "surface.h"
#include "missile.h"
#include "window.h"

namespace invader
{

int	missile::init_missile()
{
	this->surf = new (std::nothrow) surface;
	if (this->surf == nullptr)
		return -1;
	this->pos = new (std::nothrow) int[2];
	if (this->pos == nullptr)
		return -1;

	if (this->surf->loadImage("graphics/invaders.png") == -1)
		return -1;
	this->surf->SetColorKey(0, 0, 0);
	this->surf->setClip(100, 67, 7, 17);

	return 0;
}

missile::missile()
{
}

missile::~missile()
{
}

};
