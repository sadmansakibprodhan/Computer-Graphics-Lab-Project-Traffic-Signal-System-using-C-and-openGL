//Sadman Sakib Prodhan


#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.1416
#include <math.h>
#include <time.h>




GLint i;
float _angle = 0.0;
GLint flag=0;


float pixel(float point){
    return point/25.0;
}


bool tp_to_bttm=false;
bool lft_to_right=false;

bool orange_light_comes = false;


void SignalPost(float x,float y);



float carmove_lft_to_rit = 25;
float carmove_lft_to_rit2 = -30;
float carmove_lft_to_rit3 = 4;



float carmove_rt_to_lft = -2.5;
float carmove_rt_to_lft2 = -20.0;
float carmove_rt_to_lft3 = 6.0;



void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}


float clr(float x)
{
    float color = x/255;
    return color;
}





void circle(GLdouble rad)
{
    GLint points= 50;
    GLdouble delTheta = (2.0* PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for(i = 0; i<=50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}




void lineCirle(){
    glBegin(GL_LINES);
	for(int i=0;i<300;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.95;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
}


void sun(){

    glColor3f(clr(249),clr(215),clr(28));//(R,G,B)
    circle(2);


}
void car()
{


    // car body

    glColor3f(clr(0.0),clr(0.0),clr(205.0));
    glBegin(GL_POLYGON);
    glVertex2f(-2.0f,1.0f);
    glVertex2f(-0.14f,1.0f);
    glVertex2f(-0.14f,2.0f);
    glVertex2f(1.19f,2.0f);
    glVertex2f(1.50f,1.0f);
    glVertex2f(4.50f,1.0f);
    glVertex2f(5.50f,2.0f);
    glVertex2f(6.65f,2.0f);
    glVertex2f(6.83f,1.0f);
    glVertex2f(8.83f,1.0f);


    glVertex2f(8.80f,2.0f);
    glVertex2f(5.95f,3.0f);
    glVertex2f(4.00f,4.80f);
    glVertex2f(-0.40f,4.80f);
    glVertex2f(-1.40f,3.0f);
    glVertex2f(-2.0f,2.30f);

    glEnd();


    //car bampar

      glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.0f,2.0f);
     glVertex2f(8.70f,2.0f);
     glVertex2f(8.70f,1.70f);
     glVertex2f(-2.0f,1.50f);
    glEnd();

//    // car tiars //

    glColor3f(clr(190),clr(190),clr(190));
    glPushMatrix();
    glTranslatef(0.20f,0.80f,0.0f);
    circle(.52);
    glPopMatrix();


    glColor3f(clr(190),clr(190),clr(190));
    glPushMatrix();
    glTranslatef(6.70f,0.80f,0.0f);
    circle(.52);
    glPopMatrix();



    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(0.20f,0.80f,0.0f);
    glScalef(.29,.29,.29);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	lineCirle();
	glPopMatrix();


	glColor3f(0,0,0);
	glPushMatrix();
    glTranslatef(6.70f,0.80f,0.0f);
	glScalef(.29,.29,.29);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	lineCirle();
	glPopMatrix();

    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.20f,0.80f,0.0f);
    circle(.32);
    glPopMatrix();


    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(6.70f,0.80f,0.0f);
    circle(.32);
    glPopMatrix();




//////car windows
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
    glVertex2f(-0.30f,4.0f);
    glVertex2f(1.70f,4.0f);
    glVertex2f(1.70f,2.7f);
    glVertex2f(-0.80f,2.7f);

glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
    glVertex2f(2.30f,4.0f);
    glVertex2f(3.90f,4.0f);
    glVertex2f(4.95f,2.70f);
    glVertex2f(2.30f,2.75f);
    //glVertex2f(-3.80f,2.7f);

glEnd();



}



void brtc_bus(){

    // body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-10.30f,15.0f);
    glVertex2f(-20.30f,15.0f);
    glVertex2f(-22,2);
    glVertex2f(-10.30,2);
    glEnd();

    //bar

    //glColor3f(clr(34.0),clr(139.0),clr(34.0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-10.30f,9.0f);
    glVertex2f(-21.0f,9.0f);
    glVertex2f(-21.0f,8);
    glVertex2f(-10.30,8);
    glEnd();

    //windows

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-11.0f,14.0f);
    glVertex2f(-13.0f,14);
    glVertex2f(-13.0,10.0);
    glVertex2f(-11.0,10.0);
    glEnd();



    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-14.0f,14.0f);
    glVertex2f(-16.0f,14);
    glVertex2f(-16.0,10.0);
    glVertex2f(-14.0,10.0);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-17.0f,14.0f);
    glVertex2f(-19.0f,14);
    glVertex2f(-19.0,10.0);
    glVertex2f(-17.0,10.0);
    glEnd();


    //door


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-15.0f,8.0f);
    glVertex2f(-17.0f,8.0f);
    glVertex2f(-17.0f,2.50f);
    glVertex2f(-15.0f,2.50f);




    glEnd();




    //tires

    glColor3f(clr(190),clr(190),clr(190));
    glPushMatrix();
    glTranslatef(-13.0f,2.0f,0.0f);
    circle(1);
    glPopMatrix();

    glColor3f(clr(190),clr(190),clr(190));
    glPushMatrix();
    glTranslatef(-19.0f,2.0f,0.0f);
    circle(1);
    glPopMatrix();


    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(-13.0f,2.0f,0.0f);
    glScalef(.29,.29,.29);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	lineCirle();
	glPopMatrix();


	glColor3f(0,0,0);
	glPushMatrix();
    glTranslatef(-19.0f,2.0f,0.0f);
	glScalef(.29,.29,.29);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	lineCirle();
	glPopMatrix();

	 glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-13.0f,2.0f,0.0f);
    circle(.32);
    glPopMatrix();


    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-19.0f,2.0f,0.0f);
    circle(.32);
    glPopMatrix();





}

