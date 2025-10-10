//11. Container With Most Water
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int area = 0;

        while (start < end) {
            int width = end - start;
            int currentArea = min(height[start], height[end]) * width;
            area = max(area, currentArea);

            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }

        return area;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Maximum area: " << sol.maxArea(height) << endl;
    return 0;
}
