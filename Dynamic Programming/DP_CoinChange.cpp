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

ll coinTD(ll n , vector<ll> coins)
{
    if( n<=0 ) return 0 ;
    if(n==1) return 1 ;
    if(dp[n]) return dp[n] ;

    ll ans=INT_MAX ;
    forn(i,coins.size())
    {
        if(n-coins[i]>=0) ans=min(ans,1+coinTD(n-coins[i],coins));
    }
    return dp[n]=ans ;
}

ll coinUB(ll n , vector<ll> coins , vv(ll) &dp)
{
    if(n<=0) return 0 ;
    if(n==1) return n ;

    if(dp[n]) return dp[n] ;

    for(ll i=2 ; i<=n ; i++)
    {
        dp[i]=INT_MAX ;
        forn(j,coins.size())
        {
            if(i+coins[j]<=n) dp[i+coins[j]]=min(dp[i+coins[j]],1+dp[i]);
        }
    }
    return dp[n];
}

int32_t main()
{
    FIO 
    return 0;
}
