template <class T > void add_num(T a, T b) {
	
cout<<a+b<<endl;

}




We need to tell the compiler that this is a function template because it will not identify T ( since T is not a keyword ). For this, we need to include the following code before including T as shown below.

template <typename T>        // declaring function template with template parametetemplate 
T sum( T x, T y)
{
    return x + y;
}



#include <iostream>

using namespace std;

template < typename T1, typename T2 >
T2 product( T1 x, T2 y)
{
    return (T2)(x * y);
}

int main()
{
	cout << product(3, 4.7) << endl;
	cout << product(4, 5.6) << endl;
	return 0;
}