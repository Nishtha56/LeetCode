class Solution {
public:
void subset(int ind, int target, vector<int> &help, vector<vector<int>>& ans, vector<int>& candidates){
        int n=candidates.size();
     
            if(target==0){
                ans.push_back(help);
                return;
            }
        

        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;

            if(target<candidates[i]) break;

            help.push_back(candidates[i]);
            subset(i+1, target-candidates[i], help, ans, candidates);
            help.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> help;
        subset(0, target, help, ans, candidates);
        return ans;
    }
};