#include <string>
#include <iostream>

using namespace std;
string intToRoman(int num) {
    string ones[] = { "","I", "II", "III","IV","V","VI","VII","VIII","IX" };
    string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    string hunds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    string thous[] = { "", "M", "MM", "MMM" };

    string ans = "";
    ans += thous[num / 1000];
    ans += hunds[num / 100 % 10];
    ans += tens[num / 10 % 10];
    ans += ones[num % 10];
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << intToRoman(n) << endl;
    return 0;
}
