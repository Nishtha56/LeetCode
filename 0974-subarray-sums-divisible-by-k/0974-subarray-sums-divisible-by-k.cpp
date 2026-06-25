class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mp(k, 0);
        mp[0]=1;
        int alpha=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            alpha=((alpha+nums[i])%k+k)%k;   //+k do because negative value
            int beta=alpha;
            ans+=mp[beta];
            mp[alpha]++;
        }
        return ans;
    }
};