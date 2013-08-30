#include "ennemy.h"
#include "window.h"
#include "surface.h"

namespace invader
{

void	ennemy::udapte()
{
	this->pos[0] = this->pos[0] + 40;
	this->surf[0].setPos(this->pos[0], this->pos[1]);
	this->surf[1].setPos(this->pos[0], this->pos[1]);
}

int	ennemy::blit_ennemy(window* w)
{
	if (this->surf[0].blitImage(w) == -1)
		return -1;

	return 0;
}

int	ennemy::init_ennemy(int count)
{
	int	line = count / 10;
	int	col = count % 10;

	this->surf = new (std::nothrow) surface[2];
	if (this->surf == nullptr)
		return -1;
	this->pos = new (std::nothrow) int[2];
	if (this->pos == nullptr)
		return -1;

	if (this->surf[0].loadImage("graphics/invaders.png") == -1)
		return -1;
	if (this->surf[1].loadImage("graphics/invaders.png") == -1)
		return -1;
	this->surf[0].SetColorKey(0, 0, 0);
	this->surf[1].SetColorKey(0, 0, 0);

	if (count < 20)
	{
		this->surf[0].setPos(150 + (col * 50), 100 + (line * 40));
		this->surf[1].setPos(150 + (col * 50), 100 + (line * 40));
		this->surf[0].setClip(253, 9, 40, 30);
		this->surf[1].setClip(292, 9, 40, 30);
	}
	else if (count >= 20 && count < 40)
	{
		this->surf[0].setPos(150 + (col * 50), 100 + (line * 40));
		this->surf[1].setPos(150 + (col * 50), 100 + (line * 40));
		this->surf[0].setClip(166, 9, 40, 30);
		this->surf[1].setClip(212, 9, 40, 30);
	}
	else if (count >= 40 && count < 60)
	{
		this->surf[0].setPos(150 + (col * 50), 100 + (line * 40));
		this->surf[1].setPos(150 + (col * 50), 100 + (line * 40));
		this->surf[0].setClip(68, 9, 40, 30);
		this->surf[1].setClip(118, 9, 40, 30);
	}
	this->pos[0] = 150 + (col * 10);
	this->pos[1] = 100 + (line * 10);

	return 0;
}

ennemy::ennemy()
{
}

ennemy::~ennemy()
{
}

};
