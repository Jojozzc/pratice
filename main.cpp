#include <iostream>
#include <vector>
#include <set>
using namespace std;

int maxResult = -9000000;

void dfs(vector<int>& a, vector<int>& b, set<int>& mark,  int m, int *curSum){
    if (m == 0) {
        maxResult = max(maxResult, *curSum);
        return;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (mark.find(i) == mark.end()) {
            a[i] -= b[i];
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        if (mark.find(i) != mark.end()) {
            continue;
        }
        mark.insert(i);
        *curSum += (a[i] + b[i]);
        dfs(a, b, mark, m - 1, curSum);
        mark.erase(i);
    }
    for (int i = 0; i < a.size(); ++i) {
        if (mark.find(i) == mark.end()) {
            a[i] += b[i];
        }
    }

}

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    set<int> mark;
    int* curSum = new int[1];
    curSum[0] = 0;
    dfs(a, b, mark, m, curSum);
    cout << maxResult << endl;
    return 0;
}