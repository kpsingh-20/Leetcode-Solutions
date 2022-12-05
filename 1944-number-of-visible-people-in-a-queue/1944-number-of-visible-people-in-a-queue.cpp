class Solution {
public:

    
vector<int> canSeePersonsCount(vector<int>& heights) 
{
	int n = heights.size();
	stack<int> st;
	vector<int> ans(n, 0);

	for(int i=0; i<n; i++)
	{
		while(!st.empty() and heights[st.top()] < heights[i]){
			ans[st.top()]++;
			st.pop();
		}
		if(!st.empty()){
			ans[st.top()]++;
		}
		st.push(i);
	}

	return ans;
}
    
    
};