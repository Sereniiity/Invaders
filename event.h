#ifndef __EVENT_H__
#define __EVENT_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "window.h"

namespace mysdl
{
	class event
	{
		public:
			event();
			event(const event & e);
			event& operator=(const event & e);
			virtual ~event();

			void	check_event(window* w);
	};
};

#endif
