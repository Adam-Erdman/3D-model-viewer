#include "RecPrismBox.h"

//#include <objsafe.h>
#include <GL/glut.h>

#include <stdio.h>

#include <stdlib.h>


GLfloat r,g,b;
GLint rint, gint,bint;
GLfloat lightpos[4];

//constructor
RecPrismBox::RecPrismBox(QWidget *parent, const char *name) : QOpenGLWidget(parent)
{

}


/*!

  Release allocated resources
*/

//destructor
RecPrismBox::~RecPrismBox()
{
    makeCurrent();

    if (prism_object)
        glDeleteLists(prism_object, 1);
}


/*!
  Paint the panel with updated parameter values
*/
//protected method of QOpenGLWidget
void RecPrismBox::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0, 0, -10);
    glScaled(scaleFactor, scaleFactor, scaleFactor);
    glColor3ub(rint, gint, bint);
    glRotated(colorFactor, 1, 0, 0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightpos);
    glRotated(slider2Factor, 0, 1, 0);
    glRotated(zoomFactor, 0, 0, 1);
    glCallList(prism_object);
}


/*!
  Initialize
*/
//protected method of QOpenGLWidget
void RecPrismBox::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
    prism_object = makeObject();
}





/*!
  Set up the OpenGL view port, matrix mode, etc.
*/
//protected method of QOpenGLWidget
void RecPrismBox::resizeGL(int x, int y)
{
    glViewport(0, 0, (GLint)x, (GLint)y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 5, 15);
    glMatrixMode(GL_MODELVIEW);
}


/*!
  Generate prism object
*/

GLuint RecPrismBox::makeObject()
{
    GLuint list;

    list = glGenLists(1);

    glNewList(list, GL_COMPILE);

    glLineWidth(2);
    //Box
    glBegin(GL_QUADS);
    glVertex3d( 1,  0.5, -0.4);
    glVertex3d( 1, -0.5, -0.4);
    glVertex3d(-1, -0.5, -0.4);
    glVertex3d(-1,  0.5, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3d( 1,  0.5, 0.4);
    glVertex3d( 1, -0.5, 0.4);
    glVertex3d(-1, -0.5, 0.4);
    glVertex3d(-1,  0.5, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3d( 1,  0.5, -0.4);   glVertex3d( 1,  0.5, 0.4);
    glVertex3d( 1, -0.5, -0.4);   glVertex3d( 1, -0.5, 0.4);
    glVertex3d(-1, -0.5, -0.4);   glVertex3d(-1, -0.5, 0.4);
    glVertex3d(-1,  0.5, -0.4);   glVertex3d(-1,  0.5, 0.4);
    glEnd();






    glEndList();

    return list;
}

GLuint RecPrismBox::makeObjectPyramid()
{
    GLuint list;

    list = glGenLists(1);

    glNewList(list, GL_COMPILE);

    glLineWidth(2);

    glEnd();

    //Pyramid

    glBegin(GL_TRIANGLES);
    glVertex3d( 0,  1, 0);
    glVertex3d( -1, -1, 1);
    glVertex3d(1, -1, 1);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3d( 0,  1, 0);
    glVertex3d( 1, -1, 1);
    glVertex3d( 1 , -1, -1);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3d( 0,  1, 0);
    glVertex3d(1, -1, -1);
    glVertex3d(-1, -1, -1);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3d( 0,  1, 0);
    glVertex3d( -1, -1, -1);
    glVertex3d(-1, -1, 1);

    glEnd();




    glEndList();

    return list;
}

GLuint RecPrismBox::makeObjectPrism()
{
    GLuint list;

    list = glGenLists(1);

    glNewList(list, GL_COMPILE);

    glLineWidth(2);

    glEnd();

    //Pyramid

    glBegin(GL_TRIANGLES);
    glVertex3d( 0,  1, -1); //top
    glVertex3d( -1, -1, -1); //bot left
    glVertex3d(1, -1, -1); // bot  right

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3d( 0,  1, 1); //top
    glVertex3d( -1, -1, 1); //bot left
    glVertex3d(1, -1, 1); //bot right

    glEnd();

    glBegin(GL_QUADS);
    glVertex3d( 0,  1, -1); //top
    glVertex3d( 0,  1, 1); //top
    glVertex3d( -1, -1, 1); //bot left
    glVertex3d( -1, -1, -1); //bot left

    glEnd();

    glBegin(GL_QUADS);
    glVertex3d( 0,  1, -1); //top
    glVertex3d( 0,  1, 1); //top
    glVertex3d(1, -1, -1); // bot  right
    glVertex3d(1, -1, 1); //bot right

    glEnd();

    glBegin(GL_QUADS);
    glVertex3d( -1, -1, 1); //bot left
    glVertex3d( -1, -1, -1); //bot left
    glVertex3d(1, -1, -1); // bot  right
    glVertex3d(1, -1, 1); //bot right

    glEnd();


    glEndList();

    return list;
}


/*!
  make color change and rotate in x axis
*/

void RecPrismBox::makeXRotateAndChangeColor(int param)
{
    colorFactor = GLdouble(param % 360);

//    int rtemp = GLint(param % 360);
//    if (rtemp > 255){
//        rtemp=rtemp-255;
//    }
//    rint = rtemp;
//    gint = rint-100;
//    if (gint<0)
//        gint = 25;

    update();
}

void RecPrismBox::ChangeColor(int param)
{
    //colorFactor = GLdouble(param % 360);

    int rtemp = GLint(param % 360);
    if (rtemp > 255){
        rtemp=rtemp-255;
    }
    rint = rtemp;
    gint = rint-100;
    if (gint<0)
        gint = 25;

    update();
}


/*!
  Make Light change and rotate in Y axis
*/

void RecPrismBox::makeYRotateAndLightChange(int degrees)
{
    slider2Factor = GLdouble(degrees % 360);
    g=GLdouble(degrees/100);

    int ltemp = GLint(degrees/100);
    if (ltemp > 15 ){
        ltemp=15;
    }

    lightpos[0] = 5.0;
    lightpos[1] = ltemp;
    lightpos[2] = ltemp+8;
    lightpos[3] = ltemp-5;

    update();
}


/*!
  make Zoom in and Zoom out
*/

void RecPrismBox::makeZoomInZoomOut(int scale)
{
    scaleFactor = GLint(scale/100);
    update();
}

void RecPrismBox::BoxRadio(bool clicked)
{
    if  (clicked){
        initializeOpenGLFunctions();
        glClearColor(0, 0, 0, 1);
        prism_object = makeObject();
        update();
    }

}

void RecPrismBox::PyramidRadio(bool clicked)
{
    if  (clicked){
        initializeOpenGLFunctions();
        glClearColor(0, 0, 0, 1);
        prism_object = makeObjectPyramid();
        update();
    }

}

void RecPrismBox::ConeRadio(bool clicked)
{
    if  (clicked){
        initializeOpenGLFunctions();
        glClearColor(0, 0, 0, 1);
        prism_object = makeObjectPrism();
        update();
    }

}





