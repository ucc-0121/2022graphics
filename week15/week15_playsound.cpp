#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");///檔案不存在(有錯誤聲)

    PlaySound("07013033.wav",NULL,SND_SYNC);
    printf("PlaySound()之後\n");
}
