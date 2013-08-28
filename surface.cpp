#include "surface.h"
#include "window.h"

namespace mysdl
{

int	surface::loadImage(std::string filename)
{
	this->img = new(std::nothrow) img_p;
	if (this->img == nullptr)
		return -1;
	this->img->surf = IMG_Load(filename.c_str());
	return 0;
}

void	surface::setClip(int x, int y, int w, int h)
{
	this->img->clip.x = static_cast<Sint16>(x);
	this->img->clip.y = static_cast<Sint16>(y);
	this->img->clip.w = static_cast<Uint16>(w);
	this->img->clip.h = static_cast<Uint16>(h);
}

void	surface::setPos(int x, int y)
{
	this->pos.x = static_cast<Sint16>(x);
	this->pos.y = static_cast<Sint16>(y);
}

int	surface::loadText(std::string msg, int size, int red, int green, int blue, int alpha)
{
	SDL_Color	color;

	this->text = new text_p;
	if (this->text == nullptr)
		return -1;
	color = {static_cast<Uint8>(red), static_cast<Uint8>(green), static_cast<Uint8>(blue), static_cast<Uint8>(alpha)};
	this->text->police = TTF_OpenFont("graphics/sixty.ttf", size);
	if (this->text->police == nullptr)
		return -1;
	this->text->surf = TTF_RenderText_Solid(this->text->police, msg.c_str(), color);
	return 0;
}

int	surface::loadRGB(int w, int h, int d, int red, int green, int blue, int alpha)
{
	this->img = new(std::nothrow) img_p;
	if (this->img == nullptr)
		return -1;
	this->img->surf = SDL_CreateRGBSurface(SDL_HWSURFACE, w, h, d, red, green, blue, alpha);
	if (this->img == nullptr)
		return -1;
	return 0;
}

int	surface::blitImage(window* w)
{
	if (SDL_BlitSurface(this->img->surf, &this->img->clip, w->getScreen(), &this->pos) == -1)
		return -1;
	return 0;
}

int	surface::blitText(window* w)
{
	if (SDL_BlitSurface(this->text->surf, nullptr, w->getScreen(), &this->pos) == -1)
		return -1;
	return 0;
}

int	surface::blitRGB(window* w)
{
	if (SDL_BlitSurface(this->img->surf, nullptr, w->getScreen(), &this->pos) == -1)
		return -1;
	return 0;
}

surface::surface()
{
}

surface::surface(const surface & s)
{
	(void) s;
}

surface&	surface::operator=(const surface &)
{
	return (*this);
}

surface::~surface()
{
}

};
