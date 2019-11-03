int segments = 100;
float start_y = 0,end_y = 200;

float run_ball_speed_x = 8, run_ball_speed_y = -4;
float run_offset_y = 100;


void reset_runs(){
    run_ball_speed_x = 8, run_ball_speed_y = -4;
}

void drawBall(){
    // ball in thrown state
    glColor3f( 1 , 0 , 0.15 );
    drawFilledCircle( ballposx , ballposy , 8 );

    if(ballposx >= 799)
    {
        reset_runs();
        app_state = 1;
    }
}


void drawCurveLine(){
    // draw 6 line
    for(float tempy = 0;tempy<=segments;tempy++)
    {
        float tval = tempy/segments;
        glColor3f(1,1,1);
        glPointSize(3);
        float x_offset = getBez4( 650,  750 , 750 , 650 ,tval);
        float y_offset = getBez4( 0,  75 , 125 , 200 ,tval);
        glBegin(GL_POINTS);
            glVertex2f( x_offset,y_offset);
        glEnd();
    }
    load_default();
}

void moveBall(){
    ballposx += run_ball_speed_x;
    ballposy += run_ball_speed_y;

    if(ballposy <= run_offset_y){
        run_ball_speed_y = 4;
        ballposy += run_ball_speed_y;
    }
}

void draw_scene(){
    
    drawSkyBackground();

    // draw ground
    glColor3f(0,0.75,0.2);
    drawSquareP(0,200,800,0);

    drawStadium(0);

    drawCurveLine();

    drawBall();

    moveBall();
    

    load_default();
}

void draw_runs(){
    draw_scene();

    glutPostRedisplay();
}



int handleRunKey(unsigned char key){
    if(key == 's' || key =='S')
    {
        return 1;
    }
    return 2;
}   