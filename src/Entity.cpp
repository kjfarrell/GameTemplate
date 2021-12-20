#include "Entity.hpp"  
	
Entity::Entity(SDL_Rect position)
    : m_position(position)
{
    std::cout << "Entity created" << std::endl;

}
	
Entity::~Entity()
{
    std::cout << "Entity destroyed" << std::endl;
}

void Entity::setPosition(SDL_Rect position)
{
    m_previousPosition.x = m_position.x;
    m_previousPosition.y = m_position.y;

    m_position = position;
}


void Entity::update(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &m_position);
}

void Entity::move(SDL_Point position)
{
    m_previousPosition.x = m_position.x;
    m_previousPosition.y = m_position.y;

    m_position.x += position.x;
    m_position.y += position.y;
}

bool Entity::hasCollided(Entity *other)
{
    return (m_position.x < other->m_position.x + other->m_position.w &&
            m_position.x + m_position.w > other->m_position.x &&
            m_position.y < other->m_position.y + other->m_position.h &&
            m_position.y + m_position.h > other->m_position.y);
}



