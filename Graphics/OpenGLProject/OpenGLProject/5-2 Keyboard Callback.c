///***********************************************************************/
///*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(2)             */
///*           �ۼ��� : ���ֿ�          ��¥ : 2020�� 10�� 16��          */
///*                                                                     */
///* ���� ���� : Ű���� �ݹ��Լ��� �̿��Ͽ� q,a,v,r,b Ű�� ����          */
///*            �� �������� ���簢���� �̵���Ű�� r�� b�� ������ �ٲ۴�. */
///*                                                                     */
///***********************************************************************/
//
//#include <GL/glut.h>
//
//GLfloat vertex[4][3] = { {-0.5, -0.5, 0.0}, {0.5, -0.5, 0.0}, {0.5, 0.5, 0.0}, {-0.5, 0.5, 0.0} };
//GLfloat color[3] = { 0.5,0.5,0.5 };
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//}
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3fv(color);
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertex[0]);
//	glVertex3fv(vertex[1]);
//	glVertex3fv(vertex[2]);
//	glVertex3fv(vertex[3]);
//	glEnd();
//	glFlush();
//}
//void MyKeyboard(unsigned char key, int x, int y) {
//
//	/*if (vertex[0][0] >= -1.0 && vertex[0][1] >= -1.0 && vertex[1][0] <= 1.0 && vertex[1][1] >= -1.0 && vertex[2][0] <= 1.0 && vertex[2][1] <= 1.0 && vertex[3][0] <= 1.0&&vertex[3][1] >= -1.0) {*/
//		switch (key) {
//		case 'Q': exit(0); break;
//		case 'q': exit(0); break;
//
//		case 'A': if (vertex[0][0] >= -1.0){
//			vertex[0][0] += -0.1; vertex[1][0] += -0.1; vertex[2][0] += -0.1; vertex[3][0] += -0.1;
//		} break;
//		case 'a': if (vertex[0][0] >= -1.0) {
//			vertex[0][0] += -0.1; vertex[1][0] += -0.1; vertex[2][0] += -0.1; vertex[3][0] += -0.1;
//		}break; //����
//
//		case 'F': if (vertex[1][0] <= 1.0) {
//			vertex[0][0] += 0.1; vertex[1][0] += 0.1; vertex[2][0] += 0.1; vertex[3][0] += 0.1;
//		}break;
//		case 'f':  if (vertex[1][0] <= 1.0) {
//			vertex[0][0] += 0.1; vertex[1][0] += 0.1; vertex[2][0] += 0.1; vertex[3][0] += 0.1;
//		}break; //������
//
//		case 'R': if (vertex[1][1] >= -1.0) {
//			vertex[0][1] += -0.1; vertex[1][1] += -0.1; vertex[2][1] += -0.1; vertex[3][1] += -0.1; color[0] = 1.0; color[1] = 0.0; color[2] = 0.0;
//		} break;
//		case 'r': if (vertex[1][1] >= -1.0) {
//			vertex[0][1] += -0.1; vertex[1][1] += -0.1; vertex[2][1] += -0.1; vertex[3][1] += -0.1; color[0] = 1.0; color[1] = 0.0; color[2] = 0.0;
//		}break; //�Ʒ���
//
//		case 'V':if (vertex[2][1] <= 1.0) {
//			vertex[0][1] += 0.1; vertex[1][1] += 0.1; vertex[2][1] += 0.1; vertex[3][1] += 0.1;
//		}break;
//		case 'v': if (vertex[2][1] <= 1.0) {
//			vertex[0][1] += 0.1; vertex[1][1] += 0.1; vertex[2][1] += 0.1; vertex[3][1] += 0.1;
//		}break; //����
//
//		case 'b':color[0] = 0.0; color[1] = 0.0; color[2] = 1.0; break;
//		case 'B':color[0] = 0.0; color[1] = 0.0; color[2] = 1.0; break;
//
//		case 27: exit(0); break;
//		}
//
//	glutPostRedisplay();
//}
//
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Keyboard Callback");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutKeyboardFunc(MyKeyboard);
//	glutMainLoop();
//	return 0;
//}