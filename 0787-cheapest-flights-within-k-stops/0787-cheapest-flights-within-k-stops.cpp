class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : flights){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            int dis=q.front().first;
            int node=q.front().second.first;
            int stops=q.front().second.second;
            q.pop();

            if(stops==k+1){
                break;
            }
            for(auto& i : adj[node]){
                int v=i.first;
                int w=i.second;

                if(w+dis<dist[v]){
                    dist[v]=w+dis;
                    q.push({dist[v], {v, stops+1}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];

    }
};