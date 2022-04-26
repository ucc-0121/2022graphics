#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
GLUquadric * sphere = NULL;///����,����2������
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///���ਤ��
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90,1,0,0);
        glRotatef(angle,0,0,1);
        gluQuadricTexture(sphere,1);
        gluSphere(sphere,1,30,30);
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01;///�C����@��DISPLAY�[�@��
 }
 int main(int argc, char *argv[])///main()�D�禡 �i����
 {
    glutInit(&argc,argv);///��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("week10texturebackground");///�}GLUT����

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);///��ܥΪ��禡
    glutIdleFunc(display);
    myTexture("earth.jpg");
    sphere=gluNewQuadric();///�ǳƦn2������
    glutMainLoop();
 }
