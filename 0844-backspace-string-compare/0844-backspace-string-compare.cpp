class Solution {
public:
string removeHash(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(!ans.empty()) {
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
    bool backspaceCompare(string s, string t) {
        string ans1=removeHash(s);
        string ans2=removeHash(t);
        return ans1==ans2;
    }
};