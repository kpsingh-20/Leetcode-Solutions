class Solution {
public:
    
vector<int> dp;
    
int func(int i, vector<int> &nums){
    if(i >= nums.size()) return 0;
        
    if(dp[i] != -1) return dp[i];
    int a = func(i+1, nums);
    int b = func(i+2, nums) + nums[i];
    
    return dp[i] = max(a, b);
} 
int rob(vector<int>& nums) {
    dp = vector<int>(nums.size()+1, -1);
    return max(func(0, nums), func(1, nums));
}
};