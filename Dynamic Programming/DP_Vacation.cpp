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
#define trip(x) pair<x,pair<x,x>> 
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

using namespace std;

struct activity
{
    ll A,B,C ;
};

ll solve(ll n , vector<activity> v)
{
    vector<vector<ll>> dp(n+1 , vector<ll>(3));
    
    dp[1][0]=v[0].A ;
    dp[1][1]=v[0].B ;
    dp[1][2]=v[0].C ;

    for(ll i=2 ; i<=n ; i++)
    {
        dp[i][0]=v[i].A + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=v[i].B + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=v[i].C + max(dp[i-1][0],dp[i-1][1]);
    }
    
    return max(dp[n][0],dp[n][1],dp[n][2]); 
}

int main()
{
    FIO
    ll n ;
    cin>>n ;
    vector<activity> v(n);
    forn(i,n)
    {
      cin>>v[i].A>>v[i].B>>v[i].C ;
    }
    cout<<solve(n,v);
    return 0;
}
