#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;

int main()
{
    mp3.Load("07013033.mp3");
    mp3.Play();

    printf("���A�H�K��J�Ʀr�{���N�d���o: ");
    int N;
    scanf("%d",&N);
}
