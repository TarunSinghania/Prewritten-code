    #include<string>

	
    int n ;
    string s; 
    
    cin>>n;
    cin>>s;
    
    cout<<n*2<<endl;
    cout<<s<<endl;

    // setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

int main () {
  double f =3.14159;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';
  std::cout << std::fixed;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';
  return 0;
}


cin can leave a terminating character at the end 
therfore usse cin.ignore();

skips a character 

cin>>t;getline()


while(cin>>n)
solve(n);
