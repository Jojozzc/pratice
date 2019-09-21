#include <iostream>
#include <vector>
using namespace std;

bool canDiv2(vector<int>& nums, long sum) {
    if (sum % 2 == 1) {
        return false;
    }
    long half = sum / 2;
    long curSum = 0;
    int len = nums.size();
    int j = 0;
    for (int i = 0; i < len; ++i) {
        while (true) {
            if (j > len && j % len == i) {
                break;
            }
            curSum += nums[j % len];
            if (curSum == half) {
                return true;
            } else if (curSum >= half) {
                curSum -= nums[j % len];
                break;
            }
            j++;
        }
    }
    return false;
}

int main(){
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n = 0;
        cin >> n;
        vector<int> nums;
        long sum = 0;
        for (int j = 0; j < n; ++j) {
            int temp = 0;
            cin >> temp;
            sum += temp;
            nums.push_back(temp);
        }
        cout << (canDiv2(nums, sum)? "YES":"NO") << endl;
    }
    return 0;
}

