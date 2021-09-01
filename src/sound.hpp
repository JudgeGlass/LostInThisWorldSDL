#ifndef SOUND_HPP
#define SOUND_HPP

#include <SDL2/SDL_mixer.h>
#include <string>
#include <iostream>

class Sound{
    public:
        Sound();
        ~Sound();
        bool init();
        void playSound(const std::string &filename);
        void playMusic(const std::string &filename);
        void stopMusic();

    private:
        Mix_Chunk *soundEffect;
        Mix_Music *music;
};



#endif