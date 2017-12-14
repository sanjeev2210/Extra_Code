#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<wchar.h>
int main()
{
    setlocale(LC_ALL,"en_US.utf8");
    wchar_t c=L'\x216d';
    char mb[MB_CUR_MAX+1];
    printf("%d\n",MB_CUR_MAX);
    int len=wctomb(mb,c);
    mb[len]='\0';
    wprintf("UTF-8 char: %s\n",mb);
    return 0;
}