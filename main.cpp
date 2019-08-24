#include<iostream>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int len;
    cin >> len;
    string str;

    cin >> str;
    int** dp;
    dp = new int*[len + 1];
    for (int i = 0; i <= len; ++i) {
        dp[i] = new int[2];
    }
    dp[0][0] = 0;
    dp[0][1] = 0x3f3f3f;
    for(int i = 0; i < len;i++)
    {
        if(str[i]>='a' && str[i]<='b')
        {
            dp[i+1][0]=min(dp[i][0]+1,dp[i][1]+2);
            dp[i+1][1]=min(dp[i][0]+2,dp[i][1]+2);
        }
        else
        {
            dp[i+1][0]=min(dp[i][0]+2,dp[i][1]+2);
            dp[i+1][1]=min(dp[i][0]+2,dp[i][1]+1);
        }
    }
    cout << min(dp[len][0],dp[len][1]+1) << endl;
    return 0;


}