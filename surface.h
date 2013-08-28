#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include "window.h"

struct	text_p
{
	SDL_Surface*	surf;
	TTF_Font*	police = nullptr;
};

struct	img_p
{
	SDL_Surface*	surf;
	SDL_Rect	clip;
};

namespace mysdl
{
	class	surface
	{
		public:
			surface();
			surface(const surface & s);
			surface& operator=(const surface & s);
			virtual ~surface();

			int	loadImage(std::string filename);
			int	loadText(std::string msg, int size, int red, int green, int blue, int alpha);
			int	loadRGB(int w, int h, int d, int red, int green, int blue, int alpha);
			void	setClip(int x, int y, int w, int h);
			void	setPos(int x, int y);
			int	blitImage(window* w);
			int	blitText(window* w);
			int	blitRGB(window* w);
		private:
			SDL_Rect	pos;
			text_p*		text;
			img_p*		img;
			
	};
};

#endif
