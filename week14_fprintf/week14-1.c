#include <stdio.h>
int main()
{///�ɮ׫��� FOUT �}���ɮ�(�ɦW,write�Ҧ�)
    FILE * fout = fopen("file.txt","w+");
    printf("Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///�����ɮ�
}
