/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // Recursion
/*
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return 1;
        if(!p or !q) return 0;
        
        if(p->val != q->val) return 0;
        
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        
    }
*/
    
    #define Node TreeNode
    bool isSameTree(Node* p, Node* q){
        queue<Node*> pque, qque;
        
        pque.push(p);
        qque.push(q);
        
        while(!pque.empty() and !qque.empty())
        {
            Node* f = pque.front(); pque.pop();
            Node* s = qque.front(); qque.pop();
            
            if(!f and !s) continue;
            if(!f or !s) return 0;
            
            if(f->val != s->val) return 0;
            
            pque.push(f->left);
            qque.push(s->left);

            pque.push(f->right);
            qque.push(s->right);

        }
        
        if(pque.size() or qque.size()) return 0;
        return 1;
    }
};