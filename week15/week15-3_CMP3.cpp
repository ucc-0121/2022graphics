#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;

int main()
{
    mp3.Load("07013033.mp3");
    mp3.Play();

    printf("等你隨便輸入數字程式就卡住囉: ");
    int N;
    scanf("%d",&N);
}
