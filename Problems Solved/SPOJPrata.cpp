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

bool isPossible(int ranks[] , int n , int mid , int p)
{
    ll c=0 ;
    forn(i,n)
    {
        ll t=0 ;
        int j=1 ;
        while(1)
        {
            t+=j*ranks[i];
            j++ ;
            if(t>mid) break ;
            c++ ;
        }
    }
    return c>=p ;
}

int howmuchtime(int ranks[] , int n , int p)
{
    int maxrank=*max_element(ranks,ranks+n);
    ll utl=0 ;
    int i=1 , c=0 ;
    while(c<p)
    {
        utl+=i*maxrank ;
        i++ ;
        c++ ;
    }
    ll s=0 ;
    ll e=utl ;
    while(s<=e)
    {
        ll mid=(s+e)/2 ;
        if(isPossible(ranks,n,mid,p))
        {
            e=mid-1 ;
        }
        else
        {
            s=mid+1 ;
        }
    }
    return e+1 ;
}

int main()
{
    FIO
    tc
    {
        int n,p ;
        cin>>p>>n ;
        int ranks[n];
        arr(ranks,n);
        cout<<howmuchtime(ranks,n,p)<<endl;
    }
    return 0;
}
