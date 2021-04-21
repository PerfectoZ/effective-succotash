//shortest path to reach from 0 to 36 in board 

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
        }
        int bfs(T src , T dest)
        {
            map<T,int> dist ;
            map<T,T> parent ;

            queue<T> q ;
            trav(node_pair,l)
            {
                T node=node_pair.ff ;
                dist[node]=INT_MAX ;
            }
            q.push(src);
            dist[src]=0 ;
            parent[src]=src ;
            while(!q.empty())
            {
                T node=q.front();
                q.pop();

                for(int nbr:l[node])
                {
                    if(dist[node]==INT_MAX) {q.push(nbr) , dist[nbr]=1+dist[node] ,parent[nbr]=node ; }
                }
            }
            T temp=dest ;
            while(temp!=src)
            {
                cout<<temp<<" <- "
                temp=parent[temp]; 
            }
            cout<<src<<endl ;
            return dist[dest];
        }
};

int main()
{
    FIO
    int board[50]={0};
    board[2]=13 ;
    board[5]=2 ;
    board[3]=18 ;
    board[18]=11 ;
    board[17]=-13 ;
    board[20]=-14 ;
    board[24]=-8 ;
    board[25]=10 ;
    board[32]=-2 ;
    board[34]=-22 ;

    graph<int> g ;
    forn(i,37)
    {
        forn1(dice,6)
        {
            int j=i+dice ;
            j+=board[j];
            if(j<=36)
            {
                g.add_edge(i,j);
            }
        }
        g.add_edge(36,36);
    }
    g.bfs(0,36);
    return 0;
}
