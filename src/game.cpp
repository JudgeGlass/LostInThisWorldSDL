#include "game.hpp"

Game::Game(int width, int height, std::string &title){
    this->width = width;
    this->height = height;
    this->title = title;
    quit = false;
}

void Game::init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "Error: Could not setup video Game:10\n" << "Details: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if(!window){
        std::cerr << "Error: Could not setup window Game:17\n" << "Details: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr){
        std::cerr << "Error: Could not setup renderer Game:23\n" << "Details: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    world = new World(renderer);
}

void Game::loop(){
    while(!quit){
        
        world->update();
        handleEvents();
        render();
    }
}

void Game::handleEvents(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE){
            quit = true;
        }
    }
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    world->render(renderer);
    SDL_RenderPresent(renderer);
}

Game::~Game(){
    delete world;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}