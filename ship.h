#ifndef __SHIP_H__
#define __SHIP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace invader
{
	class surface;
	class window;

	class ship
	{
		public:
			ship();
			~ship();

			int	init_ship();
			int	blit_ship(window* w);
			void	udapte(int move);
		private:
			surface*	surf;
			int		life;
			int		speedmove;
			int		speedshot;
			int*		pos;
	};
};

#endif
