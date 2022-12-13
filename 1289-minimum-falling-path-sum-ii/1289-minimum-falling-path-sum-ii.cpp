class Solution {
public:
#define     vi                  vector<int>
#define     vvi                 vector<vi>

vvi dp;
int func(vvi &matrix, int i, int j)
{
	int n = matrix.size();
	int m = matrix[0].size();
	if(i == n){
		return 0;
	}
	if(dp[i][j] != -1) return dp[i][j];
	int a = INT_MAX;

	for(int k=0; k<m; k++){
		if(k == j) continue;
		a = min(a, func(matrix, i+1, k));
	}
    if(a == INT_MAX){
        return dp[i][j] = matrix[i][j];
    }
	return dp[i][j] = matrix[i][j] + a;
}

int minFallingPathSum(vvi& matrix) 
{
	int n = matrix.size();
	int m = matrix[0].size();

	dp = vvi(n, vi(m, -1));
	int ans = INT_MAX;
	for(int j=0; j<m; j++){
		ans = min(ans, func(matrix, 0, j));
	}

	return ans;
}
};