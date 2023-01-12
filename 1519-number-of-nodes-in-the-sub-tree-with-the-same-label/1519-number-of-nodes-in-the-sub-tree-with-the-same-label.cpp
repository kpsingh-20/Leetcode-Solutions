class Solution {
public:
    

    
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

    
// In this question I am returning a map which gives runtime of 2284 ms, and vortubrac passess array and vector which gives runtime of 800ms and 1200 ms respectively, 

// as the labels[node] can only be 26 so passing or returning it won't give TLE.
    
vvi g;

map<char, int> dfs(int node, int par, string &labels, vi &ans)
{
	if(g[node].size() == 1 and g[node][0] == par){
		map<char, int> mp;
		mp[labels[node]]++;
		ans[node] = mp[labels[node]];
		return mp;
	}
	std::map<char, int> f;
	std::map<char, int> final;
	for(auto child : g[node]){
		if(child  == par) continue;
		f = dfs(child, node, labels, ans);

		for(auto x : f){
			// cout << x.ff << " " << x.ss;br;
			final[x.ff] += x.ss;
		}
		// br
	}
	final[labels[node]]++;

	// cout << node << " " << labels[node] << " " << final[labels[node]];
	ans[node] = final[labels[node]];
	return final;
}

vector<int> countSubTrees(int n, vvi& edges, string labels) 
{
	g = vvi(n);

	for(auto v  : edges){
		g[v[0]].pb(v[1]);
		g[v[1]].pb(v[0]);
	}

	vi ans(n, 0);
	dfs(0, -1, labels, ans);


return ans;
}
    
    
};