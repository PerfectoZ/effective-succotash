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

ll steps2one(ll n , ll dp[]) //top down 
{
    if(n==1 or n==0)
    if(dp[n]) return dp[n];

    ll a1=a2=a3=INT_MAX ;

    if(n%3==0) a1=1+steps2one(n/3,dp);
    if(n%2==0) a2=1+steps2one(n/2,dp);
    a3=1+steps2one(n-1,dp);

    return dp[n]=min(a1,min(a2,a3));
}

ll steps2oneUB(ll n , ll ub[]) // bottomup
{
    if(ub[n]) return ub[n] ;

    for(ll i=2 ; i<=n ; i++)
    {
        ll a1=a2=a3=INT_MAX ;
        if(i%2==0) a1=dp[i/2]+1 ;
        if(i%3==0) a2=dp[i/3]+1 ;
        a3=1+dp[i-1];
        dp[i]=min(a1,min(a2,a3));
    }

    return ub[n] ;
}

int32_t main()
{
    FIO 
    return 0;
}
