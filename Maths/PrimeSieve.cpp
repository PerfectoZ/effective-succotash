#include <bits/stdc++.h>
using namespace std ;

vector<ll> primes ;
bitset<1000005> b ;
long long int n=1000005 ;

void primesieve()
{
    b.set();
    b[0]=b[1]=0 ;
    for (ll i=2 ; i<=n ; i++)
    {
        if(b[i])
        {
            primes.push_back(i);
            for (ll j=i*i ; j<=N ; j+=i)
            {
                b[j]=0 ;
            }
        }
    }
}

bool isPrime(ll x)
{
    if(x<=n) { b[x]=1 ? return true : return false ; }
    for (ll i=0 ; primes[i]*primes[i]<=x ; i++)
    {
        if(x%primes[i]==0) return false ;
    }
    return true ;
}

int main()
{
    ll N ;
    cin>>N ;
    primesieve(N);
    for (ll i=0 ; i<primes.size() ; i++)
    {
        cout<<primes[i]<<" " ;
    }
    return 0;
}
