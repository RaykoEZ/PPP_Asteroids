#include <iostream>
#include "Ship.h"

///\file Ship.cpp

void Ship::gainScore(int &io_spawnLimit, const float _score, int &o_audio)
{
    //increment score
    m_score+=_score;
    //check for level ups
    if(m_score>=m_scoreReq)
    {

        glClearColor(rng(0.35f,0.7f),rng(0.35f,0.7f),rng(0.35f,0.7f),1.0f);
        ++m_level;
        m_score=0;
        m_scoreReq+=m_scoreReq;
        ++io_spawnLimit;
        //set sudio cue to play level up sound
        o_audio=1;
        return;
    }

    //check for level downs and lowest level possible
    else if(m_score<0.0f)
    {
        if(io_spawnLimit>1)
        {
            io_spawnLimit--;
        }
        //least spawn limit is one asteroid
        if(io_spawnLimit<=1)
        {
            io_spawnLimit=1;
        }
        //level down if possible
        if(m_level>0)
        {
            --m_level;
            m_scoreReq=m_scoreReq*0.5f;
            glClearColor(0.0f,0.0f,0.0f,1.0f);
            //set audio cue to play level down sound
            o_audio=0;
            return;
        }
        //set score to : (previous level's maximum) - (leftover score deduction)
        m_score=m_scoreReq+m_score;

    }
    o_audio=-1;
    return;
}
//---------------------------------------------------------------------------------------

void Ship::spdCap()
{
    //check for whther the current speed against speed limit
    if(m_velocity>=m_spdCap)
    {
        m_velocity=m_spdCap;
    }
    else if(m_velocity<0.0f)
    {
        m_velocity=0.0f;
    }
}
//---------------------------------------------------------------------------------------

void Ship::accelerate()
{
    //accumulate acceleration/momentum when speeding up
    m_velocity+=0.01f;
    m_momentum+=0.05f;
    spdCap();
}

//---------------------------------------------------------------------------------------

void Ship::decelerate()
{
    //decrease momentum us ship is stopping
    m_velocity-=0.005f;
    spdCap();
}


//---------------------------------------------------------------------------------------

void Ship::slide()
{
    //make position vector changes when stopping to create sliding effect
    if(m_momentum>0.0f)
    {
        move(m_momentum);
        m_momentum-=0.01f;
    }
    if(m_momentum>m_momentumCap)
    {
        m_momentum=m_momentumCap;
    }
    if(m_momentum<0.0f)
    {
        m_momentum=0.0f;
    }
}
