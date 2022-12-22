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


void dfs(int node, int par, vi g[], vi &count)
{
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child, node, g, count);
        count[node] += count[child];
    }
}

void dfs2(int node, int par, vi g[], vi &res, vi &count)
{
    for(auto child : g[node]){
        if(child == par ) continue;

        res[child] = res[node] - count[child] + res.size() - count[child];

        dfs2(child, node, g, res, count);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
{
    vi g[n];
    for(auto x : edges){
        g[x[0]].pb(x[1]);   
        g[x[1]].pb(x[0]);
    }

    vi count = vi(n, 1);
    dfs(0, -1, g, count);
    int x = 0, dist = 0;

    queue<int> q;
    vi vis(n, 0);
    q.push(0); vis[0] = 1;

    while(!q.empty())
    {
        int size = q.size();
        while(size--){
            x += dist;
            int node = q.front(); q.pop();
            for(auto child : g[node]){
                if(vis[child]) continue;
                vis[child] = 1;
                q.push(child);
            }
        }
        dist++;
    }
    // coutspace(count);br;
    // cout << x;br;

    vi res(n); res[0] = x;
    dfs2(0, -1, g, res, count);

    // coutspace(res);br;


return res;
}
};