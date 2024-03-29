float batterwidth = 4;
float bowlerwidth = 4;

// bowl movements
float theta = 0, rot_speed = 2;
float ballposx = 0, ballposy=0;
float ballspeedx = -8, ballspeedy = -2;
int isthrown = 0;
float offsety = 0;

// batter arm movement
float bat_theta = 0;
float const_bat_add = 1.25;
int called_one = 0;
float max_bat_angle = 150;

// components to handle movement of bowler on key press
float bowler_x_speed = 0, bowler_y_speed = 0,factor = 0.8;
float leftLeg  = 0, rightLeg = 0;
int rotateLegs = 0,lowlimit = 300 * (0.2/factor) ,uplimit = 750 * (0.2/factor);

// run components
int taking_run = 0;
float batter_x_speed=0;
float batter_factor = 1.2;
float bleftLeg  = 0, brightLeg = 0, brotateLegs = 0;
float blowlimit =  300 * (0.2/batter_factor) ,buplimit =  600 * (0.2/batter_factor);

// wicket fall
int wicket_offset_1 = 0, wicket_offset_2=0,wicket_offset_3=0;
int is_out = 0,game_over = 0;

clock_t oldstring = clock();

//key check
char old_key;

void drawArms(int a,int b){
    // left arm
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    float tempvar1 = getXAfterRotation( a + 10, 70 + b, a  + 40, b + 92, bat_theta );
    float tempvar2 = getYAfterRotation( a + 10, 70 + b, a  + 40, b + 92, bat_theta );
    drawLine( a  + 40, b + 92 , tempvar1  , tempvar2  );
    
    
    //right arm
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    tempvar1 = getXAfterRotation( a + 10, 60 + b, a  + 40, b + 82, bat_theta );
    tempvar2 = getYAfterRotation( a + 10, 60 + b, a  + 40, b + 82, bat_theta );
    drawLine( a  + 40, b + 82 , tempvar1  , tempvar2  );

    // bat handle
    float ax07 = getXAfterRotation( a + 7, 57 + b, a  + 40, b + 82, bat_theta );
    float ay07 = getYAfterRotation( a + 7, 57 + b, a  + 40, b + 82, bat_theta );

    float ax17 = getXAfterRotation( a + 7, 73 + b, a  + 40, b + 82, bat_theta );
    float ay173 = getYAfterRotation( a + 7, 73 + b, a  + 40, b + 82, bat_theta );
    
    float ax213 = getXAfterRotation( a + 13, 73 + b, a  + 40, b + 82, bat_theta );
    float ay273 = getYAfterRotation( a + 13, 73 + b, a  + 40, b + 82, bat_theta );

    float ax413 = getXAfterRotation( a + 13, 57 + b, a  + 40, b + 82, bat_theta );
    float ay457 = getYAfterRotation( a + 13, 57 + b, a  + 40, b + 82, bat_theta );

    glBegin(GL_POLYGON);
        glColor3f(0.64,0.164,0.164);
        glVertex2f(ax07,ay07);
        glVertex2f(ax17,ay173);
        glVertex2f(ax213,ay273);
        glVertex2f(ax413,ay457);
        glColor3f(0,0,0);
    glEnd();


    // bat stick
    float f0x = getXAfterRotation( a + 13, 57 + b, a  + 40, b + 82, bat_theta );
    float f0y = getYAfterRotation( a + 13, 57 + b, a  + 40, b + 82, bat_theta );

    float f1x = getXAfterRotation( a + 18, 53 + b, a  + 40, b + 82, bat_theta );
    float f1y = getYAfterRotation( a + 18, 53 + b, a  + 40, b + 82, bat_theta );

    float f2x = getXAfterRotation( a + 18, -5 + b, a  + 40, b + 82, bat_theta );
    float f2y = getYAfterRotation( a + 18, -5 + b, a  + 40, b + 82, bat_theta );

    float f3x = getXAfterRotation( a + 2, -5 + b, a  + 40, b + 82, bat_theta );
    float f3y = getYAfterRotation( a + 2, -5 + b, a  + 40, b + 82, bat_theta );

    float f4x = getXAfterRotation( a + 2, 53 + b, a  + 40, b + 82, bat_theta );
    float f4y = getYAfterRotation( a + 2, 53 + b, a  + 40, b + 82, bat_theta );

    float f5x = getXAfterRotation( a + 7, 57 + b, a  + 40, b + 82, bat_theta );
    float f5y = getYAfterRotation( a + 7, 57 + b, a  + 40, b + 82, bat_theta );

    glBegin(GL_POLYGON);
        glColor3f(0.64,0.164,0.164);
        glVertex2f(f0x,f0y);
        glVertex2f(f1x,f1y);
        glVertex2f(f2x,f2y);
        glVertex2f(f3x,f3y);
        glVertex2f(f4x,f4y);
        glVertex2f(f5x,f5y);
        glColor3f(0,0,0);
    glEnd();

    if(bat_theta > max_bat_angle){
       called_one = 0;
       bat_theta = 0;
    }
    else if(bat_theta!=0){
        bat_theta += const_bat_add;
    }
    
}

