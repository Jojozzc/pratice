#include <iostream>
#include <vector>
using namespace std;


int main(){
    string str;
    cin >> str;
    int len = str.length();
    string outStr = "";
    int pre = 0;
    int p = 0;
    while (p < len) {
        if (str[p] == str[pre]) {
            if (p == len - 1) {
                outStr = outStr + str[p] + to_string(p - pre + 1);
            }
        } else {
            outStr = outStr + str[pre] + to_string(p - pre);
            if (p == len - 1) {
                outStr = outStr + str[p] + "1";
            }
            pre = p;
        }
        p++;
    }
    cout << outStr << endl;
    return 0;
}

