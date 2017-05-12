#include <iostream>
#include "SoundTriggers.h"

///\file SoundTriggers.cpp

void SoundTriggers::resetTrigger(int &o_trigger)
{
    //reset audio cue to default
    o_trigger=-1;
}

//-----------------------------------------------------------------------------------------------------

void SoundTriggers::trigger(SoundFX &_levelUp, SoundFX &_levelDown, SoundFX &_hit, SoundFX &_getHit)
{
    //plays audio (once) according to audio cues
    if(m_levelSound==0)
    {
       _levelDown.playSound(0);
       resetTrigger(m_levelSound);
    }
    else if(m_levelSound>0)
    {
       _levelUp.playSound(0);
       resetTrigger(m_levelSound);
    }
    else if(m_collisionSound==0)
    {
       _getHit.playSound(0);
       resetTrigger(m_collisionSound);
    }
    else if(m_collisionSound>0)
    {
       _hit.playSound(0);
       resetTrigger(m_collisionSound);
    }

}
