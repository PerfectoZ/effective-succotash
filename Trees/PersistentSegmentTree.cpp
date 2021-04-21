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
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

#define maxn 100 

using namespace std;

struct node 
{
	int val ;
	node* left , right ;
	node() {} 
	node(node* l , node* r , int v)
	{
		left=l ;
		right=r ;
		val=v ;
	}
};

int a[maxn];
node* version[maxn];

void build(node* n , int low , int high)
{
	if(low==high) 
	{
		n->val=arr[low];
		return ;
	}
	int mid=(low+high)/2 ;
	build(n->left,low,mid);
	build(n->right,mid+1,high);
	n->val=n->right->val + n->left->val ;
}

void update(node* prev , node* curr , int low , int high , int idx , int value)
{
	if (idx > high or idx < low or low > high) return;
	if (low == high)
    {
        cur->val = value;
        return;
    }
    int mid=(low+high)/2 ;

    if (idx <= mid)
    {
        cur->right = prev->right;
        cur->left = new node(NULL, NULL, 0);
        upgrade(prev->left,cur->left, low, mid, idx, value);
    }

    else
    {
        cur->left = prev->left;
        cur->right = new node(NULL, NULL, 0);
        upgrade(prev->right, cur->right, mid+1, high, idx, value);
    }
    cur->val = cur->left->val + cur->right->val;
}

void query(node* n , int low , int high , int l , int r)
{
    if (l > high or r < low or low > high) return 0;
    if (l <= low and high <= r) return n->val;
    int mid = (low+high) / 2;
    int p1 = query(n->left,low,mid,l,r);
    int p2 = query(n->right,mid+1,high,l,r);
    return p1+p2;
}

int main()
{
	int A[] = {1,2,3,4,5};
	forn(i,sizeof(A)/sizeof(A[0])) arr[i]=A[i];
	node* root = new node(NULL, NULL, 0);
    build(root, 0, n-1);
    version[0]=root
    version[1]=new node(NULL,NULL,0);
    version[2] = new node(NULL, NULL, 0);
    upgrade(version[1],version[2], 0, n-1, 2, 10);
    
    cout << "In version 1 , query(0,4) : ";
    cout << query(version[1], 0, n-1, 0, 4) << endl;
  
    cout << "In version 2 , query(3,4) : ";
    cout << query(version[2], 0, n-1, 3, 4) << endl;
  
    cout << "In version 0 , query(0,3) : ";
    cout << query(version[0], 0, n-1, 0, 3) << endl;
    return 0;
}
