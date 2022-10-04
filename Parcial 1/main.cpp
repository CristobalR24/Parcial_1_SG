#include <windows.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

float calx, caly; //coordenadas del circulo
float xx=0.0,yy=0.0; //coordenadas del carro
float a;
float b1;
int b2;


void timer(int){
    glutPostRedisplay();
    b1-=1;
    if((int)b1%2==0){ //cada paso par hara como si estuviera caminando, es decir b2 se trasladara en 1 -y-
        b2=1;
    }
    else{b2=0;}

    if(b1<-11){ //para que no se salga de la pantalla
        b1=105;
    }
    glutTimerFunc(10000/60,timer,0);
}

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
    glColor3ub(252, 219, 114);
    circulo(-4,0,2.7);
    circulo(-2,2,2.4);
    circulo(4,1,2.4);
    circulo(-1.2,0,2.3);
    circulo(1,2,2.7);
    circulo(2,0,2.7);
    circulo(5.5,-0.5,2.5);
}

void nubes(){

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
//////////////////////// Sol /////////////////////////////////
    glColor3ub(255,255,102);
    circulo(0,10,10);

//////////////////////// Nubes /////////////////////////////////
    glPushMatrix();
        glTranslated(-53,29,1);
        nube_2();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-38,21,1);
        nube_2();
    glPopMatrix();
    glPushMatrix();
        glTranslated(48,26,1);
        nube_2();
    glPopMatrix();
    ///////////////////////////
    glPushMatrix();
        glTranslated(-12,27,1);
        nube_1();
    glPopMatrix();
    glPushMatrix();
        glTranslated(18,25,1);
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

        glVertex2f(-37,30);glVertex2f(-35,31);
        glVertex2f(-35,31);glVertex2f(-34.5,30);
        glVertex2f(-34.5,30);glVertex2f(-34,31);
        glVertex2f(-34,31);glVertex2f(-32,30);
    glEnd();
////////////////////// Montañas //////////////////////////////////
    glBegin(GL_TRIANGLES);
        glColor3f(0.44,0.85,0.0); //montaña derecha
        glVertex2f(-8,-5);glColor3ub(138,128,0.0);glVertex2f(33,29);glVertex2f(74,-5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.44,0.85,0.0); //montaña izquierda
        glVertex2f(8,-5);glColor3ub(138,128,0.0);glVertex2f(-78,-5);glVertex2f(-26.3,29);
    glEnd();

     glBegin(GL_QUADS); //piso arriba
        glColor3ub(47, 117, 9);
        glVertex2i(-60,3);glVertex2i(60,3);
        glVertex2i(60,-5);glVertex2i(-60,-5);

        glColor3ub(171, 162, 150);
        glVertex2i(-40,3);glVertex2i(50,3);
        glVertex2i(54,-5);glVertex2i(-40,-5);
    glEnd();
}

void calle(){

    glBegin(GL_POLYGON);
      glColor3ub(120,120,120);
      glVertex2i(-60,-5);
      glVertex2i(60,-5);

    glColor3ub(50,50,50);
      glVertex2i(60,-20);
      glVertex2i(-60,-20);
    glEnd();

    int t1=-69,t2=-66,t3=-60,t4=-63;

    for(int i = 0;i < 200;i++){
        t1+=10;
        t2+=10;
        t3+=10;
        t4+=10;

        glBegin(GL_POLYGON);
        glColor3ub(250,253,15);
            glVertex2i(t1,-12);
            glVertex2i(t2,-11);
            glVertex2i(t3,-11);
            glVertex2i(t4,-12);
        glEnd();
    }


}
/////////////// BOSQUE ///////////////////////////
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
    int t1=-2,t2=10;

    for(int i = 0;i < 9;i++){
        t1+=2;
        t2+=1;

        glBegin(GL_TRIANGLES);
           glColor3ub(45,87,44);
           glVertex2i(-46,t1);
           glVertex2i(-46,t2);
           glVertex2i(-50,t1);
        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3ub(45,90,44);
            glVertex2i(-46,t1);
            glVertex2i(-46,t2);
            glVertex2i(-42,t1);
        glEnd();
    }
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

