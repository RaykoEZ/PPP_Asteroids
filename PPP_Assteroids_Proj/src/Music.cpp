#include <iostream>
#include "Music.h"

///\file Music.cpp

Music::~Music()
{
    // free memory for music
    Mix_FreeMusic( m_music );
}
//-------------------------------------------

bool Music::loadMusic(const char *_fileDir)
{
    //try to load music, if fails, get error
    m_music=Mix_LoadMUS(_fileDir);
    if(m_music==NULL)
    {
        std::cout<<"Failing to load music file: "<<SDL_GetError()<<'\n';
        return false;
    }
    return true;
}

//-------------------------------------------


bool Music::playMusic(const int _loops)const
{
    //Plays music through SDL_mixer if the music is properly loaded
    if(m_music!=NULL)
    {
        Mix_PlayMusic(m_music,_loops);
        return true;
    }
    return false;
}
