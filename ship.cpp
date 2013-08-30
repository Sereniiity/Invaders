#include "ship.h"
#include "surface.h"
#include "window.h"

namespace invader
{

void	ship::udapte(int move)
{
	switch (move)
	{
		case 1:
			if (this->pos[0] < 760)
				this->pos[0] = this->pos[0] + 5;
				this->surf->setPos(this->pos[0], this->pos[1]);
			break;
		case 2:
			if (this->pos[0] >= 5)
				this->pos[0] = this->pos[0] - 5;
				this->surf->setPos(this->pos[0], this->pos[1]);
			break;
		default:break;
	}
}

int	ship::blit_ship(window* w)
{
	if (this->surf->blitImage(w) == -1)
		return -1;

	return 0;
}

int	ship::init_ship()
{
	this->surf = new (std::nothrow) surface;
	if (this->surf == nullptr)
		return -1;
	this->pos = new (std::nothrow) int[2];
	if (this->pos == nullptr)
		return -1;

	if (this->surf->loadImage("graphics/ship.png") == -1)
		return -1;
	this->surf->SetColorKey(0, 0, 0);
	this->surf->setPos(380, 500);
	this->surf->setClip(102, 51, 40, 24);
	this->life = 1;
	this->pos[0] = 380;
	this->pos[1] = 500;

	return 0;
}

ship::ship()
{
}

ship::~ship()
{
}

};
