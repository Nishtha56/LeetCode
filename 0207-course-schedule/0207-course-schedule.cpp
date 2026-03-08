class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        if(prerequisites.size() <1){
            return true;
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
      

        vector<int> topo;
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

        if(topo.size()==n){
            return true;
        }
        else{
            return false;
        }
        

        
    }
};