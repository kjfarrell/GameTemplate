#ifndef ACTOR_H
#define ACTOR_H
#pragma once
	
#include <iostream>
#include <SDL.h>

#include "Entity.hpp"


class Actor : public Entity  
{
		
public:
	Actor(SDL_Rect position = {0});
	~Actor();

private:

};
#endif