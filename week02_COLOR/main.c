//step02-1 10��̺�²��GLUT�{��
//�����R���A�ؼ�5-10��A�g��
#include <GL/glut.h>

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(1,1,0);
     giutSolidTeapot(0.3);
     glutSwapBuffers();
}
int main(int )
