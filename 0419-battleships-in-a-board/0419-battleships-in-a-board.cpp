class Solution {
public:
    void dfs(int &curr, int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis){
        int n=board.size();
        int m=board[0].size();

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='.' ||vis[i][j]==1){
            return;
        }
        board[i][j]='.';

        dfs(curr, i-1, j, board, vis);
        dfs(curr, i+1, j, board, vis);
        dfs(curr, i, j-1, board, vis);
        dfs(curr, i, j+1, board, vis);

    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(curr, i, j, board, vis);
                    curr++;
                    
                } 
            }
        }
        return curr;
    }
};