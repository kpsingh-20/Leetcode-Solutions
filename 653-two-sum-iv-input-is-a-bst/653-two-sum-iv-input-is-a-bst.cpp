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
#define pb push_back
#define Node TreeNode
class Solution {
public:
    
    void func(Node* root, vector<int>& nodes)
    {
        if(!root) return;
        nodes.pb(root->val);
        
        func(root->left, nodes);
        func(root->right, nodes);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        func(root, nodes);
        
        sort(nodes.begin(), nodes.end());
        
        int l = 0;
        int r = nodes.size()-1;
        
        // for(int i=0; i<=r; i++){
        //     cout << nodes[i] << " ";    
        // }cout << endl;
        
        while(l < r){
            int sum = nodes[l] + nodes[r];
            
            if(sum == k){
                return 1;
            }
            if(sum > k){
                r--;
            }else{
                l++;
            }
        }
        
        return 0;
    }   
};