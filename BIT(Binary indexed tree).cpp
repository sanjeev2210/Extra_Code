#include<bits/stdc++.h>
using namespace std;
int arr[10004],bitree[10004];
void initialize()
{
    memset(bitree,0,sizeof(bitree));
}
int resetrightmost(int n)
{
    return (n&(n-1));
}
void updateidx(int idx,int k,int n)
{
    while(idx<=n)
    {
        bitree[idx]+=k;
        idx=idx+(idx & -idx);
    }
}
int getsum(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=bitree[idx];
        idx=resetrightmost(idx);
    }
    return sum;
}
int main()
{
    int n,i,j,temp,res;
    initialize();
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        updateidx(i+1,arr[i],n);
    }
    int type,q,l,r;
    cin>>q;
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>l>>r;
            res=getsum(l-1);
            res=getsum(r)-res;
            cout<<res<<endl;
        }
        if(type==0)
        {
            int key,index;
            cin>>index>>key;
            updateidx(index+1,key,n);
        }
    }
    return 0;
}
