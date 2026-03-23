class Solution {
public:
bool dfs(int node, int col, vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=col;
        for(auto& curr : adj[node]){
            if(vis[curr]==-1){
                if(!dfs(curr, !col, vis, adj)){
                    return false;
                }
                   
            }
            else if(vis[curr]==col){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &e:dislikes){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n+1, -1);
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(!dfs(i, 0,vis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};