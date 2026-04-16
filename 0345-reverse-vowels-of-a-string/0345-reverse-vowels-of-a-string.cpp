class Solution {
public:
    bool isVowel(char c){
        if(c=='a'|| c=='e' || c=='i'|| c=='o' || c=='u' ||c=='A'|| c=='E' || c=='I'|| c=='O' || c=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s1) {
        string s=s1;
        int i=0, j=s.length()-1;
        while(i<j){
               bool a=isVowel(s[i]);
               bool b=isVowel(s[j]);
               if(a && b){
                swap(s[i], s[j]);
                i++;
                j--;
               }
               if(!a){
                i++;
               }
               if(!b){
                j--;
               }
        }
        return s;
    }
};