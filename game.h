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

	class game
	{
		public:
			game();
			~game();

			int	blitGame(window* w);
			int	run_game(window* w);
			int	init_ship();
			int	init_ennemy();
			int	init_background();
			int	init_game();
		private:
			surface*	surf;
			ship*		s;
			ennemy*		e;
			timer*		t;
	};
};

#endif
