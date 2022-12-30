class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                 long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define 	vvc					std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     fi(i,a,b)           for(int i=a; i<b; i++)
#define     fie(i,a,b)          for(int i=a; i<=b; i++)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}

    
// Jitna dimag ka bhosda kiya he na isme utna karne ki jarurat nhi thi lekin thik hi he,
void dfs(int v, vvi& graph, vi &topo, vi &vis){
	vis[v] = 1;

	for(auto child : graph[v]){
		if(vis[child]) continue;
		dfs(child, graph, topo, vis);
	}

	topo.pb(v);
}

vvi ans;
void func(int v,vvi &g,  vector<vvi> &arrays, vi &vis, vi curr){

	// if(vis[v]){
	// 	return;
	// }
	vis[v] = 1;
	curr.pb(v);
	// cout << v;br;
	for(auto child : g[v]){
		if(vis[child]){
			// cout << child;br;

			for(auto x : arrays[child]){
				vi temp = curr;
				temp.insert(temp.end(), all(x));
				if(v == 0){
					// reverse(all(temp));
					ans.pb(temp);
				}
				arrays[v].pb(temp);
			}
			continue;
		}

	}
	// br;
}

vvi allPathsSourceTarget(vvi& graph) 
{	
	int n = graph.size();
	vi vis(n, 0), topo;
    
    for(int i=0; i<n; i++){
    	if(!vis[i]){
    		dfs(i, graph, topo, vis);
    	}
    }

    vector<vvi> arrays(n);

    arrays[n-1].pb({n-1});
    vi curr;
    vis.resize(n, 1);
    vis[n-1] = 1;
    for(int i=0; i<n; i++){
    	if(topo[i] == n-1) continue;
    	func(topo[i], graph, arrays, vis, curr);
    }

    // for(auto x : arrays){
    // 	coutvvi(x);br;
    // }
    
    return ans;
}

};