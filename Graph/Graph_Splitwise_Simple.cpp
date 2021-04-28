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

int main()
{
    FIO
    int transactions,friends ;
    cin>>transactions>>friends ;
    int x,y,amount ;
    vector<int> net(friends,0);
    forn(i,transactions)
    {
        cin>>x>>y>>amount ;
        net[x]-=amount ;
        net[y]+=amount ;
    }
    multiset<int> m ;
    forn(i,friends)
    {
        if(!net[x]) m.insert(net[x]);
    }
    int ct=0 ;
    while(!m.empty())
    {
        auto debit=*m.begin();
        auto credit=*prev(m.end());
        m.erase(m.begin()); m.erase(prev(m.end()));
        int settlement=min(-debit,credit);
        ct++ ;
        debit+=settlement ;
        credit-=settlement ;
        if(debit) m.insert(debit);
        if(credit) m.insert(credit);
    }
    cout<<ct<<endl ;
    return 0 ;
}
