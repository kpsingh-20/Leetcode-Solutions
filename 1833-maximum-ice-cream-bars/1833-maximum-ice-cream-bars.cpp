class Solution {
public:
int maxIceCream(vector<int>& a, int coins) {
    sort(a.begin(), a.end());
    
    int ans = 0;
    for(int i=0; i<a.size(); i++)
    {
        if(coins >= a[i]){
            ans++;
            coins -= a[i];
        }else{
            break;
        }
    }
    
    return ans;
}
};