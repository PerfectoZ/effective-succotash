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

vector<ll> sv1,sv2 ;

vector<ll> sumsubs(vector<ll> v)
{
    ll n=v.size();
    vector<ll> sums ;
    ll tsubs=(1<<n) ;
    forn(i,tsubs)
    {
        ll sum=0 ;
        ll temp=i,j=0 ;
        while(temp)
        {
            if(1&temp) sum+=v[j]; 
            j++ ;
            temp=temp>>1 ;
        }
        sums.pb(sum);
    }
    return sums ;
}

int main()
{
    FIO
    ll n,a,b ;
    cin>>n>>a>>b ;
    ll n1=n/2,n2=n-n1,ans=0 ;
    vector<ll> v1(n1) , v2(n2);
    arr(v1,n1);
    arr(v2,n2);
    sv1=sumsubs(v1);
    sv2=sumsubs(v2);
    sort(all(sv2));
    forn(i,sv1.size())
    {
        ll st=a-sv1[i];
        ll en=b-sv1[i];
        auto it1=lower_bound(all(sv2),st)-sv2.begin();
        auto it2=upper_bound(all(sv2),en)-sv2.begin();
        ans+=(it2-it1);
    }
    cout<<ans<<endl ;
    return 0;
}
