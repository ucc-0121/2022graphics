#include <stdio.h>
int main()
{///檔案指標 FOUT 開啟檔案(檔名,write模式)
    FILE * fout = fopen("file.txt","w+");
    printf("Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///關閉檔案
}
