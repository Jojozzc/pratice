#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;


int minOp(string s1, string s2) {
    int l1 = s1.length(), l2=s2.length();
    vector<vector<int>>dp(l1 + 1, vector<int>(l2 + 1));
    for(int i = 0;i <= l1; i++){
        for(int j = 0;j <= l2; j++){
            if(i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
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

string minW(string s, string t){
    int *check = new int['z' + 1];
    int *count = new int['z' + 1];
    for (int i = 0; i < 'z' + 1; ++i) {
        check[i] = 0;
        count[i] = 0;
    }
    int left = -1;
    int right = s.length();
    int start = 0;
    int minLen = s.length() + 1;
    for(int i = 0; i < t.length(); i++) check[t[i]]++;
    int countNum = 0;
    char ch;
    for(int i = 0; i < s.length(); i++){
        ch = s[i];
        if(check[ch] == 0){
            continue;
        }
        if(count[ch] < check[ch]){
            // 还没达到
            countNum++;
        }
        count[ch]++;
        if(countNum == t.length()){
            // 够了
            for(int j = start; j < i; j++){
                if(check[s[j]] == 0) {
                    start++;
                }
                else{
                    if(count[s[j]] == check[s[j]]){
                        start = j;
                        break;
                    }
                    else{
                        count[s[j]]--;
                        start++;
                    }
                }
            }
            if(minLen > i - start + 1){
                minLen = i - start + 1;
                left = start;
                right = i;
            }
        }
    }
    return left == -1 ? "" : s.substr(left, right + 1 - left);
}


string shortestSubstrAll(string s) {
    string minS = "";
    set<char> mark;
    for (int i = 0; i < s.length(); ++i) {
        if (mark.find(s[i]) == mark.end()) {
            mark.insert(s[i]);
            minS += s[i];
        }
    }

    // 这个temp不是字典序最小
    string temp = minW(s, minS);
    int len = temp.length();
    // 可以通过找s的长度为len的字串，看看是不是满足条件，找出字典序最小的
    for (int i = 0; i < s.length() - len + 1; ++i) {

    }
    return temp;
}


void t3(){
    string s;
    cin >> s;
    cout << shortestSubstrAll(s) << endl;
}

int main() {
    t3();
}