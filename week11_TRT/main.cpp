#include <GL/glut.h>

void hand()
{
    glColor3f(0,1,0);
    glutSolidTeapot(0.2);
}
void body()
{
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
     glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
        glPopMatrix();
        glutSwapBuffers();
angle+=0.01;
 }
 int main(int argc, char *argv[])///main()�D�禡 �i����
{
    glutInit(&argc,argv);///��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("week11TRT");///�}GLUT����

    glutDisplayFunc(display);///��ܥΪ��禡
    glutIdleFunc(display);

    glutMainLoop();
 }
