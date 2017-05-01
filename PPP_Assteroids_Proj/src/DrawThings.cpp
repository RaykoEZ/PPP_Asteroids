#include <iostream>
#include "DrawThings.h"
#include "Vec4.h"
#include "Mat4.h"
#include <cmath>


void DrawThings::draw()
{
  //rotate on axis
    glTranslatef(0.0f,-0.25f,0.25f);
    glRotatef(5.0f,0.0f,1.0f,0.0f);
    glTranslatef(0.0f,0.25f,-0.25f);

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
    glVertex3f(0.0f, -1.0f, -1.0f);

    glEnd();
}

void DrawThings::drawAsteroid()
{

}

