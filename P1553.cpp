#include <iostream>

/*什么傻逼题目*/
using namespace std;

int main() {
    string ori_num;
    cin >> ori_num;
    for (int i = 0; i < ori_num.size(); i++) {
        char c = ori_num[i];
        if (c == '.') {
            for (int x = i - 1; x > -1; x--) cout << ori_num[x];
            cout << '.';
            if (ori_num.length() - i == 2 && ori_num[ori_num.length() - 1] == '0') {
                cout << 0;
                break;
            }
            if (ori_num[i + 1] == '0') i++;
            for (int x = (int) ori_num.length() - 1; x > i; x--) cout << ori_num[x];
            return 0;
        }
        if (c == '/') {
            for (int x = i - 1; x > -1; x--) cout << ori_num[x];
            cout << '/';
            for (int x = (int) ori_num.length() - 1; x > i; x--) cout << ori_num[x];
            return 0;
        }
        if (c == '%') {
            for (int x = (int) ori_num.length() - 2; x > -1; x--) cout << ori_num[x];
            cout << '%';
            return 0;
        }
    }
    if (ori_num == "0") {
        cout << 0;
        return 0;
    }

    for (int x = (int) ori_num.length() - 1; x > -1; x--) cout << ori_num[x];
}