//#include <Windows.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//
//GLUquadricObj *cylinder;
//int Mycylinder;
//
//void MyDisplay();
//void Reshape(int w, int h);
//void MyInit();
//
//void MyCreateList() {
//	Mycylinder = glGenLists(1); // DisplayList 선언
//
//	glNewList(Mycylinder, GL_COMPILE); //DisplayList 생성
//
//	glEnd();
//	glEndList(); //DisplayList 끝
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
//	cylinder = gluNewQuadric(); //새로운 Quadric Object생성
//
//	gluQuadricDrawStyle(cylinder, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정  -> LINKE하면 Wire형태, POINT하면 점만, SILHOUETTE는 선으로 외부 모서리만 그림
//	gluQuadricNormals(cylinder, GLU_SMOOTH); // 법선벡터 제어
//	gluQuadricOrientation(cylinder, GLU_OUTSIDE); // 법선벡터 내부 및 외부 등과 같은 방향 지정
//	gluQuadricTexture(cylinder, GL_TRUE); // Texture 좌표 사용할 것인지에 대한 여부
//
//	gluCylinder(cylinder, 1.0, 0.0, 2.0, 50, 8);  //원뿔모양의 기둥생성 바닥 원 반지름=1.0, 맨 위 원 반지름=0.0, 높이=2.0
//	//glutWireCone(1.0, 1.5, 12, 12); //Wier형태
//	//glutSolidCone(1.0, 1.5, 12, 12); //Solid형태
//	glutSwapBuffers();
//
//	glCallList(Mycylinder); //DisplayList 호출
//	gluDeleteQuadric(cylinder); //Quadric Object삭제
//}
//
//void Reshape(int w, int h) {
//
//	glViewport(-10, -10, (GLsizei)w, (GLsizei)h); //시각조절
//	glMatrixMode(GL_PROJECTION); //투영
//	glLoadIdentity();
//
//	glOrtho(-2.0, 2.5,  -2.5 * (GLfloat)h/(GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //비율조절
//	gluLookAt(2, 0, 1, 0, 0, 0, 0, 1, 0); //우측에서 바로보도록
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
//
//	glClearColor(0.0, 0.0, 0.0, 0.0); //바탕색
//
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600); //윈도우 창 크기
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Cylinder Primitives");
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