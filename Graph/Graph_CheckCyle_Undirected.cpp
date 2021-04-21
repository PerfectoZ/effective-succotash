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
    int V ;
    public :
        graph(int V)
        {
            this->V = V ;
        }
        void add_edge(int x , int y , bool directed=true)
        {
            l[x].pb(y);
            if(!directed) l[y].pb(x);
        }

        bool cycle_helper(T node , bool *visited , int parent)
        {
            visited[node]=true ;
            trav(nbr,l[node])
            {
                if(!visited[nbr]) 
                {
                    bool cycle_mila=cycle_helper(nbr,visited,node);
                    if(cycle_mila) return true ;
                }
                else if(nbr!=parent) return true ;
            }
            return false ;
        }

        bool contains_cycle()
        {
            bool *visited=new bool[V];
            forn(i,V) visited[i]=false ;
            return cycle_helper(0,visited,-1);
        }

};

int main()
{
    FIO
    graph<int> g(5);

    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,0);

    if(g.contains_cycle()) cout<<"Yes cycle found" ;
    else cout<<"No cycle not found" ;
    
    return 0;
}
