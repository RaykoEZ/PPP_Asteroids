#include "Ship.h"

Ship::~Ship()
{

}
void Ship::drawMe(int _x, int _y, GLfloat _rot)
{
  //rotate on axis
  /*
    glTranslatef(0.0f,-0.25f,0.25f); //centre
    glRotatef(5.0f,0.0f,1.0f,0.0f);
    glTranslatef(0.0f,0.25f,-0.25f);
    */
    GLfloat speed = 0.01f;
    glPushMatrix();
        glTranslatef(speed*_x,speed*_y,0.0f);
        glRotatef(_rot,0.0f,1.0f,0.0f);


        glBegin(GL_TRIANGLES);


        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(0.0f, -1.0f, -1.0f);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(0.0f, -1.0f, -1.0f); //pointing forward

        glEnd();
    glPopMatrix();
    //m_position.set(m_position.m_x+speed*_x,m_position.m_y,m_position.m_z+speed*_y,1.0f);
    m_position.m_x+=speed*_x;
    m_position.m_y+=speed*_y;
}

void Ship::followMouse(int _xMouse, int _yMouse)
{
    GLfloat xDis;
    GLfloat yDis;
    GLfloat rot;
    xDis=_xMouse-m_position.m_x;
    yDis=_yMouse-m_position.m_y;
    if ((long)abs(yDis)<=std::numeric_limits<float>::epsilon())
    {
        drawMe(xDis,yDis,m_rot);
    }
    rot= atan2(yDis,xDis)*(degree());
    m_rot=rot;
    drawMe(xDis,yDis,-rot);

}

float degree()
{
    return 180/M_PI;
}
