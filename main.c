/**
 * @author micaellgoms
 * 
 * circulo de cores
 */

#include <GL/glut.h>
#include <stdlib.h> 

#define true 1
#define false 0

GLdouble radius=1, side=50, angle, fAspect;

int perspective = true;

GLfloat eyex=40, eyey=260, eyez=100, centrox, centroy, centroz;

static float red = 0.0, green = 0.0, blue = 0.0;

void displayPerspectiva() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(angle, fAspect, 0.5, 500);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glColor3f(red, green, blue); 
    
    gluLookAt(eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // glScalef(1.0,1.0,1.0);// scaling transfomation 
    glutWireCube(side);
    
    glFlush(); 
}

void displayOrtogonal() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-65.0, 65.0, -65.0, 65.0, -400.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glColor3f(red, green, blue); 
    
    gluLookAt(eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // glScalef(1.0,1.0,1.0);// scaling transfomation 
    glutWireCube(side);
    
    glFlush(); 
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if(perspective)
        displayPerspectiva();
    else
        displayOrtogonal();
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
    case 'a':
        if(red <= 1.0) red = red + 0.05;
        else red = 0.0;

        eyex -= 10;
        if(eyex < -340) eyex = 340;
        
        glLoadIdentity();
        gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
        glutPostRedisplay();
        break;
    case 's':
        if(green <= 1.0) green = green + 0.05;
        else green = 0.0; 
        
        eyey -= 10.0;
        if(eyey < -260) eyey = 260;

        glLoadIdentity();
        gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
        glutPostRedisplay();
        break;
    case 'd':
        if(blue <= 1.0) blue = blue + 0.05;
        else blue = 0.0;

        eyex += 10;
        if(eyex > 340) eyex = -340;
        
        glLoadIdentity();
        gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
        glutPostRedisplay();
        break;
    case 'w':
        if(blue <= 1.0) blue = blue + 0.05;
        else blue = 0.0;

        eyey += 10;
        if(eyey > 260) eyey = -260;
    
        glLoadIdentity();
        gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
        glutPostRedisplay();
        break;
    case 'p':
        perspective = true;
        break;
    case 'o':
        perspective = false;
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
  }
}

void init(void) {
    glClearColor (1.0, 1.0, 1.0, 1.0);
    eyex = 0.0;
	eyey = 0.0;
	eyez = 5.0;
	centrox = 0.0;
	centroy = 0.0;
	centroz = 0.0;
    angle = 45;
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    fAspect = (GLfloat)w/(GLfloat)h;
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("MyApp");    
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}