#include <iostream>
#include <cmath>

using namespace std;

bool is_loop_new(int num){
    int num_list[8] = {-1};
    int num_index = 0;
    int t_num = num;
    while(t_num != 0){
        num_list[num_index] = t_num % 10;
        t_num /= 10;
        num_index++;
    }
    int a=0,b=num_index-1;
    while (a != b && b-a !=-1){
        if (num_list[a] != num_list[b]) return false;
        a++;
        b--;
    }
    return true;
}

bool is_sig(int num) {
    int divide = (int) floor(sqrt(num));
    for (int i = 5; i < divide + 1; i+=2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int x = a; x < b + 1; x++) {
        if (x!=2 && x % 2 == 0) continue;
        if (x!=3 && x % 3 == 0) continue;
        if (x!=5 && x % 5 == 0) continue;
        if (is_loop_new(x)) {
            if (is_sig(x)) {
                cout << x << endl;
            }
        }
    }
}
