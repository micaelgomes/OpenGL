/**
 * @author micaellgoms
 * 
 * circulo de cores
 */

#include <GL/glut.h>
#include <stdio.h>

#define true 1
#define false 0

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

int ambient = true;
int specular = true;
int diffuse = true;

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

void luzAmbiente(void){
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat posicaoLuz[4]={1.0, 0.0, 1.0, 0.0};

    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

    glClearColor(1,1,1,1);

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void luzDifusa (void){
    GLfloat luzDifusa[4]={0.5,0.5,0.5,0.0};
    GLfloat posicaoLuz[4]={1.0, 0.0, 1.0, 0.0};

    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

    glClearColor(1,1,1,1);

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
}

void luzEspecular(void){
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat posicaoLuz[4]={1.0, 0.0, 1.0, 0.0};

    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

    glClearColor(1,1,1,1);

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuz );

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);
    glEnable(GL_DEPTH_TEST);
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
        if(ambient) ambient = false;
        else ambient = true;
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
        luzAmbiente();
        glutPostRedisplay();
        printf("Ambient\n");
        break;
    case 'k':
        if(specular) specular = false;
        else specular = true;
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        luzEspecular();
        glutPostRedisplay();
        printf("Specular\n");
        break;
    case 'l':
        if(diffuse) diffuse = false;
        else diffuse = true;
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT2);
        luzDifusa();
        glutPostRedisplay();
        printf("Diffuse\n");
        break;
    case '0':
        red = green = blue = 0.0;
        printf("ZERO\n");
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
    gluPerspective(39.0, (GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
    glViewport(0,0,x,y);
}

int main (int argc, char **argv) {
    glutInit(&argc, argv); 
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB); 
    glutCreateWindow("MyApp");
    
    xRotated = yRotated = zRotated = 30.0;
    xRotated = 43;
    yRotated = 50;
 
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(init);
    luzAmbiente();
    glutMainLoop();

    return 0;
}