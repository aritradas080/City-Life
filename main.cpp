#include <windows.h>  // for MS Windows
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.141516
#include<math.h>
#include<iostream>

using namespace std;
//variables
//sun variables
GLfloat position_sun = 0.0f;
GLfloat speed_sun = 0.01f;
//moon variables
GLfloat position_moon = 0.0f;
GLfloat speed_moon = 0.02;
//red car variables
GLfloat positionRedCar=0.0f;
GLfloat speedRedCar=0.013f;

//bus variables
GLfloat positionBus=0.0f;
GLfloat speedBus=0.01f;

//green car variables
GLfloat positionGreenCar=0.0f;
GLfloat speedGreenCar=0.01;
//blue car variables
GLfloat positionBlueCar=0.2f;
GLfloat speedBlueCar=0.01;
//train variables
GLfloat positionTrain=1.0f;
GLfloat speedTrain=0.008f;
//cloud variables
GLfloat positionCloud=0.0f;
GLfloat speedCloud=0.005f;
//rain
bool rainday=false;
bool thunder = false;
GLfloat Rainposition1= 0.0f;
GLfloat Rainspeed1 = 0.1f;


//snow variables
bool snowfall = false;
GLfloat snowposition = 1.0f;
GLfloat snowspeed = 0.02f;
static GLfloat snowcloud = 0.0;


//windmill variables
int windmill_wheel_position=0;

GLfloat fountain_wave_position=0.0f;
GLfloat fountain_wave_speed=0.01f;

//traffic signal color
GLfloat color1 = 0.0f;
GLfloat color2 = 1.0f;

//boat 01
GLfloat boat1_position = 0.6f;
GLfloat boat1_speed = 0.005f;

//boat 02
GLfloat boat2_position = 0.4;
GLfloat boat2_speed = 0.008;

//boat 1 smoke
GLfloat boat1_smoke_position = 0.25f;
GLfloat boat1_smoke_speed = 0.002f;

//boat 2 smoke
GLfloat boat2_smoke_position = 0.0f;
GLfloat boat2_smoke_speed = 0.002f;
//plane
GLfloat position_Plane=-0.3f;
GLfloat speed_Plane=0.0f;

//helicopter
bool helicopter = false;
GLfloat helicopter_position = 1.0f;
GLfloat helicopter_speed = 0.01f;
bool helicopter_search_light1 = false;

//Parachute
GLfloat position_parachute=0.4f;
GLfloat speed_parachute=0.0;
//spring variables
bool spring = false;

//bird variables
GLfloat birdPosition=0.0f;
GLfloat birdSpeed=0.01f;

//waves
GLfloat wavePosition=0.0f;
GLfloat waveSpeed=0.02f;

//speed boat variables
GLfloat speedboatPosition=0.0f;
GLfloat speedboatSpeed=0.0f;


void load_Start();
void load_DayBack();

void Idle()
{
    glutPostRedisplay();
}

//logics
//sun
void update_sun(int value)
{   if(position_sun <-1.0)
    {position_sun = 1.0f;
    }
    position_sun -= speed_sun;
    glutPostRedisplay();
	glutTimerFunc(90, update_sun, 0);
}

//moon
void update_moon(int value)
{   if(position_moon <-1.0)
    {position_moon = 1.0f;
    }
    position_moon -= speed_moon;
    glutPostRedisplay();
	glutTimerFunc(100, update_moon, 0);
}
//cloud logic
void UpdateCloud(int value){
if(positionCloud<-1.8f){
    positionCloud=1.0f;
}
positionCloud -= speedCloud;
glutPostRedisplay();
glutTimerFunc(1000/60, UpdateCloud, 0);
}

//rain logic
void Rainupdate1(int value) {

    if(Rainposition1 <-1.0)
        Rainposition1 = 1.0f;

    Rainposition1 -= Rainspeed1;

glutPostRedisplay();
glutTimerFunc(1000/70, Rainupdate1, 0);
}

//snow logic
void updateSnow(int value){
if(snowposition<-1.0f){
    snowposition = 1.0f;
}
snowposition -= snowspeed;
glutPostRedisplay();
glutTimerFunc(1000/20, updateSnow, 0);
}

//red car logic
void UpdateRedCar(int value){
if(positionRedCar > 1.6f){
    positionRedCar = -1.0f;
}
positionRedCar += speedRedCar;
glutPostRedisplay();
glutTimerFunc(1000/60, UpdateRedCar, 0);
}

//bus logic
void UpdateBus(int value){
if(positionBus > 1.8f){
    positionBus = -1.8f;
}
positionBus += speedBus;
glutPostRedisplay();
glutTimerFunc(1000/60, UpdateBus, 0);
}

//green car logic
void UpdateGreenCar(int value){
if(positionGreenCar<-1.8f){
    positionGreenCar = 1.0f;
}
positionGreenCar -= speedGreenCar;
glutPostRedisplay();
glutTimerFunc(1000/60, UpdateGreenCar, 0);
}

//blue car logic
void UpdateBlueCar(int value){
if(positionBlueCar<-1.8f){
    positionBlueCar = 1.0f;
}
positionBlueCar -= speedBlueCar;
glutPostRedisplay();
glutTimerFunc(1000/60, UpdateBlueCar, 0);
}

//train logic
void UpdateTrain(int value){

if(positionTrain<-1.6f){
    positionTrain = 1.0f;
}
positionTrain -= speedTrain;
glutPostRedisplay();
glutTimerFunc(1000/40, UpdateTrain, 0);
}

//windmill logic
void UpdateWindMill(int value){
windmill_wheel_position += 10;
if(windmill_wheel_position>=360){
    windmill_wheel_position=0;
}

glutPostRedisplay();
glutTimerFunc(1000/40, UpdateWindMill, 0);
}

//wave of fountain
void UpdateWaveFountain(int value){
if(fountain_wave_position<=0.42f){
    fountain_wave_position = 0.58f;
}
fountain_wave_position -= fountain_wave_speed;
glutPostRedisplay();
glutTimerFunc(1000/40, UpdateWaveFountain, 0);
}

//boat1 logic
void UpdateBoat1(int value){
if(boat1_position<=-1.0f){
    boat1_position = 1.0f;
}
boat1_position -= boat1_speed;
glutPostRedisplay();
glutTimerFunc(100, UpdateBoat1, 0);
}

//boat2 logic
void UpdateBoat2(int value){
if(boat2_position<=-1.4f){
    boat2_position = 1.1f;
}
boat2_position -= boat2_speed;
glutPostRedisplay();
glutTimerFunc(100, UpdateBoat2, 0);
}

//speedBoat logic
void UpdateSpeedBoat(int value){
if(speedboatPosition<=-1.4f){
    speedboatPosition = 0.1f;
}
speedboatPosition -= speedboatSpeed;
glutPostRedisplay();
glutTimerFunc(100, UpdateSpeedBoat, 0);
}

//boat1 smoke
void UpdateBoat1Smoke(int value){
if(boat1_smoke_position>=0.04f){
    boat1_smoke_position=0.001f;
}
boat1_smoke_position += boat1_smoke_speed;
glutPostRedisplay();
glutTimerFunc(100, UpdateBoat1Smoke, 0);
}

//boat2 smoke
void UpdateBoat2Smoke(int value){
if(boat2_smoke_position>=0.038f){
    boat2_smoke_position=0.001f;
}
boat2_smoke_position += boat2_smoke_speed;
glutPostRedisplay();
glutTimerFunc(100, UpdateBoat2Smoke, 0);
}
//plane logic
void UpdatePlane(int value){
if(position_Plane > 1.8f){
    position_Plane = -1.0f;
}
position_Plane += speed_Plane;
glutPostRedisplay();
glutTimerFunc(1000/60, UpdatePlane, 0);
}

//helicopter logic
void UpdateHelicopter(int value){
if(helicopter_position<-1.8f){
    helicopter_position = 1.0f;
}
helicopter_position -= helicopter_speed;
glutPostRedisplay();
glutTimerFunc(50, UpdateHelicopter, 0);
}

//Parachute Logic
void UpdateParachute(int value){
if(position_parachute<-1.7f){
    position_parachute = 1.0f;
}
position_parachute -= speed_parachute;
glutPostRedisplay();
glutTimerFunc(1000/60, UpdateParachute, 0);
}


//bird logic
void UpdateBird(int value){

if(birdPosition>=1.0f){
    birdPosition = -1.0f;
}
birdPosition += birdSpeed;
glutPostRedisplay();
glutTimerFunc(50, UpdateBird, 0);
}

//wave logic
void UpdateWave(int value){

if(wavePosition>=1.0f){
    wavePosition = -1.0f;
}
wavePosition += waveSpeed;
glutPostRedisplay();
glutTimerFunc(50, UpdateWave, 0);
}
//display
//sun
void Sun(){
glPushMatrix();
glTranslatef(0.0f, position_sun,0.0f);
int k;

GLfloat d1=0.7f;
GLfloat d2= 0.85f;
GLfloat r7 = 0.08f;
int triangle7=50;
GLfloat tp7 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f (d1,d2);
for(k= 0;k<=triangle7; k++)
{
glVertex2f (
d1+(r7*cos(k*tp7/triangle7)),
d2+(r7*sin(k*tp7/triangle7))
);
}
glEnd ();
glPopMatrix();
glLoadIdentity();
}

//moon
void Moon(){
glPushMatrix();
glTranslatef(0.0f, position_moon,0.0f);
int k;

GLfloat z1=-0.7f;
GLfloat z2= 0.85f;
GLfloat r100 = 0.08f;
int triangle100=50;
GLfloat tp100 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f (z1,z2);
for(k= 0;k<=triangle100; k++)
{
glVertex2f (
z1+(r100*cos(k*tp100/triangle100)),
z2+(r100*sin(k*tp100/triangle100))
);
}
glEnd ();
glPopMatrix();
glLoadIdentity();
}

//cloud
void Cloud1(){
glPushMatrix();
glTranslatef(-positionCloud, 0.0f,0.0f);
    int i;

    //1
    GLfloat p2=-0.88f; GLfloat q2= 0.84f; GLfloat r2 = 0.04;
    int tringle3=40;

    GLfloat tp3 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp3/tringle3)),
                    q2+(r2*sin(i*tp3/tringle3))
                    );


    }
    glEnd ();
    //2

    GLfloat p3=-0.83f; GLfloat q3= 0.87f; GLfloat r3 = 0.05f;
    int tringle4=40;

    GLfloat tp4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp4/tringle4)),
                    q3+(r3*sin(i*tp4/tringle4))
                    );


    }
    glEnd ();

    //3
    GLfloat p4=-0.795f; GLfloat q4= 0.9f; GLfloat r4 = 0.05f;
    int tringle5=40;

    GLfloat tp5 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p4,q4);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp5/tringle5)),
                    q4+(r4*sin(i*tp5/tringle5))
                    );


    }
    glEnd ();

    //4
    GLfloat p5=-0.76f; GLfloat q5= 0.86f; GLfloat r5 = 0.04f;
    int tringle6=40;

    GLfloat tp6 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p5,q5);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp6/tringle6)),
                    q5+(r5*sin(i*tp6/tringle6))
                    );


    }
    glEnd ();


    //5
    GLfloat p6=-0.815f; GLfloat q6= 0.82f; GLfloat r6 = 0.04f;
    int tringle7=40;

    GLfloat tp7 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p6,q6);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p6+(r6*cos(i*tp7/tringle7)),
                    q6+(r6*sin(i*tp7/tringle7))
                    );


    }
    glEnd ();


glPopMatrix();

glLoadIdentity();
}
void Thunder_With_Cloud1(){
    glPushMatrix();
    glTranslatef(-positionCloud, 0.0f,0.0f);
    if(thunder==true){
    //Thunder Effect
    //Left Side Cloud
    glBegin(GL_POLYGON);
    glColor3ub	(255,255,0);
    glVertex2f(-0.83f,0.74f);
    glVertex2f(-0.78f,0.72f);
    glColor3ub  (245,245,245);
    glVertex2f(-0.8f,0.75f);
    glVertex2f(-0.79f,0.82f);

    glVertex2f(-0.8f,0.82f);
    glEnd();

    //border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.83f,0.74f);
    glVertex2f(-0.78f,0.72f);

    glVertex2f(-0.78f,0.72f);
    glVertex2f(-0.8f,0.75f);

    glVertex2f(-0.8f,0.75f);
    glVertex2f(-0.79f,0.82f);

    glVertex2f(-0.83f,0.74f);
    glVertex2f(-0.8f,0.82f);

    glVertex2f(-0.79f,0.82f);
    glVertex2f(-0.8f,0.82f);

    glEnd();
    }
    glPopMatrix();
    glLoadIdentity();
}

void Static_thunder(){
    if(thunder == true){
    glLineWidth(5);

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.3f,0.99f);
	glVertex2f(0.29f,0.98f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.98f);
	glVertex2f(0.285f,0.975f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.285f,0.975f);
	glVertex2f(0.28f,0.97f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.28f,0.97f);
	glVertex2f(0.22f,0.95f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.22f,0.95f);
	glVertex2f(0.24f,0.93f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.24f,0.93f);
	glVertex2f(0.21f,0.91f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.21f,0.91f);
	glVertex2f(0.15f,0.88f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.15f,0.88f);
	glVertex2f(0.155f,0.82f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.155f,0.82f);
	glVertex2f(0.12f,0.81f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.155f,0.82f);
	glVertex2f(0.16f,0.77f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.24f,0.93f);
	glVertex2f(0.25f,0.92f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.25f,0.92f);
	glVertex2f(0.25f,0.86f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.25f,0.86f);
	glVertex2f(0.3f,0.83f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.3f,0.83f);
	glVertex2f(0.29f,0.82f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.82f);
	glVertex2f(0.31f,0.81f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.31f,0.81f);
	glVertex2f(0.3f,0.78f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.3f,0.78f);
	glVertex2f(0.315f,0.76f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.315f,0.76f);
	glVertex2f(0.29f,0.71f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.71f);
	glVertex2f(0.26f,0.7f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.26f,0.7f);
	glVertex2f(0.25f,0.67f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.71f);
	glVertex2f(0.31f,0.68f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.31f,0.68f);
	glVertex2f(0.315f,0.675f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.315f,0.675f);
	glVertex2f(0.305f,0.67f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.305f,0.67f);
	glVertex2f(0.32f,0.65f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.32f,0.65f);
	glVertex2f(0.29f,0.63f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.63f);
	glVertex2f(0.285f,0.6f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.24f,0.93f);
	glVertex2f(0.28f,0.94f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.28f,0.94f);
	glVertex2f(0.33f,0.925f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.33f,0.925f);
	glVertex2f(0.35f,0.9f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.35f,0.9f);
	glVertex2f(0.39f,0.885f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.39f,0.885f);
	glVertex2f(0.37f,0.84f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.39f,0.885f);
	glVertex2f(0.42f,0.87f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.42f,0.87f);
	glVertex2f(0.425f,0.81f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.425f,0.81f);
	glVertex2f(0.435f,0.8f);

	glEnd();
    }



    glLoadIdentity();
}
void Static_thunder2()
{
    if(thunder ==  true){

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-1.0f,1.0f);
	glVertex2f(-0.98f,0.97f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98f,0.97f);
	glVertex2f(-0.97f,0.94f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.97f,0.94f);
	glVertex2f(-0.94f,0.92f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.94f,0.92f);
	glVertex2f(-0.945f,0.93f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.945f,0.93f);
	glVertex2f(-0.95f,0.915f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.95f,0.915f);
	glVertex2f(-0.92f,0.905f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.92f,0.905);
	glVertex2f(-0.91f,0.88f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.91f,0.88f);
	glVertex2f(-0.89f,0.89f);

	glEnd();

    glTranslatef(-1.13,-0.04,0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.24f,0.93f);
	glVertex2f(0.25f,0.92f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.25f,0.92f);
	glVertex2f(0.25f,0.86f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.25f,0.86f);
	glVertex2f(0.3f,0.83f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.3f,0.83f);
	glVertex2f(0.29f,0.82f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.82f);
	glVertex2f(0.31f,0.81f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.31f,0.81f);
	glVertex2f(0.3f,0.78f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.3f,0.78f);
	glVertex2f(0.315f,0.76f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.315f,0.76f);
	glVertex2f(0.29f,0.71f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.71f);
	glVertex2f(0.26f,0.7f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.26f,0.7f);
	glVertex2f(0.25f,0.67f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.71f);
	glVertex2f(0.31f,0.68f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.31f,0.68f);
	glVertex2f(0.315f,0.675f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.315f,0.675f);
	glVertex2f(0.305f,0.67f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.305f,0.67f);
	glVertex2f(0.32f,0.65f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.32f,0.65f);
	glVertex2f(0.29f,0.63f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.29f,0.63f);
	glVertex2f(0.285f,0.6f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.24f,0.93f);
	glVertex2f(0.28f,0.94f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.28f,0.94f);
	glVertex2f(0.33f,0.925f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.33f,0.925f);
	glVertex2f(0.35f,0.9f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.35f,0.9f);
	glVertex2f(0.39f,0.885f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.39f,0.885f);
	glVertex2f(0.37f,0.84f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.39f,0.885f);
	glVertex2f(0.42f,0.87f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.42f,0.87f);
	glVertex2f(0.425f,0.81f);

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(0.425f,0.81f);
	glVertex2f(0.435f,0.8f);

	glEnd();

    }

	glLoadIdentity();


}


void Cloud2(){
glPushMatrix();
glTranslatef(positionCloud, 0.0f,0.0f);
    int i;

    //1
    GLfloat p2=0.88f; GLfloat q2= 0.84f; GLfloat r2 = 0.04;
    int tringle3=40;

    GLfloat tp3 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp3/tringle3)),
                    q2+(r2*sin(i*tp3/tringle3))
                    );


    }
    glEnd ();
    //2

    GLfloat p3=0.86f; GLfloat q3= 0.87f; GLfloat r3 = 0.04f;
    int tringle4=40;

    GLfloat tp4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp4/tringle4)),
                    q3+(r3*sin(i*tp4/tringle4))
                    );


    }
    glEnd ();

    //3
    GLfloat p4=0.78f; GLfloat q4= 0.86f; GLfloat r4 = 0.06f;
    int tringle5=40;

    GLfloat tp5 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p4,q4);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp5/tringle5)),
                    q4+(r4*sin(i*tp5/tringle5))
                    );


    }
    glEnd ();

    //4
    GLfloat p5=0.82f; GLfloat q5= 0.86f; GLfloat r5 = 0.04f;
    int tringle6=40;

    GLfloat tp6 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p5,q5);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp6/tringle6)),
                    q5+(r5*sin(i*tp6/tringle6))
                    );


    }
    glEnd ();


    //5
    GLfloat p6=0.815f; GLfloat q6= 0.82f; GLfloat r6 = 0.04f;
    int tringle7=40;

    GLfloat tp7 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p6,q6);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p6+(r6*cos(i*tp7/tringle7)),
                    q6+(r6*sin(i*tp7/tringle7))
                    );


    }
    glEnd ();

glPopMatrix();

glLoadIdentity();
}

void Thunder_With_Cloud2(){
    glPushMatrix();
    glTranslatef(positionCloud, 0.0f,0.0f);
    //Thunder Effect
    if(thunder==true){

    //Right Side Cloud
    glBegin(GL_POLYGON);
    glColor3ub	(255,255,0);
    glVertex2f(0.83f,0.74f);
    glVertex2f(0.78f,0.72f);
    glColor3ub  (245,245,245);
    glVertex2f(0.8f,0.75f);
    glVertex2f(0.79f,0.82f);
    glVertex2f(0.8f,0.82f);
    glEnd();

    //border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.83f,0.74f);
    glVertex2f(0.78f,0.72f);

    glVertex2f(0.78f,0.72f);
    glVertex2f(0.8f,0.75f);

    glVertex2f(0.8f,0.75f);
    glVertex2f(0.79f,0.82f);

    glVertex2f(0.83f,0.74f);
    glVertex2f(0.8f,0.82f);

    glVertex2f(0.79f,0.82f);
    glVertex2f(0.8f,0.82f);

    glEnd();
    }
    glPopMatrix();
    glLoadIdentity();
}


//day sky
void daySky(){
	glBegin(GL_QUADS);
	glColor3ub(57, 162, 244);
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(177, 231, 247);
	glVertex2f(-1.0f, 0.42f);
    glVertex2f(1.0f, 0.42f);
	glVertex2f(1.0f, 1.0f);
    glEnd();

    glLoadIdentity();
}
//night sky
void nightSky(){
	glBegin(GL_QUADS);
    glColor3ub(3, 55, 95);
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(10, 15, 25);
	glVertex2f(-1.0f, 0.42f);
    glVertex2f(1.0f, 0.42f);
	glVertex2f(1.0f, 1.0f);
    glEnd();

    glLoadIdentity();
}
//evening sky
void eveningSky(){
	glBegin(GL_QUADS);
	glColor3ub(255, 153, 51);
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(255, 178, 102);
	glVertex2f(-1.0f, 0.42f);
    glVertex2f(1.0f, 0.42f);
	glVertex2f(1.0f, 1.0f);
    glEnd();

    glLoadIdentity();
}
//rainy sky
void Rainy_Sky(){
if(rainday==true)
    {
  	glBegin(GL_QUADS);
    glColor3ub (135,206,250)  ;
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(128,128,128);
	glVertex2f(-1.0f, 0.42f);
	glColor3ub(1,1,20);
    glVertex2f(1.0f, 0.42f);
	glVertex2f(1.0f, 1.0f);


    glEnd();


    }
    glLoadIdentity();
}



//snow sky
void Snow_Sky(){
if(snowfall==true)
    {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.3f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, 0.42f);
    glVertex2f(1.0f, 0.42f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
    }
    glLoadIdentity();
}

//Plane
void Plane(){
    glPushMatrix();
    glTranslatef(position_Plane,0.0f,0.0f);
    //Plane body
	glBegin(GL_POLYGON);
	glColor3ub(255,255,224);
	glVertex2f(-0.875f, 0.84f);
	glVertex2f(-0.75f, 0.84f);
	glVertex2f(-0.71f, 0.84f);
	glVertex2f(-0.728f, 0.855f);
	glVertex2f(-0.75f, 0.88f);
	glVertex2f(-0.86f, 0.88f);
	glVertex2f(-0.87f, 0.915f);
	glVertex2f(-0.89f, 0.915f);
	glEnd();

	//border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.875f, 0.84f);
    glVertex2f(-0.708f, 0.84f);

    glVertex2f(-0.708f, 0.84f);
    glVertex2f(-0.75f, 0.88f);

    glVertex2f(-0.75f, 0.88f);
    glVertex2f(-0.86f, 0.88f);

    glVertex2f(-0.86f, 0.88f);
    glVertex2f(-0.87f, 0.915f);

    glVertex2f(-0.87f, 0.915f);
    glVertex2f(-0.89f, 0.915f);

    glVertex2f(-0.89f, 0.915f);
    glVertex2f(-0.875f, 0.84f);

    glEnd();

    //Upper-wing
	glBegin(GL_QUADS);
	glColor3ub(220,220,220);
	glVertex2f(-0.825f, 0.91f);
	glVertex2f(-0.82f, 0.88f);
	glVertex2f(-0.795f, 0.88f);
	glVertex2f(-0.81f, 0.91f);
	glEnd();

	//border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-0.825f, 0.91f);
	glVertex2f(-0.82f, 0.88f);

	glVertex2f(-0.82f, 0.88f);
	glVertex2f(-0.795f, 0.88f);

    glVertex2f(-0.795f, 0.88f);
	glVertex2f(-0.81f, 0.91f);

    glVertex2f(-0.825f, 0.91f);
	glVertex2f(-0.81f, 0.91f);


    glEnd();

	//lower-wing
    glBegin(GL_QUADS);
	glColor3ub(220,220,220);
	glVertex2f(-0.82f, 0.84f);
	glVertex2f(-0.825f, 0.815f);
	glVertex2f(-0.81f, 0.815f);
	glVertex2f(-0.795f, 0.84f);
	glEnd();

    //border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

	glVertex2f(-0.82f, 0.84f);
	glVertex2f(-0.825f, 0.815f);

	glVertex2f(-0.825f, 0.815f);
	glVertex2f(-0.81f, 0.815f);

	glVertex2f(-0.81f, 0.815f);
	glVertex2f(-0.795f, 0.84f);

	glVertex2f(-0.82f, 0.84f);
	glVertex2f(-0.795f, 0.84f);


    glEnd();


    //back-wing
    glBegin(GL_QUADS);
	glColor3ub(220,220,220);
	glVertex2f(-0.883f, 0.88f);
	glVertex2f(-0.894f, 0.855f);
	glVertex2f(-0.885f, 0.855f);
	glVertex2f(-0.88f, 0.865f);
	glEnd();


    //border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

	glVertex2f(-0.883f, 0.88f);
	glVertex2f(-0.894f, 0.855f);

	glVertex2f(-0.894f, 0.855f);
	glVertex2f(-0.885f, 0.855f);

	glVertex2f(-0.885f, 0.855f);
	glVertex2f(-0.88f, 0.865f);

	glVertex2f(-0.883f, 0.88f);
	glVertex2f(-0.88f, 0.865f);


    glEnd();


	//lower -design
    glBegin(GL_QUADS);
	glColor3ub(70,130,180);
	glVertex2f(-0.88f, 0.855f);
	glVertex2f(-0.875f, 0.84f);
	glVertex2f(-0.71f, 0.84f);
	glVertex2f(-0.72f, 0.855f);
	glEnd();

    //border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

	glVertex2f(-0.88f, 0.855f);
	glVertex2f(-0.875f, 0.84f);

	glVertex2f(-0.875f, 0.84f);
	glVertex2f(-0.71f, 0.84f);

	glVertex2f(-0.71f, 0.84f);
	glVertex2f(-0.72f, 0.855f);

	glVertex2f(-0.88f, 0.855f);
	glVertex2f(-0.72f, 0.855f);


    glEnd();

	//front window

	glBegin(GL_POLYGON);
	glColor3ub	(0,206,209);
	glVertex2f(-0.76f, 0.86f);
	glVertex2f(-0.731f, 0.86f);
	glVertex2f(-0.75f, 0.88f);
	glVertex2f(-0.76f, 0.88f);
	glVertex2f(-0.766f, 0.87f);

	glEnd();

	//side window
	//1
    int p;

    GLfloat pl1=-0.85f; GLfloat ql1= 0.87f; GLfloat rl1 = 0.008f;
    int tringlel2=40;

    GLfloat tpl2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub	(72,209,204);
    glVertex2f (pl1,ql1);
    for(p= 0;p<=tringlel2; p++)
    {
        glVertex2f (
                    pl1+(rl1*cos(p*tpl2/tringlel2)),
                    ql1+(rl1*sin(p*tpl2/tringlel2))
                    );
    }
    glEnd ();

    //2

    GLfloat pl2=-0.825f; GLfloat ql2= 0.87f; GLfloat rl2 = 0.008f;
    int tringlel3=40;

    GLfloat tpl3 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub	(72,209,204);
    glVertex2f (pl2,ql2);
    for(p= 0;p<=tringlel3; p++)
    {
        glVertex2f (
                    pl2+(rl2*cos(p*tpl3/tringlel3)),
                    ql2+(rl2*sin(p*tpl3/tringlel3))
                    );
    }
    glEnd ();

    //3

    GLfloat pl3=-0.8f; GLfloat ql3= 0.87f; GLfloat rl3 = 0.008f;
    int tringlel4=40;

    GLfloat tpl4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub	(72,209,204);
    glVertex2f (pl3,ql3);
    for(p= 0;p<=tringlel3; p++)
    {
        glVertex2f (
                    pl3+(rl3*cos(p*tpl4/tringlel4)),
                    ql3+(rl3*sin(p*tpl4/tringlel4))
                    );
    }
    glEnd ();

    //4

    GLfloat pl4=-0.775f; GLfloat ql4= 0.87f; GLfloat rl4 = 0.008f;
    int tringlel5=40;

    GLfloat tpl5 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub			(72,209,204);
    glVertex2f (pl4,ql4);
    for(p= 0;p<=tringlel5; p++)
    {
        glVertex2f (
                    pl4+(rl4*cos(p*tpl5/tringlel5)),
                    ql4+(rl4*sin(p*tpl5/tringlel5))
                    );
    }
    glEnd ();

glPopMatrix();


glLoadIdentity();

}



//greenery
void greenery(){
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(1.0f, 0.42f);
    glVertex2f(0.1f, 0.42f);
    glVertex2f(1.0f, 0.12f);
    glEnd();

    glLoadIdentity();

}

void boatDock(){
    glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex2f(0.4,0.32f);
    glVertex2f(0.3,0.24f);
    glVertex2f(0.38,0.22f);
    glVertex2f(0.48,0.295f);
    glEnd();

    //Border
    glLineWidth(1.8);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.4,0.32f);
    glVertex2f(0.3,0.24f);

    glVertex2f(0.3,0.24f);
    glVertex2f(0.38,0.22f);

    glVertex2f(0.38,0.22f);
    glVertex2f(0.48,0.295f);

    glEnd();


    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.4f,0.256f);
    glVertex2f(0.4f,0.22f);

    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.42f,0.27f);
    glVertex2f(0.42f,0.23f);

    glEnd();


    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.44f,0.29f);
    glVertex2f(0.44f,0.25f);

    glEnd();


    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.46f,0.306f);
    glVertex2f(0.46f,0.26f);

    glEnd();
    //---
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.31f,0.25f);
    glVertex2f(0.31f,0.28f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.33f,0.30f);
    glVertex2f(0.33f,0.265f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.35f,0.32f);
    glVertex2f(0.35f,0.279f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.37f,0.34f);
    glVertex2f(0.37f,0.299f);
    glEnd();


    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.37f,0.34f);
    glVertex2f(0.37f,0.299f);
    glEnd();

    //--
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.39f,0.24f);
    glVertex2f(0.465f,0.29f);
    glEnd();


    //--
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.31f,0.26f);
    glVertex2f(0.375f,0.315f);
    glEnd();

glLoadIdentity();
}

