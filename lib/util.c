void drawBitmapText(char *string,float x,float y,float z,void *font) 
{  
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter( font  , *c);
	}
}

void load_default(void){
	glColor3f(0,0,0);
	glPointSize(1);
	glLineWidth(1);
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width > height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(  -(width/2.0 - 300) , 600 + (width/2.0 - 300) , -(height/2.0 - 300), 600.0 + (height/2.0 - 300));
   } else if(height > width){
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D( 0, 600 , -(height/2.0 - 300), 600.0 + (height/2.0 - 300));
   }
   else{
      gluOrtho2D(0, 600.0, 0, 600.0 );
   }
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	load_default();
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) { 
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)), 
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
	load_default();
}

void drawSquareP(float x1,float y1,float x2,float y2){
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x1,y2);
        glVertex2f(x2,y2);
        glVertex2f(x2,y1);
    glEnd();
	load_default();
}

void drawLine(float x,float y,float w,float z){
    glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(w,z);
    glEnd();    
	load_default();
}

