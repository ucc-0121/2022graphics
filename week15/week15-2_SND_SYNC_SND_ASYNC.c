#include <windows.h>
#include <stdio.h>
int main()
{///�����ݷ|�ֳt����U�@��A���ʩʨ�
    PlaySound("07013033.wav",NULL,SND_ASYNC);///�I���|�����񦹬q����
    while(1){
        printf("�п�J�Ʀr: ");///��q�X��r
        int n;
        scanf("%d",&n);
        if(n==1)PlaySound("do.wav",NULL,SND_ASYNC);///ASYNC������
        if(n==2)PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==3)PlaySound("mi.wav",NULL,SND_ASYNC);
    }
}

