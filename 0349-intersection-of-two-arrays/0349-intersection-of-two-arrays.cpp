class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i : nums1){
            mp[i]=1;             //mark it visisted 
        }

        for(int i : nums2){
            if(mp[i]==1){
                ans.push_back(i);    
                mp[i]=0;
            }
        }
        return ans;
    }
};