// vector assign
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
  return 0;
}





#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
  vector <int> gquiz;
  int sum = 0;
  gquiz.push_back(10);
  gquiz.push_back(20);
  gquiz.push_back(30);
 
  while (!gquiz.empty())
  {
    sum += gquiz.back();
    gquiz.pop_back();
  }
 
  cout << "The sum of the elements of gquiz is :  "
       << sum << '\n';
 
  return 0;
}






#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector <int> gquiz1(3, 10);
    vector <int> :: iterator it;
 
    it = gquiz1.begin();
    it = gquiz1.insert(it, 20);
 
    gquiz1.insert(it, 2, 30);
 
    it = gquiz1.begin();
 
    vector <int> gquiz2(2, 40);
    gquiz1.insert(it + 2, gquiz2.begin(), gquiz2.end());
 
    int gq [] = {50, 60, 70};
    gquiz1.insert(gquiz1.begin(), gq, gq + 3);
 
    cout << "gquiz1 contains : ";
    for (it = gquiz1.begin(); it < gquiz1.end(); it++)
        cout << *it << '\t';
 
    return 0;
}



#include <iostream>
#include <vector>
using namespace std;
 
int main ()
{
    vector <int> gquiz;
 
    for (int i = 1; i <= 10; i++)
        gquiz.push_back(i * 2);
 
    // erase the 5th element
    gquiz.erase(gquiz.begin() + 4);
 
    // erase the first 5 elements:
    gquiz.erase(gquiz.begin(), gquiz.begin() + 5);
 
    cout << "gquiz contains :";
    for (int i = 0; i < gquiz.size(); ++i)
        cout << gquiz[i] << '\t';
 
    return 0;
}






#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector <int> gquiz1;
    vector <int> gquiz2;
    vector <int> :: iterator i;
 
    gquiz1.push_back(10);
    gquiz1.push_back(20);
 
    gquiz2.push_back(30);
    gquiz2.push_back(40);
 
    cout << "Before Swapping, \n"
         <<"Contents of vector gquiz1 : ";
 
    for (i = gquiz1.begin(); i != gquiz1.end(); ++i)
        cout << *i << '\t';
 
    cout << "\nContents of vector gquiz2 : ";
    for (i = gquiz2.begin(); i != gquiz2.end(); ++i)
        cout << *i << '\t';
 
    swap(gquiz1, gquiz2);
 
    cout << "\n\nAfter Swapping, \n";
    cout << "Contents of vector gquiz1 : ";
    for (i = gquiz1.begin(); i != gquiz1.end(); ++i)
        cout << *i << '\t';
 
    cout << "\nContents of vector gquiz2 : ";
    for (i = gquiz2.begin(); i != gquiz2.end(); ++i)
        cout << *i << '\t';
 
    cout << "\n\nNow, we clear() and then add "
         << "an element 1000 to vector gquiz1 : ";
    gquiz1.clear();
    gquiz1.push_back(1000);
    cout << gquiz1.front();
 
    return 0;
}