#ifndef COLLISIONFUNCTIONS_H
#define COLLISIONFUNCTIONS_H
#include <iostream>
#include <vector>
#include <memory>
#include "Vec4.h"
#include "GameObjects.h"
#include "Ship.h"
#include "Asteroids.h"
#include "Projectile.h"

///\file CollisionFunctions.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n

///\brief For bound box collision checking between two objects
/// @param[in] _objPos - position vector of first object
/// @param[in] _objPos1 - position vector of second object
/// @param[in] _objSize - size of bound box for first object
/// @param[in] _objSize1 - size of bound box for second object
bool collisionCheck(const Vec4 _objPos, const Vec4 _objPos1,const float _objSize, const float _objSize1);

///\brief handles collision between bullets, player and asteroids on the scene
/// @param[in] _spawnLimit - a number to limit how many asteroids can be generated, it is modified as player hits/gets hit by asteroids.
/// @param[in/out] io_player - the player's objectfor checking collision
/// @param[in/out] io_asteroids - a vector of pointers to Asteroids objects for checking their collisions
/// @param[in/out] io_bullets - a vector of pointers to Projectiles objects for checking their collisions
/// @param[out] o_collAudio - return value signals collision audio
/// @param[out] o_levelAudio - return value signals audio output when leveling up/down
void collisionManage(int &_spawnLimit,Ship &io_player,std::vector<std::unique_ptr<Asteroids>> &io_Asteroids, std::vector<std::unique_ptr<Projectile>> &io_Bullets, int &o_collAudio, int &o_levelAudio);




#endif // COLLISIONFUNCTIONS_H

