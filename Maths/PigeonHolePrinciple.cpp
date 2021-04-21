#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int N ;
    cin>>N ;
    int temp ;
    int sum=0 ;
    map<int,int> m ;
    for (int i=0 ; i<N ; i++)
    {
        cin>>temp ;
        sum+=temp ;
        sum = sum%N ;
        sum = (sum+N)%N ;
        m[sum]++ ;
    }
    int ans=0 ;
    map<int,int>::iterator it ;
    for (it=m.begin() ; it!=m.end() ; ++it)
    {
        int x=it->second ;
        ans+=(x*(x-1))/2 ;
    }
    cout<<ans<<endl ;
    return 0;
 }
