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

int main()
{
    FIO
    tc 
    {
      ll n,D,F ;
      bool flag=false ;
      pq p ;
      cin>>n ;
      vv(pp(int)) v(n);
      forn(i,n) cin>>v[i].ff>>v[i].ss ;
      cin>>D>>F ;
      forn(i,n) v[i].ff=D-v[i].ff ;
      sort(all(v));
      int prev=0 , x=0 ; //x=current city 
      while(x<n)
      {
        if(F>=v[x].ff-prev) 
        {
          F-=(v[x].ff-prev);
          prev=v[x].ff ;
          p.push(v[x].ss)
        }
        else 
        {
          if(p.empty()) { flag=true , break ; }
          F+=p.top();
          p.pop();
          ans++ ;
          continue ;
        }
        x++ ;
        if(flag) { cout<<-1<<endl ; continue ; }
        D-=v[n-1].ff ;
        while(F<D) 
        {
          if(p.empty()) { flag=true , break ; }
          F+=p.top();
          p.pop();
          ans++ ;
        }
        if(flag) { cout<<-1<<endl ; continue ; }
        cout<<ans<<endl ;
      }
    }
    return 0;
}
