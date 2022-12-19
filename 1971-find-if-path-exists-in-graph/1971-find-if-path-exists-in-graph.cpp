class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                 long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvvi                 vector<vvi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)      for(int i=0; i<n; i++) cin >> a[i];
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}

void dfs(int node, vi g[], vi &vis){

    for(auto child : g[node]){
        if(vis[child]) continue;
        vis[child] = 1;
        dfs(child, g, vis);
    }
}

bool validPath(int n, vvi& edges, int s, int d) {
    int m = edges.size();

    vi g[n];

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        g[u].pb(v);
        g[v].pb(u);
    }
    
    
    vi vis(n, 0);
    vis[s] = 1;
    dfs(s, g, vis);

    return vis[d];
}
};