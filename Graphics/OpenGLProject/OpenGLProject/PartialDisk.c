//#include <Windows.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <stdbool.h>
//
//GLUquadricObj *qobj = NULL;
//
//void MyDisplay();
//void Reshape(int w, int h);
//void MyInit();
//
//int Mypartialdisk;
//
//void MyCreateList() {
//	Mypartialdisk = glGenLists(1); // DisplayList ����
//
//	glNewList(Mypartialdisk, GL_COMPILE);
//
//	glEnd();
//	glEndList();
//
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600); //������ â ũ��
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
//	qobj = gluNewQuadric();  //���ο� Quadric Object����
//
//	gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric�� ���� ���ϴ� Draw Style ����  -> LINE�ϸ� Wire����, POINT�ϸ� ����, SILHOUETTE�� ������ �ܺ� �𼭸��� �׸�
//	gluQuadricNormals(qobj, GLU_SMOOTH); // �������� ����
//	gluQuadricOrientation(qobj, GLU_OUTSIDE); // �������� ���� �� �ܺ� ��� ���� ���� ����
//	gluQuadricTexture(qobj, GL_FALSE); // Texture ��ǥ ����� �������� ���� ����
//
//	gluPartialDisk(qobj, 1.5, 3.0, 26, 13, -90.0, 90.0);
//	glutSwapBuffers();
//
//	glCallList(Mypartialdisk); //Display List ȣ��//	gluDeleteQuadric(qobj);  // Quadric Object����//	
//}
//
//void Reshape(int w, int h) {
//
//	glViewport(200, -150, (GLsizei)w, (GLsizei)h); //�ð�����
//	glMatrixMode(GL_PROJECTION); //����
//	glLoadIdentity();
//	
//	glOrtho(-3.0, 4.0, -3.0 * (GLfloat)h / (GLfloat)w, 4.0 * (GLfloat)h / (GLfloat)w, -50.0, 50.0); //���� ����
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void MyInit()
//{
//	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 10.0 }; //�ֺ���
//	GLfloat mat_specular[] = { 10.0, 1.0, 1.0, 0.0 }; //�ݻ籤
//	GLfloat mat_shininess[] = { 10.0 }; //����
//	GLfloat light_position[] = { 10.0, 1.0, 10.0, 8.0 }; //���� ��ġ
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
