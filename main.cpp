#include<GL/glut.h>

#include<GL/freeglut.h>

#include<stdlib.h>

#include<stdio.h>



GLfloat distance = 4;

GLfloat speedBase = 0.5;

GLfloat azimuth = 0;

GLfloat incidence = 0;

GLfloat twist = 0;

GLfloat lightPosition[4]={600, 600.0, 600.0, 600};


void polarView(GLfloat distance, GLfloat azimuth, GLfloat incidence, GLfloat twist) {

	glTranslatef(0.0, 0.0, -distance);

	glRotatef(-twist, 0.0, 0.0, 1.0);

	glRotatef(-incidence, 1.0, 0.0, 0.0);

	glRotatef(-azimuth, 0.0, 0.0, 1.0);

}

void carBody(){
    glColor3f(0, 1.0, 0);

    glCullFace(GL_BACK);
    glBegin(GL_QUADS);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);
    glEnd();

    glColor3f(0, 0, 0);
    glCullFace(GL_BACK);
    glBegin(GL_QUADS);			// Face frontal
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.0, -1.0, -1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

    glColor3f(0, 1.0, 0);
    glCullFace(GL_BACK);
    glBegin(GL_QUADS);			// Face lateral esquerda
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(-1.0, -1.0, 1.0);
    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS);			// Face lateral direita
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(1.0, -1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS);			// Face superior
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS);			// Face inferior
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(1.0, -1.0, -1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
}

void carTire(double a){
    glRotated(-a,0,0,1);
    glColor3f(1, 1, 1);
    glCullFace(GL_BACK);
    glutWireTorus (0.250, 0.35, 8, 15);
}

void carFront(){

    glCullFace(GL_BACK);
    glBegin(GL_QUADS); //traseira
        glVertex3f(1.0, 1.0, -1);
        glVertex3f(-1.0, 1.0, -1);
        glVertex3f(-1.0, 1.0, 0.3);
        glVertex3f(1.0, 1.0, 0.3);
    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS); //frente do carro
        glVertex3f(1.0, 2.0, -1.0);
        glVertex3f(-1.0, 2.0, -1.0);
        glVertex3f(-1.0, 2.0, 0.3);
        glVertex3f(1.0, 2.0, 0.3);

    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS); //lateral esquerda
        glVertex3f(-1.0, 2.0, -1);
        glVertex3f(-1.0, 1.0, -1);
        glVertex3f(-1.0, 1.0, 0.3);
        glVertex3f(-1.0, 2.0, 0.3);
    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS); //lateral direita
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.0, 2.0, -1.0);
        glVertex3f(1.0, 2.0, 0.3);
        glVertex3f(1.0, 1.0, 0.3);
    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS); //topo
        glVertex3f(1.0, 2.0, 0.3);
        glVertex3f(-1.0, 2.0, 0.3);
        glVertex3f(-1,1,0.3);
        glVertex3f(1,1,0.3);
    glEnd();

    glCullFace(GL_BACK);
    glBegin(GL_QUADS); //embaixo
        glVertex3f(1.0, 2.0, -1);
        glVertex3f(-1.0, 2.0, -1);
        glVertex3f(-1.0, 1.0, -1);
        glVertex3f(1,1,-1);
    glEnd();


}


void sun(double a){

    GLfloat   defaultEmission[] = { 0.0, 0.0, 0.0, 1.0 };

    glCullFace(GL_BACK);

    glEnable( GL_LIGHTING );
    glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, defaultEmission );


    glRotatef(a * 0.3, 3, -3, -1);
    glTranslatef(-1, 10, 1.0);
    glColor3f( 1.0, 1.0, 1.0 );
    glLightfv( GL_LIGHT0, GL_POSITION, lightPosition );
    glutSolidSphere( 1, 30, 30 );

}

void floor(){
      glColor3f(1.0, 1.0, 1.0);
    glRotatef( 1 ,1, 90, 0 );

    glBegin(GL_LINES);
        for (GLfloat i = -30; i <= 30; i += 0.25) {
                glCullFace(GL_BACK);
            glVertex3f(i, 30, -1.8);
                glCullFace(GL_BACK);
            glVertex3f(i, -30, -1.8);
                glCullFace(GL_BACK);
            glVertex3f(30, i, -1.8 );
                glCullFace(GL_BACK);
            glVertex3f(-30, i, -1.8);
        }
    glEnd();
}


void display()

