class Solution {
public:
    int trailingZeroes(int n) {
        int c=0;
        while(n>0){       //In this n/5+ n/25 + n/125.......
            n=n/5;
            c=c+n;
            
        }
        return c;
    }
};