class Solution {
public:

int minimumSwap(string s1, string s2) 
{
    int ctx = 0, cty = 0;
    if(s1.size() != s2.size()) return -1;

    for(int i=0; i<s1.size(); i++){
        if(s1[i] == 'x') ctx++;
        else cty++;
    }
    for(int i=0; i<s2.size(); i++){
        if(s2[i] == 'x') ctx++;
        else cty++;
    }

    if(ctx &1 or cty&1) return -1;

    int ans = 0;
    int ct1=0, ct2 = 0;
    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i] != s2[i]){
            if(s1[i] == 'x'){
                ct1++;
                if(ct1 %2 == 0){
                    ct1 -=2;
                    ans++;
                }
            }
            if(s1[i] == 'y'){
                ct2++;
                if(ct2 %2 == 0){
                    ct2 -= 2;
                    ans++;
                }
            }
        }
    }
    ans += abs(ct1) + abs(ct2);
    return ans;
}
};