#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()���e\n");///�ɮפ��s�b(�����~�n)

    PlaySound("07013033.wav",NULL,SND_SYNC);
    printf("PlaySound()����\n");
}
