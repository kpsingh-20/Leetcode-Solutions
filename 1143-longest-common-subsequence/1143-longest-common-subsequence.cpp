class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvvi                 vector<vvi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     fi(i,a,b)           for(int i=a; i<b; i++)
#define     fie(i,a,b)          for(int i=a; i<=b; i++)
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a[i];
// #define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ' 
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";

// s1 aur s2 ko pass by value bhejne se TLE aa rha tha, baki sab sahi he
    
// int func(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
// {
// 	if(i == s1.size() || j == s2.size())return 0;
// 	if(dp[i][j] != -1) return dp[i][j];

// 	if(s1[i] == s2[j]){
// 		return dp[i][j] = func(i+1, j+1, s1, s2, dp) + 1;
// 	}

// 	int a = func(i+1, j, s1, s2, dp);       
// 	int b = func(i ,j+1, s1, s2, dp);
// 	return dp[i][j] = max(a, b);
// }

// int longestCommonSubsequence(string text1, string text2) 
// {
//     int n = text1.size(), m = text2.size();
    
//     vector<vector<int>> dp(n+10, vector<int>(m+10, -1 ));
    
//     return func(0, 0, text1, text2, dp); 
// }
    
    
/// Testing on 15 dec....
vvi dp;

int func(string &s, string &t, int i, int j)
{
    if(i == s.size() or j == t.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]){
        return dp[i][j] = 1 + func(s, t, i+1, j+1);
    }

    return dp[i][j] = max(func(s, t, i+1, j), func(s, t, i, j+1));
}

int longestCommonSubsequence(string s, string t) 
{
    dp = vvi(s.size() +  1, vi(t.size() +1, -1));
    return func(s, t, 0, 0);
}
};