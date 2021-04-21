#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define mod 1000000007
#define w(x) int x ; cin>>x ; while(x--)
#define sortl(v) sort(v.begin() , v.end());
#define sortg(v,int) sort(v.begin() , v.end() , greater<int>());
#define forl(i,a,b) for (lli i=a ; i<b ; ++i)
#define fore(i,a,b) for (lli i=a ; i<=b ; ++i)
#define foril(i,a,b,p)   for(lli i=a ; i<b ; i+=p)
#define forie(i,a,b,p)   for(lli i=a ; i<=b ; i+=p)
#define en "\n"
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
        vector<lli> v , v1 ;
        forl(i,0,n)
        {
            lli x ;
            cin>>x ;
            v.pb(x);
            v1.pb(x);
        }
        sortl(v1);
        if(v==v1) { cout<<"yes"<<en ; continue ; }
        bool f=true ;
        forl(i,0,n)
        {
            lli pos=find(v1.begin() , v1.end() , v[i])-v1.begin();
            if(abs(pos-i)<k && pos!=i) {f=false ; break ;}
        }
        if(f) cout<<"yes"<<en ;
        else cout<<"no"<<en ;
    }
	return 0;
}
