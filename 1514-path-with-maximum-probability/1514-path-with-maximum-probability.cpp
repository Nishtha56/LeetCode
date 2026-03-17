class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u,w});
        }

        vector<double> dist(n, 0);
        //dist[start_node]=1;
        queue<pair<int, double>> q;
        q.push({start_node, 1});
        while(!q.empty()){
            int node=q.front().first;
            double dis=q.front().second;
            q.pop();

            for(auto& i:adj[node]){
                int v=i.first;
                double w=i.second;
                if(dist[v]<dis*w){
                    dist[v]=dis*w;
                    q.push({v, dist[v]});
                }
            }
        }
        
        return dist[end_node];


    }
};