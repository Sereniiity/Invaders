#include "scene.h"

int	main(int, char**)
{
	invader::scene*	scene;

	scene = new (std::nothrow) invader::scene;
	if (scene == nullptr)
		return -1;
	if (scene->init_scene() == -1)
		return -1;
	if (scene->run() == -1)
		return -1;
	return 0;
}
