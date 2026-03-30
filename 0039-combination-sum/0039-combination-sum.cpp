class Solution {
public:
    void subset(int ind, int target, vector<int> &help, vector<vector<int>>& ans, vector<int>& candidates){
        int n=candidates.size();
        if(ind>=n){
            if(target==0){
                ans.push_back({help});
                
            }
            return;
        }

        //take
        if(target>=candidates[ind]){
            help.push_back(candidates[ind]);
            subset(ind, target-candidates[ind], help, ans, candidates);
            help.pop_back();
        }

        //not take
        subset(ind+1, target, help, ans, candidates);

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> help;
        subset(0, target, help, ans, candidates);
        return ans;
    }
};