#include "texture.hpp"

Texture::Texture(std::string filename, int pw, int ph){
    this->filename = filename;
    this->pw = pw;
    this->ph = ph;
}

void Texture::load(SDL_Renderer *renderer){
    SDL_Texture *texture = IMG_LoadTexture(renderer, filename.c_str());
    if(texture == nullptr){
        std::cerr << "Error loading texture: " << filename << std::endl;
    }

    std::cout << "Loaded: " << filename << std::endl;
    this->texture = texture;

    int h, w;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
}

void Texture::render(SDL_Renderer *renderer, int index, int x, int y){
    int sx = (index % 32) * 8;
    int sy = (index / 32) * 8;

    std::cout << "X: " << sx << "\tY: " << sy << std::endl;

    SDL_Rect spriteTile;
    spriteTile.x = sx;
    spriteTile.y = sy;
    spriteTile.w = pw;
    spriteTile.h = ph;

    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = pw*2;
    dst.h = ph*2;


    SDL_RenderCopy(renderer, texture, &spriteTile, &dst);
}