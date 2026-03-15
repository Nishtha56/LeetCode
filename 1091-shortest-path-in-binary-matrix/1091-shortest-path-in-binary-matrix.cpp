class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        if(n==1 && grid[0][0]==0){
            return 1;
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;    //{dist, {r, c}}

        q.push({1, {0, 0}});
        dist[0][0]=1;

        vector<int> drow={-1, -1, 0, 1, 1, 1, 0 ,-1};
        vector<int> dcol={0, 1, 1, 1,0, -1, -1, -1};

        while(!q.empty()){
            int curr=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && curr+1 < dist[nr][nc]){
                    dist[nr][nc]=curr+1;
                    if(nr==n-1 && nc==n-1){
                        return dist[nr][nc];
                    }
                    q.push({curr+1, {nr, nc}});

                }
            }
        }
          
        return -1;
    }
};