void road(){



    glColor3f(0.0,0.0,0.0);
    //upper road

    glBegin(GL_POLYGON);
        glVertex2f(3.0f,35.25f);
        glVertex2f(-3.0f,35.25f);
        glVertex2f(-3.0f,0.0f);
        glVertex2f(3.0f,0.0f);

    glEnd();

    //left road();// right road

    glBegin(GL_POLYGON);
        glVertex2f(40.0f,7.25f);
        glVertex2f(-40.0f,7.25f);
        glVertex2f(-40.0f,-10.25f);
        glVertex2f(40.0f,-10.25f);
       // glVertex2f(3.0f,0.0f);

    glEnd();

    //down road();

    glBegin(GL_POLYGON);
        glVertex2f(3.0f,-35.25f);
        glVertex2f(-3.0f,-35.25f);
        glVertex2f(-3.0f,0.0f);
        glVertex2f(3.0f,0.0f);

    glEnd();


    //middle line left to right
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
      glVertex2f(-3.0f,-1.50f);
      glVertex2f(-40.0f,-1.50f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
      glVertex2f(3.0f,-1.50f);
      glVertex2f(40.0f,-1.50f);
    glEnd();

    //middle line lower to upper

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
      glVertex2f(0.0f,25.30f);
      glVertex2f(0.0f,7.10f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
      glVertex2f(0.0f,-25.30f);
      glVertex2f(0.0f,-10.10f);
    glEnd();

//
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
      glVertex2f(3.0f,7.20f);
      glVertex2f(-3.0f,7.20f);
      glVertex2f(-3.f,-10.20f);
      glVertex2f(3.f,-10.20f);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
      glVertex2f(3.0f,7.20f);
      glVertex2f(-3.f,-10.20f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
      glVertex2f(-3.0f,7.20f);
      glVertex2f(3.f,-10.20f);
    glEnd();













    //






}

void zebra_crossing(){




    //left road
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,6.90f);
        glVertex2f(-20.0f,6.90f);
        glVertex2f(-20.0f,5.25f);
        glVertex2f(-15.0f,5.25f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,4.50f);
        glVertex2f(-20.0f,4.50f);
        glVertex2f(-20.0f,2.50f);
        glVertex2f(-15.0f,2.50f);
    glEnd();

     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,2.0f);
        glVertex2f(-20.0f,2.0f);
        glVertex2f(-20.0f,0.0f);
        glVertex2f(-15.0f,0.0f);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,-0.50f);
        glVertex2f(-20.0f,-0.50f);
        glVertex2f(-20.0f,-2.50f);
        glVertex2f(-15.0f,-2.50f);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,-3.0f);
        glVertex2f(-20.0f,-3.0f);
        glVertex2f(-20.0f,-5.0f);
        glVertex2f(-15.0f,-5.0f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,-4.0f);
        glVertex2f(-20.0f,-4.0f);
        glVertex2f(-20.0f,-5.20f);
        glVertex2f(-15.0f,-5.20f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,-5.80f);
        glVertex2f(-20.0f,-5.80f);
        glVertex2f(-20.0f,-7.80f);
        glVertex2f(-15.0f,-7.80f);
    glEnd();


     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-15.0f,-8.20f);
        glVertex2f(-20.0f,-8.20f);
        glVertex2f(-20.0f,-9.80f);
        glVertex2f(-15.0f,-9.80f);
    glEnd();


    //right road

        glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,6.90f);
        glVertex2f(20.0f,6.90f);
        glVertex2f(20.0f,5.25f);
        glVertex2f(15.0f,5.25f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,4.50f);
        glVertex2f(20.0f,4.50f);
        glVertex2f(20.0f,2.50f);
        glVertex2f(15.0f,2.50f);
    glEnd();

     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,2.0f);
        glVertex2f(20.0f,2.0f);
        glVertex2f(20.0f,0.0f);
        glVertex2f(15.0f,0.0f);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,-0.50f);
        glVertex2f(20.0f,-0.50f);
        glVertex2f(20.0f,-2.50f);
        glVertex2f(15.0f,-2.50f);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,-3.0f);
        glVertex2f(20.0f,-3.0f);
        glVertex2f(20.0f,-5.0f);
        glVertex2f(15.0f,-5.0f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,-4.0f);
        glVertex2f(20.0f,-4.0f);
        glVertex2f(20.0f,-5.20f);
        glVertex2f(15.0f,-5.20f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,-5.80f);
        glVertex2f(20.0f,-5.80f);
        glVertex2f(20.0f,-7.80f);
        glVertex2f(15.0f,-7.80f);
    glEnd();


     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(15.0f,-8.20f);
        glVertex2f(20.0f,-8.20f);
        glVertex2f(20.0f,-9.80f);
        glVertex2f(15.0f,-9.80f);
    glEnd();


  //  upperroad

   glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(3.0f,20.20f);
        glVertex2f(2.0f,20.20f);
        glVertex2f(2.0f,13.20f);
        glVertex2f(3.0f,13.20f);
    glEnd();

      glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(3.0f,-20.20f);
        glVertex2f(2.0f,-20.20f);
        glVertex2f(2.0f,-13.20f);
        glVertex2f(3.0f,-13.20f);
    glEnd();

