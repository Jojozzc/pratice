#include <iostream>
#include <string>
using namespace std;

string move(string s, int k){
    for (int i = 0; i < k; ++i) {
        if (i < s.length() - 1) {
            if (s[i] > s[i + 1]) {
                char ch = s[i];
                s.erase(i, 1);
                s = s + ch;
                return s;
            }
        }
    }
    return s;
}

int main(){
    string s;
    int k = 0;

    cin >> s;
    cin >> k;
    string res = s;
    k = k < s.length()? k : s.length();
    for (int i = 0; i < s.length() * 2; ++i) {
        s = move(s, k);
        if (s < res) {
            res = s;
        }
    }
    cout << res << endl;

}