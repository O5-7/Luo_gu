#include <iostream>

using namespace std;

int t;
int out_count = 0;
string final_out = "";

void find_x(int t_request, int index = 0, string out = "") {
    if (t_request < 0) return;
    if (index == 10 && t_request == 0) {
        out_count++;
        final_out += out + '\n';
        return;
    }
    if (index == 10) return;
    find_x(t_request - 1, index + 1, out + "1 ");
    if (t_request == 1) return;
    find_x(t_request - 2, index + 1, out + "2 ");
    if (t_request == 2) return;
    find_x(t_request - 3, index + 1, out + "3 ");
}

int main() {
    cin >> t;
    find_x(t);
    cout << out_count << endl;
    cout << final_out;
}