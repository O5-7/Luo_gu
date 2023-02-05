#include <iostream>
#include <cmath>

using namespace std;
int A, B, C;

int main() {
    int count = 0;
    cin >> A >> B >> C;
    int out[9] = {0};
    for (int a = 100; a < 999; a++) {
        int b = ((float)a / A) * (float)B;
        int c = ((float)a / A) * (float)C;
        if (b > 999 || b < 100 || c > 999 || c < 100)break;
        out[0] = int(a) / 100;
        out[1] = (int(a) % 100) / 10;
        out[2] = (int(a) % 10);
        out[3] = int(b) / 100;
        out[4] = (int(b) % 100) / 10;
        out[5] = (int(b) % 10);
        out[6] = int(c) / 100;
        out[7] = (int(c) % 100) / 10;
        out[8] = (int(c) % 10);
        bool out_able = true;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (x == y) {
                    continue;
                } else {
                    if (out[x] == out[y]) out_able = false;
                    if (out[x] == 0) out_able = false;
                }
            }
            if (!out_able) break;
        }
        if (!out_able) continue;
        count++;
        for (int i = 0; i < 9; i++) {
            cout << out[i];
            if (i == 2 || i == 5) cout << ' ';
        }
        cout << std::endl;
    }
    if (count == 0) cout << "No!!!";
}
