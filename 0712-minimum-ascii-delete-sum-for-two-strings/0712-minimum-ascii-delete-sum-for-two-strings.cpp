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

string s, t;

vvi dp;
int func(int i, int j)
{   
    if(i == s.size()){
        int ret = 0;
        for( ; j<t.size(); j++){
            ret += t[j];
        }
        return ret;
    }else if(j == t.size()){
        int ret = 0;
        for( ; i<s.size(); i++){
            ret += s[i];
        }
        return ret;
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) return dp[i][j] = func(i+1, j+1);

    int a = (int)s[i] + func(i+1, j);
    int b = (int)t[j] + func(i, j+1);

    return dp[i][j] = min(a, b);
}


int minimumDeleteSum(string s1, string s2) 
{
    s = s1; int n = s.size();
    t = s2; int m = t.size();

    dp = vvi(n+1, vi(m+1, -1));

    return func(0, 0);
return -1;
}

};