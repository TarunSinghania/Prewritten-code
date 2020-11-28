hasher hash_function() const;

Get hash function
Returns the hash function object used by the unordered_map container.

The hash function is a unary function that takes an object of type key_type as argument and returns a unique value of type size_t based on it. It is adopted by the container on construction (see unordered_maps constructor for more info). By default, it is the default hashing function for the corresponding key type: hash<key_type>.




unordered_map::hash_function

#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> stringmap;

int main ()
{
  stringmap mymap;

  stringmap::hasher fn = mymap.hash_function();

  std::cout << "this: " << fn ("this") << std::endl;
  std::cout << "thin: " << fn ("thin") << std::endl;

  ret

}

