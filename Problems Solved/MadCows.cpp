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

bool CanPlaceCows(int stalls[] , int n , int c , int min_sep)
{
  int last_cow=stalls[0];
  int cnt=1 ;
  for (int i=1 ; i<n ; i++)
  {
    if(stalls[i]-last_cow>=min_sep)
    {
      last_cow=stalls[i];
      cnt++ ;
      if(cnt==c) return true ;
    }
  }
  return false ;
}

int main()
{
    FIO
    int stalls[]={1,2,4,8,9};
    int n=5 ;
    int cows=3 ;
    int s=0 , e=stalls[n-1]-stalls[0];
    int ans=0 ;
    while(s<=e)
    {
      int mid=(s+e)/2 ;
      bool cowsrakhpaye=CanPlaceCows(stalls,n,cows,mid);
      if(cowsrakhpaye)
      {
        ans=mid ;
        s=mid+1 ;
      }
      else
      {
        e=mid-1 ;
      }
    }
      cout<<ans<<endl ;
    return 0;
}
