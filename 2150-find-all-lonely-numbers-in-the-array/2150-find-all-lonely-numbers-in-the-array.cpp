class Solution {
public:
    
    
// O(NlogN) time and O(N) space
vector<int> findLonely(vector<int>& nums) 
{
    int n = nums.size();
    map<int, int> hash;
    
    set<int> st;

    for(auto &num : nums)
    {
        hash[num]++;
        // st.insert(num);                                         // O(N)
    }
    
    vector<int> ans;
    for(int i=0; i<nums.size(); i++)
    {
        int num = nums[i];
        if(hash[num] >1) continue;
        
        bool flag = 0;
    
            int l = num - 1;
            if(hash.find(l) != hash.end()) flag = 1;

            int r = num + 1;
            if(hash.find(r) != hash.end()) flag = 1;

        
        if(!flag){
            ans.push_back(num);
        }
        
        
    }
    
    return ans;

}
};