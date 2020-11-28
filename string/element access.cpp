 std::string str ("Test string");
  for (int i=0; i<str.length(); ++i)
  {
    std::cout << str[i];
  }

  If pos is equal to the string length, the function returns a reference to the null character that follows the last character in the string (which should not be modified

  	Complexity
Constant.




std::string str ("Test string");
  for (unsigned i=0; i<str.length(); ++i)
  {
    std::cout << str.at(i);
  }

  
Complexity
Constant.


The function automatically checks whether pos is the valid position of a character in the string (i.e., whether pos is less than the string length), throwing an out_of_range exception if it is not.
