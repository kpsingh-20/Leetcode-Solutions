class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
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

// set wale ko bas priority queue me change kiya he.
vl func1(vi &nums){
	vl pre;
	// set<ll>  st;
	priority_queue<ll> pq;
	ll n = nums.size(); n = n/3;
	ll sum = 0;
	for(ll i=0; i<n; i++){
		// st.insert(nums[i]);
		pq.push(nums[i]);
		sum += nums[i];
	}

	// auto it = --st.end();
	pre.pb(sum);
	for(ll i=n; i<2*n; i++){
		// st.insert(nums[i]);	
		pq.push(nums[i]);

		// sum = sum -*(--st.end()) + nums[i];

		sum = sum -pq.top() + nums[i];

		// st.erase(--st.end());
		pq.pop();
		pre.pb(sum);
	}

	return pre;
}


vl func2(vi nums){
	ll n = nums.size(); n = n/3;

	// set<ll> st;
	priority_queue<ll, vl, greater<ll>> pq;
	ll sum = 0;

	vector<ll> ans;
	for(ll i=0; i<n; i++){
		// st.insert(nums[i]);
		pq.push(nums[i]);
		sum += nums[i];
	}
	ans.pb(sum);

	// auto it = st.begin();
	for(int i=n; i<2*n; i++){
		// st.insert(nums[i]);
		pq.push(nums[i]);

		// sum = sum -*(st.begin()) + nums[i];
		sum = sum -pq.top() + nums[i];
		// st.erase(st.begin());
		pq.pop();
		ans.pb(sum);
	}
	reverse(all(ans));
	return ans;
}
long long minimumDifference(vector<int>& nums) 
{
	int n = nums.size();
	n = n/3;

	
	vl pre = func1(nums);reverse(all(nums));
	
	vl suf = func2(nums);reverse(all(nums));




	ll ans = 1e18;

	for(int i=0; i<pre.size(); i++){
		// cout << pre[i] << " " << suf[i] << " " << pre[i] - suf[i];br;
		ans = min(ans, pre[i] - suf[i]);
	}

return ans;
}
};