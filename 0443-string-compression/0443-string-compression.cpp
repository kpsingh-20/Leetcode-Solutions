class Solution {
public:

#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
    
    
int compress(vector<char>& A) 
{
	int n = A.size();
	string s;

	int cnt = 1;
	for(int i=0; i<n; i++)
	{
		if(i == n-1){
			if(cnt == 1){
				s.pb(A[i]);
				continue;
			}
			s.pb(A[i]);
			string k = to_string(cnt);
			s.insert(s.end(), all(k));
			continue;
		}
		if(A[i] == A[i+1]){
			cnt++;
		}else{
			if(cnt == 1){
				s.pb(A[i]);
				continue;
			}
			s.pb(A[i]);
			string k = to_string(cnt);
			s.insert(s.end(), all(k));
			cnt = 1;
		}
	}
	// cout << s;br;
    for(int i=0; i<s.size(); i++){
        A[i] = s[i];
    }
	return s.size();
}
    
};