void checkBowlIncoming(){
    if(called_one==1 ){
        bat_theta = const_bat_add;
        called_one = 0;
    }
}

void checkBallHit(float a,float b){
    if(old_key=='0' && ballposx <= 80 && isthrown ==1 ){

        if( wicket_offset_3 > 10)
        {
            return;
        }
        
        // change the wicket position
        wicket_offset_1 -= 4;
        wicket_offset_2 -= 2;
        wicket_offset_3 += 2;

        return;
        
    }
    
    float res = getXAfterRotation( a + 2, -5 + b, a  + 40, b + 82, bat_theta );
    if(ballposx < res && isthrown==1 )
    {
        ballspeedx = 8;
        ballspeedy = 4;
        offsety = 750;
    }
}


void drawBatter(int a,int b){

    checkBowlIncoming();

    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    GLfloat x = 60 + a + batter_x_speed, y = 148 + b;
    // head
    drawFilledCircle( x + 40 ,117 + y,25);
    
    // torso
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    drawLine(x + 40, y + 92 , x + 40, 42 + y );

    // legs
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    drawLine( x + bleftLeg , y, x + 40, y + 42 );
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    drawLine( x + 70 + brightLeg , y  , x + 40, y + 42 );    


    if( taking_run )
    {
        batter_x_speed += batter_factor;
        if(  brotateLegs <= blowlimit  )
        {
            bleftLeg += batter_factor;
            brightLeg -= batter_factor;
        }   
        else if(brotateLegs < buplimit  )
        {
            bleftLeg -= batter_factor; 
            brightLeg += batter_factor;
        }
        else if(brotateLegs >= buplimit)
        {
            brotateLegs = 0 ; 
            bleftLeg += batter_factor;
            brightLeg -= batter_factor;
        }
        brotateLegs += 1 ;
    }


    // draw arms
    drawArms(x,y);
    
    checkBallHit(x,y);

    load_default();
}


