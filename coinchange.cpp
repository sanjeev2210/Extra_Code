#include<bits/stdc++.h>

#define gc getchar   //use getchar_unlocked if using linux else in windows use getchar and putchar
#define pc putchar
#define ll long long int
#define li long int
#define ull unsigned long long int
#define ul unsigned long int

#define mod7 1000000007
#define mod9 1000000009

#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define sc64(t) scanf("%I64d",&t)
#define scch(t) scanf("%c",&t)
#define scstr(t) scanf("%s",t)

#define mem(a,b) memset(a,(b),sizeof(a))
#define rep(i,intl,n) for(int i=intl;i<n;i++)
#define rrep(i,intl,n) for(int i=n;i>=intl;i--)
#define all(temp) temp.begin(),temp.end()
#define rall(temp) temp.end(),temp.begin()

#define vi vector<int>
#define vll vector<ll,ll>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vp vector<pi>
#define mpii map<int,int>
#define maxpr_que priority_queue<int>
#define minpr_que priority_queue<int,vector<int>,greater<int> >
#define vec(mat,n,m) vector<vector<int> > mat(n,vector<int>(m,-1))
#define sz(a) int((a).size())
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define foritr(it,c) for(auto it=c.begin();it!=c.end();it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define clr clear()
#define gcd(a,b) __gcd(a,b)
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)

#define py acos(-1.0)
#define INF (int)1e9
#define EPS 1e-9
#define pie 3.1415926535897932384626433832795

using namespace std;

//Fast input

int scan_d()		{register int c=gc();int x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
li scan_ld()		{register li c=gc();li x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
ll scan_lld()		{register ll c=gc();ll x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
ull scan_llu()		{register ull c=gc();ull x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}

//Fast output

//no line break
void print_d(int n)     	{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(li n)     	{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(ll n)     	{if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(ull n)     	{int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)     	{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void println_ld(li n)     	{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void println_lld(ll n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void println_llu(ull n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//lcm
ll lcm(ll a, ll b) {return a * (b / gcd(a, b));}
//modular exponentiation ((a^b)%c))
ll modexpo(ll a,ll b,ll c){ ll x=1,y=a; while(b){ if(b%2){ x=(x*y)%c; } y=(y*y)%c; b/=2; } return x%c;}
//multiplication modular  ((a*b)%c)
ll mulmod(ll a,ll b, ll c){ ll x=0,y=a%c; while(b){ if(b%2){x=(x+y)%c;} y=(y*2)%c; b/=2;} return x%c;}



int main()
{
    ll n,m,i,j;
    scd(n);scd(m);
    ll arr[m+1],dp[m+1][n+1];
    rep(i,1,m+1)
    {
    	scd(arr[i]);
    }
    mem(dp,0);
    rep(i,0,m+1)  //no. of ways of getting change for coin 0 of denomination i is always 1;
    {
    	dp[i][0]=1;
    }
    //cout<<"working";
    rep(i,1,m+1)
    {
    	rep(j,1,n+1)
    	{
    		dp[i][j]=(j-arr[i]>=0)?(dp[i-1][j]+dp[i][j-arr[i]]):dp[i-1][j];
    		//cout<<dp[i][j]<<" ";
    	}
    	//cout<<endl;
    }
   	print_d(dp[m][n]);
   	return 0;
}
