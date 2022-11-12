class Solution {
public:
 
// vector<int> twoSum(vector<int>& nums, int target) 
// {	
// 	int n = nums.size();
// 	std::vector<int> ans;
// 	for(int i=0; i<n; i++)
// 	{
// 		auto it = find(nums.begin(), nums.end(),target - nums[i]);
// 		if(it != nums.end() &&  (i != it - nums.begin())){
// 			ans.push_back(i);
// 			ans.push_back(it - nums.begin());
// 			break;
// 		}	
// 	}
// 	return ans;
// }
    
    
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     fi(i,a,b)           for(int i=a; i<b; i++)
#define     fie(i,a,b)          for(int i=a; i<=b; i++)
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ' 
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";


vector<int> twoSum(vector<int>& nums, int target) 
{
	vi ans;

	std::map<int, int> map;

	for(int i=0; i<nums.size(); i++){
		if(map[target - nums[i]] != 0 and map[target- nums[i]] != i+1){
			ans.pb(map[target - nums[i]]-1);
			ans.pb(i);
			break;
		}
		map[nums[i]] = i+1;
	}

	for(auto i : map){
		cout << i.ff << " " << i.ss;br;
	}
	return ans;
}

};