class Solution {
public:
    
    
#define     ll                 long long
#define     pb                  push_back
#define     vi                  vector<int>
#define     vl                  vector<long long>
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

int minimumRounds(vector<int>& tasks) 
{
	int n = tasks.size();

	std::map<ll, ll> cnt;

	for(int i=0; i<tasks.size(); i++){
		cnt[tasks[i]]++;
	}

	ll ans = 0;

	for(auto x : cnt)
	{
		if(x.ss == 1) return -1;
		if(x.ss == 2){
			ans++;
			continue;
		}
		if(x.ss % 3 == 0){
			ans += x.ss/3;
			continue;
		}

		ans += x.ss/3 + 1;

	}

return ans;
}
    
    
};