Using cin.getline

The getline member function is similar to the get function. Both functions allow a third argument that specifies the terminating character for input. The default value is the newline character. Both functions reserve one character for the required terminating character. However, get leaves the terminating character in the stream and getline removes the terminating character.

The following example specifies a terminating character for the input stream:

#include <iostream.h>

void main()
{
   char line[100];
   cout << " Type a line terminated by 't'" << endl;
   cin.getline( line, 100, 't' );
   cout << line;
}