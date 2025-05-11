#include <iostream>
#include <string>
#include <sstream>

std::string removeWhitespaces(std::string& str) {
    std::istringstream iss{str};
    std::string result = "", tmpWord="";
    while (iss >> tmpWord) {
        result += tmpWord;
    }
    return result;
}

int main() {
    std::string str = "a b c dd e f gg hhhhh";
    std::string res = removeWhitespaces(str);
    std::cout << res << std::endl;
    return 0;
}