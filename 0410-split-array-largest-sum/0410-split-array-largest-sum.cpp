class Solution {
public:
//     int splitArray(vector<int>& nums, int k) {
        
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


bool check(int cap, vi &weights, int days)
{
	int currW = 0;
	int currD = 1;
	for(int i=0; i<weights.size(); i++){
		if(currW + weights[i] > cap){
			currW = weights[i];
			if(currW > cap) return 0;
			currD++;
		}else
		{
			currW += weights[i];
		}
	}

	// cout << cap << " " << currW << " " << currD;br;
	if(currD > days) return 0;
	return 1;
}


int splitArray(vi& weights, int days) 
{
	int n = weights.size();

	int sum = accumulate(all(weights), 0LL);
	int mini = *min_element(all(weights));
	int l = mini;
	int r = sum;

	while(r - l > 1){
		int mid = (l + r)/2;

		if(check(mid,weights, days)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}

	if(check(l, weights, days)) return l;
	if(check(r, weights, days)) return r;
	
return r+1;
}

};