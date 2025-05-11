#include <iostream>
#include <string>

std::string reverseStr(std::string& str) {
    std::string res = "";
    for (int i=str.length()-1; i>=0; i--) {
        res += str[i];
    }
    return res;
}

int main() {
    std::string str = "this is a new solution";
    // output - olleh

    std::string res = reverseStr(str);
    std::cout << res << std::endl;
    return 0;
}