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

vv(pp(int)) graph[501][501];
int mon[501][501];
int n,m ;
vv(pp(int)) spl ;

bool check(int i , int j)
{
    return( i>=1 and i<=n and j>=1 and j<=m);
}

ll solve()
{
    queue<pp(int)> q ;
    vv(vv(bool)) visited( n+1 , vv(bool)(m+1,false) );
    vv(vv(ll)) d( n+1 , vv(ll)(m+1) );

    trav(cell,spl)
    {
        d[cell.ff][cell.ss]=0 ;
        visited[cell.ff][cell.ss]=true ;
        q.push(cell);
    }

    ll ans=0 ;

    while(!q.empty())
    {
        auto v=q.front();
        q.pop();

        trav(u,graph[v.ff][v.ss])
        {
            if( !visited[u.ff][u.ss] )
            {
                visited[u.ff][u.ss]=true ;
                q.push(u);
                d[u.ff][u.ss]=d[v.ff][v.ss]+1 ;
                ans=max(ans,d[u.ff][u.ss]);
            }          
        }

    }

    return ans ;
}

void add_edges()
{
    forn1(i,n)
    {
        forn1(j,m)
        {
            graph[i][j].clear();
            
            int di[]={-1,-1,-1,0,0,1,1,1};
            int dj[]={-1,0,1,-1,1,-1,0,1};

            forn(k,8)
            {
                if(check(i+di[k],j+dj[k])) graph[i][j].pb({i+di[k],j+dj[k]});
            }
        }
    }
}

int main()
{
    FIO
    tc 
    {
        cin>>n>>m ;
        forn1(i,n)
        {
            forn1(j,m) cin>>mon[i][j] , mx=max(mx,mon[i][j]);
        }

        int mx=0 ;

        spl.clear();

        forn1(i,n)
        {
            forn1(j,m) if(mon[i][j]==mx) spl.pb({i,j});
        }

        add_edges();

        cout<<get_ans()<<endl ;

    }
    return 0;
}
