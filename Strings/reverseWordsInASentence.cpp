#include <iostream>
#include <string> 
#include <vector> 
#include <sstream> 

std::string reverseSentence(std::string& str) {
    std::istringstream iss{str};
    std::vector<std::string> words;
    std::string word;
    
    while (iss >> word) {
        words.push_back(word);
    }

    std::string finalStr = "";
    for (int i=words.size()-1; i>=0; i--) {
        finalStr += words[i] + " ";
    }
    return finalStr;
}

int main() {
    std::string str = "University of Waterloo in Canada";
    // output - Waterloo of University
    std::string res =  reverseSentence(str);
    std::cout << res << std::endl;
}