// in this we have to return the minimum difference of a prime number in a certain range,
// Segmentd Seive pg Enthroposis uses

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = sqrt(right);

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> basePrimes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) basePrimes.push_back(i);
        }

        vector<bool> range(right - left + 1, true);
        if (left == 1) range[0] = false;

        for (int p : basePrimes) {
            int start = max(p * p, ((left + p - 1) / p) * p);
            for (int j = start; j <= right; j += p) {
                range[j - left] = false;
            }
        }

        vector<int> primes;
        for (int i = 0; i <= right - left; i++) {
            if (range[i]) primes.push_back(i + left);
        }

        if (primes.size() < 2) return {-1, -1};

        int a = primes[0], b = primes[1];
        for (int i = 0; i < primes.size() - 1; i++) {
            if (primes[i + 1] - primes[i] < b - a) {
                a = primes[i];
                b = primes[i + 1];
            }
        }

        return {a, b};
    }
};

int main() {
    Solution sol;

    int left = 10, right = 19;
    vector<int> ans = sol.closestPrimes(left, right);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    left = 4; right = 6;
    ans = sol.closestPrimes(left, right);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
