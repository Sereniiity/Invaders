#ifndef __ENNEMY_H__
#define __ENNEMY_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace invader
{
	class surface;
	class window;

	class ennemy
	{
		public:
			ennemy();
			~ennemy();

			int	init_ennemy(int count);
			int	blit_ennemy(window* w);
			void	udapte();
		private:
			surface*	surf;
			int		life;
			int		speedmove;
			int		speedshot;
			int*		pos;
	};
};

#endif
