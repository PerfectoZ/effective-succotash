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

struct trie
{
    int value = 0;
    trie *child[2] = { NULL , NULL };
};

int max_xor(trie* root, int key)
{
    trie* temp = root ;
    for (int i = 31; i >= 0; i--)
    {
        int current_bit = (key & (1 << i)) ? 1 : 0;
        if (temp->child[1 - current_bit] != NULL)
            temp=temp->child[1 - current_bit] ;
        else
            temp = temp->child[current_bit];
    }
    return (key ^ temp->value);
}

void insert(trie* root, int key)
{
    trie* temp = root;
    for (int i = 31; i >= 0; i--)
    {
        int current_bit = (key & (1 << i)) ? 1 : 0;
        if (temp->child[current_bit] == NULL)
            temp->child[current_bit] = new trie;
        temp = temp->child[current_bit];
    }
    temp->value = key;
}

int main()
{
    spid();
    trie* root = new trie();
    int n,m;
    cin>>n;
    forl(i,0,n)
    {
	int x ;
        cin>>x;
        insert(root, x);
    }
    cin >> m;
    forl(i,0,m)
    {
	int x ;
        cin >> x;
        cout << max_xor(root, x)<<endl;
    }
    return 0;
}
