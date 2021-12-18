#include <SDL.h>
#include "Game.hpp"

int main(int argc, char *argv[]) try
{
	Game game(SDL_Rect{0, 0, 640, 480}, "Hello World");

	game.run();

	return 0;
}
catch (const std::exception &e)
{
	std::cerr << e.what() << std::endl;
	return 1;
}