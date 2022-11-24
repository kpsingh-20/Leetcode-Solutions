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


bool isValid(int i, int j, int n, int m){
	return i>=0 and j>=0 and i<n and j<m;
}

std::vector<pair<int, int> > directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void func(int i, int j, int curr, vector<vector<char>>& board, string &word, bool &ans, vvi &vis)
{
	int n = board.size();
	int m = board[0].size();

	if(ans == 1){
		return;
	}
	if(curr == word.size()){
		ans = 1;
		return;
	}

	for(auto dir : directions){
		int x = i + dir.ff;
		int y = j + dir.ss;

		if(!isValid(x, y, n, m)) continue;
		if(vis[x][y]) continue;
		if(board[x][y] == word[curr])
		{
			// cout << board[x][y] << " " << word[curr];br;
			vis[x][y] = 1;
			func(x, y, curr + 1, board, word, ans, vis);
            vis[x][y] = 0;
			if(ans == 1){
				return;
			}
		}

	}

}

bool exist(vector<vector<char>>& board, string word) 
{
	int n = board.size();
	int m = board[0].size();
	char c = word[0];

	std::vector<pair<int, int>> v;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(board[i][j] == c){
				v.push_back({i, j});
			}
		}
	}


	if(word.size() == 1 and v.size() >= 1) return 1;	

	bool ans = 0;
	int curr = 1;
	for(int i=0; i<v.size(); i++){
		vvi vis(n, vi(m, 0));
		vis[v[i].ff][v[i].ss] = 1;
		func(v[i].ff, v[i].ss, curr , board, word, ans, vis);
        
		if(ans){
			return 1;
		}
	}
	return ans;



}

};