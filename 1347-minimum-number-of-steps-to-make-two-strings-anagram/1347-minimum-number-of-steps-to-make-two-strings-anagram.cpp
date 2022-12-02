class Solution {
public:

int minSteps(string s, string t) 
{
    int n = s.size();

    std::vector<int> freq(26, 0);
    for(int i=0; i<n; i++){
        freq[s[i] - 'a']++;
    }

    int ret = 0;
    for(int i=0; i<n; i++){
        if(freq[t[i] - 'a'] == 0) ret++;
        else freq[t[i] - 'a']--;
    }

    return ret;

}
    
};