void draw_second_batsman_Arms(int a,int b,float bat_theta ){
    // left arm
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    float tempvar1 = getXAfterRotation( a + 70, 70 + b, a  + 40, b + 92, bat_theta );
    float tempvar2 = getYAfterRotation( a + 70, 70 + b, a  + 40, b + 92, bat_theta );
    drawLine( a  + 40, b + 92 , tempvar1  , tempvar2  );
    
    
    
    //right arm
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    tempvar1 = getXAfterRotation( a + 70, 60 + b, a  + 40, b + 82, bat_theta );
    tempvar2 = getYAfterRotation( a + 70, 60 + b, a  + 40, b + 82, bat_theta );
    drawLine( a  + 40, b + 82 , tempvar1  , tempvar2  );

    
    int local_offset = 60;
    // bat handle
    float ax07 = getXAfterRotation( a + 7 + local_offset , 57 + b, a  + 40, b + 82, bat_theta );
    float ay07 = getYAfterRotation( a + 7 + local_offset , 57 + b, a  + 40, b + 82, bat_theta );

    float ax17 = getXAfterRotation( a + 7 +local_offset , 73 + b, a  + 40, b + 82, bat_theta );
    float ay173 = getYAfterRotation( a + 7 + local_offset, 73 + b, a  + 40, b + 82, bat_theta );
    
    float ax213 = getXAfterRotation( a + 13 + local_offset, 73 + b, a  + 40, b + 82, bat_theta );
    float ay273 = getYAfterRotation( a + 13 + local_offset , 73 + b, a  + 40, b + 82, bat_theta );

    float ax413 = getXAfterRotation( a + 13 + local_offset, 57 + b, a  + 40, b + 82, bat_theta );
    float ay457 = getYAfterRotation( a + 13 + local_offset , 57 + b, a  + 40, b + 82, bat_theta );

    glBegin(GL_POLYGON);
        glColor3f(0.64,0.164,0.164);
        glVertex2f(ax07,ay07);
        glVertex2f(ax17,ay173);
        glVertex2f(ax213,ay273);
        glVertex2f(ax413,ay457);
        glColor3f(0,0,0);
    glEnd();


    // bat stick
    float f0x = getXAfterRotation( a + 13 + local_offset, 57 + b, a  + 40, b + 82, bat_theta );
    float f0y = getYAfterRotation( a + 13 + local_offset, 57 + b, a  + 40, b + 82, bat_theta );

    float f1x = getXAfterRotation( a + 18 + local_offset , 53 + b, a  + 40, b + 82, bat_theta );
    float f1y = getYAfterRotation( a + 18 + local_offset, 53 + b, a  + 40, b + 82, bat_theta );

    float f2x = getXAfterRotation( a + 18 + local_offset, -5 + b, a  + 40, b + 82, bat_theta );
    float f2y = getYAfterRotation( a + 18 + local_offset, -5 + b, a  + 40, b + 82, bat_theta );

    float f3x = getXAfterRotation( a + 2 + local_offset, -5 + b, a  + 40, b + 82, bat_theta );
    float f3y = getYAfterRotation( a + 2 + local_offset, -5 + b, a  + 40, b + 82, bat_theta );

    float f4x = getXAfterRotation( a + 2 + local_offset, 53 + b, a  + 40, b + 82, bat_theta );
    float f4y = getYAfterRotation( a + 2 + local_offset, 53 + b, a  + 40, b + 82, bat_theta );

    float f5x = getXAfterRotation( a + 7 + local_offset, 57 + b, a  + 40, b + 82, bat_theta );
    float f5y = getYAfterRotation( a + 7 + local_offset, 57 + b, a  + 40, b + 82, bat_theta );

    glBegin(GL_POLYGON);
        glColor3f(0.64,0.164,0.164);
        glVertex2f(f0x,f0y);
        glVertex2f(f1x,f1y);
        glVertex2f(f2x,f2y);
        glVertex2f(f3x,f3y);
        glVertex2f(f4x,f4y);
        glVertex2f(f5x,f5y);
        glColor3f(0,0,0);
    glEnd();

    if(bat_theta > max_bat_angle){
       called_one = 0;
       bat_theta = 0;
    }
    else if(bat_theta!=0){
        bat_theta += const_bat_add;
    }
    
}

float sbleftLeg  = 0, sbrightLeg = 0, sbrotateLegs = 0,sbatter_x_speed=0;
void drawSecondBatsman(int a,int b){

    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    GLfloat x = 650 + a + sbatter_x_speed, y = 148 + b;
    // head
    drawFilledCircle( x + 40 ,117 + y,25);
    
    // torso
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    drawLine(x + 40, y + 92 , x + 40, 42 + y );

    // legs
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    drawLine( x + sbleftLeg , y, x + 40, y + 42 );
    glColor3f(0,0.74,1);
    glLineWidth(batterwidth);
    glPointSize(batterwidth);
    drawLine( x + 70 + sbrightLeg , y  , x + 40, y + 42 );    


    if( taking_run )
    {
        sbatter_x_speed -= batter_factor;
        if(  sbrotateLegs <= blowlimit  )
        {
            sbleftLeg += batter_factor;
            sbrightLeg -= batter_factor;
        }   
        else if(sbrotateLegs < buplimit  )
        {
            sbleftLeg -= batter_factor; 
            sbrightLeg += batter_factor;
        }
        else if(sbrotateLegs >= buplimit)
        {
            sbrotateLegs = 0 ; 
            sbleftLeg += batter_factor;
            sbrightLeg -= batter_factor;
        }
        sbrotateLegs += 1 ;
    }


    // draw arms
    draw_second_batsman_Arms(x,y,0);

    if( taking_run == 1 && x <= 60 ){
        // reset positions of batsman as they reached
        taking_run = 0;
        sbatter_x_speed = 0;
        batter_x_speed = 0;
        sbleftLeg = 0, sbrotateLegs = 0, sbrightLeg = 0;
        bleftLeg = 0, brotateLegs = 0, brightLeg = 0;  
        runs += 1;        
    }

    load_default();
}


