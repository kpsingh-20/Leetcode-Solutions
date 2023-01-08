class Solution {
public:
#define     pb                  push_back
#define     ll                 long double
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
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     inf                 	998244353
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}


/*
int minimumLines(vector<vector<int>>& a) 
{
    if(a.size() == 1) return 0;
	if(a.size() == 2) return 1;

	ll slope;
    sort(all(a));
	int n = a.size();
	if(a[1][0] - a[0][0] == 0){
		slope = inf;
	}
	else
		slope = (ll)(a[1][1] - a[0][1])/ (ll)(a[1][0] - a[0][0]);


	int ans = 1;
	for(int i=2; i<n; i++){

		ll curr;                                    // yaha int likh diya tha
		if(a[i][0] - a[i-1][0] == 0){
			curr = inf;
		}
		else
			curr = (ll)(a[i][1] - a[i-1][1])/ (ll)(a[i][0] - a[i-1][0]);

		if(curr != slope){
			ans++;
			slope = curr;
		}
	}

return ans;
}

*/
    
    
int minimumLines(vector<vector<int>>& a) 
{
	pii slope;

	if(a.size() == 1) return 0;
	if(a.size() == 2) return 1;

	sort(all(a));
	int n = a.size();
	if(a[1][0] - a[0][0] == 0){
		slope = {inf, inf};
	}
	else{
		int dy = a[1][1] - a[0][1];
		int dx = a[1][0] - a[0][0];
		int g = __gcd(dx, dy);
		slope = {dy/g, dx/g};
		// slope = double(a[1][1] - a[0][1])/ double(a[1][0] - a[0][0]);
	}



	int ans = 1;
	for(int i=2; i<n; i++){

		pii curr;
		if(a[i][0] - a[i-1][0] == 0){
			curr = {inf, inf};
		}
		else{
			int dy = a[i][1] - a[i-1][1];
			int dx = a[i][0] - a[i-1][0];

			int g = __gcd(dx, dy);
			curr = {dy/g, dx/g};
			// curr = double(a[i][1] - a[i-1][1])/ double(a[i][0] - a[i-1][0]);
		}


		// cout << slope << " " << curr;br;
		if(curr != slope){
			ans++;
			slope = curr;
		}
	}

return ans;
}
};