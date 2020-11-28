#include <bits/stdc++.h> 
#include <chrono> 
using namespace std; 
  
  
// A sample function whose time taken to 
// be measured 
void fun() 
{ 
    for (int i=0; i<10; i++) 
    { 
    } 
} 
  
int main() 
{ 
    auto start = chrono::high_resolution_clock::now(); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false); 
  
    fun(); 
  
    auto end = chrono::high_resolution_clock::now(); 
  
    // Calculating total time taken by the program. 
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
  
    time_taken *= 1e-9; 
  
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
    return 0; 
} 