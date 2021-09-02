#include "sound.hpp"

Sound::Sound(const std::string &cwd){
    music = NULL;
    soundEffect = NULL;
    this->cwd = cwd;
}

bool Sound::init(){
    return !(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1);
}

void Sound::playSound(const std::string &filename){
    Mix_FreeChunk(soundEffect);
    soundEffect = Mix_LoadWAV((cwd + filename).c_str());
    if(soundEffect == NULL){
        std::cerr << "COULD NOT LOAD WAV FILE: " << filename << std::endl;
        return;
    }

    Mix_PlayChannel(-1, soundEffect, 0);
}

void Sound::playMusic(const std::string &filename){
    Mix_FreeMusic(music);
    music = Mix_LoadMUS((cwd + filename).c_str());
    if(music == NULL){
        std::cerr << "COULD NOT LOAD WAV FILE: " << filename << std::endl;
        return;
    }

    std::cout << "Loaded: " << cwd << "/" << filename << std::endl;

    Mix_PlayMusic(music, 0);
}

void Sound::stopMusic(){
    Mix_HaltMusic();
}

Sound::~Sound(){
    Mix_CloseAudio();
    Mix_Quit();
}