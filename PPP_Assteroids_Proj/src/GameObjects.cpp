#include "GameObjects.h"
#include <iostream>



void GameObjects::drawMe(Shape _type,float &_x,float &_y, float _rot )
{


    outOfScreen();
    glPushMatrix();
        glTranslatef(_x,0.0f,-_y);
        glRotatef(_rot,0.0f,1.0f,0.0f);
        _type(m_size);


    glPopMatrix();

}

void GameObjects::rotateMe(bool _left,float _rotDeg)
{

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

void GameObjects::forward(Shape _type)
{
    drawMe(_type,m_position.m_x,m_position.m_y,m_rot);
    //need normalized dirrection vector to move forward
}

void GameObjects::move(float _step)
{

    m_position.set((m_position.m_x+_step*m_direction.m_x),
                   (m_position.m_y+_step*m_direction.m_y),0.0f,1.0f);

}

void GameObjects::outOfScreen()
{
    if(m_position.m_x>20.0f||m_position.m_x<-20.0f||
       m_position.m_y>20.0f||m_position.m_y<-20.0f)
    {
        m_position.m_x=-m_position.m_x;
        m_position.m_y=-m_position.m_y;
    }

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


/*
 *
 * -----------------Non-class functions----------------------------
 *
*/
void shipType(const float _size)
{
    glBegin(GL_TRIANGLES);

    //draws tetrahedron - ship shape
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, _size, 0.0f);
    glVertex3f(_size, -_size, _size);
    glVertex3f(-_size, -_size, _size);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, _size, 0.0f);
    glVertex3f(0.0f, -_size, -1.5f*_size);
    glVertex3f(_size, -_size, _size);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, _size, 0.0f);
    glVertex3f(-_size, -_size, _size);
    glVertex3f(0.0f, -_size, -1.5f*_size);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(_size, -_size, _size);
    glVertex3f(-_size, -_size, _size);
    glVertex3f(0.0f, -_size, -1.5f*_size); //pointing forward

    glEnd();
}

void bulletType(const float _size)
{
    glBegin(GL_TRIANGLE_FAN);

        glColor3f(0.8f,0.8f,0.8f);

        glVertex3f(_size*0.0f,_size*0.0f,_size*-1.0f);
        glVertex3f(_size*-1.0f,_size*0.0f,_size*0.0f);
        glVertex3f(_size*0.0f,_size*0.0f,_size*1.0f);
        glVertex3f(_size*1.0f,_size*0.0f,_size*0.0f);



    glEnd();

}

void asteroidType(const float _size)
{
    float s =_size*0.5f;

    glBegin(GL_QUADS);
        glColor3f(1.0f,1.0f,1.0f);
        //glNormal3f(0,0,1);
        glVertex3f(-s,s,s);
        glVertex3f(s,s,s);
        glVertex3f(s,-s,s);
        glVertex3f(-s,-s,s);
        // back face
        //glNormal3d(0,0,-1);
        glVertex3f(-s,s,-s);
        glVertex3f(s,s,-s);
        glVertex3f(s,-s,-s);
        glVertex3f(-s,-s,-s);
        // Left face
        //glNormal3f(1,0,0);
        glVertex3f(-s,-s,s);
        glVertex3f(-s,-s,-s);
        glVertex3f(-s,s,-s);
        glVertex3f(-s,s,s);
        // Right face
        //glNormal3f(-1,0,0);
        glVertex3f(s,-s,s);
        glVertex3f(s,-s,-s);
        glVertex3f(s,s,-s);
        glVertex3f(s,s,s);
        // Top face
        //glNormal3f(0,1,0);
        glVertex3f(-s,s,s);
        glVertex3f(-s,s,-s);
        glVertex3f(s,s,-s);
        glVertex3f(s,s,s);
        // Bottom face
        //glNormal3f(0,-1,0);
        glVertex3f(-s,-s,s);
        glVertex3f(-s,-s,-s);
        glVertex3f(s,-s,-s);
        glVertex3f(s,-s,s);


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
