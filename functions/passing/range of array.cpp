/* Function to compute the sum of a range of an array (SumArrayRange.cpp) */
#include <iostream>
using namespace std;
 
// Function prototype
int sum(const int *begin, const int *end);
 
// Test Driver
int main() {
   int a[] = {8, 4, 5, 3, 2, 1, 4, 8};
   cout << sum(a, a+8) << endl;        // a[0] to a[7]
   cout << sum(a+2, a+5) << endl;      // a[2] to a[4]
   cout << sum(&a[2], &a[5]) << endl;  // a[2] to a[4]
}
 
// Function definition
// Return the sum of the given array of the range from
// begin to end, exclude end.
int sum(const int *begin, const int *end) {
   int sum = 0;
   for (const int *p = begin; p != end; ++p) {
      sum += *p;
   }
   return sum;
}