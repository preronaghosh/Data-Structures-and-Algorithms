// Create a function that reverses a string
// Example: 'Hi My name is Andrei' --> 'ierdnA si eman yM iH'
#include<string>
#include<iostream>
#include<algorithm>

std::string reverseString (const std::string str) {
    std::string revStr = "";
    for(int i = str.length() - 1; i >=0; i--) {
        revStr += str[i];
    }
    return revStr;
}

// Using C++ STL
void reverseAgain(std::string& str) {
    std::reverse(str.begin(), str.end());
}

// Can also swap first and last letters until we reach the middle 
// Based on odd or even number of characters

int main() {
    std::string result = reverseString("Hi My name is Andrei");
    std::cout << "Result: " << result << std::endl;

    std::string str2 = "Hello World";
    reverseAgain(str2);
    std::cout << "Reversed str2: " << str2 << std::endl;

    return 0;
}
