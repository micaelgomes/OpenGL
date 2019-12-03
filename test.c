#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void drawStar(){
    glColor3f(1, 0, 0);

    glBegin(GL_LINE_LOOP); 
    glVertex3f(0.2,0.7,0.0);
    glVertex3f(0.35,0.7,0.0);
    glVertex3f(0.45,0.8,0.0);
    glVertex3f(0.55,0.7,0.0);
    glVertex3f(0.7,0.7,0.0);
    glVertex3f(0.6,0.6,0.0);
    glVertex3f(0.65,0.4,0.0);
    glVertex3f(0.45,0.5,0.0);
    glVertex3f(0.25,0.4,0.0);
    glVertex3f(0.3,0.6,0.0);

    glEnd();
}

void drawSquare(float x, float y, float size){
    glColor3f(0.0,0.0,1.0);

    glBegin(GL_POLYGON);
    glVertex3f(x, y, 0);
    glVertex3f(x+size, y, 0);
    glVertex3f(x+size, y+size, 0);
    glVertex3f(x, y+size, 0);  
    glEnd();
}

void drawTriangle(){
    glColor3f(0.0, 1.0, 0.0);
    
    glBegin(GL_TRIANGLES);
    glVertex3f(0.37, 0.98, 0);
    glVertex3f(0.3, 0.9, 0);
    glVertex3f(0.45, 0.9, 0);
    glEnd();
}

void drawHouse(){
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.05, 0.05, 0);
    glVertex3f(0.3, 0.05, 0);
    glVertex3f(0.3, 0.3, 0);
    glVertex3f(0.05, 0.3, 0);  
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.17, 0.4, 0);
    glVertex3f(0.05, 0.3, 0);
    glVertex3f(0.3, 0.3, 0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.07, 0.05, 0);
    glVertex3f(0.17, 0.05, 0);
    glVertex3f(0.17, 0.17, 0);
    glVertex3f(0.07, 0.17, 0);  
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.1, 0);
    glVertex3f(0.28, 0.1, 0);
    glVertex3f(0.28, 0.17, 0);
    glVertex3f(0.2, 0.17, 0);  
    glEnd();
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 1.0, 0, 1.0, -1, 1);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    drawSquare(0.05, 0.85, 0.1);
    drawTriangle();
    drawStar();
    drawHouse();
        
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutCreateWindow("MyApp");
    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}