class Solution {
public:
    
#define     pb                  push_back
#define     vi                  vector<int>
#define     all(a)              a.begin(),a.end()

    
vi answerQueries(vi& nums, vi& queries) {
	int n = nums.size();
	sort(all(nums));

	std::map<int, int> map;
	set<int> st;
	st.insert(0);
	int sum = 0;
	map[0] = 0;
	for(int i=0; i<nums.size(); i++){
		sum += nums[i];
		map[sum] = i+1;
		st.insert(sum);
	}

	vi ans;
	for(auto q : queries)
	{
		auto it = st.upper_bound(q);
		// cout << *it;br;
		it--;

		ans.pb(map[*it]);
	}

	return ans;	
}

};