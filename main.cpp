#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;


bool judge(int num) {
    int h = num / 100;
    int d = num / 10 % 10;
    int u = num % 10;
    return num == (h * h * h + d * d * d + u * u * u);
}

int main() {
    int n;
    cin >> n;
    int big = n;
    int small = n;
    bool bigFind = false;
    bool smallFind = false;
    int bigRes = 999999;
    int smallRes = 99999;
    while (big < 1000 || small > 99) {
        if (!bigFind && big < 1000) {
            if (judge(big)) {
                bigFind = true;
                bigRes = big;
            }
            big++;
        } else{
            big = 1000;
        }
        if (!smallFind && small > 99) {
            if (judge(small)) {
                smallFind = true;
                smallRes = small;
            }
            small--;
        } else{
            small = 0;
        }
        if (smallFind && bigFind) {
            break;
        }
    }
    cout << ((abs(n - smallRes) > bigRes - n) ? bigRes : smallRes) << endl;
}