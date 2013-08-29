#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace invader
{
	class window
	{
		public:
			window();
			~window();

			SDL_Surface*	getScreen();
		private:
			SDL_Surface*	screen;
	};
};

#endif
