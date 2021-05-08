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

bool checkwinner(string s[3] , char c)
{
    if(s[0][0]==c and s[0][1]==c and s[0][2]==c) return true ;
    if(s[1][0]==c and s[1][1]==c and s[1][2]==c) return true ;
    if(s[2][0]==c and s[2][1]==c and s[2][2]==c) return true ;
    
    if(s[0][0]==c and s[1][0]==c and s[2][0]==c) return true ;
    if(s[0][1]==c and s[1][1]==c and s[2][1]==c) return true ;
    if(s[0][2]==c and s[1][2]==c and s[2][2]==c) return true ;
    
    if(s[1][1]==c and s[2][2]==c and s[0][0]==c) return true ;
    if(s[2][0]==c and s[1][1]==c and s[0][2]==c) return true ;
    
    return false  ;
}

int main() 
{
    FIO
    tc 
    {
        string s[3] ;
        map<char,int> mp ;
        forn(i,3)
        {
            cin>>s[i] ;
            forn(j,3) mp[s[i][j]]++ ;
        }
        
        if(abs(mp['X']-mp['O'])>1 or mp['O']>mp['X']) { cout<<3<<endl ; continue ; }
        
        if(checkwinner(s,'O')==true and checkwinner(s,'X')==true) { cout<<3<<endl ; continue ; }
        
        if(checkwinner(s,'X')==true)
        {
            if(mp['X']-mp['O']==1) { cout<<1<<endl ; continue ; } 
            else { cout<<3<<endl ; continue ; }
        }
        
        else if(checkwinner(s,'O')==true)
        {
            if(mp['O']==mp['X']) { cout<<1<<endl ; continue ; } 
            else { cout<<3<<endl ; continue ; }
        }
        
        if(checkwinner(s,'O')==false and checkwinner(s,'X')==false)
        {
            if(mp.count('_')==0) { cout<<1<<endl ; continue ; }
            else { cout<<2<<endl ; continue ; }
        }
    }
    return 0; 
}
