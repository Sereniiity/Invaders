#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

namespace mysdl
{
	class system
	{
		public:
			system();
			system(const system & sy);
			system& operator=(const system & sy);
			virtual ~system();
	};
};

#endif
