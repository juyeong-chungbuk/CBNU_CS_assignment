///*************************************************************/
///*                 HW#3 : 3D ������ ���α׷�                 */
///*         �ۼ��� : ���ֿ�      ��¥ : 2020�� 10�� 11��      */
///*                                                           */                                                     
///* ���� ���� : �� ������ ������ ���ϴ� ������ �ݺ��Ͽ�       */
///*  �ﰢ�� �ӿ� �ﰢ���� �ݺ��Ǵ� ������ ���ü�� �����.    */                                              
///*************************************************************/
//
//#include<windows.h>
//#include <GL/glut.h>
//
//GLfloat v[4][3] = { {0.25, 0.0, 0.0}, {0.0,1.25,-0.5}, {-1.0,-0.5, 0.0}, {1.0,-0.5,-0.75}}; //���ü�� ���� ��
//GLfloat color[4][3] = { {0.0,1.0,0.0}, {1.0,1.0,0.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0} }; //���� ����
//
//int n = 3; //�ݺ��� ���� ��������
//
//void triangle(GLfloat *x, GLfloat *y, GLfloat *z) //������ ȣ��
//{
//	glVertex3fv(x);
//	glVertex3fv(y);
//	glVertex3fv(z); //x, y, z�� ��ǥ �� ���
//}
//
//void tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d) //divide_tetra���� ȣ���
//{
//	glColor3fv(color[0]); //���������� ������ ���� �迭 0~3���� ����
//	triangle(a, b, c); //���� �̿��Ͽ� ���� ��� �Լ� ȣ��
//	glColor3fv(color[1]);
//	triangle(a, c, d);
//	glColor3fv(color[2]);
//	triangle(a, d, b);
//	glColor3fv(color[3]);
//	triangle(b, d, c);
//}
//
//void divide(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int n) //display���� ȣ��
//{                  //    v[0]        v[1]        v[2]        v[3]
//	GLfloat p[6][3] = { {0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0} }; //0���� �ʱ�ȭ
//	int i, j;
//
//	if (n > 0){ //n�� 0���� Ŭ����
//		for (j = 0; j < 3; j++) { //���� x, y, z��ǥ�� ���� ������ ����
//			p[0][j] = (a[j] + b[j]) / 2; 
//			p[1][j] = (a[j] + c[j]) / 2;
//			p[2][j] = (a[j] + d[j]) / 2;
//			p[3][j] = (b[j] + c[j]) / 2;
//			p[4][j] = (c[j] + d[j]) / 2;
//			p[5][j] = (b[j] + d[j]) / 2;  //6���� ���� �����
//		}
//
//	divide(a, p[0], p[1], p[2], --n);
//	divide(p[0], b, p[3], p[5], n);
//	divide(p[1], p[3], c, p[4], --n);
//	divide(p[2], p[5], p[4], d, n--); //��� �Լ��� �̿��Ͽ� 4���� �� ����
//	}
//	 //n�� ���ҵż� 0���ϰ� �Ǹ�
//
//	else tetra(a, b, c, d); //���ü ����
//}
//
//void Mydisplay(void) //2��° ȣ��
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glBegin(GL_TRIANGLES); //�ﰢ�� �����
//
//	divide(v[0], v[1], v[2], v[3], n); //4���� ���� �����ؼ� 4���� ���ü ����
//
//	glEnd();
//	glFlush();
//}
//
//void reshapeCallback(int w, int h) //1��° ȣ��
//{
//	glViewport(0, 0, (GLfloat)w, (GLfloat)h); //��������
//
//	glMatrixMode(GL_PROJECTION); //����
//	glLoadIdentity();
//
//	glOrtho(-2.0, 2.0, -2.5*(GLfloat)h / (GLfloat)w, 2.0*(GLfloat)h / (GLfloat)w, -1.0, 1.0); //���ú��� ����
//
//	glMatrixMode(GL_MODELVIEW);
//	glutPostRedisplay();
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("3D tetrahedron Gasket");
//
//	glutReshapeFunc(reshapeCallback); //Reshape Callback�Լ� ȣ��
//	glutDisplayFunc(Mydisplay); //Mydisplay�Լ� ȣ��
//
//	glEnable(GL_DEPTH_TEST); 
//
//	glutMainLoop();
//	return 0;
//}