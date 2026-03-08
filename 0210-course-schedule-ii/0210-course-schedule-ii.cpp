class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> topo;
        vector<int> indeg(numCourses, 0);

        if(prerequisites.size()==0){
            for(int i=0;i<numCourses;i++){
                topo.push_back(i);
            }
            return topo;
        }
            for(auto & e:prerequisites){
                int u=e[0];
                int v=e[1];
                adj[v].push_back(u);
            }

        int n=adj.size();

        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
    
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            

            for(auto& it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        vector<int> res;

        if(topo.size()==n){
            return topo;
        }
        else{
            return res;
        }
        
    }
    
};