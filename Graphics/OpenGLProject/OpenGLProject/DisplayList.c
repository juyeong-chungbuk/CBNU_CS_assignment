//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//int MyListID; //DisplayList는 정수 ID에 의해 식별
//// Display List 생성
//
//void MyCreateList() {
//	MyListID = glGenLists(1); // DisplayList 선언
//	// 아이디를 가진 리스트 1개를 새로 만들되,
//	// 실행하지 않고 컴파일 완료된 버전을 만든다.
//	glNewList(MyListID, GL_COMPILE);
//	glBegin(GL_POLYGON); // 리스트를 구성하는 함수 나열
//	glColor3f(0.5, 0.5, 0.5);
//	glVertex3f(-0.5, -0.5, 0.0);
//	glVertex3f(0.5, -0.5, 0.0);
//	glVertex3f(0.5, 0.5, 0.0);
//	glVertex3f(-0.5, 0.5, 0.0);
//	glEnd();
//	glEndList();
//}
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glViewport(0, 0, 300, 300);
//	glCallList(MyListID); // 컴파일이 완료된 리스트가 실제로 실행
//	glFlush();
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("OpenGL Example Drawing");
//
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, - 1.0);
//
//	glutDisplayFunc(MyDisplay);
//	MyCreateList(); // Display List 생성
//	glutMainLoop();
//	return 0;
//}