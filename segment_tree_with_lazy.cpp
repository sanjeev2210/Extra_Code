#include<bits/stdc++.h>
using namespace std;
int tree[100005],lazy[100005],arr[100005];
void build(int node,int first,int last)
{
    if(first==last)
    {
        tree[node]=arr[first];
    }
    else
    {
        int mid=(first+last)/2;
        build((2*node),first,mid);
        build((2*node)+1,mid+1,last);
        tree[node]=tree[(2*node)]+tree[(2*node)+1];
    }
}
void update(int node,int first,int last,int idx,int val)
{
    if(first==last)
    {
        tree[node]+=val;
        arr[first]+=val;
    }
    else
    {
        int mid=(first+last)/2;
        if(first<=idx && idx<=mid)
        {
            update((2*node),first,mid,idx,val);
        }
        else
        {
            update((2*node)+1,mid+1,last,idx,val);
        }
        tree[node]=tree[(2*node)]+tree[(2*node)+1];
    }
}
void lazyupdate(int node,int first,int last,int l,int r,int val)
{
    if(lazy[node]!=0)   // first add the value of lazziness if there is any, then go for update
    {
        tree[node]+=(last-first+1)*lazy[node];
        if(first!=last)
        {
            lazy[(2*node)]+=lazy[node];
            lazy[(2*node)+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(first>last || first>r || l>last) // out of bound
    {
        return;
    }
    if(l<=first && last<=r)  //segment lies in the node
    {
        tree[node]+=(last-first+1)*val;
        if(first!=last) //mark the child node if any as lazy
        {
            lazy[(2*node)]+=val;
            lazy[(2*node)+1]+=val;
        }
        return;
    }
    int mid=(first+last)/2;
    lazyupdate((2*node),first,mid,l,r,val);
    lazyupdate((2*node)+1,mid+1,last,l,r,val);
    tree[node]=tree[(2*node)]+tree[(2*node)+1];
}
int query(int node,int first,int last,int l,int r)
{
    if(r<first || last<l)
    {
        return 0;
    }
    if(l<=first && last<=r)
    {
        return tree[node];
    }
    int mid=(first+last)/2;
    int res1=query((2*node),first,mid,l,r);
    int res2=query((2*node)+1,mid+1,last,l,r);
    return (res1+res2);
}
int lazyquery(int node,int first,int last,int l,int r)
{
    if(first>last || r<first || last<l)
    {
        return 0;
    }
    if(lazy[node]!=0)
    {
        tree[node]+=(last-first+1)*lazy[node];
        if(first!=last)
        {
            lazy[(2*node)]+=lazy[node];
            lazy[(2*node)+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l<=first && last<=r)
    {
        return tree[node];
    }
    int mid=(first+last)/2;
    int res1=lazyquery((2*node),first,mid,l,r);
    int res2=lazyquery((2*node)+1,mid+1,last,l,r);
    return (res1+res2);
}
int main()
{
    int i,j,temp,n;
    memset(lazy,0,sizeof(lazy));
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    /*for(i=1;i<=(2*n)-1+4;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;*/
    int q,qtype,idx,l,r,val;
    cin>>q;
    while(q--)
    {
        cin>>qtype;
        if(qtype==0) //update the element in the array with index idx by value val
        {
            cin>>idx>>val;
            update(1,1,n,idx,val);
        }
        if(qtype==1) //update the range of values in the array with given val
        {
            cin>>l>>r>>val;
            lazyupdate(1,1,n,l,r,val);
        }
        if(qtype==2)  //query for required operation(sum of values in range in this case)
        {
            cin>>l>>r;
            int res=lazyquery(1,1,n,l,r);
            cout<<res<<endl;
        }
    }
    return 0;
}




