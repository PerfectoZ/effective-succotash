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

int seg[200000] , a[100000];

using namespace std;

void build_tree(int node , int l , int r)
{
  if(l==r) { seg[node]=a[l] ; return ; }
  int mid=(l+r)/2 ;
  build_tree(2*node , l , mid);
  build_tree(2*node , mid+1 , r);
  int level=log2(r-l+1);
  if(level&1) seg[node] = seg[2*node] | seg[2*node+1] ;
  else seg[node] = seg[2*node] ^ seg[2*node+1] ;
}

void update_tree(int node , int i , int l , int r , int val)
{
  if(i<l or i>r) return ;
  if(l==r) { seg[node]=val ; return ; }
  int mid=(l+r)/2 ;
  update_tree(2*node+1 , i , l , mid , val);
  update_tree(2*node , i , mid+1 , r , val);
  int level=log2(r-l+1);
  if(level&1) seg[node] = seg[2*node] | seg[2*node+1] ;
  else seg[node] = seg[2*node] ^ seg[2*node+1] ;
}

int main()
{
  //execute 
  return 0;
}
  
