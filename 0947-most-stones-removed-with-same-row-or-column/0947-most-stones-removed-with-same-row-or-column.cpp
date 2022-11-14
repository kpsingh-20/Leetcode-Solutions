class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
	#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define 	vvc					std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     M                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}


void dfs(int i, int j, map<pii, vector<pii>> &mp, map<pii, int> &vis, int &ans)
{
	vis[{i, j}] = 1;
	ans++;
	std::vector<pii> v = mp[{i, j}];

	for(int i=0; i<v.size(); i++)
	{
		int p = v[i].ff;
		int q = v[i].ss;

		if(vis[{p, q}]) continue;

		dfs(p, q, mp, vis, ans);
	}

}

int removeStones(vvi& stones) 
{
	int n = stones.size();
	int N = 1e4+7;

	std::map<pii, vector<pii>> mp;

	for(int i=0; i<n; i++){
		int x = stones[i][0];
		int y = stones[i][1];

		for(int j=0; j<n; j++){
			int p = stones[j][0];
			int q = stones[j][1];
			if(x == p and y == q) continue;
			if(x == p || y == q)
			{
				mp[{x, y}].pb({p, q});
			}
		}
	}

	// for(auto x : mp)
	// {
	// 	cout << x.ff.ff << "," << x.ff.ss << "-";
	// 	std::vector<pii> &v = x.ss;br;
	// 	for(int i=0; i<v.size(); i++){
	// 		cout << v[i].ff << " " << v[i].ss;br;
	// 	}br;
	// }

	std::map<pii, int> vis;

	int ans = 0;
	for(int i=0; i<n; i++)
	{
		int p = stones[i][0];
		int q = stones[i][1];

		if(!vis[{p, q}]){
			int temp = 0;
			dfs(p, q, mp, vis, temp);
			ans += temp -1;
		}
	}

	return ans;	

}
};