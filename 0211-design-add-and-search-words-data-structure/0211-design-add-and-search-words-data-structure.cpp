struct Node{
    Node* links[26];  
    bool flag = 0;
};

Node* root = new Node();
void insert(string &s)
{
    Node* node = root;
    
    for(auto c : s)
    {
        if(!node->links[c - 'a']){
            node->links[c - 'a'] = new Node();
        }
        node = node->links[c - 'a'];
    }
    node->flag = 1;
}

bool func(Node* node, string &s, int i)
{
    
    if(s[i] == '.'){
        for(int j=0; j<26; j++)
        {
            if(node->links[j]){
                if(i == s.size() - 1)
                {
                    if(node->links[j]->flag) return 1;
                    continue;
                }
                bool a = func(node->links[j], s, i+1);
                if(a) return 1;
            }
        }
        return 0;
    }
    else{
        if(!node->links[s[i] - 'a']){
            return 0;
        }
        if(i == s.size()-1){
            if(node->links[s[i] - 'a']->flag) return 1;
            else return 0;
        }
        return func(node->links[s[i] - 'a'], s, i+1);
    }
}

class WordDictionary {
public:
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        insert(word);
    }
    
    bool search(string word) 
    {
        Node* node = root;
        return func(node, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */