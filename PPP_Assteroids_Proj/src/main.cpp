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
#include <vector>
#include <chrono>
#include "GameObjects.h"
#include "Ship.h"
#include "Projectile.h"
#include "Asteroids.h"
#include "Camera.h"
#include "SDLOpenGL.h"
#include "CalcFunctions.h"
#include "CollisionFunctions.h"
#include "Audio.h"
#include "Music.h"
#include "SoundFX.h"
#include "SoundTriggers.h"
#undef main

///\file main.cpp

///\brief for initializing OpenGL view matrices and colours/lighting
void initOpenGL();

///\brief for initializing SDL_mixer for audio features
void initMixer();

int main(int argc, char *argv[])
{
    //initialize screen size
    int winXLeng=720;
    int winYLeng=576;
    // create our SDLWindow
    SDLOpenGL win("PPP_Asteroids_Assignment",100,100,winXLeng,winYLeng);
    // this makes sure the window is active for OpenGL calls, if we have
    // more than one window we need to call this for the window we want to
    // set OpenGL for
    win.makeCurrent();
    // setup our default OpenGL window state
    initOpenGL();
    //instantiate our player's object
    Ship player;
    //initialiize the spawn limit for asteroids
    int spawnLimit=1;
    //setting up STL vectors for storing bullet and asteroid objects
    std::vector<std::unique_ptr<Projectile>> bulletList;
    std::vector<std::unique_ptr<Asteroids>> asteroidList;
    //initializing timers for controlling player's fire rate
    std::chrono::steady_clock::time_point current=std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point history=current;
    std::chrono::milliseconds sec;
    std::chrono::duration<float> d;
    initMixer();
    //instantiate music object for playing background music
    Music backMusic;
    //Load audio file from assets folder
    if(backMusic.loadMusic("debug/../assets/BGM2.wav")==true)
    {
        //play music if loaded corrected
        backMusic.playMusic(-1);
    }
    //Loading sound files
    SoundFX levelUp;
    levelUp.loadSound("debug/../assets/LevelUp1.wav");
    SoundFX levelDown;
    levelDown.loadSound("debug/../assets/LevelDown.wav");
    SoundFX hit;
    hit.loadSound("debug/../assets/Hit.wav");
    SoundFX getHit;
    getHit.loadSound("debug/../assets/GetHit.wav");
    //set up triggers for sound effects
    SoundTriggers triggers;

    bool quit=false;
    //start game loop
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

        default : break;
     } // end of event switch

     //handle keyboard states,  using this instead of events to allow simultaneous key_downs
     const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

     //fire bullets when space is pressed/held down
     if( currentKeyStates[ SDL_SCANCODE_SPACE ] )
     {
         //set time between the previous fire to limit fire rate
         d =(current-history);
         sec=std::chrono::duration_cast<std::chrono::milliseconds>(d);
         //std::cout<<'\n'<<"duration: "<<sec.count()<<'\n';
         if(sec.count()>200.0f)
         {
             //push newly shot bullets into the STL vector
             bulletList.push_back(std::unique_ptr<Projectile>
                                 ( new Projectile(player.m_direction,player.m_position)));
             history=current;
         }
     }
     //movement controls, calls corresponding player functions to edit pos/dir vectors
     if( currentKeyStates[ SDL_SCANCODE_UP ] )
     {
         player.accelerate();
         player.move(player.m_velocity);
     }
     //rotate ship when right or left key pressed
     if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
     {
         //false because we are NOT moving left
        player.rotateMe(false,1.0f);
     }
     if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
     {
        player.rotateMe(true,1.0f);
     }
     // start draw scene
     current=std::chrono::steady_clock::now();
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     //if there are not enough asteroids, we spawn more
     if(asteroidList.size()<spawnLimit)
     {
         //std::cout<<"SpawnLimit: "<<spawnLimit<<'\n';
         //std::cout<<"Level: "<<player.m_level<<'\n';
         asteroidList.push_back(std::unique_ptr<Asteroids>
                                (new Asteroids(Vec4(-0.8f,-0.8f,0.0f,1.0f),
                                           Vec4(0.8f,0.8f,0.0f,1.0f),
                                           Vec4(-15.5f,-15.5f,0.0f,1.0f),
                                           Vec4(-15.0f,-15.0f,0.0f,1.0f),
                                           0.1f,0.35f,
                                           0.0f,
                                           2.0f,6.0f,
                                           rng(1.0,5.0))));

     }
     //we move asteroids around
     if(asteroidList.size()>0)
     {
        for(int i=0;i<asteroidList.size();++i)
        {
            asteroidList[i]->move(asteroidList[i]->m_velocity);
            asteroidList[i]->forward(asteroidType);
        }
     }
     //we move move bullets and destroy them when they are out of range
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
     //decelerate and slide to make smoother stopping
     player.decelerate();
     player.slide();
     player.forward(player.m_shapeType);
     //checks for collisions if there are any objects to compare with
     if(bulletList.size()>0 || asteroidList.size()>0)
     {
        //check collision for each existing object
        collisionManage(spawnLimit,player,asteroidList,bulletList,
                        triggers.m_collisionSound,
                        triggers.m_levelSound);

        //trigger specific sounds corresponding to situations
        triggers.trigger(levelUp,levelDown,hit,getHit);
     }
     win.swapWindow();
    }
    //Halt all audio streams to quit mixer
    Mix_HaltChannel(-1);
    Mix_HaltMusic();
    Mix_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}

//--------------------------------------------------------------------------------

void initOpenGL()
{
  // this sets the background colour
  glClearColor(0,0,0,1.0);
  // this is how big our window is for drawing
  glViewport(0,0,720,576);
  Camera::perspective(60,float(720/576),0.01,500);
  Camera::lookAt(Vec4(0,30,0.1),Vec4(0,0,0),Vec4(0,1,0));
  //glDisable(GL_LIGHTING);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glColor3f(1,1,0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);

}
//--------------------------------------------------------------------------------

void initMixer()
{
    //initialize audio and video functions for SDL, error catch if fails
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        std::cout<<"SDL could not initialize! SDL Error: "<< SDL_GetError()<<'\n';
        return;
    }
    //open audio device for SDL_mixer, error catch if fails
    //Currently works for windows and mac, for linux, check you audio device for alsa, and check SDL_AUDIO_DEVICE environment variable
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        std::cout<< "SDL_mixer could not initialize."<< SDL_GetError()<<'\n';
        return;
    }
    return;
}

