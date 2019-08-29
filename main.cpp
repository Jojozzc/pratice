#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int lengthOfLongest(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int len = nums.size();
    int* dp = new int[nums.size()];
    dp[0] = 1;
    int maxLen = 1;
    for (int i = 1; i < len; i++) {
        int maxVal = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] >= nums[j]) {
                maxVal = max(maxVal, dp[j]);
            }
        }
        dp[i] = maxVal + 1;
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << lengthOfLongest(nums);
    return 0;

}