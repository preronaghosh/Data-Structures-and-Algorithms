#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::pair<int, int> countLetters(const std::string& str) {
    int nVowels = 0, nConsonants = 0;
    
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (const char& c : str) {
        if (std::find(vowels.begin(), vowels.end(), c) != vowels.end()) {
            nVowels++;
        } else if (std::isalpha(c)) {
            nConsonants++;
        }
    }
    return {nVowels, nConsonants};
}

int main() {

    const std::string str = "Hello World";
    std::pair<int, int> results = countLetters(str);
    std::cout << "Vowels: " << results.first << " Consonants: " << results.second;

    return 0;
}