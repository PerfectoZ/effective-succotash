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

vector<int> bellman_ford(int V , int src , int n , vv(vv(int)) edges)
{
    vector<int> dist(V+1,INT_MAX);
    dist[src]=0 ;
    forn(i,V-1)
    {
        trav(edge,edges)
        {
            int x=edge[0];
            int y=edge[1];
            int w=edge[2];
            if(dist[x]!=INT_MAX and dist[x]+w<dist[y]) dist[y]=dist[x]+w ;
        }
    }
    trav(edge,edges)
    {
        int x=edge[0];
        int y=edge[1];
        int w=edge[2];
        if(dist[x]!=INT_MAX and dist[x] + w < dist[y]) 
        {
            exit(0);
        }
    }
}

int main()
{
    FIO
    int n,m ;
    cin>>n>>m ;
    vv(vv(int)) edges ;
    forn(i,m)
    {
        int u,v,w ;
        cin>>u>>v>>w ;
        edges.pb({u,v,w});
    }
    vv(int) distances=bellman_ford(n,1,edges);
    return 0 ;
}
