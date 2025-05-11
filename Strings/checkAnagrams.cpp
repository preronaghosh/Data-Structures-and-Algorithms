#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

bool checkAnagramsUsingSorting(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

bool checkAnagramsUsingFrequencyMap(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) return false;

    // using frequency map
    std::unordered_map<char, int> freqMap;
    for(char c : s1) {
        freqMap[c]++;
    }

    for (auto c : s2) {
        if (freqMap.find(c) == freqMap.end() || freqMap[c] == 0) { // if already 0, then this character does not exist in s1 with the same frequency of s2
            return false;
        }
        freqMap[c]--; // if found, decrease the frequence
    }

    return true;
}

int main() {
    std::string s1 = "listennn"; 
    std::string s2 = "silent";

    if (checkAnagramsUsingFrequencyMap(s1, s2)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}