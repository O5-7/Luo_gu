#include <iostream>

int main() {
    char ISBN[14] = {0};
    std::cin >> ISBN;

    int judge_real = 0;
    int judge_input = 0;
    int index = 1;
    for (int i = 0; i < 13; i++) {
        if (ISBN[i] == 45) continue;
        int num = ISBN[i] - 48;
        if (i <= 10) judge_real += num * (index++);
        if (i == 12) judge_input = num;
    }
    if (judge_input == 40) judge_input = 10;
    judge_real = judge_real % 11;
    if (judge_real == judge_input) std::cout << "Right" << std::endl;
    else{
        if (judge_real == 40) ISBN[12] = 'X';
        else ISBN[12] = (char)(judge_real + 48);
        std::cout << ISBN << std::endl;
    }
}
