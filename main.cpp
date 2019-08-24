#include<iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* nums = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    stack<int*> st;
    int init[2] = {0, 0};
    st.push(init);
    int lastMax = 0;

    int maxNum = nums[0];
    int minNum = nums[0];

    for(int i = 1; i < n; ++i){
        while (nums[i] < lastMax){
            int* tmp = st.top();
            st.pop();
            maxNum = max(maxNum, tmp[1]);
            minNum = max(minNum, tmp[0]);
            minNum = min(nums[i], minNum);
            lastMax = st.top()[1];
        }
        minNum = min(nums[i], minNum);
        if(nums[i] >= maxNum){
            int tArr[] = {minNum, maxNum};
            st.push(tArr);
            lastMax = maxNum;
            maxNum = nums[i];
            minNum = nums[i];
        }
    }
    cout << st.size() << endl;
    return 0;


}