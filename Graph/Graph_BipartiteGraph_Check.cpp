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

bool dfs_helper(vector<int>graph[] , int node , int *visited , int parent , int color)
{
    visited[node]=color ;
    trav(nbr,graph[node])
    {
        if(visited[nbr]==0)
        {
            int subprob=dfs_helper(graph,nbr,visited,node,3-color);
            if(subprob==false) return false ;
        }
        else if(nbr!=parent and visited[nbr]==color) return false ;
    }
    return true ;
}

bool dfs(vector<int> graph[] , int N)
{
    int visited[N]={0};
    int color=1 ;
    return dfs_helper(graph,0,visited,-1,color);
}

int main()
{
    FIO
    int n,m ;
    cin>>n>>m ;
    vector<int> graph[n];
    while(m--)
    {
        int x,y ;
        cin>>x>>y ;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    cout<<dfs(graph,n); 
    return 0;
}
