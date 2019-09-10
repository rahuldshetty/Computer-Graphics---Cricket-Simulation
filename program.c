#include <stdio.h>
#include <GL/glut.h>
#include "lib/util.c"
#include "lib/menu.c"

const int WINDOW_HEIGHT = 600 , WINDOW_WIDTH = 600;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawMenu();

    glFlush();
}


void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,600.0,0.0,600.0);
}


int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Cricket Simulator");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);  
    init();
    glutMainLoop();
    return 0;
}