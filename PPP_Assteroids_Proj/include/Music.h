#ifndef MUSIC_H
#define MUSIC_H
#include "Audio.h"

///\file Music.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n

/// \class Music
/// \brief Class for storing a certain music
/// \todo None yet.

class Music : public Audio
{
public:
    ///\brief memory for music track
    Mix_Music *m_music=NULL;

    //dtor
    ~Music();

    ///\brief ctor, set audio type to MUSIC
    Music():
        Audio(MUSIC){;}

    ///\brief for loading music
    /// @param[in] _fileDir - directory of the file
    bool loadMusic(const char *_fileDir);

    ///\brief for playing music
    /// @param[in] _loops - numbers of repeats, -1 is continuous
    bool playMusic(const int _loops)const;
};

#endif // MUSIC_H
