// Counting numbers with K distinct prime factors 
#include <bits/stdc++.h>
using namespace std ;

int sieve(int n , int k) 
{
  int pr[n+1]={0};
  vector<int> primes ;
  for (int i=2 ; i<=n ; i++)
  {
    if(pr[i]==0)
    {
      primes.push_back(i);
      for (int j=i ; j<=n ; j+=i) pr[j]++ ;
    }
  }
  int ans=0 ;
  for (int i=2 ; i<=n ; i++) if(pr[i]==k) ans++ ;
  return ans ;
}

int main()
{
  return 0;
}
