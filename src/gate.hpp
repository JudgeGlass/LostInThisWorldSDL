#ifndef GATE_HPP
#define GATE_HPP

#include "entity.hpp"
#include "texture.hpp"

class Gate : public Entity{
    public:
        Gate(int x, int y, Texture *entityTextures);
        void render(SDL_Renderer *renderer);
        void update();
        void onTrigger(AABB *playerCollider);
    private:
        Texture *entityTextures;
};



#endif