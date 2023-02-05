#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float s, x;
    cin >> s >> x;
    float dis = 0;
    float time = 0;
    float speed = 7;

    float swim_in_time = 0;
    float swim_out_time = 0;
    bool in_ = false;

    while (true) {
        if (speed < x){
            cout << 'y';
            return 0;
        }
        dis += speed;
        time++;
        if (dis > s - x && dis < s + x && !in_) {
            in_ = true;
            swim_in_time = time - (dis - s + x) / speed;
            if (swim_in_time < 0) swim_in_time = 0;
        }
        if (dis > s + x && in_) {
            swim_out_time = time - (dis - s - x) / speed;
            break;
        }
        speed *= 0.98f;
    }
    if (swim_out_time - swim_in_time < 1) {
        cout << 'n';
    } else cout << 'y';

}