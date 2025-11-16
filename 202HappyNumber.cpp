// 202 Happy Numer ( take the number square the each digt and add then recursive these steps until you et 1 if you get then number is happy 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7) return true;
        if(n < 10) return false;

        int sum = 0;
        while(n){
            int x = n % 10;
            sum += (x * x);
            n /= 10;
        }
        return isHappy(sum);
    }
};

int main() {
    int n;
    cin >> n;      

    Solution obj;

    if(obj.isHappy(n))
        cout << "YES\n";     
    else
        cout << "NO\n";   

    return 0;
}
