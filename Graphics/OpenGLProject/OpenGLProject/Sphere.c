//#include <Windows.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <stdbool.h>
//
//GLUquadricObj *sphere = NULL;
//
//void MyDisplay();
//void Reshape(int w, int h);
//void MyInit();
//
//int Mysphere;
//
//void MyCreateList() {
//	Mysphere = glGenLists(1); // DisplayList 선언
//
//	glNewList(Mysphere, GL_COMPILE);
//
//	glEnd();
//	glEndList(); //DisplayList 끝
//
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600); //윈도우 창크기
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Sphere Primitives");
//
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(Reshape);
//
//	MyCreateList(); // Display List 생성
//
//	glutMainLoop();
//	return 0;
//}
//
//void MyDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glEnable(GL_LIGHTING);
//	glShadeModel(GL_SMOOTH); // 각 정점에 정한 색상을 보간하여 혼합하여 칠하게 설정
//
//	sphere = gluNewQuadric();   //새로운 Quadric Object생성
//
//	gluQuadricDrawStyle(sphere, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정  -> LINKE하면 Wire형태, POINT하면 점만, SILHOUETTE는 선으로 외부 모서리만 그림
//	gluQuadricNormals(sphere, GLU_SMOOTH); // 법선벡터 제어
//	gluQuadricOrientation(sphere, GLU_OUTSIDE); // 법선벡터 내부 및 외부 등과 같은 방향 지정
//	gluQuadricTexture(sphere, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
//
//	gluSphere(sphere, 1.0, 30, 30);
//	//glutWireSphere(1.0, 30, 30); //Wire형태
//	//glutSolidSphere(1.0, 30, 30); //Solid형태
//	glutSwapBuffers();
//
//	glCallList(Mysphere);//	gluDeleteQuadric(sphere);   //Quadric Object삭제//	
//}
//
//void Reshape(int w, int h) {
//
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //시각조절
//	glMatrixMode(GL_PROJECTION); //두영
//	glLoadIdentity();
//	
//	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //비울조절
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void MyInit()
//{
//	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; //주변광
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //반사광
//	GLfloat mat_shininess[] = { 50.0 }; //선명도
//	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; //조명 위치
//	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//
//}
//
