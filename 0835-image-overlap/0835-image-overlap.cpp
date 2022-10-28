class Solution {
public:
/*
    #define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define 	vvc					std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     inf                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}


int largestOverlap(vvi& img1, vvi& img2) 
{
	int ans = 0;

	int n = img1.size();

	for(int i=0; i<n; i++){
		for(int j=0;j<n; j++){

			int curr = 0;
			bool flag = 0;
			vvi temp(n, vi(n, 0));
			for(int p=0; p<n; p++){
				if(p+i == n){
					break;
				}
				for(int q =0; q<n; q++){
					if(q + j == n){
						break;
					}
					// cout << i << " " << j << " " << p << " " << q;br;
					// cout << img1[p][q] << " ";

					temp[p][q] = img1[p][q];
					if(img1[p][q] == img2[p+i][q+j] and img1[p][q] == 1){
						curr++;
					}
				}
				// br;

			}
			// coutvvi(temp);
			ans = max(ans, curr);
			// cout << curr;br;
			// br;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0;j<n; j++){

			int curr = 0;
			bool flag = 0;
			vvi temp(n, vi(n, 0));
			for(int p=0; p<n; p++){
				if(p+i == n){
					break;
				}
				for(int q =0; q<n; q++){
					if(q + j == n){
						break;
					}
					// cout << i << " " << j << " " << p << " " << q;br;
					// cout << img1[p+i][q+j] << " ";

					temp[p][q] = img1[p][q];
					if(img1[p+i][q+j] == img2[p][q] and img2[p][q] == 1){
						curr++;
					}
				}
				// br;

			}
			// coutvvi(temp);
			ans = max(ans, curr);
			// cout << curr;br;
			// br;
		}
	}


	return ans;
}
*/
    
    #define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define 	vvc					std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     inf                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}


int largestOverlap(vvi& img1, vvi& img2) 
{
	int n = img1.size();
	int ans = 0;

	std::vector<pii> v1;
	std::vector<pii> v2;

	std::map<pii, int> map;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(img1[i][j]){
				v1.pb({i, j});
			}
			if(img2[i][j]){
				v2.pb({i, j});
			}
		}
	}

	for(auto x: v1){
		for(auto y : v2){
			int i = x.ff - y.ff;
			int j = x.ss - y.ss;

			map[{i,j}]++;

			ans = max(ans, map[{i,j}]);
		}
	}

	return ans;
}
};