#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define tc ll tc; cin>>tc; for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof  pop_front
#define endl "\n"
#define umap unordered_map
#define mp make_pair 
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

int n,m ;
vv(int) graph[100005],dep(100005);
int par[100005][22];

void sparse_table(int current , int parent)
{
    par[current][0]=parent ;
    forn1(j,22)
    {
        par[current][j]=par[par[current][j-1]][j-1];
    }
    trav(x,graph[current])
    {
        if(x!=parent)
        {
            sparse_table(x,current);
        }
    }

}

int LCA_using_depth(int u , int v)
{
    if(u==v) return u ;
    if(dep[u]<dep[v]) swap(u,v);
    int diff=dep[u]-dep[v] ;
    for(int i=21 ; i>=0 ; i--)
    {
        if((diff>>i) & 1) u=par[u][i] ;
    }
    if(u==v) return u ;
    for(int i=21 ; i>=0 ; i--)
    {
        u=par[u][i];
        v=par[v][i];
    }
    return par[u][0];
}

int main()
{
    FIO
    //execution
    return 0 ;
}
