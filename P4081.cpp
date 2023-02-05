#include <iostream>
#include <vector>

using namespace std;

struct index_string {
    int index;
    string string_unique;
};

int main() {
    int N;
    cin >> N;
    vector<string> string_array = vector<string>(N, "");


    int string_MAX_length = 0;
    for (int i = 0; i < N; i++) {
        cin >> string_array[i];
        if (string_array[i].length() > string_MAX_length) string_MAX_length = string_array[i].length();
    }
    vector<vector<index_string>> unique_strings = vector<vector<index_string>>(string_MAX_length + 1, vector<index_string>());

    for (int i = 0; i < N; i++) {
        int index = string_array[i].length();
        unique_strings[index].push_back({i, string_array[i]});
    }

    for (int i = string_MAX_length; i > 0; i--) {
        for (index_string s: unique_strings[i]) {
            if (i == 1) continue;
            index_string left = s;
            left.string_unique = left.string_unique.substr(1, left.string_unique.length() - 1);
            index_string right = s;
            right.string_unique = right.string_unique.substr(0, right.string_unique.length() - 1);
            bool left_in = true;
            bool right_in = true;

            for (index_string s_1: unique_strings[i - 1]) {
                if (left_in && s_1.index == left.index && s_1.string_unique == left.string_unique) {
                    left_in = false;
                }
                if (right_in && s_1.index == right.index && s_1.string_unique == right.string_unique) {
                    right_in = false;
                }
            }

            if (left_in) unique_strings[i - 1].push_back(left);
            if (right_in) unique_strings[i - 1].push_back(right);
        }
    }

    for (int i = string_MAX_length; i > 0; i--){
        for (int j = 0;j < unique_strings[i].size();j++) {
            if (unique_strings[i][j].index == -1) continue;
            for (int k = j+1;k< unique_strings[i].size();k++){
                if (unique_strings[i][k].string_unique == unique_strings[i][j].string_unique){
                    unique_strings[i][k].index = -1;
                    unique_strings[i][j].index = -1;
                }
            }
        }
    }

    vector<int> count = vector<int>(N,0);
    for (int i = string_MAX_length; i > 0; i--){
        for (index_string s: unique_strings[i]) {
            if (s.index == -1) continue;
            else{
                count[s.index] += 1;
            };
        }
    }

    for (int i : count){
        cout << i << endl;
    }

}