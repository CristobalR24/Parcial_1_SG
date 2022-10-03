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
    gluOrtho2D(-60,60,-20,35);
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
    glColor3ub(255, 255, 255);
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
        glVertex2i(-60,35);glVertex2i(60,35);

        glColor3ub(255, 98, 71);
        glVertex2i(-60,30);glVertex2i(60,30);

        glColor3ub(255, 137, 65);
        glVertex2i(-60,10);glVertex2i(60,10);

        glColor3ub(255, 168, 62);
        glVertex2i(-60,-5);glVertex2i(60,-5);
    glEnd();

//////////////////////// Nubes /////////////////////////////////
    glPushMatrix();
        glTranslated(-45,28,1);
        nube_2();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,15,1);
        nube_2();
    glPopMatrix();

    glPushMatrix();
        glTranslated(45,26,1);
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

//////////////////////// Calle  /////////////////////////////////
void calle(){

    glBegin(GL_POLYGON);
      glColor3ub(80,80,80);
      glVertex2i(-60,-20);
      glVertex2i(-60,-5);

    glColor3ub(120,120,120);
      glVertex2i(60,-5);
      glVertex2i(60,-20);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(-59,-12);
        glVertex2i(-56,-11);
        glVertex2i(-50,-11);
        glVertex2i(-53,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(-49,-12);
        glVertex2i(-46,-11);
        glVertex2i(-40,-11);
        glVertex2i(-43,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(-39,-12);
        glVertex2i(-36,-11);
        glVertex2i(-30,-11);
        glVertex2i(-33,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(-29,-12);
        glVertex2i(-26,-11);
        glVertex2i(-20,-11);
        glVertex2i(-23,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(-19,-12);
        glVertex2i(-16,-11);
        glVertex2i(-10,-11);
        glVertex2i(-13,-12);
    glEnd();

   glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(-9,-12);
        glVertex2i(-6,-11);
        glVertex2i(0,-11);
        glVertex2i(-3,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(1,-12);
        glVertex2i(5,-11);
        glVertex2i(11,-11);
        glVertex2i(7,-12);
    glEnd();


    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(12,-12);
        glVertex2i(16,-11);
        glVertex2i(22,-11);
        glVertex2i(18,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(22,-12);
        glVertex2i(26,-11);
        glVertex2i(32,-11);
        glVertex2i(28,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(32,-12);
        glVertex2i(36,-11);
        glVertex2i(42,-11);
        glVertex2i(38,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(42,-12);
        glVertex2i(46,-11);
        glVertex2i(52,-11);
        glVertex2i(48,-12);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(250,253,15);
        glVertex2i(52,-12);
        glVertex2i(56,-11);
        glVertex2i(62,-11);
        glVertex2i(58,-12);
    glEnd();

}
////////////////////// Bosque //////////////////////////////////

void arbol_1(){

     //tronco arbol
     glLineWidth(10.0);
     glBegin(GL_LINES);
       glColor3ub(69,50,46);
       glVertex2i(-52,-5);
       glVertex2i(-52,1);
     glEnd();

     //hojas lado izquierdo
     glBegin(GL_TRIANGLES);
       glColor3ub(0,143,57);
       glVertex2i(-52,1);
       glVertex2i(-52,18);
       glVertex2i(-56,1);
     glEnd();

     //hojas lado derecho
     glBegin(GL_TRIANGLES);
       glColor3ub(0,187,45);
       glVertex2i(-52,1);
       glVertex2i(-52,20);
       glVertex2i(-48,1);
     glEnd();
   }

void arbol_2(){
       //tronco arbol
     glLineWidth(10.0);
     glBegin(GL_QUADS);
       glColor3ub(69,50,46);
       glVertex2i(-59,-5);
       glVertex2i(-59,0);
       glVertex2i(-57,0);
       glVertex2i(-57,-5);
     glEnd();

     glColor3ub(107,142,35);
     circulo(-58,4,5);

     glColor3ub(107,142,35);
     circulo(-58,9,4);

     glEnd();

   }

void arbol_3(){

    glLineWidth(10.0);
     glBegin(GL_QUADS);
       glColor3ub(69,50,46);
       glVertex2i(52,-5);
       glVertex2i(52,0);
       glVertex2i(54,0);
       glVertex2i(54,-5);
     glEnd();

     glColor3ub(40,114,51);
     circulo(53,4,5);

     glColor3ub(40,114,30);
     circulo(54,10,4);

     glColor3ub(40,114,51);
     circulo(52,11,3);

     glColor3ub(40,110,30);
     circulo(53,16,3);

     glEnd();

}

void pino_1(){

     //tronco pino
     glLineWidth(10.0);
     glBegin(GL_LINES);
       glColor3ub(69,50,46);
       glVertex2i(-46,-5);
       glVertex2i(-46,0);
     glEnd();

     glBegin(GL_QUADS);
       glColor3ub(69,50,46);
       glVertex2i(-47,-5);
       glVertex2i(-47,0);
       glVertex2i(-45,0);
       glVertex2i(-45,-5);
     glEnd();

     //hojas lado izquierdo
     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,-2);
       glVertex2i(-46,11);
       glVertex2i(-50,-2);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,0);
       glVertex2i(-46,12);
       glVertex2i(-50,0);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,2);
       glVertex2i(-46,13);
       glVertex2i(-50,2);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,4);
       glVertex2i(-46,14);
       glVertex2i(-50,4);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,6);
       glVertex2i(-46,15);
       glVertex2i(-50,6);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,8);
       glVertex2i(-46,16);
       glVertex2i(-50,8);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,10);
       glVertex2i(-46,17);
       glVertex2i(-50,10);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,12);
       glVertex2i(-46,18);
       glVertex2i(-50,12);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,14);
       glVertex2i(-46,19);
       glVertex2i(-50,14);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,16);
       glVertex2i(-46,20);
       glVertex2i(-50,16);
     glEnd();

      //hojas lado derecho
     glBegin(GL_TRIANGLES);
       glColor3ub(45,90,44);
       glVertex2i(-46,-2);
       glVertex2i(-46,11);
       glVertex2i(-42,-2);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,0);
       glVertex2i(-46,12);
       glVertex2i(-42,0);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,2);
       glVertex2i(-46,13);
       glVertex2i(-42,2);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,4);
       glVertex2i(-46,14);
       glVertex2i(-42,4);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,6);
       glVertex2i(-46,15);
       glVertex2i(-42,6);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,8);
       glVertex2i(-46,16);
       glVertex2i(-42,8);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,10);
       glVertex2i(-46,17);
       glVertex2i(-42,10);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,12);
       glVertex2i(-46,18);
       glVertex2i(-42,12);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,14);
       glVertex2i(-46,19);
       glVertex2i(-42,14);
     glEnd();

     glBegin(GL_TRIANGLES);
       glColor3ub(45,87,44);
       glVertex2i(-46,16);
       glVertex2i(-46,20);
       glVertex2i(-42,16);
     glEnd();

   }

   void pino_2(){

    //tronco arbol
     glLineWidth(10.0);
     glBegin(GL_LINES);
       glColor3ub(69,50,46);
       glVertex2i(58,-5);
       glVertex2i(58,1);
     glEnd();

     //hojas lado izquierdo
     glBegin(GL_TRIANGLES);
       glColor3ub(0,187,45);
       glVertex3i(58,-1,0);
       glVertex3i(58,20,0);
       glVertex3i(54,0,0);
     glEnd();

     //hojas lado derecho
     glBegin(GL_TRIANGLES);
       glColor3ub(0,143,57);
       glVertex3i(58,-1,0);
       glVertex3i(58,20,0);
       glVertex3i(64,0,1);
     glEnd();
}

