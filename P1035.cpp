# include <iostream>

int main(){
    int k = 0;
    std::cin >> k;
    double sum = 0;
    int n = 0;
    while (true){
        n++;
        sum += 1.0 / n;
        if (sum > k){
            std::cout << n;
            break;
        }
    }
}
