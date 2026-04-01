class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, long long> mp;
        string ans="";

        for(char c:s){
            mp[c]++;
        }
        //it gives the charcter max freq on the top := MAx heap
        priority_queue<pair<long long, char>> pq;

        for(auto& i : mp){
            pq.push({i.second, i.first});
        }

        while(!pq.empty()){
            auto a=pq.top();
            long long freq=a.first;
            char c=a.second;
            pq.pop();

            for(long long i=0;i<freq;i++){
                ans+=c;
            }
        }
        return ans;
    }
};