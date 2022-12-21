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

bool func(int node, vi g[],vi &vis, int k)
{
    if(vis[node]){
        if(vis[node] == k) return 1;
        return 0;
    }
    // cout << node << " " << k;br;
    vis[node] = k;

    bool ans = 1;
    for(auto child : g[node]){
        int temp = func(child, g, vis, -1*k);
        if(temp == 0) return 0;
    }
    return 1;

}

bool possibleBipartition(int n, vvi& dislikes) 
{
    vi g[n+1];

    for(int i=0; i<dislikes.size(); i++){
        int u = dislikes[i][0];
        int v = dislikes[i][1];

        g[u].pb(v);
        g[v].pb(u);
    }

    vi vis(n+1, 0);

    int ans= 1;
    for(int i=1; i<=n; i++){
        if(vis[i] == 0)
        if(func(i, g,vis, 1) == 0){
            // cout << "fdsa  " <<i;br;
            ans = 0;
            break;
        }
    }
    // coutspace(vis);br;
    return ans;

}

};