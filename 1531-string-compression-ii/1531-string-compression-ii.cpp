int dp[101][27][101][101];
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
#define     inf                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}

class Solution {
public:
    string s;
    
    int solve(int idx, int last, int len, int k )
    {
        if(k<0)
            return INT_MAX/2;
        
        if(idx>=s.size()) return 0;
        
        int &ans = dp[idx][last][len][k];
        
        if(ans!=-1) return ans;
        
        if(s[idx]-'a'==last){
            
            int carry=(len==1||len==9||len==99);
            
            ans= carry+solve(idx+1, last, len+1, k);
        }
        else {
            ans=min(1+solve(idx+1, s[idx]-'a', 1, k), solve(idx+1, last, len,k-1));
        }
        return ans;
    }
    int getLengthOfOptimalCompression(string str, int k) 
    {

        s=str;
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k);
        
    }
    
};