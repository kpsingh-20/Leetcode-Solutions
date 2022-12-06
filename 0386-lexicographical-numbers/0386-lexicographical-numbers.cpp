class Solution {
public:

std::vector<int> ans;

void func(int curr, int n)
{
	if(curr > n) return;
	ans.push_back(curr);
	for(int i=0; i<=9; i++)
	{	
		func(curr*10 + i, n);
	}
}


vector<int> lexicalOrder(int n) 
{
	for(int i=1; i<=9; i++)
	{
		func(i, n);
	}
	return ans;

}

};