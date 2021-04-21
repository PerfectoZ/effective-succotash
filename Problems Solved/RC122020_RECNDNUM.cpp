#include <bits/stdc++.h>

#define lli long long int 
#define pb push_back
#define mod 1000000007
#define w(x) int x ; cin>>x ; while(x--)
#define sortl(v) sort(v.begin() , v.end());
#define sortg(v,int) sort(v.begin() , v.end() , greater<int>());
#define forl(i,a,b) for (int i=a ; i<b ; ++i)
#define fore(i,a,b) for (int i=a ; i<=b ; ++i)
#define foril(i,a,b,p)   for(i=a ; i<b ; i+=p)
#define forie(i,a,b,p)   for(i=a ; i<=b ; i+=p)
#define endl "\n"
#define ct(x,v) count(v.begin() , v.end() , x);
#define lb lower_bound 
#define ub upper_bound
#define minint numeric_limits<int>::min()
#define maxint numeric_limits<int>::max()

using namespace std;

void spid()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}

int32_t main()
{
    spid();
    w(T)
    {
        lli n,k ;
        cin>>n>>k ;
        lli p=(k+2*n-1)/2 ;
        lli t=p*(p+1) ;
        if((k+2*n-1)%2==0) t=t-n ;
        else t=t+n ;
        cout<<t<<endl ;
    }
	return 0;
}
