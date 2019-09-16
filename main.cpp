#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int n, bool* mark, vector<int>& nums, vector<string>& result){
    if (nums.size() == n) {
        string str;
        for (int i = 0; i < n; ++i) {
            str += to_string(nums[i]);
        }
        result.push_back(str);
        return;
    }
    for (int i = 1; i <=n ; ++i) {
        if (mark[i]) {
            continue;
        }
        mark[i] = true;
        nums.push_back(i);
        dfs(n, mark, nums, result);
        nums.pop_back();
        mark[i] = false;
    }
}

int main(){
    int n = 0;
    cin >> n;
    vector<string> result;
    bool* mark = new bool[n + 1]; // mark[i]表示i已经在组合里了
    for (int i = 1; i <= n; ++i) {
        mark[i] = false;
    }
    vector<int> nums;
    dfs(n, mark, nums, result);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}