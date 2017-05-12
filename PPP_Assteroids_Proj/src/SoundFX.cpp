#include "SoundFX.h"

///\file SoundFX.cpp

SoundFX::~SoundFX()
{
    //free memory for sound tracks
    Mix_FreeChunk( m_sound );
}
//--------------------------------------------------

bool SoundFX::loadSound(const char *_fileDir)
{
    //load sound, if fails, get error
    m_sound=Mix_LoadWAV(_fileDir);
    if(m_sound==NULL)
    {
        std::cout<<"Failing to load sound file: "<<SDL_GetError()<<'\n';
        return false;
    }
    return true;
}


//--------------------------------------------------

bool SoundFX::playSound(const int _loops) const
{
    //play sound if sound is loaded properly
    if(m_sound!=NULL)
    {
        Mix_PlayChannel(-1,m_sound,_loops);
        return true;
    }
    return false;
}
