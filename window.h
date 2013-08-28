#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace mysdl
{
	class window
	{
		public:
			window();
			window(const window & w);
			window& operator=(const window & w);
			virtual ~window();

			void		pause();
			SDL_Surface*	getScreen();
		private:
			SDL_Surface*	screen;
	};
};

#endif
