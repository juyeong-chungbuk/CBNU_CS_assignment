//#include <stdlib.h>
//#include <GL/glut.h>
//
//GLUquadricObj *disk = NULL;
//
//void MyDisplay();
//void Reshape(int w, int h);
//void MyInit();
//
//int Mydisk;
//
//void MyCreateList() {
//	Mydisk = glGenLists(1); // DisplayList ����
//
//	glNewList(Mydisk, GL_COMPILE);
//
//	glEnd();
//	glEndList(); //DisplayList ��
//
//}
//
//void MyDisplay()
//{
//	
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glEnable(GL_LIGHTING);
//	glShadeModel(GL_SMOOTH); // �� ������ ���� ������ �����Ͽ� ȥ���Ͽ� ĥ�ϰ� ����
//	
//	disk = gluNewQuadric(); //���ο� Quadric Object����
//
//	gluQuadricDrawStyle(disk, GLU_FILL); // Quadric�� ���� ���ϴ� Draw Style ����  -> LINE�ϸ� Wire����, POINT�ϸ� ����, SILHOUETTE�� ������ �ܺ� �𼭸��� �׸�
//	gluQuadricNormals(disk, GLU_SMOOTH); // �������� ����
//	gluQuadricOrientation(disk, GLU_OUTSIDE); // �������� ���� �� �ܺ� ��� ���� ���� ����
//	gluQuadricTexture(disk, GL_FALSE); // Texture ��ǥ ����� �������� ���� ����
//
//	gluDisk(disk, 0.5, 2.0, 20, 3); //Disk����
//	//glutSolidTorus(0.3, 1.5, 20, 20); //Solid����
//	//glutWireTorus(0.3, 1.5, 20, 20); //Wire����
//	glutSwapBuffers();
////	glCallList(Mydisk); //Display List ȣ��//	gluDeleteQuadric(disk);//
//}
//
//void Reshape(int w, int h) {
//
//	glViewport(10, 10, (GLsizei)w, (GLsizei)h); //�ð� ����
//	glMatrixMode(GL_PROJECTION); //����
//	glLoadIdentity();
//
//	glOrtho(-3.0, 4.0, -3.0 * (GLfloat)h / (GLfloat)w, 4.0 * (GLfloat)h / (GLfloat)w, -50.0, 50.0); //���� ����
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void MyInit()
//{
//	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 10.0 }; //�ֺ���
//	GLfloat mat_specular[] = { 10.0, 10.0, 10.0, 5.0 }; //�ݻ籤
//	GLfloat mat_shininess[] = { 100.0 }; //����
//	GLfloat light_position[] = { -10.0, 8.0, 8.0, 20.0 }; //���� ��ġ
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
//
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600); //������ â ũ��
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Disk Primitives");
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