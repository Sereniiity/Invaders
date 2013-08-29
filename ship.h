#ifndef __SHIP_H__
#define __SHIP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace invader
{
	class surface;

	class ship
	{
		public:
			ship();
			~ship();

			int	init_ship();
		private:
			surface*	surf;
	};
};

#endif
