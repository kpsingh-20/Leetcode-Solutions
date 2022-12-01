class Solution {
public:
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
#define     M                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}


struct Node
{
	string name;
	int has;
	std::vector<Node*> set;

	Node(string _val){
		has = 0;
		name = _val;
	};
};


void traversal(Node* root, std::vector<string> &ans, string curr)
{
	if(root->set.size() == 0){
		ans.pb(curr);
		return;
	}
	for(auto x : root->set){
		string temp = curr;
		temp.pb('/');
		temp.insert(temp.end(), all(x->name));

		traversal(x, ans, temp);
	}
}

void func(Node* root, int i, string s)
{
	int n = s.size();
	if(i >= s.size()){
		return;
	}
	if(s[i] == '/'){
		func(root, i+1, s);
		return;
	}
	int j = i;
	while(j<s.size() and s[j] != '/'){
		j++;
	}
	string k = s.substr(i, j-i);

	// cout << i << " " << j;br
	// cout << k;br;

	bool flag = 0;
	for(auto x : root->set){
		if(x->name == k and x->has == 1){
			return;
		}if(x->name == k){
			func(x, j+1, s);
			flag = 1;
		}
	}
	if(flag){
		return;
	}
	Node* temp = new Node(k);
	root->set.pb(temp);
	if(j == n){
		temp->has = 1;
	}
	else{
		func(temp, j + 1, s);
	}
}

vector<string> removeSubfolders(vector<string>& folder) 
{
	int n = folder.size();

	sort(all(folder));

	Node* root = new Node("-1");

	for(int i=0; i<n; i++){
		string &s = folder[i];

		func(root, 0, s);		
	}

	std::vector<string> ans;

	string curr ;

	traversal(root, ans, curr);


	return ans;
}
};