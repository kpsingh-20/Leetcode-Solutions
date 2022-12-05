struct Node{
    Node* links[26];
    bool flag = 0;
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            int ind = word[i] - 'a';
            if(!node->links[ind]){
                node->links[ind] = new Node();
            }
            node = node->links[ind];
        }
            
        node->flag = 1;
        
    }
    
    bool search(string word) 
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            int ind = word[i] - 'a';
            if(!node->links[ind]){
                return 0;
            }
            node = node->links[ind];
        }
        if(!node->flag) return 0;
        return 1;
        
    }
    
    bool startsWith(string prefix) 
    {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            int ind = prefix[i] - 'a';
            if(!node->links[ind]){
                return 0;
            }
            node = node->links[ind];
        }
        return 1;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */