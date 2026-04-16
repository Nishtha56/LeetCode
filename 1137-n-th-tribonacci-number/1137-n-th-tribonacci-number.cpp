class Solution {
public:
    int helper(vector<int> &dp, int n){
        if(n==0) return dp[n]=0;
        if(n==1 || n==2) return dp[n]=1;
        if(dp[n] != -1) return dp[n];

        return dp[n]=helper(dp, n-1) +helper(dp, n-2) + helper(dp, n-3);
    }
    int tribonacci(int n) {
        //Recursion
        // if(n==0){
        //     return n;
        // }
        // if(n==1 || n==2){
        //     return 1;
        // }
        // return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);

        //Memoization
        
        vector<int> dp(n+1, -1);
        return helper(dp, n);
    }

};