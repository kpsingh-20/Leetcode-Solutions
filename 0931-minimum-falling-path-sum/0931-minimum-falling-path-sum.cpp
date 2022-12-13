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
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}

vvi dp;
int func(vvi &matrix, int i, int j)
{
	int n = matrix.size();
	int m = matrix[0].size();
	if(i == n){
		return 0;
	}
	if(dp[i][j] != -1) return dp[i][j];
	int a = INT_MAX;
	int b = INT_MAX;
	int c = INT_MAX;

	if(j - 1 >= 0) a = func(matrix, i+1, j-1);
					b = func(matrix, i+1, j);
	if(j + 1 < m)  c = func(matrix, i+1, j+1);

	return dp[i][j] = matrix[i][j] + min({a, b, c});
}

int minFallingPathSum(vvi& matrix) 
{
	int n = matrix.size();
	int m = matrix[0].size();

	dp = vvi(n, vi(m, -1));
	int ans = INT_MAX;
	for(int j=0; j<m; j++){
		ans = min(ans, func(matrix, 0, j));
	}

	return ans;
}
};