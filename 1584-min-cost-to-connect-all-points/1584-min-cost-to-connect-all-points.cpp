class Solution {
public:
    int prims(vector<vector<pair<int, int>>> &adj, int &V){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //{wt, node}; 

        pq.push({0, 0});
        int sum=0;
        vector<int> vis(V, 0);
        while(!pq.empty()){
            auto a=pq.top();
            int wt=a.first;
            int node=a.second;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum=sum+wt;
            for(auto it : adj[node]){
                int w=it.first;
                int adjNode=it.second;
                if(!vis[adjNode]){
                    pq.push({w, adjNode});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        //Make a adj list
        int V=points.size();

        vector<vector<pair<int, int>>> adj(V);  //{i,{j, dist}}

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int x2=points[j][0];

                int y1=points[i][1];
                int y2=points[j][1];

                int dist=abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});

            }
        }
        return prims(adj, V);

    }
};