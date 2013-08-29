#ifndef __SCENES_H__
#define __SCENES_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <iostream>

namespace invader
{

	class window;
	class intro;

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
	};
};

#endif
