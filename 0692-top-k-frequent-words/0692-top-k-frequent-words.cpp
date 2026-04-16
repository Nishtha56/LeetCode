class Solution {
public:
    struct cmp{
        bool operator()(pair<int, string>& a, pair<int, string>& b){
        if(a.first == b.first){
            return a.second<b.second;
        }
        return a.first > b.first;
    }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int , string> , vector<pair<int, string>>, cmp> pq;

        for(auto a : mp){                       //tc O(nlog k)
            pq.push({a.second, a.first});
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        vector<string> ans;

        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            ans.push_back(a.second);
        }
        reverse(ans.begin(), ans.end());           //tc:O(n)
        //sort(ans.begin(), ans.end());
        return ans;

    }
};