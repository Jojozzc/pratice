#include<iostream>
#include <string>


using namespace std;

bool judge(int cnt1[], int cnt2[]) {
    for (int i = 0; i < 26; ++i) {
        if (cnt1[i] != cnt2[i]) {
            return false;
        }
    }
    return true;
}
bool check(string s1, string s2){
    if (s1.length() < s2.length()) {
        return false;
    }
    int cnt1[26];
    int cnt2[26];
    for (int i = 0; i < 26; i++){
        cnt1[i] = 0;
        cnt2[i] = 0;
    }

    for (int i = 0; i < s2.length(); ++i) {
        cnt1[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.length(); ++i) {
        cnt2[s2[i] - 'a']++;
    }
    int lenDiff = s1.length() - s2.length();
    for (int i = 0; i < s1.length() - lenDiff; ++i) {
        if (judge(cnt1, cnt2)) {
            return true;
        }
        cnt1[s1[i] - 'a']--;
        if (i < s1.length()) {
            cnt1[s1[i + 1] - 'a']++;
        }
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (check(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}