#include <iostream>

using namespace std;
int n, k;
int *xn;
int sum = 0;
int *sign_num;
int out_count = 0;

void find(int rest_num = k,int sum_out = 0,int index = 0){
    if (rest_num == 0){
        for (int i = 0;i < sum -1;i++){
            if (sum_out == sign_num[i]){
                out_count++;
                break;
            }
        }
    }
    for(int i = index;i < n;i++){
        find(rest_num - 1,xn[i] + sum_out,i+1);
    }
}

int main() {

    cin >> n >> k;
    xn = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> xn[i];
        sum += xn[i];
    }
    sign_num = new int[sum - 1];
    for (int i = 0; i < sum - 1; i++) {
        sign_num[i] = i + 2;
    }

    for (int i = 0; i < sum - 1; i++) {
        if (sign_num[i] == 0) continue;
        int key_num = sign_num[i];
        for (int x = i + 1; x < sum - 1; x++) {
            if (sign_num[x] % key_num == 0) sign_num[x] = 0;
        }
    }

    find();
    cout << out_count;

}