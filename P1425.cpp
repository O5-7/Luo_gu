#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (d - b >= 0) {
        std::cout << c - a << ' ' << d - b << std::endl;
    }else{
        std::cout << c - a - 1 << ' ' << 60 - b + d << std::endl;
    }
}
