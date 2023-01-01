class Solution {
public:
#define     pb                  push_back
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvvi                 vector<vvi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)      for(int i=0; i<n; i++) cin >> a[i];
#define     M                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}

bool wordPattern(string p, string s) 
{
	vector<string> words;
	if(s.size() == 0){
		if(p.size() == 0) return 1;
		return 0;
	}

	string t = "";
	for(int i=0; i<=s.size(); i++){
		if(i == s.size()){
			words.pb(t);
            break;
		}
		if(s[i] == ' '){
			words.pb(t);
            t.clear();
		}else{
			t.pb(s[i]);
		}
	}

	if(words.size() != p.size()) return 0;

	std::map<char, string> m1;
	std::map<string, char> m2;
	for(int i=0; i<words.size(); i++){

		if(m1.find(p[i]) == m1.end() and m2.find(words[i])  == m2.end()){
			m1[p[i]] = words[i];
			m2[words[i]] = p[i];
		}else if(m1.find(p[i]) == m1.end() and m2.find(words[i])  != m2.end()){
			return 0;
		}else if(m1.find(p[i]) != m1.end() and m2.find(words[i])  == m2.end()){
			return 0;
		}else if(m1.find(p[i]) != m1.end() and m2.find(words[i])  != m2.end()){
			if(m1[p[i]] != words[i]) return 0;
			if(m2[words[i]] != p[i]) return 0;
		}
	}


	return 1;
}
};