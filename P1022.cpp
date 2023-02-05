#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int int_num = 0;
    int unknow_num = 0;

    string equality;
    cin >> equality;
    string left;
    string right;
    for (int i = 0; i < equality.length(); i++) {
        if (equality[i] == '=') {
            left = equality.substr(0, i);
            right = equality.substr(i + 1, equality.length() - i - 1);
        }
    }
    if (left[0] != '-') left = '+' + left;
    if (right[0] != '-') right = '+' + right;
    for (char &a: right) {
        if (a == '-') {
            a = '+';
            continue;
        }
        if (a == '+') {
            a = '-';
            continue;
        }
    }
    equality = left + right + "+";
    string signal_one = "";
    char unknow;
    int sign = 1;
    for (char a: equality) {
        if (a == '+' || a == '-') {
            if (signal_one.length() != 0) int_num += sign * stoi(signal_one);
            signal_one = "";
            if (a == '+') sign = 1;
            if (a == '-') sign = -1;
            continue;
        }
        if (a >= 48 && a <= 57) {
            signal_one += a;
        } else {
            unknow = a;
            if (signal_one.length() == 0) signal_one = '1';
            if (signal_one.length() != 0) unknow_num += sign * stoi(signal_one);
            signal_one = "";
        }
    }
    int answer = -int((float) int_num * 1000 / (float) unknow_num);
    string out = to_string(answer);
    while (out.length() < 4) out = '0' + out;
    cout << unknow << '=' << out.substr(0, out.length() - 3) << '.' << out.substr(out.length() - 3, 3);
}