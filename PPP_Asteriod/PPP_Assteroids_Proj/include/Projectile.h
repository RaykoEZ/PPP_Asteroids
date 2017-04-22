#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "GameObjects.h"
#include <iostream>
class Projectile : public GameObjects
{
public:
    Projectile():
        m_range(100.0f){;}

    Projectile(Vec4 _dir,Vec4 _pos):
               GameObjects(2,bulletType,_dir,_pos),
               m_range(100.0f){;}

    ~Projectile()
    {
        std::cout<<'\n'<<"Bullet out of range.";
    }

    void setRange(float _range);
    float getRange()const;
private:
    float m_range;
};
#endif // PROJECTILE_H
