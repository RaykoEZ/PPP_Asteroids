#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "GameObjects.h"
#include <iostream>
class Projectile : public GameObjects
{
public:
    Projectile():
        m_range(25.0f){;}

    Projectile(Vec4 _dir,Vec4 _pos):
               GameObjects(1.0f,0.5f,bulletType,_dir,_pos),
               m_range(25.0f)
               {
                //std::cout<<'\n'<<"Bullet Creation"<<'\n';
               }

    ~Projectile()
    {
        //std::cout<<"Bullet destruction"<<'\n';
    }

    void setRange(float _range);
    float getRange()const;
    void shoot();
    void rangeDecay();
    bool checkDecay();
private:
    float m_range;

};
#endif // PROJECTILE_H
