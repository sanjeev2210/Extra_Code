#include<bits/stdc++.h>
#include<locale.h>
#include<wchar.h>
#define mp make_pair
using namespace std;

map<char,pair<wchar_t,wchar_t> > homochar;
map<int,wchar_t> homospace;

void define_homo_character()
{
	homochar['-']=mp(L'\x2d',L'\x2010');
	homochar[';']=mp(L'\x3b',L'\x037e');
	homochar['C']=mp(L'\x43',L'\x216d');
	homochar['D']=mp(L'\x44',L'\x216e');
	homochar['K']=mp(L'\x4b',L'\x212a');
	homochar['L']=mp(L'\x4c',L'\x216c');
	homochar['M']=mp(L'\x4d',L'\x216f');
	homochar['V']=mp(L'\x56',L'\x2164');
	homochar['X']=mp(L'\x58',L'\x2169');
	homochar['c']=mp(L'\x63',L'\x217d');
	homochar['d']=mp(L'\x64',L'\x217e');
	homochar['i']=mp(L'\x69',L'\x2170');
	homochar['j']=mp(L'\x6a',L'\x458');
	homochar['l']=mp(L'\x6c',L'\x217c');
	homochar['v']=mp(L'\x76',L'\x2174');
	homochar['x']=mp(L'\x78',L'\x2179');
}

void define_homo_space()
{
	homospace[0]=L'\x20';
	homospace[1]=L'\x2000';
	homospace[2]=L'\x2004';
	homospace[3]=L'\x2005';
	homospace[4]=L'\x2008';
	homospace[5]=L'\x2009';
	homospace[6]=L'\x202f';
	homospace[7]=L'\x205f';
}

bool checkbit(string str,int pos)
{
    if(str.size()!=0)
        return true;
    else
        return false;
}

wchar_t get_duplicate_hex(char ch)
{
	map<char,pair<wchar_t,wchar_t> >::iterator it;
	it=homochar.find(ch);
	return (it->second.second);
}

wchar_t search_space_type(char ch,int start,int end)
{
	return L'\x43';
}

bool search_char(char ch)
{
	if(homochar.find(ch)==homochar.end())
	{
		return false;
	}
	return true;
	
}

void print_homo_char()
{
	map<char,pair<wchar_t,wchar_t> >::iterator itr;
	for(itr=homochar.begin();itr!=homochar.end();itr++)
	{
		//cout<<(*itr).first<<endl;
		//printf("%c - ",((*itr).first));
		wprintf(L"%lc",((*itr).second.first));
		wprintf(L"%lc",L'\x20');
		wprintf(L"%lc\n",(itr->second.second));
	}
}

void print_homo_space()
{
	int i=0;
	map<int,wchar_t>::iterator itr;
	/*for(itr=homospace.begin();itr!=homospace.end();itr++);
	{
		wprintf(L"%lc\n",itr->second);
	}*/
	for(i=0;i<8;i++)
	{
		wprintf(L"%lc\n",homospace[i]);
	}
}
int main()
{
	int bitpos=0;
	string watermark;
	setlocale(LC_ALL,"");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	define_homo_character();
	define_homo_space();
	
	//print_homo_char();
	//print_homo_space();
	
	char ch;
	while(scanf(" %c",&ch)!=EOF)
	{
		if(ch==' ')
		{
		
			//wchar_t space_type=search_space_type(ch,bitpos,bitpos+3);
			wprintf(L"%lc ",ch);
			bitpos+=3;
			continue;

		}
		bool result=search_char(ch);            //This is only for homoglyph characters not for spaces. Spaces has been managed above.
		if(!result)
		{
			wprintf(L"%lc",ch);
			continue;
		}
		else
		{
			bool bit_status=1;
			//bool bit_status=checkbit(watermark,bitpos);
			if(!bit_status)
			{
				wprintf(L"%lc",ch);
			}
			else
			{
				wchar_t dupl_ch=get_duplicate_hex(ch);
				wprintf(L"%lc",dupl_ch);
				bitpos++;
			}
		}
	}
	fclose(stdout);
	return 0;
}






















