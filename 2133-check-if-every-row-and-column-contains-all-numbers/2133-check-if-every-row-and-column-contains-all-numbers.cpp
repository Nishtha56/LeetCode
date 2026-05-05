class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<n;i++){
            vector<bool>vis(n+1,false);
            for(int j=0;j<n;j++){
                if(vis[matrix[i][j]]==false){
                    vis[matrix[i][j]]=true;
                }
                else{
                    return false;
                }
            }
            
        }
        for(int i=0;i<n; i++){
            vector<bool>vis(n+1,false);
            for(int j=0;j<n;j++){
                if(vis[matrix[j][i]]==false){
                    vis[matrix[j][i]]=true;
                }
                else{
                    return false;
                }
            }
            
        }

        return true;
    }
};