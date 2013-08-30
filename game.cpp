#include "game.h"
#include "surface.h"
#include "ship.h"
#include "stdlib.h"

namespace invader
{

int	game::blitGame(window* w)
{
	
	if (this->surf->blitImage(w) == -1)
		return -1;
	if (this->s->blit_ship(w) == -1)
		return -1;

	return 0;
}

int	game::run_game(window* w)
{
	int		keepgoing = 1;
	SDL_Event	ev;

	if (this->surf->blitImage(w) == -1)
		return -1;
	if (this->s->blit_ship(w) == -1)
		return -1;

	SDL_Flip(w->getScreen());

	SDL_EnableKeyRepeat(5, 5);
	while (keepgoing)
	{
		if (SDL_WaitEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
					keepgoing = 0;
					break;
				case SDL_KEYDOWN:
					switch (ev.key.keysym.sym)
					{
						;case SDLK_RIGHT:
							this->s->udapte(1);
							break;
						case SDLK_LEFT:
							this->s->udapte(2);
							break;
						default:break;
					}
					break;
				default:break;
			}
			if (this->blitGame(w) == -1)
				return -1;
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
