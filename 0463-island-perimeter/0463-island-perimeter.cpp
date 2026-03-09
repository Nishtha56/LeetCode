class Solution {
public:
    void dfs(int &curr, int i, int j, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || j<0 || i>=n || j>=m){
            curr++;
            return;
        }
        if(grid[i][j]==0){
            curr++;
            return;
        }
        if(grid[i][j]==-1){
            return;
        }

        grid[i][j]=-1;

        dfs(curr, i-1, j, grid);
        dfs(curr, i+1, j, grid);
        dfs(curr, i, j-1, grid);
        dfs(curr, i, j+1, grid);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(curr, i, j, grid);
            
                    
                } 
            }
        }
        return curr;
    }
};