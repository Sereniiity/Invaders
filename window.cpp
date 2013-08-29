#include "window.h"

namespace invader
{

void	window::resetScreen()
{
	this->screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
	SDL_Flip(screen);
}

window::window()
{
	this->screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Space Invaders", nullptr);
	SDL_Flip(screen);
}

window::~window()
{
}

SDL_Surface*	window::getScreen()
{
	return this->screen;
}

};
