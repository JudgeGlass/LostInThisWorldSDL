#ifndef ANIMATEDTILE_HPP
#define ANIMATEDTILE_HPP

#include <SDL2/SDL.h>
#include "texture.hpp"

class AnimatedTile{
    public:
        AnimatedTile(int *sprites, int delay, Texture *texture){
            this->sprites = sprites;
            this->delay = delay;
            this->texture = texture;
        }

        void update(){
            if(counter % delay == 0){
                if(index + 1 < sizeof(sprites) / sizeof(int)){
                    index++;
                }else{
                    index = 0;
                }
            }

            counter++;
        }

        void render(SDL_Renderer *renderer, int x, int y, int scale){
            texture->render(renderer, sprites[index], x, y, scale, 32);
        }
    private:
        int *sprites;
        int delay;
        int index;
        int counter;
        Texture *texture;
};


#endif