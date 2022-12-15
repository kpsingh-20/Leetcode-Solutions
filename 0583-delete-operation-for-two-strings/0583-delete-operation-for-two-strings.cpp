class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                 long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvvi                 vector<vvi>
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
string s,t;
int func(int i, int j)
{
    if(i == s.size() ){
        return t.size() - j;
    }else if(j == t.size()){
        return s.size() - i;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = func(i+1, j+1);

    return dp[i][j] = 1 + min(func(i+1, j), func(i, j+1));
}

int minDistance(string s1, string s2) {
    s = s1;
    t = s2;
    dp = vvi(s.size() + 1, vi(t.size() + 1, -1));
    return func(0, 0);
}
};