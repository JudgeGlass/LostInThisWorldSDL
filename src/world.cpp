#include "world.hpp"

World::World(SDL_Renderer *renderer){
    levelTextures = new Texture("C:\\Users\\hunte\\Documents\\SDL\\LostInThisWorld\\res\\atlas.png", 16, 16);
    levelTextures->load(renderer);

    player = new Player();
    t = new AABB(player->collider->getX(), player->collider->getY(), 34, 32, 254);

    for(int x = 0; x < 50; x++){
        for(int y = 0; y < 42; y++){
            uint8_t id = data[x + y * 50];
            if(id != 2)
                tileColliders.push_back(AABB(x*32, y*32, 32, 32, 0));
        }
    }

}

void World::render(SDL_Renderer *renderer){
    for(int x = 0; x < 50; x++){
        for(int y = 0; y < 42; y++){
            switch (data[x + y * 50])
            {
            case 0:
                levelTextures->render(renderer, 1, (x*32) + xOffset, (y*32) + yOffset, 2, 16);
                break;
            case 1:
                levelTextures->render(renderer, 2, (x*32) + xOffset, (y*32) + yOffset, 2, 16);
                break;
            case 2:
                levelTextures->render(renderer, 0, (x*32) + xOffset, (y*32) + yOffset, 2, 16);
                break;
            case 4:
                levelTextures->render(renderer, 3, (x*32) + xOffset, (y*32) + yOffset, 2, 16);
                break;
            default:
                levelTextures->render(renderer, 44, (x*32) + xOffset, (y*32) + yOffset, 2, 16);
                break;
            }
        }
    }

    for(AABB &collider: tileColliders){
        collider.updatePos(xOffset, yOffset);
        collider.render(renderer);
    }

    player->render(renderer);
    t->render(renderer);
}

void World::update(){
    player->update(xOffset, yOffset);

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_A]){
        dir = LEFT;
        if(!hitWall()){
            xOffset += 4;
        }
    }

    if(keystate[SDL_SCANCODE_D]){
        dir = RIGHT;
        if(!hitWall()){
            xOffset -= 4;
        }
    }

    if(keystate[SDL_SCANCODE_W]){
        dir = UP;
        if(!hitWall()){
            yOffset += 4;
        }
    }

    if(keystate[SDL_SCANCODE_S]){
        dir = DOWN;
        if(!hitWall()){
            yOffset -= 4;
        }
    }

    
}

bool World::hitWall(){
    
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
    delete levelTextures;
}