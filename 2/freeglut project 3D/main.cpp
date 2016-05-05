#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>


#include "Iman.h"
#include "Hipotrocoide.h"
#include "Bosque.h"
#include "Coche.h"
#include "Camara.h"
#include "Cilindro.h"
#include <iostream>
using namespace std;

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Scene variables
GLfloat angX, angY, angZ; 
bool baldosas = false;
//--------------------------------------------------------------------------------------------

// TIPOS PARA EJECUTAR LAS DIFERENTES PRACTICAS
typedef enum {
	IMAN,
	HIPOTROCOIDE,
	BOSQUE,
	COCHE,
	CAMARA,
	NONE
} Practicas;

Practicas practica = Practicas::NONE;


Iman* i;
Hipotrocoide* h;
Bosque* b;
Coche* c;
Camara* cam;
//xObjeto3D* o3d;

//--------------------------------------------------------------------------------------------


void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;	

	switch (practica){
	case IMAN:
		i = new Iman(100, 2, 5, 3);
		break;
	case HIPOTROCOIDE:
		h = new Hipotrocoide(20, 100);
		break;
	case BOSQUE:
		b = new Bosque();
		break;
	case COCHE:
		c = new Coche(3);
		break;
	case CAMARA:
		b = new Bosque();
		cam = new Camara();
		break;
	}	
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
      
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default

	buildSceneObjects();

	// Light0
	glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
    GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  	



 }



void drawScene(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	// Rotating the scene
	glRotatef(angX, 1.0f, 0.0f, 0.0f);
	glRotatef(angY, 0.0f, 1.0f, 0.0f);
	glRotatef(angZ, 0.0f, 0.0f, 1.0f);

	glLineWidth(1.5f);
	// Drawing axes
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(20, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 20, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 20);
	glEnd();

	// Drawing the scene	 		 
	glColor3f(1.0, 1.0, 1.0);

	//...........................................
	switch (practica){
	case IMAN:
		i->dibuja();
		break;
	case HIPOTROCOIDE:
		h->dibuja();
		break;
	case BOSQUE:
		b->dibuja();
		break;
	case COCHE:
		c->dibuja();
		break;
	case CAMARA:
		b->dibuja();
		break;
	}
	//...........................................

	glPopMatrix();
}


void reset(){
	angX = 0.0f;
	angY = 0.0f;
	angZ = 0.0f;
}



void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}


void zoom(float incr){
	GLdouble fAux = 1 + incr;
	GLdouble anchoNew = (xRight - xLeft) / fAux;
	GLdouble altoNew = (yTop - yBot) / fAux;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLdouble hmedio = (xRight - xLeft) / 2.0 + xLeft;
	GLdouble vmedio = (yTop - yBot) / 2.0 + yBot;
	xLeft = hmedio - anchoNew / 2.0;
	xRight = hmedio + anchoNew / 2.0;
	yBot = vmedio - altoNew / 2.0;
	yTop = vmedio + altoNew / 2.0;

	cam->actualizaVolumenVista(xLeft, xRight, yBot, yTop);

}

void embaldosar(int nCol){
	GLdouble SVAratio = (xRight - xLeft) / (yTop - yBot);
	GLdouble w = (GLdouble)WIDTH / (GLdouble)nCol;

	//La altura de cada puerto se calcula proporcionalmente
	GLdouble h = w / SVAratio;
	int idx = 0;
	for (GLint c = 0; c<nCol; c++){
		GLdouble currentH = 0;
		while ((currentH + h) <= HEIGHT){
			glViewport((GLint)(c*w), (GLint)currentH, (GLint)w, (GLint)h);
			switch (idx){
			case 0:
				cam->lateral();
				break;
			case 1:
				cam->frontal();
				break;
			case 2:
				cam->cenital();
				break;
			case 3:
				cam->rincon();
				
				break;
			default:
				break;
			}
			drawScene();
			currentH += h;
			idx++;
		}//while
	}//for

}

void desembaldosar(){
	glViewport(0, 0, WIDTH, HEIGHT);

}


void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	//a,z,s,x,d,c,g,h,f,v,p,u,i,o,b,e
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;		 
		case 'a': angX=angX+5; break;
		case 'z': angX=angX-5; break; 
		case 's': angY=angY+5; break;
		case 'x': angY=angY-5; break;
		case 'd': angZ=angZ+5; break;
		case 'c': angZ=angZ-5; break;  
		case 'g': 
			if(practica == Practicas::HIPOTROCOIDE) 
				h->cambiaModoRelleno(true);
			break;
		case 'h': 
			if (practica == Practicas::HIPOTROCOIDE)
				h->cambiaModoRelleno(false);
			else if (practica == Practicas::CAMARA)
				zoom(-0.1);
			break;
		case 'f':
			if (practica == Practicas::COCHE)
				c->mover(1);
			break;
		case 'v':
			if (practica == Practicas::COCHE)
				c->mover(-1);
			break;
		case 'F': 
			if (practica == Practicas::COCHE)
				c->girar(1); 
			break;
		case 'V':
			if (practica == Practicas::COCHE)
				c->girar(-1); 
			break;
		case '1':
			if (practica == Practicas::CAMARA)
				cam->giraX();
			break;
		case '2':
			if (practica == Practicas::CAMARA)
				cam->giraY();
			break;
		case '3':
			if (practica == Practicas::CAMARA)
				cam->giraZ();
			break;
		case '4':
			if (practica == Practicas::CAMARA)
				cam->lateral();
			break;
		case '5':
			if (practica == Practicas::CAMARA)
				cam->frontal();
			break;
		case '6':
			if (practica == Practicas::CAMARA)
				cam->cenital();
			break;
		case '7':
			if (practica == Practicas::CAMARA)
				cam->rincon();
			break;
		case '8':
			if (practica == Practicas::CAMARA)
				baldosas = true;
			break;
		case '9':
			if (practica == Practicas::CAMARA){
				if (baldosas)
					desembaldosar();
				baldosas = false;
			}
			break;
		case 'p':
			if (practica == Practicas::CAMARA)
				cam->switchProjection();
			break;
		case 'u':
			if (practica == Practicas::CAMARA)
				cam->roll(0.05); 
			break;
		case 'i':
			if (practica == Practicas::CAMARA)
				cam->yaw(0.05); 
			break;
		case 'o':
			if (practica == Practicas::CAMARA)
				cam->pitch(0.05); 
			break;
		case 'e':
			if (practica == Practicas::CAMARA)
				zoom(0.1);
			break;
		case 'r':
			reset();
			break;
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

void seleccionaPractica(){
	cout << "Selecciona la practica a ejecutar: " << endl;
	int s = -1;
	while (s < 0 || s >= Practicas::NONE){ //NONE -> ultimo elemento
		cout << "\t0.- Iman" << endl;
		cout << "\t1.- Hipotrocoide" << endl;
		cout << "\t2.- Bosque" << endl;
		cout << "\t3.- Coche" << endl;
		cout << "\t4.- Camara" << endl;
		cout << "-> ";
		cin >> s;
	}

	practica = (Practicas)s;
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (baldosas)
		embaldosar(2);
	else
		drawScene();

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	//.....................
	seleccionaPractica();
	//.....................

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();
	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}


