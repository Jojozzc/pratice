#include <iostream>
#include <vector>
using namespace std;

int binSearch(vector<long >& sums, int cur, int curVal){
    int left = 0;
    int right = cur;
    while (left <= right) {
        int mid = (left + right) / 2;
        long sum = sums[cur] - sums[mid];
        if (sum == curVal) {
            return mid;
        } else if (sum > curVal) {
            left = mid + 1;
        } else {// sum <= curVal
            if (mid == left) {
                return left;
            } else {
                if (sums[cur] - sums[mid - 1] <= curVal) {
                    right = mid - 1;
                } else {
                    return mid;
                }
            }
        }
    }
    return cur;
}

int calLongestPerfectSub(vector<int>& nums){
    if (nums.empty()) {
        return 0;
    }
    int res = 1;
    vector<long> sums;
    int len = nums.size();
    sums.push_back(0);
    int pre = 0;

    for (int i = 0; i < len; ++i) {
        sums.push_back(sums[i] + (long)nums[i]);
    }

    for (int i = 0; i < len; ++i) {
        int tempPre = binSearch(sums, i, nums[i]);
        pre = max(pre, tempPre);
        res = max(res, i - pre + 1);
    }

    return res;

}

int main(){
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n = 0;
        cin >> n;
        vector<int> nums;
        for (int j = 0; j < n; ++j) {
            int temp = 0;
            cin >> temp;
            nums.push_back(temp);
        }
        cout << calLongestPerfectSub(nums) << endl;
    }
    return 0;
}

