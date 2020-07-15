#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++ 
    ((cout << args << " "), ...);
    cout<<endl;
}

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
const double EPS = 1e-9;
const int MXX = 1e5 + 5;
class Tree{
private: 
    vector<vector<int> >  adj;
    int size , n ,l; 
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
public: 
    Tree(int sz): size(sz) , n(sz)
    {
        adj.resize(sz);
        cout<<sz<<endl; 
    }

    void dfs(int v, int p)
    {
        tin[v] = ++timer ; 
        up[v][0] =  p;
        for(int i = 1 ; i<= l ; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1] ;    
        }

        for(int u : adj[v])
        {
            if(u!= p ) 
                dfs(u, v) ; 
        }
        tout[v] = ++timer; 
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
     
    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }


    void preprocess(int root) 
    {
        tin.resize(n) ; 
        tout.resize(n) ; 
        timer = 0 ; 
        l = ceil(log2(n)) ; 
        up.assign(n, vector<int> (l+1));
        dfs(root, root) ; 
    }

    void addEdge(int a,int b) 
    { 
        adj[a].push_back(b); 
        // adj[b].push_back(a); 
    } 

    void print()
    {
        for(int i = 0 ; i< n ;i++)
        {
            cout<<i<<" :  " ; 
            for(int x : adj[i])
            {
                cout<<x <<" " ; 
            }
            cout<<endl;
        }                
    }
};

int main()
{
    FAST_IO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    int n,t,i,j,k;
    n = 8 ; 
    Tree tree (n+1); 
    tree.addEdge(0,1) ; 
    tree.addEdge(1,2); 
    tree.addEdge(1,3); 
    tree.addEdge(2,4); 
    tree.addEdge(2,5); 
    tree.addEdge(2,6); 
    tree.addEdge(3,7); 
    tree.addEdge(3,8); 
    tree.print() ; 

    tree.preprocess(0) ; 

    cout << "LCA(4, 7) = " << tree.lca(4,7) << endl; 
    cout << "LCA(4, 6) = " << tree.lca(4,6) << endl; 

    return 0;
}