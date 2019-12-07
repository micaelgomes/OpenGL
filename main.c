/**
 * @author micaellgoms
 * 
 * circulo de cores
 */

#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;

static float red = 0.0, green = 0.0, blue = 0.0;

void display() {

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(red, green, blue); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);// scaling transfomation 
    glutSolidSphere(radius,50,50);
    
    glFlush(); 
   
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
    case 'a':
        if(red >= 0.0 && red <= 1.0) red = red + 0.05;
        if(xRotated >= 0.0 && xRotated <= 360.0) xRotated = xRotated + 10.0;
        glutPostRedisplay();
        break;
    case 's':
        if(green >= 0.0 && green <= 1.0) green = green + 0.05;
        if(yRotated >= 0.0 && yRotated <= 360.0) yRotated = yRotated + 10.0;
        glutPostRedisplay();
        break;
    case 'd':
        if(blue >= 0.0 && blue <= 1.0) blue = blue + 0.05;
        if(zRotated >= 0.0 && zRotated <= 360.0) zRotated = zRotated + 10.0;
        glutPostRedisplay();
        break;
    case 'A':
        if(red >= 0.0 && red <= 1.0) red = red - 0.05;
        if(xRotated >= 0.0 && xRotated <= 360.0) xRotated = xRotated - 10.0;
        glutPostRedisplay();
        break;
    case 'S':
        if(green >= 0.0 && green <= 1.0) green = green - 0.05;
        if(yRotated >= 0.0 && yRotated <= 360.0) yRotated = yRotated - 10.0;
        glutPostRedisplay();
        break;
    case 'D':
        if(blue >= 0.0 && blue <= 1.0) blue = blue - 0.05;
        if(zRotated >= 0.0 && zRotated <= 360.0) zRotated = zRotated - 10.0;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
  }
}

void init(int x, int y) {
    if (y == 0 || x == 0) return;   
    
    glClearColor (1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

int main (int argc, char **argv) {
    glutInit(&argc, argv); 
    glutInitWindowSize(500,500);
    glutCreateWindow("MyApp");
    
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;
 
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(init);
    glutMainLoop();
    return 0;
}