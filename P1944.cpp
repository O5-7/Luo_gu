#include <iostream>
#include <cstring>

using namespace std;

struct brackets {
    char bracket;
    int index;
    brackets *last;
    brackets *next;
};

int main() {
    string input;
    cin >> input;
    bool *fit = new bool[(int) input.length()];
    memset(fit, false, sizeof(*fit) * input.length());
    auto *pin = new brackets;
    pin->last = nullptr;
    pin->next = nullptr;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        pin->bracket = c;
        pin->index = i;
        pin->next = new brackets;
        pin->next->last = pin;
        pin->next->next = nullptr;
        if (pin -> last == nullptr) {
            pin = pin->next;
            continue;
        }
        if ((pin->bracket == ']' && pin->last->bracket == '[') || (pin->bracket == ')' && pin->last->bracket == '(')) {
            fit[pin->last->index] = true;
            fit[pin->index] = true;

            pin = pin->last;
            delete pin->next;
            pin = pin->last;
            if (pin == nullptr) {
                pin = new brackets;
                pin->last = nullptr;
                pin->next = nullptr;
            } else {
                delete pin->next;
                pin->next = new brackets;
                pin->next->last = pin;
                pin->next->next = nullptr;
                pin = pin->next;
            }
        } else {
            pin = pin->next;
        }
    }

    int begin = 0;
    int end = 0;
    bool is_continue = false;
    string out;
    for (int i = 0;i<input.length();i++){
        if (fit[i]){
            if (is_continue){
                end = i;
            }else{
                is_continue = true;
                begin = i;
            }
        }else{
            if (is_continue){
                is_continue = false;
                if (end - begin + 1 > out.length()) out = input.substr(begin, end - begin + 1);
                begin = 0;
                end = 0;
            }
        }
    }
    cout << out;

}