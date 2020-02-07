Using C++11 to simplify things

  We can make sorting whole arrays even easier by using std::begin() and std::end(). std::begin() will
  return a iterator(pointer) to the first element in the array we pass it.
  Whereas std::end() will return a iterator(pointer) to one past the last element in the array we pass it. So we could call the sort 
  function by passing it begin() and end() like so.

sort(begin(intArray), end(intArray));






include <algorithm>
//OPERATOR OVERLOADED BEGIN AND END FOR ARRAYS

int main(){
  int v[2000];
  std::sort(std::begin(v), std::end(v));
}



//dont know size
std::sort(v, v + sizeof v / sizeof v[0]);




// sorting/stl-sort-array.cpp - Demo STL sort of array.
// Fred Swartz - 2003-09-26

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[7] = {23, 1, 33, -20, 6, 6, 9};
    
    sort(a, a+7);
    
    for (int i=0; i<7; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}



// C++ program to demonstrate descending order sort using
// greater<>().
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    sort(arr, arr+n, greater<int>());
 
    cout << "Array after sorting : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
 
    return 0;
}