/* WAP to set the ith bit of a number n */

#include <iostream>
using namespace std;
int main() {
    int n = 8; // 1000
    // set the 2nd bit of 8 
    int i = 2;

    n = n | (1 << i);

    // should be 1100 now, which is 12
    cout << n << endl;
}