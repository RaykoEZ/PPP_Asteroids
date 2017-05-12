#include <iostream>
#include "CollisionFunctions.h"

///\file CollisionFunctions.cpp

bool collisionCheck(const Vec4 _objPos, const Vec4 _objPos1, const float _objSize, const float _objSize1)
{
    float size=_objSize*0.5f;
    float size1=_objSize1*0.5f;
    //checking boundaries from the centre coordinate
    if(_objPos.m_x+size<_objPos1.m_x ||
       _objPos.m_x>_objPos1.m_x+size1 ||
       _objPos.m_y+size<_objPos1.m_y ||
       _objPos.m_y>_objPos1.m_y+size1)
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void collisionManage(int &_spawnLimit,Ship &io_player, std::vector<std::unique_ptr<Asteroids> > &io_asteroids, std::vector<std::unique_ptr<Projectile> > &io_bullets, int &o_collAudio, int &o_levelAudio)
{
    //Player-to-asteroid collision check
    for(int i=0;i<io_asteroids.size();++i)
    {
        //Calls collision check for each asteroid bound with player bound
        if(collisionCheck(io_player.m_position,io_asteroids[i]->m_position,
                          io_player.getSize(),io_asteroids[i]->getSize()))
        {
            //lose score when you get hit by a asteroid
            io_player.gainScore(_spawnLimit,-io_asteroids[i]->getSize(),o_levelAudio);
            //deflect asteroids when getting hit
            io_asteroids[i]->rotateMe(true,180.0f);
            io_asteroids[i]->move(io_asteroids[i]->m_velocity);
            o_collAudio=0;
            return;

        }
    }
    //Bullet-to-asteroid collision check
    if(io_bullets.size()>0 && io_asteroids.size()>0)
    {
        //check each existing bullets with current asteroids
        for(int i=0;i<io_bullets.size();++i)
        {
            for(int j=0;j<io_asteroids.size();++j)
            {
                if(collisionCheck(io_bullets[i]->m_position,io_asteroids[j]->m_position,
                                  io_bullets[i]->getSize()*5.5f,io_asteroids[j]->getSize()*2.0f))
                {
                    io_bullets.erase(io_bullets.begin()+i);
                    if(io_asteroids[j]->getSize()<=1.25f)
                    {
                        io_asteroids.erase(io_asteroids.begin()+j);
                        o_collAudio=1;
                        return;
                    }
                    io_asteroids.push_back(std::unique_ptr<Asteroids>(new Asteroids(*io_asteroids[j].get())));
                    //std::cout<<"AsteroidList Size after split: "<<_asteroids.size()<<'\n';
                    io_asteroids.push_back(std::unique_ptr<Asteroids>(new Asteroids(*io_asteroids[io_asteroids.size()-1].get())));
                    io_asteroids.erase(io_asteroids.begin()+j);
                    io_player.gainScore(_spawnLimit,io_asteroids[j]->m_velocity,o_levelAudio);
                    o_collAudio=1;
                    return;

                }
            }
        }
    }
    o_collAudio=-1;
    return;
}