void cesped(){
    int t1=-60,t2=-59,t3=-58;
    glColor3ub(0,187,45);

    glBegin(GL_TRIANGLES);
        glVertex2i(t1,-20);
        glVertex2i(t2,-19);
        glVertex2i(t3,-20);

    for(int i = 0;i < 200;i++){
        t1+=3;
        t2+=3;
        t3+=3;
        glVertex2i(t1,-20);
        glVertex2i(t2,-19);
        glVertex2i(t3,-20);
    }
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

void cabana(){
    //paredes
    glBegin(GL_QUADS);
        glColor3ub(159, 125, 85);
        glVertex2i(-20,9);glVertex2i(-34,9);
        glColor3ub(125, 96, 62);
        glVertex2i(-34,-5);glVertex2i(-20,-5);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(159, 125, 85);
        glVertex2i(-20,9);glVertex2i(-14,14);
        glColor3ub(125, 96, 62);
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
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glColor3ub(0,0,0);

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

void palacio(){
//Edificio
glBegin(GL_QUADS);
glColor3ub(221,222,223);
glVertex2f(12.2,16);glVertex2f(-14.2,16);
glColor3ub(194, 194, 194);
glVertex2f(-14.2,-2.2);glVertex2f(12.2,-2.2);
glEnd();
//Plano
glBegin(GL_QUADS);
glColor3ub(221,222,223);
glVertex2f(18,20);glVertex2f(12,16);
glColor3ub(194, 194, 194);
glVertex2f(12,-2.4);glVertex2f(18,4);
glEnd();
//Plano
glBegin(GL_QUADS);
glColor3ub(221,222,223);
glVertex2f(-14,16); glVertex2f(-10,20);
glVertex2f(18,20); glVertex2f(10,10);
glEnd();
//Contorno Del Edficio 1
glLineWidth(2);
glBegin(GL_LINE_STRIP);
glColor3ub(0,0,0);
glVertex2f(-14,16); glVertex2f(-10,20);
glVertex2f(18,20);
glEnd();
//Contorno del Edficio 2
glLineWidth(2);
glBegin(GL_LINE_STRIP);
glColor3ub(0,0,0);
glVertex2f(12,16); glVertex2f(18,20);
glVertex2f(18,20); glVertex2f(18,4);
glVertex2f(18,4); glVertex2f(12,-2.4);
glVertex2f(12,-2.4); glVertex2f(12,16);
glEnd();
//Ventana
glBegin(GL_QUADS);
glColor3ub(177,239,249);
glVertex2f(14,12); glVertex2f(14,14);
glVertex2f(16,16);glVertex2f(16,14);
glEnd();
//Ventana
glBegin(GL_QUADS);
glColor3ub(177,239,249);
glVertex2f(14,10); glVertex2f(14,12);
glVertex2f(16,14);glVertex2f(16,12);
glEnd();
//Definición Ventana
glLineWidth(2);
glBegin(GL_LINE_STRIP);
glColor3ub(0,0,0);
glVertex2f(14,12); glVertex2f(14,14);
glVertex2f(16,16);glVertex2f(16,14);
glEnd();
//Definición Ventana
glLineWidth(2);
glBegin(GL_LINE_STRIP);
glColor3ub(0,0,0);
glVertex2f(14,10); glVertex2f(14,12);
glVertex2f(16,14);glVertex2f(16,12);
glVertex2f(14,10);
glEnd();

//Definición Edificion
glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(-14.2,-2.2);
 glVertex2f(-14.2,16);
 glVertex2f(12.2,16);
 glVertex2f(12.2,-2.2);
 glVertex2f(-14.2,-2.2);
 glEnd();
//Puerta
 glBegin(GL_QUADS);
 glColor3ub(75,75,75);
 glVertex2f(-6.1,-2.2);glVertex2f(-6.1,4);
 glVertex2f(-4.5,4); glVertex2f(-4.5,-2.2);
 glEnd();

 // puerta2

 glBegin(GL_QUADS);
 glColor3ub(75,75,75);
 glVertex2f(4.1,-2.2); glVertex2f(4.1,4.1);
 glVertex2f(6,4.1); glVertex2f(6,-2.2);
 glEnd();

 //Polygono
 glBegin(GL_POLYGON);
 glColor3ub(182,182,182);
 glVertex2f(0,8);
 glVertex2f(4.1,8);
 glVertex2f(8,4.1);
 glVertex2f(0,4);
 glEnd();


 //Polygono
 glBegin(GL_POLYGON);
 glColor3ub(182,182,182);
 glVertex2f(0,4);
 glVertex2f(-8,4);
 glVertex2f(-4.5,8);
 glVertex2f(0,8);
 glEnd();


 //lineas ventanas
glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(-12,-1);
 glVertex2f(-12,6);
 glVertex2f(-8,6);
 glVertex2f(-8,-1);
 glVertex2f(-12,-1);
  glVertex2f(-8,-1);
 glEnd();

 // Interior ventana
 glBegin(GL_QUADS);
 glColor3ub(177,239,249);
 glVertex2f(-12,-1);
 glVertex2f(-12,6);
 glVertex2f(-8,6);
 glVertex2f(-8,-1);
 glEnd();


 //Ventana 2
 glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(-12,8.5);
 glVertex2f(-12,14.2);
 glVertex2f(-10,14.2);
 glVertex2f(-10,8.5);
 glVertex2f(-12,8.5);
 glEnd();

//Interior Ventana2
glBegin(GL_QUADS);
 glColor3ub(177,239,249);
 glVertex2f(-12,8.5);
 glVertex2f(-12,14.2);
 glVertex2f(-10,14.2);
 glVertex2f(-10,8.5);
 glEnd();

 //ventana3
 glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(-10,8.5);
 glVertex2f(-10,14.2);
 glVertex2f(-6.5,14.2);
 glVertex2f(-6.5,8.5);
 glVertex2f(-10,8.5);
 glEnd();
 //Interior Ventana3
 glBegin(GL_QUADS);
 glColor3ub(177,239,249);
 glVertex2f(-10,8.5);glVertex2f(-10,14.2);
 glVertex2f(-6.5,14.2);glVertex2f(-6.5,8.5);
 glEnd();

 //VentanaPrincipal
 glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(-4,10);glVertex2f(-4,14);
 glVertex2f(4,14);glVertex2f(4,10);
 glVertex2f(-4,10);
 glEnd();

 //Interior Ventana Principal
 glBegin(GL_QUADS);
 glColor3ub(177,239,249);
 glVertex2f(-4,10);glVertex2f(-4,14);
 glVertex2f(4,14);glVertex2f(4,10);
 glEnd();

 //ventana derecha
 glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(6,10);glVertex2f(6,14);
 glVertex2f(9,14);glVertex2f(9,10);
 glVertex2f(6,10);
 glEnd();
 // Interior Ventana
 glBegin(GL_QUADS);
 glColor3ub(177,239,249);
 glVertex2f(6,10);
 glVertex2f(6,14);
 glVertex2f(9,14);
 glVertex2f(9,10);
 glEnd();

 //Interior Ventana Derecha
 glBegin(GL_QUADS);
 glColor3ub(177,239,249);
 glVertex2f(-12,-1);
 glVertex2f(-12,6);
 glVertex2f(-8,6);
 glVertex2f(-8,-1);
 glEnd();


 //Ventana
 glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(8,0);
 glVertex2f(8,6);
 glVertex2f(11,6);
 glVertex2f(11,0);
 glVertex2f(8,0);
 glEnd();

 //Interior Ventana
 glBegin(GL_QUADS);
 glColor3ub(177,239,249);
 glVertex2f(8,0);glVertex2f(8,6);
 glVertex2f(11,6);glVertex2f(11,0);
 glEnd();

// Balcon

glBegin(GL_POLYGON);
glColor3ub(221,222,223);
glVertex2f(-5,10);glVertex2f(0,10);
glVertex2f(0,8); glVertex2f(-5,8);
glEnd();

//Balcon2
glBegin(GL_POLYGON);
glColor3ub(221,222,223);
glVertex2f(0,10);glVertex2f(4,10);
glVertex2f(4,8); glVertex2f(0,8);
glEnd();

// Contorno balcon
glLineWidth(2);
 glBegin(GL_LINE_STRIP);
glColor3ub(0,0,0);
glVertex2f(-5,10);glVertex2f(0,10);
glVertex2f(0,8); glVertex2f(-5,8);
glVertex2f(-5,10);
glEnd();

// Contorno Balcon #2
glLineWidth(2);
 glBegin(GL_LINE_STRIP);
glColor3ub(0,0,0);
glVertex2f(0,10);glVertex2f(4,10);
glVertex2f(4,8); glVertex2f(0,8);
glEnd();

 //Puerta
 glBegin(GL_QUADS);
 glColor3ub(116,84,9);
 glVertex2f(-2.5,-2.2); glVertex2f(-2.5,2.2);
 glVertex2f(2.5,2.2); glVertex2f(2.5,-2.2);
 glEnd();

 //Definición Puerta
 glLineWidth(2);
 glBegin(GL_LINE_STRIP);
 glColor3ub(0,0,0);
 glVertex2f(-2.5,-2.2);
 glVertex2f(-2.5,2.2);
 glVertex2f(2.5,2.2);
 glVertex2f(2.5,-2.2);
 glVertex2f(-2.5,-2.2);
 glEnd();
}

void mcdonalds(){
    //Color del Poste
    glColor3ub(50,40,30);
    //Poste
    glRecti(20,14,22,9);

    //Color del soporte
    glColor3ub(254,109,97);
    //Soporte
    glBegin(GL_QUADS);
        glVertex2i(18,15);glVertex2i(24,15);
        glVertex2i(24,14);glVertex2i(18,14);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(19,15);glVertex2i(20,16);
        glVertex2i(23,16);glVertex2i(23,15);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(24,15);glVertex2i(25,16);
        glVertex2i(25,15);glVertex2i(24,14);
    glEnd();
    //Color del logo
    glColor3ub(235, 217, 35);
    //Logo - Laterales
    glBegin(GL_QUADS);
        glVertex2i(19,15);glVertex2i(20,16);
        glVertex2i(20,21);glVertex2i(19,20);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(18,20);glVertex2i(19,20);
        glVertex2i(20,21);glVertex2i(19,21);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(19,20);glVertex2i(20,21);
        glVertex2i(22,19);glVertex2i(21,18);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(24,15);glVertex2i(25,16);
        glVertex2i(25,21);glVertex2i(24,20);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(23,20);glVertex2i(24,20);
        glVertex2i(25,21);glVertex2i(24,21);
    glEnd();
    //Logo - Frente
    glColor3ub(255,236,35);
    glRecti(18,20,19,15);
    glBegin(GL_QUADS);
        glVertex2i(18,20);glVertex2i(19,20);
        glVertex2i(21,18);glVertex2i(21,16);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(23,20);glVertex2i(24,20);
        glVertex2i(21,16);glVertex2i(21,18);
    glEnd();
    glRecti(23,20,24,15);

    //Color del Local
    glColor3ub(136, 119, 111);
    //Pared frontal 1
    glRecti(16,8,26,-5);
    //pared lateral 1
    glBegin(GL_QUADS);
        glVertex2i(26,8);glVertex2i(28,9);
        glVertex2i(28,-4);glVertex2i(26,-5);
    glEnd();
    //Pared frontal 2
    glRecti(28,9,32,-4);
    //pared lateral 2
    glBegin(GL_QUADS);
        glVertex2i(32,9);glVertex2i(34,10);
        glVertex2i(34,-3);glVertex2i(32,-4);
    glEnd();
    //pared trasera 1
    glBegin(GL_QUADS);
        glVertex2f(17.5,9.5);glVertex2f(18.5,9.5);
        glVertex2i(17,8);glVertex2i(16,8);
    glEnd();
    //pared trasera 2
    glBegin(GL_QUADS);
        glVertex2f(18.5,9.5);glVertex2f(28,9.5);
        glVertex2i(26,9);glVertex2i(18,9);
    glEnd();
    //pared trasera 3
    glBegin(GL_QUADS);
        glVertex2i(28,10);glVertex2i(29,10);
        glVertex2f(28,9.5);glVertex2f(26,9.5);
    glEnd();
    //pared trasera 4
    glBegin(GL_QUADS);
        glVertex2f(29,10);glVertex2f(34,10);
        glVertex2f(33,9.5);glVertex2f(26,9.5);
    glEnd();

    //Color del techo
    glColor3ub(70, 60, 60);
    //techo 1
    glBegin(GL_QUADS);
        glVertex2i(18,9);glVertex2i(29,9);
        glVertex2i(26,8);glVertex2i(17,8);
    glEnd();
    //techo 2
    glBegin(GL_QUADS);
        glVertex2f(28,9.5);glVertex2f(33,9.5);
        glVertex2i(32,9);glVertex2i(26,9);
    glEnd();

    //Color Puerta y Ventanas
    glColor3ub(150,179,215);
    //Ventana 1
    glBegin(GL_QUADS);
        glVertex2i(26,4);glVertex2i(16,4);
        glColor3ub(116, 139, 168);
        glVertex2i(16,-3);glVertex2i(26,-3);
    glEnd();
    //Ventana 2
    glBegin(GL_QUADS);
        glVertex2i(26,4);glVertex2i(28,5);
        glVertex2i(28,-2);glVertex2i(26,-3);
    glEnd();
    //Ventana 3
    glBegin(GL_QUADS);
        glVertex2i(32,5);glVertex2i(34,6);
        glVertex2i(34,-1);glVertex2i(32,-2);
    glEnd();
    //Puerta
    glRecti(29,1,31,-4);

    //Color Detalle
    glColor3ub(244,242,238);
    //Detalle 1
    glRecti(16,6,26,5);
    //Detalle 2
    glBegin(GL_QUADS);
        glVertex2i(26,6);glVertex2i(28,7);
        glVertex2i(28,6);glVertex2i(26,5);
    glEnd();
    //Detalle 3
    glRecti(28,7,32,6);
    //Detalle 4
    glBegin(GL_QUADS);
        glVertex2i(32,7);glVertex2i(34,8);
        glVertex2i(34,7);glVertex2i(32,6);
    glEnd();

    //Color del pavimento
    glColor3ub(171,173,181);
    //Pavimento
    glBegin(GL_QUADS);
        glVertex2i(28,-4);glVertex2i(32,-4);
        glVertex2i(30,-5);glVertex2i(26,-5);
    glEnd();

    //Marco del McDonalds
    glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glLineWidth(2.5f);

        //Paredes
        glVertex2i(16,8);glVertex2i(16,-5);
        glVertex2i(16,8);glVertex2i(26,8);
        glVertex2i(16,-5);glVertex2i(26,-5);
        glVertex2i(26,8);glVertex2i(26,-5);
        glVertex2i(26,8);glVertex2i(28,9);
        glVertex2i(28,9);glVertex2i(28,-4);
        glVertex2i(28,-4);glVertex2i(26,-5);
        glVertex2i(28,9);glVertex2i(32,9);
        glVertex2i(32,9);glVertex2i(32,-4);
        glVertex2i(32,-4);glVertex2i(28,-4);
        glVertex2i(32,9);glVertex2i(34,10);
        glVertex2i(34,10);glVertex2i(34,-3);
        glVertex2i(34,-3);glVertex2i(32,-4);
        glVertex2i(16,8);glVertex2f(17.5,9.5);
        glVertex2f(17.5,9.5);glVertex2f(26,9.5);
        glVertex2f(26,9.5);glVertex2i(28,10);
        glVertex2i(28,10);glVertex2f(34,10);

        //Ventanas
        glVertex2i(16,4);glVertex2i(26,4);
        glVertex2i(16,-3);glVertex2i(26,-3);
        glVertex2i(26,4);glVertex2i(28,5);
        glVertex2i(26,-3);glVertex2i(28,-2);
        glVertex2f(32,5);glVertex2i(34,6);
        glVertex2i(32,-2);glVertex2i(34,-1);

        //Puerta
        glVertex2i(29,1);glVertex2f(31,1);
        glVertex2i(29,1);glVertex2i(29,-4);
        glVertex2i(31,1);glVertex2i(31,-4);
        //Perno
        glVertex2f(30.5,-1);glVertex2f(30.5,-2);

        //Detalles
        glVertex2i(16,6);glVertex2f(26,6);
        glVertex2i(16,5);glVertex2i(26,5);
        glVertex2i(26,6);glVertex2i(28,7);
        glVertex2i(26,5);glVertex2i(28,6);
        glVertex2i(28,7);glVertex2i(32,7);
        glVertex2i(28,6);glVertex2i(32,6);
        glVertex2i(32,7);glVertex2i(34,8);
        glVertex2i(32,6);glVertex2i(34,7);

        //Poste
        glVertex2i(20,14);glVertex2f(20,9.5);
        glVertex2i(22,14);glVertex2f(22,9.5);

        //Soporte
        glVertex2i(18,15);glVertex2i(24,15);
        glVertex2i(24,15);glVertex2i(24,14);
        glVertex2i(23,14);glVertex2i(18,14);
        glVertex2i(18,14);glVertex2i(18,15);
        glVertex2i(25,16);glVertex2i(25,15);
        glVertex2i(23,14);glVertex2i(24,14);
        glVertex2i(24,14);glVertex2i(25,15);

        //Logo - Frontales
        glVertex2i(18,20);glVertex2i(19,20);
        glVertex2i(18,20);glVertex2i(18,15);
        glVertex2i(18,15);glVertex2i(19,15);
        glVertex2i(19,15);glVertex2f(19,18.5);
        glVertex2f(19,18.5);glVertex2i(21,16);
        glVertex2i(19,20);glVertex2i(21,18);
        glVertex2f(23,18.5);glVertex2i(21,16);
        glVertex2i(23,20);glVertex2i(21,18);
        glVertex2i(23,20);glVertex2i(24,20);
        glVertex2i(24,20);glVertex2i(24,15);
        glVertex2i(23,15);glVertex2i(24,15);
        glVertex2i(23,15);glVertex2f(23,18.5);
        //Logo - Laterales
        glVertex2i(20,21);glVertex2i(19,20);
        glVertex2i(18,20);glVertex2i(19,21);
        glVertex2i(19,21);glVertex2i(20,21);
        glVertex2i(20,21);glVertex2i(22,19);
        glVertex2i(25,21);glVertex2i(24,20);
        glVertex2i(23,20);glVertex2i(24,21);
        glVertex2i(24,21);glVertex2i(25,21);
        glVertex2i(25,21);glVertex2i(25,16);
        glVertex2i(25,16);glVertex2i(24,15);
        glVertex2i(20,16);glVertex2i(19,15);
        glVertex2i(20,16);glVertex2i(20,17);
        glVertex2i(20,16);glVertex2i(23,16);

    glEnd();
}

void metroBus()
{   //ARRIBA
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

        arbol_1();arbol_2();
        arbol_3();pino_1();
        pino_2();arbusto();

        glPushMatrix();
            glTranslated(-1,-1,0);
            glScaled(1.2,1,0);
            cabana();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-2,-2,0);
            palacio();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-9,1,0);
            glScaled(1.6,1.2,0);
            mcdonalds();
        glPopMatrix();

        calle();
        cesped();

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
        poste_luz();
        cerca();

        glPushMatrix();
            glTranslated(b1,b2,0);
            alien();
        glPopMatrix();

        glFlush();


}

void specialkey(int key, int x, int y)
{
    if((xx > -60 and xx < 60)){
        if(key==GLUT_KEY_LEFT|key==GLUT_KEY_DOWN){
            xx=xx-2;
            a+=15;
        }
        else if(key==GLUT_KEY_RIGHT|key==GLUT_KEY_UP){
            xx=xx+2;
            a-=15;
        }
        glutPostRedisplay();}
    else{
        if(xx >= 60)
            xx =-59;
        else if(xx <= -60)
            xx = 59;
    }
}

int main (int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1100,600);
    glutInitWindowPosition(300,100);

    int x = abs((GetSystemMetrics(SM_CXSCREEN)-1100)/2);
    int y = abs((GetSystemMetrics(SM_CYSCREEN)-600)/2);

    glutInitWindowPosition(x,y);

    glutCreateWindow ("Parcial 1 - Castillo, González, Morales, Quiel, Rodríguez, Saldaña");

    iniciarProyeccion();
    glutDisplayFunc(display);
    glutSpecialFunc(specialkey);
    glutTimerFunc(100,timer,0);


    glutMainLoop();
    return 0;
}

