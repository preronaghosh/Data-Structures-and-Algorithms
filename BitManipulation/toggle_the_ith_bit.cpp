/* Toggle the ith bit of a number */

#include <iostream>
using namespace std;

int main() {
    int n = 13; // 1101
    // Toggle the 3rd bit of n 
    int i = 3;

    /* Using XOR operation:
        a ^ 0 = a
        a ^ a = 0 */

    n = n ^ (1 << i);

    // should become 0101 which is 5
    cout << n << endl;
}