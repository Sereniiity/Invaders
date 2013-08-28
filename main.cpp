#include "system.h"
#include "window.h"
#include "surface.h"
#include "event.h"

int	main(int, char**)
{
	mysdl::system*	sy;
	mysdl::window*	w;
	mysdl::event*	e;
	mysdl::surface*	surface1;
	mysdl::surface*	surface2;
	mysdl::surface*	surface3;

	sy = new (std::nothrow) mysdl::system;
	if (sy == nullptr)
		return -1;
	w = new (std::nothrow) mysdl::window;
	if (w == nullptr)
		return -1;
	e = new (std::nothrow) mysdl::event;
	if (e == nullptr)
		return -1;

	surface1 = new (std::nothrow) mysdl::surface;
	if (surface1 == nullptr)
		return -1;
	surface2 = new (std::nothrow) mysdl::surface;
	if (surface2 == nullptr)
		return -1;
	surface3 = new (std::nothrow) mysdl::surface;
	if (surface3 == nullptr)
		return -1;

//Image
	if (surface1->loadImage("graphics/arcade-sona.png") == -1)
		return -1;
	surface1->setClip(0, 0, 700, 460);
	surface1->setPos(0, 0);
	if (surface1->blitImage(w) == -1)
		return -1;

//Text
	if (surface2->loadText("Coucou", 50, 0, 0, 0, 42) == -1)
		return -1;
	surface2->setPos(400, 300);
	if (surface2->blitText(w) == -1)
		return -1;

//RGB
	if (surface3->loadRGB(100, 100, 32, 0, 0, 0, 42) == -1)
		return -1;
	surface3->setPos(200, 150);
	if (surface3->blitRGB(w) == -1)
		return -1;

//Event
	e->check_event(w);

	return 0;
}
