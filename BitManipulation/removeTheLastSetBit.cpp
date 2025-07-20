/* Remove the last set bit or the rightmost set bit in a number n 

Example: input : n = 12
        which is => 1100
So, it will become 1000, and output = 8

Notes:
- The first set bit in n becomes 0 in (n-1)
- Everything to the right of the set bit position stays 0 (same) 
- Everything on the left of that position stays the same (mix of 0 and 1s)

*/

#include <iostream>
using namespace std;

int main() {
    int n = 60;

    n = n & (n-1);

    cout << n << endl;

}