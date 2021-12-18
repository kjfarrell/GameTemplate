#ifndef ENTITY_H
#define ENTITY_H
#pragma once

#include <iostream>
#include <SDL.h>
	
class Entity
{
public:
	Entity(SDL_Rect position = {0});
	~Entity();

	void update(SDL_Renderer *renderer);
	void setPosition(SDL_Rect position);
	void move(SDL_Point position);
	bool hasCollided(Entity *other);

private:
	SDL_Rect m_position = {0};
	SDL_Point m_previousPosition = {0};

};

#endif