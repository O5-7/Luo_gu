#include <iostream>
#include <string>

using namespace std;

void print_c(const int (&counter)[26]) {
    int max = 0;
    for (int count: counter) count > max ? max = count : max;
    for (int layer = max; layer > -1; layer--) {
        if (layer == 0) {
            cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (i == 25) {
                if (counter[i] >= layer) cout << "*";
                else cout << " ";
            } else {
                if (counter[i] >= layer) cout << "* ";
                else cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    string input;
    string input_4;
    int counter[26] = {0};
    for (int i = 0; i < 4; i++) {
        getline(cin, input);
        input_4 += input;
    }
    for (char &c: input_4) if (25 >= c - 65 && c - 65 >= 0) counter[c - 65] += 1;
    print_c(counter);
}