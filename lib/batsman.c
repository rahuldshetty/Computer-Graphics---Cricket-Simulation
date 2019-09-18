
void drawGround(float x1,float y1,float x2,float y2){
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
}

void drawBatsman(){
    glColor3f(1.0,0.0,0.0);
    
    //drawing texts
    char title[] = "You are Batting now.";
    void *font = GLUT_BITMAP_HELVETICA_18; 
    int HGAP_USN_NAME = 180;    
    int VGAP_ROW = 40;
    drawBitmapText(title, 230  , 580  , 0, font);

    // draw ground
    glColor3f(0,0,0);
    drawGround(0,200,600,200);
    drawGround(0,198,600,198);

}