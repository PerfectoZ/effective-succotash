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

ll solve(vector<ll> v , ll n , ll k)
{
    ll dp[n+2][k+2];
    forn(j,k+1) dp[1][j]=(j>v[1]);
    for(ll i=2 ; i<=n ; i++)
    {
        forn(j,k+1)
        {
            if(j==0) { dp[i][j]=dp[i-1][j]; continue ; }
            dp[i][j]=dp[i][j-1]+dp[i-1][j] ;
            if(j-v[i]-1>=0) dp[i][j]-=dp[i-1][j-v[i]-1];
        }
    }
    return dp[n][k];
}


int main()
{
    FIO
    ll n,k ;
    cin>>n>>k ;
    vector<ll> v(n+1); arr1(v,n);
    memset(dp,0,sizeof(dp));
    cout<<solve(v,n,k);
    return 0;
}
