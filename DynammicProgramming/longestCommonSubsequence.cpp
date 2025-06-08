/* Write a program to find the length of the longest common subsequence of a string or array using Recursion */

#include <string>
#include <iostream>
using namespace std;

int lengthOfLCS(int i, int j, string& s1, string& s2) {
    if (i == 0 || j == 0) return 0;

    if (s1[i] == s2[j]) {
        return 1 + lengthOfLCS(i-1, j-1, s1, s2);
    } else {
        return max(lengthOfLCS(i-1, j, s1, s2), lengthOfLCS(i, j-1, s1, s2));
    } 
}

int main() {
    string s1 = "ce";
    string s2 = "abcde";

    cout << lengthOfLCS(s1.length(), s2.length(), s1, s2) << endl;
}


