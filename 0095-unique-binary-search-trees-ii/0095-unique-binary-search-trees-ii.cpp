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
    
// saw coda of happy coding 
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

std::vector<Node*> dfs(int l, int r){

    if(l > r) return {NULL};
    if(l == r){
        Node *temp = new Node(l);
        return {temp};
    }

    std::vector<Node*> ans;
    for(int i=l ; i<= r; i++)
    {
        std::vector<Node*> left = dfs(l, i-1);
        std::vector<Node*> right = dfs(i+1, r);

        for(auto l : left){
            for(auto r : right){
                Node* temp = new Node(i);
                temp->left = l;
                temp->right = r;
                ans.pb(temp);
            }
        }
    }

    return ans;

}

vector<Node*> generateTrees(int n) 
{
    return dfs(1, n);

}
};