#ifndef LEVEL_H
#define LEVEL_H
#pragma once

#include <SDL.h>
#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include "Entity.hpp"

#define LEVEL_WIDTH 20
#define LEVEL_HEIGHT 15
	
class Level  
{
public:
	Level();
	~Level();

	void update(SDL_Renderer *renderer);
	auto getLevel() { return m_level; }
	auto getEntities() { return m_entities; }


private:
	std::array<std::array<int, LEVEL_WIDTH>, LEVEL_HEIGHT> m_level;
	std::vector<std::shared_ptr<Entity>> m_entities;

	
	
};
#endif