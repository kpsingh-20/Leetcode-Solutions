class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     fi(i,a,b)           for(int i=a; i<b; i++)
#define     fie(i,a,b)          for(int i=a; i<=b; i++)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ' 
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     inf                  1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}

// int longestConsecutive(vector<int>& nums) {
 
//     if(nums.size() == 0)return 0; 
//  	sort(all(nums));

//  	int maxi = 0;
//  	int curr = 1;

//  	for(int i=1; i<nums.size(); i++){
//  		if(nums[i] == nums[i-1]+1){
//  			curr++;
//  		}else if(nums[i] == nums[i-1]){
//  			continue;
//  		}else{
//  			maxi = max(maxi, curr);
//  			curr = 1;
//  		}
//  	}
//  	maxi = max(maxi, curr);

//  	return maxi;   
// }

    
    
int longestConsecutive(vector<int>& nums) 
{
	set<int> st(nums.begin(), nums.end());

	int ans = 0;
	for(int i=0; i<nums.size(); i++)
	{
		if(st.find(nums[i] - 1) == st.end())
		{
			int l = 0;
			int n = nums[i];
			while(st.find(n) != st.end()){
				l++;
				n++;
			}
			ans = max(ans, l);
		}
	}

	return ans;
}
};