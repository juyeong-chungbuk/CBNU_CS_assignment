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
//	Mysphere = glGenLists(1); // DisplayList ����
//
//	glNewList(Mysphere, GL_COMPILE);
//
//	glEnd();
//	glEndList(); //DisplayList ��
//
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600); //������ âũ��
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Sphere Primitives");
//
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(Reshape);
//
//	MyCreateList(); // Display List ����
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
//	glShadeModel(GL_SMOOTH); // �� ������ ���� ������ �����Ͽ� ȥ���Ͽ� ĥ�ϰ� ����
//
//	sphere = gluNewQuadric();   //���ο� Quadric Object����
//
//	gluQuadricDrawStyle(sphere, GLU_FILL); // Quadric�� ���� ���ϴ� Draw Style ����  -> LINKE�ϸ� Wire����, POINT�ϸ� ����, SILHOUETTE�� ������ �ܺ� �𼭸��� �׸�
//	gluQuadricNormals(sphere, GLU_SMOOTH); // �������� ����
//	gluQuadricOrientation(sphere, GLU_OUTSIDE); // �������� ���� �� �ܺ� ��� ���� ���� ����
//	gluQuadricTexture(sphere, GL_FALSE); // Texture ��ǥ ����� �������� ���� ����
//
//	gluSphere(sphere, 1.0, 30, 30);
//	//glutWireSphere(1.0, 30, 30); //Wire����
//	//glutSolidSphere(1.0, 30, 30); //Solid����
//	glutSwapBuffers();
//
//	glCallList(Mysphere);//	gluDeleteQuadric(sphere);   //Quadric Object����//	
//}
//
//void Reshape(int w, int h) {
//
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //�ð�����
//	glMatrixMode(GL_PROJECTION); //�ο�
//	glLoadIdentity();
//	
//	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //�������
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void MyInit()
//{
//	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; //�ֺ���
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //�ݻ籤
//	GLfloat mat_shininess[] = { 50.0 }; //����
//	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; //���� ��ġ
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
