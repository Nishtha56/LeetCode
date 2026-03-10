class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto& e : edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n, INT_MAX);
        queue<int> q;
        dist[source]=0;
        q.push(source);

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto& i : adj[curr]){
                if(dist[curr]+1 < dist[i]) {
                    dist[i]=dist[curr]+1;
                    q.push(i);
                }
            }            
        }
        if(dist[destination]==INT_MAX){
                return false;
        }
        else{
            return true;
        }
        
    }
};