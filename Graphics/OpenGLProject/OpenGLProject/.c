//#include <GL/glut.h>
//#include <GL/glu.h>
//GLfloat MyVertices[8][3] = { {-0.25,-0.25,0.25}, {-0.25,0.25,0.25}, {0.25,0.25,0.25},
//{0.25,-0.25,0.25}, {-0.25,-0.25,-0.25}, {-0.25,0.25,-0.25},
//{0.25,0.25,-0.25}, {0.25,-0.25,-0.25} };
//GLfloat MyColors[8][3] = { {0.2,0.2,0.2}, {1.0,0.0,0.0}, {1.0, 1.0, 0.0}, {0.0,1.0,0.0},
//{0.0,0.0,1.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };
//GLubyte MyVertexList[24] = { 0,3,2,1, 3,7,6,2, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4 };
//// �ո�, �����ʸ�, �Ʒ���(CW), ����, �޸�(CW), ���ʸ�(CW)
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFrontFace(GL_CCW); // Vertex �迭�� �ݽð�������� �����ϰڴ� : ǥ��
//	glEnable(GL_CULL_FACE); // ī�޶�κ��� ������ �ʴ� ���� ����ڴ�
//	glEnableClientState(GL_COLOR_ARRAY); // VertexArray ��� Ȱ��ȭ : ���� ��
//	glEnableClientState(GL_VERTEX_ARRAY); // VertexArray ��� Ȱ��ȭ : ���� ��ǥ
//	glColorPointer(3, GL_FLOAT, 0, MyColors); // Vertex�� ������ ������ ������ MyColors ����
//	glVertexPointer(3, GL_FLOAT, 0, MyVertices); // Vertex�� ��ǥ�� ������ ������ MyVertices ����
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glRotatef(30.0, 1.0, 1.0, 1.0); // ���� (1,1,1)�� ȸ�������� �Ͽ� �ݽð�������� 30�� ȸ��
//	for (GLint i = 0; i < 6; i++)
//		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
////	 ������ü ȭ�鿡 �׸���
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("My First OpenGL Code");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}