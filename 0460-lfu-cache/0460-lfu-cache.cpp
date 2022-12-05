#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvvi                vector<vvi>
#define     vvc                 std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
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



class LFUCache {
public:

    struct  Node
    {
        int key;
        int value;
        int freq;
        Node* prev;
        Node* next;

        Node(int key,int  value,int  freq)
        {
            this->key = key;
            this->value = value;
            this->freq = freq;
            prev = NULL;
            next = NULL;
        }
    };

    map<int, pair<Node*, Node*>> freqList;
    unordered_map<int, Node*> keyNode;
    int cap;

    LFUCache(int capacity) {
        this->cap = capacity;
    }

    void insert(Node* node, Node* right){
        Node* rp = right->prev;
        rp->next = node;
        node->next = right;
        right->prev = node;
        node->prev = rp;
    }

    void remove(Node* node){
        Node *l = node->prev;
        Node *r = node->next;

        l->next = r;
        r->prev = l;
    }

    void increaseFreq(Node * node)
    {
        node->freq++;
        int fr = node->freq;
        
        if(fr != 1){
            remove(node);
        }

        if(freqList.count(fr))
        {
            

            Node *left = freqList[fr].ff;
            Node *right = freqList[fr].ss;
            insert(node, right);



        }else{
            Node * left = new Node(0, 0, fr);
            Node * right = new Node(0, 0, fr);
            left->next = right;
            right->prev = left;
            freqList[fr]  = {left, right};
            insert(node, right);


        }
    }

    bool removeLowest(int freq)
    {
        Node *left = freqList[freq].ff;
        Node *right = freqList[freq].ss;

        if(left->next == right){
            return 0;
        }
        Node *node = left->next;
        left->next = node->next;
        node->next->prev = node->prev;

        keyNode.erase(node->key);
        return 1;



    }
    
    int get(int key) {
        if(cap == 0) return -1;

        if(keyNode.count(key))
        {
            increaseFreq(keyNode[key]);
            return keyNode[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(keyNode.count(key)){
            increaseFreq(keyNode[key]);
            keyNode[key]->value = value;
        }
        else{
            // cout << keyNode.size()<<"fdsa";br;
            if(keyNode.size() == cap)
            {
                for(int i=1; i<= freqList.size(); i++){
                    if(removeLowest(i)){
                        break;
                    }
                }

            }

            Node *node = new Node(key, value, 0);
            increaseFreq(node);

            keyNode[key] = node;

            

        }
        // br;
        // for(auto x : keyNode){
        //     cout <<"--" << x.ff << " " << x.ss->value;br;
        // }br;
        
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */