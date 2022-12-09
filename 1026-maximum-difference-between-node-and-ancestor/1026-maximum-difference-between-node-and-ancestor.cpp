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
 
#define Node TreeNode
    
int ans;
    
int func(Node* root,int maxi,int mini){
    if(!root){
        return ans;
    }
    ans = max(ans, abs(maxi - root->val));
    ans = max(ans, abs(mini - root->val));
    
    if(root->val > maxi) maxi =  root->val;
    if(root->val < mini) mini =  root->val;
    
    func(root->left, maxi, mini);
    func(root->right, maxi, mini);
    
    
    return ans;
}
    
    
    
int maxAncestorDiff(TreeNode* root) 
{
    ans = INT_MIN;
    
    return func(root, root->val, root->val);
    return ans;
    
}
};