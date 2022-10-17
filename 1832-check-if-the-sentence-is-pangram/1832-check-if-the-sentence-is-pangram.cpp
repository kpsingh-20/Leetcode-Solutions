class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> hash(26, 0);
        
        for(int i=0; i<s.size(); i++){
            hash[s[i] - 'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(hash[i] == 0){
                return 0;
            }
        }
        return 1;
    }
};