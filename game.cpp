#include "game.h"
#include "surface.h"
#include "ship.h"

namespace invader
{

int	game::run_game(window* w)
{
	int		keepgoing = 1;
	SDL_Event	ev;

	if (this->surf->blitImage(w) == -1)
		return -1;

	SDL_Flip(w->getScreen());

	while (keepgoing)
	{
		if (SDL_WaitEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
					keepgoing = 0;
					break;
				default:break;
			}
		}
		SDL_Flip(w->getScreen());
	}
	return 0;
}

int	game::init_ship()
{
	this->s = new (std::nothrow) ship;
	if (this->s == nullptr)
		return -1;

	if (this->s->init_ship() == -1)
		return -1;

	return 0;
}

int	game::init_background()
{
	this->surf = new (std::nothrow) surface;
	if (this->surf == nullptr)
		return -1;

	if (this->surf->loadImage("graphics/background.png") == -1)
		return -1;
	this->surf->setPos(0, 0);
	this->surf->setClip(0, 0, 800, 600);

	return 0;
}

int	game::init_game()
{
	if (this->init_background() == -1)
		return -1;
	if (this->init_ship() == -1)
		return -1;

	return 0;
}

game::game()
{
}

game::~game()
{
}

};
