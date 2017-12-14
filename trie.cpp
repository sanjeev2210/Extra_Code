#include<bits/stdc++.h>
using namespace std;
struct trienode
{
    bool leafnode;
    struct trienode* tarr[26];
};
typedef struct trienode trienode;
trienode* createnode()
{
    trienode* newnode=(trienode*)malloc(sizeof(trienode));
    newnode->leafnode=false;
    for(int i=0;i<26;i++)
    {
        newnode->tarr[i]=0;
    }
}
void inserttnode(trienode *root,string str)
{
    int len,i,j;
    len=str.size();
    trienode* ptrnode=root;
    for(i=0;i<len;i++)
    {
        int idx=(str[i]-'a');
        if(!ptrnode->tarr[idx])
        {
            ptrnode->tarr[idx]=createnode();
        }
        ptrnode=ptrnode->tarr[idx];
    }
    ptrnode->leafnode=true;
}
bool searchstr(trienode *root,string key)
{
    int len,i,j;
    len=key.size();
    trienode *ptrnode=root;
    for(i=0;i<len;i++)
    {
        int idx=int(key[i]-'a');
        if(!ptrnode->tarr[idx])
        {
            return false;
        }
        ptrnode=ptrnode->tarr[idx];
    }
    return (ptrnode!=NULL && ptrnode->leafnode);
}
int main()
{
    int n,i,j;
    string str[1000];
    cin>>n;
    trienode *root=createnode();
    for(i=0;i<n;i++)
    {
        cin>>str[i];
        inserttnode(root,str[i]);
    }
    string strtemp;
    int q;
    for(cin>>q;q;q--)
    {
        cin>>strtemp;
        bool val=searchstr(root,strtemp);
        if(val)
        {
            cout<<"the string exist\n";
        }
        else
        {
            cout<<"the string not found in the trie\n";
        }
    }
    return 0;
}
