class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();

        for (int &x : nums)
            x = abs(x);

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int j = 1;

        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] <= 2LL * nums[i]) {
                j++;
            }

            ans += (j - i - 1);
        }

        return ans;
    }
};
