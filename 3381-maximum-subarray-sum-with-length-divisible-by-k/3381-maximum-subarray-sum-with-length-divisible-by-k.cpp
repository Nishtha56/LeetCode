class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        long long prefixSum = 0;
        long long ans = LLONG_MIN;

        // remainder -> minimum prefix sum
        unordered_map<int, long long> mp;

        // Prefix sum before starting the array
        mp[0] = 0;

        for (int i = 0; i < n; i++) {

            prefixSum += nums[i];

            // Prefix index = i + 1
            int rem = (i + 1) % k;

            // If same remainder was seen before
            if (mp.find(rem) != mp.end()) {
                ans = max(ans, prefixSum - mp[rem]);
            }

            // Store the minimum prefix sum for this remainder
            if (mp.find(rem) == mp.end()) {
                mp[rem] = prefixSum;
            }
            else {
                mp[rem] = min(mp[rem], prefixSum);
            }
        }

        return ans;
    }
};