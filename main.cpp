#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


void xhs1(){
    string str;
    cin >> str;
    int len = str.length();

    stack<char> judgeStack;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '(') {
            judgeStack.push(str[i]);
        } else if (str[i] == ')') {
            judgeStack.pop();
        } else if (str[i] == '<') {
            if (judgeStack.empty()) {
                continue;
            } else if (judgeStack.top() == '('){
                continue;
            } else {
                judgeStack.pop();
            }
        } else {
            if ((!judgeStack.empty()) && (judgeStack.top() == '(')) {
                continue;
            }
            judgeStack.push(str[i]);
        }
    }
    string res = "";
    while (!judgeStack.empty()) {
        res = judgeStack.top() + res;
        judgeStack.pop();
    }
    cout << res;
}


void xhs2(){
    int N = 0;
    cin >> N;
    vector<int*> goods;
    int* dp = new int[N];
    for (int i = 0; i < N; ++i) {
        int *p = new int[2];
        cin >> p[0];
        cin >> p[1];
        goods.push_back(p);
    }
    for (int i = 0; i < N; ++i) {

    }
}

int main() {
    xhs1();



    return 0;

}