#include <GL/glut.h>
float angle=0,oldX=0;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
 }

 void motion(int x,int y)
 {
    angle += (x-oldX);
    oldX=x;
    display();
 }
  void mouse(int button,int state,int x,int y)
 {

    oldX=x;
 }
 int main(int argc, char *argv[])//main()�D�禡 �i����
 {
    glutInit(&argc,argv);//��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//���w�İ�+3D�`�ץ\��
    glutCreateWindow("��04�g���{����!!");//�}GLUT����

    glutDisplayFunc(display);//��ܥΪ��禡
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    glutMainLoop();
 }
