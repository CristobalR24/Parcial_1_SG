#include <windows.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

float calx, caly; //coordenadas del circulo
float xx=0.0,yy=0.0; //coordenadas del carro
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
void cabana(){
    glColor3ub(159, 125, 85);
    glRecti(-34,9,-20,-5);

    //paredes
    glBegin(GL_QUADS);
        glColor3ub(159, 125, 85);
        glVertex2i(-20,9);glVertex2i(-14,14);
        glVertex2i(-14,0);glVertex2i(-20,-5);
    glEnd();

    //techo
    glBegin(GL_QUADS);
        glColor3ub(113,67,50);
        glVertex2i(-33,12);glVertex2i(-21,12);
        glVertex2i(-17,9);glVertex2i(-36,9);
    glEnd();

    //techo 2
    glBegin(GL_QUADS);
        glColor3ub(113,67,50);
        glVertex2d(-19,20.5);glVertex2i(-13,15);
        glVertex2i(-17,9);glVertex2i(-33,12);
    glEnd();

    //techo 3
    glBegin(GL_QUADS);
        glColor3ub(113,67,50);
        glVertex2d(-24.5,20.5);glVertex2d(-19,20.5);
        glVertex2i(-17,9);glVertex2i(-36,9);
    glEnd();

    //ventana
    glColor3ub(113,67,50);
    glRecti(-31,7,-28,4);
    glRecti(-26,7,-23,4);

    //ventanas diagonales
    glBegin(GL_QUADS);
        glColor3ub(113,67,50);
        glVertex2i(-18,7);glVertex2i(-16,9);
        glVertex2i(-16,5);glVertex2i(-18,3);
    glEnd();

    //puerta
    glColor3ub(113,67,50);
    glRecti(-29,1,-26,-4);

    //marco de la cabaña
    glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glLineWidth(2.5f);
        glVertex2i(-17,9);glVertex2i(-13,15);
        glVertex2i(-36,9);glVertex2i(-17,9);
        glVertex2i(-36,9);glVertex2i(-33,12);
        glVertex2i(-33,12);glVertex2i(-20,12);
        glVertex2i(-17,9);glVertex2i(-23,15);
        glVertex2i(-33,12);glVertex2i(-30,15);
        glVertex2i(-30,15);glVertex2i(-23,15);
        glVertex2i(-30,15);glVertex2d(-24.5,20.5);
        glVertex2i(-23,15);glVertex2d(-19,20.5);
        glVertex2d(-19,20.5);glVertex2d(-24.5,20.5);
        glVertex2d(-19,20.5);glVertex2d(-13,15);
        glVertex2d(-34,9);glVertex2d(-34,-5);
        glVertex2d(-14,0);glVertex2d(-20,-5);
        glVertex2d(-14,13.5);glVertex2d(-14,0);
        glVertex2d(-20,-5);glVertex2d(-20,9);

        //marcos ventana izquierda
        glVertex2d(-31,4);  glVertex2d(-28,4);
        glVertex2d(-31,7);  glVertex2d(-28,7);
        glVertex2d(-31,4);  glVertex2d(-31,7);
        glVertex2d(-28,4);  glVertex2d(-28,7);
        glVertex2d(-29.5,4);  glVertex2d(-29.5,7);
        glVertex2d(-31,5.5);  glVertex2d(-28,5.5);

        //marcos ventana derecha
        glVertex2d(-26,4);  glVertex2d(-23,4);
        glVertex2d(-26,7);  glVertex2d(-23,7);
        glVertex2d(-26,4);  glVertex2d(-26,7);
        glVertex2d(-23,4);  glVertex2d(-23,7);
        glVertex2d(-24.5,4);  glVertex2d(-24.5,7);
        glVertex2d(-26,5.5);  glVertex2d(-23,5.5);

        //marcos ventana del fondo
        glVertex2d(-18,3);  glVertex2d(-16,5);
        glVertex2d(-18,7);  glVertex2d(-16,9);
        glVertex2d(-18,3);  glVertex2d(-18,7);
        glVertex2d(-16,5);  glVertex2d(-16,9);
        glVertex2d(-17,4);  glVertex2d(-17,8);
        glVertex2d(-18,5);  glVertex2d(-16,7);

        //marcos de la puerta
        glVertex2d(-29,1);  glVertex2d(-26,1);
        glVertex2d(-29,1);  glVertex2d(-29,-4);
        glVertex2d(-26,1);  glVertex2d(-26,-4);
        glVertex2d(-29,-4);  glVertex2d(-26,-4);
        glVertex2d(-26.5,-1);  glVertex2d(-26.5,-2);
    glEnd();
}

