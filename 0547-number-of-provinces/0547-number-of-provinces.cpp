class Solution {
public:
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int, int>
#define     ppii                pair<int, pair<int, int>>
#define     all(a)              a.begin(),a.end()

    
// void dfs(int v, vi g[], vi &vis){
//     vis[v] = 1;

//     for(auto child : g[v]){
//         if(!vis[child])
//             dfs(child, g, vis);
//     }
// }
// int findCircleNum(vector<vector<int>>& isConnected) 
// {
//     int n = isConnected.size();
//     vi g[n+1];
//     vi vis(n+1, 0);

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if(i == j) continue;
//             if(isConnected[i][j] == 1){
//                 g[i+1].pb(j+1);
//             }
//         }
//     }


//     int ans = 0;
//     for(int i=1; i<=n; i++){
//         if(!vis[i]){
//             ans++;
//             dfs(i, g, vis);
//         }
//     }

//     return ans;
    
// }

    
    
    #define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
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
#define     inf                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}


vi par;

int find(int node)
{
	if(par[node] == node) return node;
	return find(par[node]);
}

void Union(int a, int b)
{
	int p = find(a);
	int q = find(b);

	par[p] = q;
}

int findCircleNum(vector<vector<int>>& isConnected) 
{
	int n = isConnected.size();
	par = std::vector<int>(n);
	for(int i=0; i<n; i++) par[i] = i;

	for(int i=0; i<isConnected.size(); i++)
	{
		for(int j=0; j<isConnected.size(); j++)
		{
			if(i == j) continue;
			if(isConnected[i][j])
			{
				Union(i, j);
			}
		}
		
	}

	int ans = 0;
	for(int i=0; i<n; i++){
		if(par[i] == i){
			ans++;
		}
	}

	return ans;
}

};