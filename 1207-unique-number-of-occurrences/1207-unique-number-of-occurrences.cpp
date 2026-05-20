class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i : arr){
            mp[i]++;
        }
        unordered_set<int> s1;
        for(int i : arr){
            s1.insert(i);
        }

        unordered_set<int> s;
        for(auto i : mp){
            s.insert(i.second);
        }
        if(s1.size() == s.size()){
            return true;
        }
        return false;
    }
};