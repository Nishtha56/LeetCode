class Solution {
public:
    int helper(int idx, vector<int> &prices, vector<int>& dp){
        int n=prices.size();
        if(idx>=n){
            return 0;  // base case
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        int ans=INT_MAX;
        int maxi=min(n, 2*idx+2);
        for(int i=idx+1; i<=maxi;i++){
            ans=min(ans, helper(i, prices, dp));
        }
        return dp[idx]=ans+prices[idx];  // 1st element always taken
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1, -1);

        int a=helper(0, prices, dp);
        return a;

    }
};