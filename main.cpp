#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    vector<int> nums;
    int n = 0;
    while (cin >> n) {
        nums.push_back(n);
    }
    int len = nums.size();
    int* dp = new int[len];
    for (int i = 0; i < len / 2; ++i) {
        dp[i] = 1;
    }
    for (int i = len / 2; i < len; ++i) {
        dp[i] = 999999;
        for (int j = 0; j < i; ++j) {
            if (nums[j] + j == i) {
                dp[i] = min(dp[j] + 1, dp[i]);
            }
        }
    }
    if (dp[len - 1] >= len) {
        cout << -1 << endl;
    } else {
        cout << dp[len - 1] << endl;
    }
    return 0;
}