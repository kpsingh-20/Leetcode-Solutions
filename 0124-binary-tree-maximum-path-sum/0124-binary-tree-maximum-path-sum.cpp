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

#define Node TreeNode
class Solution {
public:
    int ans;
    
    int func(Node* root)
    {
        if(!root) return 0;
        
        int l = func(root->left);
        int r = func(root->right);
        
        ans = max({ans, root->val + l + r, root->val + l, root->val + r, root->val});
        
        return max({ root->val + l, root->val + r, root->val});
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        func(root);
        return ans;
    }
};