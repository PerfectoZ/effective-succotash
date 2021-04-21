#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N ;
    cin>>N ;
    int A[N][N];
    for (int i=0 ; i<N ; i++)
    {
        for (int j=0 ; j<N ; j++)
        {
            cin>>A[i][j];
        }
    }
    int key ;
    cin>>key ;
    bool isfound=false ;
    int i=0 , j=N-1 ;
    while(i<N && j>=0)
    {
        if(A[i][j]>key)
            j-- ;
        else if(A[i][j]<key)
            i++ ;
        else
        {
            isfound=true ;
            break ;
        }
    }
    if(isfound)
        cout<<"Yes"<<endl ;
    else
        cout<<"No"<<endl ;
    return 0;
}
