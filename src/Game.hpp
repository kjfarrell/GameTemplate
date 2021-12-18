#ifndef GAME_H
#define GAME_H
#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <SDL.h>

#include "Entity.hpp"
#include "Actor.hpp"
	
class Game  
{

public:
	Game(SDL_Rect position, const std::string title);
	~Game();

	void run();
	void processEvents();
	void draw();
	void clearScreen();

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	bool m_running;

	std::unique_ptr<Actor> m_player = std::make_unique<Actor>();
	std::unique_ptr<Entity> m_other = std::make_unique<Entity>();
	

};

#endif