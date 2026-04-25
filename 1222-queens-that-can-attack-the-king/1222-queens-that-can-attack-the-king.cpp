class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<bool>> board(8, vector<bool>(8, false));

        for(auto& i: queens){
            int a=i[0];
            int b=i[1];
            board[a][b]=true;
        }

        int drow[]={-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[]={0, 1, 1, 1, 0, -1, -1, -1};


        for(int i=0;i<8;i++){
            int r=king[0];
            int c=king[1];

            while(r>=0 && c>=0 && r<8 && c<8){
                r=r+drow[i];
                c=c+dcol[i];

                if(r<0 || c<0 || r>=8 ||c>=8){
                    break;
                }

                if(board[r][c] == true){
                    ans.push_back({r,c});
                    break;
                }
            }
        }
        return ans;

    }
};