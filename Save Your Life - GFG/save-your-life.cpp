//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define 	vvc					std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()


string maxSum(string w,char x[], int b[],int n){

	int curr = 0;
	int maxi = 0;

	std::map<char, int> map;
	for(int i=0; i<n; i++){
		map[x[i]] = b[i];
	}
	for(char c = 'a'; c <= 'z'; c++){
		if(map.find(c) == map.end()){
			map[c] = (int)(c);
		}
	}
	for(char c = 'A'; c <= 'Z'; c++){
		if(map.find(c) == map.end()){
			map[c] = (int)(c);
		}
	}

	string ans;
	int prev = 0;
	int last = 0;
	int l = 0, r = 0;
	for(int i=0; i<w.size(); i++){
		curr += map[w[i]];
		if(curr < 0){
			curr = 0;
			prev = i+1;
		}else{
			if(maxi < curr){
				l = prev;
				r = i;
			}
			maxi = max(curr, maxi);
			last = i;
		}
	}   
	ans = w.substr(l, r - l + 1);
	return ans;       
}



};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends