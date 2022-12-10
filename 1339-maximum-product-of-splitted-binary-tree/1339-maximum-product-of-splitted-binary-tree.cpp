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

#define  Node TreeNode
#define ll long long
#define M 1000000007
class Solution {
public:
   
ll overall(Node* root){
    if(!root){
        return 0;
    }
    return root->val  + overall(root->left) + overall(root->right);
};
    
ll ans = 0;
int sum;
int func(Node* root)
{
    if(!root){
        return 0;
    }
    int l = func(root->left);
    int r = func(root->right);
    
    // cout << sum - l - r - root->val<< " " << l + r +  root->val <<endl;
    ans = max(ans,( (sum - l - r - root->val) * 1LL * (l + r + root->val)) );
    
    return root->val + l + r;
}

int maxProduct(Node* root) 
{
    sum = overall(root);
    func(root);
    return (ans)%M;
}
    
    
};