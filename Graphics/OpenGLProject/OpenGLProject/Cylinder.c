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
//	Mycylinder = glGenLists(1); // DisplayList ����
//
//	glNewList(Mycylinder, GL_COMPILE); //DisplayList ����
//
//	glEnd();
//	glEndList(); //DisplayList ��
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
//	cylinder = gluNewQuadric(); //���ο� Quadric Object����
//
//	gluQuadricDrawStyle(cylinder, GLU_FILL); // Quadric�� ���� ���ϴ� Draw Style ����  -> LINKE�ϸ� Wire����, POINT�ϸ� ����, SILHOUETTE�� ������ �ܺ� �𼭸��� �׸�
//	gluQuadricNormals(cylinder, GLU_SMOOTH); // �������� ����
//	gluQuadricOrientation(cylinder, GLU_OUTSIDE); // �������� ���� �� �ܺ� ��� ���� ���� ����
//	gluQuadricTexture(cylinder, GL_TRUE); // Texture ��ǥ ����� �������� ���� ����
//
//	gluCylinder(cylinder, 1.0, 0.0, 2.0, 50, 8);  //���Ը���� ��ջ��� �ٴ� �� ������=1.0, �� �� �� ������=0.0, ����=2.0
//	//glutWireCone(1.0, 1.5, 12, 12); //Wier����
//	//glutSolidCone(1.0, 1.5, 12, 12); //Solid����
//	glutSwapBuffers();
//
//	glCallList(Mycylinder); //DisplayList ȣ��
//	gluDeleteQuadric(cylinder); //Quadric Object����
//}
//
//void Reshape(int w, int h) {
//
//	glViewport(-10, -10, (GLsizei)w, (GLsizei)h); //�ð�����
//	glMatrixMode(GL_PROJECTION); //����
//	glLoadIdentity();
//
//	glOrtho(-2.0, 2.5,  -2.5 * (GLfloat)h/(GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //��������
//	gluLookAt(2, 0, 1, 0, 0, 0, 0, 1, 0); //�������� �ٷκ�����
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
//
//	glClearColor(0.0, 0.0, 0.0, 0.0); //������
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
//	glutInitWindowSize(800, 600); //������ â ũ��
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Cylinder Primitives");
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