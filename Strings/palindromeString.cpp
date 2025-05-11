#include <iostream>
#include <string>

bool checkPal(std::string& str) {
    int left = 0;
    int right = str.length()-1;
    while (left <= right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main() {
    std::string str = "madam";
    bool res = checkPal(str);
    std::cout << res << std::endl;

    str = "rice";
    res = checkPal(str);
    std::cout << res << std::endl;
    return 0;
}