//speedBoat
void speedBoat(){
    glTranslatef(speedboatPosition,0.0f,0.0f);
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(240,240,220);
    glVertex2f(0.26f,0.32f);
    glVertex2f(0.3f,0.30f);
    glVertex2f(0.34f,0.30f);
    glVertex2f(0.35f,0.32f);
    glEnd();

    //border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub	(128,128,128);
    glVertex2f(0.26f,0.32f);
    glVertex2f(0.3f,0.30f);

    glVertex2f(0.3f,0.30f);
    glVertex2f(0.34f,0.30f);

    glVertex2f(0.34f,0.30f);
    glVertex2f(0.35f,0.32f);

    glVertex2f(0.26f,0.32f);
    glVertex2f(0.35f,0.32f);

    glEnd();




    glBegin(GL_TRIANGLES);
    glColor3ub(245,222,179);
    glVertex2f(0.3f,0.34f);
    glVertex2f(0.26f,0.32f);
    glVertex2f(0.31f,0.32f);
    glEnd();

    //border
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub	(128,128,128);
    glVertex2f(0.3f,0.34f);
    glVertex2f(0.26f,0.32f);

    glVertex2f(0.26f,0.32f);
    glVertex2f(0.31f,0.32f);

    glVertex2f(0.3f,0.34f);
    glVertex2f(0.31f,0.32f);

    glEnd();
    //--
    //design
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(72,61,139);
    glVertex2f(0.27f,0.32f);
    glVertex2f(0.29f,0.33f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(72,61,139);
    glVertex2f(0.29f,0.33f);
    glVertex2f(0.3f,0.32f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(72,61,139);
    glVertex2f(0.27f,0.32f);
    glVertex2f(0.3f,0.32f);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(72,61,139);
    glVertex2f(0.28f,0.31f);
    glVertex2f(0.345f,0.31f);
    glEnd();
    glPopMatrix();


glLoadIdentity();
}

//speedBoat Translation
void translateSpeedBoat(){

glPushMatrix();
glTranslatef(0.2f,-0.1f,0.0f);
speedBoat();
glPopMatrix();
glLoadIdentity();
}

//greenery trees
void greenery_trees(){
    //tree 01
    //tree stand 01, 01
    glLineWidth(5);
    glBegin(GL_LINES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(153,76,0);}
    glVertex2f(0.3f, 0.48f);
    glColor3ub(204,102,0);
    glVertex2f(0.3f, 0.36f);
    glEnd();

    //leafs
    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(51,102,0);
    glVertex2f(0.3f, 0.48f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
   glColor3ub(51,102,0);
    glVertex2f(0.29f, 0.46f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(51,102,0);
    glVertex2f(0.28f, 0.45f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(51,102,0);
    glVertex2f(0.27f, 0.46f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub(255,0,0);}
    glVertex2f(0.28f, 0.47f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    {glColor3ub(255,255,255);}
    {glColor3ub(51,102,0);}
    glVertex2f(0.31f, 0.46f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub(255,0,0);}
    glVertex2f(0.32f, 0.45f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub(255,0,0);}
    glVertex2f(0.33f, 0.44f);
    glEnd();


    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
     if (spring == true) {glColor3ub(255,0,0);}
    glVertex2f(0.33f, 0.43f);
    glEnd();


    glPointSize(12);
    glBegin(GL_POINTS);
    {glColor3ub(255,255,255);}
   {glColor3ub(51,102,0);}
    glVertex2f(0.33f, 0.44f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    {glColor3ub(255,255,255);}
    {glColor3ub(51,102,0);}
    glVertex2f(0.34f, 0.44f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub(255,0,0);}
    glVertex2f(0.33f, 0.46f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub	(255,127,80);}
    glVertex2f(0.33f, 0.48f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub	(255,127,80);}
    glVertex2f(0.33f, 0.50f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub	(255,127,80);}
    glVertex2f(0.32f, 0.50f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
   {glColor3ub(255,255,255);}
    {glColor3ub(51,102,0);}
    glVertex2f(0.31f, 0.49f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub	(255,127,80);}
    glVertex2f(0.32f, 0.46f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    glVertex2f(0.32f, 0.47f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub	(255,127,80);}
    glVertex2f(0.255f, 0.47f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    glVertex2f(0.255f, 0.48f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    glVertex2f(0.26f, 0.49f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub	(255,127,80);}
    glVertex2f(0.26f, 0.51f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    glVertex2f(0.265f, 0.50f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    if (spring == true) {glColor3ub	(255,127,80);}
    glVertex2f(0.27f, 0.50f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    if (snowfall==false){glColor3ub(51,102,0);}
    glVertex2f(0.28f, 0.50f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(51,102,0);}
    glVertex2f(0.285f, 0.50f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(51,102,0);}
    glVertex2f(0.285f, 0.52f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.295f, 0.52f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.34f, 0.47f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.34f, 0.49f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.27f, 0.53f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.275f, 0.54f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.30f, 0.54f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.30f, 0.52f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.31f, 0.52f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if (snowfall==false){glColor3ub(0,153,0);}
    glVertex2f(0.315f, 0.52f);
    glEnd();
glLoadIdentity();
}


void extra_greenery_trees(){

glPushMatrix();
glTranslatef(-0.15f,0.03f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.1f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.2f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.1f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.2f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.3f,0.06f,0.0f);
greenery_trees();
glPopMatrix();


glPushMatrix();
glTranslatef(0.4f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.5f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.6f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.7f,0.06f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.7f,-0.24f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.6f,-0.2f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.5f,-0.16f,0.0f);
greenery_trees();
glPopMatrix();

glPushMatrix();
glTranslatef(0.4f,-0.12f,0.0f);
greenery_trees();
glPopMatrix();

glLoadIdentity();
}
//Parachute
void Parachute(){

    glPushMatrix();
    glTranslatef(position_parachute,0.0f,0.0f);

    //upper part
    int i = 0;

    GLfloat pr1=0.615f; GLfloat qr1= 0.80f; GLfloat rr1 = 0.015f;
    int tringler2=40;

    GLfloat tpr2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(255,69,0);
    glVertex2f (pr1,qr1);
    for(i= 0;i<=tringler2; i++)
    {
        glVertex2f (
                    pr1+(rr1*cos(i*tpr2/tringler2)),
                    qr1+(rr1*sin(i*tpr2/tringler2))
                    );
    }
    glEnd ();
    //--
    GLfloat pr2=0.639f; GLfloat qr2= 0.81f; GLfloat rr2 = 0.016f;
    int tringler3=40;

    GLfloat tpr3 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(255,215,0);
    glVertex2f (pr2,qr2);
    for(i= 0;i<=tringler3; i++)
    {
        glVertex2f (
                    pr2+(rr2*cos(i*tpr3/tringler3)),
                    qr2+(rr2*sin(i*tpr3/tringler3))
                    );


    }
    glEnd ();
    //----

    GLfloat pr3=0.665f; GLfloat qr3= 0.808f; GLfloat rr3 = 0.016f;
    int tringler4=40;

    GLfloat tpr4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(106,90,205);
    glVertex2f (pr3,qr3);
    for(i= 0;i<=tringler4; i++)
    {
        glVertex2f (
                    pr3+(rr3*cos(i*tpr4/tringler4)),
                    qr3+(rr3*sin(i*tpr4/tringler4))
                    );


    }
    glEnd ();

    //---

    GLfloat pr4=0.688f; GLfloat qr4= 0.80f; GLfloat rr4 = 0.013f;
    int tringler5=40;

    GLfloat tpr5 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(210,105,30);
    glVertex2f (pr4,qr4);
    for(i= 0;i<=tringler5; i++)
    {
        glVertex2f (
                    pr4+(rr4*cos(i*tpr5/tringler5)),
                    qr4+(rr4*sin(i*tpr5/tringler5))
                    );


    }
    glEnd ();



    glBegin(GL_QUADS);
    glColor3ub(139,0,0);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.63f,0.67f);
    glColor3ub(138,43,226);
    glVertex2f(0.67f,0.67f);
    glVertex2f(0.7f,0.8f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(255,69,0);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.65f,0.67f);
    glVertex2f(0.625f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,215,0);
    glVertex2f(0.625f,0.8f);
    glVertex2f(0.65f,0.67f);
    glVertex2f(0.65f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(106,90,205);
    glVertex2f(0.65f,0.8f);
    glVertex2f(0.65f,0.67f);
    glVertex2f(0.675f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(210,105,30);
    glVertex2f(0.675f,0.8f);
    glVertex2f(0.65f,0.67f);
    glVertex2f(0.7f,0.8f);
    glEnd();


    //lower part
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2f(0.63f,0.63f);
    glVertex2f(0.63f,0.59f);
    glVertex2f(0.67f,0.59f);
    glVertex2f(0.67f,0.63f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.635f,0.67f);
    glVertex2f(0.635f,0.63f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.64f,0.67f);
    glVertex2f(0.64f,0.63f);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.66f,0.67f);
    glVertex2f(0.66f,0.63f);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.665f,0.67f);
    glVertex2f(0.665f,0.63f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(253,245,230);
    glVertex2f(0.63f,0.61f);
    glVertex2f(0.63f,0.60f);
    glVertex2f(0.67f,0.60f);
    glVertex2f(0.67f,0.61f);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.63f,0.624f);
    glVertex2f(0.67f,0.624f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.63f,0.6f);
    glVertex2f(0.67f,0.6f);
    glEnd();


glPopMatrix();
glLoadIdentity();
}

//windmill
void windmill(){

glPushMatrix();
glBegin(GL_QUADS);
glColor3ub(96,96,96);
glVertex2f(0.5f, 0.72f);
glVertex2f(0.5f, 0.32f);
glVertex2f(0.52f, 0.32f);
glVertex2f(0.52f, 0.72f);
glEnd();

glPushMatrix();
    glTranslatef(0.51,0.72,0);
        glPushMatrix();
            glRotatef(windmill_wheel_position,0,0,1);
                    glLineWidth(15);
                    glBegin(GL_LINES);
                    if(snowfall==false){glColor3ub(153,76,0);}
                    else if(snowfall==true){glColor3ub(255,255,255);}
                    glVertex2f(-0.2f, 0.0f);
                    glVertex2f( 0.2f, 0.00f);
                    glVertex2f( 0.0f, -0.2f);
                    glVertex2f(-0.0f,  0.2f);
                    glEnd();

                    //outer circle part
                int k;

                GLfloat d1=0.0f;
                GLfloat d2= 0.0f;
                GLfloat r1 = 0.02f;
                GLfloat r2 = 0.01f;
                int triangle1=50;
                GLfloat tp1 =2.0f * PI ;

                glBegin (GL_TRIANGLE_FAN);
                    glColor3ub(255,255,0);
                    glVertex2f (d1,d2);
                    for(k= 0;k<=triangle1; k++)
                        {
                            glVertex2f (
                                d1+(r1*cos(k*tp1/triangle1)),
                                d2+(r1*sin(k*tp1/triangle1))
                        );
                    }
                glEnd ();
                //inner circle
                 glBegin (GL_TRIANGLE_FAN);
                    glColor3ub(153,76,0);
                    glVertex2f (d1,d2);
                    for(k= 0;k<=triangle1; k++)
                        {
                            glVertex2f (
                                d1+(r2*cos(k*tp1/triangle1)),
                                d2+(r2*sin(k*tp1/triangle1))
                        );
                    }
                glEnd ();

        glPopMatrix();
    glPopMatrix();


glLoadIdentity();
}


//hills windmills
void hills_windmills(){

//hill_windmill 01
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.16f, 0.56f);
glVertex2f(0.16f, 0.66f);
glEnd();

glPushMatrix();
    glTranslatef(0.16,0.66,0);
        glPushMatrix();
            glRotatef(windmill_wheel_position,0,0,1);
                    glLineWidth(3);
                    glBegin(GL_LINES);

                    glColor3f(0.0f, 0.0f, 0.0f);
                    glVertex2f(-0.025f, 0.0f);
                    glVertex2f( 0.025f, 0.00f);
                    glVertex2f( 0.0f, -0.025f);
                    glVertex2f(-0.0f,  0.025f);
                    glEnd();

        glPopMatrix();
    glPopMatrix();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.0f, 0.42f);
glVertex2f(0.0f, 0.66f);
glEnd();

glPushMatrix();
    glTranslatef(0.0,0.66,0);
        glPushMatrix();
            glRotatef(windmill_wheel_position,0,0,1);
                    glLineWidth(3);
                    glBegin(GL_LINES);

                    glColor3f(0.0f, 0.0f, 0.0f);
                    glVertex2f(-0.025f, 0.0f);
                    glVertex2f( 0.025f, 0.00f);
                    glVertex2f( 0.0f, -0.025f);
                    glVertex2f(-0.0f,  0.025f);
                    glEnd();

        glPopMatrix();
    glPopMatrix();

glLoadIdentity();
}

//hills
//hills
void Hills(){

    //hill with fountain
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.24f, 0.68f);
    glVertex2f(-0.52f, 0.42f);
    glVertex2f(0.0f, 0.42f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex2f(-0.41f, 0.70f);
    glVertex2f(-0.64f, 0.42f);
    glVertex2f(-0.18f, 0.42f);
    glEnd();

    //red hills 02
    glBegin(GL_TRIANGLES);
    glColor3ub(153,122,0);
    glVertex2f(0.16f, 0.42f);
    glColor3ub(255,128,0);
    glVertex2f(0.48f, 0.42f);
    glColor3ub(255,178,102);
    glVertex2f(0.32f, 0.72f);
    glEnd();

    //red hills 02
    glBegin(GL_TRIANGLES);
    glColor3ub(153,76,0);
    glVertex2f(-0.08f, 0.42f);
    glColor3ub(255,128,0);
    glVertex2f(0.32f, 0.42f);
    glColor3ub(255,178,102);
    glVertex2f(0.16f, 0.62f);
    glEnd();

    //red hills 01
    glBegin(GL_TRIANGLES);
    glColor3ub(153,76,0);
    glVertex2f(-0.16f, 0.42f);
    glColor3ub(255,128,0);
    glVertex2f(0.0f, 0.42f);
    glColor3ub(255,178,102);
    glVertex2f(-0.08f, 0.52f);
    glEnd();


    glLoadIdentity();
}
//fountain
void fountain(){

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.10f, 0.42f);
    glVertex2f(-0.36f, 0.64f);
    glVertex2f(-0.18f, 0.42f);
    glEnd();

}

//fountain waves
void fountain_waves(){
glTranslatef(-fountain_wave_position,fountain_wave_position-0.42f,0.0f);
glPushMatrix();
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(0,255,255);
glVertex2f(0.28f, 0.43f);
glVertex2f(0.27f, 0.44f);
glEnd();

glPushMatrix();
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(0,255,255);
glVertex2f(0.27f, 0.43f);
glVertex2f(0.28f, 0.42f);
glEnd();
glPopMatrix();

glPushMatrix();
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(0,255,255);
glVertex2f(0.26f, 0.45f);
glVertex2f(0.268f, 0.44f);
glEnd();
glPopMatrix();

glPushMatrix();
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(0,255,255);
glVertex2f(0.25f, 0.445f);
glVertex2f(0.257f, 0.435f);
glEnd();

glPushMatrix();
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(0,255,255);
glVertex2f(0.24f, 0.46f);
glVertex2f(0.25f, 0.45f);
glEnd();
glPopMatrix();

glLoadIdentity();
}

//boat1
void boat1(){

glTranslatef(boat1_position,0.0f,0.0f);
glPushMatrix();
//Boat

glBegin(GL_QUADS);
glColor3ub(160,160,160);
glVertex2f(-0.08f,0.12f);
glVertex2f(-0.05f,0.1f);
glVertex2f(0.05f,0.1f);
glVertex2f(0.06f,0.12f);
glEnd();

glLineWidth(2.2);
glBegin(GL_LINES);
glColor3ub	(25,25,112);
glVertex2f(-0.08f,0.12f);
glVertex2f(-0.05f,0.1f);

glVertex2f(-0.05f,0.1f);
glVertex2f(0.05f,0.1f);

glVertex2f(0.05f,0.1f);
glVertex2f(0.06f,0.12f);

glVertex2f(-0.08f,0.12f);
glVertex2f(0.06f,0.12f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(0,153,153);
glVertex2f(-0.12f,0.16f);
glVertex2f(-0.08f,0.12f);
glVertex2f(0.06f,0.12f);
glVertex2f(0.07f,0.14f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3ub	(25,25,112);
glVertex2f(-0.12f,0.16f);
glVertex2f(-0.08f,0.12f);

glVertex2f(-0.08f,0.12f);
glVertex2f(0.06f,0.12f);

glVertex2f(0.06f,0.12f);
glVertex2f(0.07f,0.14f);

glVertex2f(-0.12f,0.16f);
glVertex2f(0.07f,0.14f);


glEnd();

//body end

//Stand
glBegin(GL_QUADS);
glColor3ub(102,51,0);
glVertex2f(-0.06f,0.21f);
glVertex2f(-0.06f,0.15f);
glVertex2f(-0.05f,0.15f);
glVertex2f(-0.05f,0.21f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,153,51);
glVertex2f(-0.06f,0.21f);
glVertex2f(-0.06f,0.25f);
glVertex2f(-0.05f,0.25f);
glVertex2f(-0.05f,0.21f);
glEnd();

//1st Container
glBegin(GL_QUADS);
glColor3ub(204,102,0);
glVertex2f(-0.02f,0.17f);
glVertex2f(-0.02f,0.15f);
glVertex2f(0.02f,0.145f);
glVertex2f(0.02f,0.17f);
glEnd();


glLineWidth(1.5);
glBegin(GL_LINES);
glColor3ub(0,128,128);
glVertex2f(-0.02f,0.17f);
glVertex2f(-0.02f,0.15f);

glVertex2f(-0.02f,0.15f);
glVertex2f(0.02f,0.145f);

glVertex2f(0.02f,0.145f);
glVertex2f(0.02f,0.17f);

glVertex2f(-0.02f,0.17f);
glVertex2f(0.02f,0.17f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(0,204,102);
glVertex2f(-0.02f,0.19f);
glVertex2f(-0.02f,0.17f);
glVertex2f(0.02f,0.17f);
glVertex2f(0.02f,0.19f);
glEnd();


glLineWidth(1.5);
glBegin(GL_LINES);
glColor3ub(0,128,128);
glVertex2f(-0.02f,0.19f);
glVertex2f(-0.02f,0.17f);

glVertex2f(-0.02f,0.17f);
glVertex2f(0.02f,0.17f);

glVertex2f(0.02f,0.17f);
glVertex2f(0.02f,0.19f);

glVertex2f(-0.02f,0.19f);
glVertex2f(0.02f,0.19f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(224,224,224);
glVertex2f(-0.02f,0.21f);
glVertex2f(-0.02f,0.19f);
glVertex2f(0.02f,0.19f);
glVertex2f(0.02f,0.21f);
glEnd();

glLineWidth(1.5);
glBegin(GL_LINES);
glColor3ub(0,128,128);
glVertex2f(-0.02f,0.21f);
glVertex2f(-0.02f,0.19f);

glVertex2f(-0.02f,0.19f);
glVertex2f(0.02f,0.19f);

glVertex2f(0.02f,0.19f);
glVertex2f(0.02f,0.21f);

glVertex2f(-0.02f,0.21f);
glVertex2f(0.02f,0.21f);
glEnd();



//2nd Side Container

glBegin(GL_QUADS);
glColor3ub(153,153,255);
glVertex2f(0.025f,0.17f);
glVertex2f(0.025f,0.145f);
glVertex2f(0.058f,0.14f);
glVertex2f(0.058f,0.17f);
glEnd();

glLineWidth(1.5);
glBegin(GL_LINES);
glColor3ub(0,128,128);
glVertex2f(0.025f,0.17f);
glVertex2f(0.025f,0.145f);

glVertex2f(0.025f,0.145f);
glVertex2f(0.058f,0.14f);

glVertex2f(0.058f,0.14f);
glVertex2f(0.058f,0.17f);

glVertex2f(0.025f,0.17f);
glVertex2f(0.058f,0.17f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(204,102,0);
glVertex2f(0.025f,0.19f);
glVertex2f(0.025f,0.17f);
glVertex2f(0.058f,0.17f);
glVertex2f(0.058f,0.19f);
glEnd();

glLineWidth(1.5);
glBegin(GL_LINES);
glColor3ub(0,128,128);
glVertex2f(0.025f,0.19f);
glVertex2f(0.025f,0.17f);

glVertex2f(0.025f,0.17f);
glVertex2f(0.058f,0.17f);

glVertex2f(0.058f,0.17f);
glVertex2f(0.058f,0.19f);

glVertex2f(0.025f,0.19f);
glVertex2f(0.058f,0.19f);
glEnd();



    //Boat 1 Smoke

    glTranslatef(0.0f, boat1_smoke_position, 0.0f);
    glPushMatrix();
    int i;


    GLfloat p1=-0.058f; GLfloat q1= 0.32f; GLfloat r1 = 0.018f;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (195,188,188);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );


    }
    glEnd ();


    GLfloat p2=-0.058f; GLfloat q2= 0.3; GLfloat r2 = 0.015f;
    int tringle3=40;

    GLfloat tp3 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (224,224,224);
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp3/tringle3)),
                    q2+(r2*sin(i*tp3/tringle3))
                    );


    }
    glEnd ();

    GLfloat p3=-0.058; GLfloat q3= 0.28f; GLfloat r3 = 0.01f;
    int tringle4=40;

    GLfloat tp4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (195,188,188);
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp4/tringle4)),
                    q3+(r3*sin(i*tp4/tringle4))
                    );


    }
    glEnd ();
    glPopMatrix();

glPopMatrix();
glLoadIdentity();
}
 //Boat 2
void boat2(){
    glPushMatrix();
    glTranslatef(boat2_position,0.0f,0.0f);

    glBegin(GL_QUADS);
    glColor3ub(245,245,245);
    glVertex2f(0.35f,-0.08f);
    glVertex2f(0.425f,-0.13f);
    glVertex2f(0.6f,-0.13f);
    glVertex2f(0.63f,-0.08f);
    glEnd();

    //under design
    glBegin(GL_QUADS);
    glColor3ub(25,25,112);
    glVertex2f(0.395f,-0.11f);
    glVertex2f(0.425f,-0.13f);
    glVertex2f(0.6f,-0.13f);
    glVertex2f(0.61f,-0.11f);
    glEnd();

    //1st Floor
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(0.4f,-0.06f);
    glVertex2f(0.38f,-0.08f);
    glVertex2f(0.61f,-0.08f);
    glVertex2f(0.61f,-0.06f);
    glEnd();


    //2nd Floor

    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(0.44f,-0.04f);
    glVertex2f(0.42f,-0.06f);
    glVertex2f(0.6f,-0.06f);
    glVertex2f(0.6f,-0.04f);
    glEnd();

    //3rd Floor

    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(0.48f,-0.02f);
    glVertex2f(0.46f,-0.04f);
    glVertex2f(0.59f,-0.06f);
    glVertex2f(0.59f,-0.02f);
    glEnd();


    //Boat Border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub		(192,192,192);
    glVertex2f(0.35f,-0.08f);
    glVertex2f(0.425f,-0.13f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub		(192,192,192);
    glVertex2f(0.425f,-0.13f);
    glVertex2f(0.6f,-0.13f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub		(192,192,192);
    glVertex2f(0.6f,-0.13f);
    glVertex2f(0.63f,-0.08f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub	(192,192,192);
    glVertex2f(0.63f,-0.08f);
    glVertex2f(0.35f,-0.08f);
    glEnd();

    //Ship Window
    //Floor 1


    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.40f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.41f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.42f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.43f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.44f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.45f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.46f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.47f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.48f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.49f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.50f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.51f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.52f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.53f, -0.07f);
    glEnd();


    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.54f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.55f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.56f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.57f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.58f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.59f, -0.07f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.60f, -0.07f);
    glEnd();

    //Floor 2
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.44f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.45f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.46f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.47f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.48f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.49f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.50f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.51f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.52f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.53f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.54f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.55f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.56f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.57f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.58f, -0.05f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.59f, -0.05f);
    glEnd();

    // 3rd Floor

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.48f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.49f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.50f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.51f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.52f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.53f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.54f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.55f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.56f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.57f, -0.03f);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(0,206,209);
    glVertex2f(0.58f, -0.03f);
    glEnd();

    //Boat 2 Stand
    glLineWidth(4.5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.5f, -0.02f);
    glVertex2f(0.5f, 0.05f);
    glEnd();

    //upper stand
    glPushMatrix();
    glTranslatef(0.495f,0.03f,0.0f);
    glRotatef(windmill_wheel_position,0.0f,0.0f,0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub	(47,79,79);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.029f, 0.0f);
    glEnd();
    glPopMatrix();

    //lower stand
    glPushMatrix();
    glTranslatef(0.505f,0.015f,0.0f);
    glRotatef(windmill_wheel_position,0.0f,0.0f,0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub	(47,79,79);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.02f, 0.0f);
    glEnd();
    glPopMatrix();



    //Boat2 Smoke Stand

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.568f, 0.03f);
    glVertex2f(0.56f, -0.02f);
    glVertex2f(0.58f, -0.02f);
    glVertex2f(0.58f, 0.03f);


    glColor3ub(0,0,0);
    glVertex2f(0.568f, 0.03f);
    glVertex2f(0.563f, 0.015f);
    glVertex2f(0.58f, 0.015f);
    glVertex2f(0.58f, 0.03f);
    glEnd();



    //Floor Border

    //Floor 1
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.38f,-0.08f);
    glVertex2f(0.4f,-0.06f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.61f,-0.06f);
    glVertex2f(0.4f,-0.06f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.61f,-0.06f);
    glVertex2f(0.61f,-0.08f);
    glEnd();

    //Floor 2

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.42f,-0.06f);
    glVertex2f(0.44f,-0.04f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.44f,-0.04f);
    glVertex2f(0.6f,-0.04f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.6f,-0.04f);
    glVertex2f(0.6f,-0.04f);
    glEnd();
    //Floor 3

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.46f,-0.04f);
    glVertex2f(0.48f,-0.02f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.48f,-0.02f);
    glVertex2f(0.59f,-0.02f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub	(211,211,211);
    glVertex2f(0.59f,-0.02f);
    glVertex2f(0.59f,-0.04f);
    glEnd();


    //Boat 2 smoke
    glTranslatef(0.0f,boat2_smoke_position,0.0f);
    glPushMatrix();
    int i;


    GLfloat p1=0.575f; GLfloat q1= 0.045f; GLfloat r1 = 0.018f;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (195,188,188);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );


    }
    glEnd ();


    GLfloat p2=0.578f; GLfloat q2= 0.066f; GLfloat r2 = 0.015f;
    int tringle3=40;

    GLfloat tp3 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (224,224,224);
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp3/tringle3)),
                    q2+(r2*sin(i*tp3/tringle3))
                    );


    }
    glEnd ();

    GLfloat p3=0.581; GLfloat q3= 0.084f; GLfloat r3 = 0.01f;
    int tringle4=40;

    GLfloat tp4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (195,188,188);
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp4/tringle4)),
                    q3+(r3*sin(i*tp4/tringle4))
                    );


    }
    glEnd ();
    glPopMatrix();


glPopMatrix();

glLoadIdentity();
}

void Rain()
{
glLineWidth(3);
if(rainday==true)
{

//1st full translation

glPushMatrix();
glTranslatef(-0.8f, 0.8f, 0.0f);
glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.2f, 0.2f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.0f);
glVertex2f(0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.0f);
glVertex2f(0.4f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.0f);
glVertex2f(0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.0f);
glVertex2f(0.6f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, 0.0f);
glVertex2f(0.7f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, 0.0f);
glVertex2f(0.8f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, 0.0f);
glVertex2f(0.9f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, 0.5f);
glVertex2f(-0.6f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.5f);
glVertex2f(-0.3f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.1f);
glVertex2f(-0.8f, 0.3f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.4f);
glVertex2f(-0.8f, 0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.7f);
glVertex2f(-0.8f, 0.9f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, 0.7f);
glVertex2f(-0.7f, 0.9f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, 0.0f);
glVertex2f(-0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.0f);
glVertex2f(-0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.0f);
glVertex2f(-0.2f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.0f);
glVertex2f(-0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.6f);
glVertex2f(0.3f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.6f);
glVertex2f(0.4f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.6f);
glVertex2f(0.5f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.6f);
glVertex2f(0.6f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.1f, 0.6f);
glVertex2f(0.0f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.6f);
glVertex2f(-0.1f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.6f);
glVertex2f(-0.2f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, -0.8f);
glVertex2f(-0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, -0.8f);
glVertex2f(-0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.5f, -0.8f);
glVertex2f(-0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, -0.8f);
glVertex2f(-0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, -0.8f);
glVertex2f(-0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, -0.8f);
glVertex2f(-0.1f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, -0.8f);
glVertex2f(-0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, -0.8f);
glVertex2f(-0.8f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.0f, -0.8f);
glVertex2f(-0.9f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.8f);
glVertex2f(0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.8f);
glVertex2f(0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.8f);
glVertex2f(0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.8f);
glVertex2f(0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.8f);
glVertex2f(0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.8f);
glVertex2f(0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.8f);
glVertex2f(0.8f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.8f);
glVertex2f(1.0f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.4f);
glVertex2f(0.2f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.4f);
glVertex2f(0.3f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.4f);
glVertex2f(0.4f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.4f);
glVertex2f(0.5f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.4f);
glVertex2f(0.6f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.4f);
glVertex2f(0.7f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.4f);
glVertex2f(0.8f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.4f);
glVertex2f(0.9f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.4f);
glVertex2f(1.0f, -0.2f);
glEnd();

glPopMatrix();


//2nd full translation

glPushMatrix();
glTranslatef(-0.4f, 0.4f, 0.0f);
glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.2f, 0.2f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.0f);
glVertex2f(0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.0f);
glVertex2f(0.4f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.0f);
glVertex2f(0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.0f);
glVertex2f(0.6f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, 0.0f);
glVertex2f(0.7f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, 0.0f);
glVertex2f(0.8f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, 0.0f);
glVertex2f(0.9f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, 0.5f);
glVertex2f(-0.6f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.5f);
glVertex2f(-0.3f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.1f);
glVertex2f(-0.8f, 0.3f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.4f);
glVertex2f(-0.8f, 0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.7f);
glVertex2f(-0.8f, 0.9f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, 0.7f);
glVertex2f(-0.7f, 0.9f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, 0.0f);
glVertex2f(-0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.0f);
glVertex2f(-0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.0f);
glVertex2f(-0.2f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.0f);
glVertex2f(-0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.6f);
glVertex2f(0.3f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.6f);
glVertex2f(0.4f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.6f);
glVertex2f(0.5f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.6f);
glVertex2f(0.6f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.1f, 0.6f);
glVertex2f(0.0f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.6f);
glVertex2f(-0.1f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.6f);
glVertex2f(-0.2f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, -0.8f);
glVertex2f(-0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, -0.8f);
glVertex2f(-0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.5f, -0.8f);
glVertex2f(-0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, -0.8f);
glVertex2f(-0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, -0.8f);
glVertex2f(-0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, -0.8f);
glVertex2f(-0.1f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, -0.8f);
glVertex2f(-0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, -0.8f);
glVertex2f(-0.8f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.0f, -0.8f);
glVertex2f(-0.9f, -0.6f);
glEnd();

//////////2

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.8f);
glVertex2f(0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.8f);
glVertex2f(0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.8f);
glVertex2f(0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.8f);
glVertex2f(0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.8f);
glVertex2f(0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.8f);
glVertex2f(0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.8f);
glVertex2f(0.8f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.8f);
glVertex2f(1.0f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.4f);
glVertex2f(0.2f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.4f);
glVertex2f(0.3f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.4f);
glVertex2f(0.4f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.4f);
glVertex2f(0.5f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.4f);
glVertex2f(0.6f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.4f);
glVertex2f(0.7f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.4f);
glVertex2f(0.8f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.4f);
glVertex2f(0.9f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.4f);
glVertex2f(1.0f, -0.2f);
glEnd();
glPopMatrix();


