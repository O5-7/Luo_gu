#include <iostream>

using namespace std;

int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;

    int *apples_h = new int[n];
    int *apples_f = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> apples_h[i] >> apples_f[i];
    }

    int out = 0;
    int h_limit = a + b;
    int f_low = 0;
    while (true) {
        for (int i = 0; i < n; i++) {
            if (apples_h[i] <= h_limit) {
                if (apples_f[i] == f_low) {
                    out++;
                    s -= f_low;
                    if (s < 0) break;
                }
            }
        }
        f_low++;
        if (s > 0 && out != n && f_low <= 100) continue;
        else break;
    }

    if (s < 0) out--;
    cout << out;


}