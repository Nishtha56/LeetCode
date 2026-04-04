class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         int maxi=0;
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto i: mp){
            pq.push({i.second, i.first}); // freq, element
        }
        auto t=pq.top();
        int ct=t.first;
        maxi=ct;
        pq.pop();
        
        while(!pq.empty()){
            auto a=pq.top();
            int c=a.first;
            if(c==ct){
                maxi+=c;
            }
            else{
                break;
            }

            
            pq.pop();
        }
        return maxi;

    }
};