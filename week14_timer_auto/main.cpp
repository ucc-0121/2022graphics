///week14_timer
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){
    printf("我起床囉!  %d\n",t);
    PlaySound("do.wav",NULL,SND_ASYNC);
    glutTimerFunc(2000,timer,t+1);
}
void display()
{
}
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_timer");

    glutTimerFunc(5000,timer,0);///設定:5秒後,才叫第0個timer

    glutDisplayFunc(display);
    glutMainLoop();
 }
