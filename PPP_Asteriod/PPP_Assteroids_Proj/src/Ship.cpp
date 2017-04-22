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





