#include "system.h"

namespace mysdl
{

system::system()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
}

system::system(const system & sy)
{
	(void)sy;
}

system&	system::operator=(const system &)
{
	return (*this);
}

system::~system()
{
	TTF_Quit();
	SDL_Quit();
}

};
