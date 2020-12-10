#ifndef ANIMATEDTILE_HPP
#define ANIMATEDTILE_HPP

#include <SDL2/SDL.h>
#include "texture.hpp"

class AnimatedTile{
    public:
        AnimatedTile(int sprites[], int spriteLen, int delay, Texture *texture){
            this->sprites = new int[spriteLen];
            this->spriteLen = spriteLen;
            this->sprites = sprites;
            this->delay = delay;
            this->texture = texture;
        }

        void update(){
            std::cout << "INDEX: " << index << "\tCOUNTER: " << counter << "\tDELAY: " << delay << "\tSIZE: " << (sizeof(sprites) / sizeof(sprites[0]))<< std::endl;
            if(counter % delay == 0){
                if(index + 1 < spriteLen){
                    index++;
                }else{
                    index = 0;
                }

                counter = 0;
            }

            counter++;
        }

        void render(SDL_Renderer *renderer, int x, int y, int scale){
            texture->render(renderer, sprites[index], x, y, scale, 32);
        }
    private:
        int *sprites;
        int spriteLen = 0;
        int delay = 0;
        int index = 0;
        int counter = 0;
        Texture *texture;
};


#endif