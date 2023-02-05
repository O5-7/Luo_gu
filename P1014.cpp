#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    int line_len = 1;
    while (true) {
        count += line_len;
        if (N > count) {
            line_len++;
            continue;
        } else {
            int over_count = count - N;
            if (line_len % 2 == 0) cout << line_len - over_count << '/' << 1 + over_count;
            else cout << 1 + over_count << '/' << line_len - over_count ;
            return 0;
        }
    }
}