#include <iostream>
#include <string>
#include <unordered_set>

std::string removeDuplicates(std::string& str) {
    std::unordered_set<char> newStr;
    std::string retStr = "";

    for (const char& c : str) {
        if (newStr.insert(c).second) { 
            // set did not have this character before, hence it was successfully inserted
            retStr += c;
        }
    }  
    return retStr;
}

int main() {
    std::string str = "banana";
    std::string newStr = removeDuplicates(str);
    std::cout << newStr << std::endl;
    return 0;
}