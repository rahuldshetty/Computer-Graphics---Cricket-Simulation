void drawArms(int a,int b){
    // left arm
    drawLine( a  + 40, b + 92 , a + 10  , 70 + b  );
    //right arm
    drawLine( a  + 40, b + 82 , a + 10  , 60 + b  );

    // bat handle
    glBegin(GL_POLYGON);
        glColor3f(0.64,0.164,0.164);
        glVertex2f(a+7,b+57);
        glVertex2f(a+7,b+73);
        glVertex2f(a+13,b+73);
        glVertex2f(a+13,b+57);
        glColor3f(0,0,0);
    glEnd();

    // bat stick
    glBegin(GL_POLYGON);
        glColor3f(0.64,0.164,0.164);
        glVertex2f(a+13,b+57);
        glVertex2f(a+18,b+53);
        glVertex2f(a+18,b-5);
        glVertex2f(a+2,b-5);
        glVertex2f(a+2,b+53);
        glVertex2f(a+7,b+57);
        glColor3f(0,0,0);
    glEnd();

}

void drawBody(int a,int b){
    GLfloat x = 60 + a , y = 148 + b;
    // head
    drawHollowCircle( x + 40 ,117 + y,25);

    // torso
    drawLine(x + 40, y + 92 , x + 40, 42 + y );

    // legs
    drawLine( x , y, x + 40, y + 42 );
    drawLine( x + 70 , y  , x + 40, y + 42 );    

    drawArms(x,y);

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
    glColor3f(0,0.8,0.2);
    drawSquareP(0,148,600,0);
    

    drawBody(0,0);
}

