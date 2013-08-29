#include "intro.h"
#include "stdlib.h"

namespace invader
{

int	intro::run_intro(window* w)
{
	int		keepgoing = 1;
	SDL_Event	ev;

	if (this->tab_surf[0].blitRGB(w) == -1)
		return -1;
	if (this->tab_surf[1].blitImage(w) == -1)
		return -1;
	if (this->tab_surf[2].blitImage(w) == -1)
		return -1;

	while (keepgoing)
	{
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
						case SDLK_SPACE:
							this->t->start();
							break;
						default:break;
					}
				default:break;
			}
		}
		if (this->t->get_ticks() > 1000 && this->t->get_ticks() < 2000)
		{
			if (this->tab_surf[3].blitImage(w) == -1)
				return -1;
		}
		else if (this->t->get_ticks() > 2000 && this->t->get_ticks() < 3000)
		{
			this->tab_surf[3].setPos(365, 72);
			if (this->tab_surf[3].blitImage(w) == -1)
				return -1;
		}
		else if (this->t->get_ticks() > 3000 && this->t->get_ticks() < 4000)
		{
			this->tab_surf[3].setPos(432, 72);
			if (this->tab_surf[3].blitImage(w) == -1)
				return -1;
		}
		else if (this->t->get_ticks() > 4000)
		{
			keepgoing = 0;
		}
		SDL_Flip(w->getScreen());
	}
	this->t->stop();
	return 0;
}

void	intro::init_clip_surf()
{
	this->tab_surf[1].setClip(0, 0, 200, 74);
	this->tab_surf[2].setClip(288, 168, 278, 156);
	this->tab_surf[3].setClip(339, 4, 57, 41);
}

void	intro::init_pos_surf()
{
	this->tab_surf[0].setPos(0, 0);
	this->tab_surf[1].setPos(300, 263);
	this->tab_surf[2].setPos(261, 72);
	this->tab_surf[3].setPos(301, 72);
}

int	intro::init_tab_surf()
{
	if (this->tab_surf[0].loadRGB(800, 600, 32, 0, 0, 0, 42) == -1)
		return -1;
	if (this->tab_surf[1].loadImage("graphics/Intro1.png") == -1)
		return -1;
	if (this->tab_surf[2].loadImage("graphics/Intro2.jpg") == -1)
		return -1;
	if (this->tab_surf[3].loadImage("graphics/invader.png") == -1)
		return -1;
	return 0;
}

int	intro::init_intro()
{
	this->tab_surf = new (std::nothrow) surface[4];
	if (this->tab_surf == nullptr)
		return -1;
	this->t = new (std::nothrow) timer;
	if (this->t == nullptr)
		return -1;

	if (this->init_tab_surf() == -1)
		return -1;
	this->init_pos_surf();
	this->init_clip_surf();
	return 0;
}

intro::intro()
{
}

intro::~intro()
{
}

};
