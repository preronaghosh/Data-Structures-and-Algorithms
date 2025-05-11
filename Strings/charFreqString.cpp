#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> getFreqMap(const std::string& str) {
    std::unordered_map<char, int> freqMap;

    for (const char& c : str) {
        if (c != ' ') {
            freqMap[c]++;
        }
    }
    return freqMap;
}

int main() {
    const std::string str = "banana";
    auto fMap = getFreqMap(str);

    for(const auto& pair : fMap) {
        std::cout << pair.first << ":" << pair.second << " ";
    }

    return 0;
}