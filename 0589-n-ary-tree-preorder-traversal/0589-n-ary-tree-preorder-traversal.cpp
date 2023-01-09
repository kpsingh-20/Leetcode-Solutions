/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // recursive;
    
/*
    vector<int> ans;
    
    void func(Node* root)
    {
        if(!root) return;
        ans.push_back(root->val);
        
        for(int i=0; i<root->children.size(); i++){
            func(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        func(root);
        return ans;
    }
    
*/
    
    
// Here is the iterative approach
vector<int> preorder(Node* root) {
    
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty())
    {
        Node* node = st.top(); st.pop();
        if(node == NULL) continue;
        
        ans.push_back(node->val);
        
        for(int i=node->children.size() - 1; i>=0; i--)
        {
            Node* &curr = node->children[i];
            if(curr == NULL) continue;
            
            st.push(curr);
        }
    }
    return ans;
}
  
    
};