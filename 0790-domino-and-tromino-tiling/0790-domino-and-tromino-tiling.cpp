class Solution {
public:
    
vector<int> dp; 
int M = 1e9+7;
    
    int func(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        
        if(dp[n] != -1) return dp[n];
        return dp[n] = (2*1LL*func(n-1) +0LL+ func(n-3))%M;

    }
    
    int numTilings(int n) {
        dp = vector<int>(n+1, -1);
        
        return func(n);
    }
};