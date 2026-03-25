class DSU{
    public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n){
        rank.resize(n, 0);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionRank(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return;

        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       
        int extra=0;
        DSU ds(n);
        for(auto& i:connections){
            int u=i[0];
            int v=i[1];
            if(ds.findParent(u) == ds.findParent(v)){
                extra++;
            }
            else{
                ds.unionRank(u,v);
            }
        }

        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                comp++;
            }
        }

        if(extra>=comp-1){
            return comp-1;
        }
        else{
            return -1;
        }
        
        
    }
};