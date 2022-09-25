#include <windows.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

float calx, caly;
float a;


void circulo(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < 50; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(50);//obtiene el angulo actual

        float x = r * cosf(theta);//calcula el componente X
        float y = r * sinf(theta);//calcula el componente Y

        glVertex2f(x + cx, y + cy);//saca el vertice
    }
    glEnd();
}

void iniciarProyeccion ()
{   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f,0.0);
    gluOrtho2D(-40,40,-20,35);
}

void nube_1(){
    glColor3ub(252, 219, 114);
    circulo(-3,0,3);
    circulo(0,2.2,2.7);
    circulo(0,-1,2.7);
    circulo(3.5,1,2.5);
    circulo(3.5,-1,2.5);
    circulo(6,0,2.3);
}

void nube_2(){
    glColor3ub(252, 219, 114);
    circulo(-4,0,2.7);
    circulo(-2,2,2.4);
    circulo(4,1,2.4);
    circulo(-1.2,0,2.3);
    circulo(1,2,2.7);
    circulo(2,0,2.7);
    circulo(5.5,-0.5,2.5);
}

void fondo(){
//////////////// FONDO * Cielo * ////////////////////////////////
    glBegin(GL_QUAD_STRIP);
        glColor3ub(254, 64, 76);
        glVertex2i(-40,35);glVertex2i(40,35);

        glColor3ub(255, 98, 71);
        glVertex2i(-40,30);glVertex2i(40,30);

        glColor3ub(255, 137, 65);
        glVertex2i(-40,10);glVertex2i(40,10);

        glColor3ub(255, 168, 62);
        glVertex2i(-40,-5);glVertex2i(40,-5);
    glEnd();
//////////////////////// Sol /////////////////////////////////
    /*glColor3ub(252, 219, 114);
    circulo(0,-5,10);*/
//////////////////////// Nubes /////////////////////////////////
    glPushMatrix();
        glTranslated(-32,28,1);
        nube_2();
    glPopMatrix();
    glPushMatrix();
        glTranslated(0,15,1);
        nube_2();
    glPopMatrix();
    glPushMatrix();
        glTranslated(38,26,1);
        nube_2();
    glPopMatrix();
    ///////////////////////////
    glPushMatrix();
        glTranslated(-12,26,1);
        nube_1();
    glPopMatrix();
    glPushMatrix();
        glTranslated(18,29,1);
        nube_1();
    glPopMatrix();
////////////////// Aves ///////////////////////
    glColor3ub(20,20,20);
    glLineWidth(2.8);
    glBegin(GL_LINES);
        glVertex2f(-15,19);glVertex2f(-13,20);
        glVertex2f(-13,20);glVertex2f(-12.5,19);
        glVertex2f(-12.5,19);glVertex2f(-12,20);
        glVertex2f(-12,20);glVertex2f(-10,19);

        glVertex2f(30,33);glVertex2f(32,34);
        glVertex2f(32,34);glVertex2f(32.5,33);
        glVertex2f(32.5,33);glVertex2f(33,34);
        glVertex2f(33,34);glVertex2f(35,33);
    glEnd();
////////////////////// Montañas //////////////////////////////////
    glBegin(GL_TRIANGLES);
        glColor3f(0.44,0.85,0.0); //montaña derecha
        glVertex2f(0,-5);glColor3ub(138,128,0.0);glVertex2f(27,29);glVertex2f(54,-5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.44,0.85,0.0); //montaña izquierda
        glVertex2f(4,-5);glColor3ub(138,128,0.0);glVertex2f(-58,-5);glVertex2f(-26.3,29);
    glEnd();
}

static void display()
{
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        fondo();
        glFlush();

}
/*
void specialkey(int key, int x, int y)
{
    if(key==GLUT_KEY_UP|GLUT_KEY_DOWN|GLUT_KEY_RIGHT|GLUT_KEY_LEFT)
        a-=20;
        glutPostRedisplay();
}*/


int main (int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(950,600);
    glutInitWindowPosition(300,100);

    int x = abs((GetSystemMetrics(SM_CXSCREEN)-950)/2);
    int y = abs((GetSystemMetrics(SM_CYSCREEN)-600)/2);

    glutInitWindowPosition(x,y);

    glutCreateWindow ("Parcial 1 - Castillo, González, Morales, Quiel, Rodríguez, Saldaña");

    iniciarProyeccion();
    glutDisplayFunc(display);
    //glutSpecialFunc(specialkey);

    glutMainLoop();
    return 0;
}

