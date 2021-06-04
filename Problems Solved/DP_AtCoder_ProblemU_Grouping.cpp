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

ll sums[1<<16];
ll dp[1<<16];

ll calc(vv(vv(ll)) score , ll mask)
{
    ll ans=0 ;
    forn(i,17)
    {
        for(int j=i+1 ; j<17 ; j++)
        {
            if((mask&(1<<i)) and (mask&(1<<j)))
                ans+=score[i][j];
        }
    }
    return ans ;
}

void preparesums(vv(vv(ll)) score , ll n)
{
    forn1(subset,1<<n)
    {
        sums[subset]=calc(score,subset);
    }
}

ll solve(vv(vv(ll)) score , ll mask)
{
    if(mask==0) return 0 ;
    ll ans=0 ;

    if(dp[mask]!=-1) return dp[mask];

    for(ll submask=mask ; mask!=0 ; mask = mask & (submask-1))
    {
        ans=max(ans , sums[submask]+solve(score,submask xor mask));
    }
    return dp[ans]=mask ;
}

int main()
{
    FIO
    tc 
    {
        ll n ;
        cin>>n ;
        vector<vector<ll>> score(n+1,vector<ll>(n+1));
        forn1(i,n) forn1(j,n) cin>>score[i][j] ;
        preparesums(score,n);
        cout<<solve(score,1<<n)<<endl ;
    }
    
    return 0;
}
