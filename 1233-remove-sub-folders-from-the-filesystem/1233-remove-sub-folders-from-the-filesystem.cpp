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
    Node* links[26];
    bool flag = 0;
    
};

vector<string> removeSubfolders(vector<string>& folder) 
{
    Node* root = new Node();

    sort(all(folder));
    std::vector<string> ans;

    for(int j=0; j<folder.size(); j++){
        string s = folder[j];

        Node *node = root;
        bool isEnd = 0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '/') continue;

            if(node->links[s[i] - 'a'] == NULL){
                node->links[s[i] - 'a'] = new Node();
            }

            node = node->links[s[i] - 'a'];

            if(i+1 < s.size() and s[i+1] == '/' and node->flag){
                isEnd = 1;
                break;
            }
        }
        if(!isEnd){
            ans.pb(s);
            node->flag = 1;
        }

    }
    return ans;
}
};