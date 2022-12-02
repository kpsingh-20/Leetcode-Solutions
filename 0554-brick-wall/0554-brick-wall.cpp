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
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}
int leastBricks(vvi& wall) 
{
    int n = wall.size();

    // coutvvi(wall);br;
    std::map<int, int> map;
    for(int i=0; i<wall.size(); i++)
    {
        int curr = 1;
        int total = 0;
        for(int j=0; j<wall[i].size()-1 ; j++){
            total += wall[i][j];

            map[total]++;
        }
    }
    int ans = INT_MAX;


    for(auto x : map){
        cout << x.ff << " " << x.ss;br;
        ans = min(ans, n - x.ss);
    }
    if(ans == INT_MAX) return n;

    return ans;
}
};