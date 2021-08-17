/* 
	Natus Vincere 
	Born To Conquer
*/
 
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
#define Roll cout<<"Mandeep Taneja\n2K20/IT/84\n" ;
ll power(ll x , ll b) { ll p = 1; while (b > 0) { if(b&1) { p = p * x; p %= mod; } b >>= 1; x *= x; x %= mod; } return p % mod; }
 
using namespace std;
 
struct line
{
	ll slope ;
	ll intercept ;
	
	line(ll m , ll y)
	{
		slope=m ; intercept=y ;
	}
	
	ll valatx(ll x0)
	{
		return slope*x0+intercept ;
	}
	
	ll x_inter(line &l2)
	{
		return ceil(1.0*(l2.intercept-intercept)/(slope-l2.slope));
	}
};	
 
class CHT
{
	deque<pair<line,ll>> dq ;
	public :
		
		void insert(line l)
		{
			if(dq.empty())
			{
				dq.pb({l,0});
				return ;
			}
			while(!dq.empty())
			{
				ll x0=l.x_inter(dq.back().ff);
				if(x0<=dq.back().ss) dq.pob();
				else break ;
			}
			ll x0=l.x_inter(dq.back().ff);
			dq.pb({l,x0});
		}

		ll query(ll x0)
		{
			while(dq.size()>1)
			{
				if(dq[1].ss<=x0)
					dq.pof();
				else 
					break ;
			}
			return dq[0].ff.valatx(x0);
		}
};	
 

ll solve(vector<ll> v , ll c , ll n)
{
	vector<ll> dp(n);
	CHT cht ;
	dp[0]=0 ;
	cht.insert({-2*v[0],v[0]*v[0]});
	forn1(i,n-1)
	{
		dp[i]=v[i]*v[i] + c + cht.query(v[i]);
		cht.insert({-2*v[i],dp[i]+v[i]*v[i]});
	}
	return dp[n-1];
}
 
int main()
{
	FIO
	ll n,c ; cin>>n>>c ;
	vector<ll> v(n); arr(v,n);
	cout<<solve(v,c,n);
	return 0;
}
