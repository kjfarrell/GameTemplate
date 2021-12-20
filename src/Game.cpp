#include "Game.hpp"  
	
Game::Game(SDL_Rect position, const std::string title)
{

    SDL_Init(SDL_INIT_VIDEO);

    m_window = SDL_CreateWindow(
        title.c_str(),
        position.x,
        position.y,
        position.w,
        position.h,
        0
    );
    if(!m_window) 
        throw std::runtime_error("Could not create window");
    std::cout << "Window created" << std::endl;

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if(!m_renderer) 
        throw std::runtime_error("Could not create renderer");
    std::cout << "Renderer created" << std::endl;


    m_player->setPosition({0, 0, 32, 32});
    m_other->setPosition({5*32, 64, 32, 32});

    

	
}
	
Game::~Game()
{
    SDL_DestroyRenderer(m_renderer);
    std::cout << "Renderer destroyed" << std::endl;
    SDL_DestroyWindow(m_window);
    std::cout << "Window destroyed" << std::endl;
    SDL_Quit();
    std::cout << "SDL quit" << std::endl;
}

void Game::run()
{
    m_running = true;
    int i = 0;

    int fps=60;
    int desiredDelta = 1000/fps; 
    while(m_running)
    {
        Uint64 start = SDL_GetTicks();
        processEvents();
        clearScreen();

        level.update(m_renderer);


        m_player->update(m_renderer);   
        m_player->move({0, 1});
        if(m_player->hasCollided(m_other.get()))
        {
            m_player->move({0, -1});
        }

        for(auto &e : level.getEntities())
        {
            if(m_player->hasCollided(e.get()))
            {
                m_player->move({0, -1});
            }
        }

        m_other->update(m_renderer);
        draw();
        SDL_RenderPresent(m_renderer);

        Uint64 delta = SDL_GetTicks() - start;
        if(delta < desiredDelta)
        {
            SDL_Delay(desiredDelta - delta);
        }

    }
}

void Game::processEvents()
{
    SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                m_running = false;
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        m_running = false;
                        break;
                }
            }
        }

}

void Game::clearScreen()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);
}

void Game::draw()
{

    SDL_RenderPresent(m_renderer);
}