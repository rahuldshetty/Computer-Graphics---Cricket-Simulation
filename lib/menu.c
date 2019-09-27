void *fontMenu = GLUT_BITMAP_TIMES_ROMAN_24;

float r=1,g=0,b=0;


int timer = 0;
clock_t oldclock;

void drawPressToStart(){
    int HGAP_USN_NAME = 50;
    int VGAP_ROW = 40;
    char batsman[] = "Press A to start";
    if(timer==0){
        glColor3f(r,g,b);
        drawBitmapText(batsman, 280 + HGAP_USN_NAME , 475 + VGAP_ROW  , 0 ,fontMenu );   
        r = (rand()%257) / 256.0;
        g = (rand()%257) / 256.0;
        b = (rand()%257) / 256.0;
        glutPostRedisplay();
        oldclock = clock(); 
        timer = 1;
    }    
    else if(conv2seconds(clock()-oldclock) >= 0.25 )
    {
        timer = 0;
        oldclock = clock();
        glColor3f(r,g,b);
        drawBitmapText(batsman, 280 + HGAP_USN_NAME , 475 + VGAP_ROW  , 0 ,fontMenu );   
        glutPostRedisplay();
    }
    else{
        glColor3f(r,g,b);
        drawBitmapText(batsman, 280 + HGAP_USN_NAME , 475 + VGAP_ROW  , 0 ,fontMenu );   
        glutPostRedisplay();
    }
}

void drawMenu(){
    
    glColor3f(1.0,0.0,0.0);
    char title[] = "Cricket Simulation";

    char name1[] = "Rahul D Shetty";
    char name2[] = "Rajath Gundmi Aithal";
    char name3[] = "Rakesh Arasu";
    
    char usn1[] = "4NM16CS111";
    char usn2[] = "4NM16CS112";
    char usn3[] = "4NM16CS113";
    
    // usn - name
    //   title
    
    int HGAP_USN_NAME = 230;
    int VGAP_ROW = 40;

    drawBitmapText(usn3, 200 , 600 , 0 ,fontMenu );
    drawBitmapText(usn2, 200 , 600 + VGAP_ROW * 1 , 0 ,fontMenu );
    drawBitmapText(usn1, 200 , 600 + VGAP_ROW * 2 , 0,fontMenu  );
    

    drawBitmapText(name3, 200 + HGAP_USN_NAME , 600 , 0 ,fontMenu);
    drawBitmapText(name2, 200 + HGAP_USN_NAME , 600 + VGAP_ROW * 1 , 0 ,fontMenu );
    drawBitmapText(name1, 200 + HGAP_USN_NAME , 600 + VGAP_ROW * 2 , 0  ,fontMenu);

    glColor3f(0.0,0.0,1.0);
    drawBitmapText(title, 305  , 600 - VGAP_ROW*1  , 0,fontMenu);

    drawPressToStart();
}

int handleMenuKey(unsigned char key){
    if(key=='A' || key=='a')
    {
        // start batsman 
        return 1;
    }
    else{
        return 0;
    }

}