#ifndef SHIP_H
#define SHIP_H
#include "GameObjects.h"
#include "CalcFunctions.h"


class Ship : public GameObjects
{
public:

    Ship():
        m_level(0),
        m_spdCap(0.08f),
        m_momentum(0.0f),
        m_momentumCap(0.3f),
        m_score(0.0f),
        m_scoreReq(1.0f){;}
    ~Ship(){;}
    //NOTE: SDL_MOUSEMOTION y position = -z position in this created space

    int m_level;
    void followMouse(float &_xMouse, float &_yMouse);
    void accelerate();
    void decelerate();
    void spdCap();
    void slide();
    float getScore()const{return m_score;}
    float getScoreReq()const{return m_scoreReq;}
    void gainScore(int &_level,const float _score);
    void incScoreReq(const float _req);
private:
    float m_spdCap;
    float m_momentum;
    float m_momentumCap;
    float m_score;
    float m_scoreReq;


};

#endif // SHIP_H
