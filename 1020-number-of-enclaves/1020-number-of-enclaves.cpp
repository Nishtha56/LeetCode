class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &vis, int &curr, bool &tb){
        int n=grid.size();
        int m=grid[0].size();

        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==0 || vis[r][c]==1){
            return;
        }
        
        if(r==0 || c==0 || r==n-1 || c==m-1){
            tb=true;
        }
            curr=curr+1;
            vis[r][c]=1;
            dfs(grid, r+1,c,vis,curr, tb);
            dfs(grid, r-1,c,vis,curr,tb);
            dfs(grid, r,c+1,vis,curr,tb);
            dfs(grid, r,c-1,vis,curr,tb);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int ct=0;
                    bool tb=false;
                    dfs(grid, i, j, vis,ct, tb);
                    if(tb==true){
                        ct=0;
                    }
                    maxi=maxi+ct;
                    
                }
            }
        }
        return maxi;
    }
};