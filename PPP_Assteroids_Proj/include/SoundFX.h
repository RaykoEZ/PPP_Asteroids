#ifndef SOUNDFX_H
#define SOUNDFX_H
#include "Audio.h"

///\file SoundFX.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n

/// \class SoundFX
/// \brief Class for storing a certain sound effect
/// \todo None yet.

class SoundFX : public Audio
{
public:

    ///\brief memory for sound track
    Mix_Chunk *m_sound=NULL;

    ///\brief dtor
    ~SoundFX();

    ///\brief ctor, set audio type to SHORT
    SoundFX():
        Audio(SHORT){;}

    ///\brief for loading sound
    /// @param[in] _fileDir - directory of the file
    bool loadSound(const char *_fileDir);

    ///\brief for playing sound
    /// @param[in] _loops - numbers of repeats, -1 is continuous
    bool playSound(const int _loops)const;


};

#endif // SOUNDFX_H
