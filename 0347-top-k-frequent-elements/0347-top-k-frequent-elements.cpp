class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto& i: mp){
            pq.push({i.second, i.first});  //freq, element
        }

        for(int i=0;i<k;i++){
           int curr=pq.top().second;
           res.push_back(curr);
           pq.pop();

        }
        return res;
    }
};