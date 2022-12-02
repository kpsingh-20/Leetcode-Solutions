class Solution {
public:
int minSteps(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();

    std::vector<int> freq1(26, 0), freq2(26, 0);

    for(int i=0; i<n1; i++){
        freq1[s[i] - 'a']++;
    }
    for(int i=0; i<n2; i++){
        freq2[t[i] - 'a']++;
    }

    int ans = 0;
    
    for(int i=0; i<26; i++){
        ans += abs(freq2[i] - freq1[i]);
    }
    return ans;
}

};