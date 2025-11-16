//Problem number 1979 : Find Greatest Common Divisor of Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int m, int n){
        if(n == 0) return m;
        return gcd(n, m % n);
    }

    int findGCD(vector<int>& nums) {
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());
        return gcd(a, b);
    }
};

int main() {
    int n;
    cin >> n;        

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.findGCD(nums) << endl;

    return 0;
}
