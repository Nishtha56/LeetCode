class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+2);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> indeg(n+2,0);
        for(int i=1;i<=n+1;i++){
            for(auto& it : adj[i]){
                indeg[it]++;
            }
        }
        for(int i=1;i<=n+1;i++){
            if(indeg[i] == n){
                return i;
            }
        }
        return -1;
    }
};