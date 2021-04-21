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

bool isPossible(int books[] , int n , int m , int curr_min)
{
  int student=1 ;
  int pages=0 ;
  forn(i,n)
  {
    if(pages+books[i]>curr_min)
    {
      student++ ;
      pages=curr_min ;
      if(student>m) return false ;
    }
    else 
    {
      pages+=books[i];
    }
  }
  return true ;
}

int FindPage(int books[] , int n , int m)
{
  ll sum=0 ;
  int s=0 ;
  forn(i,n) sum+=books[i];
  int e=sum ;
  int ans=INT_MAX ;
  while(s<=e)
  {
    int mid=(s+e)/2 ;
    if(isPossible(books,n,m,mid))
    {
      ans=min(ans,mid);
      e=mid-1 ;
    }
    else 
    {
      s=mid+1 ;
    }
    return ans ;
}

int main()
{
    FIO
    int books[]=(10,20,30,40};
    int n=4 , m=2 ;
    cout<<FindPage(books,n,m);
    return 0;
}