//3rd full translation

glPushMatrix();
glTranslatef(0.4f, -0.4f, 0.0f);
glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.2f, 0.2f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.0f);
glVertex2f(0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.0f);
glVertex2f(0.4f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.0f);
glVertex2f(0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.0f);
glVertex2f(0.6f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, 0.0f);
glVertex2f(0.7f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, 0.0f);
glVertex2f(0.8f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, 0.0f);
glVertex2f(0.9f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, 0.5f);
glVertex2f(-0.6f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.5f);
glVertex2f(-0.3f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.1f);
glVertex2f(-0.8f, 0.3f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.4f);
glVertex2f(-0.8f, 0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.7f);
glVertex2f(-0.8f, 0.9f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, 0.7f);
glVertex2f(-0.7f, 0.9f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, 0.0f);
glVertex2f(-0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.0f);
glVertex2f(-0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.0f);
glVertex2f(-0.2f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.0f);
glVertex2f(-0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.6f);
glVertex2f(0.3f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.6f);
glVertex2f(0.4f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.6f);
glVertex2f(0.5f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.6f);
glVertex2f(0.6f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.1f, 0.6f);
glVertex2f(0.0f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.6f);
glVertex2f(-0.1f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.6f);
glVertex2f(-0.2f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, -0.8f);
glVertex2f(-0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, -0.8f);
glVertex2f(-0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.5f, -0.8f);
glVertex2f(-0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, -0.8f);
glVertex2f(-0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, -0.8f);
glVertex2f(-0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, -0.8f);
glVertex2f(-0.1f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, -0.8f);
glVertex2f(-0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, -0.8f);
glVertex2f(-0.8f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.0f, -0.8f);
glVertex2f(-0.9f, -0.6f);
glEnd();

//////////2

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.8f);
glVertex2f(0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.8f);
glVertex2f(0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.8f);
glVertex2f(0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.8f);
glVertex2f(0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.8f);
glVertex2f(0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.8f);
glVertex2f(0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.8f);
glVertex2f(0.8f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.8f);
glVertex2f(1.0f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.4f);
glVertex2f(0.2f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.4f);
glVertex2f(0.3f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.4f);
glVertex2f(0.4f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.4f);
glVertex2f(0.5f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.4f);
glVertex2f(0.6f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.4f);
glVertex2f(0.7f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.4f);
glVertex2f(0.8f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.4f);
glVertex2f(0.9f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.4f);
glVertex2f(1.0f, -0.2f);
glEnd();
glPopMatrix();


//4th full translation

glPushMatrix();
glTranslatef(0.8f, -0.8f, 0.0f);
glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.2f, 0.2f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.0f);
glVertex2f(0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.0f);
glVertex2f(0.4f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.0f);
glVertex2f(0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.0f);
glVertex2f(0.6f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, 0.0f);
glVertex2f(0.7f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, 0.0f);
glVertex2f(0.8f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, 0.0f);
glVertex2f(0.9f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, 0.5f);
glVertex2f(-0.6f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.5f);
glVertex2f(-0.3f, 0.7f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.1f);
glVertex2f(-0.8f, 0.3f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.4f);
glVertex2f(-0.8f, 0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, 0.7f);
glVertex2f(-0.8f, 0.9f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, 0.7f);
glVertex2f(-0.7f, 0.9f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, 0.0f);
glVertex2f(-0.5f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, 0.0f);
glVertex2f(-0.3f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.0f);
glVertex2f(-0.2f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.0f);
glVertex2f(-0.1f, 0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, 0.6f);
glVertex2f(0.3f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, 0.6f);
glVertex2f(0.4f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, 0.6f);
glVertex2f(0.5f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, 0.6f);
glVertex2f(0.6f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.1f, 0.6f);
glVertex2f(0.0f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, 0.6f);
glVertex2f(-0.1f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, 0.6f);
glVertex2f(-0.2f, 0.8f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.6f, -0.8f);
glVertex2f(-0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.7f, -0.8f);
glVertex2f(-0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.5f, -0.8f);
glVertex2f(-0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f, -0.8f);
glVertex2f(-0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.3f, -0.8f);
glVertex2f(-0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.2f, -0.8f);
glVertex2f(-0.1f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.8f, -0.8f);
glVertex2f(-0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.9f, -0.8f);
glVertex2f(-0.8f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.0f, -0.8f);
glVertex2f(-0.9f, -0.6f);
glEnd();

//////////2

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.8f);
glVertex2f(0.6f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.8f);
glVertex2f(0.7f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.8f);
glVertex2f(0.5f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.8f);
glVertex2f(0.4f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.8f);
glVertex2f(0.3f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.8f);
glVertex2f(0.2f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.8f);
glVertex2f(0.8f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.8f);
glVertex2f(0.9f, -0.6f);
glEnd();


glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.8f);
glVertex2f(1.0f, -0.6f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f, -0.4f);
glVertex2f(0.2f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f, -0.4f);
glVertex2f(0.3f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.3f, -0.4f);
glVertex2f(0.4f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -0.4f);
glVertex2f(0.5f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f, -0.4f);
glVertex2f(0.6f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.6f, -0.4f);
glVertex2f(0.7f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.7f, -0.4f);
glVertex2f(0.8f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.8f, -0.4f);
glVertex2f(0.9f, -0.2f);
glEnd();

glTranslatef(Rainposition1, Rainposition1, 0.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.9f, -0.4f);
glVertex2f(1.0f, -0.2f);
glEnd();
glPopMatrix();
}

    glutPostRedisplay();
    glFlush();
}

//Rainy Road
void Rain_Road(){
if(rainday==true){
int i;

//1
GLfloat p3 = -0.76f;
GLfloat q3 = -0.86f;
GLfloat r3 = 0.04f;
int triangle3 = 10;
GLfloat tp3 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);
glVertex2f (p3,q3);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p3+(r3*cos(i*tp3/triangle3)),
q3+(r3*sin(i*tp3/triangle3))
);
}
glEnd ();

//2
GLfloat p1 = -0.65f;
GLfloat q1 = -0.70f;
GLfloat r1 = 0.02f;
int triangle1 = 50;
GLfloat tp1 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);
glVertex2f (p1,q1);
for(i= 0;i<=triangle1; i++)
{
glVertex2f (
p1+(r1*cos(i*tp1/triangle1)),
q1+(r1*sin(i*tp1/triangle1))
);
}
glEnd ();


//3
GLfloat p5 = -0.56f;
GLfloat q5 = -0.75f;
GLfloat r5 = 0.04f;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);
glVertex2f (p5,q5);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p5+(r5*cos(i*tp3/triangle3)),
q5+(r5*sin(i*tp3/triangle3))
);
}
glEnd ();

//4
GLfloat p6 = -0.5f;
GLfloat q6 = -0.77f;
GLfloat r6 = 0.04f;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);
glVertex2f (p6,q6);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p6+(r6*cos(i*tp3/triangle3)),
q6+(r6*sin(i*tp3/triangle3))
);
}
glEnd ();

//5
GLfloat pp6 = -0.26f;
GLfloat qq6 = -0.85f;
GLfloat rr6 = 0.05f;
int triangles1 = 70;


glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);
glVertex2f (pp6,qq6);
for(i= 0;i<=triangles1; i++)
{
glVertex2f (
pp6+(rr6*cos(i*tp3/triangles1)),
qq6+(rr6*sin(i*tp3/triangles1))
);
}
glEnd ();

//6
GLfloat p7 = 0.0f;
GLfloat q7 = -0.77f;
GLfloat r7 = 0.04f;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);
glVertex2f (p7,q7);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p7+(r7*cos(i*tp3/triangle3)),
q7+(r7*sin(i*tp3/triangle3))
);
}
glEnd ();

//7
GLfloat p8 = 0.3f;
GLfloat q8 = -0.80f;
GLfloat r8 = 0.05f;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);;
glVertex2f (p8,q8);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p8+(r8*cos(i*tp3/triangle3)),
q8+(r8*sin(i*tp3/triangle3))
);
}
glEnd ();

//8
GLfloat p10 = 0.6f;
GLfloat q10 = -0.8f;
GLfloat r10 = 0.07f;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);
glVertex2f (p10,q10);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p10+(r10*cos(i*tp3/triangle3)),
q10+(r10*sin(i*tp3/triangle3))
);
}
glEnd ();

//Boat Dock Rain_Effects
//1
GLfloat pb8 = 0.42f;
GLfloat qb8 = 0.29f;
GLfloat rb8 = 0.01f;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);;
glVertex2f (pb8,qb8);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
pb8+(rb8*cos(i*tp3/triangle3)),
qb8+(rb8*sin(i*tp3/triangle3))
);
}
glEnd ();

//2
GLfloat pb81 = 0.38f;
GLfloat qb81 = 0.26f;
GLfloat rb81 = 0.02f;

glBegin (GL_TRIANGLE_FAN);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glColor4ub(240,255,255,110);;
glVertex2f (pb81,qb81);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
pb81+(rb81*cos(i*tp3/triangle3)),
qb81+(rb81*sin(i*tp3/triangle3))
);
}
glEnd ();


}
}
//snow
void snow(){
if(snowfall==true){
glTranslatef(0.0f, snowposition, 0.0f);
glPushMatrix();
//y = 0
glPointSize(6);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.0f,0.03f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.2f,0.01f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.27f,0.01f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.45f,0.0f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.53f,0.0f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.65f,0.0f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.85f,0.0f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.97f,0.0f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.94f,0.0f);
glEnd();


//y=.25
glPointSize(4);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.0f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.28f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.26f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.54f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.57f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.65f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.67f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.89f,0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.89f,0.25f);
glEnd();


//y=.5
glPointSize(5);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.017,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.271f,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.214f,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.4f,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.34f,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.615f,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.35f,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-.85f,0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.82f,0.5f);
glEnd();

//y=.75
glPointSize(8);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.1f,0.875f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.29f,0.975f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.23f,0.765f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.34f,0.875f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.89f,0.675f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.79f,0.735f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.75f,0.875f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.990f,0.75f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.94f,0.785f);
glEnd();

//y=-.25
glPointSize(3);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.005f,-0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.25f,-0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.25f,-0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.5f,-0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.5f,-0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.75f,-0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.75f,-0.25f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.0f,-0.254f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(1.0f,-0.245f);
glEnd();

//y=-.5
glPointSize(5);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.01f,-0.56f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.295f,-0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.225f,-0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.5f,-0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.435f,-0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.575f,-0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.715f,-0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.0f,-0.5f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(1.0f,-0.5f);
glEnd();


//y=-.75
glPointSize(9);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.02f,-0.675f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.215f,-0.785f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.245f,-0.775f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.45f,-0.75f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.65f,-0.75f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.785f,-0.975f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.735f,-0.715f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.0f,-0.865f);
glEnd();

glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(1.0f,-0.735f);
glEnd();
glPopMatrix();
    }
glutPostRedisplay();
glFlush();
}

//sea
void DaySea(){
    glBegin(GL_QUADS);

    glColor3ub(126, 249, 255);
    glVertex2f(-1.0f,0.42f);

    //glColor3ub(126, 249, 255);
    glVertex2f(-1.0f,-0.6f);

    //glColor3ub();
    glVertex2f(1.0f,-0.6f);

    glColor3ub(16, 52, 166);
    glVertex2f(1.0f,0.42f);
    glEnd();

    glLoadIdentity();
}
//Night sea
void NightSea(){
    glBegin(GL_QUADS);
    glColor3ub(25,25,112);
    glVertex2f(-1.0f,0.42f);
    glColor3ub(70,130,180);
    glVertex2f(-1.0f,-0.6f);
    glColor3ub(70,130,180);
    glVertex2f(1.0f,-0.6f);
    glVertex2f(1.0f,0.42f);
    glEnd();

    glLoadIdentity();
}

//Evening Sea
void EveningSea(){
    glBegin(GL_QUADS);
    glColor3ub(126, 249, 255);
    glVertex2f(-1.0f,0.42f);
    glVertex2f(-1.0f,-0.6f);
    glColor3ub(244,164,96);
    glVertex2f(1.0f,-0.6f);
    glVertex2f(1.0f,0.42f);
    glEnd();

    glLoadIdentity();
}


//buildings
//building 1
void Building1(){
    //building 1 roof
    glBegin(GL_QUADS);
    glColor3ub(0, 51, 102);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.95f, 0.4f);
    glVertex2f(-0.79f, 0.4f);
    glVertex2f(-0.85f, 0.45f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 51, 102);
    glVertex2f(-1.0f,0.45f);
    glColor3ub(0, 102, 204);
    glVertex2f(-1.0f,-0.6f);
    glColor3ub(0, 51, 102);
    glVertex2f(-0.95f,-0.6f);
    glColor3ub(0, 102, 204);
    glVertex2f(-0.95f, 0.4f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 51, 102);
    glVertex2f(-0.95f,0.4f);

    glColor3ub(0, 128, 255);
    glVertex2f(-0.95f,-0.6f);

    glColor3ub(0, 51, 102);
    glVertex2f(-0.79f,-0.6f);

    glColor3ub(0, 128, 255);
    glVertex2f(-0.79f, 0.4f);
    glEnd();

    //windows (floor1)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,0.35);
    glEnd();


    //windows (floor2)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,0.31);
    glEnd();

    //windows (floor3)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,0.27);
    glEnd();

        //windows (floor4)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,0.23);
    glEnd();


    //windows (floor5)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,0.19);
    glEnd();

    //6th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.15);
    glVertex2f(-0.81,0.15);
    glEnd();

    //7th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.11);
    glVertex2f(-0.81,0.11);
    glEnd();

    //8th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.07);
    glVertex2f(-0.81,0.07);
    glEnd();

    //9th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,0.03);
    glEnd();

    //10th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,-0.01);
    glEnd();


    //11th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,-0.05);
    glEnd();


    //12th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,-0.09);
    glEnd();

    //13th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,-0.13);
    glEnd();

    //14th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.17);
    glVertex2f(-0.81,-0.17);
    glEnd();

    //15th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.21);
    glVertex2f(-0.81,-0.21);
    glEnd();


    //16th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.25);
    glVertex2f(-0.81,-0.25);
    glEnd();

    //17th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.30);
    glVertex2f(-0.93,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.91,-0.30);
    glVertex2f(-0.91,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.89,-0.30);
    glVertex2f(-0.89,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87,-0.30);
    glVertex2f(-0.87,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.85,-0.30);
    glVertex2f(-0.85,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.83,-0.30);
    glVertex2f(-0.83,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.81,-0.30);
    glVertex2f(-0.81,-0.4);
    glEnd();

    //18th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.45);
    glVertex2f(-0.81,-0.45);
    glEnd();


    //19th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.45);
    glVertex2f(-0.81,-0.45);
    glEnd();

    //20th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.5);
    glVertex2f(-0.81,-0.5);
    glEnd();

    //21th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.93,-0.55);
    glVertex2f(-0.81,-0.55);
    glEnd();

    //window of left side
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,0.40);
    glVertex2f(-0.96,0.37);
    glEnd();
    glLoadIdentity();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,0.35);
    glVertex2f(-0.96,0.32);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,0.29);
    glVertex2f(-0.96,0.26);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,0.23);
    glVertex2f(-0.96,0.20);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,0.17);
    glVertex2f(-0.96,0.14);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,0.05);
    glVertex2f(-0.96,0.02);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,0.00);
    glVertex2f(-0.96,-0.03);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.06);
    glVertex2f(-0.96,-0.09);
    glEnd();
    //9
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.12);
    glVertex2f(-0.96,-0.15);
    glEnd();
    //10
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.18);
    glVertex2f(-0.96,-0.21);
    glEnd();
    //11
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.30);
    glVertex2f(-0.96,-0.33);
    glEnd();
    //12
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.36);
    glVertex2f(-0.96,-0.39);
    glEnd();
    //13
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.42);
    glVertex2f(-0.96,-0.45);
    glEnd();
    //14
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.48);
    glVertex2f(-0.96,-0.51);
    glEnd();
    //15
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0,-0.54);
    glVertex2f(-0.96,-0.57);
    glEnd();

    glLoadIdentity();
}

//building 1 night
void Building1Night(){
    //building 1 roof
    glBegin(GL_QUADS);
    glColor3ub(0, 51, 102);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.95f, 0.4f);
    glVertex2f(-0.79f, 0.4f);
    glVertex2f(-0.85f, 0.45f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 51, 102);
    glVertex2f(-1.0f,0.45f);
    glColor3ub(0, 102, 204);
    glVertex2f(-1.0f,-0.6f);
    glColor3ub(0, 51, 102);
    glVertex2f(-0.95f,-0.6f);
    glColor3ub(0, 102, 204);
    glVertex2f(-0.95f, 0.4f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 51, 102);
    glVertex2f(-0.95f,0.4f);

    glColor3ub(0, 128, 255);
    glVertex2f(-0.95f,-0.6f);

    glColor3ub(0, 51, 102);
    glVertex2f(-0.79f,-0.6f);

    glColor3ub(0, 128, 255);
    glVertex2f(-0.79f, 0.4f);
    glEnd();

    //windows (floor1)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,0.35);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,0.35);
    glEnd();


    //windows (floor2)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,0.31);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,0.31);
    glEnd();

    //windows (floor3)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,0.27);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,0.27);
    glEnd();

        //windows (floor4)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,0.23);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,0.23);
    glEnd();


    //windows (floor5)
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,0.19);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,0.19);
    glEnd();

    //6th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.15);
    glVertex2f(-0.81,0.15);
    glEnd();

    //7th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.11);
    glVertex2f(-0.81,0.11);
    glEnd();

    //8th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.07);
    glVertex2f(-0.81,0.07);
    glEnd();

    //9th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,0.03);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,0.03);
    glEnd();

    //10th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,-0.01);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,-0.01);
    glEnd();


    //11th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,-0.05);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,-0.05);
    glEnd();


    //12th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,-0.09);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,-0.09);
    glEnd();

    //13th floor
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,-0.13);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,-0.13);
    glEnd();

    //14th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.17);
    glVertex2f(-0.81,-0.17);
    glEnd();

    //15th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.21);
    glVertex2f(-0.81,-0.21);
    glEnd();


    //16th floor
    glPointSize(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.25);
    glVertex2f(-0.81,-0.25);
    glEnd();

    //17th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.30);
    glVertex2f(-0.93,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.91,-0.30);
    glVertex2f(-0.91,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.89,-0.30);
    glVertex2f(-0.89,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.87,-0.30);
    glVertex2f(-0.87,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.85,-0.30);
    glVertex2f(-0.85,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.83,-0.30);
    glVertex2f(-0.83,-0.4);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.81,-0.30);
    glVertex2f(-0.81,-0.4);
    glEnd();

    //18th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.45);
    glVertex2f(-0.81,-0.45);
    glEnd();


    //19th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.45);
    glVertex2f(-0.81,-0.45);
    glEnd();

    //20th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.5);
    glVertex2f(-0.81,-0.5);
    glEnd();

    //21th floor
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-0.93,-0.55);
    glVertex2f(-0.81,-0.55);
    glEnd();

    //window of left side
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,0.40);
    glVertex2f(-0.96,0.37);
    glEnd();
    glLoadIdentity();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,0.35);
    glVertex2f(-0.96,0.32);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,0.29);
    glVertex2f(-0.96,0.26);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,0.23);
    glVertex2f(-0.96,0.20);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,0.17);
    glVertex2f(-0.96,0.14);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,0.05);
    glVertex2f(-0.96,0.02);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,0.00);
    glVertex2f(-0.96,-0.03);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.06);
    glVertex2f(-0.96,-0.09);
    glEnd();
    //9
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.12);
    glVertex2f(-0.96,-0.15);
    glEnd();
    //10
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.18);
    glVertex2f(-0.96,-0.21);
    glEnd();
    //11
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.30);
    glVertex2f(-0.96,-0.33);
    glEnd();
    //12
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.36);
    glVertex2f(-0.96,-0.39);
    glEnd();
    //13
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.42);
    glVertex2f(-0.96,-0.45);
    glEnd();
    //14
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.48);
    glVertex2f(-0.96,-0.51);
    glEnd();
    //15
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,102);
    glVertex2f(-1.0,-0.54);
    glVertex2f(-0.96,-0.57);
    glEnd();


    glLoadIdentity();
}

//building 2
void Building2(){
    glBegin(GL_POLYGON);
    glColor3f(0.5f,0.66f,0.7f);
    glVertex2f(-0.75f,0.75f);
    glVertex2f(-0.85f,0.6f);
    glVertex2f(-0.85f,-0.6f);
    glVertex2f(-0.7f,-0.6f);
    glVertex2f(-0.7f,0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.7f,0.7f);
    glVertex2f(-0.75f,0.75f);
    glVertex2f(-0.75f,-0.6f);
    glVertex2f(-0.65f,-0.6f);
    glVertex2f(-0.65f,0.6f);
    glEnd();

    //window
    //1st floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.7,0.5);
    glVertex2f(-0.7,0.4);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.68,0.5);
    glVertex2f(-0.68,0.4);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.72,0.5);
    glVertex2f(-0.72,0.4);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.74,0.5);
    glVertex2f(-0.74,0.4);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.76,0.5);
    glVertex2f(-0.76,0.4);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.78,0.5);
    glVertex2f(-0.78,0.4);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.8,0.5);
    glVertex2f(-0.8,0.4);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.82,0.5);
    glVertex2f(-0.82,0.4);
    glEnd();
    //2nd floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.7,0.35);
    glVertex2f(-0.7,0.25);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.68,0.35);
    glVertex2f(-0.68,0.25);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.72,0.35);
    glVertex2f(-0.72,0.25);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.74,0.35);
    glVertex2f(-0.74,0.25);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.76,0.35);
    glVertex2f(-0.76,0.25);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.78,0.35);
    glVertex2f(-0.78,0.25);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.8,0.35);
    glVertex2f(-0.8,0.25);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.82,0.35);
    glVertex2f(-0.82,0.25);
    glEnd();

    //3rd floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.7,0.20);
    glVertex2f(-0.7,0.10);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.68,0.20);
    glVertex2f(-0.68,0.10);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.72,0.20);
    glVertex2f(-0.72,0.10);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.74,0.20);
    glVertex2f(-0.74,0.10);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.76,0.20);
    glVertex2f(-0.76,0.10);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.78,0.20);
    glVertex2f(-0.78,0.10);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.8,0.20);
    glVertex2f(-0.8,0.10);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.82,0.20);
    glVertex2f(-0.82,0.10);
    glEnd();

    //4th floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.7,0.0);
    glVertex2f(-0.7,-0.10);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.68,0.0);
    glVertex2f(-0.68,-0.10);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.72,0.0);
    glVertex2f(-0.72,-0.10);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.74,0.0);
    glVertex2f(-0.74,-0.10);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.76,0.0);
    glVertex2f(-0.76,-0.10);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.78,0.0);
    glVertex2f(-0.78,-0.10);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.8,0.0);
    glVertex2f(-0.8,-0.10);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.82,0.0);
    glVertex2f(-0.82,-0.10);
    glEnd();

    //5th floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.7,-0.15);
    glVertex2f(-0.7,-0.25);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.68,-0.15);
    glVertex2f(-0.68,-0.25);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.72,-0.15);
    glVertex2f(-0.72,-0.25);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.74,-0.15);
    glVertex2f(-0.74,-0.25);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.76,-0.15);
    glVertex2f(-0.76,-0.25);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.78,-0.15);
    glVertex2f(-0.78,-0.25);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.8,-0.15);
    glVertex2f(-0.8,-0.25);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.82,-0.15);
    glVertex2f(-0.82,-0.25);
    glEnd();

    //6th floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.7,-0.55);
    glVertex2f(-0.7,-0.45);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.68,-0.55);
    glVertex2f(-0.68,-0.45);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.72,-0.55);
    glVertex2f(-0.72,-0.45);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.74,-0.55);
    glVertex2f(-0.74,-0.45);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.76,-0.55);
    glVertex2f(-0.76,-0.45);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.78,-0.55);
    glVertex2f(-0.78,-0.45);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.8,-0.55);
    glVertex2f(-0.8,-0.45);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.82,-0.55);
    glVertex2f(-0.82,-0.45);
    glEnd();

    glLoadIdentity();
}


//building2 night
void Building2Night(){
    glBegin(GL_POLYGON);
    glColor3f(0.5f,0.66f,0.7f);
    glVertex2f(-0.75f,0.75f);
    glVertex2f(-0.85f,0.6f);
    glVertex2f(-0.85f,-0.6f);
    glVertex2f(-0.7f,-0.6f);
    glVertex2f(-0.7f,0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.7f,0.7f);
    glVertex2f(-0.75f,0.75f);
    glVertex2f(-0.75f,-0.6f);
    glVertex2f(-0.65f,-0.6f);
    glVertex2f(-0.65f,0.6f);
    glEnd();

    //window
    //1st floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.7,0.5);
    glVertex2f(-0.7,0.4);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.68,0.5);
    glVertex2f(-0.68,0.4);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.72,0.5);
    glVertex2f(-0.72,0.4);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.74,0.5);
    glVertex2f(-0.74,0.4);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.76,0.5);
    glVertex2f(-0.76,0.4);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.78,0.5);
    glVertex2f(-0.78,0.4);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.8,0.5);
    glVertex2f(-0.8,0.4);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.82,0.5);
    glVertex2f(-0.82,0.4);
    glEnd();
    //2nd floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.7,0.35);
    glVertex2f(-0.7,0.25);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.68,0.35);
    glVertex2f(-0.68,0.25);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.72,0.35);
    glVertex2f(-0.72,0.25);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.74,0.35);
    glVertex2f(-0.74,0.25);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.76,0.35);
    glVertex2f(-0.76,0.25);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.78,0.35);
    glVertex2f(-0.78,0.25);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.8,0.35);
    glVertex2f(-0.8,0.25);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.82,0.35);
    glVertex2f(-0.82,0.25);
    glEnd();

    //3rd floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.7,0.20);
    glVertex2f(-0.7,0.10);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.68,0.20);
    glVertex2f(-0.68,0.10);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.72,0.20);
    glVertex2f(-0.72,0.10);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.74,0.20);
    glVertex2f(-0.74,0.10);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.76,0.20);
    glVertex2f(-0.76,0.10);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.78,0.20);
    glVertex2f(-0.78,0.10);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.8,0.20);
    glVertex2f(-0.8,0.10);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.82,0.20);
    glVertex2f(-0.82,0.10);
    glEnd();

    //4th floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.7,0.0);
    glVertex2f(-0.7,-0.10);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.68,0.0);
    glVertex2f(-0.68,-0.10);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.72,0.0);
    glVertex2f(-0.72,-0.10);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.74,0.0);
    glVertex2f(-0.74,-0.10);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.76,0.0);
    glVertex2f(-0.76,-0.10);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.78,0.0);
    glVertex2f(-0.78,-0.10);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.8,0.0);
    glVertex2f(-0.8,-0.10);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.82,0.0);
    glVertex2f(-0.82,-0.10);
    glEnd();

    //5th floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.7,-0.15);
    glVertex2f(-0.7,-0.25);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.68,-0.15);
    glVertex2f(-0.68,-0.25);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.72,-0.15);
    glVertex2f(-0.72,-0.25);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.74,-0.15);
    glVertex2f(-0.74,-0.25);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.76,-0.15);
    glVertex2f(-0.76,-0.25);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.78,-0.15);
    glVertex2f(-0.78,-0.25);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.8,-0.15);
    glVertex2f(-0.8,-0.25);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.82,-0.15);
    glVertex2f(-0.82,-0.25);
    glEnd();

    //6th floor
    //1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.7,-0.55);
    glVertex2f(-0.7,-0.45);
    glEnd();
    //2
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.68,-0.55);
    glVertex2f(-0.68,-0.45);
    glEnd();
    //3
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.72,-0.55);
    glVertex2f(-0.72,-0.45);
    glEnd();
    //4
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.74,-0.55);
    glVertex2f(-0.74,-0.45);
    glEnd();
    //5
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.76,-0.55);
    glVertex2f(-0.76,-0.45);
    glEnd();
    //6
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.78,-0.55);
    glVertex2f(-0.78,-0.45);
    glEnd();
    //7
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.8,-0.55);
    glVertex2f(-0.8,-0.45);
    glEnd();
    //8
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.82,-0.55);
    glVertex2f(-0.82,-0.45);
    glEnd();

    glLoadIdentity();
}
//building 3
void Building3(){

    glBegin(GL_QUADS);
    glColor3ub(102,51,0);
    glVertex2f(-0.6f,0.0f);
    glVertex2f(-0.6f,-0.6f);
    glVertex2f(-0.35f,-0.6f);
    glVertex2f(-0.35f, 0.0f);
    glEnd();

    //floor 1 windows 1
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.59f,-0.05f);
    glVertex2f(-0.59f,-0.08f);
    glVertex2f(-0.56f,-0.08f);
    glVertex2f(-0.56f,-0.05f);
    glEnd();

    //floor 1 windows 2
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.54f,-0.05f);
    glVertex2f(-0.54f,-0.08f);
    glVertex2f(-0.51f,-0.08f);
    glVertex2f(-0.51f,-0.05f);
    glEnd();

    //floor 1 windows 3
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.49f,-0.05f);
    glVertex2f(-0.49f,-0.08f);
    glVertex2f(-0.46f,-0.08f);
    glVertex2f(-0.46f,-0.05f);
    glEnd();

    //floor 1 windows 4
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.44f,-0.08f);
    glVertex2f(-0.41f,-0.08f);
    glVertex2f(-0.41f,-0.05f);
    glEnd();

    //floor 1 windows 5
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.39f,-0.05f);
    glVertex2f(-0.39f,-0.08f);
    glVertex2f(-0.36f,-0.08f);
    glVertex2f(-0.36f,-0.05f);
    glEnd();

    //floor 2 windows 1
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2f(-0.59f,-0.10f);
    glVertex2f(-0.59f,-0.15f);
    glVertex2f(-0.56f,-0.15f);
    glVertex2f(-0.56f,-0.10f);
    glEnd();

    //floor 2 windows 2
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2f(-0.54f,-0.10f);
    glVertex2f(-0.54f,-0.15f);
    glVertex2f(-0.51f,-0.15f);
    glVertex2f(-0.51f,-0.10f);
    glEnd();

    //floor 2 windows 3
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2f(-0.49f,-0.10f);
    glVertex2f(-0.49f,-0.15f);
    glVertex2f(-0.46f,-0.15f);
    glVertex2f(-0.46f,-0.10f);
    glEnd();

    //floor 2 windows 4
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2f(-0.44f,-0.10f);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.41f,-0.15f);
    glVertex2f(-0.41f,-0.10f);
    glEnd();

    //floor 2 windows 5
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2f(-0.39f,-0.10f);
    glVertex2f(-0.39f,-0.15f);
    glVertex2f(-0.36f,-0.15f);
    glVertex2f(-0.36f,-0.10f);
    glEnd();

    //floor 3 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.18f);
    glVertex2f(-0.56f,-0.18f);
    glEnd();

    //floor 3 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.18f);
    glVertex2f(-0.51f,-0.18f);
    glEnd();

    //floor 3 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.18f);
    glVertex2f(-0.46f,-0.18f);
    glEnd();

    //floor 3 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.18f);
    glVertex2f(-0.41f,-0.18f);
    glEnd();

    //floor 3 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.18f);
    glVertex2f(-0.36f,-0.18f);
    glEnd();

    //floor 4 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.22f);
    glVertex2f(-0.56f,-0.22f);
    glEnd();

    //floor 4 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.22f);
    glVertex2f(-0.51f,-0.22f);
    glEnd();

    //floor 4 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.22f);
    glVertex2f(-0.46f,-0.22f);
    glEnd();

    //floor 4 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.22f);
    glVertex2f(-0.41f,-0.22f);
    glEnd();

    //floor 4 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.22f);
    glVertex2f(-0.36f,-0.22f);
    glEnd();

    //floor 5 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.26f);
    glVertex2f(-0.56f,-0.26f);
    glEnd();

    //floor 5 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.26f);
    glVertex2f(-0.51f,-0.26f);
    glEnd();

    //floor 5 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.26f);
    glVertex2f(-0.46f,-0.26f);
    glEnd();

     //floor 5 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.26f);
    glVertex2f(-0.41f,-0.26f);
    glEnd();

     //floor 5 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.26f);
    glVertex2f(-0.36f,-0.26f);
    glEnd();

    //floor 6 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.30f);
    glVertex2f(-0.56f,-0.30f);
    glEnd();

    //floor 6 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.30f);
    glVertex2f(-0.51f,-0.30f);
    glEnd();

    //floor 6 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.30f);
    glVertex2f(-0.46f,-0.30f);
    glEnd();

     //floor 6 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.30f);
    glVertex2f(-0.41f,-0.30f);
    glEnd();

     //floor 6 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.30f);
    glVertex2f(-0.36f,-0.30f);
    glEnd();

    //floor 7 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.34f);
    glVertex2f(-0.56f,-0.34f);
    glEnd();

    //floor 7 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.34f);
    glVertex2f(-0.51f,-0.34f);
    glEnd();

    //floor 7 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.34f);
    glVertex2f(-0.46f,-0.34f);
    glEnd();

     //floor 7 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.34f);
    glVertex2f(-0.41f,-0.34f);
    glEnd();

     //floor 7 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.34f);
    glVertex2f(-0.36f,-0.34f);
    glEnd();

     //floor 8 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.38f);
    glVertex2f(-0.56f,-0.38f);
    glEnd();

    //floor 8 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.38f);
    glVertex2f(-0.51f,-0.38f);
    glEnd();

    //floor 8 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.38f);
    glVertex2f(-0.46f,-0.38f);
    glEnd();

     //floor 8 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.38f);
    glVertex2f(-0.41f,-0.38f);
    glEnd();

     //floor 8 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.38f);
    glVertex2f(-0.36f,-0.38f);
    glEnd();

    //floor 9 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.42f);
    glVertex2f(-0.56f,-0.42f);
    glEnd();

    //floor 9 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.42f);
    glVertex2f(-0.51f,-0.42f);
    glEnd();

    //floor 9 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.42f);
    glVertex2f(-0.46f,-0.42f);
    glEnd();

     //floor 9 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.42f);
    glVertex2f(-0.41f,-0.42f);
    glEnd();

     //floor 9 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.42f);
    glVertex2f(-0.36f,-0.42f);
    glEnd();

    //floor 10 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.46f);
    glVertex2f(-0.56f,-0.46f);
    glEnd();

    //floor 10 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.46f);
    glVertex2f(-0.51f,-0.46f);
    glEnd();

    //floor 10 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.46f);
    glVertex2f(-0.46f,-0.46f);
    glEnd();

     //floor 10 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.46f);
    glVertex2f(-0.41f,-0.46f);
    glEnd();

     //floor 10 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.46f);
    glVertex2f(-0.36f,-0.46f);
    glEnd();

  //floor 11 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.50f);
    glVertex2f(-0.56f,-0.50f);
    glEnd();

    //floor 11 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.50f);
    glVertex2f(-0.51f,-0.50f);
    glEnd();

    //floor 11 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.50f);
    glVertex2f(-0.46f,-0.50f);
    glEnd();

     //floor 11 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.50f);
    glVertex2f(-0.41f,-0.50f);
    glEnd();

     //floor 11 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.50f);
    glVertex2f(-0.36f,-0.50f);
    glEnd();


     //floor 12 windows 1
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.59f,-0.55f);
    glVertex2f(-0.59f,-0.58f);
    glVertex2f(-0.56f,-0.58f);
    glVertex2f(-0.56f,-0.55f);
    glEnd();

    //floor 12 windows 2
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.54f,-0.55f);
    glVertex2f(-0.54f,-0.58f);
    glVertex2f(-0.51f,-0.58f);
    glVertex2f(-0.51f,-0.55f);
    glEnd();

    //floor 12 windows 3
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.49f,-0.55f);
    glVertex2f(-0.49f,-0.58f);
    glVertex2f(-0.46f,-0.58f);
    glVertex2f(-0.46f,-0.55f);
    glEnd();

    //floor 12 windows 4
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.44f,-0.55f);
    glVertex2f(-0.44f,-0.58f);
    glVertex2f(-0.41f,-0.58f);
    glVertex2f(-0.41f,-0.55f);
    glEnd();

    //floor 12 windows 5
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.39f,-0.55f);
    glVertex2f(-0.39f,-0.58f);
    glVertex2f(-0.36f,-0.58f);
    glVertex2f(-0.36f,-0.55f);
    glEnd();

    //topmost header base
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-0.6f,0.05f);
    glVertex2f(-0.6f,0.0f);
    glVertex2f(-0.35f,0.0f);
    glVertex2f(-0.35f,0.05f);
    glEnd();

    //topmost header base 2
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-0.55f,0.1f);
    glVertex2f(-0.57f,0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.41f,0.1f);
    glEnd();

    //topmost header base 3
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(0,51,51);
    glVertex2f(-0.48f,0.2f);
    glVertex2f(-0.48f,0.1f);
    glEnd();

    glLoadIdentity();
}


