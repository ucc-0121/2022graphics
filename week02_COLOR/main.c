//step02-1 10行最精簡的GLUT程式
//先全刪除，目標5-10行，寫完
#include <GL/glut.h>

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(1,1,0);
     giutSolidTeapot(0.3);
     glutSwapBuffers();
}
int main(int )