//

      glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(1.70f,20.20f);
        glVertex2f(0.50f,20.20f);
        glVertex2f(0.50f,13.20f);
        glVertex2f(1.70f,13.20f);
    glEnd();

       glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(1.70f,-20.20f);
        glVertex2f(0.50f,-20.20f);
        glVertex2f(0.50f,-13.20f);
        glVertex2f(1.70f,-13.20f);
    glEnd();


       glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.30f,20.20f);
        glVertex2f(-0.90f,20.20f);
        glVertex2f(-0.90f,13.20f);
        glVertex2f(0.30f,13.20f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.30f,-20.20f);
        glVertex2f(-0.90f,-20.20f);
        glVertex2f(-0.90f,-13.20f);
        glVertex2f(0.30f,-13.20f);
    glEnd();

    //
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-1.10f,20.20f);
        glVertex2f(-2.10f,20.20f);
        glVertex2f(-2.10f,13.20f);
        glVertex2f(-1.10f,13.20f);
    glEnd();

     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-1.10f,-20.20f);
        glVertex2f(-2.10f,-20.20f);
        glVertex2f(-2.10f,-13.20f);
        glVertex2f(-1.10f,-13.20f);
    glEnd();


     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-2.30f,20.20f);
        glVertex2f(-3.10f,20.20f);
        glVertex2f(-3.10f,13.20f);
        glVertex2f(-2.30f,13.20f);
    glEnd();

     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-2.30f,-20.20f);
        glVertex2f(-3.10f,-20.20f);
        glVertex2f(-3.10f,-13.20f);
        glVertex2f(-2.30f,-13.20f);
    glEnd();





}




