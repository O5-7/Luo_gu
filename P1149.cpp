#include <iostream>

using namespace std;

int requset(int num) {
    switch (num) {
        case 0:
            return 6;
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 6;
        default:
            return 0;
    }
}

int full_request(int num){
    if (num <=9) return requset(num);
    return requset(num % 10) + full_request(num / 10);
}

int range = 1000;

int main() {
    int count = 0;
    int n;
    cin >> n;
    if (n <= 4) {
        cout << 0 ;
        return 0;
    }
    n-=4;
    for (int a = 0; a < range;a++){
        for(int b = 0;b < range;b++){
            int c = a+b;
            if (full_request(a) + full_request(b) + full_request(c) == n) count++;
        }
    }
    cout << count;
}