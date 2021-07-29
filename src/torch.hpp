#ifndef TORCH_HPP
#define TORCH_HPP

#include "texture.hpp"
#include "aabb.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "animatedtile.hpp"

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
        AnimatedTile *fireTile;
        AABB *collider;
        Player *player;
        bool torchLit;
        int fireTextureIndex[2] {36, 36+32};
};


#endif