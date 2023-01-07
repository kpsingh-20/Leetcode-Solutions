class Solution {
public:

    
    
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
	stack<int> st;
	int n = pushed.size();

	int j=0;
	for(int i=0; i<=n; i++)
	{
		// cout << st.size();br;
		while(!st.empty() and st.top() == popped[j]){
			st.pop();
			j++;
		}

		if(i < n)
		st.push(pushed[i]);
	}

	if(j == n) return 1;


return 0;
}
    
    
};