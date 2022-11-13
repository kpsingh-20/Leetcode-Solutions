class Solution {
public:
    
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     vi                  vector<int>

    
vector<double> medianSlidingWindow(vi& nums, int k) 
{	
	int n = nums.size();
	std::vector<double> ans;

	multiset<int> window(nums.begin(), nums.begin()+k);
	auto mid = next(window.begin(), k/2);

	for(int i=k; ; i++)
	{
		ans.pb(((double)(*mid) + *prev(mid, 1- k%2))/2);

		if(i == n) return ans;

		window.insert(nums[i]);
		if(nums[i] < *mid){
			mid--;
		}
		if(nums[i-k] <= *mid){
			mid++;
		}

		window.erase(window.lower_bound(nums[i-k]));
	}

	return ans;
} 
};