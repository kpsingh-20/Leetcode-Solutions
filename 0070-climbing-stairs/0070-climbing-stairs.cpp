class Solution {
public:
    
vector<int> dp;
int func(int n)
{ 
    if(n == 1 or n == 0 or n == 2) return n;
    if(dp[n] != -1) return dp[n];
    int ans = func(n-1) + func(n-2);
    // ans += func(n-2) + 1;
    
    return dp[n] = ans;
}
    
int climbStairs(int n) {
    dp = vector<int>(n + 1, -1);
    return func(n);
}
};