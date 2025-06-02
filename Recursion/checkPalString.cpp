#include <string>
#include <iostream>

bool check(std::string& s, int left, int right) {
    if (left >= right) return true;

    if (s[left] != s[right]) return false;

    return check(s, ++left, --right);
}

int main() {
    std::string str1 = "abccba"; // true
    std::cout << (check(str1, 0, str1.length()-1) ? "True" : "False") << std::endl;

    std::string str2 = "abcklba"; // false
    std::cout << (check(str2, 0, str2.length()-1) ? "True" : "False") << std::endl;

    std::string str3 = "abcba"; // true
    std::cout << (check(str3, 0, str3.length()-1) ? "True" : "False") << std::endl;

    return 0;
}