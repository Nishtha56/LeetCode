class Solution {
public:
    bool cmp(vector<int> &a , vector<int>&b){
        return a[1]<b[1];  //sort acc to finish time
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int n=intervals.size();
        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]>end){
                ans.push_back({start, end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else {
                start=min(start, intervals[i][0]);
                end=max(end, intervals[i][1]);
            }

        }
        ans.push_back({start, end});
        return ans;


        

    }
};