void arbusto(){
  //lado izquierdo
  glColor3ub(28,84,45);
  circulo(-58,-5,2);

  glColor3ub(28,84,45);
  circulo(-55,-5,3);

  glColor3ub(0,143,57);
  circulo(-53,-5,3);

  glColor3ub(0,143,57);
  circulo(-50,-5,2);

  glColor3ub(45,87,44);
  circulo(-48,-5,1);

  glColor3ub(45,87,44);
  circulo(-47,-5,1);

  glColor3ub(45,87,44);
  circulo(-45,-5,2);

  //lado derecho

  glColor3ub(28,84,45);
  circulo(58,-5,2);

  glColor3ub(28,84,45);
  circulo(55,-5,3);

  glColor3ub(0,143,57);
  circulo(53,-5,3);

  glColor3ub(0,143,57);
  circulo(50,-5,2);

  glColor3ub(45,87,44);
  circulo(48,-5,1);

}

/////////////////////// cerca autopista /////////////////////////

void cerca(){

   glLineWidth(8.9);
   glBegin(GL_LINES);
     glColor3ub(84,56,34);

     glVertex2i(-60,-18);
     glVertex2i(60,-18);

     glColor3ub(121,80,48);
     glVertex2i(-58,-20);
     glVertex2i(-58,-16);

     glVertex2i(-48,-20);
     glVertex2i(-48,-16);

     glVertex2i(-38,-20);
     glVertex2i(-38,-16);

     glVertex2i(-28,-20);
     glVertex2i(-28,-16);


     glVertex2i(-18,-20);
     glVertex2i(-18,-16);

     glVertex2i(-8,-20);
     glVertex2i(-8,-16);

     glVertex2i(0,-20);
     glVertex2i(0,-16);

     glVertex2i(8,-20);
     glVertex2i(8,-16);

     glVertex2i(18,-20);
     glVertex2i(18,-16);

     glVertex2i(28,-20);
     glVertex2i(28,-16);

     glVertex2i(38,-20);
     glVertex2i(38,-16);

     glVertex2i(48,-20);
     glVertex2i(48,-16);

     glVertex2i(58,-20);
     glVertex2i(58,-16);

   glEnd();

}

