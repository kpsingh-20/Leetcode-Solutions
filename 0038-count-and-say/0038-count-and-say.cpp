class Solution {
public:
string countAndSay(int n) {

    if(n == 1){
        return "1";
    }
    
    string s = countAndSay(n-1);
        
    string ret;
    for(int i=0; i<s.size(); )
    {
        char x = s[i];
        int j = i+1;
        while(j<s.size() and s[j] == s[i]){
            j++;
        }
        string cnt = to_string(j-i);
        ret.insert(ret.end(), cnt.begin(), cnt.end());
        
        ret.push_back(x);
        i = j;
    }
    
    return ret;

}
};