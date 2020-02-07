/* Test dynamic allocation of array  (TestDynamicArray.cpp) */
#include <iostream>
#include <cstdlib>
using namespace std;
 
int main() {
   const int SIZE = 5;
   int * pArray;
 
   pArray = new int[SIZE];  // Allocate array via new[] operator
 
   // Assign random numbers between 0 and 99
   for (int i = 0; i < SIZE; ++i) {
      *(pArray + i) = rand() % 100;
   }
   // Print array
   for (int i = 0; i < SIZE; ++i) {
      cout << *(pArray + i) << " ";
   }
   cout << endl;
 
   delete[] pArray;  // Deallocate array via delete[] operator
   return 0;
}



/* Pointer and Array (TestPointerArray.cpp) */
#include <iostream>
using namespace std;
 
int main() {
   const int SIZE = 5;
   int numbers[SIZE] = {11, 22, 44, 21, 41};  // An int array
 
   // The array name numbers is an int pointer, pointing at the
   // first item of the array, i.e., numbers = &numbers[0]
   cout << &numbers[0] << endl; // Print address of first element (0x22fef8)
   cout << numbers << endl;     // Same as above (0x22fef8)
   cout << *numbers << endl;         // Same as numbers[0] (11)
   cout << *(numbers + 1) << endl;   // Same as numbers[1] (22)
   cout << *(numbers + 4) << endl;   // Same as numbers[4] (41)

}



In C/C++, an arrays name is a pointer, pointing to the first element (index 0) of the array. For example, suppose that numbers is an int array, numbers is a also an int pointer, pointing at the first element of the array. That is, numbers is the same as &numbers[0]. Consequently, *numbers is number[0]; *(numbers+i) is numbers[i].

int numbers[] = {11, 22, 33};
int * iPtr = numbers;
cout << iPtr << endl;        // 0x22cd30
cout << iPtr + 1 << endl;    // 0x22cd34 (increase by 4 - sizeof int)
cout << numbers  << endl;    // 0x22cd30
cout << numbers+1 << endl;   //0x22cd34
cout << *iPtr << endl;       // 11
cout << *(iPtr + 1) << endl; // 22
cout << *(numbers) << endl; //11
cout << *(numbers + 1) << endl;  //22

cout << *iPtr + 1 << endl;   // 12
cout<<&numbers +1 <<endl;    //0x22cd3c //moves to base address +size of array 3*4bytes = 12bytes