//building 3 night
//building 3
void Building3Night(){

    glBegin(GL_QUADS);
    glColor3ub(102,51,0);
    glVertex2f(-0.6f,0.0f);
    glVertex2f(-0.6f,-0.6f);
    glVertex2f(-0.35f,-0.6f);
    glVertex2f(-0.35f, 0.0f);
    glEnd();

    //floor 1 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.59f,-0.05f);
    glVertex2f(-0.59f,-0.08f);
    glVertex2f(-0.56f,-0.08f);
    glVertex2f(-0.56f,-0.05f);
    glEnd();

    //floor 1 windows 2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.05f);
    glVertex2f(-0.54f,-0.08f);
    glVertex2f(-0.51f,-0.08f);
    glVertex2f(-0.51f,-0.05f);
    glEnd();

    //floor 1 windows 3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.49f,-0.05f);
    glVertex2f(-0.49f,-0.08f);
    glVertex2f(-0.46f,-0.08f);
    glVertex2f(-0.46f,-0.05f);
    glEnd();

    //floor 1 windows 4
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.44f,-0.08f);
    glVertex2f(-0.41f,-0.08f);
    glVertex2f(-0.41f,-0.05f);
    glEnd();

    //floor 1 windows 5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.39f,-0.05f);
    glVertex2f(-0.39f,-0.08f);
    glVertex2f(-0.36f,-0.08f);
    glVertex2f(-0.36f,-0.05f);
    glEnd();

    //floor 2 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.59f,-0.10f);
    glVertex2f(-0.59f,-0.15f);
    glVertex2f(-0.56f,-0.15f);
    glVertex2f(-0.56f,-0.10f);
    glEnd();

    //floor 2 windows 2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.10f);
    glVertex2f(-0.54f,-0.15f);
    glVertex2f(-0.51f,-0.15f);
    glVertex2f(-0.51f,-0.10f);
    glEnd();

    //floor 2 windows 3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.49f,-0.10f);
    glVertex2f(-0.49f,-0.15f);
    glVertex2f(-0.46f,-0.15f);
    glVertex2f(-0.46f,-0.10f);
    glEnd();

    //floor 2 windows 4
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.10f);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.41f,-0.15f);
    glVertex2f(-0.41f,-0.10f);
    glEnd();

    //floor 2 windows 5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.39f,-0.10f);
    glVertex2f(-0.39f,-0.15f);
    glVertex2f(-0.36f,-0.15f);
    glVertex2f(-0.36f,-0.10f);
    glEnd();

    //floor 3 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.59f,-0.18f);
    glVertex2f(-0.56f,-0.18f);
    glEnd();

    //floor 3 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.18f);
    glVertex2f(-0.51f,-0.18f);
    glEnd();

    //floor 3 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.49f,-0.18f);
    glVertex2f(-0.46f,-0.18f);
    glEnd();

    //floor 3 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.18f);
    glVertex2f(-0.41f,-0.18f);
    glEnd();

    //floor 3 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.39f,-0.18f);
    glVertex2f(-0.36f,-0.18f);
    glEnd();

    //floor 4 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.22f);
    glVertex2f(-0.56f,-0.22f);
    glEnd();

    //floor 4 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.22f);
    glVertex2f(-0.51f,-0.22f);
    glEnd();

    //floor 4 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.22f);
    glVertex2f(-0.46f,-0.22f);
    glEnd();

    //floor 4 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.22f);
    glVertex2f(-0.41f,-0.22f);
    glEnd();

    //floor 4 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.22f);
    glVertex2f(-0.36f,-0.22f);
    glEnd();

    //floor 5 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.59f,-0.26f);
    glVertex2f(-0.56f,-0.26f);
    glEnd();

    //floor 5 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.26f);
    glVertex2f(-0.51f,-0.26f);
    glEnd();

    //floor 5 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.49f,-0.26f);
    glVertex2f(-0.46f,-0.26f);
    glEnd();

     //floor 5 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.26f);
    glVertex2f(-0.41f,-0.26f);
    glEnd();

     //floor 5 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.39f,-0.26f);
    glVertex2f(-0.36f,-0.26f);
    glEnd();

    //floor 6 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.30f);
    glVertex2f(-0.56f,-0.30f);
    glEnd();

    //floor 6 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.30f);
    glVertex2f(-0.51f,-0.30f);
    glEnd();

    //floor 6 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.30f);
    glVertex2f(-0.46f,-0.30f);
    glEnd();

     //floor 6 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.30f);
    glVertex2f(-0.41f,-0.30f);
    glEnd();

     //floor 6 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.30f);
    glVertex2f(-0.36f,-0.30f);
    glEnd();

    //floor 7 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.59f,-0.34f);
    glVertex2f(-0.56f,-0.34f);
    glEnd();

    //floor 7 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.34f);
    glVertex2f(-0.51f,-0.34f);
    glEnd();

    //floor 7 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.49f,-0.34f);
    glVertex2f(-0.46f,-0.34f);
    glEnd();

     //floor 7 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.34f);
    glVertex2f(-0.41f,-0.34f);
    glEnd();

     //floor 7 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.39f,-0.34f);
    glVertex2f(-0.36f,-0.34f);
    glEnd();

     //floor 8 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.38f);
    glVertex2f(-0.56f,-0.38f);
    glEnd();

    //floor 8 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.38f);
    glVertex2f(-0.51f,-0.38f);
    glEnd();

    //floor 8 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.38f);
    glVertex2f(-0.46f,-0.38f);
    glEnd();

     //floor 8 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.38f);
    glVertex2f(-0.41f,-0.38f);
    glEnd();

     //floor 8 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.38f);
    glVertex2f(-0.36f,-0.38f);
    glEnd();

    //floor 9 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.59f,-0.42f);
    glVertex2f(-0.56f,-0.42f);
    glEnd();

    //floor 9 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.42f);
    glVertex2f(-0.51f,-0.42f);
    glEnd();

    //floor 9 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.49f,-0.42f);
    glVertex2f(-0.46f,-0.42f);
    glEnd();

     //floor 9 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.42f);
    glVertex2f(-0.41f,-0.42f);
    glEnd();

     //floor 9 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.39f,-0.42f);
    glVertex2f(-0.36f,-0.42f);
    glEnd();

    //floor 10 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.59f,-0.46f);
    glVertex2f(-0.56f,-0.46f);
    glEnd();

    //floor 10 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.54f,-0.46f);
    glVertex2f(-0.51f,-0.46f);
    glEnd();

    //floor 10 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.49f,-0.46f);
    glVertex2f(-0.46f,-0.46f);
    glEnd();

     //floor 10 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.44f,-0.46f);
    glVertex2f(-0.41f,-0.46f);
    glEnd();

     //floor 10 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229,255,204);
    glVertex2f(-0.39f,-0.46f);
    glVertex2f(-0.36f,-0.46f);
    glEnd();

  //floor 11 windows 1
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.59f,-0.50f);
    glVertex2f(-0.56f,-0.50f);
    glEnd();

    //floor 11 windows 2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.50f);
    glVertex2f(-0.51f,-0.50f);
    glEnd();

    //floor 11 windows 3
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.49f,-0.50f);
    glVertex2f(-0.46f,-0.50f);
    glEnd();

     //floor 11 windows 4
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.50f);
    glVertex2f(-0.41f,-0.50f);
    glEnd();

     //floor 11 windows 5
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.39f,-0.50f);
    glVertex2f(-0.36f,-0.50f);
    glEnd();


     //floor 12 windows 1
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.59f,-0.55f);
    glVertex2f(-0.59f,-0.58f);
    glVertex2f(-0.56f,-0.58f);
    glVertex2f(-0.56f,-0.55f);
    glEnd();

    //floor 12 windows 2
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.54f,-0.55f);
    glVertex2f(-0.54f,-0.58f);
    glVertex2f(-0.51f,-0.58f);
    glVertex2f(-0.51f,-0.55f);
    glEnd();

    //floor 12 windows 3
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.49f,-0.55f);
    glVertex2f(-0.49f,-0.58f);
    glVertex2f(-0.46f,-0.58f);
    glVertex2f(-0.46f,-0.55f);
    glEnd();

    //floor 12 windows 4
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.44f,-0.55f);
    glVertex2f(-0.44f,-0.58f);
    glVertex2f(-0.41f,-0.58f);
    glVertex2f(-0.41f,-0.55f);
    glEnd();

    //floor 12 windows 5
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.39f,-0.55f);
    glVertex2f(-0.39f,-0.58f);
    glVertex2f(-0.36f,-0.58f);
    glVertex2f(-0.36f,-0.55f);
    glEnd();

    //topmost header base
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-0.6f,0.05f);
    glVertex2f(-0.6f,0.0f);
    glVertex2f(-0.35f,0.0f);
    glVertex2f(-0.35f,0.05f);
    glEnd();

    //topmost header base 2
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-0.55f,0.1f);
    glVertex2f(-0.57f,0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.41f,0.1f);
    glEnd();

    //topmost header base 3
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(0,51,51);
    glVertex2f(-0.48f,0.2f);
    glVertex2f(-0.48f,0.1f);
    glEnd();

    glLoadIdentity();
}

//building 4
void Building4(){
    glBegin(GL_QUADS);
    glColor3f(0.7f,0.7f,0.7f);
    glVertex2f(-0.6f,0.3f);
    glVertex2f(-0.6f,-0.6f);
    glVertex2f(-0.5f,-0.6f);
    glVertex2f(-0.5f, 0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(-0.5f,0.4f);
    glVertex2f(-0.5f,-0.6f);
    glVertex2f(-0.3f,-0.6f);
    glVertex2f(-0.3f, 0.4f);
    glEnd();
    glLoadIdentity();
}
//building 5
void Building5(){
glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.15f,0.2f);
    glVertex2f(-0.15f,-0.6f);
    glVertex2f(-0.05f,-0.6f);
    glVertex2f(-0.05f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5f,0.0f,0.0f);
    glVertex2f(-0.05f,0.2f);
    glVertex2f(-0.05f,-0.6f);
    glVertex2f(0.15f,-0.6f);
    glEnd();

    //windows
    //left side
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,0.18f);
    glVertex2f(-0.13f,0.12f);
    glVertex2f(-0.07f,0.12f);
    glVertex2f(-0.07f,0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,0.10f);
    glVertex2f(-0.13f,0.04f);
    glVertex2f(-0.07f,0.04f);
    glVertex2f(-0.07f,0.10f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,0.02f);
    glVertex2f(-0.13f,-0.04f);
    glVertex2f(-0.07f,-0.04f);
    glVertex2f(-0.07f,0.02f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,-0.06f);
    glVertex2f(-0.13f,-0.12f);
    glVertex2f(-0.07f,-0.12f);
    glVertex2f(-0.07f,-0.06f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,-0.14f);
    glVertex2f(-0.13f,-0.20f);
    glVertex2f(-0.07f,-0.20f);
    glVertex2f(-0.07f,-0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,-0.22f);
    glVertex2f(-0.13f,-0.28f);
    glVertex2f(-0.07f,-0.28f);
    glVertex2f(-0.07f,-0.22f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,-0.30f);
    glVertex2f(-0.13f,-0.36f);
    glVertex2f(-0.07f,-0.36f);
    glVertex2f(-0.07f,-0.30f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,-0.38f);
    glVertex2f(-0.13f,-0.44f);
    glVertex2f(-0.07f,-0.44f);
    glVertex2f(-0.07f,-0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,-0.46f);
    glVertex2f(-0.13f,-0.52f);
    glVertex2f(-0.07f,-0.52f);
    glVertex2f(-0.07f,-0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.13f,-0.54f);
    glVertex2f(-0.13f,-0.58f);
    glVertex2f(-0.07f,-0.58f);
    glVertex2f(-0.07f,-0.54f);
    glEnd();
    glLoadIdentity();
}


//building 5 night
void Building5Night(){
glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.15f,0.2f);
    glVertex2f(-0.15f,-0.6f);
    glVertex2f(-0.05f,-0.6f);
    glVertex2f(-0.05f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5f,0.0f,0.0f);
    glVertex2f(-0.05f,0.2f);
    glVertex2f(-0.05f,-0.6f);
    glVertex2f(0.15f,-0.6f);
    glEnd();

    //windows
    //left side
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,0.18f);
    glVertex2f(-0.13f,0.12f);
    glVertex2f(-0.07f,0.12f);
    glVertex2f(-0.07f,0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,0.10f);
    glVertex2f(-0.13f,0.04f);
    glVertex2f(-0.07f,0.04f);
    glVertex2f(-0.07f,0.10f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,0.02f);
    glVertex2f(-0.13f,-0.04f);
    glVertex2f(-0.07f,-0.04f);
    glVertex2f(-0.07f,0.02f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,-0.06f);
    glVertex2f(-0.13f,-0.12f);
    glVertex2f(-0.07f,-0.12f);
    glVertex2f(-0.07f,-0.06f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,-0.14f);
    glVertex2f(-0.13f,-0.20f);
    glVertex2f(-0.07f,-0.20f);
    glVertex2f(-0.07f,-0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,-0.22f);
    glVertex2f(-0.13f,-0.28f);
    glVertex2f(-0.07f,-0.28f);
    glVertex2f(-0.07f,-0.22f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,-0.30f);
    glVertex2f(-0.13f,-0.36f);
    glVertex2f(-0.07f,-0.36f);
    glVertex2f(-0.07f,-0.30f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,-0.38f);
    glVertex2f(-0.13f,-0.44f);
    glVertex2f(-0.07f,-0.44f);
    glVertex2f(-0.07f,-0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,-0.46f);
    glVertex2f(-0.13f,-0.52f);
    glVertex2f(-0.07f,-0.52f);
    glVertex2f(-0.07f,-0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.13f,-0.54f);
    glVertex2f(-0.13f,-0.58f);
    glVertex2f(-0.07f,-0.58f);
    glVertex2f(-0.07f,-0.54f);
    glEnd();
    glLoadIdentity();
}

void Building9(){
    //9 NO BUILDING START
    glBegin(GL_QUADS);
    glColor3ub(95,182,147);
    glVertex2f(-0.25f,0.3f);
    glVertex2f(-0.25f,-0.6f);
    glVertex2f(-0.38f,-0.6f);
    glVertex2f(-0.38f,0.3f);
    glEnd();


    //Windows Start
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.28f);
    glVertex2f(-0.37f,0.26f);
    glVertex2f(-0.26f,0.26f);
    glVertex2f(-0.26f,0.28f);
    glEnd();

    //2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.25f);
    glVertex2f(-0.37f,0.23f);
    glVertex2f(-0.26f,0.23f);
    glVertex2f(-0.26f,0.25f);
    glEnd();

    //3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.22f);
    glVertex2f(-0.37f,0.20f);
    glVertex2f(-0.26f,0.20f);
    glVertex2f(-0.26f,0.22f);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.19f);
    glVertex2f(-0.37f,0.17f);
    glVertex2f(-0.26f,0.17f);
    glVertex2f(-0.26f,0.19f);
    glEnd();

    //5
     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.16f);
    glVertex2f(-0.37f,0.14f);
    glVertex2f(-0.26f,0.14f);
    glVertex2f(-0.26f,0.16f);
    glEnd();

    //6
      glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.13f);
    glVertex2f(-0.37f,0.11f);
    glVertex2f(-0.26f,0.11f);
    glVertex2f(-0.26f,0.13f);
    glEnd();

    //7
      glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.10f);
    glVertex2f(-0.37f,0.08f);
    glVertex2f(-0.26f,0.08f);
    glVertex2f(-0.26f,0.10f);
    glEnd();

    //8
     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.07f);
    glVertex2f(-0.37f,0.05f);
    glVertex2f(-0.26f,0.05f);
    glVertex2f(-0.26f,0.07f);
    glEnd();

    //9
     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.04f);
    glVertex2f(-0.37f,0.02f);
    glVertex2f(-0.26f,0.02f);
    glVertex2f(-0.26f,0.04f);
    glEnd();

    //10
     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,0.01f);
    glVertex2f(-0.37f,-0.01f);
    glVertex2f(-0.26f,-0.01f);
    glVertex2f(-0.26f,0.01f);
    glEnd();

    //11
     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.02f);
    glVertex2f(-0.37f,-0.04f);
    glVertex2f(-0.26f,-0.04f);
    glVertex2f(-0.26f,-0.02f);
    glEnd();

    //12
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.05f);
    glVertex2f(-0.37f,-0.07f);
    glVertex2f(-0.26f,-0.07f);
    glVertex2f(-0.26f,-0.05f);
    glEnd();

    //13
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.08f);
    glVertex2f(-0.37f,-0.1f);
    glVertex2f(-0.26f,-0.1f);
    glVertex2f(-0.26f,-0.08f);
    glEnd();

    //14
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.11f);
    glVertex2f(-0.37f,-0.13f);
    glVertex2f(-0.26f,-0.13f);
    glVertex2f(-0.26f,-0.11f);
    glEnd();

    //15
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.14f);
    glVertex2f(-0.37f,-0.16f);
    glVertex2f(-0.26f,-0.16f);
    glVertex2f(-0.26f,-0.14f);
    glEnd();

    //16
     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.17f);
    glVertex2f(-0.37f,-0.19f);
    glVertex2f(-0.26f,-0.19f);
    glVertex2f(-0.26f,-0.17f);
    glEnd();

    //17
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.20f);
    glVertex2f(-0.37f,-0.22f);
    glVertex2f(-0.26f,-0.22f);
    glVertex2f(-0.26f,-0.20f);
    glEnd();

    //18
       glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.23f);
    glVertex2f(-0.37f,-0.25f);
    glVertex2f(-0.26f,-0.25f);
    glVertex2f(-0.26f,-0.23f);
    glEnd();

    //19
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.26f);
    glVertex2f(-0.37f,-0.28f);
    glVertex2f(-0.26f,-0.28f);
    glVertex2f(-0.26f,-0.26f);
    glEnd();

    //20
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.29f);
    glVertex2f(-0.37f,-0.31f);
    glVertex2f(-0.26f,-0.31f);
    glVertex2f(-0.26f,-0.29f);
    glEnd();

    //21

        glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.32f);
    glVertex2f(-0.37f,-0.34f);
    glVertex2f(-0.26f,-0.34f);
    glVertex2f(-0.26f,-0.32f);
    glEnd();

    //22

            glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.35f);
    glVertex2f(-0.37f,-0.37f);
    glVertex2f(-0.26f,-0.37f);
    glVertex2f(-0.26f,-0.35f);
    glEnd();

    //23


            glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.38f);
    glVertex2f(-0.37f,-0.40f);
    glVertex2f(-0.26f,-0.40f);
    glVertex2f(-0.26f,-0.38f);
    glEnd();

    //24


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.41f);
    glVertex2f(-0.37f,-0.43f);
    glVertex2f(-0.26f,-0.43f);
    glVertex2f(-0.26f,-0.41f);
    glEnd();

    //25

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.44f);
    glVertex2f(-0.37f,-0.46f);
    glVertex2f(-0.26f,-0.46f);
    glVertex2f(-0.26f,-0.44f);
    glEnd();


    //26


        glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.47f);
    glVertex2f(-0.37f,-0.49f);
    glVertex2f(-0.26f,-0.49f);
    glVertex2f(-0.26f,-0.47f);
    glEnd();

    //27

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.50f);
    glVertex2f(-0.37f,-0.52f);
    glVertex2f(-0.26f,-0.52f);
    glVertex2f(-0.26f,-0.50f);
    glEnd();


    //28


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.53f);
    glVertex2f(-0.37f,-0.55f);
    glVertex2f(-0.26f,-0.55f);
    glVertex2f(-0.26f,-0.53f);
    glEnd();

    //29

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.37f,-0.56f);
    glVertex2f(-0.37f,-0.58f);
    glVertex2f(-0.26f,-0.58f);
    glVertex2f(-0.26f,-0.56f);
    glEnd();

    //windows end


    //9 no Building right-side
    glBegin(GL_QUADS);
    glColor3ub(52,124,101);
    glVertex2f(-0.25f,0.3f);
    glVertex2f(-0.25f,-0.6f);
    glVertex2f(-0.21f,-0.6f);
    glVertex2f(-0.21f,0.2f);
    glEnd();

    //9 no building END
    glLoadIdentity();
}
void Building7Night(){
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2f(-1.0f,0.9f);
    glVertex2f(-1.0f,-0.6f);
    glVertex2f(-0.9f,-0.6f);
    glVertex2f(-0.9f,0.9f);
    glEnd();
    //window 1
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.88f);
    glVertex2f(-0.99f,0.86f);
    glVertex2f(-0.91f,0.86f);
    glVertex2f(-0.91f,0.88f);
    glEnd();

    //window 2
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.84f);
    glVertex2f(-0.99f,0.82f);
    glVertex2f(-0.91f,0.82f);
    glVertex2f(-0.91f,0.84f);
    glEnd();

    //window 3
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.80f);
    glVertex2f(-0.99f,0.78f);
    glVertex2f(-0.91f,0.78f);
    glVertex2f(-0.91f,0.80f);
    glEnd();

    //window 4
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.76f);
    glVertex2f(-0.99f,0.74f);
    glVertex2f(-0.91f,0.74f);
    glVertex2f(-0.91f,0.76f);
    glEnd();

    //window 5
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.72f);
    glVertex2f(-0.99f,0.70f);
    glVertex2f(-0.91f,0.70f);
    glVertex2f(-0.91f,0.72f);
    glEnd();

    //window 6
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.68f);
    glVertex2f(-0.99f,0.66f);
    glVertex2f(-0.91f,0.66f);
    glVertex2f(-0.91f,0.68f);
    glEnd();

    //window 7
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.64f);
    glVertex2f(-0.99f,0.62f);
    glVertex2f(-0.91f,0.62f);
    glVertex2f(-0.91f,0.64f);
    glEnd();

    //window 8
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.60f);
    glVertex2f(-0.99f,0.58f);
    glVertex2f(-0.91f,0.58f);
    glVertex2f(-0.91f,0.60f);
    glEnd();

    //window 9
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.56f);
    glVertex2f(-0.99f,0.54f);
    glVertex2f(-0.91f,0.54f);
    glVertex2f(-0.91f,0.56f);
    glEnd();

    //window 10
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.52f);
    glVertex2f(-0.99f,0.50f);
    glVertex2f(-0.91f,0.50f);
    glVertex2f(-0.91f,0.52f);
    glEnd();

    //window 11
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.48f);
    glVertex2f(-0.99f,0.46f);
    glVertex2f(-0.91f,0.46f);
    glVertex2f(-0.91f,0.48f);
    glEnd();

    //window 12
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.44f);
    glVertex2f(-0.99f,0.42f);
    glVertex2f(-0.91f,0.42f);
    glVertex2f(-0.91f,0.44f);
    glEnd();

    //window 13
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.40f);
    glVertex2f(-0.99f,0.38f);
    glVertex2f(-0.91f,0.38f);
    glVertex2f(-0.91f,0.40f);
    glEnd();

    //window 14
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.36f);
    glVertex2f(-0.99f,0.34f);
    glVertex2f(-0.91f,0.34f);
    glVertex2f(-0.91f,0.36f);
    glEnd();

    //window 15
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.32f);
    glVertex2f(-0.99f,0.30f);
    glVertex2f(-0.91f,0.30f);
    glVertex2f(-0.91f,0.32f);
    glEnd();

    //window 16
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.28f);
    glVertex2f(-0.99f,0.26f);
    glVertex2f(-0.91f,0.26f);
    glVertex2f(-0.91f,0.28f);
    glEnd();

    //window 17
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.24f);
    glVertex2f(-0.99f,0.22f);
    glVertex2f(-0.91f,0.22f);
    glVertex2f(-0.91f,0.24f);
    glEnd();

    //window 18
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.20f);
    glVertex2f(-0.99f,0.18f);
    glVertex2f(-0.91f,0.18f);
    glVertex2f(-0.91f,0.20f);
    glEnd();

    //window 19
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.16f);
    glVertex2f(-0.99f,0.14f);
    glVertex2f(-0.91f,0.14f);
    glVertex2f(-0.91f,0.16f);
    glEnd();

    //window 20
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.12f);
    glVertex2f(-0.99f,0.10f);
    glVertex2f(-0.91f,0.10f);
    glVertex2f(-0.91f,0.12f);
    glEnd();

    //window 21
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.08f);
    glVertex2f(-0.99f,0.06f);
    glVertex2f(-0.91f,0.06f);
    glVertex2f(-0.91f,0.08f);
    glEnd();

    //window 22
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.99f,0.04f);
    glVertex2f(-0.99f,0.02f);
    glVertex2f(-0.91f,0.02f);
    glVertex2f(-0.91f,0.04f);
    glEnd();

}

