#include <GL/glut.h>
#include <stdio.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);

    glutSwapBuffers();
 }
 void keyboard( unsigned char key,int x,int y)
 {
    printf("�A���U�F%c �b%d %d�y��\n",key,x,y);
 }
 int main(int argc, char *argv[])//main()�D�禡 �i����
 {
    glutInit(&argc,argv);//��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//���w�İ�+3D�`�ץ\��
    glutCreateWindow("week05");//�}GLUT����

    glutDisplayFunc(display);//��ܥΪ��禡
    glutKeyboardFunc(keyboard);
    glutMainLoop();
 }
