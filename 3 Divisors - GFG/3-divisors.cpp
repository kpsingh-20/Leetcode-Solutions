//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

#define     vi                  vector<int>

bool isPrime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i == 0) return 0;
	}
	return 1;
}

vector<int> threeDivisors(vector<long long> query, int q)
{
	vector<int> ans(query.size());
	
	int N = *max_element(query.begin(), query.end());
	vector<bool> Prime(N, 1);
	
	for(int i=2; i<N; i++)
	{
	    if(Prime[i]){
	        for(int j=2; j*i <= N; j++)
	        {
	            Prime[j*i] = false;
	        }
	    }
	}
	vi temp(N+1,0);
	for(int i=2; i<N; i++)
	{
	    temp[i] = temp[i-1];
	    if(Prime[i]){
	        temp[i]++;
	    }
	}
	
	
	for(int i=0; i<query.size(); i++)
	{
		int n = query[i];
        int j = sqrt(n);
        ans[i] = temp[j];
	}

	return ans;
}

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends