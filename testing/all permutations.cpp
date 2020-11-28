#include<bits/stdc++.h>
using namespace std;
  

/* Drier program to test above function*/
int main() 
{ 
  int n;
  cin>>n;
    int a[n]; 

  for(int i = 0; i < n ; i++)
      cin>>a[i];


  sort(a,a+n);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
   for(int i = 0;i <n;i++)
    cout<<a[i]<<" ";
cout<<endl;
      
  } while ( std::next_permutation(a,a+n));  

  
    return 0; 
} 
