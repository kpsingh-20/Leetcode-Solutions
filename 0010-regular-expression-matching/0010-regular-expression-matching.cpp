class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvc                 std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
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


bool func(int i, int j, string &s, string &p)
{

    if(i >= s.size() and j >= p.size()){
        return 1;
    }
    if(i < s.size() and j>= p.size()){
        return 0;
    }

    if(j+1 < p.size() and p[j+1] == '*'){
        bool b=0;
        bool a = func(i, j+2, s, p);
        if(i<s.size() and (s[i] == p[j] or p[j] == '.')){
            b =func(i+1, j, s, p);
        }
        return (a or b);
    }
    if( i<s.size() and (s[i] == p[j] or p[j] == '.')){
        return func(i+1, j+1, s, p);
    }
    return 0;
}

bool isMatch(string s, string p) 
{
    return func(0, 0, s, p);
}

};