#include "sound.hpp"

Sound::Sound(){
    music = NULL;
    soundEffect = NULL;
}

bool Sound::init(){
    return !(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1);
}

void Sound::playSound(const std::string &filename){
    Mix_FreeChunk(soundEffect);
    soundEffect = Mix_LoadWAV(filename.c_str());
    if(soundEffect == NULL){
        std::cerr << "COULD NOT LOAD WAV FILE: " << filename << std::endl;
    }

    Mix_PlayChannel(-1, soundEffect, 0);
}

void Sound::playMusic(const std::string &filename){
    Mix_FreeMusic(music);

    Mix_PlayMusic(music, 0);
}

void Sound::stopMusic(){
    Mix_HaltMusic();
}

Sound::~Sound(){
    Mix_CloseAudio();
    Mix_Quit();
}