{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   GLfloat speed = 0.0;
   const double a = glutGet(GLUT_ELAPSED_TIME)/100;

   glPushMatrix();

          polarView(distance, azimuth, incidence, twist);

          glPushMatrix();
            floor();
          glPopMatrix();

          glPushMatrix();
            sun(a);
          glPopMatrix();
          speed = speedBase + a * 0.01;
          glPushMatrix();
               glTranslatef( 0, speed, 0);
               carBody();
               carFront();

               glPushMatrix(); //esquerda atras

                    glRotatef( 90.0 , 20.0, 380.0, 1.0 );
                    glTranslatef( 1.2, -0.5, -1.0);
                    carTire(speed * 3);
               glPopMatrix();

               glPushMatrix(); //esquerda frente
                    glRotatef( 90.0 , 20.0, 380.0, 1.0 );
                    glTranslatef( 1.2, 1.5, -1.0);
                    carTire(speed * 3);
               glPopMatrix();

               glPushMatrix(); //direita frente
                    glRotatef( 90.0 , 20.0, 380.0, 1.0 );
                    glTranslatef( 1.2, 1.5, 1.0);
                    carTire(speed * 3);
               glPopMatrix();

               glPushMatrix(); //direita atras
                    glRotatef( 90.0 , 20.0, 380.0, 1.0 );
                    glTranslatef( 1.2, -0.5, 1.0);
                    carTire(speed * 3);
               glPopMatrix();
          glPopMatrix();

    glPopMatrix();


    glutSwapBuffers();

}



void myReshape(int winWidth, int winHeight) // reshape window

{

    int tam = winWidth < winHeight ? winWidth : winHeight;

    glViewport(0, 0, tam, tam);

}



void myKeyboard(unsigned char c, int x, int y)

{



    switch(c){

        case  27: exit(0);          break; // ESC

        case 'a': azimuth   -= 0.8; break;

        case 'd': azimuth   += 0.8; break;

        case 'w': incidence -= 0.8; break;

        case 's': incidence += 0.8; break;

        case 'q': twist     -= 0.8; break;

        case 'e': twist     += 0.8; break;

        case 'z': distance  -= 0.1; break;

        case 'x': distance  += 0.1; break;

        case 'v': speedBase += 0.2; break;
    }

    glutPostRedisplay();

}



void keySpecial(int key, int x, int y) {

    //printf("(%d, %d)\n", x, y);

    switch(key){

        case GLUT_KEY_LEFT:  azimuth -=0.8;   break;

        case GLUT_KEY_RIGHT: azimuth +=0.8;   break;

        case GLUT_KEY_UP:    incidence -=0.8; break;

        case GLUT_KEY_DOWN:  incidence +=0.8; break;

    }

    glutPostRedisplay();

}



void myMouse(int b, int s, int x, int y)

{

    switch(b){

        case GLUT_LEFT_BUTTON:

            printf("(%d, %d)\n", x, y);

    }

}



void myMotion(int x, int y){

    printf("Motion: (%d, %d)\n", x, y);

}



// Rotina Callback chamada quando nao ocorre nenhum evento

void idle(){

    glutPostRedisplay(); // Solicita redesenho da tela

}


void initgfx( )
{
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glEnable( GL_DEPTH_TEST );



    /* Turn on a default light */
    glEnable( GL_LIGHT0 );
}

void init()

{

      glEnable(GL_COLOR_MATERIAL);

 	//Habilita o uso de iluminação

 	glEnable(GL_LIGHTING);

 	// Habilita a luz de número 0

 	glEnable(GL_LIGHT0);

 	// Habilita o depth-buffering

 	glEnable(GL_DEPTH_TEST);



 	// Habilita o modelo de colorização de Gouraud

 	glShadeModel(GL_SMOOTH);
     /* Define a cor de fundo (preto) */

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_CULL_FACE);

    /* Inicializa as Matrizes do OpenGL */

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(-10, 10, -10, 10, -10, 10);

    gluPerspective(45, 10, 10, 10);

    glMatrixMode(GL_MODELVIEW);

}



int main(int argc, char** argv)

{





	glutInit(&argc, argv);

     glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH );

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Trabalho final");

    init();



	// Registro de Rotinas Callback

    glutDisplayFunc(display);

    glutReshapeFunc(myReshape);

    glutKeyboardFunc(myKeyboard);

    glutSpecialFunc(keySpecial);

    glutMouseFunc(myMouse);

    glutMotionFunc(myMotion);

    glutIdleFunc(idle);



	// Loop principal

    glutMainLoop();



    return 0;

}

