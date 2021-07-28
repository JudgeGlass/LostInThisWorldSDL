#ifndef TORCH_HPP
#define TORCH_HPP

#include "texture.hpp"
#include "aabb.hpp"
#include "entity.hpp"
#include "player.hpp"

class Torch : public Entity{
    public:
        Torch(int x, int y, Texture *entityTextures, Player *player);
        ~Torch();
        void render(SDL_Renderer *renderer);
        void update();
        void onTrigger(AABB *playerCollider);
        bool isLit();

    private:
        Texture *entityTextures;
        AABB *collider;
        Player *player;
        bool torchLit;
};


#endif