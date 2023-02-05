# include <iostream>

int main(){
    int n;
    std::cin >> n;
    int set[n];
    for (int i = 0; i<n; i++){
        std::cin >> set[i];
    }

    int sum = 0;
    for (int & i: set){
        int a, b;
        bool exist = false;
        for (int x = 0; x < n; x++){
            a = set[x];
            for (int y = x + 1;y < n; y++){
                b = set[y];
                if (a + b == i) exist = true;
            }
        }
        if (exist) sum++;
    }
    std::cout << sum;
}