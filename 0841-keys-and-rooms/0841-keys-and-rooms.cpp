class Solution {
public:

    
    
#define     vi                  vector<int>
#define     vvi                 vector<vi>


void dfs(int node, vvi &rooms, vi &vis)
{
    if(vis[node]) return;
    vis[node] = 1;

    for(auto child : rooms[node]){
        dfs(child, rooms, vis);
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
    int n = rooms.size();
    vi vis(n, 0);

    dfs(0, rooms, vis);

    for(int i=1; i<n; i++){
        if(!vis[i]) return 0;
    }
    return 1;
}
    
    
    
};