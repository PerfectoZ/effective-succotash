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

template<typename T>
class graph
{
    map<T,list<T>> l ;
    public :
        void add_edge(int x , int y)
        {
            l[y].pb(x);
            l[x].pb(y);
        }

        void dfs_helper(T src , map<T,bool> &visited)
        {
            cout<<src<<" " ;
            visited[src]=true ;
            trav(nbr,l[src]) if(!visited[nbr]) dfs_helper(nbr,visited);
        }

        void dfs()
        {
            map<T,bool> visited ;
            trav(p,l) visited[p.ff]=false ;
            int ct=0 ;
            trav(p,l)
            {
                T node=p.ff ;
                if(!visited[node]) 
                {
                    cout<<"Component "<<ct<<" --> " ;
                    dfs_helper(node,visited);
                    ct++ ;
                    cout<<endl ;
                }
            }
        }
};

int main()
{
    FIO
    graph<int> g ;
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(0,3);
    g.add_edge(0,4);

    g.add_edge(5,6);
    g.add_edge(6,7);

    g.add_edge(8,8);
    g.dfs();
    return 0;
}
