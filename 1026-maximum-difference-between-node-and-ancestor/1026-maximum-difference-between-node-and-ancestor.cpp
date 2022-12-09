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
    
vector<int> func(Node* root){
    if(!root){
        return {};
    }
    
    vector<int> l = func(root->left);
    vector<int> r = func(root->right);
    
    l.push_back(root->val);
    
    l.insert(l.end(), r.begin(), r.end());
    
    for(int i=0; i<l.size(); i++)
    {
        // cout << l[i] << " " << endl;
        ans = max(ans, abs(l[i] - root->val));
    }
    
    return l;
}
    
    
    
int maxAncestorDiff(TreeNode* root) 
{
    ans = INT_MIN;
    
    func(root);
    return ans;
    
}
};