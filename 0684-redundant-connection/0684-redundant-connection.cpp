class Solution {
public:
    class DSU{
        vector<int> rank;
        vector<int> parent;
        public:
        DSU(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);

            for(int i=1;i<=n;i++){
                parent[i]=i;
            }
        }

            int findParent(int node){
                if(node==parent[node]){
                    return node;
                }
                return parent[node]=findParent(parent[node]);
            }

            bool Union(int u, int v){
                int pu=findParent(u);
                int pv=findParent(v);

                if(pu==pv){
                    return true; // cycle detected

                }
                else if(rank[pu]>=rank[pv]){
                    parent[pv]=pu;
                    rank[pu]++;
                }
                else{
                    parent[pu]=pv;
                }
                return false;
            }
        

    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU d(n);
        for(auto e : edges){
            if((d.Union(e[0] , e[1])) == true){
                return {e[0], e[1]};
            }
        }
        return {};

    }
};