class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j]==1){
                    adj[i].push_back(j);
                

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int it : adj[i]){
                 indeg[it]++;
            }
           
        }
        return indeg;
    }
};