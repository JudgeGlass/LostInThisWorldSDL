#include "world.hpp"

World::World(SDL_Renderer *renderer){
    std::string cwd = SDL_GetBasePath();

    levelTextures = new Texture(cwd + "res/atlas.png", 16, 16);
    levelTextures->load(renderer);
    entityTextures = new Texture(cwd + "res/entityAtlas.png", 8, 8);
    entityTextures->load(renderer);
    fontTextures = new Texture(cwd + "res/fontAtlas.png", 8, 8);
    fontTextures->load(renderer);

    player = new Player(entityTextures);
    hud = new HUD(fontTextures, entityTextures);
    t = new AABB(player->collider->getX(), player->collider->getY(), 34, 32, 254);

    for(int x = 0; x < 50; x++){
        for(int y = 0; y < 42; y++){
            uint8_t id = data[x + y * 50];
            if(id != 2)
                tileColliders.push_back(AABB(x*32, y*32, 32, 32, 0));
        }
    }

    for(int i = 0; i < 16; i++){
        entities.push_back(std::make_unique<Key>((i * 16)+100, (i * 16)+100, entityTextures, player));
        entities.push_back(std::make_unique<Map>((i * 32)+200, (i * 32)+100, entityTextures, player));
    }

    entities.push_back(std::make_unique<Key>(100, 100, entityTextures, player));
}

void World::render(SDL_Renderer *renderer){
    for(int x = 0; x < 50; x++){
        for(int y = 0; y < 42; y++){
            switch (data[x + y * 50])
            {
            case 0:
                levelTextures->render(renderer, 1, (x*32) + worldXOffset, (y*32) + worldYOffset, 2, 16);
                break;
            case 1:
                levelTextures->render(renderer, 2, (x*32) + worldXOffset, (y*32) + worldYOffset, 2, 16);
                break;
            case 2:
                levelTextures->render(renderer, 0, (x*32) + worldXOffset, (y*32) + worldYOffset, 2, 16);
                break;
            case 4:
                levelTextures->render(renderer, 3, (x*32) + worldXOffset, (y*32) + worldYOffset, 2, 16);
                break;
            case 3:
                levelTextures->render(renderer, 252, (x*32) + worldXOffset, (y*32) + worldYOffset, 2, 16);
                break;
            default:
                levelTextures->render(renderer, 44, (x*32) + worldXOffset, (y*32) + worldYOffset, 2, 16);
                break;
            }
        }
    }

    for(AABB &collider: tileColliders){
        collider.updatePos(worldXOffset, worldYOffset);
        //collider.render(renderer);
    }

    player->render(renderer);
    t->render(renderer);
    hud->render(renderer);
}

void World::update(){
    hud->update();
    player->update(worldXOffset, worldYOffset);

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_A]){
        dir = LEFT;
        if(!hitWall()){
            worldXOffset += 4;
        }
    }

    if(keystate[SDL_SCANCODE_D]){
        dir = RIGHT;
        if(!hitWall()){
            worldXOffset -= 4;
        }
    }

    if(keystate[SDL_SCANCODE_W]){
        dir = UP;
        if(!hitWall()){
            worldYOffset += 4;
        }
    }

    if(keystate[SDL_SCANCODE_S]){
        dir = DOWN;
        if(!hitWall()){
            worldYOffset -= 4;
        }
    }

    
}

bool World::hitWall(){
    // Makes AABB collider that is 4px away from the player on all sides and sees if it hits a wall.
    switch (dir)
    {
    case RIGHT:
        t = new AABB(player->collider->getX(), player->collider->getY(), 34, 32, 254);
        break;
    case LEFT:
        t = new AABB(player->collider->getX()-4, player->collider->getY(), 32, 32, 254);
        break;
    case UP:
        t = new AABB(player->collider->getX(), player->collider->getY()-4, 32, 32, 254);
        break;
    case DOWN:
        t = new AABB(player->collider->getX(), player->collider->getY(), 32, 34, 254);
        break;
    
    default:
        break;
    }

    for(AABB &tc: tileColliders){
        if(player->checkCollision(tc, *t)){
            return player->checkCollision(tc, *t);
        }
        
    }

    return false;
}

World::~World(){
    delete t;
    delete entityTextures;
    delete levelTextures;
    delete fontTextures;
    delete hud;
    delete player;
}