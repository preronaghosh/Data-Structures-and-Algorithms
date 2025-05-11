#include <iostream>
#include <string>
#include <sstream>

std::string replaceWhiteSpace(const std::string& str) {
    std::stringstream ss{str};
    std::string word = "";
    std::string result = "";
    while (ss >> word) {
        result += word + "%20";
    }
    return result;
}   

int main() {
    const std::string s1 = "Hello World. This is a test string.";
    // output : "Hello%20World.%20This%20is%20a%20test%20string."

    auto res = replaceWhiteSpace(s1);
    std::cout << res << std::endl;
    return 0;
}