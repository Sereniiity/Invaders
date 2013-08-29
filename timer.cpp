#include "timer.h"

namespace invader
{

bool	timer::is_paused()
{
	return this->paused;
}

bool	timer::is_started()
{
	return this->started;
}

void	timer::unpause()
{
	if (this->paused == true)
	{
		this->paused = false;
		this->startTicks = SDL_GetTicks() - this->pausedTicks;
		this->pausedTicks = 0;
	}
}

void	timer::pause()
{
	if ((this->started == true) && (this->paused == false))
	{
		this->paused = true;
		this->pausedTicks = SDL_GetTicks() - this->startTicks;
	}
}

int	timer::get_ticks()
{
	if (this->started == true)
	{
		if (this->paused == true)
		{
			return this->pausedTicks;
		}
		else
		{
			return SDL_GetTicks() - this->startTicks;
		}
	}
	return 0;
}

void	timer::stop()
{
	this->started = false;
	this->paused = false;
}

void	timer::start()
{
	this->started = true;
	this->paused = false;
	this->startTicks = SDL_GetTicks();
}

timer::timer()
{
	this->startTicks = 0;
	this->pausedTicks = 0;
	this->paused = false;
	this->started = false;
}

};
