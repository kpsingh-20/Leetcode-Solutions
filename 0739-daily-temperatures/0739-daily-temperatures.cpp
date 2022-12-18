class Solution {
public:

#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                 long long
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
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)		for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)		for(auto &x : grid){cinvec(x);}

vi dailyTemperatures(vi& arr) {
	int n = arr.size();
	vi ans(n, 0);

	stack<pii> st;

	for(int i=n-1; i>=0; i--)
	{
		while(!st.empty() and st.top().ff <= arr[i]){
			st.pop();
		}

		if(!st.empty()){
			int prev = st.top().ss;
			ans[i] = prev - i;
		}
		st.push({arr[i], i});
	}

	return ans;

}
};