void sky(){
    glColor3f(0.0,0.8,1.0);//(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2d(40,40);
    glVertex2d(-40,40);
    glVertex2f(-30,10);
    glVertex2f(30,15);


glEnd();
}



void field(){


  glColor3f(0.1333333f,0.5450980392f,0.133333333f);
 // glColor3f(0.0,0.2,0.0);
  glBegin(GL_POLYGON);
    glVertex3f(-683.0,-386,0.0);
    glVertex3f(683.0,-386.0,0.0);
    glVertex3f(683.0,200.0,0.0);
    glVertex3f(-683.0,200.0,0);
glEnd();

}
void init(){

    glClearColor(0.0, 0.0, 0.0, 1.0);
     glOrtho(-25,25,-25,25,-25,25);

}

bool redsignal = false;
bool green_signal = false;
bool orange_light = false;

bool start = true;

void alltransports_move(int value){

    if(start){
            if(orange_light_comes){
                green_signal = false;
                redsignal = false;
                orange_light = true;
            }
            else{
                green_signal = true;
                redsignal = false;
                orange_light = false;
            }


            if(lft_to_right){
                carmove_rt_to_lft -= .020f;
                if (carmove_rt_to_lft < pixel(-800.0))
                    carmove_rt_to_lft = pixel(800);

                carmove_rt_to_lft2 -= .030f;

                if (carmove_rt_to_lft2 < pixel(-800.0))
                    carmove_rt_to_lft2 = pixel(800);

                carmove_rt_to_lft3 -= .040f;
                if (carmove_rt_to_lft3 < pixel(-800.0))
                    carmove_rt_to_lft3 = pixel(800);

                carmove_lft_to_rit += .020f;
                if (carmove_lft_to_rit > pixel(1000.0)) {
                    carmove_lft_to_rit = pixel(-800.0);
                }

                carmove_lft_to_rit2 += .030f;
                if (carmove_lft_to_rit2 > pixel(900.0)) {
                    carmove_lft_to_rit2 = pixel(-800.0);
                }

                _angle -= 2.0f;
                carmove_lft_to_rit3 += .040f;
                if (carmove_lft_to_rit3 > pixel(900.0)) {
                    carmove_lft_to_rit3 = pixel(-800.0);
                }
            }

        glutPostRedisplay();
        glutTimerFunc(15, alltransports_move, 0);
    }
    else{
            orange_light_comes = false;
            green_signal = false;
            redsignal = true;
            orange_light = false;
            carmove_lft_to_rit += 0.0f;
            carmove_rt_to_lft -= 0.0f;

            glutPostRedisplay();
            glutTimerFunc(15, alltransports_move, 0);
    }


}






