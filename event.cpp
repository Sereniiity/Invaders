#include "event.h"
#include "window.h"

namespace mysdl
{

event::event()
{
}

event::event(const event & e)
{
	(void) e;
}

event&	event::operator=(const event &)
{
	return (*this);
}

event::~event()
{
}

void	event::check_event(window* w)
{
	SDL_Event ev;
	int	keepgoing;

	keepgoing = 1;
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
						case SDLK_ESCAPE:
							keepgoing = 0;
							break;
						default:break;
					}
				default:break;
			}
		}
		SDL_Flip(w->getScreen());
	}
}

};
