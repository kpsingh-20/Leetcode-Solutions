class Solution {
public:

#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vl                  vector<long long>
#define     vvi                 vector<vi>
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
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)		for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)		for(auto &x : grid){cinvec(x);}

int dfs(int node,int par, vector<pii> g[], vl &vis, vector<bool>& hasApple, vl &depth)
{
	if(vis[node]) return 0;
	vis[node] = 1;
	
	if(par != -1)
		depth[node] = 1 + depth[par];

	int ans = 0;
	if(hasApple[node]) ans = 1;
	for(auto &child : g[node]){
		int t = dfs(child.ff,node, g, vis, hasApple, depth);
		// cout << child.ff << " " << t;br;
		child.ss = t;
		ans += t;
	}

	return ans;
}

void dfs2(int node,int par, vector<pii> g[], ll &ans)
{
	for(auto child : g[node])
	{
		if(child.ff == par) continue;
		if(child.ss >= 1)
			ans -= (child.ss-1)*2;

		dfs2(child.ff, node, g, ans);
		// cout << child.ff << " " << child.ss;br;
	}
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
{
	int m = edges.size();
	vector<pii> g[n+1];

	for(int i=0; i<m; i++){
		int u = edges[i][0];
		int v = edges[i][1];

		g[u].pb({v, 0});
		g[v].pb({u, 0});
	}

	vl vis(n+1, 0);
	vl depth(n+1, 0);
	dfs(0,-1, g, vis, hasApple, depth);

	// coutspace(depth);br;						
	ll ans = 0;

	for(int i=0; i<n; i++)
	{
		if(hasApple[i]){	
			ans += 2*depth[i];				// for each appple, if I have to go back to 0;
		}
	}	

	dfs2(0,-1, g, ans);						// And for common nodes I am subtracting ans;


return (int)ans;
}

};