/* WAP to clear the ith bit of a number n */

#include <iostream>
using namespace std;

int main() {
    int n = 8; // 1000
    // clear the 3rd bit of 8 
    int i = 3;
    
    // use AND operation, because we need to multiply that bit to 0 to clear it
    // rest of the bits should be multiplied by 1 to retain all values, hence the NOT operation has to be done
    n = n & ~(1 << i);

    cout << n << endl; // should be 0 now
}