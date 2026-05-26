class DSU{
    vector<int> rank;
    vector<int> parent;

public:

    DSU(int n){

        rank.resize(n,0);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){

        if(node==parent[node]){
            return node;
        }

        return parent[node]=findParent(parent[node]);
    }

    void Union(int u,int v){

        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv){
            return;
        }

        if(rank[pu] >= rank[pv]){
            parent[pv]=pu;
            rank[pu]++;
        }
        else{
            parent[pu]=pv;
        }
    }
};

class Solution {
public:

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

        int n=vals.size();
        vector<vector<int>> adj(n);

        for(auto& e : edges){

            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        map<int, vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[vals[i]].push_back(i);
        }

        DSU dsu(n);
        int c=0;

        for(auto& it : mp){
            for(int node : it.second){
                for(int i : adj[node]){

                    if(vals[i]<=vals[node]){
                        dsu.Union(node, i);
                    }
                }
            }

            unordered_map<int,int> cnt;
            for(int node : it.second){
                int p=dsu.findParent(node);
                cnt[p]++;
            }

            for(auto &x : cnt){

                int k=x.second;
                c+=(k*(k+1))/2;
            }
        }

        return c;
    }
};