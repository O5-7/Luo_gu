#include <iostream>

using namespace std;
int answer_list[21 * 21 * 21] = {0};

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        a = 0;
        b = 0;
        c = 0;
    }
    if (a > 20 || b > 20 || c > 20) {
        a = 20;
        b = 20;
        c = 20;
    }
    int index = a * 21 * 21 + b * 21 + c;
    if (answer_list[index] != 0) return answer_list[index];
    else {
        int answer;
        if (a < b && b < c) answer = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        else answer = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        answer_list[index] = answer;
        return answer;
    }
}

int main() {
    answer_list[0] = 1;
    while (true) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == b && b == c && a == -1) return 0;
        cout << "w(" << a
             << ", " << b
             << ", " << c << ") = ";
        if (a <= 0 || b <= 0 || c <= 0) {
            cout << w(0, 0, 0) << endl;
            continue;
        }

        if (a > 20 || b > 20 || c > 20) cout << w(20, 20, 20) << endl;
        else cout << w(int(a), int(b), int(c)) << endl;
    }
}