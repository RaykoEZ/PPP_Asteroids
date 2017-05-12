#ifndef SOUNDTRIGGERS_H
#define SOUNDTRIGGERS_H
#include "Audio.h"
#include "SoundFX.h"

///\file SoundTriggers.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n

/// \class SoundTriggers
/// \brief Class for storing audio cues
/// \todo None yet

class SoundTriggers
{
public:
    ///\brief default ctor
    SoundTriggers():
        ///brief all initialize to -1 to enumerate "null"
        m_collisionSound(-1),
        m_levelSound(-1){;}

    ///\brief default dtor
    ~SoundTriggers(){;}

    ///\brief trigger for collision type audio que
    int m_collisionSound;

    ///\brief trigger for player level based audio que
    int m_levelSound;

    ///\brief for reseting audio cues
    /// @param[out] o_trigger - reset audio trigger to default state
    void resetTrigger(int &o_trigger);

    ///\brief for playing audio according to the values of the sound cues
    /// @param[in] _levelUp - audio for level up
    /// @param[in] _levelDown - audio for level down
    /// @param[in] _hit - audio for hitting
    /// @param[in] _getHit audio for getting hit
    void trigger(SoundFX &_levelUp, SoundFX &_levelDown,SoundFX &_hit, SoundFX &_getHit);
};

#endif // SOUNDTRIGGERS_H
