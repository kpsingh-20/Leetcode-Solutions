class Solution {
public:
    
int func(int n, vector<int> &dp){
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    if(dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    for(int i=1; i*i <= n; i++){
        // cout << i << " " << i*i << endl;
        ans = min(ans, 1 + func(n-(i*i) ,dp));
    }
    
    return dp[n] = ans;

}
    
int numSquares(int n) 
{
    vector<int> dp(n+1, -1);
    return func(n,dp);
}
};