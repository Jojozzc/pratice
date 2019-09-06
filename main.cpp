#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    int result = 0;
    cin >> n;
    if (n <= 1) {
        cout << 1;
        return 0;
    }
    int* nums = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }


    int start = 0;

    int single = 1;
    while (start < n) {
        while (start < n && nums[start] == 1) {
            start++;
        }
        if (start == n) {
            break;
        }
        int p = start;
        while (p < n && nums[p] == 0) {
            p++;
        }
        // p是1或者边界的位置
        int zeroCount = p - start;
        if (start > 0 && p < n) {
            // 前后都是1
            if (zeroCount <= 2) {
                single = 0;
            } else if (zeroCount % 2 == 1) {
                // 奇数个数的0只能有一种改法
                single = zeroCount / 2;
            } else {
                // 个数是偶数
                single = (zeroCount - 1) / 2;
            }
        } else if (start == 0 && p == n){
            // 前后都没东西
            if (zeroCount % 1 == 1) {
                single = (zeroCount + 1) / 2;
            } else {
                single = zeroCount / 2;
            }
        } else {
            // 前后只有一个地方是1
            single = zeroCount / 2;
        }

        start = p;
        result += single;
    }
    cout << result << endl;
    return 0;

}