#include "game.h"
#include "surface.h"
#include "ship.h"
#include "ennemy.h"
#include "timer.h"
#include "missile.h"

namespace invader
{

int	game::blitGame(window* w, int anim)
{
	int	count = 0;

	if (this->surf->blitImage(w) == -1)
		return -1;
	if (this->s->blit_ship(w) == -1)
		return -1;
	while (count != 60)
	{
		if (this->e[count].blit_ennemy(w, anim) == -1)
			return -1;
		count++;
	}

	return 0;
}

int	game::run_game(window* w)
{
	int		keepgoing = 1;
	int		count = 0;
	int		direction = 0;
	int		anim = 0;
	int		time;
	SDL_Event	ev;

	if (this->blitGame(w, anim) == -1)
		return -1;

	SDL_Flip(w->getScreen());

	SDL_EnableKeyRepeat(5, 5);
	this->t->start();
	time = this->t->get_ticks() + 1000;
	while (keepgoing)
	{
		count = 0;
		if (SDL_PollEvent(&ev))
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
		}
		if (time < this->t->get_ticks())
		{
			if (anim == 0)
				anim = 1;
			else if (anim == 1)
				anim = 0;
			direction = this->e[9].check_direction(direction);
			while (count != 60)
			{
				this->e[count].udapte(direction);
				count++;
			}
			time = this->t->get_ticks() + 1000;
		}
		if (this->blitGame(w, anim) == -1)
			return -1;
		SDL_Flip(w->getScreen());
	}
	this->t->stop();
	return 0;
}

int	game::init_missile()
{
	this->m = new (std::nothrow) missile;
	if (this->m == nullptr)
		return -1;

	if (this->m->init_missile() == -1)
		return -1;

	return 0;
}

int	game::init_ennemy()
{
	int	count = 0;

	this->e = new (std::nothrow) ennemy[60];
	if (this->e == nullptr)
		return -1;

	while (count != 60)
	{
		if (this->e[count].init_ennemy(count) == -1)
			return -1;
		count++;
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
	if (this->init_ennemy() == -1)
		return -1;
	if (this->init_missile() == -1)
		return -1;
	this->t = new (std::nothrow) timer;
	if (this->t == nullptr)
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