void Building8Night(){
    glBegin(GL_QUADS);
    glColor3ub(160,160,160);
    glVertex2f(-0.9f,0.7f);
    glVertex2f(-0.9f,-0.6f);
    glVertex2f(-0.8f,-0.6f);
    glVertex2f(-0.8f,0.7f);
    glEnd();
    //window 1
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.68f);
    glVertex2f(-0.89f,0.66f);
    glVertex2f(-0.81f,0.66f);
    glVertex2f(-0.81f,0.68f);
    glEnd();

    //window 2
  glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.64f);
    glVertex2f(-0.89f,0.62f);
    glVertex2f(-0.81f,0.62f);
    glVertex2f(-0.81f,0.64f);
    glEnd();

    //window 3
  glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.60f);
    glVertex2f(-0.89f,0.58f);
    glVertex2f(-0.81f,0.58f);
    glVertex2f(-0.81f,0.60f);
    glEnd();

    //window 4
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.56f);
    glVertex2f(-0.89f,0.54f);
    glVertex2f(-0.81f,0.54f);
    glVertex2f(-0.81f,0.56f);
    glEnd();

    //window 5
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.52f);
    glVertex2f(-0.89f,0.50f);
    glVertex2f(-0.81f,0.50f);
    glVertex2f(-0.81f,0.52f);
    glEnd();

    //window 6
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.48f);
    glVertex2f(-0.89f,0.46f);
    glVertex2f(-0.81f,0.46f);
    glVertex2f(-0.81f,0.48f);
    glEnd();

    //window 7
  glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.44f);
    glVertex2f(-0.89f,0.42f);
    glVertex2f(-0.81f,0.42f);
    glVertex2f(-0.81f,0.44f);
    glEnd();

    //window 8
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.40f);
    glVertex2f(-0.89f,0.38f);
    glVertex2f(-0.81f,0.38f);
    glVertex2f(-0.81f,0.40f);
    glEnd();

    //window 9
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.36f);
    glVertex2f(-0.89f,0.34f);
    glVertex2f(-0.81f,0.34f);
    glVertex2f(-0.81f,0.36f);
    glEnd();

    //window 10
 glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.32f);
    glVertex2f(-0.89f,0.30f);
    glVertex2f(-0.81f,0.30f);
    glVertex2f(-0.81f,0.32f);
    glEnd();

    //window 11
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.28f);
    glVertex2f(-0.89f,0.26f);
    glVertex2f(-0.81f,0.26f);
    glVertex2f(-0.81f,0.28f);
    glEnd();

    //window 12
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.24f);
    glVertex2f(-0.89f,0.22f);
    glVertex2f(-0.81f,0.22f);
    glVertex2f(-0.81f,0.24f);
    glEnd();

    //window 13
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.20f);
    glVertex2f(-0.89f,0.18f);
    glVertex2f(-0.81f,0.18f);
    glVertex2f(-0.81f,0.20f);
    glEnd();

    //window 14
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.16f);
    glVertex2f(-0.89f,0.14f);
    glVertex2f(-0.81f,0.14f);
    glVertex2f(-0.81f,0.16f);
    glEnd();

    //window 15
 glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.12f);
    glVertex2f(-0.89f,0.10f);
    glVertex2f(-0.81f,0.10f);
    glVertex2f(-0.81f,0.12f);
    glEnd();

    //window 16
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.08f);
    glVertex2f(-0.89f,0.06f);
    glVertex2f(-0.81f,0.06f);
    glVertex2f(-0.81f,0.08f);
    glEnd();

    //window 17
   glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.89f,0.04f);
    glVertex2f(-0.89f,0.02f);
    glVertex2f(-0.81f,0.02f);
    glVertex2f(-0.81f,0.04f);
    glEnd();

}

//building 9 night
void Building9Night(){
    //9 NO BUILDING START
    glBegin(GL_QUADS);
    glColor3ub(95,182,147);
    glVertex2f(-0.25f,0.3f);
    glVertex2f(-0.25f,-0.6f);
    glVertex2f(-0.38f,-0.6f);
    glVertex2f(-0.38f,0.3f);
    glEnd();


    //Windows Start
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.28f);
    glVertex2f(-0.37f,0.26f);
    glVertex2f(-0.26f,0.26f);
    glVertex2f(-0.26f,0.28f);
    glEnd();

    //2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.25f);
    glVertex2f(-0.37f,0.23f);
    glVertex2f(-0.26f,0.23f);
    glVertex2f(-0.26f,0.25f);
    glEnd();

    //3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.22f);
    glVertex2f(-0.37f,0.20f);
    glVertex2f(-0.26f,0.20f);
    glVertex2f(-0.26f,0.22f);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.19f);
    glVertex2f(-0.37f,0.17f);
    glVertex2f(-0.26f,0.17f);
    glVertex2f(-0.26f,0.19f);
    glEnd();

    //5
     glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.16f);
    glVertex2f(-0.37f,0.14f);
    glVertex2f(-0.26f,0.14f);
    glVertex2f(-0.26f,0.16f);
    glEnd();

    //6
      glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.13f);
    glVertex2f(-0.37f,0.11f);
    glVertex2f(-0.26f,0.11f);
    glVertex2f(-0.26f,0.13f);
    glEnd();

    //7
      glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.10f);
    glVertex2f(-0.37f,0.08f);
    glVertex2f(-0.26f,0.08f);
    glVertex2f(-0.26f,0.10f);
    glEnd();

    //8
     glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.07f);
    glVertex2f(-0.37f,0.05f);
    glVertex2f(-0.26f,0.05f);
    glVertex2f(-0.26f,0.07f);
    glEnd();

    //9
     glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.04f);
    glVertex2f(-0.37f,0.02f);
    glVertex2f(-0.26f,0.02f);
    glVertex2f(-0.26f,0.04f);
    glEnd();

    //10
     glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,0.01f);
    glVertex2f(-0.37f,-0.01f);
    glVertex2f(-0.26f,-0.01f);
    glVertex2f(-0.26f,0.01f);
    glEnd();

    //11
     glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.02f);
    glVertex2f(-0.37f,-0.04f);
    glVertex2f(-0.26f,-0.04f);
    glVertex2f(-0.26f,-0.02f);
    glEnd();

    //12
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.05f);
    glVertex2f(-0.37f,-0.07f);
    glVertex2f(-0.26f,-0.07f);
    glVertex2f(-0.26f,-0.05f);
    glEnd();

    //13
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.08f);
    glVertex2f(-0.37f,-0.1f);
    glVertex2f(-0.26f,-0.1f);
    glVertex2f(-0.26f,-0.08f);
    glEnd();

    //14
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.11f);
    glVertex2f(-0.37f,-0.13f);
    glVertex2f(-0.26f,-0.13f);
    glVertex2f(-0.26f,-0.11f);
    glEnd();

    //15
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.14f);
    glVertex2f(-0.37f,-0.16f);
    glVertex2f(-0.26f,-0.16f);
    glVertex2f(-0.26f,-0.14f);
    glEnd();

    //16
     glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.17f);
    glVertex2f(-0.37f,-0.19f);
    glVertex2f(-0.26f,-0.19f);
    glVertex2f(-0.26f,-0.17f);
    glEnd();

    //17
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.20f);
    glVertex2f(-0.37f,-0.22f);
    glVertex2f(-0.26f,-0.22f);
    glVertex2f(-0.26f,-0.20f);
    glEnd();

    //18
       glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.23f);
    glVertex2f(-0.37f,-0.25f);
    glVertex2f(-0.26f,-0.25f);
    glVertex2f(-0.26f,-0.23f);
    glEnd();

    //19
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.26f);
    glVertex2f(-0.37f,-0.28f);
    glVertex2f(-0.26f,-0.28f);
    glVertex2f(-0.26f,-0.26f);
    glEnd();

    //20
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.29f);
    glVertex2f(-0.37f,-0.31f);
    glVertex2f(-0.26f,-0.31f);
    glVertex2f(-0.26f,-0.29f);
    glEnd();

    //21

        glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.32f);
    glVertex2f(-0.37f,-0.34f);
    glVertex2f(-0.26f,-0.34f);
    glVertex2f(-0.26f,-0.32f);
    glEnd();

    //22

            glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.35f);
    glVertex2f(-0.37f,-0.37f);
    glVertex2f(-0.26f,-0.37f);
    glVertex2f(-0.26f,-0.35f);
    glEnd();

    //23


    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.38f);
    glVertex2f(-0.37f,-0.40f);
    glVertex2f(-0.26f,-0.40f);
    glVertex2f(-0.26f,-0.38f);
    glEnd();

    //24


    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.41f);
    glVertex2f(-0.37f,-0.43f);
    glVertex2f(-0.26f,-0.43f);
    glVertex2f(-0.26f,-0.41f);
    glEnd();

    //25

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.44f);
    glVertex2f(-0.37f,-0.46f);
    glVertex2f(-0.26f,-0.46f);
    glVertex2f(-0.26f,-0.44f);
    glEnd();


    //26


    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.47f);
    glVertex2f(-0.37f,-0.49f);
    glVertex2f(-0.26f,-0.49f);
    glVertex2f(-0.26f,-0.47f);
    glEnd();

    //27

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.50f);
    glVertex2f(-0.37f,-0.52f);
    glVertex2f(-0.26f,-0.52f);
    glVertex2f(-0.26f,-0.50f);
    glEnd();


    //28


    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.53f);
    glVertex2f(-0.37f,-0.55f);
    glVertex2f(-0.26f,-0.55f);
    glVertex2f(-0.26f,-0.53f);
    glEnd();

    //29

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.37f,-0.56f);
    glVertex2f(-0.37f,-0.58f);
    glVertex2f(-0.26f,-0.58f);
    glVertex2f(-0.26f,-0.56f);
    glEnd();

    //windows end


    //9 no Building right-side
    glBegin(GL_QUADS);
    glColor3ub(52,124,101);
    glVertex2f(-0.25f,0.3f);
    glVertex2f(-0.25f,-0.6f);
    glVertex2f(-0.21f,-0.6f);
    glVertex2f(-0.21f,0.2f);
    glEnd();

    //9 no building END
    glLoadIdentity();
}

void Building10(){

    glBegin(GL_QUADS);
    glColor3ub(38,41,65);
    glVertex2f(-0.26f,-0.1f);
    glVertex2f(-0.26f,-0.6f);
    glVertex2f(-0.17f,-0.6f);
    glVertex2f(-0.17f,-0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(9,9,9);
    glVertex2f(-0.17f,-0.1f);
    glVertex2f(-0.17f,-0.6f);
    glVertex2f(-0.10f,-0.6f);
    glVertex2f(-0.10f,-0.2f);
    glEnd();

    //floor 1 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.12f);
    glVertex2f(-0.25f,-0.14f);
    glVertex2f(-0.18f,-0.14f);
    glVertex2f(-0.18f,-0.12f);
    glEnd();

    //floor 2 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.15f);
    glVertex2f(-0.25f,-0.17f);
    glVertex2f(-0.18f,-0.17f);
    glVertex2f(-0.18f,-0.15f);
    glEnd();

    //floor 3 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.18f);
    glVertex2f(-0.25f,-0.20f);
    glVertex2f(-0.18f,-0.20f);
    glVertex2f(-0.18f,-0.18f);
    glEnd();

    //floor 4 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.21f);
    glVertex2f(-0.25f,-0.23f);
    glVertex2f(-0.18f,-0.23f);
    glVertex2f(-0.18f,-0.21f);
    glEnd();

     //floor 5 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.24f);
    glVertex2f(-0.25f,-0.26f);
    glVertex2f(-0.18f,-0.26f);
    glVertex2f(-0.18f,-0.24f);
    glEnd();

     //floor 6 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.27f);
    glVertex2f(-0.25f,-0.29f);
    glVertex2f(-0.18f,-0.29f);
    glVertex2f(-0.18f,-0.27f);
    glEnd();

     //floor 7 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.30f);
    glVertex2f(-0.25f,-0.32f);
    glVertex2f(-0.18f,-0.32f);
    glVertex2f(-0.18f,-0.30f);
    glEnd();

     //floor 8 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.33f);
    glVertex2f(-0.25f,-0.35f);
    glVertex2f(-0.18f,-0.35f);
    glVertex2f(-0.18f,-0.33f);
    glEnd();

     //floor 9 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.36f);
    glVertex2f(-0.25f,-0.38f);
    glVertex2f(-0.18f,-0.38f);
    glVertex2f(-0.18f,-0.36f);
    glEnd();

    //floor 10 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.39f);
    glVertex2f(-0.25f,-0.41f);
    glVertex2f(-0.18f,-0.41f);
    glVertex2f(-0.18f,-0.39f);
    glEnd();

    //floor 11 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.42f);
    glVertex2f(-0.25f,-0.44f);
    glVertex2f(-0.18f,-0.44f);
    glVertex2f(-0.18f,-0.42f);
    glEnd();

    //floor 12 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.45f);
    glVertex2f(-0.25f,-0.47f);
    glVertex2f(-0.18f,-0.47f);
    glVertex2f(-0.18f,-0.45f);
    glEnd();

    //floor 13 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.48f);
    glVertex2f(-0.25f,-0.50f);
    glVertex2f(-0.18f,-0.50f);
    glVertex2f(-0.18f,-0.48f);
    glEnd();

    //floor 14 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.51f);
    glVertex2f(-0.25f,-0.53f);
    glVertex2f(-0.18f,-0.53f);
    glVertex2f(-0.18f,-0.51f);
    glEnd();

    //floor 15 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.54f);
    glVertex2f(-0.25f,-0.56f);
    glVertex2f(-0.18f,-0.56f);
    glVertex2f(-0.18f,-0.54f);
    glEnd();

    //floor 16 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.57f);
    glVertex2f(-0.25f,-0.59f);
    glVertex2f(-0.18f,-0.59f);
    glVertex2f(-0.18f,-0.57f);
    glEnd();

    glLoadIdentity();
}

//building 10 night
void Building10Night(){

    glBegin(GL_QUADS);
    glColor3ub(38,41,65);
    glVertex2f(-0.26f,-0.1f);
    glVertex2f(-0.26f,-0.6f);
    glVertex2f(-0.17f,-0.6f);
    glVertex2f(-0.17f,-0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(9,9,9);
    glVertex2f(-0.17f,-0.1f);
    glVertex2f(-0.17f,-0.6f);
    glVertex2f(-0.10f,-0.6f);
    glVertex2f(-0.10f,-0.2f);
    glEnd();

    //floor 1 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.25f,-0.12f);
    glVertex2f(-0.25f,-0.14f);
    glVertex2f(-0.18f,-0.14f);
    glVertex2f(-0.18f,-0.12f);
    glEnd();

    //floor 2 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.15f);
    glVertex2f(-0.25f,-0.17f);
    glVertex2f(-0.18f,-0.17f);
    glVertex2f(-0.18f,-0.15f);
    glEnd();

     //floor 3 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.25f,-0.18f);
    glVertex2f(-0.25f,-0.20f);
    glVertex2f(-0.18f,-0.20f);
    glVertex2f(-0.18f,-0.18f);
    glEnd();

     //floor 4 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.21f);
    glVertex2f(-0.25f,-0.23f);
    glVertex2f(-0.18f,-0.23f);
    glVertex2f(-0.18f,-0.21f);
    glEnd();

     //floor 5 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.25f,-0.24f);
    glVertex2f(-0.25f,-0.26f);
    glVertex2f(-0.18f,-0.26f);
    glVertex2f(-0.18f,-0.24f);
    glEnd();

     //floor 6 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.27f);
    glVertex2f(-0.25f,-0.29f);
    glVertex2f(-0.18f,-0.29f);
    glVertex2f(-0.18f,-0.27f);
    glEnd();

     //floor 7 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.25f,-0.30f);
    glVertex2f(-0.25f,-0.32f);
    glVertex2f(-0.18f,-0.32f);
    glVertex2f(-0.18f,-0.30f);
    glEnd();

     //floor 8 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.33f);
    glVertex2f(-0.25f,-0.35f);
    glVertex2f(-0.18f,-0.35f);
    glVertex2f(-0.18f,-0.33f);
    glEnd();

     //floor 9 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);;
    glVertex2f(-0.25f,-0.36f);
    glVertex2f(-0.25f,-0.38f);
    glVertex2f(-0.18f,-0.38f);
    glVertex2f(-0.18f,-0.36f);
    glEnd();

    //floor 10 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.39f);
    glVertex2f(-0.25f,-0.41f);
    glVertex2f(-0.18f,-0.41f);
    glVertex2f(-0.18f,-0.39f);
    glEnd();

    //floor 11 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.25f,-0.42f);
    glVertex2f(-0.25f,-0.44f);
    glVertex2f(-0.18f,-0.44f);
    glVertex2f(-0.18f,-0.42f);
    glEnd();

    //floor 12 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.45f);
    glVertex2f(-0.25f,-0.47f);
    glVertex2f(-0.18f,-0.47f);
    glVertex2f(-0.18f,-0.45f);
    glEnd();

    //floor 13 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.25f,-0.48f);
    glVertex2f(-0.25f,-0.50f);
    glVertex2f(-0.18f,-0.50f);
    glVertex2f(-0.18f,-0.48f);
    glEnd();

    //floor 14 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.51f);
    glVertex2f(-0.25f,-0.53f);
    glVertex2f(-0.18f,-0.53f);
    glVertex2f(-0.18f,-0.51f);
    glEnd();

    //floor 15 windows 1
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(-0.25f,-0.54f);
    glVertex2f(-0.25f,-0.56f);
    glVertex2f(-0.18f,-0.56f);
    glVertex2f(-0.18f,-0.54f);
    glEnd();

    //floor 16 windows 1
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-0.25f,-0.57f);
    glVertex2f(-0.25f,-0.59f);
    glVertex2f(-0.18f,-0.59f);
    glVertex2f(-0.18f,-0.57f);
    glEnd();

    glLoadIdentity();
}
//building 6
void Building6(){
    glBegin(GL_QUADS);
    glColor3ub(160,160,160);
    glVertex2f(-0.55f,0.55f);
    glVertex2f(-0.55f,-0.65f);
    glVertex2f(-0.45f,-0.65f);
    glVertex2f(-0.45f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2f(-0.45f,0.55f);
    glVertex2f(-0.45f,-0.6f);
    glVertex2f(-0.35f,-0.6f);
    glVertex2f(-0.35f, 0.5f);
    glEnd();

    //floor 1
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.53f);
    glVertex2f(-0.46f,0.53f);
    glEnd();

    //floor 2
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.50f);
    glVertex2f(-0.46f,0.50f);
    glEnd();


    //floor 3
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.47f);
    glVertex2f(-0.46f,0.47f);
    glEnd();

    //floor 4
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.44f);
    glVertex2f(-0.46f,0.44f);
    glEnd();

    //floor 5
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.41f);
    glVertex2f(-0.46f,0.41f);
    glEnd();

    //floor 6
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.38f);
    glVertex2f(-0.46f,0.38f);
    glEnd();

    //floor 7
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.35f);
    glVertex2f(-0.46f,0.35f);
    glEnd();

    //floor 8
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.32f);
    glVertex2f(-0.46f,0.32f);
    glEnd();

    //floor 9
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.26f);
    glVertex2f(-0.46f,0.26f);
    glEnd();

    //floor 10
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.23f);
    glVertex2f(-0.46f,0.23f);
    glEnd();

    //floor 11
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.20f);
    glVertex2f(-0.46f,0.20f);
    glEnd();

    //floor 12
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.17f);
    glVertex2f(-0.46f,0.17f);
    glEnd();


    //floor 13
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.14f);
    glVertex2f(-0.46f,0.14f);
    glEnd();

    //floor 14
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.11f);
    glVertex2f(-0.46f,0.11f);
    glEnd();

    //floor 15
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.08f);
    glVertex2f(-0.46f,0.08f);
    glEnd();

    //floor 16
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,0.05f);
    glVertex2f(-0.46f,0.05f);
    glEnd();

    //floor 17
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.01f);
    glVertex2f(-0.46f,-0.01f);
    glEnd();

    //floor 18
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.04f);
    glVertex2f(-0.46f,-0.04f);
    glEnd();

    //floor 19
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.07f);
    glVertex2f(-0.46f,-0.07f);
    glEnd();

    //floor 20
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.1f);
    glVertex2f(-0.46f,-0.1f);
    glEnd();

    //floor 21
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.13f);
    glVertex2f(-0.46f,-0.13f);
    glEnd();

    //floor 22
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.16f);
    glVertex2f(-0.46f,-0.16f);
    glEnd();

    //floor 23
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.19f);
    glVertex2f(-0.46f,-0.19f);
    glEnd();

    //floor 24
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.22f);
    glVertex2f(-0.46f,-0.22f);
    glEnd();

    //floor 25
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.25f);
    glVertex2f(-0.46f,-0.25f);
    glEnd();

    //floor 26
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.30f);
    glVertex2f(-0.46f,-0.30f);
    glEnd();

    //floor 27
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.33f);
    glVertex2f(-0.46f,-0.33f);
    glEnd();

    //floor 28
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.36f);
    glVertex2f(-0.46f,-0.36f);
    glEnd();

    //floor 29
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.39f);
    glVertex2f(-0.46f,-0.39f);
    glEnd();

    //floor 30
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.42f);
    glVertex2f(-0.46f,-0.42f);
    glEnd();

    //floor 31
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.45f);
    glVertex2f(-0.46f,-0.45f);
    glEnd();

    //floor 31
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.48f);
    glVertex2f(-0.46f,-0.48f);
    glEnd();

    //floor 32
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.51f);
    glVertex2f(-0.46f,-0.51f);
    glEnd();

    //floor 33
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.54f);
    glVertex2f(-0.46f,-0.54f);
    glEnd();

    //floor 34
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.54f,-0.57f);
    glVertex2f(-0.46f,-0.57f);
    glEnd();

    //right side window
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.51f);
    glVertex2f(-0.36f,0.47f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.47f);
    glVertex2f(-0.36f,0.43f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.43f);
    glVertex2f(-0.36f,0.39f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.39f);
    glVertex2f(-0.36f,0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.35f);
    glVertex2f(-0.36f,0.31f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.31f);
    glVertex2f(-0.36f,0.27f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.25f);
    glVertex2f(-0.36f,0.21f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.21f);
    glVertex2f(-0.36f,0.17f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.17f);
    glVertex2f(-0.36f,0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.13f);
    glVertex2f(-0.36f,0.09f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.09f);
    glVertex2f(-0.36f,0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.36f,0.01f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.01f);
    glVertex2f(-0.36f,-0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.36f,-0.09f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.09f);
    glVertex2f(-0.36f,-0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.13f);
    glVertex2f(-0.36f,-0.17f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.17f);
    glVertex2f(-0.36f,-0.21f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.21f);
    glVertex2f(-0.36f,-0.25f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.25f);
    glVertex2f(-0.36f,-0.29f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.29f);
    glVertex2f(-0.36f,-0.33f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.33f);
    glVertex2f(-0.36f,-0.37f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.37f);
    glVertex2f(-0.36f,-0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.41f);
    glVertex2f(-0.36f,-0.45f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.45f);
    glVertex2f(-0.36f,-0.49f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.49f);
    glVertex2f(-0.36f,-0.53f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.6f,0.8f);
    glVertex2f(-0.44f,-0.53f);
    glVertex2f(-0.36f,-0.57f);
    glEnd();


    glLoadIdentity();
}

//building 6 night
void Building6Night(){
    glBegin(GL_QUADS);
    glColor3ub(160,160,160);
    glVertex2f(-0.55f,0.55f);
    glVertex2f(-0.55f,-0.65f);
    glVertex2f(-0.45f,-0.65f);
    glVertex2f(-0.45f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2f(-0.45f,0.55f);
    glVertex2f(-0.45f,-0.6f);
    glVertex2f(-0.35f,-0.6f);
    glVertex2f(-0.35f, 0.5f);
    glEnd();

    //floor 1
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.53f);
    glVertex2f(-0.46f,0.53f);
    glEnd();

    //floor 2
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.50f);
    glVertex2f(-0.46f,0.50f);
    glEnd();


    //floor 3
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.47f);
    glVertex2f(-0.46f,0.47f);
    glEnd();

    //floor 4
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.44f);
    glVertex2f(-0.46f,0.44f);
    glEnd();

    //floor 5
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.41f);
    glVertex2f(-0.46f,0.41f);
    glEnd();

    //floor 6
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.38f);
    glVertex2f(-0.46f,0.38f);
    glEnd();

    //floor 7
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.35f);
    glVertex2f(-0.46f,0.35f);
    glEnd();

    //floor 8
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.32f);
    glVertex2f(-0.46f,0.32f);
    glEnd();

    //floor 9
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.26f);
    glVertex2f(-0.46f,0.26f);
    glEnd();

    //floor 10
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.23f);
    glVertex2f(-0.46f,0.23f);
    glEnd();

    //floor 11
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.20f);
    glVertex2f(-0.46f,0.20f);
    glEnd();

    //floor 12
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.17f);
    glVertex2f(-0.46f,0.17f);
    glEnd();


    //floor 13
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.14f);
    glVertex2f(-0.46f,0.14f);
    glEnd();

    //floor 14
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.11f);
    glVertex2f(-0.46f,0.11f);
    glEnd();

    //floor 15
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.08f);
    glVertex2f(-0.46f,0.08f);
    glEnd();

    //floor 16
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,0.05f);
    glVertex2f(-0.46f,0.05f);
    glEnd();

    //floor 17
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.01f);
    glVertex2f(-0.46f,-0.01f);
    glEnd();

    //floor 18
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.04f);
    glVertex2f(-0.46f,-0.04f);
    glEnd();

    //floor 19
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.07f);
    glVertex2f(-0.46f,-0.07f);
    glEnd();

    //floor 20
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.1f);
    glVertex2f(-0.46f,-0.1f);
    glEnd();

    //floor 21
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.13f);
    glVertex2f(-0.46f,-0.13f);
    glEnd();

    //floor 22
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.16f);
    glVertex2f(-0.46f,-0.16f);
    glEnd();

    //floor 23
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.19f);
    glVertex2f(-0.46f,-0.19f);
    glEnd();

    //floor 24
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.22f);
    glVertex2f(-0.46f,-0.22f);
    glEnd();

    //floor 25
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.25f);
    glVertex2f(-0.46f,-0.25f);
    glEnd();

    //floor 26
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.30f);
    glVertex2f(-0.46f,-0.30f);
    glEnd();

    //floor 27
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.33f);
    glVertex2f(-0.46f,-0.33f);
    glEnd();

    //floor 28
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.36f);
    glVertex2f(-0.46f,-0.36f);
    glEnd();

    //floor 29
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.39f);
    glVertex2f(-0.46f,-0.39f);
    glEnd();

    //floor 30
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.42f);
    glVertex2f(-0.46f,-0.42f);
    glEnd();

    //floor 31
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.45f);
    glVertex2f(-0.46f,-0.45f);
    glEnd();

    //floor 31
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.48f);
    glVertex2f(-0.46f,-0.48f);
    glEnd();

    //floor 32
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.51f);
    glVertex2f(-0.46f,-0.51f);
    glEnd();

    //floor 33
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.54f);
    glVertex2f(-0.46f,-0.54f);
    glEnd();

    //floor 34
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.54f,-0.57f);
    glVertex2f(-0.46f,-0.57f);
    glEnd();

    //right side window
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.51f);
    glVertex2f(-0.36f,0.47f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.47f);
    glVertex2f(-0.36f,0.43f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.43f);
    glVertex2f(-0.36f,0.39f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.39f);
    glVertex2f(-0.36f,0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.35f);
    glVertex2f(-0.36f,0.31f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.31f);
    glVertex2f(-0.36f,0.27f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.25f);
    glVertex2f(-0.36f,0.21f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.21f);
    glVertex2f(-0.36f,0.17f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.17f);
    glVertex2f(-0.36f,0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.13f);
    glVertex2f(-0.36f,0.09f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.09f);
    glVertex2f(-0.36f,0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.36f,0.01f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.01f);
    glVertex2f(-0.36f,-0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.36f,-0.09f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.09f);
    glVertex2f(-0.36f,-0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.13f);
    glVertex2f(-0.36f,-0.17f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.17f);
    glVertex2f(-0.36f,-0.21f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.21f);
    glVertex2f(-0.36f,-0.25f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.25f);
    glVertex2f(-0.36f,-0.29f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.29f);
    glVertex2f(-0.36f,-0.33f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.33f);
    glVertex2f(-0.36f,-0.37f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);;
    glVertex2f(-0.44f,-0.37f);
    glVertex2f(-0.36f,-0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.41f);
    glVertex2f(-0.36f,-0.45f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.45f);
    glVertex2f(-0.36f,-0.49f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.49f);
    glVertex2f(-0.36f,-0.53f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f,-0.53f);
    glVertex2f(-0.36f,-0.57f);
    glEnd();


    glLoadIdentity();
}

