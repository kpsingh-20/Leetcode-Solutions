//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     inf                  	1000000000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}


string decodedString(string s)
{
	stack<char> st;

	for(int i=0; i<s.size(); i++){
		if(s[i] == ']'){
			string k;
			string n;
			while(!st.empty() ){
				char c = st.top(); st.pop();
				if(c == '[') break;
				k.pb(c);
			}
			while(!st.empty()){
				char c = st.top();
				if(!(c >= '0' and c <='9')) break;
				st.pop();
				n.pb(c);
			}

    		reverse(all(n));

			int num = stoi(n);
			reverse(all(k));
			// cout << n  << " " << k;br;

			for(int q=0; q<num; q++)
			{
				for(int p=0; p<k.size(); p++){
					st.push(k[p]);
				}
			}

		}else{
			st.push(s[i]);
		}
	}
	string ans;
	while(!st.empty()){
		ans.pb(st.top()); st.pop();
	}

	reverse(all(ans));
	return ans;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends