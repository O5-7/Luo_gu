#include <iostream>
#include <cmath>

using namespace std;
int a;

int main() {
    cin >> a;
    int *nums = new int[a - 2];
    for (int i = 0; i < a - 2; i++) {
        nums[i] = i + 2;
    }
    for (int i = 0; i < a - 2; i++) {
        if (nums[i] == 0)continue;
        int did = nums[i];
        for (int x = i + 1; x < a - 2; x++) {
            if ((nums[x] % did) == 0) {
                nums[x] = 0;
            }
        }
    }
    int k_nums = 0;
    for (int i = 0; i < a - 2; i++) {
        if (nums[i] != 0) k_nums++;
    }
    int *k_nums_list = new int[k_nums];
    int m = 0;
    for (int i = 0; i < a - 2; i++) {
        if (nums[i] != 0) {
            k_nums_list[m] = nums[i];
            m++;
        };
    }
    delete[] nums;


    for (int x = 0; x < k_nums; x++) {
        for (int y = 0; y < k_nums; y++) {
            for (int z = 0; z < k_nums; z++) {
                if (k_nums_list[x] + k_nums_list[y]+ k_nums_list[z] == a){
                    cout << k_nums_list[x] << ' '<< k_nums_list[y] << ' '<< k_nums_list[z];
                    return 0;
                }
            }
        }
    }

}
