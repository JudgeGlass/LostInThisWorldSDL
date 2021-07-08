#ifndef MAP_HPP
#define MAP_HPP

#include "game_vars.hpp"
#include "entity.hpp"
#include "aabb.hpp"
#include "texture.hpp"
#include "player.hpp"

class Map : public Entity{
    public:
        Map(int x, int y, Texture *entityTextures, Player *player);
        ~Map();
        void render(SDL_Renderer *renderer);
        void update();
        void onTrigger(AABB *playerCollider);
    private:
        Texture *entityTextures;
        AABB *collider;
        Player *player;
};


#endif