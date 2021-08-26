#ifndef GATE_HPP
#define GATE_HPP

#include "entity.hpp"
#include "texture.hpp"
#include "game_vars.hpp"
#include "torch.hpp"

class Gate : public Entity{
    public:
        Gate(int x, int y, Texture *entityTextures, std::vector<AABB> *colliders, std::vector<Torch> torches);
        void render(SDL_Renderer *renderer);
        void update();
        void onTrigger(AABB *playerCollider);
    private:
        Texture *entityTextures;
        AABB *collider;
        std::vector<Torch> torches;
};



#endif