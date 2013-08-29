#ifndef __SCENES_H__
#define __SCENES_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

namespace invader
{

	class window;
	class intro;
	class game;

	class scene
	{
		public:
			scene();
			~scene();

			int	init_scene();
			int	run();
		private:
			window*	w;
			intro*	i;
			game*	g;
	};
};

#endif
