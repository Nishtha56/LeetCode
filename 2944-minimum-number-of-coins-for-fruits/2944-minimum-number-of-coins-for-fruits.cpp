class Solution {
public:
    // int helper(int idx, vector<int> &prices, vector<int>& dp){
    //     int n=prices.size();
    //     if(idx>=n){
    //         return 0;  // base case
    //     }

    //     if(dp[idx]!=-1){
    //         return dp[idx];
    //     }

    //     int ans=INT_MAX;
    //     int maxi=min(n, 2*idx+2);
    //     for(int i=idx+1; i<=maxi;i++){
    //         ans=min(ans, helper(i, prices, dp));
    //     }
    //     return dp[idx]=ans+prices[idx];  // 1st element always taken
    // }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1;i>=0;i--){
            int ans=INT_MAX;
            int maxi=min(n, 2*i+2);
            for(int j=i+1; j<=maxi;j++){
                ans=min(ans,dp[j]);
            }
            dp[i]=ans+prices[i];

        }
        return dp[0];

    }
};