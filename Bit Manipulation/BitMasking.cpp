#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc ll tc; cin>>tc ; cin.ignore(5,'\n'); for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof  pop_front
#define endl "\n"
#define umap unordered_map
#define pq priority_queue
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define bp ll kkk; cin >>kkk;
#define dbgArr(a,n) cout<<"Array "<<#a<<endl; for(ll i=0 ; i<n ; i++) cout<<a[i]<<" "; cout<<endl;
#define forn(i,n) for(ll i=0 ; i<n ; i++)
#define forn1(i,n) for(ll i=1 ; i<=n ; i++)
#define arr(a,n) for(ll i=0;i<n;i++){ cin>>a[i]; }
#define arr1(a,n) for(ll i=1;i<=n;i++){ cin>>a[i]; }
#define file freopen("inp.in","r",stdin); freopen("outp.out","w",stdout)
#define print cout<<"Case #"<<number<<": "
#define all(x) x.begin(), x.end()
#define trav(x, a) for(auto &x: a)
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

using namespace std;

int CountBitsFast(int n)
{
  int Count=0 ;
  while(n)
  {
    count++ ;
    n= n & (n-1);
  }
  return Count ;
}

int GetIthBit(int n , int i)
{
  return (n&(1<<i))!=0 ? 1:0 ;
}

int SetIthBit(int n , int i)
{
  int mask=1<<i ;
  return (n|mask);
}

int ClearIthBit(int n , int i)
{
  int mask=1<<i ;
  mask= ~mask
  return (n & mask) ;
}

int ClearLastIBits(int n , int i)
{
  int mask=(-1<<i);
  return n & mask ;
}

int ClearRangeItoJBits(int n , int i , int j)
{
  int a=(~0)<<(j+1);
  int b=(1<<i)-1 ;
  int mask=a|b ;
  return n & mask ;
}

int replacebits(int n , int i , int j , int m)
{
  int n_ = ClearRangeItoJBits(n , i , j);
  return (n_ | (mask<<i));
}

void filterchars(string s , int n)
{
  int i=0 ;
  while(n>0)
  {
    (n&1) ? cout<<a[i] : cout<<"" ;
    n=n>>1 ;
    i++ ;
  }
}

void generatesubsets(string s)
{
   int n=s.length();
   int range=(1<<n)-1 ;
   for (int i=0 ; i<=range ; i++)
   {
    filterchars(s,i);
   }
}

int main()
{
 int N ;
 cin>>N ;
 cout<<CountBitsFast(N)<<" " ;
 cout<<GetIthBit(N,5)<<" " ;
 ClearIthBit(N,5);
 cout<<N<<" " ;
 SetIthBit(N,5);
 cout<<N<<" " ;
 string S ;
 cin>>S ;
 generatesubsets(S);
 return 0;
 }
