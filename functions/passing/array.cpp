
void func(int *a)

{

a[0]=89;
//code;

}

void func(int a[])
void func(int a[5])
typedef int array_plz[5];
void func(array_plz a)
//all are ddecayed to first one 
//size of function would return size of pointer 



//to pass with struct get a copy with size of wotking
//pass structure by value to make changes


struct array_rly {
    int a[5];
};
void func(struct array_rly a)
{
    printf("%zd\n", sizeof(a.a)/sizeof(a.a[0]));  /* prints 5 */
}



void func(const int (*a)[5])
{
    printf("%zd\n", sizeof(*a)/sizeof((*a)[0]));  /* prints 5 */
}




void func(int n, const int (*a)[n])
{
    printf("%zd\n", sizeof(*a)/sizeof((*a)[0]));  /* prints n */
}




///pass by value example


// C program to demonstrate passing an array
// by value using structures.
#include<stdio.h>
#include<stdlib.h>
 
# define SIZE 5
 
// A wrapper for array to make sure that array
// is passed by value.
struct ArrayWrapper
{
    int arr[SIZE];
};
 
// An array is passed by value wrapped in temp
void modify(struct ArrayWrapper temp)
{
    int *ptr = temp.arr;
    int i;
 
    // Display array contents
    printf("In 'modify()', before modification\n");
    for (i = 0; i < SIZE; ++i)
        printf("%d ", ptr[i]);
 
    printf("\n");
 
    // Modify the array
    for (i = 0; i < SIZE; ++i)
        ptr[i] = 100; // OR *(ptr + i)
 
    printf("\nIn 'modify()', after modification\n");
    for (i = 0; i < SIZE; ++i)
        printf("%d ", ptr[i]); // OR *(ptr + i)
}
 
// Driver code
int main()
{
    int i;
    struct ArrayWrapper obj;
    for (i=0; i<SIZE; i++)
        obj.arr[i] = 10;
 
    modify(obj);
 
    // Display array contents
    printf("\n\nIn 'Main', after calling modify() \n");
    for (i = 0; i < SIZE; ++i)
        printf("%d ", obj.arr[i]); // Not changed
 
    printf("\n");
 
    return 0;
}














An array is passed into a function as a pointer to the first element of the array. You can use array notation (e.g., int[]) or pointer notation (e.g., int*) in the function declaration. The compiler always treats it as pointer (e.g., int*). For example, the following declarations are equivalent:

int max(int numbers[], int size);
int max(int *numbers, int size);
int max(int number[50], int size);

Array is passed by reference into the function, because a pointer is passed instead of a clone copy. If the array is modified inside the function, the modifications are applied to the caller s copy. You could declare the array parameter as const to prevent the array from being modified inside the function.

The size of the array is not part of the array parameter, and needs to be passed in another int parameter. Compiler is not able to deduce the array size from the array pointer, and does not perform array bound check.


/* Passing array in/out function (TestArrayPassing.cpp) */
#include <iostream>
using namespace std;
 
// Function prototypes
int max(const int arr[], int size);
void replaceByMax(int arr[], int size);
void print(const int arr[], int size);
 
int main() {
   const int SIZE = 4;
   int numbers[SIZE] = {11, 22, 33, 22};
   print(numbers, SIZE);
   cout << max(numbers, SIZE) << endl;
   replaceByMax(numbers, SIZE);
   print(numbers, SIZE);
}
 
// Return the maximum value of the given array.
// The array is declared const, and cannot be modified inside the function.
int max(const int arr[], int size) {
   int max = arr[0];
   for (int i = 1; i < size; ++i) {
      if (max < arr[i]) max = arr[i];
   }
   return max;
}
 
// Replace all elements of the given array by its maximum value
// Array is passed by reference. Modify the caller's copy.
void replaceByMax(int arr[], int size) {
   int maxValue = max(arr, size);
   for (int i = 0; i < size; ++i) {
      arr[i] = maxValue;
   }
}
 
// Print the array's content
void print(const int arr[], int size) {
   cout << "{";
   for (int i = 0; i < size; ++i) {
      cout << arr[i];
      if (i < size - 1) cout << ",";
   }
   cout << "}" << endl;
}


