/* Check if a number is a power of 2 

Important Point:
- If a number is a power of 2, it will have exactly one set bit.
- So if we do a (n & (n-1)), it will return 0 for a number that is a power of 2
- If it is not, a non-zero number would be returned.

*/

#include <iostream>
using namespace std;

bool checkPowerOfTwo(int n) {
    return (n & (n-1)) == 0;
}

int main() {
    cout << checkPowerOfTwo(32) << endl;

    cout << checkPowerOfTwo(141) << endl;
}