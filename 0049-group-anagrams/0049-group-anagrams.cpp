#define     test(t)             int t; cin>>t; while(t--)
#define     ll                  long long
#define     pb                  push_back
#define 	ff 					first
#define 	ss 					second
#define     vi                  vector<int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     fi(i,a,b)           for(int i=a; i<b; i++)
#define     fie(i,a,b)          for(int i=a; i<=b; i++)
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a{i};
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ' 
#define     cinarray(a)         for(int i=0; i<a.size(); i++) cin >> a{i};
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";

class Solution {
public:
    
/*
    vector<vector<string>> groupAnagrams(vector<string>& v) {

	int n= v.size();
	std::vector<std::vector<int>> hsh2;

	for(int i=0; i<n; i++)
	{	
		std::vector<int> hsh3(52, 0);
		string s = v[i];
		for(int j=0; j<s.size(); j++)
		{
			if(s[j] <= 'Z'){
				// cout << (s[i] - 'A');br;
				hsh3[s[j] - 'A' + 26]++;
			}
			else{
				// cout << (s[j] - 'a');br;
				hsh3[s[j] - 'a' ]++;
			}
		}

		hsh2.pb(hsh3);
	}

	std::vector<int> vis(n, 0);
	std::vector<std::vector<string>> ans;
	for(int i=0; i<n; i++)
	{	
		if(vis[i] == 1) continue;

		std::vector<string> k;
		k.pb(v[i]);
		for(int j=i+1; j<n; j++)
		{
			if(hsh2[i] == hsh2[j]){
				k.pb(v[j]);
				vis[j] = 1;
			}
		}
		ans.pb(k);
	}

	// for(auto vec : ans){
	// 	coutspace(vec);br;
	// }

    return ans;

}
*/
    vector<vector<string>> groupAnagrams(vector<string>& v) 
{
	std::map<string, std::vector<string>> map;

	for(auto s : v){
		string t = s;
		sort(all(t));
		map[t].pb(s);
	}

	vector<vector<string>> ans;
	for(auto x : map){
		ans.pb(x.ss);
	}

	return ans;
}
};