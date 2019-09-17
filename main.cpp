#include <iostream>
#include <string>
using namespace std;

bool validIpv4(string IP) {
    int cnt = 0;
    function <bool(char)> isNumber = [] (char c) {return isdigit(c);};
    for(auto it = IP.begin(); it != IP.end(); ) {
        if(isNumber(*it)) {
            auto it2 = find_if_not(it, IP.end(), isNumber);
            if(it2 != IP.end() && (*it2) != '.') {//divider must be '.' or ending flag
                return false;
            }
            string sub = string(it, it2);
            if((sub.size() > 1 && sub[0] == '0') || sub.size() > 3 || stoi(sub) > 255) {// no leading zero, digits <= 3, num <= 255
                return false;
            }
            cnt++;
            if(cnt == 4 && it2 != IP.end()) {//no more than 4 segments
                return false;
            }
            it = it2;
        }
        else {
            if(*it != '.') {// only '.' can be divider
                return false;
            }
            it++;
            if(it != IP.end() && (*it) == '.') {// no consecutive '.' permitted.
                return false;
            }
        }
    }
    return cnt == 4;
}
int main() {
    string str;
    cin >> str;
    cout << validIpv4(str) << endl;
}