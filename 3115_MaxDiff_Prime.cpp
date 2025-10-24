// You are given an integer array nums.

//Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i <= n / i; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int i, j;
        for (i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) break;
        }
        for (j = nums.size() - 1; j >= 0; j--) {
            if (isPrime(nums[j])) break;
        }
        return abs(i - j);
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 8, 2, 10, 3, 15, 5};
    cout << s.maximumPrimeDifference(nums);
    return 0;
}
