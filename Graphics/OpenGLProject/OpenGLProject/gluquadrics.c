//#include <stdlib.h>
//#include <GL/glut.h>
//GLUquadricObj* qobj;  // 새로운 Quadric 생성
//
//void MyInit(void) {
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
//}
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glEnable(GL_LIGHTING);
//	glShadeModel(GL_SMOOTH); // 각 정점에 정한 색상을 보간하여 혼합하여 칠하게 설정
//
//	qobj = gluNewQuadric();
//	gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric을 위해 원하는 Draw Style 지정
//	gluQuadricNormals(qobj, GLU_FLAT); // 법선벡터 제어
//	gluQuadricOrientation(qobj, GLU_INSIDE); // 법선벡터 내부 및 외부 등과 같은 방향 지정
//	gluQuadricTexture(qobj, GL_TRUE); // Texture 좌표 사용할 것인지에 대한 여부
//	gluSphere(qobj, 1.5, 50, 50); // Sphere 생성
//	glutSwapBuffers();
//}
//
//void Reshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Graphics Primitives");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(Reshape);
//	glutMainLoop();
//	return 0;
//}