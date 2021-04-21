#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc ll tc; cin>>tc ; cin.ignore(5,'\n'); for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof  pop_front
#define endl "\n"
#define umap unordered_map
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

vector<ll> A;

typedef struct node{
    ll sum;
    ll best;
    ll best_left;
    ll best_right;
    node(ll a, ll b, ll c, ll d)
    {
        sum = a;
        best = b;
        best_left = c;
        best_right = d;
    }
}node;

vector<node> tree(1000002 , node(0,0,0,0));

void build_tree(int idx , int ss , int se)
{
  if(ss>se) return ;
  if(ss==se) { tree[idx]=node(A[ss],A[ss],A[ss],A[ss]); return ; }
  int mid=(ss+se)/2 ;
  build_tree(2*idx+1 , ss , mid);
  build_tree(2*idx+2 , mid+1 , se);
  
  tree[idx].sum = tree[idx*2+1].sum + tree[idx*2+2].sum;
  
  tree[idx].best_left = max(tree[idx*2+1].best_left, tree[idx*2+1].sum + tree[idx*2+2].best_left);
  
  tree[idx].best_right = max(tree[idx*2+2].best_right, tree[idx*2+1].best_right + tree[idx*2+2].sum);
  
  tree[idx].best = max(max(max(tree[idx].sum,tree[idx*2+1].best_right + tree[idx*2+2].best_left), tree[idx*2+1].best), tree[idx*2+2].best);
  
  tree[idx].best = max(tree[idx].best, tree[idx].best_left);
  
  tree[idx].best = max(tree[idx].best, tree[idx].best_right);
  
}

node query_tree(int idx , int ss , int se , int l , int r)
{
  if(ss>se || ss>r || se<l) return node(INT_MIN,INT_MIN,INT_MIN,INT_MIN);
  if(ss>=l && se<=r) return tree[idx] ;
  int mid=(ss+se)/2 ;
  node q1=query_tree(2*idx+1 , ss , mid , l , r);
  node q2=query_tree(2*idx , mid+1 , se , l , r);
  node q(0,0,0,0);
  q.sum = q1.sum + q2.sum;
  q.best_left = max(q1.best_left, q1.sum + q2.best_left);
  q.best_right = max(q2.best_right, q1.best_right + q2.sum);
  q.best = max(q1.best, q2.best);
  q.best = max(q.best, q1.best_right + q2.best_left);
  q.best = max(q.best, q1.sum + q2.sum);
  q.best = max(q.best, q.best_left);
  q.best = max(q.best, q.best_right);
  return q ;
}

int main()
{
    FIO ;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        long long int t;
        cin>>t ;
        A.pb(t);
    }
    build_tree(0, 0, n-1);
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int xi,yi;
        cin>>xi>>yi ;
        xi--;
        yi--;
        printf("%lld",query_tree(0, 0, n-1, xi, yi).best);
        if(i != m-1)
            printf("\n");
    }
  return 0 ;
}
