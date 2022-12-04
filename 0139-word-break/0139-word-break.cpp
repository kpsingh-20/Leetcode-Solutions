class Solution {
public:
//     bool wordBreak(string s, vector<string>& wordDict) {
        
//     }
    
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     fi(i,a,b)           for(int i=a; i<b; i++)
#define     fie(i,a,b)          for(int i=a; i<=b; i++)
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ' 
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";

std::map<pair<int, string>, int> dp;

int func(string A, vector<string> &B,map<string, int> &map, int i, string curr)
{
				// cout <<i << " " << curr;br

	if(i == A.size()){
		if(map[curr]){
			return 1;
			br;
		}
		return -1;		
	}

	if(dp[{i, curr}] != 0) return dp[{i,curr}]; 

	int a = 0, b = 0;
	if(map[curr]){
		string curr1 = "";
		curr1 += A[i];
		a = func(A, B, map, i+1, curr1);
		if(a == 1) return 1;


		curr += A[i];
		b = func(A, B, map, i+1, curr);

		return dp[{i, curr}] = max(a, b);
	}

	a = func(A, B, map, i+1, curr + A[i]);
	return dp[{i, curr}] = a;
}

bool wordBreak(string A, vector<string> &B) 
{

	map<string, int> map;

	for(string s : B){
		map[s] = 1;
	}
	// return func(A, B, map, 0, "");
    
    if(func(A, B, map, 0, "") == 1) return 1;
	return 0;
}
};