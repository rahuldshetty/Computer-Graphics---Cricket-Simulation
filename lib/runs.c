
void draw_runs(){
    
    glutPostRedisplay();
}


int handleRunKey(unsigned char key){
    if(key == 's' || key =='S')
    {
        return 1;
    }
    return 2;
}   