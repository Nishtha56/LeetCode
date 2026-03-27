class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(char c:s){
            if(isalnum(c)){
                ans+=tolower(c);
            }
        }
        int m=ans.length();
        string a=ans;
        reverse(ans.begin(),ans.end());

        for(int i=0;i<m;i++){
            if(a[i]!=ans[i]){
                return false;
            }
        }
        return true;

    }
};