void cesped(){

  glBegin(GL_TRIANGLES);
    glColor3ub(0,187,45);
    glVertex2i(-60,-20);
    glVertex2i(-59,-19);
    glVertex2i(-58,-20);

    glVertex2i(-57,-20);
    glVertex2i(-56,-19);
    glVertex2i(-55,-20);

    glVertex2i(-54,-20);
    glVertex2i(-53,-19);
    glVertex2i(-52,-20);

    glVertex2i(-51,-20);
    glVertex2i(-50,-19);
    glVertex2i(-49,-20);

    glVertex2i(-48,-20);
    glVertex2i(-47,-19);
    glVertex2i(-46,-20);

    glVertex2i(-45,-20);
    glVertex2i(-44,-19);
    glVertex2i(-43,-20);

    glVertex2i(-42,-20);
    glVertex2i(-41,-19);
    glVertex2i(-40,-20);

    glVertex2i(-39,-20);
    glVertex2i(-38,-19);
    glVertex2i(-37,-20);

    glVertex2i(-36,-20);
    glVertex2i(-35,-19);
    glVertex2i(-34,-20);

    glVertex2i(-33,-20);
    glVertex2i(-32,-19);
    glVertex2i(-31,-20);

    glVertex2i(-30,-20);
    glVertex2i(-29,-19);
    glVertex2i(-28,-20);

    glVertex2i(-27,-20);
    glVertex2i(-26,-19);
    glVertex2i(-25,-20);

    glVertex2i(-24,-20);
    glVertex2i(-23,-19);
    glVertex2i(-22,-20);

    glVertex2i(-21,-20);
    glVertex2i(-20,-19);
    glVertex2i(-19,-20);

    glVertex2i(-18,-20);
    glVertex2i(-17,-19);
    glVertex2i(-16,-20);

    glVertex2i(-15,-20);
    glVertex2i(-14,-19);
    glVertex2i(-13,-20);

    glVertex2i(-12,-20);
    glVertex2i(-11,-19);
    glVertex2i(-10,-20);

    glVertex2i(-9,-20);
    glVertex2i(-8,-19);
    glVertex2i(-7,-20);

    glVertex2i(-6,-20);
    glVertex2i(-5,-19);
    glVertex2i(-4,-20);

    glVertex2i(-3,-20);
    glVertex2i(-2,-19);
    glVertex2i(-1,-20);

    glVertex2i(0,-20);
    glVertex2i(1,-19);
    glVertex2i(2,-20);

    glVertex2i(3,-20);
    glVertex2i(4,-19);
    glVertex2i(5,-20);

    glVertex2i(6,-20);
    glVertex2i(7,-19);
    glVertex2i(8,-20);

    glVertex2i(9,-20);
    glVertex2i(10,-19);
    glVertex2i(11,-20);

    glVertex2i(12,-20);
    glVertex2i(13,-19);
    glVertex2i(14,-20);

    glVertex2i(15,-20);
    glVertex2i(16,-19);
    glVertex2i(17,-20);

    glVertex2i(18,-20);
    glVertex2i(19,-19);
    glVertex2i(20,-20);

    glVertex2i(21,-20);
    glVertex2i(22,-19);
    glVertex2i(23,-20);

    glVertex2i(24,-20);
    glVertex2i(25,-19);
    glVertex2i(26,-20);

    glVertex2i(27,-20);
    glVertex2i(28,-19);
    glVertex2i(29,-20);

    glVertex2i(30,-20);
    glVertex2i(31,-19);
    glVertex2i(32,-20);

    glVertex2i(33,-20);
    glVertex2i(34,-19);
    glVertex2i(35,-20);

    glVertex2i(36,-20);
    glVertex2i(37,-19);
    glVertex2i(38,-20);

    glVertex2i(39,-20);
    glVertex2i(40,-19);
    glVertex2i(41,-20);

    glVertex2i(42,-20);
    glVertex2i(43,-19);
    glVertex2i(44,-20);

    glVertex2i(45,-20);
    glVertex2i(46,-19);
    glVertex2i(47,-20);

    glVertex2i(48,-20);
    glVertex2i(49,-19);
    glVertex2i(50,-20);

    glVertex2i(51,-20);
    glVertex2i(52,-19);
    glVertex2i(53,-20);

    glVertex2i(54,-20);
    glVertex2i(55,-19);
    glVertex2i(56,-20);

    glVertex2i(57,-20);
    glVertex2i(58,-19);
    glVertex2i(59,-20);

    glVertex2i(60,-20);
    glVertex2i(61,-19);
    glVertex2i(62,-20);
  glEnd();
}

