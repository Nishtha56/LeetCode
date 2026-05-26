class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int n=words.size();
        if(n<right){
            right=n-1;
        }
        int c=0;
        for(int i=left;i<=right;i++){
            string s=words[i];
            char a=s[0];
            char b=s[s.length()-1];

            if(isVowel(a) && isVowel(b)){
                c++;
            }
        }
        return c;
    }
};