void drawWicket(int x,int y,int wicket_offset_1,int wicket_offset_2,int wicket_offset_3){   
    float width = 3.9;
    glLineWidth(width);
    drawLine( 50 + x, y + 148 , x + 50 + wicket_offset_1 , y + 215 + wicket_offset_1 );
    glLineWidth(width);
    drawLine( 58 + x, y + 148 + 5 , x + 58 + wicket_offset_2 , y + 215 + 5 + wicket_offset_2 );
    glLineWidth(width);
    drawLine( 66 + x, y + 148 + 10 , x + 66 + wicket_offset_3 , y + 215 + 10 + wicket_offset_3 );

    glLineWidth(width-1.2);
    drawLine( 50 + x + wicket_offset_2 , y + 215 + wicket_offset_2  , x + 66 , y + 215 + 10 );
}


// rotation of arm(s)
void drawBowlerArms(int a,int b){
    // left arm
    glColor3f(0.10,0.0,0.0);
    glLineWidth(bowlerwidth);
    glPointSize(bowlerwidth);
    drawLine( a  + 40, b + 92 , a + 10  , 70 + b  );
    
    float rightArmXEnd = a + 40 + 30 ;
    float rightArmYEnd = 70 + b ;

    float tx = getXAfterRotation(rightArmXEnd, rightArmYEnd, a  + 40, b + 92, theta);
    float ty = getYAfterRotation(rightArmXEnd, rightArmYEnd, a  + 40, b + 92, theta);
    
    //right arm
    glColor3f(0.10,0.0,0.0);
    glLineWidth(bowlerwidth);
    glPointSize(bowlerwidth);
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
            if(old_key!='0')
                called_one = 1;
            theta = 0;
            isthrown = 1;
            ballposx = tx;
            ballposy = ty;
            offsety = ty - 0.5 ;
        }
        else{
            if(taking_run == 0){
                theta = 0;
                // draw small bowl
                glColor3f( 1 , 0 , 0.15 );
                drawFilledCircle( tx , ty , 8 );
            }
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

    
        if(ballposx <= 10){
            // reset if gone behind
            // test purpose
            isthrown = 0;
            ballspeedx = -8;
            ballspeedy = -2;
            factor = 0.8;
            if(old_key=='0' && is_out==0){
                is_out = 1;
                wickets+=1;
            }                
        }   

        if(ballposx >= 800)
        {
            isthrown = 0;
            ballspeedx = -8;
            ballspeedy = -2;
            factor = 0.8;
            // do transition
            app_state = 2;
            ballposx = 0;
            if( old_key == '6' ){
                runs += 6;
                ballposy = 600 + rand()%50 - rand()%50; 
            }
               
            else if( old_key == '4')
            {
                runs += 4;
                ballposy = 380 + rand()%50 - rand()%50;
            }
            else if(old_key=='1')
            {
                // Take One Run
                app_state = 1;
                taking_run = 1;
            }
            else if(old_key=='0'){
                // wicket out
                app_state = 1;
    
            }
        }

    }
}

