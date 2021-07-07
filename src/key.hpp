#ifndef KEY_HPP
#define KEY_HPP

#include <SDL2/SDL.h>
#include <algorithm>

#include "entity.hpp"
#include "game_vars.hpp"
#include "texture.hpp"
#include "aabb.hpp"
#include "player.hpp"

class Key : public Entity{
    public:
        Key(int x, int y, Texture *entityTextures, Player *player);
        ~Key();
        void render(SDL_Renderer *renderer);
        void update();
        void onTrigger(AABB *playerCollider);
    private:
        Texture *entityTextures;
        AABB *collider;
        Player *player;
};

#endif