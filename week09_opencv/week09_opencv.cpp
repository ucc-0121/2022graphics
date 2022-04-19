#include <opencv/highgui.h>
int main()
{
    IplImage*img=cvLoadImage("smile.jpg");
    cvShowImage("week09",img);
    cvWaitKey(0);
}
