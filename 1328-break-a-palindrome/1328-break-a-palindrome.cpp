class Solution {
public:
bool onlyA(string s){
	for(int i=0; i<s.size(); i++){
		if(s[i] != 'a'){
			return 0;
		}
	}
	return 1;
}

string breakPalindrome(string s) 
{
	if(s.size() == 1){
		return "";
	}

	if(onlyA(s)){
		s[s.size()-1] = 'b';
		return s;
	}

	for(int i=0; i<s.size(); i++){
		if(s[i] == 'a') continue;
		else{
			if(i == s.size()/2){
				s[s.size()-1] = 'b';
				return s;
			}
			s[i] = 'a';
			break;
		}
	}
    return s;
}	



};