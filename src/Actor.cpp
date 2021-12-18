#include "Actor.hpp"  
	
Actor::Actor(SDL_Rect position)
    :Entity(position)
{
    std::cout << "Actor created" << std::endl;

}
	
Actor::~Actor()
{
    std::cout << "Actor destroyed" << std::endl;
	
}