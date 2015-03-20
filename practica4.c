#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>

// ----------------------------------------------------------
// Prototipos de función
// ----------------------------------------------------------
void display();
void specialKeys();
 
// ----------------------------------------------------------
// Variables globales
// ----------------------------------------------------------
double rotate_y=0; 
double rotate_x=0;
double rotate_z=0; 

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
// ----------------------------------------------------------
// Función de retrollamada "display()"
// ----------------------------------------------------------
void display(){
 
  //  Borrar pantalla y Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  
  glLoadIdentity();
 
  // Otras transformaciones
  //glTranslatef( 0.1, 0.0, 0.0 );      // No incluido
   //glRotatef( 180, 0.0, 1.0, 0.0 );    // No incluido
 
  // Rotar cuando el usuario cambie "rotate_x" y "rotate_y"
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef(rotate_z, 0.0, 0.0, 1.0 );
  glTranslatef(X, Y, Z); 
  
      glScalef(scale, scale, scale);
 
  //Lado Frontal: Unión de 4 colores: Blanco, Amarillo, Azul y Rojo
  glBegin(GL_POLYGON);
 
  glColor3f(   1.0,  1.0, 1.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // Blanco
  glColor3f(   1.0,  1.0,  0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // Amarillo
  glColor3f(   0.0,  0.0,  1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // Azul
  glColor3f(   1.0,  0.0,  0.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // Rojo
 
  glEnd();
 
  // Lado trasero: Blanco
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 
  // Lado derecho: Verde
  glBegin(GL_POLYGON);
  glColor3f(  0.0,  1.0,  0.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  // Lado izquierdo: Amarillo
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // Lado superior: Azul
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  // Lado inferior: Rojo
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  glFlush();
  glutSwapBuffers();
 
}
 
// ----------------------------------------------------------
// Función de retrollamada "specialKeys()" 
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
  //  Flecha derecha del teclado: aumentar rotación 7 grados
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 7;
 
  //  Flecha izquierda del teclado: disminuir rotación 7 grados
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 7;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 7;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 7;
    
  else if (key == GLUT_KEY_F2)
    rotate_z += 7;

  else if (key == GLUT_KEY_F2)
    rotate_z -= 7;

  //  Solicitar actualización de visualización
  glutPostRedisplay();
 
}

 void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        scale=0.5;
        break;
    case 'S':
        scale=1.5;
        break;
    case 'X' :
        X += 0.1f;
        break;
    case 'x' :
        X -= 0.1f;
        break;
    case 'y' :
        Y -= 0.1f;
        break;
    case 'Y' :
        Y += 0.1f;
        break;
    case 'z':
        Z += 0.1f;
        break;
    case 'Z':
        Z -= 0.1f;
        break;
    case 27 :
        exit(0);			// Salir del programa
    }

    glutPostRedisplay();		  // actualización de visualización
}
// ----------------------------------------------------------
// Función "main()"
// ----------------------------------------------------------
int main(int argc, char* argv[]){
 
  //  Inicializar los parámetros GLUT y de usuario proceso
  glutInit(&argc,argv);
 
  //  Solicitar ventana con color real y doble buffer con Z-buffer 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Crear ventana con el nombre de ella en la barra de título
  glutCreateWindow("Práctica 4 - Cubo Tridimensional");
 
  //  Habilitar la prueba de profundidad de Z-buffer
  glEnable(GL_DEPTH_TEST);
 
  // Funciones de retrollamada
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
 glutKeyboardFunc(keyboard); //invoca funciones de teclado
  //  Pasar el control de eventos a GLUT
  glutMainLoop();
 
  //  Regresar al sistema operativo
  return 0;
 
}

