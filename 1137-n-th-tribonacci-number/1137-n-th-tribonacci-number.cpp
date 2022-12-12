class Solution {
public:
    
vector<int> dp;
int func(int n)
{
    if(n == 0 or n == 1) return n;
    if(dp[n] != -1) return dp[n];
    if(n == 2) return 1;
    
    return dp[n] = func(n-1) + func(n-2) + func(n-3);
}
    int tribonacci(int n) {
        dp = vector<int> (n+1, -1);
        return func(n);
        
    }
};