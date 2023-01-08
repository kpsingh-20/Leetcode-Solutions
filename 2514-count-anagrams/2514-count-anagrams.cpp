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
#define     M                 	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}

vi fact;

vi perms;


long long power(long long x,int y,int mod){
    long long ans = 1;
    x = x%mod;
    while(y >0){
        if(y&1){
            ans = (ans*x)%mod;
        }
        y>>=1;
        x = (x*x)%mod;
    }
    return ans;
}
long long modInverse(long long n,int mod){
    return power(n,mod-2,mod);
}

void func(string &s)
{	
	vi hash(26, 0);

	for(int i=0; i<s.size(); i++)
	{
		hash[s[i] - 'a']++;
	}

	for(int i=0; i<26; i++){

	}
	int perm = fact[s.size()];

	for(int i=0; i<26; i++)
	{
		perm = (perm * modInverse(fact[hash[i]], M))%M;
	}
	// cout << s <<" " << perm;br;
	perms.pb(perm);
	s = "";
}


int countAnagrams(string s) 
{
	int N = 1e5 + 7;
	fact = vi(N);
	fact[0] = 1;

	for(int i=1; i<N; i++){
		fact[i] = (i *1LL* fact[i-1])%M;
	}


	int  n = s.size();
	string word = "";
	for(int i=0; i<=n; i++)
	{
		if(i == n){
			func(word);
			break;
		}
		if(s[i] == ' '){
			func(word);
		}else{
			word.pb(s[i]);
		}
	}

	int ans  = 1;


	for(int i=0; i<perms.size(); i++){
		ans = (ans * 1LL* perms[i])%M;
	}

return ans;
}
    
    
    
    
    
};