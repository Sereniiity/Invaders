#ifndef __MISSILE_H__
#define __MISSILE_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace invader
{
	class surface;
	class window;

	class missile
	{
		public:
			missile();
			~missile();

			int	init_missile();
		private:
			surface*	surf;
			int		speedmove;
			int*		pos;
	};
};

#endif
