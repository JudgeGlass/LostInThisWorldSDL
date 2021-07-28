#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "aabb.hpp"
#include "animatedtile.hpp"
#include "game_vars.hpp"

class Player{
    public:
        Player(Texture *entityTextures);
        ~Player();
        void setPos(int x, int y);
        void render(SDL_Renderer *renderer);
        void update(int xoff, int yoff);
        bool checkCollision(AABB &b1, AABB &b2);

        int xOffset = 0;
        int yOffset = 0;

        AABB *collider;
    private:
        void drawDarkness(SDL_Renderer *renderer);

        Texture *entityTextures;
        AnimatedTile *animatedTile;
        int sprites[2] {36, 36+32};
        int x;
        int y;
        
};


#endif