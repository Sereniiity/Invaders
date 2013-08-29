#include "scene.h"
#include "window.h"
#include "intro.h"

namespace invader
{

int	scene::run()
{
	if (this->i->init_intro() == -1)
		return -1;
	if (this->i->run_intro(this->w) == -1)
		return -1;
	return 0;
}

int	scene::init_scene()
{
	this->w = new (std::nothrow) window;
	if (this->w == nullptr)
		return -1;
	this->i = new (std::nothrow) intro;
	if (this->i == nullptr)
		return -1;
	return 0;
}

scene::scene()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
}

scene::~scene()
{
	TTF_Quit();
	SDL_Quit();
}

};
