///week14_timer
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){
    printf("�_��,�{�b�ɶ�: %d\n",t);
}
void display()
{
}
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_timer");

    glutTimerFunc(1000,timer,1);
    glutTimerFunc(2000,timer,2);
    glutTimerFunc(3000,timer,3);
    glutTimerFunc(4000,timer,4);
    glutTimerFunc(5000,timer,5);
    glutDisplayFunc(display);
    glutMainLoop();
 }