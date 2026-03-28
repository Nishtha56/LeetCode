class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> p1;
        for(char c:magazine){
            p1[c]++;
        }

        for(char c:ransomNote){
            if(p1[c]==0){
                return false;
            }
            p1[c]--;
        }
        return true;

    }
};