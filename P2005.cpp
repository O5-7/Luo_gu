#include <iostream>

int main(){
    int height[10] = {0};
    int taotao = 0;

    for (int & i : height){
        std::cin >> i;
    }
    std::cin >> taotao;

    int sum = 0;
    for (int & i: height) {
        if ((taotao + 30) >= i) sum++;
    }
    std::cout << sum;
}