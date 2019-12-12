/**
 * @author micaellgoms
 * 
 * circulo de cores
 */

#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;

static float red = 0.0, green = 1.0, blue = 0.0;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 100.0f }; 

GLfloat none[] = { 0.0f, 0.0f, 0.0f, 0.0f };

void display() {

    // glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glColor3d(red, green, blue); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    // glScalef(1.0,1.0,1.0);// scaling transfomation 

    glPushMatrix();
    glTranslated(0.0,0.0,0.0);
    glutSolidSphere(radius,50,50);
    glPopMatrix(); 
    
    glutSwapBuffers();

    glFlush(); 
   
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
    case 'a':
        if(red < 1.0) red = red + 0.05;
        else red = 0.0;
        if(xRotated < 360.0) xRotated = xRotated + 10.0;
        else xRotated = 0.0;
        break;
    case 's':
        if(green < 1.0) green = green + 0.05;
        else green = 0.0;
        if(yRotated < 360.0) yRotated = yRotated + 10.0;
        else yRotated = 0.0;
        break;
    case 'd':
        if(blue < 1.0) blue = blue + 0.05;
        else blue = 0.0;
        if(zRotated < 360.0) zRotated = zRotated + 10.0;
        else zRotated = 0.0;
        break;
    case 'A':
        if(red > 0.0) red = red - 0.05;
        else red = 1.0;
        if(xRotated > 0.0) xRotated = xRotated - 10.0;
        else xRotated = 360.0;
        break;
    case 'S':
        if(green > 0.0) green = green - 0.05;
        else green = 1.0;
        if(yRotated > 0.0) yRotated = yRotated - 10.0;
        else yRotated = 360.0;
        break;
    case 'D':
        if(blue > 0.0) blue = blue - 0.05;
        else blue = 1.0;
        if(zRotated > 0.0) zRotated = zRotated - 10.0;
        else zRotated = 360.0;
        break;
    case 'j':
        // glDisable(GL_LIGHT0);
        

        glLightfv(GL_LIGHT0, GL_AMBIENT, none);
        glMaterialfv(GL_FRONT, GL_AMBIENT, none);

        glEnable(GL_LIGHT0);
        break;
    case 'k':
        break;
    case 'l':
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
  }
  glutPostRedisplay();
}

void init(int x, int y) {
    if (y == 0 || x == 0) return;   
    
    glClearColor (1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
    glViewport(0,0,x,y);

    // set Light
    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); 
 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
 
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

}

int main (int argc, char **argv) {
    glutInit(&argc, argv); 
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
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