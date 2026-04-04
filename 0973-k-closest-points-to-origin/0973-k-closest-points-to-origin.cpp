class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        //maxHeap
        priority_queue<pair<double, pair<int, int>>> pq;  //{dist, {x, y}}
        int n=points.size();
        
        for(auto i : points){
            int a=i[0];
            int b=i[1];
            double eu=sqrt(a*a+b*b);
            pq.push({eu, {a, b}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            auto pt=pq.top();
            int a=pt.second.first;
            int b=pt.second.second;
            pq.pop();
            ans.push_back({a,b});
        }
        return ans;
    }
};