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

vector<vector<int>> graph ;
int n,m ;
int cnt1=0 , cnt0=0 , can=1 ;

void dfs(int idx , vector<int> &visited , int parity=0)
{
    if(visited[idx])
    {
        if(1+parity!=visited[idx])
        {
            can=0 ; 
            return ;
        }
    }

    if(parity==0)
    {
        cnt0++ ;
        visited[idx]=1 ;
    }

    else
    {
        cnt1++ ;
        visited[idx]=2 ;
    }

    trav(el,graph[idx])
    {
        dfs(el,visited,1-parity);
    }

}

int solve()
{
    int ans=1 ;
    vv(int) visited(n+1,0);
    forn1(i,n)
    {
        if(!visited[i])
        {
            cnt0=0 , cnt1=0 , can=1 ;
            dfs(i,visited,0);
            if(!can) return 0 ;
            ans=(ans*(power(2,cnt1)+power(2,cnt0)))%mod ;
        }
    }
    return ans ;
}

int main()
{
    FIO
    tc 
    {
        cin>>n>>m ;
        graph.clear();
        graph.resize(n+1);
        forn(i,m)
        {
            int u,v ;
            cin>>u>>v ;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        cout<<solve()<<endl ;
    }
    return 0;
}
