class Solution {
public:
bool increasingTriplet(vector<int>& nums) 
{
	int n = nums.size();

	int above = INT_MAX;

	int mini = INT_MAX;

	for(int i=0; i<n; i++){
		mini = min(mini, nums[i]);
		if(nums[i] > mini){
			if(nums[i] > above){
				return 1;
			}else{
				above = nums[i];
			}
		}

		// cout << mini << " " << above;br;
	}
	return 0;
}
    
    
};