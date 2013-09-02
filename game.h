#ifndef __GAME_H__
#define __GAME_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

namespace invader
{
	class surface;
	class window;
	class ship;
	class ennemy;
	class timer;
	class missile;

	class game
	{
		public:
			game();
			~game();

			int	blitGame(window* w, int anim);
			int	run_game(window* w);
			int	init_missile();
			int	init_ship();
			int	init_ennemy();
			int	init_background();
			int	init_game();
		private:
			surface*	surf;
			ship*		s;
			ennemy*		e;
			timer*		t;
			missile*	m;
	};
};

#endif
