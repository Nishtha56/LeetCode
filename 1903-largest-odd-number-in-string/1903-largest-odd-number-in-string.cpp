class Solution {
public:
    string largestOddNumber(string num) {
        string s="";
        int n=num.length();

        for(int i=n-1;i>=0;i--){
            int a=num[i]-'0';
            if(a%2 != 0){
                s=num.substr(0, i+1);
                break;
            }
        }
        return s;
    }
};