//building 7
void Building7(){
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2f(-1.0f,0.9f);
    glVertex2f(-1.0f,-0.6f);
    glVertex2f(-0.9f,-0.6f);
    glVertex2f(-0.9f,0.9f);
    glEnd();

    //window 1
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.88f);
    glVertex2f(-0.99f,0.86f);
    glVertex2f(-0.91f,0.86f);
    glVertex2f(-0.91f,0.88f);
    glEnd();

    //window 2
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.84f);
    glVertex2f(-0.99f,0.82f);
    glVertex2f(-0.91f,0.82f);
    glVertex2f(-0.91f,0.84f);
    glEnd();

    //window 3
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.80f);
    glVertex2f(-0.99f,0.78f);
    glVertex2f(-0.91f,0.78f);
    glVertex2f(-0.91f,0.80f);
    glEnd();

    //window 4
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.76f);
    glVertex2f(-0.99f,0.74f);
    glVertex2f(-0.91f,0.74f);
    glVertex2f(-0.91f,0.76f);
    glEnd();

    //window 5
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.72f);
    glVertex2f(-0.99f,0.70f);
    glVertex2f(-0.91f,0.70f);
    glVertex2f(-0.91f,0.72f);
    glEnd();

    //window 6
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.68f);
    glVertex2f(-0.99f,0.66f);
    glVertex2f(-0.91f,0.66f);
    glVertex2f(-0.91f,0.68f);
    glEnd();

    //window 7
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.64f);
    glVertex2f(-0.99f,0.62f);
    glVertex2f(-0.91f,0.62f);
    glVertex2f(-0.91f,0.64f);
    glEnd();

    //window 8
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.60f);
    glVertex2f(-0.99f,0.58f);
    glVertex2f(-0.91f,0.58f);
    glVertex2f(-0.91f,0.60f);
    glEnd();

    //window 9
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.56f);
    glVertex2f(-0.99f,0.54f);
    glVertex2f(-0.91f,0.54f);
    glVertex2f(-0.91f,0.56f);
    glEnd();

    //window 10
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.52f);
    glVertex2f(-0.99f,0.50f);
    glVertex2f(-0.91f,0.50f);
    glVertex2f(-0.91f,0.52f);
    glEnd();

    //window 11
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.48f);
    glVertex2f(-0.99f,0.46f);
    glVertex2f(-0.91f,0.46f);
    glVertex2f(-0.91f,0.48f);
    glEnd();

    //window 12
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.44f);
    glVertex2f(-0.99f,0.42f);
    glVertex2f(-0.91f,0.42f);
    glVertex2f(-0.91f,0.44f);
    glEnd();

    //window 13
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.40f);
    glVertex2f(-0.99f,0.38f);
    glVertex2f(-0.91f,0.38f);
    glVertex2f(-0.91f,0.40f);
    glEnd();

    //window 14
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.36f);
    glVertex2f(-0.99f,0.34f);
    glVertex2f(-0.91f,0.34f);
    glVertex2f(-0.91f,0.36f);
    glEnd();

    //window 15
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.32f);
    glVertex2f(-0.99f,0.30f);
    glVertex2f(-0.91f,0.30f);
    glVertex2f(-0.91f,0.32f);
    glEnd();

    //window 16
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.28f);
    glVertex2f(-0.99f,0.26f);
    glVertex2f(-0.91f,0.26f);
    glVertex2f(-0.91f,0.28f);
    glEnd();

    //window 17
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.24f);
    glVertex2f(-0.99f,0.22f);
    glVertex2f(-0.91f,0.22f);
    glVertex2f(-0.91f,0.24f);
    glEnd();

    //window 18
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.20f);
    glVertex2f(-0.99f,0.18f);
    glVertex2f(-0.91f,0.18f);
    glVertex2f(-0.91f,0.20f);
    glEnd();

    //window 19
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.16f);
    glVertex2f(-0.99f,0.14f);
    glVertex2f(-0.91f,0.14f);
    glVertex2f(-0.91f,0.16f);
    glEnd();

    //window 20
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.12f);
    glVertex2f(-0.99f,0.10f);
    glVertex2f(-0.91f,0.10f);
    glVertex2f(-0.91f,0.12f);
    glEnd();

    //window 21
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.08f);
    glVertex2f(-0.99f,0.06f);
    glVertex2f(-0.91f,0.06f);
    glVertex2f(-0.91f,0.08f);
    glEnd();

    //window 22
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.99f,0.04f);
    glVertex2f(-0.99f,0.02f);
    glVertex2f(-0.91f,0.02f);
    glVertex2f(-0.91f,0.04f);
    glEnd();
}

//building 8
void Building8(){
    glBegin(GL_QUADS);
    glColor3ub(160,160,160);
    glVertex2f(-0.9f,0.7f);
    glVertex2f(-0.9f,-0.6f);
    glVertex2f(-0.8f,-0.6f);
    glVertex2f(-0.8f,0.7f);
    glEnd();

    //window 1
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.68f);
    glVertex2f(-0.89f,0.66f);
    glVertex2f(-0.81f,0.66f);
    glVertex2f(-0.81f,0.68f);
    glEnd();

    //window 2
  glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.64f);
    glVertex2f(-0.89f,0.62f);
    glVertex2f(-0.81f,0.62f);
    glVertex2f(-0.81f,0.64f);
    glEnd();

    //window 3
  glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.60f);
    glVertex2f(-0.89f,0.58f);
    glVertex2f(-0.81f,0.58f);
    glVertex2f(-0.81f,0.60f);
    glEnd();

    //window 4
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.56f);
    glVertex2f(-0.89f,0.54f);
    glVertex2f(-0.81f,0.54f);
    glVertex2f(-0.81f,0.56f);
    glEnd();

    //window 5
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.52f);
    glVertex2f(-0.89f,0.50f);
    glVertex2f(-0.81f,0.50f);
    glVertex2f(-0.81f,0.52f);
    glEnd();

    //window 6
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.48f);
    glVertex2f(-0.89f,0.46f);
    glVertex2f(-0.81f,0.46f);
    glVertex2f(-0.81f,0.48f);
    glEnd();

    //window 7
  glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.44f);
    glVertex2f(-0.89f,0.42f);
    glVertex2f(-0.81f,0.42f);
    glVertex2f(-0.81f,0.44f);
    glEnd();

    //window 8
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.40f);
    glVertex2f(-0.89f,0.38f);
    glVertex2f(-0.81f,0.38f);
    glVertex2f(-0.81f,0.40f);
    glEnd();

    //window 9
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.36f);
    glVertex2f(-0.89f,0.34f);
    glVertex2f(-0.81f,0.34f);
    glVertex2f(-0.81f,0.36f);
    glEnd();

    //window 10
 glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.32f);
    glVertex2f(-0.89f,0.30f);
    glVertex2f(-0.81f,0.30f);
    glVertex2f(-0.81f,0.32f);
    glEnd();

    //window 11
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.28f);
    glVertex2f(-0.89f,0.26f);
    glVertex2f(-0.81f,0.26f);
    glVertex2f(-0.81f,0.28f);
    glEnd();

    //window 12
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.24f);
    glVertex2f(-0.89f,0.22f);
    glVertex2f(-0.81f,0.22f);
    glVertex2f(-0.81f,0.24f);
    glEnd();

    //window 13
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.20f);
    glVertex2f(-0.89f,0.18f);
    glVertex2f(-0.81f,0.18f);
    glVertex2f(-0.81f,0.20f);
    glEnd();

    //window 14
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.16f);
    glVertex2f(-0.89f,0.14f);
    glVertex2f(-0.81f,0.14f);
    glVertex2f(-0.81f,0.16f);
    glEnd();

    //window 15
 glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.12f);
    glVertex2f(-0.89f,0.10f);
    glVertex2f(-0.81f,0.10f);
    glVertex2f(-0.81f,0.12f);
    glEnd();

    //window 16
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.08f);
    glVertex2f(-0.89f,0.06f);
    glVertex2f(-0.81f,0.06f);
    glVertex2f(-0.81f,0.08f);
    glEnd();

    //window 17
   glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.89f,0.04f);
    glVertex2f(-0.89f,0.02f);
    glVertex2f(-0.81f,0.02f);
    glVertex2f(-0.81f,0.04f);
    glEnd();
}
void Bridge(){
    //bridge for train
    //part 01
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2f(-1.0f,-0.2f);
    glVertex2f(-1.0f,-0.25f);
    glVertex2f(1.0f,-0.25f);
    glVertex2f(1.0f,-0.2f);
    glEnd();


    //bridge border
    glBegin(GL_QUADS);
    glColor3ub(102,51,0);
    glVertex2f(-1.0f,-0.25f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(1.0f,-0.26f);
    glVertex2f(1.0f,-0.25f);
    glEnd();

    //part 02
    glBegin(GL_QUADS);
    glColor3ub(32,32,32);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0f,-0.34f);
    glVertex2f(1.0f,-0.34f);
    glVertex2f(1.0f,-0.26f);
    glEnd();

    //bridge upper bases
    //upper base 1
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-1.0f,-0.34f);
    glVertex2f(-0.9f,-0.26f);
    glEnd();

    //upper base 2
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.9f,-0.26f);
    glVertex2f(-0.8f,-0.34f);
    glEnd();

    //upper base 3
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.8f,-0.34f);
    glVertex2f(-0.7f,-0.26f);
    glEnd();

    //upper base 4
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.7f,-0.26f);
    glVertex2f(-0.6f,-0.34f);
    glEnd();

    //upper base 5
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.6f,-0.34f);
    glVertex2f(-0.5f,-0.26f);
    glEnd();

    //upper base 6
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.5f,-0.26f);
    glVertex2f(-0.4f,-0.34f);
    glEnd();

    //upper base 7
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.4f,-0.34f);
    glVertex2f(-0.3f,-0.26f);
    glEnd();

    //upper base 8
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.3f,-0.26f);
    glVertex2f(-0.2f,-0.34f);
    glEnd();

    //upper base 9
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.2f,-0.34f);
    glVertex2f(-0.1f,-0.26f);
    glEnd();

    //upper base 10
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.1f,-0.26f);
    glVertex2f(-0.0f,-0.34f);
    glEnd();

    //upper base 11
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.0f,-0.34f);
    glVertex2f(0.1f,-0.26f);
    glEnd();

    //upper base 12
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.1f,-0.26f);
    glVertex2f(0.2f,-0.34f);
    glEnd();

    //upper base 13
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.2f,-0.34f);
    glVertex2f(0.3f,-0.26f);
    glEnd();

    //upper base 14
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.3f,-0.26f);
    glVertex2f(0.4f,-0.34f);
    glEnd();

    //upper base 15
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.4f,-0.34f);
    glVertex2f(0.5f,-0.26f);
    glEnd();

    //upper base 16
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.5f,-0.26f);
    glVertex2f(0.6f,-0.34f);
    glEnd();

    //upper base 17
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.6f,-0.34f);
    glVertex2f(0.7f,-0.26f);
    glEnd();

    //upper base 18
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.7f,-0.26f);
    glVertex2f(0.8f,-0.34f);
    glEnd();

    //upper base 19
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.8f,-0.34f);
    glVertex2f(0.9f,-0.26f);
    glEnd();

    //upper base 20
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.9f,-0.26f);
    glVertex2f(1.0f,-0.34f);
    glEnd();


    //dividers
    //divider 01
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.9f,-0.34f);
    glVertex2f(-0.9f,-0.26f);
    glEnd();

    //divider 02
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.8f,-0.34f);
    glVertex2f(-0.8f,-0.26f);
    glEnd();

    //divider 03
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.7f,-0.34f);
    glVertex2f(-0.7f,-0.26f);
    glEnd();

    //divider 04
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.6f,-0.34f);
    glVertex2f(-0.6f,-0.26f);
    glEnd();

    //divider 05
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.5f,-0.34f);
    glVertex2f(-0.5f,-0.26f);
    glEnd();

    //divider 06
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.4f,-0.34f);
    glVertex2f(-0.4f,-0.26f);
    glEnd();

    //divider 07
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.3f,-0.34f);
    glVertex2f(-0.3f,-0.26f);
    glEnd();

    //divider 08
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.2f,-0.34f);
    glVertex2f(-0.2f,-0.26f);
    glEnd();

    //divider 09
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.1f,-0.34f);
    glVertex2f(-0.1f,-0.26f);
    glEnd();

    //divider 10
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(-0.0f,-0.34f);
    glVertex2f(-0.0f,-0.26f);
    glEnd();

    //divider 11
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.1f,-0.34f);
    glVertex2f(0.1f,-0.26f);
    glEnd();

    //divider 12
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.2f,-0.34f);
    glVertex2f(0.2f,-0.26f);
    glEnd();

    //divider 13
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.3f,-0.34f);
    glVertex2f(0.3f,-0.26f);
    glEnd();

    //divider 14
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.4f,-0.34f);
    glVertex2f(0.4f,-0.26f);
    glEnd();

    //divider 15
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.5f,-0.34f);
    glVertex2f(0.5f,-0.26f);
    glEnd();

    //divider 16
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.6f,-0.34f);
    glVertex2f(0.6f,-0.26f);
    glEnd();

    //divider 17
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.7f,-0.34f);
    glVertex2f(0.7f,-0.26f);
    glEnd();

    //divider 18
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.8f,-0.34f);
    glVertex2f(0.8f,-0.26f);
    glEnd();

    //divider 19
    glBegin(GL_LINES);
    glColor3ub(224,224,224);
    glVertex2f(0.9f,-0.34f);
    glVertex2f(0.9f,-0.26f);
    glEnd();

   //extra lines 01
    glBegin(GL_LINES);
    glColor3ub(224,204,153);
    glVertex2f(-1.0f,-0.34f);
    glVertex2f(1.0f,-0.34f);
    glEnd();

    //extra lines 02
    glBegin(GL_LINES);
    glColor3ub(160,160,160);
    glVertex2f(-1.0f,-0.27f);
    glVertex2f(1.0f,-0.27f);
    glEnd();

    //train stands 01
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.1f, -0.25f);
    glVertex2f(0.1f, -0.15f);
    glEnd();

    //train stands 02

    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.2f, -0.25f);
    glVertex2f(0.2f, -0.05f);
    glEnd();

    //train stands 03
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.3f, -0.25f);
    glVertex2f(0.3f, 0.05f);
    glEnd();

    //train stands 04
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.4f, -0.25f);
    glVertex2f(0.4f, 0.15f);
    glEnd();

     //train stands 05
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.5f, -0.25f);
    glVertex2f(0.5f, 0.25f);
    glEnd();

     //train stands 06
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.6f, -0.25f);
    glVertex2f(0.6f, 0.35f);
    glEnd();

    //train stands 07
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.7f, -0.25f);
    glVertex2f(0.7f, 0.25f);
    glEnd();

    //train stands 08
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.8f, -0.25f);
    glVertex2f(0.8f, 0.15f);
    glEnd();


    //train stands 09
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.9f, -0.25f);
    glVertex2f(0.9f, 0.05f);
    glEnd();

    //train stands 11
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.0f, -0.25f);
    glVertex2f(0.0f, -0.05f);
    glEnd();

    //train stands 12
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.1f, -0.25f);
    glVertex2f(-0.1f, 0.05f);
    glEnd();

    //train stands 13
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.2f, -0.25f);
    glVertex2f(-0.2f, 0.15f);
    glEnd();

    //train stands 14
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.3f, 0.25f);
    glEnd();

    //train stands 15
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.4f, 0.35f);
    glEnd();

    //train stands 16
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.5f, -0.25f);
    glVertex2f(-0.5f, 0.25f);
    glEnd();

    //train stands 17
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.6f, -0.25f);
    glVertex2f(-0.6f, 0.15f);
    glEnd();

    //train stands 18
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.7f, -0.25f);
    glVertex2f(-0.7f, 0.05f);
    glEnd();

    //train stands 19
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.8f, -0.25f);
    glVertex2f(-0.8f, -0.05f);
    glEnd();

    //train stands 20
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-0.9f, -0.25f);
    glVertex2f(-0.9f, 0.05f);
    glEnd();


    //train extra holders with stands
    //holder 01
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.58f, 0.33f);
    glVertex2f(0.58f, -0.6f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.62f, 0.33f);
    glVertex2f(0.62f, -0.6f);
    glEnd();


    //holder 02
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.08f, -0.6f);
    glVertex2f(0.08f, -0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.12f, -0.6f);
    glVertex2f(0.12f, -0.13f);
    glEnd();

    //base 01
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2f(0.56f, -0.34f);
    glColor3ub(160,160,160);
    glVertex2f(0.56f, -0.54f);
    glVertex2f(0.64f, -0.54f);
    glVertex2f(0.64f, -0.34f);
    glEnd();

    //base 02
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2f(0.06f, -0.34f);
    glColor3ub(160,160,160);
    glVertex2f(0.06f, -0.54f);
    glVertex2f(0.14f, -0.54f);
    glVertex2f(0.14f, -0.34f);
    glEnd();



    glLoadIdentity();
}

//train
void Train(){
    glPushMatrix();
    glTranslatef(positionTrain,0.0f,0.0f);
    glScalef(0.55,1.0,0);
    //1st bogie
    glBegin(GL_QUADS);
    glColor3ub	(255,250,240);
    glVertex2f(0.49f,-0.16f);
    glVertex2f(0.4f,-0.25f);
    glVertex2f(0.8f,-0.25f);
    glVertex2f(0.8f,-0.16f);
    glEnd();

    //Border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.49f,-0.16f);
    glVertex2f(0.4f,-0.25f);
    glVertex2f(0.4f,-0.25f);
    glVertex2f(0.8f,-0.25f);
    glVertex2f(0.8f,-0.25f);
    glVertex2f(0.8f,-0.16f);
    glVertex2f(0.49f,-0.16f);
    glVertex2f(0.8f,-0.16f);
    glEnd();

    //2nd bogie

    glBegin(GL_QUADS);
    glColor3ub	(255,250,240);
    glVertex2f(0.81f,-0.16f);
    glVertex2f(0.81f,-0.25f);
    glVertex2f(1.11f,-0.25f);
    glVertex2f(1.11f,-0.16f);
    glEnd();

    //Border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.81f,-0.16f);
    glVertex2f(0.81f,-0.25f);

    glVertex2f(0.81f,-0.25f);
    glVertex2f(1.11f,-0.25f);

    glVertex2f(1.11f,-0.25f);
    glVertex2f(1.11f,-0.16f);

    glVertex2f(0.81f,-0.16f);
    glVertex2f(1.11f,-0.16f);
    glEnd();

    //3rd bogie
    glBegin(GL_QUADS);
    glColor3ub	(255,250,240);
    glVertex2f(1.12f,-0.16f);
    glVertex2f(1.12f,-0.25f);
    glVertex2f(1.42f,-0.25f);
    glVertex2f(1.42f,-0.16f);
    glEnd();

    //Border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(1.12f,-0.16f);
    glVertex2f(1.12f,-0.25f);

    glVertex2f(1.12f,-0.25f);
    glVertex2f(1.42f,-0.25f);

    glVertex2f(1.42f,-0.25f);
    glVertex2f(1.42f,-0.16f);

    glVertex2f(1.12f,-0.16f);
    glVertex2f(1.42f,-0.16f);
    glEnd();

    //Under-Line
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.42f,-0.23f);
    glVertex2f(1.42f,-0.23f);
    glEnd();


    //Upper-Line
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub	(176,196,222);
    glVertex2f(0.475f,-0.175f);
    glVertex2f(0.8f,-0.175f);

    glVertex2f(0.81f,-0.175f);
    glVertex2f(1.11f,-0.175f);

    glVertex2f(1.12f,-0.175f);
    glVertex2f(1.42f,-0.175f);
    glEnd();

    //1st bogie door

    glBegin(GL_QUADS);
    glColor3ub	(176,196,222);
    glVertex2f(0.52f,-0.185f);
    glVertex2f(0.52f,-0.245f);
    glVertex2f(0.55f,-0.245f);
    glVertex2f(0.55f,-0.185f);
    glEnd();
    //border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(25,25,112);
    glVertex2f(0.52f,-0.185f);
    glVertex2f(0.52f,-0.245f);

    glVertex2f(0.55f,-0.245f);
    glVertex2f(0.55f,-0.185f);

    glVertex2f(0.52f,-0.245f);
    glVertex2f(0.55f,-0.245f);

    glVertex2f(0.52f,-0.185f);
    glVertex2f(0.55f,-0.185f);


    glEnd();


    //2nd bogie door

    //1st
    glBegin(GL_QUADS);
    glColor3ub	(176,196,222);
    glVertex2f(0.83f,-0.185f);
    glVertex2f(0.83f,-0.245f);
    glVertex2f(0.86f,-0.245f);
    glVertex2f(0.86f,-0.185f);
    glEnd();

    //border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(25,25,112);
    glVertex2f(0.83f,-0.185f);
    glVertex2f(0.83f,-0.245f);

    glVertex2f(0.86f,-0.245f);
    glVertex2f(0.86f,-0.185f);

    glVertex2f(0.83f,-0.245f);
    glVertex2f(0.86f,-0.245f);

    glVertex2f(0.83f,-0.185f);
    glVertex2f(0.86f,-0.185f);
    glEnd();


    //2nd

    glBegin(GL_QUADS);
    glColor3ub	(176,196,222);
    glVertex2f(1.06f,-0.185f);
    glVertex2f(1.06f,-0.245f);
    glVertex2f(1.09f,-0.245f);
    glVertex2f(1.09f,-0.185f);
    glEnd();

    //border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(25,25,112);
    glVertex2f(1.06f,-0.185f);
    glVertex2f(1.06f,-0.245f);

    glVertex2f(1.09f,-0.245f);
    glVertex2f(1.09f,-0.185f);

    glVertex2f(1.06f,-0.245f);
    glVertex2f(1.09f,-0.245f);

    glVertex2f(1.06f,-0.185f);
    glVertex2f(1.09f,-0.185f);
    glEnd();

    //3rd bogie door
    //1
    glBegin(GL_QUADS);
    glColor3ub	(176,196,222);
    glVertex2f(1.14f,-0.185f);
    glVertex2f(1.14f,-0.245f);
    glVertex2f(1.17f,-0.245f);
    glVertex2f(1.17f,-0.185f);
    glEnd();

    //border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(25,25,112);
    glVertex2f(1.14f,-0.185f);
    glVertex2f(1.14f,-0.245f);

    glVertex2f(1.17f,-0.245f);
    glVertex2f(1.17f,-0.185f);

    glVertex2f(1.14f,-0.245f);
    glVertex2f(1.17f,-0.245f);

    glVertex2f(1.14f,-0.185f);
    glVertex2f(1.17f,-0.185f);
    glEnd();


    //2
    glBegin(GL_QUADS);
    glColor3ub	(176,196,222);
    glVertex2f(1.4f,-0.185f);
    glVertex2f(1.4f,-0.245f);
    glVertex2f(1.37f,-0.245f);
    glVertex2f(1.37f,-0.185f);
    glEnd();

    //border

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(25,25,112);
    glVertex2f(1.4f,-0.185f);
    glVertex2f(1.4f,-0.245f);

    glVertex2f(1.37f,-0.245f);
    glVertex2f(1.37f,-0.185f);

    glVertex2f(1.4f,-0.245f);
    glVertex2f(1.37f,-0.245f);

    glVertex2f(1.4f,-0.185f);
    glVertex2f(1.37f,-0.185f);
    glEnd();

    //Train windows

    //1st bogey
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,128);
    glVertex2f(0.468f, -0.178f);
    glVertex2f(0.438f, -0.213f);
    glVertex2f(0.468f, -0.213f);
    glEnd();


    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.496f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.57f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.61f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.65f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.69f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.73f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.77f, -0.2f);
    glEnd();
    //2nd bogey windows
    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.88f, -0.2f);
    glEnd();

     glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.92f, -0.2f);
    glEnd();

     glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(0.96f, -0.2f);
    glEnd();


    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(1.0f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(1.04f, -0.2f);
    glEnd();

    //3rd bogey
    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(1.19f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(1.23f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(1.27f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(1.31f, -0.2f);
    glEnd();

    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3ub(0,128,128);
    glVertex2f(1.35f, -0.2f);
    glEnd();











    glPopMatrix();

    glLoadIdentity();
}

//train upper stands
void TrainUpperStands(){

   //bridge upper connectors 01 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.1f, -0.15f);
    glVertex2f(0.15f, -0.11f);
    glEnd();

    //bridge upper connectors 01 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.15f, -0.11f);
    glVertex2f(0.2f, -0.05f);
    glEnd();

    //bridge upper connectors 02 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.25f, -0.01f);
    glEnd();

    //bridge upper connectors 02 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.01f);
    glVertex2f(0.3f, 0.05f);
    glEnd();


    //bridge upper connectors 03 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.3f, 0.05f);
    glVertex2f(0.35f, 0.09f);
    glEnd();

    //bridge upper connectors 03 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.09f);
    glVertex2f(0.4f, 0.15f);
    glEnd();

    //bridge upper connectors 04 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.4f, 0.15f);
    glVertex2f(0.45f, 0.19f);
    glEnd();

    //bridge upper connectors 04 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.45f, 0.19f);
    glVertex2f(0.5f, 0.25f);
    glEnd();

    //bridge upper connectors 05 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.5f, 0.25f);
    glVertex2f(0.55f, 0.29f);
    glEnd();

    //bridge upper connectors 05 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.55f, 0.29f);
    glVertex2f(0.6f, 0.35f);
    glEnd();

    //bridge upper connectors 06 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.65f, 0.29f);
    glEnd();

    //bridge upper connectors 06 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.65f, 0.29f);
    glVertex2f(0.7f, 0.25f);
    glEnd();

    //bridge upper connectors 07 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.7f, 0.25f);
    glVertex2f(0.75f, 0.19f);
    glEnd();

    //bridge upper connectors 07 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.75f, 0.19f);
    glVertex2f(0.8f, 0.15f);
    glEnd();

    //bridge upper connectors 08 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.8f, 0.15f);
    glVertex2f(0.85f, 0.09f);
    glEnd();

    //bridge upper connectors 08 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.85f, 0.09f);
    glVertex2f(0.9f, 0.05f);
    glEnd();

    //bridge upper connectors 09 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.9f, 0.05f);
    glVertex2f(0.95f, -0.01f);
    glEnd();

    //bridge upper connectors 09 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.95f, -0.01f);
    glVertex2f(1.0f, -0.05f);
    glEnd();

    //bridge upper connectors -0.1 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.1f, -0.15f);
    glVertex2f(0.05f, -0.11f);
    glEnd();

    //bridge upper connectors -0.1 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.05f, -0.11f);
    glVertex2f(0.0f, -0.05f);
    glEnd();

    //bridge upper connectors -0.2 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0f, -0.05f);
    glVertex2f(-0.05f, -0.01f);
    glEnd();

    //bridge upper connectors -0.2 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.05f, -0.01f);
    glVertex2f(-0.1f, 0.05f);
    glEnd();

    //bridge upper connectors -0.3 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.1f, 0.05f);
    glVertex2f(-0.15f, 0.09f);
    glEnd();

    //bridge upper connectors -0.3 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.15f, 0.09f);
    glVertex2f(-0.2f, 0.15f);
    glEnd();

    //bridge upper connectors -0.3 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.2f, 0.15f);
    glVertex2f(-0.25f, 0.19f);
    glEnd();

    //bridge upper connectors -0.3 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.25f, 0.19f);
    glVertex2f(-0.3f, 0.25f);
    glEnd();

    //bridge upper connectors -0.4 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.3f, 0.25f);
    glVertex2f(-0.35f, 0.29f);
    glEnd();

    //bridge upper connectors -0.4 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.35f, 0.29f);
    glVertex2f(-0.4f, 0.35f);
    glEnd();

    //bridge upper connectors -0.5 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.4f, 0.35f);
    glVertex2f(-0.45f, 0.29f);
    glEnd();

    //bridge upper connectors -0.5 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.45f, 0.29f);
    glVertex2f(-0.5f, 0.25f);
    glEnd();

    //bridge upper connectors -0.5 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.5f, 0.25f);
    glVertex2f(-0.55f, 0.19f);
    glEnd();

    //bridge upper connectors -0.5 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.55f, 0.19f);
    glVertex2f(-0.6f, 0.15f);
    glEnd();


    //bridge upper connectors -0.5 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.6f, 0.15f);
    glVertex2f(-0.65f, 0.09f);
    glEnd();

    //bridge upper connectors -0.5 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.65f, 0.09f);
    glVertex2f(-0.7f, 0.05f);
    glEnd();

    //bridge upper connectors -0.5 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.7f, 0.05f);
    glVertex2f(-0.75f, -0.01f);
    glEnd();

    //bridge upper connectors -0.5 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.75f, -0.01f);
    glVertex2f(-0.8f, -0.05f);
    glEnd();

    //bridge upper connectors -0.5 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.8f, -0.05f);
    glVertex2f(-0.85f, -0.11f);
    glEnd();

    //bridge upper connectors -0.5 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.11f);
    glVertex2f(-0.9f, -0.15f);
    glEnd();

    //bridge upper connectors -0.5 half 01
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.9f, -0.15f);
    glVertex2f(-0.95f, -0.11f);
    glEnd();

    //bridge upper connectors -0.5 half 02
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.11f);
    glVertex2f(-1.0f, -0.05f);
    glEnd();

    glLoadIdentity();
}
//road
void Road(){
//road1
    glBegin(GL_QUADS);
    glColor3f(0.3f,0.3f,0.3f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -0.6f);
    glEnd();

    //road2
    glBegin(GL_QUADS);
    glColor3f(0.4f,0.4f,0.4f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.8f);
    glEnd();

    //road strips
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0f, -0.79f);
    glVertex2f(-1.0f, -0.81f);
    glVertex2f(-0.9f, -0.81f);
    glVertex2f(-0.9f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.8f, -0.79f);
    glVertex2f(-0.8f, -0.81f);
    glVertex2f(-0.7f, -0.81f);
    glVertex2f(-0.7f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.6f, -0.79f);
    glVertex2f(-0.6f, -0.81f);
    glVertex2f(-0.5f, -0.81f);
    glVertex2f(-0.5f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.4f, -0.79f);
    glVertex2f(-0.4f, -0.81f);
    glVertex2f(-0.3f, -0.81f);
    glVertex2f(-0.3f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.2f, -0.79f);
    glVertex2f(-0.2f, -0.81f);
    glVertex2f(-0.1f, -0.81f);
    glVertex2f(-0.1f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.0f, -0.79f);
    glVertex2f(0.0f, -0.81f);
    glVertex2f(0.1f, -0.81f);
    glVertex2f(0.1f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.2f, -0.79f);
    glVertex2f(0.2f, -0.81f);
    glVertex2f(0.3f, -0.81f);
    glVertex2f(0.3f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.4f, -0.79f);
    glVertex2f(0.4f, -0.81f);
    glVertex2f(0.5f, -0.81f);
    glVertex2f(0.5f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.6f, -0.79f);
    glVertex2f(0.6f, -0.81f);
    glVertex2f(0.7f, -0.81f);
    glVertex2f(0.7f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.8f, -0.79f);
    glVertex2f(0.8f, -0.81f);
    glVertex2f(0.9f, -0.81f);
    glVertex2f(0.9f, -0.79f);
    glEnd();

    //road border
    //road border 01
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-1.0f, -0.5f);
    glColor3ub(0,102,102);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-0.8f, -0.6f);
    glVertex2f(-0.8f, -0.5f);
    glEnd();

    //road border 02
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-0.7f, -0.5f);
    glColor3ub(0,102,102);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();

    //road border 03
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-0.3f, -0.5f);
    glColor3ub(0,102,102);
    glVertex2f(-0.3f, -0.6f);
    glVertex2f(-0.1f, -0.6f);
    glVertex2f(-0.1f, -0.5f);
    glEnd();

    //road border 04
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(0.1f, -0.5f);
    glColor3ub(0,102,102);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.3f, -0.6f);
    glVertex2f(0.3f, -0.5f);
    glEnd();

    //road border 05
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(0.5f, -0.5f);
    glColor3ub(0,102,102);
    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.7f, -0.5f);
    glEnd();

        //road border 05
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(0.9f, -0.5f);
    glColor3ub(0,102,102);
    glVertex2f(0.9f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -0.5f);
    glEnd();
    glLoadIdentity();
}

