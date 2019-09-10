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

    drawBitmapText(usn3, 100 , 400 , 0  );
    drawBitmapText(usn2, 100 , 400 + VGAP_ROW * 1 , 0  );
    drawBitmapText(usn1, 100 , 400 + VGAP_ROW * 2 , 0  );
    

    drawBitmapText(name3, 100 + HGAP_USN_NAME , 400 , 0  );
    drawBitmapText(name2, 100 + HGAP_USN_NAME , 400 + VGAP_ROW * 1 , 0  );
    drawBitmapText(name1, 100 + HGAP_USN_NAME , 400 + VGAP_ROW * 2 , 0  );

    glColor3f(0.0,0.0,1.0);
    drawBitmapText(title, 180  , 400 - VGAP_ROW*1  , 0);

}