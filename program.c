#define PI 3.142

#include <stdio.h>
#include <GL/glut.h>
#include<math.h>
#include "lib/util.c"
#include "lib/menu.c"
#include "lib/batsman.c"

const int WINDOW_HEIGHT = 600 , WINDOW_WIDTH = 600;

int app_state = 0;

GLvoid display(){
    glClear(GL_COLOR_BUFFER_BIT);

    switch (app_state)
    {
    case 0:
         drawMenu();
        break;

    case 1:
        drawBatsman();
        break;

    case 2:

        break;
    
    default:
        break;
    }
   

    glFlush();
}

void keyboard(unsigned char key,int x,int y){
    switch (app_state)
    {
    case 0:
        // handle all menu keys
        app_state = handleMenuKey(key);
        glutPostRedisplay();
        break;
    
    default:
        break;
    }
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
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}