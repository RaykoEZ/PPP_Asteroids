#ifndef SHIP_H
#define SHIP_H
#include "GameObjects.h"



class Ship : public GameObjects
{
public:

    Ship():
        m_fireRate(1){;}

    ~Ship(){;}
    //NOTE: SDL_MOUSEMOTION y position = -z position in this created space

    void followMouse(float &_xMouse, float &_yMouse);
private:
    int m_fireRate;



};

#endif // SHIP_H
