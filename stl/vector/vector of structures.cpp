#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//here sturcutre is intitalised 
//operator is overloaded < 
 
struct Donnees
{

  int m_1;
  std::string m_2;
  float m_3;
 
  Donnees() : m_1(0), m_3(0.f) {}
  Donnees(int iM1, std::string const & iM2, float iM3) : m_1(iM1), m_2(iM2), m_3(iM3) {}
 
  bool operator < (const Donnees &iData) const
  {
    return m_1 < iData.m_1;
  }

};
 
int main(int argc, char* argv[])
{ 
  std::vector<Donnees> vect;
  vect.push_back(Donnees(5,"C1",0.2f));
  vect.push_back(Donnees(2,"C2",0.4f));
  vect.push_back(Donnees(8,"C3",0.25f));
  vect.push_back(Donnees(4,"C4",0.15f));
  vect.push_back(Donnees(3,"C5",0.6f));
 
  std::sort(vect.begin(), vect.end());
 
  for(std::vector<Donnees>::iterator it = vect.begin(); it != vect.end(); it++)
    std::cout << "(" << it->m_1 << "," << it->m_2 << "," << it->m_3 << ")" << std::endl;
 
  return 0;
}












#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std ;

//here sturcutre is intitalised 
//operator is overloaded < 
 
struct groups
{

  int n;
  int s;
  int e;
//constructor  
  groups(int j, int k, int l) : n(j), s(k), e(l) {}
 
  bool operator < (const groups &iData) const
  {
    return e < iData.e;
  }

};
 
int main()
{ 
  std::vector<groups> vect;
  int n ; 
  cin>>n;
  for (int i = 1; i < n+1 ; i++) {
    int s , e;
    cin>>s>>e;
  vect.push_back(groups(n,s,e));  
         
  }
  
 
 
  std::sort(vect.begin(), vect.end());
 
  for(std::vector<groups>::iterator it = vect.begin(); it != vect.end(); it++)
  {//  std::cout << "(" << it->n << "," << it->s << "," << it->e << ")" << std::endl;
 
  //if(it->e>(++it)->s)
  
  
      
  }
  return 0;
}



