struct Node
{
    int val;
    Node* left;
    Node* right;
    
    Node(int _val){
        val = _val;
        left = NULL;
        right = NULL;
    }
};

#define ll long long
class Solution {
public:
   
ll n;
ll ans = 0;
vector<ll> score;
int func(Node* root)
{
    if(!root) return 0;
    
    int l = func(root->left);
    int r = func(root->right);
    
    ll templ = l;
    ll tempr = r;
    
    if(!templ) templ++;
    if(!tempr) tempr++;
    
    if(root->val == 0){
        score[root->val] = templ * tempr;
    }else
        score[root->val] = (n - l - r - 1) * templ * tempr;
    
    // cout << root->val <<  " " <<l << " " << r << " " << score[root->val]  << endl;
    return 1 + l + r;
}
    
int countHighestScoreNodes(vector<int>& parents) 
{
    n = parents.size();
    map<int , Node*> mp;
    score = vector<ll>(n, 0);
    for(int i=0; i<n; i++)
    {
        mp[i] = new Node(i);
    }
    
    for(int i=1; i<n; i++){
        int par = parents[i];
        int node = i;
        
        if(!mp[par]->left){
            mp[par]->left = mp[node];
        }else{
            mp[par]->right = mp[node];
        }
    }
    
    func(mp[0]);
    
    ll maxi = *max_element(score.begin(), score.end());
    int cnt = 0;
    for(int i=0; i<score.size(); i++){
        if(score[i] == maxi) cnt++;
    }
    
    return cnt;
}
};