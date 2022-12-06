class Solution {
public:
    
bool upper(char c)
{
    return c >='A' and c <= 'Z';
}
    
vector<bool> camelMatch(vector<string>& v, string p) {
    int n = v.size();
    vector<bool> ans(n, 0);
    
    for(int k=0; k<n; k++)
    {
        string s = v[k];
        bool flag = 1;

        int i=0 , j=0;
        while(i<s.size() and j<p.size())
        {
            if(s[i] == p[j]){
                i++;
                j++;
            }else{
                if(upper(s[i])){
                    flag = 0;
                    break;
                }
                i++;
            }
        }
        if(j < p.size()){
            flag = 0;
            continue;
        }
        while(i < s.size()){
            if(upper(s[i])){
                flag = 0;
                break;
            }
            i++;
        }
        if(flag)
        ans[k] = 1;
    }
    return ans;
}
};