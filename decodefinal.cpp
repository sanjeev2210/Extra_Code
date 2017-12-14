#include<bits/stdc++.h>
#include<wchar.h>
#include<locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL,"");
	freopen("output.txt","r",stdin);
	//freopen("finaldecode.txt","w",stdout);
	wchar_t wc;
	while(wscanf(L"%lc",&wc)!=WEOF)
	{
		wprintf(L"%#x ",wc);
	}
	fclose(stdout);
	return 0;
}
