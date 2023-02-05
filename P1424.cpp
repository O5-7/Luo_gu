# include <iostream>

int main(){
    int sum = 0;
    int week, day;
    std::cin >> week >> day;
    for (int i = 0; i<day; i++){
        if (week != 6 and week != 7) sum += 250;
        week++;
        if (week == 8) week = 1;
    }
    std::cout << sum;
}
