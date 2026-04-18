class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto&e : times){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({k, 0});

        while(!q.empty()){
            int node=q.top().first;
            int dis=q.top().second;
            q.pop();

            for(auto& it : adj[node]){
                int v=it.first;
                int w=it.second;
                if(dist[v]>dis+w){
                    dist[v]=dis+w;
                    q.push({v, dist[v]});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<dist.size();i++){
            maxi=max(maxi, dist[i]);
        }
        
        if(maxi==INT_MAX){
            return -1;
        }
        return maxi;
    }
};