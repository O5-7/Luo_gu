#include <iostream>
#include <string>

int main(){
    std::string word;
    std::string liter;
    std::getline(std::cin, word);
    for (char & c : word) if (isupper(c)) c = (char)tolower(c);
    std::getline(std::cin, liter);

    int index[100000] = {-1};
    int index_i = 1;
    for (int i = 0;i < liter.size();i++){
        if (isupper(liter[i])) liter[i] = (char)tolower(liter[i]);
        if (liter[i] == ' ') index[index_i++] = i;
    }

    int sum = 0;
    int first_index = -1;
    for (int i = 0; i < index_i; i++){
        std::string sub_string =  liter.substr(index[i]+1, index[i+1] - index[i] -1);
        if (sub_string == word){
            sum++;
            if (first_index  == -1) first_index = index[i] + 1;
        }
    }
    if (sum == 0) std::cout << -1 <<std::endl;
    else std::cout << sum << ' ' << first_index << std::endl;

}