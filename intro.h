#ifndef __INTRO_H__
#define __INTRO_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

#include "surface.h"
#include "timer.h"

namespace invader
{
	class surface;
	class timer;

	class intro
	{
		public:
			intro();
			~intro();

			int	init_intro();
			int	init_tab_surf();
			void	init_pos_surf();
			void	init_clip_surf();
			int	run_intro(window* w);
		private:
			surface*	tab_surf;
			timer*		t;
	
	};
};

#endif
