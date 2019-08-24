#include<iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int len;
    cin >> len;
    string str;
    cin >> str;
    int dp[1000000][2];
    if(str[0]<='Z'){
        dp[0][0]=0;
        dp[0][1]=1;
    }
    else {
        dp[0][0]=0;
        dp[0][1]=2;
    }
    for(int i = 0; i < len;i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
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
    cout << min(dp[len][0],dp[len][1]) << endl;
    return 0;


}