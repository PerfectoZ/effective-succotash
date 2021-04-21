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
#define en "\n"
#define ct(v,x) count(v.begin() , v.end() , x);
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

class node
{
public:
    char key ;
    int total ;
    unordered_map<char,node*> h ;
    bool isTerminal ;
    node(char d)
    {
        total=0 ;
        key=d ;
        isTerminal=false ;
    }
};

class Trie
{
    node* root ;
public:
    Trie()
    {
        root=new node('\0');
    }

    void addword(string s)
    {
        node* temp=root ;
        forl(i,0,s.length())
        {
            char x=s[i] ;
            if(temp->h.count(x)==0)
            {
                node* child=new node(x);
                temp->h[x]=child ;
                temp=child ;
            }
            else
            {
                temp=temp->h[x];
            }
            temp->total=temp->total+1 ;
        }
        temp->isTerminal=true ;
    }

    bool Search(string s)
    {
        node* temp=root ;
        forl(i,0,s.length())
        {
            char x=s[i];
            if(temp->h.count(x)==0) return false ;
            else temp=temp->h[x];
        }
        return temp->isTerminal ;
    }

    int countsub(string s)
    {
        node* temp=root ;
        forl(i,0,s.length())
        {
            char x=s[i];
            if(temp->h.count(x)==0) return 0;
            else temp=temp->h[x];
        }
        return temp->total ;
    }
};

int32_t main()
{
    spid();
    Trie t ;
    int n ;
    cin>>n ;
    cin.ignore(5,'\n');
    forl(i,0,n)
    {
        string s,op ;
        cin>>op>>s ;
        if(op=="add") t.addword(s); 
        else cout<<t.countsub(s)<<endl ;
    }
    return 0;
}
