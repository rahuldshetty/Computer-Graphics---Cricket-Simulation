void *fontMenu = GLUT_BITMAP_TIMES_ROMAN_24;
void drawPressToStart(){
    int HGAP_USN_NAME = 50;
    int VGAP_ROW = 40;

    char batsman[] = "Press A to play as batsman";
    char bowler[] = "Press B to play as bowler";

    glColor3f(0,0,0);
    drawBitmapText(batsman, 100 + HGAP_USN_NAME , 280 + VGAP_ROW  , 0 ,fontMenu );
    drawBitmapText(bowler, 100 + HGAP_USN_NAME , 250 + VGAP_ROW , 0 ,fontMenu );
    
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
    
    int HGAP_USN_NAME = 180;
    int VGAP_ROW = 40;

    drawBitmapText(usn3, 100 , 400 , 0 ,fontMenu );
    drawBitmapText(usn2, 100 , 400 + VGAP_ROW * 1 , 0 ,fontMenu );
    drawBitmapText(usn1, 100 , 400 + VGAP_ROW * 2 , 0,fontMenu  );
    

    drawBitmapText(name3, 100 + HGAP_USN_NAME , 400 , 0 ,fontMenu);
    drawBitmapText(name2, 100 + HGAP_USN_NAME , 400 + VGAP_ROW * 1 , 0 ,fontMenu );
    drawBitmapText(name1, 100 + HGAP_USN_NAME , 400 + VGAP_ROW * 2 , 0  ,fontMenu);

    glColor3f(0.0,0.0,1.0);
    drawBitmapText(title, 180  , 400 - VGAP_ROW*1  , 0,fontMenu);

    drawPressToStart();

}

int handleMenuKey(unsigned char key){
    if(key=='A' || key=='a')
    {
        // start batsman 
        return 1;
    }
    else if(key=='B' || key=='b'){
        // start bowler
        return 2;
    }
    else{
        return 0;
    }

}