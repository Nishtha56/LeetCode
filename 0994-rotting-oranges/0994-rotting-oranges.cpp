class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int minTime=0;
        bool isOrange=false; //  if no orange in grid

        while(!q.empty()){
            isOrange=true;
            int s=q.size();
            for(int x=0;x<s;x++){
                auto a=q.front();
                int i=a.first; //row
                int j=a.second; //col
                q.pop();
                if(i-1>=0 && grid[i-1][j]==1){ //up
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(i+1<r && grid[i+1][j]==1){ //down
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1){ //left
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j+1<c && grid[i][j+1]==1){ //right
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }

            }
            minTime++;
        }
        for(int i=0;i<r;i++){  //any orange left for rotten
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(!isOrange) return 0;
        return minTime-1;
    }
};