#include <iostream>
#include "CollisionFunctions.h"

bool collisionCheck(Vec4 _objPos, Vec4 _objPos1, const float _objSize, const float _objSize1)
{
    float size=_objSize*0.5f;
    float size1=_objSize1*0.5f;

    if(_objPos.m_x+size<_objPos1.m_x ||
       _objPos.m_x>_objPos1.m_x+size1 ||
       _objPos.m_y+size<_objPos1.m_y ||
       _objPos.m_y>_objPos1.m_y+size1)
    {
        return false;
    }

    return true;
}

