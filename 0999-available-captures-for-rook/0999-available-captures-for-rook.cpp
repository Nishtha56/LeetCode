class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n=board.size();
        vector<vector<int>> vis(8, vector<int>(8, 0));
        int a,b;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j] == 'p'){
                    vis[i][j]=1;
                }
                else if(board[i][j] == 'R'){
                    vis[i][j]=2;
                    a=i;
                    b=j;
                }
                else if(board[i][j] == 'B'){
                    vis[i][j]=3;
                }
                
            }
        }
        int ct=0;
        int drow[]={-1, 0, 1, 0};
        int dcol[]={0, 1, 0, -1};


        for(int i=0;i<4;i++){
            int r=a;
            int c=b;

            while(r>=0 && c>=0 && r<8 && c<8){
                r=r+drow[i];
                c=c+dcol[i];

                if(r<0 || c<0 || r>=8 ||c>=8 || vis[r][c] == 3){
                    break;
                }

                if(vis[r][c] == 1){
                    ct++;
                    break;
                }
            }
        }
        return ct;


    }
};