class Solution {
public:
//     int jump(vector<int>& nums) {
        
//     }
    
    
    

#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                 long long
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
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     M                  	998244353
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define 	coutvvi(grid)		for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)		for(auto &x : grid){cinvec(x);}

vi dp;
int func(int i, vi &nums)
{
	if(i>= nums.size()-1){
		 return 0;
	}

	if(dp[i] != -1) return dp[i];

	int ans = 1e9;
	for(int j=nums[i]; j>0; j--){
		int a = func(i+j, nums);
		ans = min(ans, a + 1);
	}
	return dp[i] = ans;
}

int jump(vector<int>& nums) 
{
	dp = vi(nums.size()+1, -1);

	return func(0, nums);

}
};