void drawBowler(int a,int b){
    glColor3f(0.10,0.0,0.0);
    glLineWidth(bowlerwidth);
    glPointSize(bowlerwidth);
    
    GLfloat x = 720 + a + bowler_x_speed , y = 148 + b + bowler_y_speed;
    // head
    glColor3f(0.10,0.0,0.0);
    glLineWidth(bowlerwidth);
    glPointSize(bowlerwidth);
    drawFilledCircle( x + 40 ,117 + y,25);

    // torso
    glColor3f(0.10,0.0,0.0);
    glLineWidth(bowlerwidth);
    glPointSize(bowlerwidth);
    drawLine(x + 40, y + 92 , x + 40, 42 + y );

    // legs
    glColor3f(0.10,0.0,0.0);
    glLineWidth(bowlerwidth);
    glPointSize(bowlerwidth);
    drawLine( x + leftLeg, y, x + 40, y + 42 );

    glColor3f(0.10,0.0,0.0);
    glLineWidth(bowlerwidth);
    glPointSize(bowlerwidth);
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
    
    load_default();
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


void drawStrings(){
    void *fontMenu = GLUT_BITMAP_9_BY_15;
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

    if(runs>=target_score){
        // team blue wins
        game_over = 1;
        char new_score_text[100] = "Team India Wins - Press R to Restart";
        unsigned char new_score_string[100] = "Team India Wins - Press R to Restart";
        void *localFont =  GLUT_BITMAP_8_BY_13;
        int size_string = glutBitmapLength(localFont, new_score_string);
        float newloc = 250 + (150 - size_string/2.0  );
        drawBitmapText(new_score_text, newloc, 420 , 0 ,localFont);
        load_default(); 
        return;

    }
    
    if(is_out){
        if(wickets>=10 && runs<target_score-1){
            // team black wins
            game_over = 1;
            char new_score_text[100] = "Team England Wins - Press R to Restart";
            unsigned char new_score_string[100] = "Team England Wins - Press R to Restart";
            void *localFont =  GLUT_BITMAP_8_BY_13;
            int size_string = glutBitmapLength(localFont, new_score_string);
            float newloc = 250 + (150 - size_string/2.0  );
            drawBitmapText(new_score_text, newloc, 420 , 0 ,localFont);
            load_default(); 
            return;
        }
        else if(wickets>=10 && runs == target_score-1){
            // match tie
            
            game_over = 1;
            char new_score_text[100] = "Game Draw - Press R to Restart";
            unsigned char new_score_string[100] = "Game Draw - Press R to Restart";
            void *localFont =  GLUT_BITMAP_8_BY_13;
            int size_string = glutBitmapLength(localFont, new_score_string);
            float newloc = 250 + (150 - size_string/2.0  );
            drawBitmapText(new_score_text, newloc, 420 , 0 ,localFont);
            load_default(); 
            return;
        }
        else{
            char new_score_text[100] = "OUT - Press A to Continue";
            unsigned char new_score_string[100] = "OUT - Press A to Continue";
            void *localFont =  GLUT_BITMAP_9_BY_15;
            int size_string = glutBitmapLength(localFont, new_score_string);
            float newloc = 250 + (150 - size_string/2.0  );
            drawBitmapText(new_score_text, newloc, 420 , 0 ,localFont);
            load_default(); 
            return;
        }
        

    }
   
    char match_name[] = "INDIA VS ENGLAND";
    unsigned char string[] = "INDIA VS ENGLAND";
    int size_string = glutBitmapLength(fontMenu, string);
    float newloc = 250 + (150 - size_string/2.0  );
    drawBitmapText(match_name, newloc, 450  ,0,fontMenu);


    // convert int Runs to string
    //Runs
    char result[50]; 
    sprintf(result, "%d", runs);

    char new_score_text[100] = "Runs: ";
    unsigned char new_score_string[100] = "Runs: ";
    int tlen = 6;
    for(int i = 0; result[i]!='\0';i++ ){
        new_score_text[tlen] = result[i];
        new_score_string[tlen] = result[i];
        tlen++ ;
    }

    size_string = glutBitmapLength(fontMenu, new_score_string);
    newloc = 250 + (150 - size_string/2.0  );
    drawBitmapText(new_score_text, newloc, 430 , 0 ,fontMenu);

    // target score
    sprintf(result, "%d", target_score);
    char new_target_text[100] = "Target: ";
    unsigned char new_target_string[100] = "Target: ";
    tlen = 8;
    for(int i = 0; result[i]!='\0';i++ ){
        new_target_text[tlen] = result[i];
        new_target_string[tlen] = result[i];
        tlen++ ;
    }

    size_string = glutBitmapLength(fontMenu, new_target_string);
    newloc = 250 + (150 - size_string/2.0  );
    drawBitmapText(new_target_text, newloc, 410 , 0 ,fontMenu);

    // wickets down
    sprintf(result, "%d", wickets);
    char new_wicket_text[100] = "Wickets: ";
    unsigned char new_wicket_string[100] = "Wickets: ";
    tlen = 9;
    for(int i = 0; result[i]!='\0';i++ ){
        new_wicket_text[tlen] = result[i];
        new_wicket_string[tlen] = result[i];
        tlen++ ;
    }

    size_string = glutBitmapLength(fontMenu, new_wicket_string);
    newloc = 250 + (150 - size_string/2.0  );
    drawBitmapText(new_wicket_text, newloc, 390 , 0 ,fontMenu);

    

    load_default(); 
}

void drawMesh(int x,int y){
    int dx = 10, dy=10;
    int rows = 80,cols = 5;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
        {
            glLineWidth(2);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x + dx*i , y + dy*j );
                glVertex2f(x + dx*(i+1) , y + dy*j );
                glVertex2f(x + dx*(i+1) , y + dy*(j+1)  );
                glVertex2f(x + dx*i , y + dy*(j+1) );
            glEnd();            
        }
    load_default();
}

