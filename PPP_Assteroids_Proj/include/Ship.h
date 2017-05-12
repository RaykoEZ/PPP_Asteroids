#ifndef SHIP_H
#define SHIP_H
#include "GameObjects.h"
#include "CalcFunctions.h"

///\file Ship.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n


/// \class Ship
/// \brief Class for storing movement values and scores for the player.
/// \todo None yet.
class Ship : public GameObjects
{
public:

    ///\brief default ctor for player
    Ship():
        m_level(0),
        m_momentum(0.0f),
        m_momentumCap(0.3f),
        m_spdCap(0.08f),
        m_score(0.0f),
        m_scoreReq(1.0f){;}

    ///\brief dtor
    ~Ship(){;}

    ///\brief Stores the current level of achievement
    int m_level;

    ///\brief For accelerating ship when boost is pressed
    void accelerate();

    ///\brief For slowing down when boost is released
    void decelerate();

    ///\brief Apply sliding when stopping
    void slide();

    ///\brief Gets current score
    float getScore()const{return m_score;}

    ///\brief Gets score required to level up
    float getScoreReq()const{return m_scoreReq;}

    ///\brief Increment score
    /// @param[in/out] io_spawnLimit - current asteroid spawn limit
    /// @param[in] _score - value of increment
    /// @param[out] o_audio - return value signals audio output when leveling up/down
    void gainScore(int &io_spawnLimit,const float _score, int &o_audio);

private:

    ///\brief Momentum the ship builds when travelling
    float m_momentum;

    ///\brief Maximum momentum can be built
    float m_momentumCap;

    ///\brief current score gained
    float m_score;

    ///\brief score required to gain level (increment m_level)
    float m_scoreReq;

    ///\brief Maximum speed the object can reach
    float m_spdCap;

    ///\brief For checking for whether speed reaches terminal velocity
    void spdCap();

};

#endif // SHIP_H
