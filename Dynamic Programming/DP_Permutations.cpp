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

ll dp[3001][3001];

void solve(string s , ll n)
{
    dp[n][0] = (s[n-2]=='>') ? 1:0 ;
    dp[n][1] = (s[n-2]=='<') ? 1:0 ;

    for(ll i=n ; i>=2 ; i--)
    {
        ll total=n-i+1 ;
        forn(g,total+1)
        {
            if(g==0)
            {
                if(i==n) continue ;
                
                dp[i][g]=0 ;

                if(s[i-2]== '<') continue ;

                forn1(j,total)
                {
                    dp[i][g] = (dp[i][g]+dp[i+1][total-j])%mod ;
                }
            }
            else 
            {
                if(s[i-2]=='>') dp[i][g] = ( dp[i][g-1] - dp[i+1][g-1] )%mod ;
                else dp[i][g] = (dp[i][g-1] + dp[i+1][g-1])%mod ;

            }
        }
    }
}

int main()
{
    FIO
    ll n ; cin>>n ;
    string s ;
    cin>>s ;
    solve(s,n);
    ll ans=0 ;
    for(int gr=n-1 ; gr>=0 ; gr--) ans=(ans+dp[2][gr])%mod ;
    cout<<ans<<endl ;
    return 0;
}