void metroBus()
{
    //LLANTAS DEL BUS


   /* glColor3ub(169,169,169);
    circulo(-6,-13,1.8);
    circulo(7,-13,1.8);*/

    //ARRIBA
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex2f(-4,3); glVertex2f(19,3);
        glVertex2f(19,3); glVertex2f(14,-3);
        glVertex2f(14,-3); glVertex2f(-10,-3);
        glVertex2f(-10,-3); glVertex2f(-4,3);
    glEnd();

    //AL LADO
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
        glVertex2f(-10,-3); glVertex2f(14,-3);
        glVertex2f(14,-3); glVertex2f(14,-13);
        glVertex2f(14,-13); glVertex2f(-10,-13);
        glVertex2f(-10,-13); glVertex2f(-10,-3);
    glEnd();

    //AL FRENTE
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
        glVertex2f(14,-3); glVertex2f(19,3);
        glVertex2f(19,3); glVertex2f(19,-7);
        glVertex2f(19,-7); glVertex2f(14,-13);
        glVertex2f(14,-13); glVertex2f(14,-3);
    glEnd();

    /////////// PUERTA DELANTERA //////////
    glBegin(GL_QUADS);
    glColor3ub(206,231,255);
        glVertex2f(9,-4); glVertex2f(13,-4);
        glVertex2f(13,-4); glVertex2f(13,-12);
        glVertex2f(13,-12); glVertex2f(9,-12);
        glVertex2f(9,-12); glVertex2f(9,-4);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(9,-4); glVertex2f(13,-4);
        glVertex2f(13,-4); glVertex2f(13,-12);
        glVertex2f(11,-4); glVertex2f(11,-12);
        glVertex2f(13,-12); glVertex2f(9,-12);
        glVertex2f(9,-12); glVertex2f(9,-4);
    glEnd();

    /////////// DIAGONAL NARANJA DEL METROBUS - PARTE DE LA PUERTA//////////
    glBegin(GL_QUADS);
    glColor3ub(255,165,0);
        glVertex2f(-6,-3); glVertex2f(2,-3);
        glVertex2f(2,-3); glVertex2f(7,-13);
        glVertex2f(7,-13); glVertex2f(-1,-13);
        glVertex2f(-1,-13); glVertex2f(-6,-3);
    glEnd();

    /////////// PUERTA TRASERA //////////
    glBegin(GL_QUADS);
    glColor3ub(206,231,255);
        glVertex2f(-4,-4); glVertex2f(0,-4);
        glVertex2f(0,-4); glVertex2f(0,-12);
        glVertex2f(0,-12); glVertex2f(-4,-12);
        glVertex2f(-4,-12); glVertex2f(-4,-4);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-4,-4); glVertex2f(0,-4);
        glVertex2f(0,-4); glVertex2f(0,-12);
        glVertex2f(-2,-4); glVertex2f(-2,-12);
        glVertex2f(0,-12); glVertex2f(-4,-12);
        glVertex2f(-4,-12); glVertex2f(-4,-4);
    glEnd();

    /////////// DIAGONAL NARANJA DEL METROBUS - PARTE DE ARRIBA//////////
    glBegin(GL_QUADS);
    glColor3ub(255,165,0);
        glVertex2f(0,3); glVertex2f(7,3);
        glVertex2f(7,3); glVertex2f(2,-3);
        glVertex2f(2,-3); glVertex2f(-6,-3);
        glVertex2f(-6,-3); glVertex2f(0,3);
    glEnd();

    ////////// VENTANA DELANTERA DEL METROBUS /////////////////
    glBegin(GL_QUADS);
    glColor3ub(206,231,255);
        glVertex2f(1,-4); glVertex2f(8,-4);
        glVertex2f(8,-4); glVertex2f(8,-9);
        glVertex2f(8,-9); glVertex2f(1,-9);
        glVertex2f(1,-9); glVertex2f(1,-4);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(1,-4); glVertex2f(8,-4);
        glVertex2f(8,-4); glVertex2f(8,-9);
        glVertex2f(3,-4); glVertex2f(3,-9);
        glVertex2f(6,-4); glVertex2f(6,-9);
        glVertex2f(8,-9); glVertex2f(1,-9);
        glVertex2f(1,-9); glVertex2f(1,-4);
    glEnd();

    ////////// VENTANA TRASERA DEL METROBUS /////////////////
    glBegin(GL_QUADS);
    glColor3ub(206,231,255);
        glVertex2f(-9,-4); glVertex2f(-5,-4);
        glVertex2f(-5,-4); glVertex2f(-5,-9);
        glVertex2f(-5,-9); glVertex2f(-9,-9);
        glVertex2f(-9,-9); glVertex2f(-9,-4);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-9,-4); glVertex2f(-5,-4);
        glVertex2f(-5,-4); glVertex2f(-5,-9);
        glVertex2f(-7,-4); glVertex2f(-7,-9);
        glVertex2f(-5,-9); glVertex2f(-9,-9);
        glVertex2f(-9,-9); glVertex2f(-9,-4);
    glEnd();

    ////////// VENTANA FRONTAL DEL METROBUS /////////////////
    glBegin(GL_QUADS);
    glColor3ub(206,231,255);
        glVertex2f(14.5,-3.2); glVertex2f(18.7,2);
        glVertex2f(18.7,2); glVertex2f(18.7,-3.6);
        glVertex2f(18.7,-3.6); glVertex2f(14.5,-8.7);
        glVertex2f(14.5,-8.7); glVertex2f(14.5,-3.2);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(14.5,-3.2); glVertex2f(18.7,2);
        glVertex2f(18.7,2); glVertex2f(18.7,-3.6);
        glVertex2f(16.8,-0.4); glVertex2f(16.8,-6.2);
        glVertex2f(18.7,-3.6); glVertex2f(14.5,-8.7);
        glVertex2f(14.5,-8.7); glVertex2f(14.5,-3.2);
    glEnd();

    ////////// PARTE FRONTAL INFERIOR DEL METROBUS /////////////////
    glBegin(GL_QUADS);
    glColor3ub(255,165,0);
        glVertex2f(14.5,-11); glVertex2f(18.7,-6);
        glVertex2f(18.7,-6); glVertex2f(18.7,-7);
        glVertex2f(18.7,-7); glVertex2f(14.5,-12);
        glVertex2f(14.5,-12); glVertex2f(14.5,-11);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex2f(14.5,-11.5); glVertex2f(18.7,-6.5);
    glEnd();
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

