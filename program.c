#define PI 3.142

#include <stdio.h>
#include <time.h> 
#include<math.h>
#include <stdlib.h> 

#include <GL/glut.h>

int app_state = 0;
int runs = 0, wickets = 0,target_score = 0;

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,800.0,0.0,800.0);    
    target_score = rand()%50;
    wickets = 0;
    runs = 0;
    app_state = 0;
}

void restart_game(){
    target_score = rand()%50;
    wickets = 0;
    runs = 0;
    app_state = 1;
}

#include "lib/util.c"
#include "lib/menu.c"
#include "lib/batsman.c"
#include "lib/runs.c"

const int WINDOW_HEIGHT = 800 , WINDOW_WIDTH = 800;



GLvoid display(){
    glClear(GL_COLOR_BUFFER_BIT);
    switch (app_state)
    {
        case 0:
            // to draw the initial scene
            drawMenu();
            break;

        case 1:
            // to draw the batting scene
            drawBatsman();
            break;
        
        case 2:
            // to draw the scene of taking 4 or 6
            draw_runs();
            break;

        default:
            break;
    }
    glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y){
    switch (app_state)
    {
    case 0:
        // handle all menu keys
        app_state = handleMenuKey(key);
        glutPostRedisplay();
        break;
    
    case 1:
        app_state = handleGameKey(key);
        glutPostRedisplay();
        break;
    
    case 2:
        app_state = handleRunKey(key);
        glutPostRedisplay();
        break;

    default:
        break;
    }
}





int main(int argc,char** argv){
    srand(time(0)); 

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Cricket Simulation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);  
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}