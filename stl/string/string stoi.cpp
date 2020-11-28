/ stoi example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int main ()
{
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz;   // alias of size_t

  int i_dec = std::stoi (str_dec,&sz);
  int i_hex = std::stoi (str_hex,nullptr,16);
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0);

  std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';

  return 0;
}


/* strtoll example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtoll */

int main ()
{
  char szNumbers[] = "1856892505 17b00a12b -01100011010110000010001101100 0x6fffff";
  char* pEnd;
  long long int lli1, lli2, lli3, lli4;
  lli1 = strtoll (szNumbers, &pEnd, 10);
  lli2 = strtoll (pEnd, &pEnd, 16);
  lli3 = strtoll (pEnd, &pEnd, 2);
  lli4 = strtoll (pEnd, NULL, 0);
  printf ("The decimal equivalents are: %lld, %lld, %lld and %lld.\n", lli1, lli2, lli3, lli4);
  return 0;
}



/* atoi example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

int main ()
{
  int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);
  i = atoi (buffer);
  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
  return 0;
}