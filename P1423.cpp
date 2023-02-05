# include <iostream>
# include <cmath>

int main(){
    double dis;
    double swim = 0;
    int step = 0;
    std::cin >> dis;
    while (true){
        step++;
        swim += 2.0 * pow(0.98, step - 1);
        if (swim >= dis){
            std::cout << step;
            break;
        }
    }
}
