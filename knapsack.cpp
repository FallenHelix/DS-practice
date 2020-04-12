#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Include for built in treap
#include <ext/pb_ds/tree_policy.hpp>

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++ 
    ((cout << args << " "), ...);
cout<<endl;
}

using namespace __gnu_pbds;
const int MOD = 1e9 + 7;
#define cer(x) cerr<<#x<<"="<<x<<'\n'
#define deb(x) cout<<#x<<"="<<x<<'\n'
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define si set<int>
#define mpii map<int, int>
#define prq priority_queue
#define sz(s) (int) s.size()
#define pf(a) printf("%d\n",a)
#define sc1(a) scanf("%d",&a)
#define sc2(a, b) scanf("%d%d",&a,&b)
#define pi 2 * acos (0.0)
#define inf 1e9
#define dbg cout<<"ok"<<endl;
#define FOR(i, j, k) for(int i=(j); i<(k); i++)
#define REV(i, j, k) for(int i=(n-1); i>=k; i--)
#define rnd(a, b) ((((rand()<<15)^rand())%((b)-(a) + 1))+(a))
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)
#define mem(x, y) memset(x, y, sizeof(x))
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;
const double EPS = 1e-9;
const int MXX = 1e5 + 5;


void knapsack(vector<int> &p,vector<int> &w,int m,int n)
{
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<m+1;++j)
        {

            if(w.at(i)<=j)
            {   
                dp.at(i).at(j)=max(dp[i-1][j],p[i]+dp[i-1][j-w[i]]);
            }
            else
            {
                dp.at(i).at(j)=dp.at(i-1).at(j);
            }
            
        }
    }

    cout<<dp.at(n).at(m)<<endl;
    cout<<"Items Included: "<<endl;
    for(int i=n,j=m;j>0,i>0;)
    {
        if(dp.at(i).at(j)==dp.at(i-1).at(j))
        {
            --i;
        }
        else
        {
            cout<<i<<" ";
            j=j-w.at(i);
            --i;
        }
        
    }
}
int main()
{
    FAST_IO;
  
    int n,t,i,j,k,v,u,q;
    int m;


    vector<int>p,w;
    p={0,60, 100, 120}; 
    w={0,10, 20, 30};
    m=50,n=3;
    knapsack(p,w,m,n);

    return 0;
}
