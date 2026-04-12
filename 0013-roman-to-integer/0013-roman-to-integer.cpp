class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        unordered_map<char, int> mp={{'I',1},{'V',5},{'X',10}, {'L',50},{'C',100},{'D',500}, {'M',1000}};
        int n=s.length();
        sum=mp[s[n-1]];
        for(int i=n-2; i>=0;i--){
            if(mp[s[i]]<mp[s[i+1]]){
                sum=sum-mp[s[i]];
            }
            else{
                sum=sum+mp[s[i]];
            }
        }
        return sum;
        
    }
};