void rueda(){

    glColor3ub(48, 48, 48);
    circulo(0,0,2.3);

    glColor3ub(169,169,169);
    circulo(0,0,1.8);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(105,105,105);
        glVertex2f(-1.8,0);glVertex2f(1.8,0);
        glVertex2f(0,1.8);glVertex2f(0,-1.8);
    glColor3ub(82, 82, 82);
        glVertex2f(-1.3,-1.3);glVertex2f(1.3,1.3);
        glVertex2f(-1.3,1.3);glVertex2f(1.3,-1.3);
    glEnd();
}


static void display()
{
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        fondo();
        cabana();

        glPushMatrix();
            glTranslated(xx,yy,0);
            metroBus();
            glPushMatrix();
                glTranslated(-7,-13,0);
                glRotatef(a,0,0,1);
                rueda();
            glPopMatrix();;
            glPushMatrix();
                glTranslated(6,-13,0);
                glRotatef(a,0,0,1);
                rueda();
            glPopMatrix();


        glPopMatrix();
        glFlush();

}
/*
void specialkey(int key, int x, int y)
{
    if(key==GLUT_KEY_UP|GLUT_KEY_DOWN|GLUT_KEY_RIGHT|GLUT_KEY_LEFT)
        a-=20;
        glutPostRedisplay();
}
*/

void specialkey(int key, int x, int y)
{
    if((xx > -40 and xx < 40)){
        if(key==GLUT_KEY_LEFT|key==GLUT_KEY_DOWN){
            xx=xx-2;
            a-=15;
        }
        else if(key==GLUT_KEY_RIGHT|key==GLUT_KEY_UP){
            xx=xx+2;
            a-=15;
        }
        glutPostRedisplay();}
    else{
        if(xx >= 40)
            xx =-39;
        else if(xx <= -40)
            xx = 39;
    }
}

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
    glutSpecialFunc(specialkey);

    glutMainLoop();
    return 0;
}

