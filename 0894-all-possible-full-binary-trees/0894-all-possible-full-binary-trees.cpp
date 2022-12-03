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
    
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     Node                TreeNode

class Solution {
public:
std::vector<Node*> dfs(int n){
    if(n == 1){
        Node *temp = new Node(0);
        return {temp};
    }
    std::vector<Node*> ans;
    for(int i=2; i<=n-1; i+=2){
        std::vector<Node*> left = dfs(i-1);
        std::vector<Node*> right = dfs(n-i);

        for(auto l : left){
            for(auto r : right){
                Node* temp = new Node(0);
                temp->left = l;
                temp->right = r;
                ans.pb(temp);
            }
        }
    }
    return ans;
}

vector<Node*> allPossibleFBT(int n) 
{
    return dfs(n);
}
};