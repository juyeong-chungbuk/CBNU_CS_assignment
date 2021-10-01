//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	GLfloat Size[2];
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
//	glPointSize(Size[0] * 3);
//	glBegin(GL_POINTS);
//	glVertex3f(-0.8, 0.78, 0.0); /*맨밑*/ glVertex3f(-0.9, 0.85, 0.0); /*왼쪽밑*/ glVertex3f(-0.9, 0.9, 0.0); /*왼쪽위*/
//	glVertex3f(-0.85, 0.95, 0.0); /*왼쪽 꼭지*/ glVertex3f(-0.8, 0.9, 0.0); /*가운데파인곳*/ glVertex3f(-0.75, 0.95, 0.0); /*오른쪽 꼭지*/
//	glVertex3f(-0.7, 0.9, 0.0); /*오른쪽위*/ glVertex3f(-0.7, 0.85, 0.0); /*오른쪽밑*/
//
//	glVertex3f(-0.5, 0.78, 0.0); /*맨밑*/ glVertex3f(-0.6, 0.85, 0.0); /*왼쪽밑*/ glVertex3f(-0.6, 0.9, 0.0); /*왼쪽위*/
//	glVertex3f(-0.55, 0.95, 0.0); /*왼쪽 꼭지*/ glVertex3f(-0.5, 0.9, 0.0); /*가운데파인곳*/ glVertex3f(-0.45, 0.95, 0.0); /*오른쪽 꼭지*/
//	glVertex3f(-0.4, 0.9, 0.0); /*오른쪽위*/ glVertex3f(-0.4, 0.85, 0.0); /*오른쪽밑*/
//
//	glVertex3f(-0.2, 0.78, 0.0); /*맨밑*/ glVertex3f(-0.3, 0.85, 0.0); /*왼쪽밑*/ glVertex3f(-0.3, 0.9, 0.0); /*왼쪽위*/
//	glVertex3f(-0.25, 0.95, 0.0); /*왼쪽 꼭지*/ glVertex3f(-0.2, 0.9, 0.0); /*가운데파인곳*/ glVertex3f(-0.15, 0.95, 0.0); /*오른쪽 꼭지*/
//	glVertex3f(-0.1, 0.9, 0.0); /*오른쪽위*/ glVertex3f(-0.1, 0.85, 0.0); /*오른쪽밑*/
//
//	glVertex3f(0.1, 0.78, 0.0); /*맨밑*/ glVertex3f(0.0, 0.85, 0.0); /*왼쪽밑*/ glVertex3f(0.0, 0.9, 0.0); /*왼쪽위*/
//	glVertex3f(0.05, 0.95, 0.0); /*왼쪽 꼭지*/ glVertex3f(0.1, 0.9, 0.0); /*가운데파인곳*/ glVertex3f(0.15, 0.95, 0.0); /*오른쪽 꼭지*/
//	glVertex3f(0.2, 0.9, 0.0); /*오른쪽위*/ glVertex3f(0.2, 0.85, 0.0); /*오른쪽밑*/
//
//	glVertex3f(0.4, 0.78, 0.0); /*맨밑*/ glVertex3f(0.3, 0.85, 0.0); /*왼쪽밑*/ glVertex3f(0.3, 0.9, 0.0); /*왼쪽위*/
//	glVertex3f(0.35, 0.95, 0.0); /*왼쪽 꼭지*/ glVertex3f(0.4, 0.9, 0.0); /*가운데파인곳*/ glVertex3f(0.45, 0.95, 0.0); /*오른쪽 꼭지*/
//	glVertex3f(0.5, 0.9, 0.0); /*오른쪽위*/ glVertex3f(0.5, 0.85, 0.0); /*오른쪽밑*/
//
//	glVertex3f(0.7, 0.78, 0.0); /*맨밑*/ glVertex3f(0.6, 0.85, 0.0); /*왼쪽밑*/ glVertex3f(0.6, 0.9, 0.0); /*왼쪽위*/
//	glVertex3f(0.65, 0.95, 0.0); /*왼쪽 꼭지*/ glVertex3f(0.7, 0.9, 0.0); /*가운데파인곳*/ glVertex3f(0.75, 0.95, 0.0); /*오른쪽 꼭지*/
//	glVertex3f(0.8, 0.9, 0.0); /*오른쪽위*/ glVertex3f(0.8, 0.85, 0.0); /*오른쪽밑*/
//
//
//	glBegin(GL_LINES);
//	glVertex3f(0.0, -0.5, 0.0); glVertex3f(-0.5, 0.0, 0.0); //	glVertex3f(0.0, 0.5, 0.0); glVertex3f(0.5, 0.5, 0.0); ////
//	glBegin(GL_LINE_STRIP);
//	glVertex3f(-0.75, 0.5, 0.0); glVertex3f(-0.5, 0.25, 0.0); 
//	glVertex3f(0.0, 0.5, 0.0); glVertex3f(0.5, 0.25, 0.0);
//
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(-0.75, 0.5, 0.0); glVertex3f(-0.5, 0.25, 0.0);
//	glVertex3f(-0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);
//	glVertex3f(0.0, 0.5, 0.0); glVertex3f(0.5, 0.25, 0.0);
//
//	glBegin(GL_TRIANGLES);
//	glVertex3f(0.0, 0.5, 0.0); glVertex3f(0.5, -0.5, 0.0); 	glVertex3f(-0.5, -0.5, 0.0);
//
//	glBegin(GL_TRIANGLE_STRIP);
//	glVertex3f(0.9, 0.2, 0.0); glVertex3f(0.75, 0.5, 0.0); glVertex3f(0.5, 0.1, 0.0);
//	glVertex3f(0.25, 0.25, 0.0); glVertex3f(0.0, 0.0, 0.0); glVertex3f(-0.25, -0.25, 0.0);
//	glVertex3f(-0.5, -0.5, 0.0);
//
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex3f(0.0, 0.0, 0.0); 
//	glVertex3f(0.1, 0.5, 0.0); glVertex3f(0.2, 0.53, 0.0); glVertex3f(0.3, 0.45, 0.0); 
//	glVertex3f(0.4, 0.4, 0.0); glVertex3f(0.5, 0.2, 0.0);
//
//	glBegin(GL_POLYGON);
//	glVertex3f(0.0, 1.0, 0.0); glVertex3f(-1.0, 0.5, 0.0);
//	glVertex3f(-1.0, -0.5, 0.0); glVertex3f(0.0, -1.0, 0.0);
//	glVertex3f(1.0, -0.5, 0.0); glVertex3f(1.0, 0.5, 0.0);
//
//	glBegin(GL_QUADS);
//	glVertex3f(-0.5, -0.5, 0.0); glVertex3f(-0.5, 0.5, 0.0);
//	glVertex3f(0.5, 0.5, 0.0); glVertex3f(0.5, -0.5, 0.0);
//
//	glBegin(GL_QUAD_STRIP);
//	glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.1, 0.2, 0.0);
//	glVertex3f(0.2, 0.25, 0.0); glVertex3f(0.15, -0.1, 0.0);
//	glVertex3f(0.3, 0.0, 0.0); glVertex3f(0.25, -0.2, 0.0);
//	glVertex3f(0.35, -0.15, 0.0); glVertex3f(0.32, -0.18, 0.0);
//
//	glEnd();
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