class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int n = s.size();
        int first = 0, second = 0;
        for(int i=0; i<n; i++){
            
            if(i<n/2){
                if(s[i]== 'a' or s[i] == 'e' or s[i]== 'i' or s[i] == 'o' or s[i]== 'u' or
                  s[i]== 'A' or s[i] == 'E' or s[i]== 'I' or s[i] == 'O' or s[i]== 'U'){
                    first++;
                }
            }else
            {
                if(s[i]== 'a' or s[i] == 'e' or s[i]== 'i' or s[i] == 'o' or s[i]== 'u' or
                  s[i]== 'A' or s[i] == 'E' or s[i]== 'I' or s[i] == 'O' or s[i]== 'U'){
                    second++;
                }
            }
        }
        if(first == second){
            return 1;
        }
        return 0;
        
    }
};