class Solution {
public:

    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int>& check, vector<vector<int>>& graph){
        vis[node]=1;
        pathVis[node]=1;
        //it is not a safe node;
        check[node]=0;

        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, check, graph)){
                    check[it]=0;
                    return true;
                }
            }
            else if(pathVis[it]==1){
                check[it]=0;
                return true;
            }
        
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n+1, 0);
        vector<int> pathVis(n+1,0);
        vector<int> check(n+1, 0);

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, check, graph);
            }
           
        }

        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};