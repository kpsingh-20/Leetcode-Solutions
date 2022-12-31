

class Solution {
private:
    vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
    void backtrack(int x,int y,int &ans,vector<vector<int>>&grid,int numWalk,int totalWalk){
        int m=grid.size(),n=grid[0].size();
        if(grid[x][y]==-1){
            return;
        } else if(grid[x][y]==2){
            if(numWalk==totalWalk){
                ans++;
            }
        } else {
            int tmp=grid[x][y];
            grid[x][y]=-1;
            if(tmp==0){
                numWalk++;
            }
            for(int i=0;i<dirs.size();i++){
                int nx=x+dirs[i][0];
                int ny=y+dirs[i][1];
                if(nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]==-1){
                    continue;
                } else {
                    backtrack(nx,ny,ans,grid,numWalk,totalWalk);
                }
            }
            if(tmp==0){
                numWalk--;
            }
            grid[x][y]=tmp;
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int totalWalk=0,x=0,y=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    totalWalk++;
                } else if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        int ans=0;
        backtrack(x,y,ans,grid,0,totalWalk);
        return ans;
    }
};
