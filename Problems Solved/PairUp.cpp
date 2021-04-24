// No of ways to pair up 2 cities such that they are not connected to each other 

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

class graph
{
    int V ;
    list<pair<int,int>> l ;
    public :
        graph(int V) { this->V = V ; }

        int add_edge(int x , int y)
        {
            l.pb(mp(x,y));
        }

        int findset(int i , int parent[])
        {
            if(i==-1) return i ;
            return findset(parent[i],parent);
        }

        void union_set(int x , int y , int parent[] , int rank[])
        {
            int s1=findset(x,parent);
            int s2=findset(y,parent);
            if(s1!=s2)
            {
                if(rank[s1]<rank[s2]) { parent[s1]=s2 ; rank[s2]+=rank[s1]; }
                else { parent[s2]=s1 ; rank[s1]+=rank[s2]; }
            }
        }

        int pairing()
        {
            int *parent=new int[V];
            int *rank=new int[V];
            forn(i,V) { rank[i]=1 ; parent[i]=-1 ; }

            int ans=0 ;
            trav(edge,l)
            {
                int i=edge.ff ;
                int j=edge.ss ;

                int s1=findset(i,parent);
                int s2=findset(j,parent);

                if(s1!=s2) union_set(i,j,parent,rank);
            }

            forn(i,V) ans+=V-rank[findset(i,parent)];
            delete[] parent ;
            delete[] rank ;
            return ans/2 ;
        }
};

int main()
{
    FIO
    int n,m ;
    cin>>n>>m ;
    graph g(n);
    while(m--)
    {
        int x,y ;
        cin>>x>>y ;
        g.add_edge(x,y);
    }
    
    cout<<g.pairing()<<endl ;

    return 0;
}
