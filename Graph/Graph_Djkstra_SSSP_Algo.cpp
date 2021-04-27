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
    unordered_map<T,pair<T,int>> m ;
    public :
        void addEdge(T x , T y , int w , bool bidir=true)
        {
            m[x].pb(mp(y,w));
            if(bidir) m[y].pb(mp(x,w));
        }
        void printList()
        {
            trav(j,m)
            {
                cout<<j.ff<<" " ;
                trav(k,j.ss)
                {
                    cout<<"("<<k.ff<<" "<<k.ss<<")"<<" " ;
                }
                cout<<endl ;
            }
        }
        void djikstra(T src)
        {
            unordered_map<T,int> dist ;
            trav(j,m) dist[j]=INT_MAX ;
            dist[src]=0 ;
            set<pair<int,T>> Q ;
            Q.insert(mp(0,src));
            while(!Q.empty())
            {
                auto p=*Q.brgin();
                Q.erase(Q.begin());

                T node=p.ss ;
                int nodedist=p.ff ;

                trav(childPair , m[node])
                {
                    if(nodedist + childPair.ss < dist[childPair.ff])
                    {
                        T dest=childPair.ss ;
                        auto f=Q.find(mp(dist[childPair.ff],dest));
                        if(f!=Q.end())
                        {
                            Q.erase(f);

                        }
                        dist[dest]=nodedist + childPair.ss ;
                        Q.insert(mp(dist[dest],dest));
                    }
                }
            }
            trav(d,dist)
            {
                cout<<dist.ff<<" "<<dist.ss<<endl ;
            }
        }
};

int main()
{
    FIO
    graph<string> g ;
    g.addEdge("Amritsar","Delhi",1);
    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Jaipur","Delhi",2);
    g.addEdge("Jaipur","Mumbai",8);
    g.addEdge("Bhopal","Agra",2);
    g.addEdge("Mumbai","Bhopal",3);
    g.addEdge("Agra","Delhi",1);
    g.djikstra("Amritsar");
    return 0 ;
}
