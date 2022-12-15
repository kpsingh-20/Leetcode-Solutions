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

    
/*
vi s, t;

int func(int i, int minis, int minit)                   // wrong
{
    if(i == s.size()) return 0;

    if(s[i] <= minis){                                  // yaha change kiya
        if(t[i] <= minis) return -1;
        return 1 + func(i+1, t[i], s[i]);
    }
    if(t[i] <= minit){
        if(s[i] <= minis) return -1;
        return 1 + func(i+1, t[i], s[i]);
    }

    int a = func(i+1, s[i], t[i]);
    int b = func(i+1, t[i], s[i]);

    if(a == -1) return 1 + b;
    if(b == -1) return a;

    return min(a, 1 + b);
}



int minSwap(vi& nums1, vi& nums2) 
{   
    s = nums1;
    t = nums2;
    return func(0, -1, -1);

return -1;
}
*/
////////////////////////////////////////////////////////////////////////////////
vi s, t;    
vvi dp;
int func(int i, int minis, int minit, bool swapped)
{
    if(i == s.size()) return 0;

    if(dp[i][swapped] != -1) return dp[i][swapped];

    int swap = 1e9, noswap = 1e9;

    if(s[i] > minis and t[i] > minit){
        noswap = func(i+1, s[i], t[i], 0);
    }

    if(s[i] > minit and t[i] > minis){
        swap = 1 + func(i+1, t[i], s[i], 1);
    }

    return dp[i][swapped] = min(swap, noswap);
}



int minSwap(vi& nums1, vi& nums2) 
{   
    s = nums1;  int n = s.size();
    t = nums2;  int m = t.size();

    dp = vvi(n + 1, vi(2, -1));

    return func(0, -1, -1, 0);

return -1;
}
    
    
    
};