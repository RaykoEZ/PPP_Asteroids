#include "Ship.h"
#include <iostream>



void Ship::followMouse(float &_xMouse, float &_yMouse)
{
    GLfloat xDis;
    GLfloat yDis;
    GLfloat rot;
    xDis=_xMouse-m_position.m_x;
    yDis=_yMouse-m_position.m_y;


    if ((long)abs(yDis)<=std::numeric_limits<float>::epsilon())
    {
        drawMe(shipType,xDis,yDis,m_rot);
    }

    rot= atan2(yDis,xDis)*(degree());
    m_rot=rot;
    //std::cout<<"_xMouse: "<<_xMouse<<'\n'<<"_yMouse: "<<_yMouse<<'\n';
    //std::cout<<"Ship rotation: "<<rot<<'\n'<<"Mouse Distance x,y: "<<xDis<<','<<yDis<<'\n';

    drawMe(shipType,xDis,yDis,rot);

}

void Ship::gainScore(int &_spawnLimit, const float _score)
{
    m_score+=_score;
    if(m_score>=m_scoreReq)
    {
        glClearColor(rng(0.35f,0.7f),rng(0.35f,0.7f),rng(0.35f,0.7f),1.0f);
        ++m_level;
        m_score=0;
        m_scoreReq+=m_scoreReq;
        _spawnLimit+=m_level;
    }
    else if(m_score<0.0f)
    {
        _spawnLimit-=m_level;
        if(m_level>0)
        {
            --m_level;
        }
        m_scoreReq-=m_scoreReq*0.5f;
        m_score=0.0f;

    }
}

void Ship::accelerate()
{
    m_velocity+=0.01f;
    m_momentum+=0.05f;
    spdCap();
}

void Ship::decelerate()
{
    m_velocity-=0.005f;
    spdCap();
}

void Ship::spdCap()
{
    if(m_velocity>=m_spdCap)
    {
        m_velocity=m_spdCap;
    }
    else if(m_velocity<0.0f)
    {
        m_velocity=0.0f;
    }
}

void Ship::slide()
{
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
