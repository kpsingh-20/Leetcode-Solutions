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

ll maximumSubsequenceCount(string text, string pattern) 
{
    string s = "#";                             
    for(auto &c : text){
        if(c == pattern[0] or c == pattern[1]){
            s.pb(c);
        }
    }
    s.pb('#');

    ll ans = 0;
    ll n = s.size();
    vector<ll> pre(n); pre[0] = 0;
    vector<ll>  suf(n); suf[n-1] = 0;

    for(ll i=1; i<n; i++){
        pre[i] = pre[i-1];
        if(s[i] == pattern[0]) pre[i]++;
    }

    for(ll i=n-2; i>=0; i--){
        suf[i] = suf[i+1];
        if(s[i] == pattern[1]) suf[i]++;
    }

    for(ll i=0; i<n; i++){
        if(s[i] == pattern[0]){
            ans += suf[i+1];
        }
        // ans = max(ans, pre[i] * 1LL *suf[i]);        // for this case : mpmp mp
    }
    // coutspace(pre);br
    // coutspace(suf);br

    // if adding a;
    ans += max(pre[n-1], suf[0]);

return ans;
}


};