void signal1(float x,float y){

//    SetSignalPostColor();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x),pixel(y),0.0);
    glVertex3f(pixel(x+5.0),pixel(y),0.0);
    glVertex3f(pixel(x+5.0),pixel(y+25.0),0.0);
    glVertex3f(pixel(x),pixel(y+25.0),0.0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-15.0),pixel(y+25.0),0.0);
    glVertex3f(pixel(x+20.0),pixel(y+25.0),0.0);
    glVertex3f(pixel(x+20.0),pixel(y+75.0),0.0);
    glVertex3f(pixel(x-15.0),pixel(y+75.0),0.0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+20.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+20.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+23.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+23.0),0.0);
    glEnd();

    if(lft_to_right=true){
    if(green_signal){
        glColor3f(0.0,1.0,0.0);
        redsignal = false;
        orange_light = false;
    }
    else{
        glColor3f(0.0,0.0,0.0);
    }
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+45.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+45.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+58.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+58.0),0.0);
    glEnd();
    }

    if(tp_to_bttm==false){
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+60.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+60.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+73.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+73.0),0.0);
    glEnd();}




    if(orange_light){
        glColor3f(1.0,0.5,0.0);
        green_signal = false;
        redsignal = false;
    }
    else{
        glColor3f(0.0,0.0,0.0);
    }
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+42.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+42.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+30.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+30.0),0.0);
    glEnd();

}




//void Signal1(float x,float y){
//
//   // SetSignalPostColor();
//
//   //Signal red
//    glColor3f(1.0,1.0,1.0);
//    glBegin(GL_POLYGON);
//    glVertex2f(-3,3);
//    glVertex2f(-4,3);
//    glVertex2f(-4,2);
//    glVertex2f(-3,2);
//    glEnd();
//
//     //Signal greean
//    glColor3f(1.0,1.0,1.0);
//    glBegin(GL_POLYGON);
//    glVertex2f(-3,2);
//    glVertex2f(-4,2);
//    glVertex2f(-4,1);
//    glVertex2f(-3,1);
//    glEnd();
//
//     //Signal yeollow
//    glColor3f(1.0,1.0,1.0);
//    glBegin(GL_POLYGON);
//    glVertex2f(-3,1);
//    glVertex2f(-4,1);
//    glVertex2f(-4,0.50);
//    glVertex2f(-3,0.50);
//    glEnd();
//
//
//
//
//    if(vertical==false){
////    SignalLightColorRed();
//    glColor3f(1.0,1.0,1.0);
//
//    glBegin(GL_POLYGON);
//    glVertex3f(pixel(x-8.0),pixel(y+60.0),0.0);
//    glVertex3f(pixel(x+12.0),pixel(y+60.0),0.0);
//    glVertex3f(pixel(x+12.0),pixel(y+73.0),0.0);
//    glVertex3f(pixel(x-8.0),pixel(y+73.0),0.0);
//    glEnd();}
//
//    if(vertical){
//  //  SignalLightColorGreen();
//      glColor3f(1.0,1.0,1.0);
//
//    glBegin(GL_POLYGON);
//    glVertex3f(pixel(x-8.0),pixel(y+45.0),0.0);
//    glVertex3f(pixel(x+12.0),pixel(y+45.0),0.0);
//    glVertex3f(pixel(x+12.0),pixel(y+58.0),0.0);
//    glVertex3f(pixel(x-8.0),pixel(y+58.0),0.0);
//    glEnd();}
//
//   // SignalLightColorOrange();
//       glColor3f(1.0,1.0,1.0);
//
//    glBegin(GL_POLYGON);
//    glVertex3f(pixel(x-8.0),pixel(y+42.0),0.0);
//    glVertex3f(pixel(x+12.0),pixel(y+42.0),0.0);
//    glVertex3f(pixel(x+12.0),pixel(y+30.0),0.0);
//    glVertex3f(pixel(x-8.0),pixel(y+30.0),0.0);
//    glEnd();
//}





void helpscreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(-5.0,10.0,0.0,"Instructions");
glColor3f(0.5,0.1,0.2);
drawstring(-7.0,8.0,0.0,"Press R for traffic Red Light");
glColor3f(0.5,0.1,0.3);
drawstring(-7.0,6.0,0.0,"Press O for traffic Orange Light");
glColor3f(0.5,0.1,0.4);
drawstring(-7.0,4.0,0.0,"Press G for traffic Green Light");
glColor3f(1.0,0.0,0.0);
drawstring(-7.0,2.0,0.0,"Press Escape for Exit");
glColor3f(0.1333333f,0.5450980392f,0.133333333f);
drawstring(-7.0,-10.0,0.0,"PRESS ENTER TO START");
glFlush();
}

