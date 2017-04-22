#include "GameObjects.h"
#include <iostream>


void GameObjects::killToggle()
{
    if(m_isDead==true)
    {
        m_isDead=false;
    }
    else
    {
        m_isDead=true;
    }
}

void GameObjects::hideToggle()
{
    if(m_isVisible==true)
    {
        m_isVisible=false;
    }
    else
    {
        m_isVisible=true;
    }
}

void GameObjects::drawMe(shape _type,float _x,float _y, float _rot )
{
  //rotate on axis
  /*
    glTranslatef(0.0f,-0.25f,0.25f); //centre
    glRotatef(5.0f,0.0f,1.0f,0.0f);
    glTranslatef(0.0f,0.25f,-0.25f);
    */
    GLfloat speed = 0.03f;

    //Vec4 distance(_x,_y,0.0f,1.0f);
    //std::cout<<"Distance from mouse: "<<distance.length()<<'\n';
    //std::cout<<"Translation Vector: "<<_x<<" , "<<_y<<'\n';

    glPushMatrix();
        glTranslatef(speed*_x,0.0f,speed*-_y);
       /* if(distance.length()>=std::numeric_limits<float>::epsilon())
        {

            //glTranslatef(0.0f,-2.5f,-2.5f); //centre
            //glRotatef(_rot/10,0.0f,1.0f,0.0f);
            //glTranslatef(0.0f,2.5f,2.5f);
            glTranslatef(speed*_x,0.0f,speed*_y);

        }
        */

        //glTranslatef(0.0f,-0.5f,-0.5f); //centre
        glRotatef(_rot,0.0f,1.0f,0.0f);
        //glTranslatef(0.0f,0.5f,0.5f);
        _type(m_size);


    glPopMatrix();
    //m_position.set(m_position.m_x+speed*_x,m_position.m_y,m_position.m_z+speed*_y,1.0f);
    //m_position.m_x+=speed*_x;
    //m_position.m_y+=speed*_y;
    //std::cout<<"m_x: "<<m_position.m_x<<" m_y: "<<m_position.m_y<<'\n';
}

void GameObjects::rotateMe(bool _left,float _rotDeg)
{
    float rotRad=_rotDeg*radian();
    float rotFDir=m_rot*radian();
     //std::cout<<"Direction Vector before: "<<m_direction.m_x<<" , "<<m_direction.m_y<<'\n';
    if((_left&&m_rot<=90.0f)||m_rot<-270.0f)
    {
        if(m_rot<-270.0f)
        {
            m_rot-=m_rotSpd*_rotDeg;
        }
        else
        {
            m_rot+=m_rotSpd*_rotDeg;
        }
        m_direction.set(-sin(rotFDir),
                        cos(rotFDir),0.0f,1.0f);
        cycle();
    }
    else if((!_left&&m_rot>=-90.0f)||m_rot>270.0f)
    {
        if(m_rot>270.0f)
        {
            m_rot+=m_rotSpd*_rotDeg;
        }
        else
        {
            m_rot-=m_rotSpd*_rotDeg;
        }
        m_direction.set(-sin(rotFDir),
                        cos(rotFDir),0.0f,1.0f);
        cycle();
    }
    else if(m_rot>90.0f||m_rot<-180.0f)
    {
        if(m_rot<-180.0f)
        {
            m_rot-=m_rotSpd*_rotDeg;
        }
        else
        {
            m_rot+=m_rotSpd*_rotDeg;
            //std::cout<<"Direction Vector after: "<<m_direction.m_x<<" , "<<m_direction.m_y<<'\n';
        }
        m_direction.set(-sin(rotFDir),
                        cos(rotFDir),0.0f,1.0f);
    }
    else if(m_rot<-90.0f||m_rot>180.0f)
    {
        if(m_rot>180.0f)
        {
            m_rot+=m_rotSpd*_rotDeg;
            m_direction.set(cos(rotFDir),
                            sin(rotFDir),0.0f,1.0f);

        }
        else
        {
            m_rot-=m_rotSpd*_rotDeg;
            m_direction.set(-sin(rotFDir),
                            cos(rotFDir),0.0f,1.0f);

        }
    }


    //std::cout<<"m_rot: "<<m_rot<<'\n';
    //change direction vector
}

void GameObjects::forward(shape _type)
{
    drawMe(_type,m_position.m_x,m_position.m_y,m_rot);
    //need normalized dirrection vector to move forward
}

void GameObjects::move(float _step)
{

    m_position.set((m_position.m_x+_step*m_direction.m_x),
                   (m_position.m_y+_step*m_direction.m_y),0.0f,1.0f);

}

void GameObjects::cycle()
{
    if(m_rot>360.0f)
    {

       m_rot-=360.0f;

    }
    else if(m_rot<-360.0f)
    {
        m_rot+=360.0f;
    }
    //std::cout<<"m_rot: "<<m_rot<<'\n';
}


void GameObjects::shoot()
{
    //std::cout<<"Shooting"<<'\n';
}
/*
 *
 * -----------------Non-class functions----------------------------
 *
*/
void shipType(const int _size)
{
    glBegin(GL_TRIANGLES);

    //draws tetrahedron - ship shape
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, -1.5f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, -1.5f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, -1.5f); //pointing forward

    glEnd();
}

void bulletType(const int _size)
{
    glBegin(GL_TRIANGLE_STRIP);

        glColor3f(1.0f,1.0f,1.0f);

        glVertex3f(0.0f,0.0f,-1.0f);
        glVertex3f(-1.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.0f,1.0f);
        glVertex3f(1.0f,0.0f,0.0f);

    glEnd();

}

float degree()
{
    return 180/M_PI;
}

float radian()
{
    return M_PI/180;
}
