/* Check if the ith bit of a number is set or not */

#include <iostream>
using namespace std;

int main() {
    int n = 13;
    int i = 1; // check if 2nd bit of 13 is set or not (2nd bit is 3 positions left of lsb bit)

    bool isSet = (n & (1 << i)) != 0;
    cout << "isSet: " << isSet << endl;
}