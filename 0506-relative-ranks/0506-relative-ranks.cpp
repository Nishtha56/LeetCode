class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n);

        priority_queue<pair<int, int>> pq;

        for(int i=0;i<n;i++){
            pq.push({score[i], i});
        }

        int r=1;
        while(!pq.empty()){
            int sc=pq.top().first;
            int idx=pq.top().second;

            pq.pop();
            if(r==1){
                ans[idx]="Gold Medal";
            }
            else if(r==2){
                ans[idx]="Silver Medal";
            }
            else if(r==3){
                ans[idx]="Bronze Medal";
            }
            else{
                ans[idx]=to_string(r);
            }
            r++;
        }
        return ans;
    }
};