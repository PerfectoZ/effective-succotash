#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc ll tc; cin>>tc; for(ll number = 1 ; number <= tc ; number ++ )
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

void multiply(int *a , int &n , int no)
{
    int carry=0 ;
    for (int i=0 ; i<n ; i++)
    {
        int product=a[i]*no+carry ;
        a[i]=product%10 ;
        carry=product/10 ;
    }
    while(carry)
    {
        a[n]=carry%10 ;
        carry=carry/10 ;
        n++ ;
    }
}

void fac(int num)
{
    int a[1000]={0};
    a[0]=a[1]=1 ;
    int n=1 ;
    for (int i=2 ; i<=num ; i++ )
    {
        multiply(a,n,i);
    }
    for (int i=n-1 ; i>=0 ; i--)
    {
        cout<<a[i] ;
    }
}

int main()
{
    FIO
    int n ;
    cin>>n ;
    fac(n);
    return 0;
}
