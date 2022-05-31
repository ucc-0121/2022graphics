#include <windows.h>
#include <stdio.h>
int main()
{///不等待會快速執行下一行，互動性佳
    PlaySound("07013033.wav",NULL,SND_ASYNC);///背景會先撥放此段音樂
    while(1){
        printf("請輸入數字: ");///邊秀出文字
        int n;
        scanf("%d",&n);
        if(n==1)PlaySound("do.wav",NULL,SND_ASYNC);///ASYNC不等待
        if(n==2)PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==3)PlaySound("mi.wav",NULL,SND_ASYNC);
    }
}