//Bus
void Bus(){
glPushMatrix();
glTranslatef(positionBus,0.0f,0.0f);

glBegin(GL_POLYGON);
    glColor3f(0.5f,0.7f,0.5f);
    glVertex2f(0.28f, -0.71f);
     glVertex2f(0.7f, -0.71f);
    glVertex2f(0.7f, -0.51f);
    glVertex2f(0.28f, -0.51f);

    glEnd();
    // bus glass
    glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(0.29f, -0.52f);
    glVertex2f(0.29f, -0.6f);
    glVertex2f(0.35f, -0.6f);
    glVertex2f(0.35f, -0.52f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(0.42f, -0.52f);
    glVertex2f(0.42f, -0.6f);
    glVertex2f(0.36f, -0.6f);
    glVertex2f(0.36f, -0.52f);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(0.43f, -0.52f);
    glVertex2f(0.43f, -0.6f);
    glVertex2f(0.49f, -0.6f);
    glVertex2f(0.49f, -0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(0.50f, -0.52f);
    glVertex2f(0.50f, -0.695f);
    glVertex2f(0.57f, -0.695f);
    glVertex2f(0.57f, -0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(0.58f, -0.52f);
    glVertex2f(0.58f, -0.6f);
    glVertex2f(0.63f, -0.6f);
    glVertex2f(0.63f, -0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(0.69f, -0.52f);
    glVertex2f(0.69f, -0.6f);
    glVertex2f(0.64f, -0.6f);
    glVertex2f(0.64f, -0.52f);
    glEnd();

    glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0.01f, 0.01f, 0.01f);
	glVertex2f(0.535f, -0.52f);
	glVertex2f(0.535f, -0.695f);

	glEnd();
//bus tier 1
    int t;

    GLfloat a7=0.35f,b7=-0.7f,r7=0.043f;
    int tringle7=40;
    GLfloat tp7 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(a7,b7);

    for(t= 0;t<=tringle7; t++)
    {glVertex2f (a7+(r7*cos(t*tp7/tringle7)),b7+(r7*sin(t*tp7/tringle7)));}
    glEnd ();

    //bus tier 2
    int r;

    GLfloat a8=0.63f,b8=-0.7f,r8=0.043f;
    int tringle8=40;
    GLfloat tp8 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(a8,b8);

    for(r= 0;r<=tringle8;r++)
    {glVertex2f (a8+(r8*cos(r*tp8/tringle8)),b8+(r8*sin(r*tp8/tringle8)));}
    glEnd ();
glPopMatrix();
glLoadIdentity();

}
//red car
void CarRed(){
    //car1 (red)
    //car body 1(red)
    glPushMatrix();
    glTranslatef(positionRedCar,0.0f,0.0f);
   //micro car
    //car body
    glPushMatrix();
glBegin(GL_POLYGON);
    glColor3f(1.0f,0.7f,0.0f);
    glVertex2f(-0.28f, -0.71f);
     glVertex2f(-0.0f, -0.71f);
    glVertex2f(-0.0f, -0.64f);
    glVertex2f(-0.07f, -0.57f);
    glVertex2f(-0.28f, -0.57f);

    glEnd();

    //car glass
glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(-0.27f, -0.59f);
    glVertex2f(-0.27f, -0.645f);
    glVertex2f(-0.22f, -0.645f);
    glVertex2f(-0.22f, -0.59f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(-0.21f, -0.59f);
    glVertex2f(-0.21f, -0.645f);
    glVertex2f(-0.13f, -0.645f);
    glVertex2f(-0.13f, -0.59f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(-0.12f, -0.59f);
    glVertex2f(-0.12f, -0.645f);
    glVertex2f(-0.015f, -0.645f);
    glVertex2f(-0.075f, -0.59f);
    glEnd();

    glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.122f, -0.57f);
	glVertex2f(-0.122f, -0.71f);

	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.128f, -0.57f);
	glVertex2f(-0.128f, -0.71f);

	glEnd();
    glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.21f, -0.57f);
	glVertex2f(-0.21f, -0.71f);

	glEnd();
    //car tier 1
    int i1;

    GLfloat a1=-0.08f,b1=-0.7f,r111=0.036f;
    int tringle1=40;
    GLfloat tp111 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(a1,b1);

    for(i1= 0;i1<=tringle1; i1++)
    {glVertex2f (a1+(r111*cos(i1*tp111/tringle1)),b1+(r111*sin(i1*tp111/tringle1)));}
    glEnd ();

    //car tier 2
    int j;

    GLfloat a2=-0.2f,b2=-0.7f,r222=0.036f;
    int tringle2=40;
    GLfloat tp222 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(a2,b2);

    for(j= 0;j<=tringle2; j++)
    {glVertex2f (a2+(r222*cos(j*tp222/tringle2)),b2+(r222*sin(j*tp222/tringle2)));}
    glEnd ();

    glPopMatrix();

    glLoadIdentity();
}
/*
//red car night
//red car
void CarRedNight(){
    //car1 (red)
    //car body 1(red)
    glPushMatrix();
    glTranslatef(positionRedCar,0.0f,0.0f);
    glScalef(0.4,1.0,0);
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.94f, -0.59f);
    glVertex2f(-0.98f, -0.64f);
    glVertex2f(-0.70f, -0.64f);
    glVertex2f(-0.78f, -0.59f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.99f, -0.64f);
    glVertex2f(-0.99f, -0.70f);
    glVertex2f(-0.60f, -0.70f);
    glVertex2f(-0.66f, -0.64f);
    glEnd();

    //car glass
    glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(-0.91f, -0.60f);
    glVertex2f(-0.94f, -0.64f);
    glVertex2f(-0.74f, -0.64f);
    glVertex2f(-0.80f, -0.60f);
    glEnd();

    //glass outlines
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.86f, -0.60f);
    glVertex2f(-0.86f, -0.64f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.85f, -0.64f);
    glVertex2f(-0.74f, -0.64f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.87f, -0.64f);
    glVertex2f(-0.94f, -0.64f);
    glEnd();

//headlight
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,200);;
    glVertex2f(-0.68f, -0.60f);
    glVertex2f(-0.68f, -0.64f);
    glVertex2f(-0.68f, -0.68f);
    glEnd();


    //car tier 1(red)
    int i;

    GLfloat a1=-0.94f,b1=-0.7f,r1=0.03f;
    int tringle1=40;
    GLfloat tp1 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(a1,b1);

    for(i= 0;i<=tringle1; i++)
    {glVertex2f (a1+(r1*cos(i*tp1/tringle1)),b1+(r1*sin(i*tp1/tringle1)));}
    glEnd ();

    //car tier 2(red)
    int j;

    GLfloat a2=-0.70f,b2=-0.7f,r2=0.03f;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(a2,b2);

    for(j= 0;j<=tringle2; j++)
    {glVertex2f (a2+(r2*cos(j*tp2/tringle2)),b2+(r2*sin(j*tp2/tringle2)));}
    glEnd ();

    glPopMatrix();

    glLoadIdentity();
}
*/

//green Car
void CarGreen(){
    //car2 (light green)
    //car body 1
    glPushMatrix();
    glTranslatef(positionGreenCar,0.0f,0.0f);
    //car 1
    //car body
      glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.75f,0.75f,0.75f);
    glVertex2f(0.5f, -0.78f);
    glVertex2f(0.56f, -0.85f);
    glVertex2f(0.56f, -0.9f);
    glVertex2f(0.27f, -0.9f);
    glVertex2f(0.27f, -0.85f);
    glVertex2f(0.34f, -0.78f);
    glEnd();

    //car glass

glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(0.34f, -0.797f);
    glVertex2f(0.29f, -0.85f);
    glVertex2f(0.545f, -0.85f);
    glVertex2f(0.5f, -0.797f);

    glEnd();

    glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(0.42f, -0.78f);
	glVertex2f(0.42f, -0.9f);
    glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(0.42f, -0.78f);
	glVertex2f(0.42f, -0.9f);
	glEnd();

    //car tier 1
    int k;

    GLfloat a3=0.36f,b3=-0.90f,r333=0.035f;
    int tringle3=40;
    GLfloat tp333 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(.0f,.0f,0.0f);
    glVertex2f(a3,b3);

    for(k= 0;k<=tringle3; k++)
    {glVertex2f (a3+(r333*cos(k*tp333/tringle3)),b3+(r333*sin(k*tp333/tringle3)));}
    glEnd ();

    //car tier 2
    int l;

    GLfloat a4=0.5f,b4=-0.90f,r4=0.035f;
    int tringle4=40;
    GLfloat tp4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(a4,b4);

    for(l= 0;l<=tringle4; l++)
    {glVertex2f (a4+(r4*cos(l*tp4/tringle4)),b4+(r4*sin(l*tp4/tringle4)));}
    glEnd ();

    glPopMatrix();

    glLoadIdentity();
}

//Blue Car
void CarBlue(){
//car3 (blue car)
    //car body 1
    glPushMatrix();
    glTranslatef(positionBlueCar,0.0f,0.0f);
    //car 2

   //car body
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.75f,0.75f);
    glVertex2f(-0.5f, -0.78f);
    glVertex2f(-0.56f, -0.85f);
    glVertex2f(-0.56f, -0.9f);
    glVertex2f(-0.27f, -0.9f);
    glVertex2f(-0.27f, -0.85f);
    glVertex2f(-0.34f, -0.78f);
    glEnd();

//car glass

glBegin(GL_QUADS);
    glColor3f(0.5f,0.9f,0.9f);
    glVertex2f(-0.34f, -0.797f);
    glVertex2f(-0.29f, -0.85f);
    glVertex2f(-0.545f, -0.85f);
    glVertex2f(-0.5f, -0.797f);

    glEnd();

    glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.01f, 0.01f, 0.01f);
	glVertex2f(-0.42f, -0.78f);
	glVertex2f(-0.42f, -0.9f);

	glEnd();
//car tier 1
    int m;

    GLfloat a5=-0.48f,b5=-0.90f,r5=0.035f;
    int tringle5=40;
    GLfloat tp5 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(a5,b5);

    for(m= 0;m<=tringle5; m++)
    {glVertex2f (a5+(r5*cos(m*tp5/tringle5)),b5+(r5*sin(m*tp5/tringle5)));}
    glEnd ();

    //car tier 2
    int n;

    GLfloat a6=-0.34f,b6=-0.90f,r6=0.035f;
    int tringle6=40;
    GLfloat tp6 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(a6,b6);

    for(n= 0;n<=tringle6;n++)
    {glVertex2f (a6+(r6*cos(n*tp6/tringle6)),b6+(r6*sin(n*tp6/tringle6)));}
    glEnd ();
    glPopMatrix();

    glLoadIdentity();
}

//traffic Light
void TrafficLight(){
    //traffic light
    //traffic light stand
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.005f, -0.6f);
    glVertex2f(-0.005f, -0.8f);
    glVertex2f(0.001f, -0.8f);
    glVertex2f(0.001f, -0.6f);
    glEnd();

    //upper stand
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.02f, -0.6f);
    glVertex2f(-0.02f, -0.48f);
    glVertex2f(0.02f, -0.48f);
    glVertex2f(0.02f, -0.6f);
    glEnd();



    //traffic light round shape

    int o;

    GLfloat a7=0.0f,b7=-0.54f,r7=0.015f;
    int tringle7=40;
    GLfloat tp7 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(color1,color2,0.0f);
    glVertex2f(a7,b7);

    for(o= 0;o<=tringle7;o++)
    {glVertex2f (a7+(r7*cos(o*tp7/tringle7)),b7+(r7*sin(o*tp7/tringle7)));}
    glEnd ();



    glLoadIdentity();
}


//road lights
void RoadLights_Day(){

    //road light 01
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.8f);
    glVertex2f(-0.85f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.58f);
    glVertex2f(-0.83f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.58f);
    glVertex2f(-0.87f, -0.58f);
    glEnd();


    //road light 02
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.65f, -0.8f);
    glVertex2f(-0.65f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.65f, -0.58f);
    glVertex2f(-0.63f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.65f, -0.58f);
    glVertex2f(-0.67f, -0.58f);
    glEnd();


    //road light 03
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.45f, -0.8f);
    glVertex2f(-0.45f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.45f, -0.58f);
    glVertex2f(-0.43f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.45f, -0.58f);
    glVertex2f(-0.47f, -0.58f);
    glEnd();



    //road light 04
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.25f, -0.8f);
    glVertex2f(-0.25f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.25f, -0.58f);
    glVertex2f(-0.23f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.25f, -0.58f);
    glVertex2f(-0.27f, -0.58f);
    glEnd();


    //road light 05
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.8f);
    glVertex2f(0.25f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.58f);
    glVertex2f(0.23f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.58f);
    glVertex2f(0.27f, -0.58f);
    glEnd();


    //road light 06
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.45f, -0.8f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.45f, -0.58f);
    glVertex2f(0.43f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.45f, -0.58f);
    glVertex2f(0.47f, -0.58f);
    glEnd();



    //road light 07
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.65f, -0.8f);
    glVertex2f(0.65f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.65f, -0.58f);
    glVertex2f(0.63f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.65f, -0.58f);
    glVertex2f(0.67f, -0.58f);
    glEnd();


    //road light 08
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.85f, -0.8f);
    glVertex2f(0.85f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.85f, -0.58f);
    glVertex2f(0.83f, -0.58f);
    glEnd();
    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.85f, -0.58f);
    glVertex2f(0.87f, -0.58f);
    glEnd();



glLoadIdentity();
}





//night road light
//road lights
void RoadLights_Night(){

    //road light 01
    //stand
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.8f);
    glVertex2f(-0.85f, -0.58f);
    glEnd();
    //Right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.58f);
    glVertex2f(-0.83f, -0.58f);
    glEnd();


    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.84f, -0.585f);
    glEnd();

    //Right light reflection
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(-0.84f,-0.585f);
    glVertex2f(-0.84f,-0.8f);
    glVertex2f(-0.8f,-0.8f);
    glEnd();


    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.585f);
    glVertex2f(-0.87f, -0.585f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.86f, -0.585f);
    glEnd();

    //Left light reflection
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(-0.86f,-0.585f);
    glVertex2f(-0.9f,-0.8f);
    glVertex2f(-0.86f,-0.8f);
    glEnd();



    //road light 02
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.65f, -0.8f);
    glVertex2f(-0.65f, -0.58f);
    glEnd();
    //Right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.65f, -0.58f);
    glVertex2f(-0.63f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.64f, -0.585f);
    glEnd();

    //Right light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(-0.64f,-0.585f);
    glVertex2f(-0.6f,-0.8f);
    glVertex2f(-0.64f,-0.8f);
    glEnd();


    //Left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.65f, -0.58f);
    glVertex2f(-0.67f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.66f, -0.585f);
    glEnd();

    //Left light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);

    glVertex2f(-0.66f,-0.585f);
    glVertex2f(-0.7f,-0.8f);
    glVertex2f(-0.66f,-0.8f);
    glEnd();




    //road light 03
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.45f, -0.8f);
    glVertex2f(-0.45f, -0.58f);
    glEnd();
    //Right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.45f, -0.58f);
    glVertex2f(-0.43f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.44f, -0.585f);
    glEnd();

    //Right light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(-0.44f,-0.585f);
    glVertex2f(-0.4f,-0.8f);
    glVertex2f(-0.44f,-0.8f);
    glEnd();


    //Left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.45f, -0.58f);
    glVertex2f(-0.47f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.46f, -0.585f);
    glEnd();

    //Left light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(-0.46f,-0.585f);
    glVertex2f(-0.5,-0.8f);
    glVertex2f(-0.46f,-0.8f);
    glEnd();




    //road light 04
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.25f, -0.8f);
    glVertex2f(-0.25f, -0.58f);
    glEnd();
    //Right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.25f, -0.58f);
    glVertex2f(-0.23f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.24f, -0.585f);
    glEnd();

    //Right light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(-0.24f,-0.585f);
    glVertex2f(-0.2f,-0.8f);
    glVertex2f(-0.24f,-0.8f);
    glEnd();



    //Left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.25f, -0.58f);
    glVertex2f(-0.27f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.26f, -0.585f);
    glEnd();

    //Left light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(-0.26f,-0.585f);
    glVertex2f(-0.3,-0.8f);
    glVertex2f(-0.26f,-0.8f);
    glEnd();


    //road light 05
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.8f);
    glVertex2f(0.25f, -0.58f);
    glEnd();
    //Left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.58f);
    glVertex2f(0.23f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.24f, -0.585f);
    glEnd();

     //Left light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.24f,-0.585f);
    glVertex2f(0.2f,-0.8f);
    glVertex2f(0.24f,-0.8f);
    glEnd();










    //Right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.58f);
    glVertex2f(0.27f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.26f, -0.585f);
    glEnd();

    //Right light Reflection
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.26f,-0.585f);
    glVertex2f(0.3,-0.8f);
    glVertex2f(0.26f,-0.8f);
    glEnd();




    //road light 06
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.45f, -0.8f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.45f, -0.58f);
    glVertex2f(0.43f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.44f, -0.585f);
    glEnd();

    //left light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.44f,-0.585f);
    glVertex2f(0.4f,-0.8f);
    glVertex2f(0.44f,-0.8f);
    glEnd();


    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.45f, -0.58f);
    glVertex2f(0.47f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.46f, -0.585f);
    glEnd();

    //Right light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.46f,-0.585f);
    glVertex2f(0.5,-0.8f);
    glVertex2f(0.46f,-0.8f);
    glEnd();




    //road light 07
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.65f, -0.8f);
    glVertex2f(0.65f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.65f, -0.58f);
    glVertex2f(0.63f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.64f, -0.585f);
    glEnd();


    //Left light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.64f,-0.585f);
    glVertex2f(0.6f,-0.8f);
    glVertex2f(0.64f,-0.8f);
    glEnd();



    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.65f, -0.58f);
    glVertex2f(0.67f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.66f, -0.585f);
    glEnd();

    //Right light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.66f,-0.585f);
    glVertex2f(0.7f,-0.8f);
    glVertex2f(0.66f,-0.8f);
    glEnd();

    //road light 08
    //stand
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.85f, -0.8f);
    glVertex2f(0.85f, -0.58f);
    glEnd();
    //left light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.85f, -0.58f);
    glVertex2f(0.83f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.84f, -0.585f);
    glEnd();

     //Left light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.84f,-0.585f);
    glVertex2f(0.84f,-0.8f);
    glVertex2f(0.8f,-0.8f);
    glEnd();


    //right light
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.85f, -0.58f);
    glVertex2f(0.87f, -0.58f);
    glEnd();

    glPointSize(9);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.86f, -0.585f);
    glEnd();

    //right light reflection

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,70);
    glVertex2f(0.86f,-0.585f);
    glVertex2f(0.9f,-0.8f);
    glVertex2f(0.86f,-0.8f);
    glEnd();


glLoadIdentity();
}


//zebra crossing
void ZebraCrossing(){
//white part
glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.09f,-0.6f);
glVertex2f(-0.09f,-1.0f);
glVertex2f(-0.02f,-1.0f);
glVertex2f(-0.02f,-0.6f);
glEnd();

//black parts
//black part 01
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.61f);
glVertex2f(-0.085f,-0.63f);
glVertex2f(-0.025f,-0.63f);
glVertex2f(-0.025f,-0.61f);
glEnd();

//black part 02
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.65f);
glVertex2f(-0.085f,-0.67f);
glVertex2f(-0.025f,-0.67f);
glVertex2f(-0.025f,-0.65f);
glEnd();

//black part 03
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.69f);
glVertex2f(-0.085f,-0.71f);
glVertex2f(-0.025f,-0.71f);
glVertex2f(-0.025f,-0.69f);
glEnd();

//black part 04
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.73f);
glVertex2f(-0.085f,-0.75f);
glVertex2f(-0.025f,-0.75f);
glVertex2f(-0.025f,-0.73f);
glEnd();

//black part 05
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.77f);
glVertex2f(-0.085f,-0.79f);
glVertex2f(-0.025f,-0.79f);
glVertex2f(-0.025f,-0.77f);
glEnd();

//black part 06
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.81f);
glVertex2f(-0.085f,-0.83f);
glVertex2f(-0.025f,-0.83f);
glVertex2f(-0.025f,-0.81f);
glEnd();

//black part 07
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.85f);
glVertex2f(-0.085f,-0.87f);
glVertex2f(-0.025f,-0.87f);
glVertex2f(-0.025f,-0.85f);
glEnd();

//black part 08
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.89f);
glVertex2f(-0.085f,-0.91f);
glVertex2f(-0.025f,-0.91f);
glVertex2f(-0.025f,-0.89f);
glEnd();

//black part 09
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.085f,-0.93f);
glVertex2f(-0.085f,-0.95f);
glVertex2f(-0.025f,-0.95f);
glVertex2f(-0.025f,-0.93f);
glEnd();

glLoadIdentity();
}

void HelicopterWheels(){
if(helicopter==true){
glTranslatef(helicopter_position,0.0f,0.0f);
//bigger wheel
glPushMatrix();
    glTranslatef(0.85,0.68,0);
        glPushMatrix();
            glRotatef(windmill_wheel_position,0,0,1);
                    glLineWidth(4);
                    glBegin(GL_LINES);

                    glColor3f(1.0f, 1.0f, 1.0f);
                    glVertex2f(-0.1f, 0.0f);
                    glVertex2f( 0.1f, 0.00f);
                    glVertex2f( 0.0f, -0.1f);
                    glVertex2f(-0.0f,  0.1f);
                    glEnd();


        glPopMatrix();
glPopMatrix();
}
glLoadIdentity();
}

//Small wheel
void Helicopter_SmallerWheels(){
if(helicopter==true){
glTranslatef(helicopter_position,0.0f,0.0f);
//smaller wheel
   glPushMatrix();
    glTranslatef(0.94,0.68,0);
    //glTranslatef(helicopter_position,0.0f,0.0f);
        glPushMatrix();
            glRotatef(windmill_wheel_position,0,0,1);
                    glLineWidth(4);
                    glBegin(GL_LINES);

                    glColor3f(1.0f, 1.0f, 1.0f);
                    glVertex2f(-0.025f, 0.0f);
                    glVertex2f( 0.025f, 0.00f);
                    glVertex2f( 0.0f, -0.025f);
                    glVertex2f(-0.0f,  0.025f);
                    glEnd();

        glPopMatrix();
    glPopMatrix();
}
glLoadIdentity();
}


//Helicopter

void Helicopter(){
if(helicopter==true){
//glTranslatef(helicopter_position,0.0f,0.0f);
//glPushMatrix();
//HelicopterWheels();

glTranslatef(helicopter_position,0.0f,0.0f);
glPushMatrix();
//main body
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.8f,0.65f);
glVertex2f(0.78f,0.6f);
glVertex2f(0.92f,0.6f);
glVertex2f(0.9f,0.65f);
glEnd();

//lower part of the body
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,0.0f);
glVertex2f(0.78f,0.6f);
glVertex2f(0.78f,0.58f);
glVertex2f(0.92f,0.58f);
glVertex2f(0.92f,0.6f);
glEnd();

//back triangle part
glBegin(GL_TRIANGLES);
glColor3f(1.0f,1.0f,0.0f);
glVertex2f(0.92f,0.58f);
glVertex2f(0.92f,0.62f);
glVertex2f(0.94f,0.68f);
glEnd();

//helicopter glass
glBegin(GL_QUADS);
glColor3ub(102, 255, 255);
glVertex2f(0.8f,0.64f);
glVertex2f(0.785f,0.6f);
glVertex2f(0.90f,0.6f);
glVertex2f(0.9f,0.64f);
glEnd();

//helicopter under paddles
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(0.785f,0.58f);
glVertex2f(0.785f,0.56f);
glVertex2f(0.785f,0.56f);
glVertex2f(0.9f,0.56f);
glVertex2f(0.785f,0.58f);
glVertex2f(0.9f,0.58f);
glVertex2f(0.9f,0.56f);
glVertex2f(0.9f,0.58f);
glEnd();

//helicopter outline
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(0.90f,0.6f);
glVertex2f(0.785f,0.6f);
glEnd();


//Helicopter Search Light 1
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(255, 255, 0);
glVertex2f(0.785f,0.56f);
glEnd();


if(helicopter_search_light1==true){
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
glColor4ub(255,255,121,70);
glVertex2f(0.785f,0.56f);
glVertex2f(-0.6f,-0.6f);
glVertex2f(-0.3f,-0.6f);
glEnd();

int k;

GLfloat d1=-0.45f;
GLfloat d2= -0.6f;
GLfloat r7 = 0.15f;
int triangle7=50;
GLfloat tp7 =2.0f * PI ;

//round search light
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,121,70);
glVertex2f (d1,d2);
for(k= 0;k<=triangle7; k++)
{
glVertex2f (
d1+(r7*cos(k*tp7/triangle7)),
d2+(r7*sin(k*tp7/triangle7))
);
}
glEnd ();
}

glPopMatrix();

//glPopMatrix();

}
glLoadIdentity();
}


//road trees
void road_trees(){
//tree 01
    glLineWidth(7);
    glBegin(GL_LINES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false)
        {glColor3ub(102,51,0);}
    glVertex2f(-0.75f, -0.4f);
   {glColor3ub(153,76,0);}
    glVertex2f(-0.75f, -0.6f);
    glEnd();
//triangle leaves
    glBegin(GL_TRIANGLES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(0,102,0);}
    glVertex2f(-0.75f, -0.3f);
   if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(-0.80f, -0.5f);
      if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(-0.70f, -0.5f);
    glEnd();



    //tree 02
    glLineWidth(7);
    glBegin(GL_LINES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(102,51,0);}
    glVertex2f(-0.4f, -0.4f);
    if(snowfall==true){glColor3ub(153,76,0);}
    else if(snowfall==false){glColor3ub(153,76,0);}
    glVertex2f(-0.4f, -0.6f);
    glEnd();
//triangle leaves
    glBegin(GL_TRIANGLES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(0,102,0);}
    glVertex2f(-0.4f, -0.3f);
    if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(-0.45f, -0.5f);
     if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(-0.35f, -0.5f);
    glEnd();

    //tree 03
    glLineWidth(7);
    glBegin(GL_LINES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(102,51,0);}
    glVertex2f(-0.0f, -0.4f);
    if(snowfall==true){glColor3ub(153,76,0);}
    else if(snowfall==false){glColor3ub(153,76,0);}
    glVertex2f(-0.0f, -0.6f);
    glEnd();
//triangle leaves
    glBegin(GL_TRIANGLES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(0,102,0);}
    glVertex2f(-0.0f, -0.3f);
  if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(-0.05f, -0.5f);
     if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(0.05f, -0.5f);
    glEnd();

    //tree 04
    glLineWidth(7);
    glBegin(GL_LINES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(102,51,0);}
    glVertex2f(0.4f, -0.4f);
    if(snowfall==true){glColor3ub(153,76,0);}
    else if(snowfall==false){glColor3ub(153,76,0);}
    glVertex2f(0.4f, -0.6f);
    glEnd();
//triangle leaves
    glBegin(GL_TRIANGLES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(0,102,0);}
    glVertex2f(0.4f, -0.3f);
     if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(0.35f, -0.5f);
     if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(0.45f, -0.5f);
    glEnd();

    //tree 05
    glLineWidth(7);
    glBegin(GL_LINES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(102,51,0);}
    glVertex2f(0.8f, -0.4f);
    if(snowfall==true){glColor3ub(153,76,0);}
    else if(snowfall==false){glColor3ub(153,76,0);}
    glVertex2f(0.8f, -0.6f);
    glEnd();
//triangle leaves
    glBegin(GL_TRIANGLES);
    if(snowfall==true){glColor3ub(255,255,255);}
    else if(snowfall==false){glColor3ub(0,102,0);}
    glVertex2f(0.8f, -0.3f);
 if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(0.75f, -0.5f);
     if(snowfall==true){glColor3ub(104,255,104);}
     if(snowfall==false){glColor3ub(0,204,0);}
    glVertex2f(0.85f, -0.5f);
    glEnd();

}




void SpringFlowers(){
if(spring==true){
    //flower of the road trees
    //tree 01
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(-0.75f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.75f, -0.42f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.77f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(-0.77f, -0.42f);
    glEnd();

    //tree 02
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(-0.4f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.4f, -0.42f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.38f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(-0.38f, -0.42f);
    glEnd();

    //tree 03
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(-0.0f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(-0.0f, -0.42f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.02f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(0.02f, -0.42f);
    glEnd();

    //tree 04
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(0.4f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.4f, -0.42f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.42f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(0.42f, -0.42f);
    glEnd();

    //tree 05
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(0.8f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.8f, -0.42f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,255,0);
    glVertex2f(0.82f, -0.4f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);
    glVertex2f(0.82f, -0.42f);
    glEnd();
}

glLoadIdentity();
}

void springSun(){
if(spring==true){
int k;

GLfloat d1=0.7f;
GLfloat d2= 0.85f;
GLfloat r7 = 0.08f;
int triangle7=50;
GLfloat tp7 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f (d1,d2);
for(k= 0;k<=triangle7; k++)
{
glVertex2f (
d1+(r7*cos(k*tp7/triangle7)),
d2+(r7*sin(k*tp7/triangle7))
);
}
glEnd ();
}

glLoadIdentity();
}

void bird(){
if(spring==true){
//1st bird

glPushMatrix();
glTranslatef(birdPosition,0.0f,0.0f);
int i;
GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
int triangleAmount = 20;
GLfloat twicePi = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(96,96,96);
glVertex2f(mm, nn); // center of circle
for(i = 0; i <= triangleAmount;i++){
			glVertex2f(mm+(radiusmm*cos(i* twicePi/triangleAmount)), nn+(radiusmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);  //birds downside
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f); // white wings
    glVertex2f(0.14f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(0.175f,0.8f);  //shadow wings
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
    glPopMatrix();

	/////2nd bird////

glPushMatrix();
glTranslatef(birdPosition,0.0f,0.0f);
	glBegin(GL_POLYGON);
    glColor3ub(96,96,96);
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(96,96,96);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(mmm+(radiusmmm*cos(i* twicePi/triangleAmount)),nnn+(radiusmmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();
glPopMatrix();
	/////3rd bird/////

glPushMatrix();
glTranslatef(birdPosition,0.0f,0.0f);
	glBegin(GL_POLYGON);
    glColor3ub(96,96,96);
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(96,96,96);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(mmmm+(radiusmmm*cos(i* twicePi/triangleAmount)), nnnn+(radiusmmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();
glPopMatrix();
	////4th bird////

	glPushMatrix();
	glTranslatef(birdPosition,0.0f,0.0f);
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(96,96,96);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(mmmmm+(radiusmm*cos(i* twicePi/triangleAmount)), nnnnn+(radiusmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();
glPopMatrix();

}
glLoadIdentity();
}

//******************spring cloud without translation
void SpringCloud(){
if(spring==true){
 //1
    int i;
    GLfloat p2=-0.88f; GLfloat q2= 0.84f; GLfloat r2 = 0.04;
    int tringle3=40;

    GLfloat tp3 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp3/tringle3)),
                    q2+(r2*sin(i*tp3/tringle3))
                    );


    }
    glEnd ();
    //2

    GLfloat p3=-0.83f; GLfloat q3= 0.87f; GLfloat r3 = 0.05f;
    int tringle4=40;

    GLfloat tp4 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp4/tringle4)),
                    q3+(r3*sin(i*tp4/tringle4))
                    );


    }
    glEnd ();

    //3
    GLfloat p4=-0.795f; GLfloat q4= 0.9f; GLfloat r4 = 0.05f;
    int tringle5=40;

    GLfloat tp5 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p4,q4);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp5/tringle5)),
                    q4+(r4*sin(i*tp5/tringle5))
                    );


    }
    glEnd ();

    //4
    GLfloat p5=-0.76f; GLfloat q5= 0.86f; GLfloat r5 = 0.04f;
    int tringle6=40;

    GLfloat tp6 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p5,q5);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp6/tringle6)),
                    q5+(r5*sin(i*tp6/tringle6))
                    );


    }
    glEnd ();


    //5
    GLfloat p6=-0.815f; GLfloat q6= 0.82f; GLfloat r6 = 0.04f;
    int tringle7=40;

    GLfloat tp7 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p6,q6);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p6+(r6*cos(i*tp7/tringle7)),
                    q6+(r6*sin(i*tp7/tringle7))
                    );


    }
    glEnd ();


    //2nd cloud


    //1
    GLfloat p7=0.88f; GLfloat q7= 0.84f; GLfloat r7 = 0.04;
    int tringle8=40;

    GLfloat tp8 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p7,q7);
    for(i= 0;i<=tringle8; i++)
    {
        glVertex2f (
                    p7+(r7*cos(i*tp8/tringle8)),
                    q7+(r7*sin(i*tp8/tringle8))
                    );


    }
    glEnd ();
    //2

    GLfloat p8=0.86f; GLfloat q8= 0.87f; GLfloat r8 = 0.04f;
    int tringle9=40;

    GLfloat tp9 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p8,q8);
    for(i= 0;i<=tringle9; i++)
    {
        glVertex2f (
                    p8+(r8*cos(i*tp9/tringle9)),
                    q8+(r8*sin(i*tp9/tringle9))
                    );


    }
    glEnd ();

    //3
    GLfloat p9=0.78f; GLfloat q9= 0.86f; GLfloat r9 = 0.06f;
    int tringle10=40;

    GLfloat tp10 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p9,q9);
    for(i= 0;i<=tringle10; i++)
    {
        glVertex2f (
                    p9+(r9*cos(i*tp10/tringle10)),
                    q9+(r9*sin(i*tp10/tringle10))
                    );


    }
    glEnd ();

    //4
    GLfloat p10=0.82f; GLfloat q10= 0.86f; GLfloat r10 = 0.04f;
    int tringle11=40;

    GLfloat tp11 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p10,q10);
    for(i= 0;i<=tringle11; i++)
    {
        glVertex2f (
                    p10+(r10*cos(i*tp11/tringle11)),
                    q10+(r10*sin(i*tp11/tringle11))
                    );


    }
    glEnd ();


    //5
    GLfloat p11=0.815f; GLfloat q11= 0.82f; GLfloat r11 = 0.04f;
    int tringle12=40;

    GLfloat tp12 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p11,q11);
    for(i= 0;i<=tringle11; i++)
    {
        glVertex2f (
                    p11+(r11*cos(i*tp12/tringle12)),
                    q11+(r11*sin(i*tp12/tringle12))
                    );


    }
    glEnd ();
}
}

