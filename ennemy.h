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
			int	blit_ennemy(window* w, int anim);
			void	udapte(int);
			int	check_direction(int direction);
		private:
			surface*	surf;
			int		life;
			int		speedmove;
			int		speedshot;
			int*		pos;
			int		old_dir;
	};
};

#endif
