class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
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
#define     inf                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}

struct Node
{
	Node *links[2];
};

string binary(int n)
{
	string s;
	int i = 32;
	while(i--){
		if(n&1) s.pb('1');
		else s.pb('0');
		n = n>>1;
	}
	reverse(all(s));
	return s;
}

Node* root = new Node();

void insert(string s)
{
	Node* node = root;
	for(int i=0; i<s.size(); i++){
		if(!node->links[s[i] - '0']){
			node->links[s[i] - '0'] = new Node();
		}
		node = node->links[s[i] - '0'];
	}
}

int func(string s)
{
	Node* node = root;
	string k;
	int n = 31;
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		if(node->links[!(s[i] - '0')]){
			k.pb(!(s[i] - '0'));
			ans += pow(2, n);
			node = node->links[!(s[i] - '0')];
		}else{
			k.pb(s[i] - '0');
			node = node->links[s[i] - '0'];
		}
		n--;
	}

	return ans;
}

int findMaximumXOR(vector<int>& nums) 
{	

	int n = nums.size();
	for(int i=0; i<n; i++){
		// cout <<(binary(nums[i]));br;
		insert(binary(nums[i]));
	}

	int ans = INT_MIN;
	for(int i=0; i<nums.size(); i++){
		ans = max(ans, func(binary(nums[i])));
	}

	return ans;
}
};