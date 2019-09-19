#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> nums;
    int n = 0;
    while (cin >> n) {
        nums.push_back(n);
    }
    int k = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[k]) {
            continue;
        } else{
            k++;
            nums[k] = nums[i];
        }
    }
    for (int i = 0; i <= k; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << nums[i];
    }
    return 0;
}