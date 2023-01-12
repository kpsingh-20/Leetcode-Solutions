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
    #define all(x) x.begin(), x.end()
    
    
// Ye tarika isliye kam nahi karega kyuki apne ko ek string ko global minimum se compare karna padega..
    

    bool comp(string &l, string &r)
    {
        int i=0, j=0;
        // reverse(all(l));
        // reverse(all(r));
        
        for(; i<l.size() and j<r.size(); i++, j++){
            if(l[i] < r[j]) return 1;
            if(r[j] < l[i]) return 0;
        }
        if(i == l.size()) return 1;
        if(j == r.size()) return 0;
        
        return l < r;
        
    }
    
/*
    string smallestFromLeaf(TreeNode* root) {
        
        if(root == NULL) return  "";
        
        string l = smallestFromLeaf(root->left);    l.push_back(char(root->val + 'a'));
        string r = smallestFromLeaf(root->right);   r.push_back(char(root->val + 'a'));
        
        if(!root->left){
            return r;
        }if(!root->right){
            return l;
        }

        if(comp(l, r)){
            return l;
        }
        return r;

    }
*/
string ans;
    
void func(TreeNode* root, string s)
{
    if(!root){
        return;
    }
    
    s.push_back(char(root->val + 'a'));
    if(root->left){
        func(root->left, s);
    }
    if(root->right){
        func(root->right, s);
    }
    if(!root->left and !root->right)                 // This is leaf node;
    {
        reverse(all(s));
        if(comp(s, ans)){
            ans = s;
        }
    }
}
string smallestFromLeaf(TreeNode* root) 
{
    ans.push_back('z' + 1);
    func(root, "");
    return ans;

}

    
    
    
    
    
    
    
    
    
    
    
    
    

};