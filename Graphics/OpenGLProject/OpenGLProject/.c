//#include <GL/glut.h>
//#include <GL/glu.h>
//GLfloat MyVertices[8][3] = { {-0.25,-0.25,0.25}, {-0.25,0.25,0.25}, {0.25,0.25,0.25},
//{0.25,-0.25,0.25}, {-0.25,-0.25,-0.25}, {-0.25,0.25,-0.25},
//{0.25,0.25,-0.25}, {0.25,-0.25,-0.25} };
//GLfloat MyColors[8][3] = { {0.2,0.2,0.2}, {1.0,0.0,0.0}, {1.0, 1.0, 0.0}, {0.0,1.0,0.0},
//{0.0,0.0,1.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };
//GLubyte MyVertexList[24] = { 0,3,2,1, 3,7,6,2, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4 };
//// 앞면, 오른쪽면, 아래면(CW), 윗면, 뒷면(CW), 왼쪽면(CW)
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFrontFace(GL_CCW); // Vertex 배열을 반시계방향으로 연결하겠다 : 표면
//	glEnable(GL_CULL_FACE); // 카메라로부터 보이지 않는 면을 숨기겠다
//	glEnableClientState(GL_COLOR_ARRAY); // VertexArray 기능 활성화 : 정점 색
//	glEnableClientState(GL_VERTEX_ARRAY); // VertexArray 기능 활성화 : 정점 좌표
//	glColorPointer(3, GL_FLOAT, 0, MyColors); // Vertex의 색상을 저장한 변수명 MyColors 제시
//	glVertexPointer(3, GL_FLOAT, 0, MyVertices); // Vertex의 좌표를 저장한 변수명 MyVertices 제시
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glRotatef(30.0, 1.0, 1.0, 1.0); // 벡터 (1,1,1)을 회전축으로 하여 반시계방향으로 30도 회전
//	for (GLint i = 0; i < 6; i++)
//		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
////	 정육면체 화면에 그리기
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