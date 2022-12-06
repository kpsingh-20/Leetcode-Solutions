struct Node{
    Node* links[26];
    bool isEnd = 0;
};

Node* root = new Node();

void insert(string &s)
{
    Node* node = root;
    for(int i=0; i<s.size(); i++)
    {
        if(!node->links[s[i] - 'a']){
            node->links[s[i] - 'a'] = new Node();
        }
        node = node->links[s[i] - 'a'];
    }
    node->isEnd = 1;
}

bool search(string s)
{
    Node* node = root;
    for(int i=0; i<s.size(); i++)
    {
        node = node->links[s[i] - 'a'];
        if(node->isEnd == 0) return 0;
    }
    return 1;
}



class Solution {
public:
string longestWord(vector<string>& words)
{
    root = new Node();
    for(auto word : words){
        insert(word);
    }
    string ans = "";
    for(auto word : words)
    {
        if(search(word))
        {
            if(ans.size() < word.size()){
                ans = word;
            }else if(ans.size() == word.size() and ans > word){
                ans = word;
            }
        }
    }
    return ans;

}
};