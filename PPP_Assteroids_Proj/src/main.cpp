/// under mac __APPLE__ is defined by the compiler so we can check
/// this to get the correct includes for OpenGL
#ifdef WIN32
  #include <Windows.h>
#endif

#if defined (__linux__) || defined (WIN32)
  #include <GL/gl.h>
#endif
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#endif
#include <memory>
#include <iostream>
#include <cstdlib>
#include "GameObjects.h"
#include "Ship.h"
#include "Projectile.h"
#include "Asteroids.h"
#include "Camera.h"
#include "SDLOpenGL.h"
#include "CalcFunctions.h"
#include "CollisionFunctions.h"
#include <vector>
#include <chrono>

#undef main

// function to init the basic OpenGL scene for this demo
void initOpenGL();
// function to manage collisions on the scene
void collisionManage(int &_level,Ship &_player,std::vector<std::unique_ptr<Asteroids>> &_Asteroids, std::vector<std::unique_ptr<Projectile>> &_Bullets);


int main(int argc, char *argv[])
{


    int winXLeng=720;
    int winYLeng=576;
    //float halfX=winXLeng/2;
    //float halfY=winYLeng/2;
    // create our SDLWindow
    SDLOpenGL win("GLFunctions Demo",100,100,winXLeng,winYLeng);
    // this makes sure the window is active for OpenGL calls, if we have
    // more than one window we need to call this for the window we want to
    // set OpenGL for
    win.makeCurrent();
    // setup our default OpenGL window state
    initOpenGL();

    //initIrrKlang();
    Ship player;
    int spawnLimit=3;
    //float xMouse=0.00f;
    //float yMouse=0.00f;
    std::vector<std::unique_ptr<Projectile>> bulletList;
    std::vector<std::unique_ptr<Asteroids>> asteroidList;
    std::chrono::steady_clock::time_point current=std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point history=current;
    std::chrono::milliseconds sec;
    std::chrono::duration<float> d;

    bool quit=false;
    while(!quit)
    {

      SDL_Event event;
      // grab the event from the window (note this explicitly calls make current)
      win.pollEvent(event);
      switch (event.type)
      {
        // this is the window x being clicked.
        case SDL_QUIT : quit = true; break;
        // now we look for a keydown event
        case SDL_KEYDOWN:
        {
          switch( event.key.keysym.sym )
          {
            // if it's the escape key quit
            case SDLK_ESCAPE :
              quit = true;
              break;
            // make OpenGL draw wireframe
            case SDLK_e : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
            // make OpenGL draw solid
            case SDLK_r : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;
          } // end of key process
        } // end of keydown
        //Now we look for Mouse movements
        case SDL_MOUSEMOTION:
        {

            //xMouse=(event.motion.x);
            //yMouse=(event.motion.y);


            //std::cout<<"From SDL_MOUSEMOTION:"<<'\n'<<"Mouse at: "<<xMouse<<','<<yMouse<<'\n';
        }


        default : break;
     } // end of event switch

      //handle keyboard states
     const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
     if( currentKeyStates[ SDL_SCANCODE_SPACE ] )
     {
         d =(current-history);
         sec=std::chrono::duration_cast<std::chrono::milliseconds>(d);
         //std::cout<<'\n'<<"duration: "<<sec.count()<<'\n';
         if(sec.count()>225.0f)
         {
             bulletList.push_back(std::unique_ptr<Projectile>
                                 ( new Projectile(player.m_direction,player.m_position)));
             history=current;
             //std::cout<<'\n'<<" Shots Fyerd! "<<'\n';
         }
     }

     if( currentKeyStates[ SDL_SCANCODE_UP ] )
     {
         player.accelerate();
         player.move(player.getVelo());
     }
     if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
     {
        player.rotateMe(false,1.0f);
     }
     if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
     {
        player.rotateMe(true,1.0f);
     }
     // draw scene
     current=std::chrono::steady_clock::now();
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     //std::cout<<"bulletList size: "<<bulletList.size()<<'\n';
     if(asteroidList.size()<spawnLimit)
     {
         //std::cout<<"SpawnLimit: "<<spawnLimit<<'\n';
         //std::cout<<"Leve: "<<player.m_level<<'\n';
         asteroidList.push_back(std::unique_ptr<Asteroids>
                                (new Asteroids(Vec4(-1.0f,-1.0f,0.0f,1.0f),
                                           Vec4(0.8f,0.8f,0.0f,1.0f),
                                           Vec4(-15.5f,-15.5f,0.0f,1.0f),
                                           Vec4(-15.0f,-15.0f,0.0f,1.0f),
                                           0.1f,0.35f,
                                           0.0f,
                                           2.0f,6.0f,
                                           rng(1.0,5.0))));

     }
     //std::cout<<"AsteroidList Size: "<<asteroidList.size()<<'\n';
     if(asteroidList.size()>0)
     {
        for(int i=0;i<asteroidList.size();++i)
        {
            asteroidList[i]->move(asteroidList[i]->getVelo());
            asteroidList[i]->forward(asteroidType);
        }
     }

     if(bulletList.size()>0)
     {
         for(int i=0;i<bulletList.size();++i)
         {
            bulletList[i]->shoot();
            //std::cout<<"Bullet List Size: "<<bulletList.size()<<'\n';
            if(bulletList[i]->checkDecay())
            {
                bulletList.erase(bulletList.begin()+i);
            }
         }
     }
     player.decelerate();
     //std::cout<<"Ship Velocity: "<<player.getVelo()<<'\n';
     player.slide();
     player.forward(player.m_shapeType);
     //std::cout<<"Player Updating."<<'\n';
     // update the buffer so we can see what we have drawn.
     if(bulletList.size()>0 || asteroidList.size()>0)
     {
        collisionManage(spawnLimit,player,asteroidList,bulletList);
     }
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}

void initOpenGL()
{
  // this sets the background colour
  glClearColor(0,0,0,1.0);
  // this is how big our window is for drawing
  glViewport(0,0,720,576);
  Camera::perspective(60,float(720/576),0.01,500);
  Camera::lookAt(Vec4(0,30,0.1),Vec4(0,0,0),Vec4(0,1,0));
  glDisable(GL_LIGHTING);
  //glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  glColor3f(1,1,0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);

}



void collisionManage(int &_spawnLimit,Ship &_player, std::vector<std::unique_ptr<Asteroids> > &_asteroids, std::vector<std::unique_ptr<Projectile> > &_bullets)
{
    //Player-to-asteroid collision check
    for(int i=0;i<_asteroids.size();++i)
    {
        if(collisionCheck(_player.m_position,_asteroids[i]->m_position,
                          _player.getSize(),_asteroids[i]->getSize()))
        {

            _player.gainScore(_spawnLimit,-_asteroids[i]->getVelo());
            glClearColor(0.0f,0.0f,0.0f,1.0f);

        }
    }
    //Bullet-to-asteroid collision check
    if(_bullets.size()>0 && _asteroids.size()>0)
    {
        for(int i=0;i<_bullets.size();++i)
        {
            for(int j=0;j<_asteroids.size();++j)
            {
                if(collisionCheck(_bullets[i]->m_position,_asteroids[j]->m_position,
                                  _bullets[i]->getSize()*5.5f,_asteroids[j]->getSize()*2.0f))
                {
                    _bullets.erase(_bullets.begin()+i);
                    if(_asteroids[j]->getSize()<=1.25f)
                    {
                        _asteroids.erase(_asteroids.begin()+j);
                        return;
                    }
                    _asteroids.push_back(std::unique_ptr<Asteroids>(new Asteroids(*_asteroids[j].get())));
                    //std::cout<<"AsteroidList Size after split: "<<_asteroids.size()<<'\n';
                    _asteroids.push_back(std::unique_ptr<Asteroids>(new Asteroids(*_asteroids[_asteroids.size()-1].get())));
                    _asteroids.erase(_asteroids.begin()+j);
                    _player.gainScore(_spawnLimit,_asteroids[j]->getVelo());

                    return;

                }
            }
        }
    }

}
