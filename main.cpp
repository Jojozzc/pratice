#include <iostream>
#include <vector>

using namespace std;

int fact[] = {1,1,2,6,24,120,720};

int main(){
    int n = 0;
    cin >> n;
    cout << fact[6] / fact[6 - n] << endl;
    return 0;
}

