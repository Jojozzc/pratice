#include<iostream>
#include <string>
#include <set>
#include <map>

using namespace std;


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
    map<char, int > check;
    for (int i = 0; i < len; ++i) {
        if (check.find(s[i]) == check.end()) {
            check[s[i]] = 1;
        } else{
            check[s[i]]++;
        }
    }
    // 可以通过找s的长度为len的字串，看看是不是满足条件，找出字典序最小的
    for (int i = len; i < s.length() - len + 1; ++i) {
        check[s[i - 1]]--;
        if (check[s[i - 1]] == 0) {
            check.erase(s[i - 1]);
        }
        if (check.find(s[i + len - 1]) == check.end()) {
            check[s[i + len - 1]] = 1;
        } else {
            check[s[i + len - 1]]++;
        }
        if (check.size() == len) {
            if (s.substr(i, len) < temp) {
                temp = s.substr(i, len);
            }
        }
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