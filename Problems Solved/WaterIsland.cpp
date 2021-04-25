// Find the cluster of land together in 2D array using dfs 

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

using namespace std ;

int n, m;
int counter;
vector<string> v(100005);

void dfs(int x, int y){
    if(v[x][y] == '1'){
        v[x][y] = 'x';
        ++counter;
    }
    if(x < n && y + 1 < m ){
        if(v[x][y + 1] == '1') dfs(x, y + 1);
    }
    if(x + 1 < n && y < m){
        if(v[x + 1][y] == '1') dfs(x + 1, y);
    }
    if(x - 1 >= 0 && y < m){
        if(v[x - 1][y] == '1') dfs(x - 1, y);
    }
    if(x < n && y - 1 >= 0){
        if(v[x][y - 1] == '1') dfs(x, y - 1);
    }
}


void solve(){
    tc 
    {
        cin>>n>>m;
        forn(i,n) cin>>v[i];
        vector<int> arr;
        forn(i,n)
        {
            forn(j,m)
            {
                counter = 0;
                if(v[i][j] == '1')
                {
                    dfs(i, j);
                    arr.pb(counter);
                }
            }
        }
        sort(all(arr),greater<int>());
        int ans = 0;
        if(arr.size() > 1){
            forn(i,arr.size()) if(i & 1) ans += arr[i];
            cout<<ans<<endl;
        }
        else cout<<0<<endl;
    }
}

int main(){
    FIO 
    solve();
    return 0;
}
