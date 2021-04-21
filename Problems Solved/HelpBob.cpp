// Sum of min(1,i&k) from i=0 to i=N using bit manipulation and binary search in O(logN*logN)

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

ll solve(ll n , ll k)
{
  dp[2]={};
  dp[1]=1 ;
  for(int i=62 ; i>=0 ; i--)
  {
    if(k & 1ll<<i)
    {
      if(n & 1ll<<i)
      {
        dp[0]+=dp[1];
        dp[1]=0 ;
      }
    }
    else 
    {
      dp[0]=2*dp[0];
      if(n & 1ll<<i)
      {
        dp[0]+=dp[1];
      }
    }
  }
  return n+1-(dp[0]+dp[1]);
}

int main()
{
    FIO
    tc 
    {
      ll k,x ;
      cin>>k>>x ;
      int s = 0, e = 1000000
      while(s<e)
      {
        int mid=(s+e+1)/2 ;
        if(solve(mid,k)>x) e=mid-1 ;
        else s=mid ;
      }
      cout<<s<<endl ;
    }
    return 0;
}
