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

class person_compare
{
    public :
        bool operator()(pair<string,int> p1 , pair<string,int> p2)
        {
            return p1.ss < p2.ss ;
        }
};

int main()
{
    FIO
    int transactions,friends ;
    cin>>transactions>>friends ;
    string x,y ; 
    int amount ;
    map<string,int> net ;
    forn(i,transactions)
    {
        cin>>x>>y>>amount ;
        if(net.count(x)==0) net[x]=0 ;
        if(net.count(y)==0) net[y]=0 ;
        net[x]-=amount ;
        net[y]+=amount ;

    }
    multiset<pair<string,int> , person_compare> m ;
    trav(p,net)
    {
        string person=p.ff ;
        int amt=p.ss ;
        if(net[person]!=0)
        {
            m.insert(mp(person,amount));
        }

    }
    int ct=0 ;
    while(!m.empty())
    {
        auto low=m.begin() , high=prev(m.end());
        int debit=(*low).ss , credit=(*high).ss ;
        string debit_person = (*low).ff , credit_person=(*high).ff ;
        m.erase(low); m.erase(high);
        int settlement=min(-debit,credit);
        ct++ ;
        cout<<debit_person<<" -> "<<credit_person<<" "<<settlement<<"$"<<endl ;
        if(debit) m.insert(mp(debit_person,debit));
        if(credit) m.insert(mp(credit_person,credit));
    }
    cout<<ct<<endl ;
    return 0 ;
}
