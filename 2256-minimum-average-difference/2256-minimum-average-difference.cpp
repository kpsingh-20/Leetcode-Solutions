class Solution {
public:
#define     ll                  long long


int minimumAverageDifference(vector<int>& nums) 
{
    ll n = nums.size();
    if(n == 1) return 0;

    ll ans;
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
    }


    ll curr = 0;
    ll ele = 0;

    ll globalAvg = INT_MAX;
    for(int i=0; i<n-1; i++)
    {
        curr += nums[i];
        sum -= nums[i];
        int avg = abs(curr/(i+1) -  sum/(n-i-1));

        if(avg < globalAvg){
            globalAvg = avg;
            ans = i;
        }
    }
    curr += nums[n-1];
    if(curr/(n) < globalAvg){
        ans = n-1;
}
    return ans;
}
};