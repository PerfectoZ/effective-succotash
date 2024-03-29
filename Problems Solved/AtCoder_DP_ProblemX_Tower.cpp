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
#define bp(kkk); ll kkk; cin >>kkk;
#define dbgArr(a,n) cout<<"Array "<<#a<<endl; for(ll i=0 ; i<n ; i++) cout<<a[i]<<" "; cout<<endl;
#define forn(i,n) for(ll i=0 ; i<n ; i++)
#define forn1(i,n) for(ll i=1 ; i<=n ; i++)
#define arr(a,n) for(ll i=0;i<n;i++){ cin>>a[i]; }
#define arr1(a,n) for(ll i=1;i<=n;i++){ cin>>a[i]; }
#define file freopen("inp.in","r",stdin); freopen("outp.out","w",stdout)
#define print(number) cout<<"Case #"<<number<<": "
#define all(x) x.begin(), x.end()
#define trav(x, a) for(auto &x: a)
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

using namespace std;

ll dp[1001][10001];

struct box
{
    ll w,s,v ;
};

ll solve(vector<box>&v)
{
    sort(all(v),compbox);
    forn(j,10001)
    {
        if(v[0].s >= j) dp[0][j]=v[0].v ;
        else dp[0][j]=0 ;
    }
    forn1(i,v.size()-1)
    {
        forn(j,10001)
        {
            ll op1=dp[i-1][j];
            ll op2= (v[i].s>=j) ? (v[i].v + (j+v[i].w > 10000 ? 0 : dp[i-1][j+v[i].w])) : 0 ;
            dp[i][j]=max(op1,op2);
        }
    }
    return dp[v.size()-1][0];
}

bool compbox(box b1 , box b2)
{
    return b1.w+b1.s > b2.w+b2.s ;
}

int main()
{
    FIO
    tc 
    {
        ll n ;
        cin>>n ;
        vector<box> v(n) ;
        forn(i,n) 
        {
            // input boxes 
        }
        cout<<solve(v)<<endl ;
    }
    return 0;
}
