class Solution {
public:
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()

    
string reverseWords(string s) 
{
	string ret;

	int i= s.size()-1;
	while(i>=0){
		string k;
		while(i >=0 and s[i] == ' ') i--;
		while(i >=0 and s[i] != ' '){
			k.pb(s[i]);
			i--;
		}
		reverse(all(k));
		if(k.size() >0){
			ret.insert(ret.end(), all(k));
			ret.pb(' ');
		}
	}
	ret.pop_back();
	return ret;
}

};