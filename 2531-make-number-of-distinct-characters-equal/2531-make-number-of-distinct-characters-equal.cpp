class Solution {
public:

    
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
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                  	998244353
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}


bool same(std::map<int, int>& m1, std::map<int, int> &m2 ){
	int c1 = 0, c2 = 0;

	for(int i=0; i<26; i++){
		if(m1[i] > 0	) c1++;
		if(m2[i] > 0	) c2++;
	}

	return c1 == c2;
}

bool isItPossible(string s, string t)        
{
	int n = s.size(), m = t.size();

	std::map<int, int> m1, m2;

	for(int i=0; i<n; i++){
		m1[s[i]-'a']++;
	}
	for(int i=0; i<m; i++){
		m2[t[i]-'a']++;
	}

	for(int i=0; i<26; i++){
		if(m1[i] == 0) continue;
		for(int j=0; j<26; j++)
		{
			if(m2[j] == 0) continue;

			m1[i]--;
			m2[i]++;

			m1[j]++;
			m2[j]--;

			if(same(m1, m2)) return 1;

			m1[i]++;
			m2[i]--;

			m1[j]--;
			m2[j]++;
		}
	}


return 0;
}    
    
};