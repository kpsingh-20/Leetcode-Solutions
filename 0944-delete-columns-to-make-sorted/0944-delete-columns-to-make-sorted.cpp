class Solution {
public:
int minDeletionSize(vector<string>& strs) {
    int ans = 0;
    for(int j=0; j<strs[0].size(); j++){
        char maxi =  strs[0][j];
        bool flag = 0;
        for(int i=1; i<strs.size(); i++){
            if(maxi > strs[i][j]){
                flag = 1;
                break;
            }
            maxi = strs[i][j];
        }
        if(flag){
            ans++;
        }
    }
    return ans;
}
};