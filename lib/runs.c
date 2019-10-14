void draw_scene(){
    // draw ground
    glColor3f(0,0.75,0.2);
    drawSquareP(0,200,800,0);

    drawStadium(0);

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