void rules_screen(void){

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.78877,0.1998765,0.987655441,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    drawstring(-10.0,15.0,0.0,"United International University");

    glFlush();



}

void frontscreen(void)
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0.5019607843,0.0,0.5019607843,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
drawstring(-5,7,0.0," TRAFFIC SIGNALS");
glColor3f(1,0.5,0);
drawstring(-4,4,0.0,"Implimented By:");
glColor3f(0.1333333f,0.5450980392f,0.133333333f);
drawstring(-6.50,1,0.0,"Sadman Sakib  ID:011151139");
glColor3f(0.1333333f,0.5450980392f,0.133333333f);
drawstring(-6.50,-1,0.0,"Sarah Ali          ID:011151098");
glFlush();
}





void display1(){

    glColor3f(0.7,0,1);
    drawstring(-15.0,8.90,0.0,"United International University");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


    field();
    sky();


    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective



	glTranslatef(0.0,0.0,0.0);
    road();
    zebra_crossing();

    glPushMatrix();
    glTranslatef(-20.0,20.0,0.0);
    sun();
    glPopMatrix();


    glPushMatrix();
    signal1(-80.0,-35.0);
    glPopMatrix();



    glPushMatrix();
    signal1(72.0,-35.0);
    glPopMatrix();


    glPushMatrix();
    signal1(0.0,175.0);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(carmove_lft_to_rit2,2,0);
	glRotatef(180,0,1,0);
    brtc_bus();
    glPopMatrix();




    glPushMatrix();
	glTranslatef(carmove_lft_to_rit2,2.0,0);
    car();
    glPopMatrix();


     glPushMatrix();
	glTranslatef(carmove_rt_to_lft2,-9,0);
	glRotatef(180,0,1,0);
    car();
    glPopMatrix();

    glFlush();
  // glutSwapBuffers();


}


void mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(flag==0)
        frontscreen ();
    if(flag==1)
        helpscreen();
    if(flag==2)
       rules_screen();
    if(flag==3)
        display1();
    glFlush();
}


void my_keyboard(unsigned char key, int x, int y){

switch(key)
{

	case 13:
		if(flag==1)
		{
            flag=3;
            display1();
		}
		if(flag==0) //Ascii of 'enter' key is 13
		{
            flag=1;
            display1();
		}
		if(flag==2)
        {
            rules_screen();
        }

    case 't':rules_screen();


	break;

    }
    if(key == 27){
        exit(0);
    }
    if(key == 'r'){
        start = false;
    }
    if(key == 'g'){
        start = true;
    }

    if (key == 'd' && (carmove_rt_to_lft>pixel(350) ||
    carmove_rt_to_lft < pixel(-180) ) && (carmove_rt_to_lft2>pixel(260) ||
    carmove_rt_to_lft2 < pixel(-160) ) && (carmove_rt_to_lft3>pixel(300) ||
   carmove_rt_to_lft3 < pixel(-180) ) &&(carmove_lft_to_rit<pixel(-460)
  || carmove_lft_to_rit > pixel(50) ) && (carmove_lft_to_rit2<pixel(-370) ||
   carmove_lft_to_rit2 > pixel(50) )&& (carmove_lft_to_rit3<pixel(-410) ||
                                             carmove_lft_to_rit3 > pixel(60) )
)
{
        tp_to_bttm = true;
        lft_to_right = false;

            }
     if(key == 'o'){
        start = true;
        orange_light_comes = true;
    }

 }


int main()
{

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1366, 768);
	glutInitWindowPosition (20, 40 );
	glutCreateWindow ("Traffic signal created by Sadman Sakib");
	glutTimerFunc(15, alltransports_move, 1);
	init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(mydisplay);
	glutTimerFunc(15, alltransports_move, 0);
	glutMainLoop();
	return 0;
}
