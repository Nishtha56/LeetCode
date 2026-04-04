class Solution {
public:
struct cmp{
    bool operator()(pair<int,int>& a, pair<int,int>& b){    //if freq same then lager value comes first
        if(a.first==b.first){
            return a.second< b.second;    //For values
        }
        return a.first>b.first;      //smaller freq comes first
    } 
};
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto i: mp){
            pq.push({i.second, i.first}); // freq, element
        }
        
        while(!pq.empty()){
            auto a=pq.top();
            for(int i=0;i<a.first;i++){
                ans.push_back(a.second);
            }
            
            pq.pop();
        }
        return ans;


    }
};