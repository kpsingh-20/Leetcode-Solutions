class Solution {
public:
int dp[20];

int func(int n)
{
    if(n == 0 or n == 1){
        return 1;
    }
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += func(i-1) * func(n-i);
    }
    return dp[n] = ans;
}

int numTrees(int n) {
    memset(dp, -1, sizeof(dp));
    return func(n);
}
};
