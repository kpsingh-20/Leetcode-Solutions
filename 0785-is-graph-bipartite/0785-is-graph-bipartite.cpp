class Solution {
public:
//     bool isBipartite(vector<vector<int>>& graph) {
        
//     }
    
    
#define     pb                  push_back
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


void dfs(int node, vvi &g, vi &vis, int k, int &ans){
	if(ans == 0) return;

	if(vis[node]){
		if(vis[node] != k){
			ans = 0;
		}
		return;
	}

	vis[node] = k;

	for(auto child : g[node]){
		dfs(child, g, vis, -k, ans);
	}
}

bool isBipartite(vector<vector<int>>& g){

// 	int n; cin >> n;

// 	vi g[n+1];

// 	for(int i=0; i<n; i++){
// 		int u, v; cin >> u >> v;

// 		g[u].pb(v);
// 		g[v].pb(u);
// 	}

	int ans = 1;
    int n = g.size();
	vi vis(n, 0);

	for(int i=0; i<n; i++){
		if(!vis[i]){
			int curr = 1;
			dfs(i, g, vis,1, curr);
			if(!curr) return 0;
		}
	}
	
return 1;
}
};