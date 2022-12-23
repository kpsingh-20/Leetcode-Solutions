class Solution {
public:

    
 
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()


int dp[5007][2];
int func(int i, int canBuy, vi& price)
{
    if(i >= price.size()) return 0;

    if(dp[i][canBuy] != -1) return dp[i][canBuy];
    if(canBuy){
        int a = func(i+1, 0, price)- price[i];
        int b = func(i+1, 1, price);
        return dp[i][canBuy] = max(a,b);
    }   
    else{
        int a = func(i+2, 1, price) + (price[i]);
        int b = func(i+1, 0, price);

        return dp[i][canBuy] = max(a, b);
    }
}

int maxProfit(vector<int>&price)
{
    int n =price.size();
    memset(dp, -1, sizeof(dp));
    return func(0, 1, price);

}
};