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


class LRUCache {
public:
    
	
	struct Node
		{
			int key;
			int value;
			Node* prev;
			Node* next;

			Node(int _key, int _value){
				key = _key;
				value = _value;
				prev = NULL;
				next = NULL;
			}
		};	
    
    Node*left = new Node(0,0);
    Node*right = new Node(0,0);
    unordered_map<int, Node*> um;
    int cap;

    LRUCache(int capacity) {
    	this->cap = capacity;
    	right->prev = left;
    	left->next = right;
    }

    void remove(Node *node)
    {
    	Node * p = node->prev;
    	Node * n = node->next;

    	n->prev = p;
    	p->next = n;
    }
    void insert(Node* node)
    {
    	node->next = right;
    	node->prev = right->prev;
    	right->prev->next = node;
    	right->prev = node;
    }
    
    int get(int key) {
        if(um.count(key)){
        	Node * node = um[key];
        	remove(node);
        	insert(node);
        	return um[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
    	if(um.count(key)){
        	Node * node = um[key];
        	remove(node);
        	insert(node);
        	node->value = value;
    	}else{
    		um[key] = new Node(key, value);
    		insert(um[key]);

    		if(um.size() > cap){
    			Node * node = left->next;
    			remove(node);
    			um.erase(node->key);
    		}
    	}
        // for(auto x : um){
        // 	cout << x.ff << " " << x.ss->value;br;
        // }
    }
};