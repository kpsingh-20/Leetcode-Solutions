class Solution {
public:

    

#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvvi                vector<vvi>
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
#define     inf                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}
std::vector<std::vector<string>> ans;

bool isPal(string s)
{
    int l = 0;
    int r = s.size()-1;

    while(l<=r){
        if(s[l++] != s[r--]){
            return 0;
        }
    }
    return 1;
}

void func(int i, string &s, std::vector<string> curr)
{
    if(i == s.size()){
        ans.pb(curr);
        return;
    }
    for(int j =i; j<s.size(); j++)
    {
        if(isPal(s.substr(i, j- i +1))){
            curr.pb(s.substr(i, j-i+1));
            func(j+1, s, curr);
            curr.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) 
{   
    func(0, s, {});


    return ans;
}    


};