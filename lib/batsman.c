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


// rotation of arm(s)
float theta = 0, rot_speed = 2;
float ballposx = 0, ballposy=0;
float ballspeedx = -4, ballspeedy = -2;
int isthrown = 0;
float offsety = 0;
void drawBowlerArms(int a,int b){
    // left arm
    drawLine( a  + 40, b + 92 , a + 10  , 70 + b  );
    
    float rightArmXEnd = a + 40 + 30 ;
    float rightArmYEnd = 70 + b ;

    float tx = getXAfterRotation(rightArmXEnd, rightArmYEnd, a  + 40, b + 92, theta);
    float ty = getYAfterRotation(rightArmXEnd, rightArmYEnd, a  + 40, b + 92, theta);
    
    //right arm
    drawLine( a  + 40, b + 92 , tx  , ty  );

    if(isthrown==0){
        if(theta!=0 && theta <= 250 )
        {
            theta += rot_speed;
            // draw small bowl
            glColor3f( 1 , 0 , 0.15 );
            drawFilledCircle( tx , ty , 8 );
        }
        else if(theta>250){
            // throw the ball
            theta = 0;
            isthrown = 1;
            ballposx = tx;
            ballposy = ty;
            offsety = ty - 0.5 ;
        }
        else{
            theta = 0;
            // draw small bowl
            glColor3f( 1 , 0 , 0.15 );
            drawFilledCircle( tx , ty , 8 );
        }
    }
    else{
        // ball in thrown state
        glColor3f( 1 , 0 , 0.15 );
        drawFilledCircle( ballposx , ballposy , 8 );
        ballposx+= ballspeedx;
        ballposy+= ballspeedy;
        if(ballposy <= 150){
            ballspeedy = 2;
        }
        else if(ballposy >= offsety )
        {
            offsety -= 1.9;
            ballspeedy = -2;
        }

    
        if(ballposx <= 10 ){
            // reset if gone behind
            // test purpose
            isthrown = 0;
        }   

    }
    
}

// components to handle movement of bowler on key press
float bowler_x_speed = 0, bowler_y_speed = 0,factor = 0.8;
float leftLeg  = 0, rightLeg = 0;
int rotateLegs = 0,lowlimit = 300 * (0.2/factor) ,uplimit = 750 * (0.2/factor);

void drawBowler(int a,int b){
    GLfloat x = 720 + a + bowler_x_speed , y = 148 + b + bowler_y_speed;
    // head
    drawHollowCircle( x + 40 ,117 + y,25);

    // torso
    drawLine(x + 40, y + 92 , x + 40, 42 + y );

    // legs
    drawLine( x + leftLeg, y, x + 40, y + 42 );
    drawLine( x + 70 + rightLeg , y  , x + 40, y + 42 );    

    drawBowlerArms(x,y);

    if( 720 + a + bowler_x_speed <= 600)
    {
        // when the bowler reaches the crease
        bowler_x_speed = 0.0;
        leftLeg = 0;
        rightLeg = 0;
        rotateLegs = 0;
    }
    else if( bowler_x_speed <= -factor)
    {
        bowler_x_speed -= factor;
        if(  rotateLegs <= lowlimit  )
        {
            leftLeg += factor;
            rightLeg -= factor;
        }   
        else if(rotateLegs < uplimit  )
        {
            leftLeg -= factor; 
            rightLeg += factor;
        }
        else if(rotateLegs >= uplimit)
        {
            rotateLegs = 0 ; 
            leftLeg += factor;
            rightLeg -= factor;
        }
        rotateLegs += 1 ;
      

    }
        
    glutPostRedisplay();
}

void drawLights(int x,int y)
{
    int dx = 10, dy=10;
    int rows = 10,cols = 10;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
        {
            glColor3f(0,0,0);
            glLineWidth(1.4);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x + dx*i , y - dy*j );
                glVertex2f(x + dx*(i+1) , y - dy*j );
                glVertex2f(x + dx*(i+1) , y - dy*(j+1)  );
                glVertex2f(x + dx*i , y - dy*(j+1) );
            glEnd();            
        }
    
    glColor3f(0,0,0);
    drawSquareP( x + (cols/2)*dx - 10 , y - (rows*dy), x + (cols/2)*dx + 10 , 400  );

    load_default();
}

clock_t oldstring = clock();
void drawStrings(){

    if( conv2seconds(clock() - oldstring ) < 0.5  )
    {
        glColor3f(1,1,1);
    }   
    else if( conv2seconds(clock() - oldstring) < 1 ){
        glColor3f(0.5,0.5,0.5);
    }
    else {
        oldstring = clock();
    }


    void *fontMenu = GLUT_BITMAP_9_BY_15;
    char match_name[] = "INDIA VS ENGLAND";
    unsigned char string[] = "INDIA VS ENGLAND";
    int size_string = glutBitmapLength(fontMenu, string);
    float newloc = 250 + (150 - size_string/2.0  );
    drawBitmapText(match_name, newloc, 450  ,0,fontMenu);
    load_default(); 
}

void drawStadium(){

    // gray background
    glColor3f(0.75,0.75,0.75);
    drawSquareP(0,400,800,200);

    //box cooordinated: TL:(250,500) BR:(550,350)

    // board
    glColor3f(0.2,0.2,0.2);
    drawSquareP(245,505,555,345);
    glColor3f(0,0,0);
    drawSquareP(250,500,550,350);

    // blinking text effect
    drawStrings();

    // draw ligths
    drawLights(80,550);
    drawLights(635,550);
}


void drawBatsman(){
    glColor3f(1.0,0.0,0.0);
    

    // draw ground
    glColor3f(0,0.75,0.2);
    drawSquareP(0,200,800,0);

    // draw 6 line
    glColor3f(1,1,1);
    glLineWidth(1);
    drawLine(0,195,800,195);
    
    // drawing back stadium
    drawStadium();


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


int handleGameKey(unsigned char key){
    if(key == 's' || key =='S')
    {
        bowler_x_speed -= factor;
        theta += rot_speed;
    }
    return 1;
}