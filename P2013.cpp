# include <iostream>

int single_num(unsigned long long num, int x ,int count = 0){
    unsigned long long sig_num;
    if (num >= 10){
        sig_num = num % 10;
        num = num / 10;
    }else{
        if (num == x) return 1 + count;
        else return count;
    }
    if (sig_num == x) count++;
    return single_num(num, x, count);
}

int main(){
    int n, x, sum = 0;
    std::cin >> n >> x;
    for (int i = 1; i <= n; i++){
        sum += single_num((unsigned long long)i, x);
    }
    std::cout << sum;

}
