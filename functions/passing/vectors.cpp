// C++ program to demonstrate how vectors
// can be passed by reference with modifications
// restricted.
#include<bits/stdc++.h>
using namespace std;
  
// The vect is passed by constant reference
// and cannot be changed by this function.
void func(const vector<int> &vect)
{
    // vect.push_back(30);  // Uncommenting this line would
                             // below error
    // "prog.cpp: In function 'void func(const std::vector<int>&)':
    // prog.cpp:9:18: error: passing 'const std::vector<int>' 
    // as 'this' argument discards qualifiers [-fpermissive]"   
   
    for (int i=0; i<vect.size(); i++)
       cout << vect[i] << " ";
}
  
int main()
{
    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
  
    func(vect);
   
    return 0;
}





// C++ program to demonstrate how vectors
// can be passed by reference.
#include<bits/stdc++.h>
using namespace std;
  
// The vect is passed by reference and changes
// made here reflect in main()
void func(vector<int> &vect)
{
   vect.push_back(30);
}
  
int main()
{
    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
  
    func(vect);
 
    for (int i=0; i<vect.size(); i++)
       cout << vect[i] << " ";
  
    return 0;
}



// C++ program to demonstrate that when vectors
// are passed to functions without &, a copy is
// created.
#include<bits/stdc++.h>
using namespace std;
  
// The vect here is a copy of vect in main()
void func(vector<int> vect)
{
   vect.push_back(30);
}
  
int main()
{
    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
  
    func(vect);
  
    // vect remains unchanged after function
    // call
    for (int i=0; i<vect.size(); i++)
       cout << vect[i] << " ";
  
    return 0;
}





