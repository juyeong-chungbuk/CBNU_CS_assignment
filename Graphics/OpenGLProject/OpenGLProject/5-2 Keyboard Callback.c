///***********************************************************************/
///*             HW#4 : Callback 프로그래밍  - 키보드콜백(2)             */
///*           작성자 : 신주영          날짜 : 2020년 10월 16일          */
///*                                                                     */
///* 문제 정의 : 키보드 콜백함수를 이용하여 q,a,v,r,b 키를 통해          */
///*            각 방향으로 정사각형을 이동시키고 r과 b는 색상을 바꾼다. */
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
//		}break; //왼쪽
//
//		case 'F': if (vertex[1][0] <= 1.0) {
//			vertex[0][0] += 0.1; vertex[1][0] += 0.1; vertex[2][0] += 0.1; vertex[3][0] += 0.1;
//		}break;
//		case 'f':  if (vertex[1][0] <= 1.0) {
//			vertex[0][0] += 0.1; vertex[1][0] += 0.1; vertex[2][0] += 0.1; vertex[3][0] += 0.1;
//		}break; //오른쪽
//
//		case 'R': if (vertex[1][1] >= -1.0) {
//			vertex[0][1] += -0.1; vertex[1][1] += -0.1; vertex[2][1] += -0.1; vertex[3][1] += -0.1; color[0] = 1.0; color[1] = 0.0; color[2] = 0.0;
//		} break;
//		case 'r': if (vertex[1][1] >= -1.0) {
//			vertex[0][1] += -0.1; vertex[1][1] += -0.1; vertex[2][1] += -0.1; vertex[3][1] += -0.1; color[0] = 1.0; color[1] = 0.0; color[2] = 0.0;
//		}break; //아래쪽
//
//		case 'V':if (vertex[2][1] <= 1.0) {
//			vertex[0][1] += 0.1; vertex[1][1] += 0.1; vertex[2][1] += 0.1; vertex[3][1] += 0.1;
//		}break;
//		case 'v': if (vertex[2][1] <= 1.0) {
//			vertex[0][1] += 0.1; vertex[1][1] += 0.1; vertex[2][1] += 0.1; vertex[3][1] += 0.1;
//		}break; //위쪽
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