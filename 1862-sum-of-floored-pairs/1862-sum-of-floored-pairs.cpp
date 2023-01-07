class Solution {
public:

#define     ll                 	long long
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

int sumOfFlooredPairs(vector<int>& nums) 
{
	int n = nums.size();
	int N = 2e5 + 7;
	vi hash(N, 0);

	std::map<int, int> map;

	int maxi = 0;
	for(int i=0; i<n; i++)
	{
		hash[nums[i]]++;
		map[nums[i]]++;
		maxi = max(maxi, nums[i]);
	}

	for(int i=1; i<N; i++)
	{
		hash[i] += hash[i-1];
	}
	// for(int i=0; i<10; i++){
	// 	cout << i << " " << hash[i] << " ";br;
	// }br;

	ll ans = 0;
	for(auto x : map)
	{
		ll num = x.ff;
		ll freq = x.ss;

		ll j=1;
		ll curr = 0;
		for(ll i=num + num-1; i<N; i+=num){
			ll k = hash[i] - hash[i-num];
			curr += j*k;
			j++;
		}
		ans = ( ans+ (curr * freq))%M;
	}

return (ans)%M;
}

};