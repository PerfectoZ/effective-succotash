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

int tme ;
map<int,vector<int>> graph ;
map<int,int> discovery , lowest ;
vector<int> arT ;
vv(pp(int)) bridge ;

void dfs(int current , int parent)
{
    discovery[current] = lowest[current] = tme++ ;
    int childs=0 ;
    trav(child , graph[current])
    {
        if(discovery[child])
        {
            dfs(child,current);
            childs++ ;
            lowest[current]=min(lowest[current],lowest[child]);

            // arT point 
            if(parent!=0 and lowest[child]>=discovery[current]) arT.pb(current);

            //bridge
            if(lowest[child]>discovery[current]) bridge.pb(mp(current,child));
        }
        else //backedge 
        {
            lowest[current]=min(lowest[current],discovery[child]);
        }

        //considering root
        if(parent==0 and childs>=2)
        {
            arT.pb(current);
        }
    }
    return ;
}

int main()
{
    FIO
    int n ;
    cin>>n ;
    forn(i,n)
    {
        int x,y ;
        cin>>x>>y ;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    tme=1 ;
    dfs(1,0);
    return 0 ;
}
