#include <iostream>
#include <vector>
using namespace std;


int numDecodings(string s) {
    int cur = 1;
    int pre = 1;
    for(int i = 1; i < s.length(); i++){
        int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
        int temp = cur;
        if(s[i] == '0'){
            if(num > 26 || num == 0) return 0;
            cur = pre;
        }
        else{
            if(s[i - 1] == '0') cur = pre;
            else {
                if(num <= 26) cur += pre;
            }
        }

        pre = temp;
    }
    return cur;
}

int main(){
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}