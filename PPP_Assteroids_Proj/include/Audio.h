#ifndef AUDIO_H
#define AUDIO_H
#include <iostream>
#include "SDL_mixer.h"

///\file Audio.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n

/// \class Audio
/// \brief Class for defining a type of audio
/// \todo None yet.

class Audio
{
public:

    ///\brief enums for audio type
    typedef enum
    {
        MUSIC = 0,
        SHORT = 1
    }AudioType;

    ///\brief virtual dtor for inheritance
    virtual ~Audio(){;}
    ///\brief ctor, initialize to MUSIC unless stated otherwise
    Audio():
        m_type(MUSIC){;}

    ///\brief ctor for specific audio type
    /// @param[in] _type - specified audio type
    Audio(AudioType _type):
        m_type(_type){;}
    AudioType m_type;

};


#endif // AUDIO_H
