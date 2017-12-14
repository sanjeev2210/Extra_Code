#include<bits/stdc++.h>
#include<wchar.h>
#include<locale.h>
int main()
{
    freopen("latin.txt","w",stdout);
    setlocale(LC_ALL,"");
    wchar_t c=L'\x43';
    wprintf(L"%lc\n",c);
    fclose(stdout);
    return 0;
}
