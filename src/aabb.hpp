#ifndef AABB_HPP
#define AABB_HPP

#include <SDL2/SDL.h>
#include <iostream>

class AABB{
    public:
        AABB(int x, int y, int width, int height, uint8_t id){
            this->x = x;
            this->y = y;
            ox = x;
            oy = y;
            this->width = width;
            this->height = height;
            this->id = id;
        }

        int getBottom() {
		    return y + height;
	    }

        int getTop() {
		    return y;
	    }

        int getLeft() {
		    return x;
	    }

        int getRight() {
		    return x + width;
	    }

        void addX(int x) {
		    this->x += x;
	    }

        void addY(int y) {
		    this->y += y;
	    }

        void updatePos(int xoff, int yoff){
            x = xoff + ox;
            y = yoff + oy;
        }

        int getX(){
            return x;
        }

        int getY(){
            return y;
        }

        void render(SDL_Renderer *renderer){
            SDL_Rect outline;
            outline.x = x;
            outline.y = y;
            outline.w = width;
            outline.h = height;

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            
            SDL_RenderDrawRect(renderer, &outline);

            //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        }
    private:
        int x;
        int y;
        int ox;
        int oy;
        int width;
        int height;
        uint8_t id;

};

#endif