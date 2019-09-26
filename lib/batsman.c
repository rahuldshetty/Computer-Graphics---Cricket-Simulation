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

void drawBatter(int a,int b){
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



void drawWicket(int x,int y){
    float width = 3.9;
    glLineWidth(width);
    drawLine( 50 + x, y + 148 , x + 50 , y + 215 );
    glLineWidth(width);
    drawLine( 58 + x, y + 148 + 5 , x + 58 , y + 215 + 5 );
    glLineWidth(width);
    drawLine( 66 + x, y + 148 + 10 , x + 66 , y + 215 + 10 );

    glLineWidth(width-1.2);
    drawLine( 50 + x, y + 215  , x + 66 , y + 215 + 10 );
}

void drawBowlerArms(int a,int b){
    // left arm
    drawLine( a  + 40, b + 92 , a + 10  , 70 + b  );
    //right arm
    drawLine( a  + 40, b + 92 , a + 40 + 30  , 70 + b  );

    // draw small bowl
    glColor3f( 1 , 0 , 0.15 );
    drawFilledCircle( a + 40 + 30 , b + 70 , 8 );

}

void drawBowler(int a,int b){
    GLfloat x = 720 + a , y = 148 + b;
    // head
    drawHollowCircle( x + 40 ,117 + y,25);

    // torso
    drawLine(x + 40, y + 92 , x + 40, 42 + y );

    // legs
    drawLine( x , y, x + 40, y + 42 );
    drawLine( x + 70 , y  , x + 40, y + 42 );    

    drawBowlerArms(x,y);
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
    glColor3f(0,0.75,0.2);
    drawSquareP(0,200,800,0);

    // draw pit
    float points[][2] = { { 15,160 },{4,125},{739,125},{750,160} };
    glColor3f(0.933,0.785,0.542);
    drawPolygon(points,4);

    //drawing the white crease
    glColor3f(1,1,1);
    glLineWidth(2.5);
    drawLine(70,160,60,125);
    glColor3f(1,1,1);
    glLineWidth(2.5);
    drawLine(640,160,630,125);
    
    // batsman wicket
    drawWicket(-15,0);
    //bowler wicket
    drawWicket(640,0);

    drawBatter(0,0);

    drawBowler(0,0);
    


}

