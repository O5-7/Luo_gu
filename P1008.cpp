#include <iostream>

int main() {
    int out[9] = {0};
    for(int a = 100;a<999;a++){
        int b = 2 * a;
        int c = 3 * a;
        if (c > 999) break;
        out[0] = a / 100;
        out[1] = (a % 100) / 10;
        out[2] = (a % 10);
        out[3] = b / 100;
        out[4] = (b % 100) / 10;
        out[5] = (b % 10);
        out[6] = c / 100;
        out[7] = (c % 100) / 10;
        out[8] = (c % 10);
        bool out_able = true;
        for (int x = 0;x<9;x++){
            for (int y = 0;y<9;y++){
                if (x == y){
                    continue;
                }else{
                    if (out[x] == out[y]) out_able = false;
                    if (out[x] == 0) out_able = false;
                }
            }
            if (!out_able) break;
        }
        if (!out_able) continue;
        for (int i = 0;i<9;i++){
            std::cout << out[i];
            if (i == 2 || i ==5) std::cout << ' ';
        }
        std::cout << std::endl;
    }
}
