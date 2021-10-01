///*************************************************************/
///*                 HW#3 : 3D 가스켓 프로그램                 */
///*         작성자 : 신주영      날짜 : 2020년 10월 11일      */
///*                                                           */                                                     
///* 문제 정의 : 각 점들의 중점을 구하는 과정을 반복하여       */
///*  삼각형 속에 삼각형이 반복되는 구조를 사면체로 만든다.    */                                              
///*************************************************************/
//
//#include<windows.h>
//#include <GL/glut.h>
//
//GLfloat v[4][3] = { {0.25, 0.0, 0.0}, {0.0,1.25,-0.5}, {-1.0,-0.5, 0.0}, {1.0,-0.5,-0.75}}; //사면체를 위한 점
//GLfloat color[4][3] = { {0.0,1.0,0.0}, {1.0,1.0,0.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0} }; //색깔 설정
//
//int n = 3; //반복을 위한 전역변수
//
//void triangle(GLfloat *x, GLfloat *y, GLfloat *z) //마지막 호출
//{
//	glVertex3fv(x);
//	glVertex3fv(y);
//	glVertex3fv(z); //x, y, z의 좌표 점 찍기
//}
//
//void tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d) //divide_tetra에서 호출됨
//{
//	glColor3fv(color[0]); //전역변수로 선언한 색깔 배열 0~3까지 대입
//	triangle(a, b, c); //점을 이용하여 점을 찍는 함수 호출
//	glColor3fv(color[1]);
//	triangle(a, c, d);
//	glColor3fv(color[2]);
//	triangle(a, d, b);
//	glColor3fv(color[3]);
//	triangle(b, d, c);
//}
//
//void divide(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int n) //display에서 호출
//{                  //    v[0]        v[1]        v[2]        v[3]
//	GLfloat p[6][3] = { {0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0} }; //0으로 초기화
//	int i, j;
//
//	if (n > 0){ //n이 0보다 클때만
//		for (j = 0; j < 3; j++) { //각각 x, y, z좌표에 따라 중점을 구함
//			p[0][j] = (a[j] + b[j]) / 2; 
//			p[1][j] = (a[j] + c[j]) / 2;
//			p[2][j] = (a[j] + d[j]) / 2;
//			p[3][j] = (b[j] + c[j]) / 2;
//			p[4][j] = (c[j] + d[j]) / 2;
//			p[5][j] = (b[j] + d[j]) / 2;  //6개의 중점 만들기
//		}
//
//	divide(a, p[0], p[1], p[2], --n);
//	divide(p[0], b, p[3], p[5], n);
//	divide(p[1], p[3], c, p[4], --n);
//	divide(p[2], p[5], p[4], d, n--); //재귀 함수를 이용하여 4개의 면 생성
//	}
//	 //n이 감소돼서 0이하가 되면
//
//	else tetra(a, b, c, d); //사면체 생성
//}
//
//void Mydisplay(void) //2번째 호출
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glBegin(GL_TRIANGLES); //삼각형 만들기
//
//	divide(v[0], v[1], v[2], v[3], n); //4개의 점을 분할해서 4개의 사면체 생성
//
//	glEnd();
//	glFlush();
//}
//
//void reshapeCallback(int w, int h) //1번째 호출
//{
//	glViewport(0, 0, (GLfloat)w, (GLfloat)h); //뷰폿설정
//
//	glMatrixMode(GL_PROJECTION); //투영
//	glLoadIdentity();
//
//	glOrtho(-2.0, 2.0, -2.5*(GLfloat)h / (GLfloat)w, 2.0*(GLfloat)h / (GLfloat)w, -1.0, 1.0); //가시부피 설정
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
//	glutReshapeFunc(reshapeCallback); //Reshape Callback함수 호출
//	glutDisplayFunc(Mydisplay); //Mydisplay함수 호출
//
//	glEnable(GL_DEPTH_TEST); 
//
//	glutMainLoop();
//	return 0;
//}