//sun ray of spring
void springSunRay(){
if(spring==true){

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(-0.7f,-0.6f);
    glVertex2f(-0.65f,-0.6f);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(-0.8f,-0.3f);
    glVertex2f(-0.75f,-0.3f);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(0.6f,-1.0f);
    glVertex2f(0.65f,-1.0f);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(0.4f,-1.0f);
    glVertex2f(0.45f,-1.0f);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(0.2f,-1.0f);
    glVertex2f(0.25f,-1.0f);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.05f,-1.0f);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(-0.2f,-0.95f);
    glVertex2f(-0.15f,-0.95f);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(-0.4f,-0.85f);
    glVertex2f(-0.35f,-0.85f);
    glEnd();


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4ub(230,252,121,35);
    glVertex2f(0.7f,0.85f);
    glVertex2f(-0.6f,-0.75f);
    glVertex2f(-0.55f,-0.75f);
    glEnd();
}

glLoadIdentity();
}

//more winter effects
void winterHills(){
if(snowfall==true){
        //left hill 01
    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
    glVertex2f(-0.41f, 0.70f);
            glColor3ub(173,173,173);

    glColor3ub(102,255,255);
            glColor3ub(153,220,153);

    glVertex2f(-0.64f, 0.42f);
    glVertex2f(-0.18f, 0.42f);
    glEnd();

             //left hill 02

    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
    glVertex2f(-0.24f, 0.68f);
        glColor3ub(153,153,153);

    glColor3ub(102,255,255);
        glColor3ub(153,220,153);

    glVertex2f(-0.52f, 0.42f);
    glVertex2f(0.0f, 0.42f);
    glEnd();



    //hills 05 middle
    glBegin(GL_TRIANGLES);
  glColor3ub(153,220,153);
    glColor3ub(102,255,255);
            glColor3ub(153,153,153);

    glVertex2f(-0.08f, 0.42f);
    glVertex2f(0.26f, 0.42f);
    glColor3ub(255,255,255);


    glVertex2f(0.12f, 0.82f);
    glEnd();

    //hills 06
    glBegin(GL_TRIANGLES);
  glColor3ub(153,220,153);
    glVertex2f(0.0f, 0.42f);
                glColor3ub(173,173,173);

    glVertex2f(0.66f, 0.42f);
    glColor3ub(255,255,255);

    glVertex2f(0.24f, 0.82f);
    glEnd();

    //hill 7
    glBegin(GL_TRIANGLES);
  glColor3ub(153,220,153);
    glVertex2f(0.66f, 0.42f);
                    glColor3ub(173,173,173);
    glVertex2f(1.0f, 0.42f);
        glColor3ub(255,255,255);

    glVertex2f(0.84f, 0.82f);
    glEnd();

    //hills 03
    glBegin(GL_TRIANGLES);
    glColor3ub(255,229,204);
    glVertex2f(0.16f, 0.42f);
    glColor3ub(0,153,153);
    glVertex2f(0.48f, 0.42f);
    glVertex2f(0.32f, 0.72f);
    glEnd();

    //hills 04
    glBegin(GL_TRIANGLES);
    glColor3ub(0,102,102);
    glVertex2f(-0.08f, 0.42f);
    glColor3ub(0,153,153);
    glVertex2f(0.32f, 0.42f);
    glVertex2f(0.16f, 0.62f);
    glEnd();
}
glLoadIdentity();
}

//snow clouds
void snowClouds(){
if(snowfall==true){

//left to right clouds
//
glPushMatrix();
glTranslatef(-positionCloud, 0.0f,0.0f);
int i;
//middle round
GLfloat p1=0.2f;
GLfloat q1= -0.10f;
GLfloat r1 = 0.06f;
int triangle1=50;
GLfloat tp1 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p1,q1);
for(i= 0;i<=triangle1; i++)
{
glVertex2f (
p1+(r1*cos(i*tp1/triangle1)),
q1+(r1*sin(i*tp1/triangle1))
);
}
glEnd ();
//
GLfloat p11=0.5f;
GLfloat q11= 0.95f;
GLfloat r11 = 0.1f;
int triangle11=50;
GLfloat tp11 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p11,q11);
for(i= 0;i<=triangle11; i++)
{
glVertex2f (
p11+(r11*cos(i*tp11/triangle11)),
q11+(r11*sin(i*tp11/triangle11))
);
}
glEnd ();
//
GLfloat p21=-0.5f;
GLfloat q21= 0.45f;
GLfloat r21 = 0.15f;
int triangle21=50;
GLfloat tp21 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p21,q21);
for(i= 0;i<=triangle21; i++)
{
glVertex2f (
p21+(r21*cos(i*tp21/triangle21)),
q21+(r21*sin(i*tp21/triangle21))
);
}
glEnd ();
//
GLfloat p31=-0.0f;
GLfloat q31= 0.0f;
GLfloat r31 = 0.15f;
int triangle31=50;
GLfloat tp31 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p31,q31);
for(i= 0;i<=triangle31; i++)
{
glVertex2f (
p31+(r31*cos(i*tp31/triangle31)),
q31+(r31*sin(i*tp31/triangle31))
);
}
glEnd ();
//
GLfloat p41=-0.8f;
GLfloat q41= 0.8f;
GLfloat r41 = 0.15f;
int triangle41=50;
GLfloat tp41 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p41,q41);
for(i= 0;i<=triangle41; i++)
{
glVertex2f (
p41+(r41*cos(i*tp41/triangle41)),
q41+(r41*sin(i*tp41/triangle41))
);
}
glEnd ();



//left round
GLfloat p2=0.2f;
GLfloat q2= 0.35f;
GLfloat r2 = 0.06f;
int triangle2=50;

GLfloat tp2 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p2,q2);
for(i= 0;i<=triangle2; i++)
{
glVertex2f (
p2+(r2*cos(i*tp2/triangle2)),
q2+(r2*sin(i*tp2/triangle2))
);
}
glEnd ();

//right round
GLfloat p3=0.2f;
GLfloat q3= 0.65f;
GLfloat r3 = 0.08f;
int triangle3=50;

GLfloat tp3 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p3,q3);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p3+(r3*cos(i*tp3/triangle3)),
q3+(r3*sin(i*tp3/triangle3))
);
}
glEnd ();
glPopMatrix();


////

//right to left clouds
glPushMatrix();
glTranslatef(positionCloud, 0.0f,0.0f);
int j;
//middle round
GLfloat p4=-0.2f;
GLfloat q4= -0.45f;
GLfloat r4 = 0.06f;
int triangle4=50;
GLfloat tp4 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p4,q4);
for(j= 0;j<=triangle4; j++)
{
glVertex2f (
p4+(r4*cos(j*tp4/triangle4)),
q4+(r4*sin(j*tp4/triangle4))
);
}
glEnd ();
//left round
GLfloat p5=-0.1f;
GLfloat q5= 0.35f;
GLfloat r5 = 0.06f;
int triangle5=50;

GLfloat tp5 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p5,q5);
for(j= 0;j<=triangle5; j++)
{
glVertex2f (
p5+(r5*cos(j*tp5/triangle5)),
q5+(r5*sin(j*tp5/triangle5))
);
}
glEnd ();

//right round
GLfloat p6=-0.3f;
GLfloat q6= 0.65f;
GLfloat r6 = 0.08f;
int triangle6=50;

GLfloat tp6 =2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p6,q6);
for(j= 0;j<=triangle6; j++)
{
glVertex2f (
p6+(r6*cos(j*tp6/triangle6)),
q6+(r6*sin(j*tp6/triangle6))
);
}
glEnd ();

//
GLfloat p12=-0.8f;
GLfloat q12= 0.8f;
GLfloat r12= 0.15f;
int triangle12=50;
GLfloat tp12=2.0f * PI ;

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glBegin (GL_TRIANGLE_FAN);
glColor4ub(255,255,255,100);
glVertex2f (p12,q12);
for(i= 0;i<=triangle12; i++)
{
glVertex2f (
p12+(r12*cos(i*tp12/triangle12)),
q12+(r12*sin(i*tp12/triangle12))
);
}
glEnd ();
glPopMatrix();
}
glLoadIdentity();
}

//solid snows
void solidSnows(){
if(snowfall==true){
glPushMatrix();
//1
int i;
GLfloat p1 = -0.65f;
GLfloat q1 = -0.70f;
GLfloat r1 = 0.02f;
int triangle1 = 50;
GLfloat tp1 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p1,q1);
for(i= 0;i<=triangle1; i++)
{
glVertex2f (
p1+(r1*cos(i*tp1/triangle1)),
q1+(r1*sin(i*tp1/triangle1))
);
}
glEnd ();
//2
GLfloat p2 = -0.8f;
GLfloat q2 = -0.7f;
GLfloat r2 = 0.02f;
int triangle2 = 50;
GLfloat tp2 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p2,q2);
for(i= 0;i<=triangle2; i++)
{
glVertex2f (
p2+(r2*cos(i*tp2/triangle2)),
q2+(r2*sin(i*tp2/triangle2))
);
}
glEnd ();

//3
GLfloat p3 = -0.76f;
GLfloat q3 = -0.86f;
GLfloat r3 = 0.04f;
int triangle3 = 10;
GLfloat tp3 =2.0f * PI ;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p3,q3);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p3+(r3*cos(i*tp3/triangle3)),
q3+(r3*sin(i*tp3/triangle3))
);
}
glEnd ();

//4
GLfloat p4 = -0.6f;
GLfloat q4 = -0.80f;
GLfloat r4 = 0.04f;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p4,q4);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p4+(r4*cos(i*tp3/triangle3)),
q4+(r4*sin(i*tp3/triangle3))
);
}
glEnd();

//5
GLfloat p5 = -0.56f;
GLfloat q5 = -0.75f;
GLfloat r5 = 0.04f;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p5,q5);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p5+(r5*cos(i*tp3/triangle3)),
q5+(r5*sin(i*tp3/triangle3))
);
}
glEnd ();

//5 er pase
GLfloat pp5 = -0.36f;
GLfloat qq5 = -0.795f;
GLfloat rr5 = 0.04f;
int triangle = 30;


glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (pp5,qq5);
for(i= 0;i<=triangle; i++)
{
glVertex2f (
pp5+(rr5*cos(i*tp3/triangle)),
qq5+(rr5*sin(i*tp3/triangle))
);
}
glEnd ();
//5 er paser pase
GLfloat pp6 = -0.26f;
GLfloat qq6 = -0.85f;
GLfloat rr6 = 0.05f;
int triangles1 = 70;


glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (pp6,qq6);
for(i= 0;i<=triangles1; i++)
{
glVertex2f (
pp6+(rr6*cos(i*tp3/triangles1)),
qq6+(rr6*sin(i*tp3/triangles1))
);
}
glEnd ();
//6
GLfloat p6 = -0.5f;
GLfloat q6 = -0.77f;
GLfloat r6 = 0.04f;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p6,q6);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p6+(r6*cos(i*tp3/triangle3)),
q6+(r6*sin(i*tp3/triangle3))
);
}
glEnd ();

//7
GLfloat p7 = 0.0f;
GLfloat q7 = -0.77f;
GLfloat r7 = 0.04f;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p7,q7);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p7+(r7*cos(i*tp3/triangle3)),
q7+(r7*sin(i*tp3/triangle3))
);
}
glEnd ();

//8
GLfloat p8 = 0.3f;
GLfloat q8 = -0.80f;
GLfloat r8 = 0.05f;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p8,q8);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p8+(r8*cos(i*tp3/triangle3)),
q8+(r8*sin(i*tp3/triangle3))
);
}
glEnd ();

//9
GLfloat p9 = 0.7f;
GLfloat q9 = -0.80f;
GLfloat r9 = 0.05f;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p9,q9);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p9+(r9*cos(i*tp3/triangle3)),
q9+(r9*sin(i*tp3/triangle3))
);
}

//10
GLfloat p10 = 0.6f;
GLfloat q10 = -0.77f;
GLfloat r10 = 0.07f;

glBegin (GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
glVertex2f (p10,q10);
for(i= 0;i<=triangle3; i++)
{
glVertex2f (
p10+(r10*cos(i*tp3/triangle3)),
q10+(r10*sin(i*tp3/triangle3))
);
}
glEnd ();
glPopMatrix();
}


glLoadIdentity();
}

//waves
void Waves(){
glPushMatrix();
glTranslatef(wavePosition,0.0f,0.0f);
glLineWidth(0.5);
glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.6f,0.3f);
glVertex2f(0.65f,0.3f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.75f,0.35f);
glVertex2f(0.8f,0.35f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.9f,0.31f);
glVertex2f(0.95f,0.31f);
glEnd();

////////////////////////////////////////////

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.9f,0.29f);
glVertex2f(-0.95f,0.29f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.75f,0.25f);
glVertex2f(-0.8f,0.25f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.6f,0.27f);
glVertex2f(-0.65f,0.27f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.45f,0.26f);
glVertex2f(-0.50f,0.26f);
glEnd();



glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.30f,0.32f);
glVertex2f(-0.35f,0.32f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.15f,0.26f);
glVertex2f(-0.20f,0.26f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.0f,0.27f);
glVertex2f(-0.05f,0.27f);
glEnd();



glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.15f,0.28f);
glVertex2f(0.20f,0.28f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.30f,0.31f);
glVertex2f(0.35f,0.31f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.45f,0.27f);
glVertex2f(0.50f,0.27f);
glEnd();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////1st end

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.93f,0.08f);
glVertex2f(-0.98f,0.08f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.78f,0.03f);
glVertex2f(-0.83f,0.03f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.62f,0.07f);
glVertex2f(-0.67f,0.07f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.47f,0.12f);
glVertex2f(-0.52f,0.12f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.33f,0.16f);
glVertex2f(-0.38f,0.16f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.16f,0.09f);
glVertex2f(-0.21f,0.09f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.0f,-0.02f);
glVertex2f(-0.03f,-0.02f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.07f,0.10f);
glVertex2f(0.15f,0.10f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.19f,-0.01f);
glVertex2f(0.24f,-0.01f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.33f,0.11f);
glVertex2f(0.38f,0.11f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.50f,0.16f);
glVertex2f(0.56f,0.16f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.62f,0.11f);
glVertex2f(0.67f,0.11f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.78f,0.05f);
glVertex2f(0.83f,0.05f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.92f,0.15f);
glVertex2f(0.97f,0.15f);
glEnd();


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////2nd end

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.62f,-0.24f);
glVertex2f(0.67f,-0.24f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.80f,-0.32f);
glVertex2f(0.87f,-0.32f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(1.0f,-0.26f);
glVertex2f(0.96f,-0.26f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.92f,-0.34f);
glVertex2f(-0.97f,-0.34f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.77f,-0.30f);
glVertex2f(-0.82f,-0.30);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.59f,-0.36f);
glVertex2f(-0.64f,-0.36f);
glEnd();

glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.50f,-0.24f);
glVertex2f(-0.55f,-0.24f);
glEnd();



glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.30f,-0.30f);
glVertex2f(-0.35f,-0.30f);
glEnd();


glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(-0.17f,-0.23f);
glVertex2f(-0.23f,-0.23f);
glEnd();

/*
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(-0.15f,-0.3f);
glVertex2f(-0.20f,-0.3f);
glEnd();
*/



glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.26f,-0.31f);
glVertex2f(0.31f,-0.31f);
glEnd();



glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.07f,-0.33f);
glVertex2f(0.12f,-0.33f);
glEnd();





glBegin(GL_LINES);
glColor3ub(255,255,255);

glVertex2f(0.47f,-0.30f);
glVertex2f(0.53f,-0.30f);
glEnd();






glPopMatrix();
}

//views
void load_Restart(int x)
{
    glutDisplayFunc(load_Start);
}
//night
void NightView(){
glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
if(rainday==true){
Rainy_Sky();
Static_thunder();
Static_thunder2();
Hills();
fountain();
fountain_waves();
Cloud1();
Thunder_With_Cloud1();
Cloud2();
Thunder_With_Cloud2();
Plane();
NightSea();
Waves();
greenery();
greenery_trees();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
extra_greenery_trees();
Building4();
Building8Night();
Building2Night();
Building6Night();
Building7Night();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1Night();
Building9Night();
Building10Night();
Building3Night();
Building5Night();
road_trees();
Road();
Rain_Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Night();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
Rain();
}
if(snowfall==true){
Snow_Sky();
winterHills();
Plane();
hills_windmills();
NightSea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8Night();
Building2Night();
Building6Night();
Building7Night();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1Night();
Building9Night();
Building10Night();
Building3Night();
Building5Night();
road_trees();
Road();
solidSnows();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Night();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
snowClouds();
snow();
}

if(spring==true){
daySky();
springSun();
SpringCloud();
Hills();
Plane();
hills_windmills();
fountain();
fountain_waves();
DaySea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8();
Building2();
Building6();
Building7();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1();
Building9();
Building10();
Building3();
Building5();
road_trees();
Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Day();
CarGreen();
CarBlue();
if(spring == true){
SpringFlowers();
bird();
}
springSunRay();
}

if(rainday==false && snowfall==false && spring==false){
nightSky();
Moon();
Cloud1();
Cloud2();
Hills();
Plane();
hills_windmills();
fountain();
fountain_waves();
NightSea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8Night();
Building2Night();
Building6Night();
Building7Night();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1Night();
Building9Night();
Building10Night();
Building3Night();
Building5Night();
road_trees();
Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Night();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
if(spring == true){SpringFlowers();}
}
glutTimerFunc(5500,load_Restart,0);
//position_sun = 0.0f;
  glFlush();
}
void load_Night(int x)
{
    glutDisplayFunc(NightView);
}


//evening
void EveningView(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
if(rainday==true){
Rainy_Sky();
Static_thunder();
Static_thunder2();
Hills();
hills_windmills();
fountain();
fountain_waves();
Cloud1();
Thunder_With_Cloud1();
Cloud2();
Thunder_With_Cloud2();
Plane();
NightSea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8Night();
Building2Night();
Building6Night();
Building7Night();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1Night();
Building9Night();
Building10Night();
Building3Night();
Building5Night();
road_trees();
Road();
Rain_Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Night();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
Rain();
}
if(snowfall==true){
Snow_Sky();
winterHills();
Plane();
hills_windmills();
NightSea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8Night();
Building2Night();
Building6Night();
Building7Night();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1Night();
Building9Night();
Building10Night();
Building3Night();
Building5Night();
road_trees();
Road();
solidSnows(
);
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Night();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
snowClouds();
snow();
}

if(spring==true){
daySky();
springSun();
SpringCloud();
Hills();
Plane();
hills_windmills();
fountain();
fountain_waves();
DaySea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8();
Building2();
Building6();
Building7();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1();
Building9();
Building10();
Building3();
Building5();
road_trees();
Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Day();
CarGreen();
CarBlue();
if(spring == true){
SpringFlowers();
bird();
}
springSunRay();
}

if(rainday==false && snowfall==false && spring==false){
eveningSky();
Sun();
Cloud1();
Cloud2();
Plane();
Hills();
hills_windmills();
fountain();
fountain_waves();
EveningSea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8();
Building2();
Building6();
Building7();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1();
Building9();
Building10();
Building3();
Building5();
road_trees();
Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Night();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
if(spring == true){SpringFlowers();}
}
glutTimerFunc(5500,load_Night,0);
glFlush();
}

void load_Evening(int x)
{
    glutDisplayFunc(EveningView);
}


//day
void DayView(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
if(rainday==true){
Rainy_Sky();
Static_thunder();
Static_thunder2();
Hills();
hills_windmills();
fountain();
fountain_waves();
Cloud1();
Thunder_With_Cloud1();
Cloud2();
Thunder_With_Cloud2();
Plane();
NightSea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8Night();
Building2Night();
Building6Night();
Building7Night();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1Night();
Building9Night();
Building10Night();
Building3Night();
Building5Night();
road_trees();
Road();
Rain_Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Day();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
Rain();
}
if(snowfall==true){
Snow_Sky();
winterHills();
Plane();
hills_windmills();
NightSea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8Night();
Building2Night();
Building6Night();
Building7Night();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1Night();
Building9Night();
Building10Night();
Building3Night();
Building5Night();
road_trees();
Road();
solidSnows();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Day();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
snowClouds();
snow();
}

if(spring==true){
daySky();
springSun();
SpringCloud();
Plane();
Hills();
hills_windmills();
fountain();
fountain_waves();
DaySea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8();
Building2();
Building6();
Building7();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1();
Building9();
Building10();
Building3();
Building5();
road_trees();
Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Day();
CarGreen();
CarBlue();
if(spring == true){
SpringFlowers();
bird();
}
springSunRay();
}

if(rainday==false && snowfall==false && spring==false){
daySky();
Sun();
Cloud1();
Cloud2();
Plane();
Hills();
hills_windmills();
fountain();
fountain_waves();
DaySea();
Waves();
greenery();
speedBoat();
boatDock();
translateSpeedBoat();
boat1();
boat2();
greenery_trees();
extra_greenery_trees();
Building4();
Building8();
Building2();
Building6();
Building7();
Bridge();
Train();
Parachute();
windmill();
TrainUpperStands();
Building1();
Building9();
Building10();
Building3();
Building5();
road_trees();
Road();
ZebraCrossing();
CarRed();
Bus();
TrafficLight();
RoadLights_Day();
CarGreen();
CarBlue();
if(helicopter==true){HelicopterWheels();Helicopter();Helicopter_SmallerWheels();}
}
glutTimerFunc(5500,load_Evening,0);
glFlush();
}

void load_Day(int x)
{
    glutDisplayFunc(DayView);
}

void load_Start()
{
    glutDisplayFunc(DayView);
}

//mousecontrol
void handleMouse(int button,int state,int x,int y){
if (button == GLUT_LEFT_BUTTON){
    speedBlueCar += 0.02f;
    speedRedCar+= 0.02f;
    speedBus += 0.02f;
    speedGreenCar+= 0.02f;

}
if (button == GLUT_RIGHT_BUTTON){
    speedBlueCar -= 0.01f;
    speedRedCar-= 0.01f;
    speedBus -= 0.01f;
    speedGreenCar-= 0.01f;
}
    glutPostRedisplay();
}


//keyboard key
void handleKeypress(unsigned char key, int x, int y) {
switch (key) {
case 'a':
    speedRedCar= 0.0f;
    speedBlueCar= 0.0f;
    speedGreenCar=0.0f;
    speedBus = 0.0f;
    color1 += 1.0f;
    color2 -= 1.0f;
    glutPostRedisplay();
    break;

case 'b':
    speedRedCar = 0.01f;
    speedBlueCar = 0.01f;
    speedGreenCar = 0.01f;
    speedBus=0.01f;
    color1 = 0.0f;
    color2 = 1.0f;
    glutPostRedisplay();
    break;


case 'r':
    rainday=true;
    glutPostRedisplay();
    break;
case 'x':
    rainday=false;
    glutPostRedisplay();
    break;
case 's':
    snowfall=true;
    glutPostRedisplay();
    break;
case 'y':
    snowfall=false;
    glutPostRedisplay();
    break;
case 'k':
    helicopter=true;
    glutPostRedisplay();
    break;
case 'l':
    helicopter=false;
    glutPostRedisplay();
    break;
case 'c':
    helicopter_speed = 0.0f;
    glutPostRedisplay();
    break;
case 'd':
    helicopter_speed = 0.02f;
    glutPostRedisplay();
    break;
case 't':
    helicopter_search_light1 = true;
    glutPostRedisplay();
    break;
case 'u':
    helicopter_search_light1 = false;
    glutPostRedisplay();
    break;
case 'w':
    spring = true;
    glutPostRedisplay();
    break;
case 'z':
    spring = false;
    glutPostRedisplay();
    break;
glutPostRedisplay();

case 'o':
  snowspeed = 0.0f;
  glutPostRedisplay();
    break;
case 'v':
  snowspeed = 0.02f;
  glutPostRedisplay();
    break;
case '1':
  speedboatSpeed=0.02f;
  glutPostRedisplay();
    break;
case '2':
  speedboatSpeed=0.0f;
  glutPostRedisplay();
    break;
 case '3':
  speed_parachute=0.001f;
  glutPostRedisplay();
    break;
case '4':
  speed_parachute=0.0f;
  glutPostRedisplay();
    break;
case '5':
  speed_Plane=0.01f;
  glutPostRedisplay();
    break;
case '6':
  speed_Plane=0.0f;
  glutPostRedisplay();
    break;

case '/':
  boat2_speed+=0.008f;
  boat1_speed+=0.004f;
  glutPostRedisplay();
    break;
case '*':
  boat2_speed=0.0f;
  boat1_speed = 0.0f;
  glutPostRedisplay();
    break;


case '7':
    thunder=true;
    glutPostRedisplay();
    break;
case '8':
    thunder=false;
    glutPostRedisplay();
    break;

}
}
int main(int argc, char** argv)
{


	glutInit(&argc, argv);                 // Initialize GLUT

    glutInitWindowPosition(0,0);
	glutInitWindowSize(1400, 720);
    glutCreateWindow("City Life"); // Create a window with the given title
    cout<<" HELP : "<<endl;
	cout<<"*******************************************************"<<endl;

	cout<<" To stop car for traffic, Press 'A' "<<endl;
	cout<<" To start car for traffic, Press 'B' "<<endl;

	cout<<" To start rain, Press 'R' "<<endl;
	cout<<" To stop rain, Press 'X' "<<endl;

	cout<<" To start snowfall, Press 'S' "<<endl;
	cout<<" To stop snowfall, Press 'Y' "<<endl;

	cout<<" To start helicopter, Press 'K' "<<endl;
    cout<<" To stop helicopter, Press 'L' "<<endl;

	cout<<" To speed up the helicopter, Press 'D' "<<endl;
	cout<<" To speed down the helicopter, Press 'C' "<<endl;

	cout<<" To start helicopter search light, Press 'T' "<<endl;
    cout<<" To stop helicopter search light, Press 'U' "<<endl;

	cout<<" To watch spring, Press 'W' "<<endl;
	cout<<" To stop watch spring, Press 'Z' "<<endl;

	cout<<" To speed up the snowfall, Press 'V' "<<endl;
	cout<<" To speed down the snowfall, Press 'O' "<<endl;

	cout<<" To start boat, Press '1' "<<endl;
	cout<<" To stop boat, Press '2' "<<endl;

	cout<<" To speed up the boat, Press '/' "<<endl;
	cout<<" To speed down the boat , Press '*' "<<endl;

	cout<<" To start parachute, Press '3' "<<endl;
    cout<<" To stop parachute, Press '4' "<<endl;

    cout<<" To start plane, Press '5' "<<endl;
    cout<<" To stop plane, Press '6' "<<endl;

    cout<<" To start thunder, Press '7' "<<endl;
    cout<<" To stop thunder, Press '8' "<<endl;

    cout<<" To speed up the car, Click the 'Right Button' "<<endl;
	cout<<" To speed down the car, Click the 'Left Button' "<<endl;
	glutDisplayFunc(load_Start);
    glutTimerFunc(100, UpdateRedCar, 0);
    glutTimerFunc(100, UpdateBus, 0);
    glutTimerFunc(100, UpdateGreenCar, 0);
    glutTimerFunc(100, UpdateBlueCar, 0);
    glutTimerFunc(100, UpdateTrain, 0);
    glutTimerFunc(135, update_sun, 0);
    glutTimerFunc(80, update_moon, 0);
    glutTimerFunc(1000/60, UpdateCloud, 0);
    glutTimerFunc(1000/70, Rainupdate1, 0);
    glutTimerFunc(1000/20, updateSnow, 0);
    glutTimerFunc(1000/40, UpdateWindMill, 0);
    glutTimerFunc(1000/40, UpdateWaveFountain, 0);
    glutTimerFunc(100, UpdateBoat1, 0);
    glutTimerFunc(100, UpdateBoat1Smoke, 0);
    glutTimerFunc(100, UpdateBoat2, 0);
    glutTimerFunc(100, UpdateBoat2Smoke, 0);
    glutTimerFunc(100, UpdatePlane, 0);
    glutTimerFunc(100, UpdateHelicopter, 0);
    glutTimerFunc(100, UpdateParachute, 0);
    glutTimerFunc(50, UpdateBird, 0);
    glutTimerFunc(50, UpdateWave, 0);
    glutTimerFunc(100, UpdateSpeedBoat, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutIdleFunc(Idle);

	glutMainLoop();           // Enter the event-processing loop
	return 0;

}


