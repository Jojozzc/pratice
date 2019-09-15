#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int cityNum = n + 1;
    int* a = new int[n + 2];
    int* b = new int[n + 2];
    long total = 0L;
    int* left = new int[n + 2]; // 第i个城市还差几个怪没杀


    for (int i = 1; i <= cityNum; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    left[0] = 0;
    left[1] = a[1];
    for (int i = 1; i <= n; ++i) {
        int killNum = b[i];
        if (left[i] >= killNum) {
            left[i] -= killNum;
            killNum = 0;
        } else {
            killNum = killNum - left[i];
            left[i] = 0;
        }
        if (killNum > 0) {
            left[i + 1] = max(0, a[i + 1] - killNum);
            killNum = max(0, killNum - a[i + 1]);
        }
        total += (b[i] - killNum);
    }
    total += (a[n + 1] - left[n + 1]);
    cout << total << endl;
    return 0;
}