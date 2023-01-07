class Solution {
public:
int maximumTop(vector<int>& nums, int k) {
    int n = nums.size();
        
    
    if(n == 1){
        if(k&1) return -1;
        return nums[0];
    }
    int ans = -1;
    for(int i=0; i<n and i<k-1; i++){
        ans = max(ans, nums[i]);
    }
    if(k < n) 
    return max(nums[k], ans);

	return ans;
}

};
