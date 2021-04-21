#include <bits/stdc++.h>
using namespace std ;

void filter(string s , int n)
{
    int i=0 ;
    while(n)
    {
        if(n&1)
            cout<<s[i] ;
        i++ ;
        n=n>>1 ;
    }
}

void generatesubset(string s)
{
    int n=s.length();
    int range=1<<n ;
    for (int i=1 ; i<range ; i++)
    {
        filter(s,i);
    }
}

int main()
{
  //appropriate function calls
  return 0;
}