//////// Postes de luz //////////////

void poste_luz(){

  glLineWidth(6.0);

  glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex2i(-57,15);
    glVertex2i(-59,12);
    glVertex2i(-65,12);  //cables
    glVertex2i(-69,15);
  glEnd();


  glBegin(GL_QUADS);
    glColor3ub(0,0,0);   //poste
    glVertex2i(-57,-20);
    glVertex2i(-57,15);
    glVertex2i(-55,15);
    glVertex2i(-55,-20);
  glEnd();

  glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(-65,15);
    glVertex2i(-48,15);
  glEnd();

  glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex2i(-55,15);  //cables
    glVertex2i(-53,12);
    glVertex2i(-4,12.5);
    glVertex2i(-2,15);
  glEnd();

  glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-2,-20);
    glVertex2i(-2,15);
    glVertex2i(0,15);
    glVertex2i(0,-20);
  glEnd();

  glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(-9,15);
    glVertex2i(7,15);
  glEnd();

  glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex2i(0,15);
    glVertex2i(2,12);
    glVertex2i(53,12);  //cables
    glVertex2i(55,15);
  glEnd();

  glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(57,-20);
    glVertex2i(57,15);
    glVertex2i(55,15);
    glVertex2i(55,-20);
  glEnd();

  glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(48,15);
    glVertex2i(65,15);
  glEnd();

  glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex2i(57,15);
    glVertex2i(59,12);
    glVertex2i(65,12);  //cables
    glVertex2i(69,15);
  glEnd();


}

///////////////////// alien /////////////////////////

void alien(){
    glColor3ub(143,212,0); //cuerpo
    circulo(-50,-22,6);

    glColor3ub(200,255,0); //cabeza
    circulo(-50,-14,4);

    glColor3ub(0,0,0);  //ojos
    circulo(-48.5,-13,0.7);

    glColor3ub(0,0,0);
    circulo(-51.5,-13,0.7);

    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP); //Boca
     glColor3ub(0,0,0);
     glVertex2i(-52,-15);
     glVertex2i(-51,-16);
     glVertex2i(-49,-16);
     glVertex2i(-48,-15);
    glEnd();

}

static void display()
{
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        fondo();
        arbol_1();
        arbol_2();
        arbol_3();

        pino_1();
        pino_2();
        arbusto();
        calle();
        poste_luz();
        cerca();
        cesped();

        alien();
        glFlush();


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

    glutMainLoop();
    return 0;
}