void drawperson(int x,int y)
{
    // total size = div
    int personWidth = 15,personBodyHeight = 15;
    int head=5;
    glColor3f(0,0,0);
    drawSquareP(x,y, x + personWidth, y + personBodyHeight  );
    
    float r = 0.928 , g = 0.734 , b = 0.7013 ;
    glColor3f(r,g,b);
    drawFilledCircle( x + personWidth/2, personBodyHeight + y + head, head  );   

    // drawing hands
    glColor3f(0,0,0);
    if(rand()%5 <= 1){
        drawLine( x , y + personBodyHeight,  x - 5 , y + 2  );
        drawLine( x + personWidth , y + personBodyHeight,  x + personWidth +  5 , y + 2  );
    }
       
    else{
        drawLine( x , y + personBodyHeight, x - 5 , y +  personBodyHeight + 5   );
        drawLine( x + personWidth , y + personBodyHeight,  x + personWidth +  5 , y + personBodyHeight + 5  );
    }
     
}

void drawStands(int x,int y){
    int div = 25;
    int last = 800;
   
    for(int i=y;i<400;i+=div)
    {
        glColor3f(0.65,0.65,0.65);
        drawLine(0,i,last,i);
        for(int w=15;w<800;w+=40)
        {
            drawperson(w,i);
        }
    }
}

void drawStadium(int show_score){

    // gray background
    glColor3f(0.75,0.75,0.75);
    drawSquareP(0,400,800,200);

    //box cooordinated: TL:(250,500) BR:(550,350)

    // draw ligths
    drawLights(80,550);
    drawLights(635,550);


    // draw 
    drawStands(0,200);

    if(show_score){
        // board
        glColor3f(0.2,0.2,0.2);
        drawSquareP(245,505,555,345);
        glColor3f(0,0,0);
        drawSquareP(250,500,550,350);

        // blinking text effect
        drawStrings();

    }
        
     // draw net
    glColor3f(1,1,1);
    drawMesh( 0,200 );

}


void drawBatsman(){
    
    glColor3f(1.0,0.0,0.0);
    
    drawSkyBackground();

    // draw ground
    glColor3f(0,0.75,0.2);
    drawSquareP(0,200,800,0);

    // draw 6 line
    glColor3f(1,1,1);
    glLineWidth(1);
    drawLine(0,195,800,195);
    
    // drawing back stadium
    drawStadium(1);


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
    drawWicket(-15,0,wicket_offset_1,wicket_offset_2,wicket_offset_3);


    drawSecondBatsman(0,0);

    //bowler wicket
    drawWicket(640,0,0,0,0);

    drawBowler(0,0);
    
    drawBatter(0,0);


}


int handleGameKey(unsigned char key){
        
    if((key == 's' || key =='S' || key=='4' || key=='6' || key=='1' || key=='0') && is_out==0 && game_over==0)  
    {
        bowler_x_speed -= factor;
        theta += rot_speed;
    }
    else if((key=='a'||key=='A') && game_over==0 )
    {
        is_out = 0;
        wicket_offset_1 = 0;
        wicket_offset_2 = 0;
        wicket_offset_3 = 0;
    }
    else if(game_over==1 && (key=='R' || key=='r')){
        game_over = 0;
        is_out = 0;
        wicket_offset_1 = 0;
        wicket_offset_2 = 0;
        wicket_offset_3 = 0;
        restart_game();

    }
    old_key = key;
    return 1;
}