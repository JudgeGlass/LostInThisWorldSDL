#include "game.hpp"

Game::Game(int width, int height, std::string &title){
    this->width = width;
    this->height = height;
    this->title = title;
    quit = false;
}

void Game::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
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


    std::string cwd = SDL_GetBasePath();
    sound = new Sound(cwd);
    if(!sound->init()){
        std::cerr << "Error: Could not setup sound\nDetails: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_ShowCursor(SDL_DISABLE);

#if _WIN32
    levelTextures = new Texture(cwd + "res\\atlas.png", 16, 16);
    entityTextures = new Texture(cwd + "res\\entityAtlas.png", 8, 8);
    fontTextures = new Texture(cwd + "res\\fontAtlas.png", 8, 8);
#else
    levelTextures = new Texture(cwd + "res/atlas.png", 16, 16);
    entityTextures = new Texture(cwd + "res/entityAtlas.png", 8, 8);
    fontTextures = new Texture(cwd + "res/fontAtlas.png", 8, 8);
#endif

    world = new World(renderer, entityTextures, fontTextures, levelTextures);
    hud = new HUD(fontTextures, entityTextures);
}

void Game::loop(){
    while(!quit){
        int start = SDL_GetTicks();
        int startFps = SDL_GetPerformanceCounter();

        SDL_GetMouseState(&mouseX, &mouseY);

        world->update();
        hud->update();

        for(auto &entity: entities){
            entity->update();
        }

        //Removes entities that requesed to be destroyed.
        // Most likely very inefficient 
        for(auto &index: entityRemoveQueue){
            entities.erase(entities.begin() + index);
        }

        entityRemoveQueue.clear();

        handleEvents();

        render();

        int end = SDL_GetTicks();
        float elapsedMS = (end - start) / (float) SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(13.66666f - elapsedMS);
        int endFps = SDL_GetPerformanceCounter();
        fps = 1 / ((endFps - startFps) / (float)SDL_GetPerformanceFrequency());
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
    
    for(auto &entity: entities){
        entity->render(renderer);
    }

    world->player->render(renderer);
    hud->render(renderer);

    SDL_RenderPresent(renderer);
}

Game::~Game(){
    delete world;
    delete hud;
    delete sound;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}