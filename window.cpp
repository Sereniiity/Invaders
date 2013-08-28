#include "window.h"

namespace mysdl
{

window::window()
{
	this->screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
	SDL_Flip(screen);
}

window::window(const window & w)
{
	(void) w;
}

window&	window::operator=(const window &)
{
	return (*this);
}

window::~window()
{
}

SDL_Surface*	window::getScreen()
{
	return this->screen;
}

};
