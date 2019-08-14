#include<iostream>
#include <string>
#include <vector>


using namespace std;


int minOp(string s1, string s2) {
    int l1 = s1.length(), l2=s2.length();
    vector<vector<int>>dp(l1 + 1, vector<int>(l2 + 1));
    for(int i = 0;i <= l1;i++){
        for(int j = 0;j <= l2;j++){
            if(i == 0){
                dp[i][j] = j;   //如果 i=0 则需要插入j个字符
            }else if(j == 0){
                dp[i][j] = i;    //如果j=0则需要删除i个字符
            }else if(s1[i-1] == s2[j-1]){   //如果字符相同则不做变换，等于这个字符之前的步数
                dp[i][j] = dp[i-1][j-1];
            }else{                          //否则 就从插入，删除，修改中选择最小的 加 1
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
    }
    return dp[l1][l2];
}

void t2(){
    string s1;
    string s2;
    while (cin >> s1 && cin >> s2) {
        cout << minOp(s1, s2) << endl;
    }
}


int main() {
    t2();
}