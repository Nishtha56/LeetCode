class Solution {
public:

    void dfs(vector<vector<char>> &board, int i, int j, vector<vector<int>> &vis){
        int n=board.size();
        int m=board[0].size();
        
        if(i>=n || j>=m || i<0 || j<0 || board[i][j]=='X' || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;

        
            dfs(board, i+1, j, vis);
            dfs(board, i-1, j, vis);
            dfs(board, i, j+1, vis);
            dfs(board, i, j-1, vis);
        
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 ||j==0 || i==n-1 || j==m-1){
                    if(vis[i][j]==0 && board[i][j]=='O'){
                        dfs(board, i, j, vis);
                    }
                
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    if(!vis[i][j]){
                        board[i][j]='X';
                        vis[i][j]=1;
                    }
                    
                }
            }
        }
    }
};