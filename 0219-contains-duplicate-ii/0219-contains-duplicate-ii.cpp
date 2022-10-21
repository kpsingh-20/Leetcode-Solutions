class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    map<int, int> map;
    
    for(int i=0; i<nums.size(); i++){
        if(map.find(nums[i]) == map.end()){
            map[nums[i]] = i;
        }else{
            if(abs(map[nums[i]] - i) <= k){
                return 1;
            }
            map[nums[i]] = i;
        }
    }
    return 0;
}
};